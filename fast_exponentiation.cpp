#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// compute for p^n%m
	int n,m,p,ret=1; cin>>n>>m>>p;
	while(n) {
		if(n&1) ret=ret*p%m;
		n>>=1, p=p*p%m;
	}
	cout << ret << endl;
	return 0;
}
