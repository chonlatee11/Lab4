#include<stdio.h>
#include<ctype.h>
#define SIZE 50
char s[SIZE]; 
int top=-1;
void push(char oper);
char pop();
int priority(char oper);
void display(char ch,char postfix[50]);
int main()
{        
	char infix[50],postfix[50],ch;
	int i=0,k=0;
	for(int j=-1;j<=50;j++)
		postfix[j]='\0';
	printf("\n\nInfix Expression : ");
	scanf("%s",infix);
	while( (ch=infix[i++]) != '\0'){
		if(ch == '(')
			push(ch);
		else
			if(isalnum(ch))
				postfix[k++]=ch;
			else
				if(ch == ')'){
					while(s[top] != '(')
						postfix[k++]=pop();
					pop();
				}else{
					while((priority(ch) <= priority(s[top])) && (top != -1))
						postfix[k++]=pop();
					push(ch);
				}
	display(ch,postfix);
	}
	while( top != -1){
		postfix[k++]=pop();
		display(ch,postfix);
    }
    postfix[k++]='\0';
    printf("\n\nInfix Expn: %s postfix Expn: %s\n",infix,postfix);
return 0;
}

void push(char oper){
	s[++top]=oper;
}
char pop(){
	char x;
	x = s[top];
	s[top--]='\0';
	return(x);
}
int priority(char oper){
	switch(oper){
		case '(': return 0;
		case '+': 
		case '-': return 1;
		case '*':
		case '/': return 2;
		case '^': return 3;
	}
	return 1;
}
void display(char ch,char postfix[50]){
	printf("%c\t",ch);
	printf("%s\t",s);
	printf("%s\n",postfix);
}