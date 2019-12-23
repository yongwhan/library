#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

// smallest key at least k
int lbd(map<int,int> &mp, int k) {
	auto it=mp.lower_bound(k);
	if(it==mp.end()) return -1;
	return it->first;
}

// greatest key at most k
int ubd(map<int,int> &mp, int k) {
	auto it=mp.upper_bound(k);
	if(it==mp.begin()) return -1;
	it--;
	return it->first;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	map<int,int> mp;
	return 0;
}
