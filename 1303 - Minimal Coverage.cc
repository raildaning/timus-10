#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define INF 9999999
using namespace std;

class segment{
public:
    int left_point;
    int right_point;
};

bool compare(segment a, segment b){
    if(a.left_point < b.left_point) return true;
    else if(a.left_point > b.left_point) return false;
    else{
        if(a.right_point >= b.right_point) return true;
        else return false;
    }
}

int main(){
    int M;
    vector<segment> v;
    vector<segment> sol;
    segment s;
    int left_covered = 0;
    int right_covered = 0;

    cin >> M;
    while(cin >> s.left_point >> s.right_point){
        if(s.left_point == 0 && s.right_point == 0) break;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), compare);

    for(int i=0; i<v.size(); i++){
        int track = -1;
        while(i < v.size() && v[i].left_point <= left_covered){
            if(v[i].right_point >= right_covered){
                right_covered = v[i].right_point;
                track = i;
            }
            i++;
        }

        if(track == -1) break;
        sol.push_back(v[track]);
        left_covered = right_covered;
        if(right_covered >= M) break;
        i--;
    }

    if(right_covered >= M){
        cout << sol.size() << endl;
        for(int i=0; i<sol.size(); i++){
            cout<<sol[i].left_point << " " << sol[i].right_point<<endl;
        }
    }
    else{
        cout << "No solution" << endl;
    }
}
