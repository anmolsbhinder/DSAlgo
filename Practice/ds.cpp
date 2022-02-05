#include<stdio.h>
#include<stdlib.h>
struct stack{
 float *a;
 int top;
 int size;
};
int isfull(struct stack *st)
{
return (st->top==st->size-1);
}
int isempty(struct stack *st)
{
 return st->top==-1;
}
void push(struct stack *st,float x)
{
 if(isfull(st))
 {
 printf("stack is full and element cannot be pushed!\n");
 return;
 }
 st->top++;
 st->a[st->top]=x;
}
void pop(struct stack *st)
{
 if(isempty(st))
 {
 printf("stack is empty!\n");
 return;
 }
 st->top--;
}
int is_operand(char ch)
{
 if (ch == '+' || ch == '/' || ch == '*' || ch == '-')
 return 0;
 return 1;
}
float evaluate(char ch, int a, int b)
{
 switch (ch)
 {
 case '+':
 return a + b;
 break;
 case '-':
 return a - b;
 break;
 case '*':
 return a * b;
 break;
 case '/':
 return a / (float)b;
 break;
 }
 return -1;
}
float evaluation_of_postfix(char post[])
{
 struct stack st=(struct stack)malloc(sizeof(struct stack));
 st->a=(float *)malloc(sizeof(float)*100);
 st->top=-1;
 st->size=100;
 for (int i = 0; post[i]!='\0'; i++)
 {
 if (is_operand(post[i]))
 push(st, post[i] - 48);
 else
 {
 int b = st->a[st->top];
 pop(st);
 int a = st->a[st->top];
 pop(st);
 float x = evaluate(post[i], a, b);
 push(st,x);
 }
 }
 return st->a[st->top];
}
int main()
{
 char post[50];
 printf("\nEnter the postfix expression: ");
 scanf("%s",post);
 printf("Answer: %f\n",evaluation_of_postfix(post));
 return 0;
}