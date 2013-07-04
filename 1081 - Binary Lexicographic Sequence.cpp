#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

long long int dp[45][3];

void precalc(){
    memset(dp,0,sizeof(dp));
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = dp[1][0]+dp[1][1];

    for(int i=2; i<45; i++){
        dp[i][0] = dp[i-1][2];
        dp[i][1] = dp[i-1][0];
        dp[i][2] = dp[i][0]+dp[i][1];
    }
}

void print_sol(long long int n, long long int k){
    if(n == 1){
        if(k > 2){
            cout<<"-1";
            return;
        }
        else if(k > 1){
            cout << "1";
            return;
        }
        else{
            cout<<"0";
            return;
        }
    }
    else{
        if(k > dp[n][2]){
            cout<<"-1";
            return;
        }
        else{
            if(k > dp[n][0]){
                cout<<"1";
                print_sol(n-1, k-dp[n][0]);
            }
            else{
                cout<<"0";
                print_sol(n-1, k);
            }
        }
    }
}

int main(){
    precalc();
    //cout << dp[43][2]<<endl;
    long long int n,k;
    cin >> n >> k;
    print_sol(n,k);
}
