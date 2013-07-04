#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 25
#define MAXCONF 1050000
#define MAXVAL 100000
#define u_int unsigned int
using namespace std;

u_int N;
u_int balcony[MAXN];
u_int moves[MAXN];
u_int damage[MAXCONF];
u_int dp[MAXCONF];

void print_bin(u_int n){
        u_int mask = 1 << (N-1);
        for(int i=0; i<N; i++){
        	if((n & mask) != 0){
            		cout<<"1";
        	}
        	else cout << "0";
            mask = mask >> 1;
    	}
    	cout << endl;
}

u_int calculate_damage(u_int bitmap){
        u_int i;
    	u_int mask = 1 << (N-1);
    	u_int temp[MAXN];

    	memcpy(temp, balcony, sizeof(balcony));

    	for(i=0; i<N; i++){
        	if((bitmap & mask) != 0){
            		temp[i] = 0;
        	}
            mask = mask >> 1;
    	}

    	u_int ret = 0;
    	for(i=0; i<N; i++){
        	ret += temp[i];
    	}
    	return ret;
}

u_int solve(u_int bitmap){
    if(dp[bitmap] == -1){
        u_int i;
        for(i=0; i<N; i++){
            bool isValid = false;
            if((moves[i]&bitmap)==0) isValid=true;
            if((moves[(i+1)%N]&bitmap)==0) isValid=true;
            if((moves[(i+2)%N]&bitmap)==0) isValid=true;

            if(isValid == false) continue;

            u_int mask = bitmap;
            mask = mask | moves[i];
            mask = mask | moves[(i+1)%N];
            mask = mask | moves[(i+2)%N];
            u_int temp = solve(mask) + damage[mask];
            if(temp < dp[bitmap] || dp[bitmap] == -1){
                    dp[bitmap] = temp;
            }
        }
        if(dp[bitmap] != -1) return dp[bitmap];
        else{
            dp[bitmap] = 0;
            return dp[bitmap];
        }
    }
    return dp[bitmap];
}


int main(){
    	u_int i,j,k;
    	scanf("%u", &N);
    	for(i=0; i<N; i++){
        	scanf("%u", &balcony[i]);
    	}

        u_int lim = (u_int)1 << N;
    	memset(damage, MAXVAL, sizeof(damage));
    	for(i=0; i<lim; i++){
        	damage[i] = calculate_damage(i);
    	}

        memset(dp, -1, sizeof(dp));
        moves[0] = (u_int)1 << (N-1);
        for(i=1; i<N; i++){
            moves[i] = moves[i-1] >> 1;
        }

        u_int res = solve((u_int)0);
        printf("%u\n", dp[0]);

    	return 0;
}
