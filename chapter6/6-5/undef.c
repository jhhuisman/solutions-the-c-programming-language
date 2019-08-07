/* Based on C Answer Book page 163 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHSIZE 101

struct nlist {
	char *name;
	char *defn;
	struct nlist *next;
};

static struct nlist *hashtab[HASHSIZE]; /* pointer table */

unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
void undef(char *name);

int main()
{
	struct nlist *np;

	np = install("aa", "bb");

	undef("aa");

	printf("## %s\n", np->defn);
	printf("## %p\n", np);
	printf("## %p\n", np->next);

	return 0;
}

void undef(char *name)
{
	struct nlist *np, *prev;
	unsigned hashval;

	hashval = hash(name);

	for (np = hashtab[hashval]; np != NULL; np = np->next) {
		if (strcmp(name, np->name) == 0)
			break;

		prev = np; /* remember previous entry */
	}

	if (np != NULL) { /* found name */
		if (prev == NULL) /* first in the hash list? */
			hashtab[hashval] = np->next;
		else
			prev->next = np->next;

		free((void *) np->name);
		free((void *) np->defn);
		free((void *) np);
	}
}

/* hash: form hash value for string s */
unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;

	return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np; /* found */

	return NULL;
}

struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) { /* not found */
		np = (struct nlist *) malloc(sizeof(*np));

		if (np == NULL || (np->name = strdup(name)) == NULL)
			return NULL;

		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else /* already there */
		free((void *) np->defn); /* free previous defn */

	if ((np->defn = strdup(defn)) == NULL)
		return NULL;

	return np;
}
