#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#define MAXN 10010
#define MAXE 25000
using namespace std;

class edge{
    public:
    int u,v;
    int w;
};

edge eg[MAXE];
int edgei,N,K,M;
int parent[MAXN];
int size[MAXN];

bool compare(edge a,edge b){
    return a.w<b.w?true:false;
}

int find_parent(int x){
    if(parent[x]==x) return x;
    else return parent[x] = find_parent(parent[x]);
}

int kruskal(){
    //cout<<"entering kruskal"<<endl;
    int i,j,k;
    int ret=0;
    for(i=0;i<edgei;i++){
        int p=find_parent(eg[i].u);
        int q=find_parent(eg[i].v);
        if(p!=q){
            ret+=eg[i].w;
            if(size[q]>size[p]) swap(p,q);
            size[p]+=size[q];
            parent[q]=p;
        }
    }
    //cout<<"returning "<<ret<<endl;
    return ret;
}

bool check(){
    int a=parent[0];
    for(int i=0;i<N;i++){
        if(parent[i]!=a) return false;
    }
    return true;
}

int main(){
    int i,j,k;
    while(cin>>N>>K>>M){
        edgei=0;
        for(i=0;i<K;i++){
            cin>>j>>k;
            eg[edgei].u=j;
            eg[edgei].v=k;
            eg[edgei].w=0;
            edgei++;
        }
        for(i=0;i<M;i++){
            cin>>j>>k;
            eg[edgei].u=j;
            eg[edgei].v=k;
            eg[edgei].w=1;
            edgei++;
        }
        sort(eg,eg+edgei,compare);
        for(i=0;i<N;i++){
            parent[i]=i;
            size[i]=1;
        }
        int ret = kruskal();
        printf("%d\n",ret);
    }
    return 0;
}
