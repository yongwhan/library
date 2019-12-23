#include<bits/stdc++.h>
using namespace std;

const int mx=1005;

int C[mx][mx];
string s,t;
string backtrack(int i, int j) {
	if(i==0||j==0) return "";
	else if (s[i-1]==t[j-1]) return backtrack(i-1,j-1)+s[i-1];
	else {
		if (C[i][j-1]>C[i-1][j]) return backtrack(i,j-1);
		else return backtrack(i-1,j);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>s>>t;
	int n=s.size(), m=t.size();
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=m; j++) {
			C[i][j]=0;
		}
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if(s[i-1]==t[j-1]) C[i][j]=C[i-1][j-1]+1;
			else C[i][j]=max(C[i][j-1],C[i-1][j]);
		}
	}
	cout << C[n][m] << endl;
	cout << backtrack(n,m) << endl;
	return 0;
}
