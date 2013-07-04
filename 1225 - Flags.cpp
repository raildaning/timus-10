/*
You can reason about this without using numerical examples (it's not necessarily clear from a few numerical cases that the pattern will always hold!).

If you want to make a sequence of length n, you can either:
1) take a sequence of length n-1 and add one flag to it (the new flag color is dictated by how the n-1 sequence ends, and there's only one choice, so there are as many ways to extend to n in this way as there are ways to make all n-1 sequences); or
2) take a sequence of length n-2 and add a blue-white/red sequence.   There's only one way to do this based on how the n-2 sequence ends, so there are as many ways to extend to n as there are ways to make this n-2 sized sequence.

So the # of ways to make a sequence of size n is: # of ways to make n-1 + # of ways to make n-2
*/

#include <iostream>
#include <cstdio>
#define MAX 50
using namespace std;

long long int dp[MAX];

void precalc(){
    dp[1]=2;
    dp[2]=2;
    for(int i=3;i<=45;i++) dp[i] = dp[i-1]+dp[i-2];
    return;
}

int main(){
    precalc();
    int n;
    while(cin>>n){
        printf("%lld\n",dp[n]);
    }
    return 0;
}
