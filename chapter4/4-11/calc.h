#define NUMBER '0' /* signal that a number was found */

extern void push(double f);
extern double pop(void);

extern int getop(char s[]);
extern int getch(void);
extern void ungetch(int c);
