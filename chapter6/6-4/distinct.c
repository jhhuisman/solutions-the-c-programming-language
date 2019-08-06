/* Answer inspired by C Answer Book page 156 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *p, char *w);
void treeprint(struct tnode *);
int getword(char *, int);
struct tnode *sortlist(struct tnode *sroot, struct tnode *p);

int main()
{
	struct tnode *root;
	struct tnode *sroot;
	char word[MAXWORD];
	int linenr = 1;

	root = NULL;
	sroot = NULL;

	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);
		else if (word[0] == '\n')
			linenr++;

	sroot = sortlist(sroot, root);

	treeprint(sroot);

	return 0;
}

struct tnode *talloc(void);

struct tnode *addtreesort(struct tnode *sp, struct tnode *p)
{
	if (sp == NULL) {
		sp = talloc();
		sp->word = strdup(p->word);
		sp->count = p->count;
		sp->left = sp->right = NULL;
	} else if (p->count < sp->count) {
		sp->left = addtreesort(sp->left, p);
	}
	else {
		sp->right = addtreesort(sp->right, p);
	}

	return sp;
}

struct tnode *sortlist(struct tnode *sroot, struct tnode *p)
{
	if (p != NULL) {
		sortlist(sroot, p->left);

		sroot = addtreesort(sroot, p);

		sortlist(sroot, p->right);
	}

	return sroot;
}

char *strdup_kr(char *s);

/* addtreex: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if (p == NULL) {
		p = talloc();
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;
	else if (cond < 0) /* less than into left subtree */
		p->left = addtree(p->left, w);
	else /* greater than into right subtree */
		p->right = addtree(p->right, w);

	return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->right);

		printf("%d: %s\n", p->count, p->word);

		treeprint(p->left);
	}
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup_kr(char *s) /* make a duplicate of s */
{
	char *p;

	p = (char *) malloc(strlen(s) + 1); /*+1 for '\0' */

	if (p != NULL)
		strcpy(p, s);

	return p;
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
	int c, d, comment(void), getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		if (c == '\n') {
			*w = c;
			return c;
		}

	if (c != EOF)
		*w++ = c;

	if (isalpha(c) || c == '_' || c == '#') {
		for ( ; --lim > 0; w++)
			if (!isalnum(*w = getch()) && *w != '_') {
				ungetch(*w);
				break;
			}
	} else if (c == '\'' || c == '"') {
		for ( ; --lim > 0; w++)
			if ((*w = getch()) == '\\')
				*++w = getch();
			else if (*w == c) {
				w++;
				break;
			} else if (*w == EOF)
				break;
	} else if (c == '/')
		if ((d = getch()) == '*')
			c = comment();
		else
			ungetch(d);

	*w = '\0';

	return c;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

/* comment: skip over comment and return a character */
int comment(void)
{
	int c;

	while ((c = getch()) != EOF)
		if (c == '*')
			if ((c = getch()) == '/')
				break;
			else
				ungetch(c);

	return c;
}
