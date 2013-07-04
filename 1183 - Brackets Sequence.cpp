#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#define N 110
using namespace std;

int dp[N][N];
string sol[N][N];
string input;

void init(string input, int len){
    int i,j;
    for(i=0;i<len;i++){
        for(j=0;j<len;j++){
            if(i>j){
                dp[i][j] = 0;
                sol[i][j] = "";
            }
            else if(i == j){
                dp[i][j] = 1;
                if(input[i] == '(' || input[i] == ')') sol[i][j] = "()";
                else if(input[i] == '[' || input[i] == ']') sol[i][j] = "[]";
                else sol[i][j] = "";
            }
            else{
                dp[i][j] = 999999999;
                sol[i][j] = "";
            }
        }
    }
}

int main(){
    int i,j,k,t,len;
    char arr[N];
    gets(arr);

    if(arr[0] == '\0'){
        printf("%s", arr);
        return 0;
    }

    string input(arr);
    len = input.size();

    init(input, len);

    for(i=len-1; i>=0; i--){
        for(j=i; j<len; j++){
            for(k=i; k<j; k++){
                t = dp[i][k] + dp[k+1][j];
                if(t < dp[i][j]){
                    dp[i][j] = t;
                    sol[i][j] = sol[i][k]+sol[k+1][j];
                }
            }
            if((input[i]=='(' && input[j]==')')||(input[i]=='[' && input[j]==']')){
                t = dp[i+1][j-1];
                if(t < dp[i][j]){
                    dp[i][j] = t;
                    if(input[i] == '(') sol[i][j] = "("+sol[i+1][j-1]+")";
                    else sol[i][j] = "["+sol[i+1][j-1]+"]";
                }
            }
            else if((input[i]=='(' && input[j]=='(')||(input[i]=='[' && input[j]=='[')){
                t = dp[i+1][j]+1;
                if(t < dp[i][j]){
                    dp[i][j] = t;
                    if(input[i] == '(') sol[i][j] = "("+sol[i+1][j]+")";
                    else sol[i][j] = "["+sol[i+1][j]+"]";
                }
            }
            else if((input[i]=='(' && input[j]==']')||(input[i]=='[' && input[j]==')')){
                t = dp[i+1][j]+1;
                if(t < dp[i][j]){
                    dp[i][j] = t;
                    if(input[i] == '(') sol[i][j] = "("+sol[i+1][j]+")";
                    else sol[i][j] = "["+sol[i+1][j]+"]";
                }
                t = dp[i][j-1]+1;
                if(t < dp[i][j]){
                    dp[i][j] = t;
                    if(input[i] == '(') sol[i][j] = "["+sol[i][j-1]+"]";
                    else sol[i][j] = "("+sol[i][j-1]+")";
                }
            }
            else if((input[i]=='(' && input[j]=='[')||(input[i]=='[' && input[j]=='(')){
                t = dp[i+1][j]+1;
                if(t < dp[i][j]){
                    dp[i][j] = t;
                    if(input[i] == '(') sol[i][j] = "("+sol[i+1][j]+")";
                    else sol[i][j] = "["+sol[i+1][j]+"]";
                }
            }
        }
    }

    cout << sol[0][len-1] << endl;
    return 0;
}
