#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int stack[1000];
int top = -1;

void push(int x){
    if(top >= 1000-1){
        printf("Error, Stack Kelebihan");
        exit(1);
    }
    stack[++top] = x;
}

int pop(){
    if(top < 0){
        printf("Error, Stak Minus");
        exit(1);
    }
    return stack[top--];
}

int top_stack(){
    return stack[top];
}

int is_empty() {
    return top == -1;
}
int prioritas(char operator){
    if(operator == '+' || operator == '-'){
        return 1;
    }
    else if(operator == '*' || operator == '/'){
        return 2;
    }
    else if(operator == '^'){
        return 3;
    }
    else{
        return -1;
    }
}

void konversi(char infix[], char postfix[]){ 
    int i=0, j=0;
    char ch;
    while ((ch = infix[i++]) != '\0'){
        if(isdigit(ch)){
            postfix[j++] = ch;
            while (isdigit(ch = infix[i]))
                 postfix[j++] = ch, i++;
            postfix[j++] = ' ';
        }
        else if(ch == '('){
            push(ch);
        }
        else if(ch == ')'){
            while(!is_empty() && top_stack() != '(')
                 postfix[j++] = pop(), postfix[j++] = ' ';
            if(!is_empty() && top_stack() != '('){
                exit(1);
            }
            pop();
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch =='^'){
            while(!is_empty() && prioritas(ch) <= prioritas(top_stack()))
                postfix[j++] = pop(), postfix[j++] = ' ';
            push(ch);
        }
    } // endwhile
    while(!is_empty())
         postfix[j++] = pop(), postfix[j++] = ' ';
    postfix[j] = '\0';
} //akhir void

int kalkulasi(char postfix[]){
    int i=0, hasil=0;
    char ch;
    while((ch = postfix[i++]) != '\0'){
        if(isdigit(ch)){
            int num = ch - '0';
            while(isdigit(ch = postfix[i++]))
                 num = num*10 + (ch - '0');
            i--;
            push(num);
        }
        else if(ch == ' '){
            continue;
        }
        else if(ch == '+'){
            int operator2 = pop();
            int operator1 = pop();
            hasil = operator1 + operator2;
            push(hasil);
        }
        else if(ch == '-'){
            int operator2 = pop();
            int operator1 = pop();
            hasil = operator1 - operator2;
            push(hasil);
        }
        else if(ch == '*'){
            int operator2 = pop();
            int operator1 = pop();
            hasil = operator1 * operator2;
            push(hasil);
        }
        else if(ch == '/'){
            int operator2 = pop();
            int operator1 = pop();
            hasil = operator1 / operator2;
            push(hasil);
        }
        else if(ch == '^'){
            int operator2 = pop();
            int operator1 = pop();
            
            hasil = 1;
            for (int j = 1; j < operator2+1; j++) {
                hasil *= operator1;
            }
            push(hasil);
        }
    }//end while
    return pop();
}//akhir kalkulasi
int main()
{
    char infix[100], postfix[100];
    printf("Masukkan ekspresi infix: ");
    fgets(infix, 100, stdin);
    konversi(infix, postfix);
    printf("Ekspresi postfixnya adalah: %s\n", postfix);
    printf("Hasil kalkulasinya adalah: %d", kalkulasi(postfix));
    return 0;
}
