/***************************************************************************

mat[i][j] -> number of staircases with exactly i bricks having upto j height.

A staircase having i bricks and upto j height can be formed in two ways.
1) It has height less than j
2) It has height exactly equal to j

no (1) is exactly mat[i][j-1].
But no (2) can be done by adding a column of j bricks
at the end of some staircase that has been built by i-j bricks and have height
at most j-1 or, i-j if j-1 is greater than i-j.

****************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 510
using namespace std;

long long int mat[MAX][MAX];

long long int Max(long long int a, long long int b){
    return (a>b?a:b);
}

long long int Min(long long int a, long long int b){
    return (a<b?a:b);
}

int main(){
    int n;
    int i,j;
    scanf("%d", &n);
    mat[0][0] = 1;
    for(i=1;i<=n;i++){
        for(j=1; j<=i; j++){
            mat[i][j] += mat[i][j-1] + mat[i-j][Max(0, Min(i-j, j-1))];
        }
    }
    printf("%lld\n", mat[n][n] - 1);
    return 0;
}
