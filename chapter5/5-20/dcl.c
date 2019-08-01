/* Answer of C Answer Book page 146 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };
enum { NO, YES };

void dcl(void);
void dirdcl(void);
void errmsg(char *);
void parmdcl(void);
void dclspec(void);
int  gettoken(void);
int  typespec(void);
int  typequal(void);
int  compare(char **s, char **t);

int  tokentype;          /* type of last token */
char token[MAXTOKEN];    /* last token string */
char name[MAXTOKEN];     /* identifier name */
char datatype[MAXTOKEN]; /* data type = char, int, etc. */
char out[1000];          /* output string */
int  prevtoken;

int main()
{
	while (gettoken() != EOF) { /* 1st token on line */
		strcpy(datatype, token); /* is the datatype */

		out[0] = '\0';

		dcl(); /* parse rest of line */

		if (tokentype != '\n')
			printf("syntax error\n");

		printf("%s: %s %s\n", name, out, datatype);
	}

	return 0;
}

int gettoken(void) /* return next token */
{
	int c, getch(void);
	void ungetch(int);
	char *p = token;

	if (prevtoken == YES) {
		prevtoken = NO;
		return tokentype;
	}

	while ((c = getch()) == ' ' || c == '\t')
		;

	if (c == '(') {
		if ((c = getch()) == ')') {
			strcpy(token, "()");
			return tokentype = PARENS;
		} else {
			ungetch(c);
			return tokentype = '(';
		}
	} else if (c == '[') {
		for (*p++ = c; (*p++ = getch()) != ']'; )
			;

		*p = '\0';

		return tokentype = BRACKETS;
	} else if (isalpha(c)) {
		for (*p++ = c; isalnum(c = getch()); )
			*p++ = c;

		*p = '\0';

		ungetch(c);

		return tokentype = NAME;
	} else
		return tokentype = c;
}

/* dcl: parse a declarator */
void dcl(void)
{
	int ns;

	for (ns = 0; gettoken() == '*'; ) /* count *'s */
		ns++;

	dirdcl();

	while (ns-- > 0)
		strcat(out, " pointer to");
}

/* dirdcl: parse a direct declarator */
void dirdcl(void)
{
	int type;

	if (tokentype == '(') { /* ( dcl ) */
		dcl();

		if (tokentype != ')')
			errmsg("error: missing )\n");
	} else if (tokentype == NAME) { /* variable name */
		if (name[0] == '\0')
			strcpy(name, token);
	} else
		prevtoken = YES;

	while ((type = gettoken()) == PARENS || type == BRACKETS || type == '(')
		if (type == PARENS)
			strcat(out, "function returning");
		else if (type == '(') {
			strcat(out, " function expecting");
			parmdcl();
			strcat(out, " and returning");
		} else {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
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

/* errmsg: print error message and indicate avail. token */
void errmsg(char *msg)
{
	printf("%s", msg);
	prevtoken = YES;
}

/* parmdcl: parse a parameter declarator */
void parmdcl(void)
{
	do {
		dclspec();
	} while (tokentype == ',');

	if (tokentype != ')')
		errmsg("missing ) in parameter declaration\n");
}

/* dclspec: declaration specification */
void dclspec(void)
{
	char temp[MAXTOKEN];

	temp[0] = '\0';

	gettoken();

	do {
		if (tokentype != NAME) {
			prevtoken = YES;
			dcl();
		} else if (typespec() == YES) {
			strcat(temp, " ");
			strcat(temp, token);
			gettoken();
		} else if (typequal() == YES) {
			strcat(temp, " ");
			strcat(temp, token);
			gettoken();
		} else
			errmsg("unknown type in parameter list\n");
	} while (tokentype != ',' && tokentype != ')');

	strcat(out, temp);

	if (tokentype == ',')
		strcat(out, ",");
}

/* typespec: return YES if token is a type specifier */
int typespec(void)
{
	static char *types[] = {
		"char",
		"int",
		"void"
	};

	char *pt = token;

	if (bsearch(&pt, types, sizeof(types)/sizeof(char *), sizeof(char *),
		compare) == NULL)
		return NO;
	else
		return YES;
}

/* typequal: return YES if token is a type-qualifier */
int typequal(void)
{
	static char *typeq[] = {
		"const",
		"volatile"
	};

	char *pt = token;

	if (bsearch(&pt, typeq, sizeof(typeq)/sizeof(char *), sizeof(char *),
		    compare) == NULL)
		return NO;
	else
		return YES;
}

/* compare: compare two strings for bsearch */
int compare(char **s, char **t)
{
	return strcmp(*s, *t);
}
