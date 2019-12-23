#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long ll;

const ll INF=1e15;

// return true if good; return false if bad.
bool C(int d) {
	return true;
}

int main() {
	ll lb=0, ub=INF;
	while(ub-lb>1) {
		ll mid=(lb+ub)/2;
		if(C(mid)) lb=mid;
		else ub=mid;
	}
	cout << lb << endl;
	return 0;
}
