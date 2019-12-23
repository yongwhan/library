#include<bits/stdc++.h>
using namespace std;

const int INF=1e9+777;

int dp[16][1<<16], w[16][16], N;

int dfs(int n, int v) {
	if(dp[n][v]!=-1)
		return dp[n][v];
	if(v==(1<<N)-1)
		return w[n][0]?w[n][0]:INF;
	dp[n][v]=INF;
	for(int i = 0; i < N; i++) {
		if((v&(1<<i))||w[n][i]==0) continue;
		dp[n][v]=min(dp[n][v],dfs(i,v|(1<<i))+w[n][i]);
	}
	return dp[n][v];
}

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d",&w[i][j]);
	memset(dp,-1,sizeof(dp));
	printf("%d\n",dfs(0,1));
	return 0;
}
