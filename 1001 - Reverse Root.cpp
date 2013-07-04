#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int main(){
	double a;
	vector<double> v;
	while(cin >> a){
		v.push_back(sqrt(a));
	}
	for(int i=v.size()-1; i>=0 ; i--){
		printf("%0.4lf\n",v[i]);
	}
	return 0;
}
