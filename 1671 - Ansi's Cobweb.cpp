/*****************************************

Streightforward disjoint set problem
with a little tricks. I unioned all
edges except the ones which are to be
deleted. Then I unioned those deleteListed
edges by scanning one by one from backward
of the list. At each step of union one answer
is found.

*****************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#define MAX 100000
using namespace std;

class edge{
public:
    int u,v;
    bool doesExist;
};

int N, M, Q;
vector<edge> edgeList;
int parent[MAX];
int size[MAX];
int delList[MAX];
int compCount;

int find_parent(int n)
{
    if(parent[n] == n) return n;
    else{
        parent[n] = find_parent(parent[n]);
        return parent[n];
    }
}

int main(){
    compCount = 0;
    int i,j,k;
    edge temp;
    scanf("%d %d", &N, &M);

    for(i = 1; i < N; i++){
        parent[i] = i;
        size[i] = 1;
    }
    compCount = N;

    edgeList.push_back(temp);   //pushing a dummy edge
    for(i = 1; i <= M; i++){
        cin >> temp.u >> temp.v;
        temp.doesExist = true;
        edgeList.push_back(temp);
    }

    cin >> Q;
    for(i = 0; i < Q; i++){
        cin >> delList[i];
        edgeList[delList[i]].doesExist = false;
    }

    for(i=1; i<=M; i++){
        if(edgeList[i].doesExist == true){
            int p = find_parent(edgeList[i].u);
            int q = find_parent(edgeList[i].v);

            if(p != q){     //This means two set need to be merged and one component is decreased
                compCount--;
                if(size[p] >= size[q]){
                    size[p] += size[q];
                    parent[q] = p;
                }
                else{
                    size[q] += size[p];
                    parent[p] = q;
                }
            }
        }
    }

    stack<int> ans;
    for(i=Q-1; i>=0; i--){
        ans.push(compCount);
        int p = find_parent(edgeList[delList[i]].u);
        int q = find_parent(edgeList[delList[i]].v);

        if(p != q){     //This means two set need to be merged and one component is decreased
            compCount--;
            if(size[p] >= size[q]){
                size[p] += size[q];
                parent[q] = p;
            }
            else{
                size[q] += size[p];
                parent[p] = q;
            }
        }
    }

    //cout << compCount << endl;
    while(ans.size() != 0){
        cout << ans.top();
        ans.pop();
        if(ans.size() != 0) cout << ' ';
    }
    cout << endl;
    return 0;
}
