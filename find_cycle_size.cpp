#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx=1e6+5, mod=1e9+7;
int a[mx], dp[mx], vis[mx];
vector<int> cyc;
int cycct=0;

void dfs2(int u) {
	cyc[cycct]++;
	vis[u]=3;
	if(vis[a[u]]==3) return;
	dfs2(a[u]);
}

void dfs(int u) {
	vis[u]=2;
	if(!vis[a[u]]) dfs(a[u]);
	else if(vis[a[u]]==1) {
		vis[u]=1;
		return;
	}
	else {
		cyc.push_back(0);
		dfs2(u);
		cycct++;
	}
	vis[u]=1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin>>n;
	for (int i=1; i<=n; i++) cin>>a[i];
	dp[0]=1;
	for (int i=1; i<=n; i++)
		dp[i]=(dp[i-1]*2LL)%mod;

	ll ret=1;
	for (int i=1; i<=n; i++)
		if(!vis[i]) dfs(i);

	ll ct=n;
	for (int x : cyc) {
		ct-=x;
		ret=(ret*(dp[x]-2+mod))%mod;
	}
	ret=(ret*dp[ct])%mod;
	if(ret<0) ret+=mod;
	cout << ret << endl;
	return 0;
}
