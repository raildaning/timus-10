/*
Take n=5 for example

The permutations are:

1 2 3 4 5
1 2 3 5 4
1 2 4 3 5
1 2 4 5 3
1 3 2 4 5
1 3 5 4 2

a[i-1] stands for the first four, beginning with '1 2'. If you ignore 1, you have the same prob for N=i-1.
a[i-3] stands for the fifth, beginning with '1 3 2 4'. If you ignore 1, 3, 2, you have the same prob for N=i-3.
And a special case (the last) -- all the odds in increasing order, followed by all the evens in decreasing order. The is what the +1 in the formula means.
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 60
using namespace std;

long long int arr[MAX];

long long int dp(int n){
	if(arr[n] == -1){
		if(n==1) arr[n] = 1;
		else if(n==2) arr[n] = 1;
		else if(n==3) arr[n] = 2;
		else arr[n] = dp(n-1)+dp(n-3)+1;
	}
	return arr[n];
}

int main(){
	int n;
	for(int i=0;i<MAX;i++) arr[i] = -1;
	scanf("%d",&n);
	//dp(n);
	//for(int i=0;i<=n;i++) printf("%d\n",arr[i]);
	printf("%lld\n",dp(n));
	return 0;
}
