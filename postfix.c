#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct stack
{
	int TOP;
	int SIZE;
	char *arr;
	int *arr1;
};

struct expression
{
	char *infix;
	char *postfix;
};

void push(struct stack *s, char x)
{
	if(s->TOP >= s->SIZE-1)
	{
		printf("Cannot evaluate\n");
		exit(0);
	}
	
	else
	{
		s->arr[++s->TOP] = x;
	}
}

char pop(struct stack *s)
{
	if(s->TOP == -1)
	{
		printf("Cannot evaluate\n");
		exit(0);
	}

	else
	{
		char x = s->arr[s->TOP];
		s->TOP--;
		return x;
	}
}

void push1(struct stack *s, int x)
{
	if(s->TOP >= s->SIZE-1)
	{
		printf("Cannot evaluate\n");
		exit(0);
	}
	
	else
	{
		s->arr1[++s->TOP] = x;
	}
}

int pop1(struct stack *s)
{
	if(s->TOP == -1)
	{
		printf("Cannot evaluate\n");
		exit(0);
	}

	else
	{
		int x = s->arr1[s->TOP];
		s->TOP--;
		return x;
	}
}

int ISP(char X)
{
	if(X == '+' || X == '-')
		return 2;
	else if(X == '*' || X == '/')
		return 4;
	else if(X == '^')
		return 5;
	else if(X >= '0' && X <= '9' || X >= 'a' && X<= 'z' || X >= 'A' && X<= 'Z')
		return 8;
	else if(X == '(')
		return 0;
}

int ICP(char X)
{
	if(X == '+' || X == '-')
		return 1;
	else if(X == '*' || X == '/')
		return 3;
	else if(X == '^')
		return 6;
	else if(X >= '0' && X <= '9' || X >= 'a' && X<= 'z' || X >= 'A' && X<= 'Z')
		return 7;
	else if(X == '(')
		return 9;
	else if(X == ')')
		return 0;
}

void infix_to_postfix(struct expression *exp)
{
	int i=0, j=0;
	struct stack s;

	s.TOP = -1;
	s.SIZE = strlen(exp->infix);
	s.arr = (char*) malloc(s.SIZE * sizeof(char));

	push(&s, '(');

	while(s.TOP > -1)
	{	
		char X = pop(&s);
		
		if(exp->infix[i] == '(')
		{
			push(&s, X);
			push(&s, exp->infix[i]);
		}
		else if(exp->infix[i] == ')')
		{
			while(X != '(')
			{
				exp->postfix[j] = X;
				X = pop(&s);
				j++;
			}
		}
		else if(exp->infix[i] >= 'a' && exp->infix[i] <= 'z' || exp->infix[i] >= 'A' && exp->infix[i] <= 'Z' || exp->infix[i] >= '0' && exp->infix[i] <= '9')
		{
			push(&s, X);
			exp->postfix[j] = exp->infix[i];
			j++;
		}
		else if(ISP(X) >= ICP(exp->infix[i]))
		{
			while(ISP(X) >=  ICP(exp->infix[i]))
			{
				exp->postfix[j] = X;
				X = pop(&s);
				j++;
			}
			push(&s, X);
			push(&s, exp->infix[i]);
		}
		else if(ISP(X) < ICP(exp->infix[i]))
		{
			push(&s, X);
			push(&s, exp->infix[i]);
		}
		else if(exp->infix[i] == ' ')
		{
			//skip
		}
		else
		{
			printf("INVALID EXPRESSION!\n");
			exit(0);
		}
			
		i++;
	}
}

int evaluate_postfix(char* postfix)
{
	postfix[strlen(postfix)] = '#';

	int i=0;
	int exp[strlen(postfix)];
	
	while(i<strlen(postfix))
	{
		if(postfix[i] >= 'a' && postfix[i] <= 'z' || postfix[i] >= 'A' && postfix[i] <= 'Z')
		{
			printf("Enter value for %c\n", postfix[i]);
			scanf("%d", &exp[i]);
		}
		else if(postfix[i] >= '0' && postfix[i] <= '9')
		{
			exp[i] = postfix[i] - 48;
		}
		i++;
	}
	
	int x1, x2;
	struct stack s;
	i = 0;

	s.TOP = -1;
	s.SIZE = strlen(postfix);
	s.arr1 = (int*) malloc(s.SIZE * sizeof(int));
	
	while(1)
	{
		switch(postfix[i])
		{
			case '+' : 
				x2 = pop1(&s);
				x1 = pop1(&s);
				push1(&s, x1+x2);
				break;
			case '-' : 
				x2 = pop1(&s);
				x1 = pop1(&s);
				push1(&s, x1-x2);
				break;
			case '*' : 
				x2 = pop1(&s);
				x1 = pop1(&s);
				push1(&s, x1*x2);
				break;
			case '/' : 
				x2 = pop1(&s);
				x1 = pop1(&s);
				push1(&s, x1/x2);
				break;
			case '^' : 
				x2 = pop1(&s);
				x1 = pop1(&s);
				push1(&s, pow(x1, x2));
				break;
			case '!' :
				x1 = pop1(&s);
				push1(&s, -x1);
				break;
			case '#' :
				x1 = pop1(&s);
				return x1;
			default :	
				push1(&s, exp[i]);
		}
		i++;
	}
}

void main()
{
	struct expression exp;
	
	exp.infix = (char*) malloc(100 * sizeof(char));
	exp.postfix = (char*) malloc(strlen(exp.infix) * sizeof(char));

	printf("Enter expression to be evaluated:\n");
	printf("NB:- For numbers with more than 1 digit, enter a variable (eg:- A, x, y, etc...) and for negative numbers add '!' after it.\n");
	fgets(exp.infix, 100, stdin);
	
	exp.infix[strlen(exp.infix)-1] = ')';
	
	infix_to_postfix(&exp);
	
	puts(exp.postfix);
	
	printf("Result = %d\n", evaluate_postfix(exp.postfix));
}



