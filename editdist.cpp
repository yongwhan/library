#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime> 
#define MAX 2500
using namespace std;

int dp[MAX][MAX];

int editdist(string s, string t) {
	int n=s.size(), m=t.size();
	for (int i=0; i<=n; i++) dp[i][0]=i;
	for (int j=0; j<=m; j++) dp[0][j]=j;
	for (int j=1; j<=m; j++)
	for (int i=1; i<=n; i++) {
		if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1];
		else {
			int cur=dp[i-1][j]+1; // deletion
			cur=min(cur,dp[i][j-1]+1); // insertion
			cur=min(cur,dp[i-1][j-1]+1); // substitution
			dp[i][j]=cur;
		}
	}
	return dp[n][m];
}

int main() {
	int t; cin>>t;
	while(t--) {
		string s,t; cin>>s>>t; cout << editdist(s,t) << endl;
	}
	return 0;
}
