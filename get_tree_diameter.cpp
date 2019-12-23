#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int mx=1e5+777;
int n;
vector<vector<int>> adj(mx);

int bfs(int init) {
	queue<int> q; q.push(init);
	set<int> vis; vis.insert(init);
	int last=-1;
	while(!q.empty()) {
		int cur=q.front(); q.pop();
		last=cur;
		for (auto nxt : adj[cur])
			if(vis.find(nxt)==vis.end())
				vis.insert(nxt),
				q.push(nxt);
	}
	return last;
}

int bfs2(int init) {
	queue<int> q; q.push(init);
	vector<int> dist(n,-1);
	dist[init]=0;
	while(!q.empty()) {
		int cur=q.front(); q.pop();
		for (auto nxt : adj[cur])
			if(dist[nxt]==-1)
				q.push(nxt),
				dist[nxt]=dist[cur]+1;
	}
	return *max_element(dist.begin(), dist.end());
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int m; scanf("%d %d", &n, &m);
	for (int i=0; i<m; i++) {
		int a,b; scanf("%d %d", &a, &b);
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	printf("%d\n", bfs2(bfs(0)));
	return 0;
}
