/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 11485
 * Submitted at:  2015-01-28 14:55:52
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    381
 * Problem Name:  Hexadecimal Calculation
 */

#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>


using namespace std;

int cmpPriority(char a, char b){
    if(a=='*' || (a=='+' && b=='('))
        return 1;
    else
        return 0;
}

int isOperator(char a){
    if(a=='*' || a=='+')
        return 1;
    else
        return 0;
}

int isBracket(char a){
    if(a=='(' || a==')')
        return 1;
    else
        return 0;
}


int hex2dec(char a){
    if(a>='0' && a<='9')
        return a-'0';
    else
        return 10+(a-'A');
}

char dec2hex(int a){
    if(a>=0 && a<=9){
        return '0'+a;
    }
    else{
        return 'A'+(a-10);
    }
}

unsigned long cal(unsigned long a,unsigned long b,char c){
    if(c=='+'){
        return a+b;
    }
    else{
        return a*b;
    }
}


int main()
{
    char c;
    stack<unsigned long> operandStack;
    stack<char> operatorStack;
    char opt[9];
    int i=-1;
    while((c=getchar())!=EOF){
        if(c!='\n'){
            if (!isBracket(c) && !isOperator(c)){
                operandStack.push(hex2dec(c));
                //printf("%ld\n",operandStack.top());
            }
            
            if (isBracket(c)){
                if(c=='(')
                    operatorStack.push(c);
                else{
                    while(operatorStack.top()!='('){
                        char op=operatorStack.top();
                        operatorStack.pop();
                        
                        unsigned long op1=operandStack.top();
                        operandStack.pop();
                        unsigned long op2=operandStack.top();
                        operandStack.pop();
                        
                        unsigned long result=cal(op1,op2,op);
                        operandStack.push(result);
                    }
                    operatorStack.pop();
                }
            }
            if(isOperator(c)){
                if(operatorStack.empty()){
                    operatorStack.push(c);
                    //printf("%c\n",operatorStack.top());
                }
                else{
                    while(!operatorStack.empty() && !cmpPriority(c,operatorStack.top())){
                        char op=operatorStack.top();
                        operatorStack.pop();
                        
                        unsigned long op1=operandStack.top();
                        operandStack.pop();
                        unsigned long op2=operandStack.top();
                        operandStack.pop();
                        
                        unsigned long result=cal(op1,op2,op);
                        operandStack.push(result);
                        
                    }
                    operatorStack.push(c);
                    //printf("%c\n",operatorStack.top());
                    //printf("%ld\n",operandStack.top());
                }
                
            }
        }
        else{
            while (!operatorStack.empty() && !operandStack.empty()){
                char op=operatorStack.top();
                operatorStack.pop();
                
                unsigned long op1=operandStack.top();
                operandStack.pop();
                unsigned long op2=operandStack.top();
                operandStack.pop();
                
                unsigned long result=cal(op1,op2,op);
                operandStack.push(result);
            }
            unsigned long r=operandStack.top();
            operandStack.pop();
            
            if(r==0){
                opt[++i]='0';
            }
            else{
                while(r!=0){
                    opt[++i]=dec2hex(r%16);
                    r/=16;
                }
            }
                        
            while(i>=0){
                printf("%c",opt[i--]);
            }
            printf("\n");
        }
    }

    return 0;
}