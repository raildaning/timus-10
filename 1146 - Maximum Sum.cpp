#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 110
using namespace std;

int n;
int grid[MAX][MAX];

int max(int a, int b){
    return a>b?a:b;
}

int kadane(int arr[]){
    int i=0;
    int max_so_far=0, max_ending_here=0;
    for(i=0;i<n;i++){
        max_ending_here = max(0,max_ending_here+arr[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

int main(){
    scanf("%d",&n);
    int i,j;
    const int neg_inf = -999999999;
    int raw_res = neg_inf;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &grid[i][j]);
            raw_res = max(raw_res,grid[i][j]);
        }
    }
    int res=0;
    for(i=0;i<n;i++){
        int arr[MAX]={0};
        for(j=i;j<n;j++){
            for(int k=0;k<n;k++) arr[k] += grid[j][k];
            res = max(res, kadane(arr));
        }
    }
    if(raw_res >= 0) printf("%d\n",res);
    else printf("%d\n",raw_res);
    return 0;
}
