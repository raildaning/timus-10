#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int main(){
    char ex[25];
    int n;
    while(cin>>n>>ex){
        int k=strlen(ex);
        if(n%k==0){
            int ans=1;
            int cnt=n/k;
            for(int i=0;i<cnt;i++){
                ans*=(n-i*k);
            }
            cout<<ans<<endl;
        }
        else{
            int ans=1;
            int cnt=n/k;
            for(int i=0;i<=cnt;i++){
                ans*=(n-i*k);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
