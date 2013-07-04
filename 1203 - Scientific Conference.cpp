#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class ss{
public:
    int s;
    int e;
};

vector<ss> v;

bool compare(ss a, ss b){
    if(b.e<a.e) return false;
    else if(a.e<b.e) return true;
    else{
        if(b.s<a.s) return false;
        else return true;
    }
}

int main(){
    int n;
    ss s;
    cin>>n;
    while(n--){
        cin >> s.s >> s.e;
        v.push_back(s);
    }
    sort(v.begin(),v.end(),compare);
    //vector<bool> color(v.size(),false);
    int cnt=0;
    int last=-1;
    for(int i=0; i<v.size();i++){
        if(v[i].s>last){
            cnt++;
            last = v[i].e;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
