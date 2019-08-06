/* Answer inspired by C Answer Book page 156 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct linenr {
	int linenr;
	struct linenr *next;
};

struct tnode {
	char *word;
	struct linenr *lines;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *p, char *w, int linenr);
void treeprint(struct tnode *);
int getword(char *, int);

int main()
{
	struct tnode *root;
	char word[MAXWORD];
	int linenr = 1;

	root = NULL;

	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]) && !isnoise(word))
			root = addtree(root, word, linenr);
		else if (word[0] == '\n')
			linenr++;

	treeprint(root);

	return 0;
}

int isnoise(char *word)
{
	char *words[] = {
		"the",
		"and"
	};

	char **p = words;
	int wcount = sizeof(words) / sizeof(words[0]);

	while (wcount-- > 0) {
		if (strcmp(word, *p) == 0)
			return 1;

		p++;
	}

	return 0;
}

struct tnode *talloc(void);
struct linenr *lalloc(void);
char *strdup_kr(char *s);
void addlinenr(struct tnode *p, int linenr);

/* addtreex: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w, int linenr)
{
	int cond;

	if (p == NULL) {
		p = talloc();
		p->word = strdup(w);
		p->lines = lalloc();
		p->lines->linenr = linenr;
		p->lines->next = NULL;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		addlinenr(p, linenr);
	else if (cond < 0) /* less than into left subtree */
		p->left = addtree(p->left, w, linenr);
	else /* greater than into right subtree */
		p->right = addtree(p->right, w, linenr);

	return p;
}

void addlinenr(struct tnode *p, int linenr)
{
	struct linenr *newnr;

	newnr = p->lines;

	while (newnr->next != NULL) /* find insert point */
		newnr = newnr->next;

	if (newnr->linenr != linenr) {
		newnr->next = lalloc();
		newnr->next->linenr = linenr;
		newnr->next->next = NULL;
	}
}

void print_linenrs(struct tnode *p);

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{

	if (p != NULL) {
		treeprint(p->left);

		printf("%s: ", p->word);
		print_linenrs(p);
		printf("\n");

		treeprint(p->right);
	}
}

void print_linenrs(struct tnode *p)
{
	struct linenr *linenr_p;

	linenr_p = p->lines;

	while (linenr_p != NULL) {
		printf("%d ", linenr_p->linenr);
		linenr_p = linenr_p->next;
	}
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

/* lalloc: make a linenr */
struct linenr *lalloc(void)
{
	return (struct linenr *) malloc(sizeof(struct linenr));
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
