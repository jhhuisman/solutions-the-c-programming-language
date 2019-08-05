/* Answer based on C Answer Book page 153 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define YES 1
#define NO 0

struct tnode {
	char *word;
	int match;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtreex(struct tnode *p, char *w, int n, int *found);
void treeprint(struct tnode *);
int getword(char *, int);
int compare(char *s, struct tnode *p, int n, int *found);

int main(int argc, char *argv[])
{
	struct tnode *root;
	char word[MAXWORD];
	int found = NO;
	int n; /* compare first n characters */

	n = (argc > 1 && argv[1][0] == '-') ? atoi(&argv[1][1]) : 6;

	root = NULL;

	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]) && strlen(word) >= n)
			root = addtreex(root, word, n, &found);

	treeprint(root);

	return 0;
}

struct tnode *talloc(void);
char *strdup_kr(char *s);

/* addtreex: add a node with w, at or below p */
struct tnode *addtreex(struct tnode *p, char *w, int n, int *found)
{
	int cond;

	if (p == NULL) {
		p = talloc();
		p->word = strdup(w);
		p->match = *found;
		p->left = p->right = NULL;
	} else if ((cond = compare(w, p, n, found)) < 0)
		p->left = addtreex(p->left, w, n, found);
	else if (cond > 0) /* less than into left subtree */
		p->right = addtreex(p->right, w, n, found);

	return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);

		if (p->match)
			printf("%s\n", p->word);

		treeprint(p->right);
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
		;

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

/* compare: compare words and update p->match */
int compare(char *s, struct tnode *p, int n, int *found)
{
	int i;
	char *t = p->word;

	for (i = 0; *s == *t; i++, s++, t++)
		if (*s == '\0')
			return 0;
	if (i >= n) {
		*found = YES;
		p->match = YES;
	}

	return *s - *t;
}
