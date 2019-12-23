#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
typedef pair<int,int> pt;

inline double ccw(pt A, pt B, pt C) {
	return ((double)(B.x-A.x)*(C.y-B.y)-(B.y-A.y)*(C.x-B.x))/2.;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	return 0;
}
