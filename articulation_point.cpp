#include<bits/stdc++.h>
using namespace std;

int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

set<int> ret;
void IS_CUTPOINT(int x) {
	ret.insert(x);
}

void dfs(int v, int p = -1) {
	visited[v] = true;
	tin[v] = low[v] = timer++;
	int children=0;
	for (int to : adj[v]) {
		if (to == p) continue;
		if (visited[to]) {
			low[v] = min(low[v], tin[to]);
		} else {
			dfs(to, v);
			low[v] = min(low[v], low[to]);
			if (low[to] >= tin[v] && p!=-1)
				IS_CUTPOINT(v);
			++children;
		}
	}
	if(p == -1 && children > 1)
		IS_CUTPOINT(v);
}

void find_cutpoints() {
	timer = 0;
	visited.assign(n, false);
	tin.assign(n, -1);
	low.assign(n, -1);
	for (int i = 0; i < n; ++i) {
		if (!visited[i])
			dfs (i);
	}
}

int main() {
	cin>>n; int m; cin>>m;
	adj.resize(n);
	for (int i=0; i<m; i++) {
		int x,y; cin>>x>>y; x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	find_cutpoints();
	cout<<ret.size()<<endl;
	for (const int &x:ret)
		cout<<x+1<<" ";
	cout<<endl;
	return 0;
}
