/* Based on The C Answer book page 89 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100 /* maximum depth of val stack */
#define MAXLINE 100

int getop(char []);
void push(double);
double pop(void);
void print_top(void);
void duplicate_top(void);
void reverse_top2(void);
void clear_stack(void);
int getline_kr(char s[], int lim);

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

int li = 0; /* input line index */
char line[MAXLINE]; /* one input line */

/* reverse Polish calculator */
int main()
{
	int type, i, var;
	double op2, last;
	char s[MAXOP];
	double variables[26];

	for (i = 0; i < 26; ++i)
		variables[i] = 0.0;

	while ((type = getop(s)) != EOF) {
		switch (type) {
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
			case 's': /* sin */
				push(sin(pop()));
				break;
			case 'e': /* exp */
				push(exp(pop()));
				break;
			case '^': /* power */
				op2 = pop();
				push(pow(pop(), op2));
				break;
			case '=': /* asign number to variable */
				pop();

				if (var >= 'A' && var <= 'Z')
					variables[var - 'A'] = pop();
				else
					printf("Error: invalid variable name %c\n", var);
				break;
			case '\n':
				last = pop();
				printf("\t%.8g\n", last);
				break;
			case '?': /* print top element stack */
				print_top();
				break;
			case 'd': /* duplicate top stack element */
				duplicate_top();
				break;
			case 'r': /* Reverse top two elements */
				reverse_top2();
				break;
			case 'c': /* Clear stack */
				clear_stack();
				break;
			case 'l': /* most recently printed value */
				push(last);
				break;
			default:
				if (type >= 'A' && type <= 'Z')
					push(variables[type - 'A']);
				else
					printf("Error: unknown command %s\n", s);
				break;
		}

		var = type;
	}

	return 0;
}

/* print top stack element */
void print_top(void)
{
	double top; /* top stack element */

	top = pop();

	printf("%f\n", top);

	push(top);
}

/* print top stack element */
void duplicate_top(void)
{
	double top; /* top stack element */

	top = pop();
	push(top);
	push(top);
}

/* print top stack element */
void reverse_top2(void)
{
	double top, before_top;

	top = pop();
	before_top = pop();

	push(top);
	push(before_top);
}

/* clear stack */
void clear_stack(void)
{
	sp = 0;
}

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

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c;

	if (line[li] == '\0') {
		if (getline_kr(line, MAXLINE) == 0)
			return EOF;
		else
			li = 0;
	}

	while ((s[0] = c = line[li++]) == ' ' || c == '\t')
		;

	s[1] = '\0';

	if (!isdigit(c) && c != '.' && c != '-')
		return c; /* not a number */

	i = 0;

	/* differentiate between negative sign and substract operator */
	if (c == '-') {
		if (isdigit(c = line[li++]) || c == '.')
			s[++i] = c; /* negative number */
		else {
			if (c != EOF)
				li--;
			return '-'; /* substract operator */
		}
	}

	if (isdigit(c)) /* collect integer part */
		while (isdigit(s[++i] = c = line[li++]))
			;

	if (c == '.') /* collect fraction part */
		while (isdigit(s[++i] = c = line[li++]))
			;

	s[i] = '\0';

	li--;

	return NUMBER;
}

/* getline_kr: get line into s, return length */
int getline_kr(char s[], int lim)
{
	int c, i;

	i = 0;

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;

	if (c == '\n')
		s[i++] = c;

	s[i] = '\0';

	return i;
}
