/* Based on C Answer Book page 115 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
void ungets(char *s);

int main(int argc, char *argv[])
{
	double op2;
	char s[MAXOP];

	if (argc == 1)
		printf("Usage: expr <expression>\n");

	while (--argc > 0) {
		ungets(*++argv);

		switch (getop(s)) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push((int) pop() % (int) op2);
				else
					printf("Error: zero operand\n");
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("Error: zero divisor\n");
				break;
			default:
				printf("Error: unknown command %s\n", s);
				argc = 1;
				break;
		}
	}

	printf("\t%.8g\n", pop());

	return 0;
}

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f into value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("Error: stack full, can't push %g\n", f);
}

/* pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("Error: stack empty\n");
		return 0.0;
	}
}

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;

	s[1] = '\0';
	i = 0;

	if (!isdigit(c) && c != '.' && c != '-')
		return c; /* not a number */

	/* differentiate between negative sign and substract operator */
	if (c == '-') {
		if (isdigit(c = getch()) || c == '.')
			s[++i] = c; /* negative number */
		else {
			if (c != EOF)
				ungetch(c); /* undo peaking ahead */
			return '-'; /* substract operator */
		}
	}

	if (isdigit(c)) /* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;

	if (c == '.') /* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;

	s[i] = '\0';

	if (c != EOF)
		ungetch(c);

	return NUMBER;
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

void ungets(char *s)
{
	int index;

	for (index = strlen(s); index >= 0; --index)
		ungetch(s[index]);
}
