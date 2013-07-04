#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAX 1010
using namespace std;

bool map[MAX][MAX];
float inf = 99999999999.0;

float minimum(float a, float b, float c){
    if(a<b){
        if(a<c) return a;
        else return c;
    }
    else{
        if(b<c) return b;
        else return c;
    }
}

int main(){
    int i,j,k,N,M;
    int a,b;
    memset(map,false,sizeof(map));
    const float diag = sqrt(2.00*10000.0);
    cin>>N>>M>>k;
    while(k--){
        cin>>a>>b;
        map[b][a] = true;
    }
    float dp[2][MAX];
    for(i=0;i<=M;i++){
        for(j=0;j<=N;j++){
            if(i==0) dp[1][j] = j * 100.0;
            else{
                if(j==0) dp[1][j] = dp[0][j]+100.0;
                else{
                    if(map[i][j]==true){                        dp[1][j] = minimum(dp[0][j]+100.0, dp[1][j-1]+100.0, dp[0][j-1]+diag);
                    }
                    else dp[1][j] = minimum(dp[0][j]+100.0, dp[1][j-1]+100.0, inf);
                }
            }
        }
        //for(j=0;j<=N;j++) dp[0][j] = dp[1][j];
        memcpy(dp[0],dp[1],sizeof(dp[1]));
    }
    printf("%0.0f\n",dp[0][N]);
    return 0;
}
