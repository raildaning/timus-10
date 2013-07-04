/*
I've got a good method. Use the following recurrence eqn and solve using DP.
dp(n,s)=sigma(i=0 to 9){ ((s-i)>=0)?dp(n-1, s-i):0}
n represents the number of digits and s represents the sum of digits.
dp(n,s) represents # of numbers containing upto n digits that make sum of digits s
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXDIGIT 10
#define MAXSUM 100
using namespace std;

int mat[MAXDIGIT][MAXSUM];

int dp(int digit,int sum){
    if(sum < 0) return 0;
    if(sum == 0) return 1;
    if(digit == 0) return 0;
    //if(mat[digit][sum] != -1) return mat[digit][sum];
    if(mat[digit][sum] >= 0) return mat[digit][sum];
    mat[digit][sum]=0;
    for(int i=0;i<=9;i++){
        mat[digit][sum] += dp(digit-1,sum-i);
    }
    return mat[digit][sum];
}

int main(){
    int s;
    scanf("%d",&s);
    for(int i=0;i<MAXDIGIT;i++){
        for(int j=0;j<MAXSUM;j++) mat[i][j] = -1;
    }
    int res = dp(9,s);
    if(s==1) res++;
    printf("%d\n",res);
    return 0;
}
