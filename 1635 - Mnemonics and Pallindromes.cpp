#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#define MAX 4010
using namespace std;

int pal[MAX][MAX];
int fin[MAX];
int fin_track[MAX];
vector<string> sol;

int Min(int a, int b){
    return a<b?a:b;
}

void pal_map(string s){
    int len = s.size();
    int i,j;
    memset(pal, 0, sizeof(pal));
    for(i=len-1; i>=0;i--){
        for(j=i; j<len; j++){
            if(s[i] == s[j]){
                if(i+1 <= j-1){
                    if(pal[i+1][j-1] == 1) pal[i][j] = 1;
                    else pal[i][j] = 0;
                }
                else pal[i][j] = 1;
            }
            else pal[i][j] = 0;
        }
    }
}

void print_sol(string s, int i){
    if(i==-1) return;
    else{
        print_sol(s, fin_track[i]-1);
        if(fin_track[i]==0){
            cout<<s.substr(fin_track[i], i-fin_track[i]+1);
        }
        else{
            cout<<" "<<s.substr(fin_track[i], i-fin_track[i]+1);
        }
    }
}

void final_calc(string s){
    int i,j,len;
    memset(fin, 9999999, sizeof(fin));
    len = s.size();
    for(i=0; i<len; i++){
        fin_track[i] = i;
    }
    for(i=0;i<len;i++){
        if(pal[0][i] == 1){
            fin[i] = 1;
            fin_track[i] = 0;
        }
        else{
            for(j = 0; j<i; j++){
                int t;
                if(pal[j+1][i] == 1){
                    t = fin[j]+1;
                    if(t < fin[i]){
                        fin[i] = t;
                        fin_track[i] = j+1;
                    }
                }
                else{
                    t = fin[j]+(i-j);
                    if(t < fin[i]){
                        fin[i] = t;
                        fin_track[i] = i;
                    }
                }
            }
        }
    }
}

int main(){
    string in;
    cin >> in;
    pal_map(in);
    /*
    for(int i=0; i<in.size(); i++){
        for(int j=0; j<in.size(); j++){
            printf("%d ", pal[i][j]);
        }
        cout<<endl;
    }
    */
    final_calc(in);
    /*
    for(int i = 0; i<in.size(); i++)
        cout<<fin[i]<<" "<<fin_track[i]<<endl;
    */
    cout<<fin[in.size()-1]<<endl;
    print_sol(in, in.size()-1);
    cout<<endl;
    return 0;
}
