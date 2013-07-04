#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 510
#define INF 99999999
using namespace std;

int cum[MAX];
int dp[MAX][MAX];

int calculate(int n, int k){
    if(dp[n][k] != -1) return dp[n][k];
    else{
        if(k==0){
            int cost;
            cost = cum[n]*(n-cum[n]);
            dp[n][k] = cost;
            return dp[n][k];
        }
        else{
            int cost = INF,temp;
            for(int i = 1; (i <= n) && (n-i >= k-1); i++){
                temp = calculate(n-i, k-1) + (cum[n]-cum[n-i])*(i-cum[n]+cum[n-i]);
                if(temp < cost) cost = temp;
            }
            dp[n][k] = cost;
            return dp[n][k];
        }
    }

}

int main(){
    int n,k;
    int a,b,c;
    scanf("%d %d", &n, &k);
    cum[0] = 0;
    for(a = 1; a<=n; a++){
        scanf("%d", &cum[a]);
    }
    for(a = 1; a <= n; a++) cum[a] += cum[a-1];
    memset(dp, -1, sizeof(dp));
    printf("%d\n", calculate(n,k-1));
    return 0;
}
