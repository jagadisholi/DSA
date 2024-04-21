// infix to postfix
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
// function to -> to set the precedence

int precedence(char C ){
    if(C=='^')
    return 3;
    else if(C=='/' || C=='*')
    return 2;
    else if(C=='+' || C=='-')
    return 1;
    else 
    return -1;
}

char associativity(char C){
    if( C=='^')
    return 'R';
    return 'L' ; // default to left associativity
}

// to convert infix to postfix

void infixToPostFix(char s[]){
    char result[1000];
    int resultIndex = 0;
    int len  =strlen(s);
    char stack [1000];
    char stackIndex = -1;
    int i;
    for(i=0; i<len; i++){
        char C = s[i];

        // if the scanned character is an operand add it ot the o/p string.

        if((C>='a' && C<='z') || (C>='A' && C<='Z') ||(C>='0' && C<='9')){
            result[resultIndex++] = C;
        }

        // if the scanned char is an ) pop and add to the o/p string from the stack.

        else if(C==')'){
            while(stackIndex >=0 && stack[stackIndex++] !='('){
                result[resultIndex++]=stack[stackIndex++];
            }
            stackIndex--; // pop'('
        }
        // if an operator is scanned

        else{
            while(stackIndex >=0 &&(precedence(s[i]))<precedence(stack[stackIndex]) || precedence(s[i])==precedence(stack[stackIndex]) && associativity(s[i]=='L')){
                result[resultIndex++] = stack[stackIndex--];
            }
            stack[++stackIndex] = C;
            printf("\n %d \n", stack[stackIndex]);
        }
    }

    // pop all the remaning all the elements form the stack 

    while(stackIndex>=0){
        result[resultIndex++] = stack[stackIndex--];
    }

    result[resultIndex] = '\0';
    printf("%s\n", result);
}

// main function 

int main(){
    char expression[]= "a+b-/c+d-m";
    infixToPostFix(expression); // fucntion call 
    return 0;
}

