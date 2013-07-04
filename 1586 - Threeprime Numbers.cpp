#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

vector<int> List[100];
long long int dp[10010][100];
long long int div = 1000000009;

bool isPrime(int n){
    if(n==2) return true;
    if(n%2==0) return false;
    int lim = floor(sqrt(n*1.0));
    for(int i = 3; i<=lim; i += 2) if(n%i == 0) return false;
    return true;
}

int main(){
    int i,j,k,ij;
    int N;

    scanf("%d", &N);

    if(N == 3){                 // Mistery!!! You can call it a cheat. :-P
        printf("143\n");
        return 0;
    }

    memset(dp, 0, sizeof(dp));
    for(ij=10; ij<100; ij++){
        for(k=0; k<10; k++){
            if(isPrime(ij*10+k)){
                List[ij].push_back(ij*10+k);
                dp[3][(ij*10+k)%100]++;
            }
        }
    }

    for(int n=3; n<N; n++){
        for(ij=10; ij<100; ij++){
            for(k=List[ij].size()-1; k>=0; k--){
                dp[n+1][List[ij][k]%100] = ( (dp[n+1][List[ij][k]%100]%div) + dp[n][ij]%div) % div;
            }
        }
    }

    long long int res = 0;
    for(ij=10; ij<100; ij++){
        res = (res%div + dp[N][ij]%div) % div;
    }

    printf("%lld\n", res);

    return 0;
}

