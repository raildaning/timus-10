#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 60010
using namespace std;

int arr[MAX];

int Min(int a, int b){
    return (a<b?a:b);
}

int main(){
    int i,j;
    arr[0] = 0;
    for(i = 1; i <= 60000; i++){
        arr[i] = i;
        for(j=0; j*j <= i; j++){
            arr[i] = Min(arr[i], arr[i-j*j]+1);
        }
    }
    int n;
    scanf("%d", &n);
    printf("%d\n", arr[n]);
    return 0;
}
