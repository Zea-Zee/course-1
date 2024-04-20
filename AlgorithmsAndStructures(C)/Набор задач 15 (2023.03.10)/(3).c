#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 50000000
#pragma comment(linker, "/STACK:5000000000")

char *inStr;
int pos;
char *token;
char *readToken(char*);
char *peekToken(char*);
double parseExpr();
double parseMonome();
double parseAtom();
double makeSol(char, double, double);

char *readToken(char *token){
    char symb = inStr[pos];
    while(symb == ' '){
        pos++;
        symb = inStr[pos];
    }
    if(symb == '+' || symb == '-' || symb == '*' || symb == '/' || symb == '(' || symb == ')'){
        memset(token,'\0',4);
        token[0] = inStr[pos];
        pos++;
        return token;
    }
    for(int i = 0; isdigit(symb); i++){
        token[i] = inStr[pos];
        pos++;
        symb = inStr[pos];
    }
    return token;
    return (char*) 'b';
}

char *peekToken(char *token){
    int oldPos = pos;
    token = readToken(token);
    pos = oldPos;
    return token;
}

double parseExpr(){
    double res = parseMonome();
    char symb = peekToken(token)[0];
    while(symb == '+' || symb == '-'){
//        char oper = symb;//readToken(token)[0];
        char oper = readToken(token)[0];
//        pos++;
        double add = parseMonome();
        res = makeSol(oper, res, add);
        symb = peekToken(token)[0];
    }
    return res;
}

double parseMonome(){
    double res = parseAtom();
    char symb = peekToken(token)[0];
    while(symb == '*' || symb == '/'){
//        char oper = symb;//readToken(token)[0];
//        pos++;
        char oper = readToken(token)[0];
        double add = parseAtom();
        res = makeSol(oper, res, add);
        symb = peekToken(token)[0];
    }
    return res;
}

double parseAtom(){
    char symb = peekToken(token)[0];
    double res;
    char oFlag = 0;
    if(symb == '-'){
        readToken(token);
        token = readToken(token);
//        printf("token (atom) is: %s\n", token);
        if(token[0]!= '('){
            res = makeSol(symb, 0, atoi(token));
            return res;
        } else {
            symb = token[0];
            oFlag = 1;
        }
    }
    if(symb == '('){
        if(oFlag){
            res = parseExpr();
            readToken(token);
            return (res * -1);
        }
        readToken(token);        //clear (
        res = parseExpr();
        readToken(token);        //clear )
        return res;
    }
    res = atoi(readToken(token));
//    printf("token double (atom) is: %lf\n", res);
    return res;
}

double makeSol(char oper, double a, double b){
    switch (oper){
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default: a;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    inStr = (char*) calloc(N, 1);
    token = (char*) calloc(10, 1);
    gets(inStr);
    int pos = 0;
    double rres = 0;
    printf("%0.20lf", parseExpr());
    return 0;
}
