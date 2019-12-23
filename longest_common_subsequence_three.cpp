#include<bits/stdc++.h>
using namespace std;

const int mx=105;

int C[mx][mx][mx];
string s,t,u;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>s>>t>>u;
	int n=s.size(), m=t.size(), l=u.size();
	for (int i=0; i<=n; i++)
		for (int j=0; j<=m; j++)
			for (int k=0; k<=l; k++)
				C[i][j][k]=0;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			for (int k=1; k<=l; k++) {
				if(s[i-1]==t[j-1]&&t[j-1]==u[k-1]) C[i][j][k]=C[i-1][j-1][k-1]+1;
				else C[i][j][k]=max(C[i][j][k-1], max(C[i][j-1][k], C[i-1][j][k]));
			}
		}
	}
	cout << C[n][m][l] << endl;
	return 0;
}
