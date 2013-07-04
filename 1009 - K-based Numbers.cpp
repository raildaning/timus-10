/*
How can we get valid n-digit number? Trivially, we can append each of (k-1) possible digits (k digits except for 0) to the front of each of (n-1)-digit valid numbers.
But we can also form valid number this way: append 0 to the front of (n-2)-digit valid number, and then append (k-1) possible digits, as in the first case.

This gives us F(n) = (k-1)*F(n-1)+(k-1)*F(n-2), where F is the function to yield the amount of valid n-digit numbers.
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#define MAX 20
using namespace std;

int main(){
    int N,K;
    long long int arr[MAX];
    while(scanf("%d %d",&N,&K)!=EOF){
        memset(arr,0,sizeof(arr));
        arr[0]=1;
        arr[1]=K-1;
        for(int i=2;i<=N;i++){
            arr[i]=(K-1)*(arr[i-1]+arr[i-2]);
        }
        printf("%lld\n",arr[N]);
    }
    return 0;
}
