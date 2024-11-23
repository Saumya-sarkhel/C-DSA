#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void push(char *,char);
void push1(char *, char);
char pop(char *); 
int precedence(char);
void display(char *);
void stringreverce(char *, char *);
int top=-1;
int top1= -1;

int main(){
    char a[20], b[20], c[20], stack[20], arr[20], t, k;
	  int i;
	  printf("Entering the infix expression : ");
    scanf("%s", &a);
    stringreverce(b,a);
    printf("\nThe postfix expression of corresponding %s infix expression : ",a);

	for(i=0; b[i]!='\0'; i++){
    t=b[i];

		if(t>=40 && t<=47||t=='^'||t=='%'){
      if(t=='('){
        push(stack,t);
      }

      else if(t==')'){
        while((k=pop(stack))!='(')
        {
         push1(arr,k);
        }
      }

      else{
        if(top==-1)
        {
          push(stack,t);
        }

        else{
          while(precedence(t)<precedence(stack[top])){
            k=pop(stack);
            push1(arr,k);
            if(top==-1)
              break;
          }
          push(stack,t);
        }
      }
    }

    else
      push1(arr,t);
  }
  while(top!=-1){
        k=pop(stack);
        push1(arr,k);
    }
    display(arr);

    return 0;
}

int precedence(char t){
    if(t=='(')
        return(0);
    if(t=='-'||t=='+')
        return(1);
    if(t=='/'||t=='%'||t=='*')
        return(2);
    if(t=='^')
        return(3);
}

void push(char *stack,char ch){
    top++;
	  stack[top]=ch;
}

void push1(char *arr, char ch){
  top1++;
  arr[top1]=ch;
}

char pop(char *stack){
	char c;
	c=stack[top];
	top--;
	return(c);
}

void display(char *arr){
	int i;
	i=top1;
	if(top1==-1){
		printf("stack is empty.");
	}
	else{
		while(i>=0){
			printf("%c",arr[i]);
			i--;
		}
	}
}

void stringreverce(char *str2, char *str1){
  int i, len;
  char num;
  strcpy(str2,str1);
  len = strlen(str2);

  for(i=0; i<(len/2); i++){
    num = str2[i];
    str2[i] = str2[len-1-i];
    str2[len-1-i] = num;
  }

  for(i=0; str2[i]!='\0'; i++){
    if(str2[i] == '(' )
      str2[i] = str2[i]+1;

    else if(str2[i] == ')' )
      str2[i] = str2[i]-1;
  }
} 