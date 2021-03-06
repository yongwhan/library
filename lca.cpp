#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

struct LCA {
	vector<int> height, euler, first, segtree, d_to_r;
	vector<bool> visited;
	int n;

	LCA(vector<vector<ii>> &adj, int root = 0) {
		n = adj.size();
		d_to_r.resize(n);
		height.resize(n);
		first.resize(n);
		euler.reserve(n * 2);
		visited.assign(n, false);
		d_to_r[root]=0;
		dfs(adj, root);
		int m = euler.size();
		segtree.resize(m * 4);
		build(1, 0, m - 1);
	}

	void dfs(vector<vector<ii>> &adj, int node, int h = 0) {
		visited[node] = true;
		height[node] = h;
		first[node] = euler.size();
		euler.push_back(node);
		for (auto to : adj[node]) {
			if (!visited[to.first]) {
				d_to_r[to.first]=d_to_r[node]+to.second;
				dfs(adj, to.first, h + 1);
				euler.push_back(node);
			}
		}
	}

	void build(int node, int b, int e) {
		if (b == e) {
			segtree[node] = euler[b];
		} else {
			int mid = (b + e) / 2;
			build(node << 1, b, mid);
			build(node << 1 | 1, mid + 1, e);
			int l = segtree[node << 1], r = segtree[node << 1 | 1];
			segtree[node] = (height[l] < height[r]) ? l : r;
		}
	}

	int query(int node, int b, int e, int L, int R) {
		if (b > R || e < L)
			return -1;
		if (b >= L && e <= R)
			return segtree[node];
		int mid = (b + e) >> 1;

		int left = query(node << 1, b, mid, L, R);
		int right = query(node << 1 | 1, mid + 1, e, L, R);
		if (left == -1) return right;
		if (right == -1) return left;
		return height[left] < height[right] ? left : right;
	}

	int lca(int u, int v) {
		int left = first[u], right = first[v];
		if (left > right)
			swap(left, right);
		return query(1, 0, euler.size() - 1, left, right);
	}

	int dist(int u, int v) {
		return d_to_r[u]+d_to_r[v]-2*d_to_r[lca(u,v)];
	}
};

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,m,u,v,w; cin>>n;
	vector<vector<ii>> adj(n);
	for (int i=0; i<n-1; i++)
		cin>>u>>v>>w, adj[u].push_back({v,w}), adj[v].push_back({u,w});
	LCA lca(adj);
	cin>>m;
	for (int i=0; i<m; i++)
		cin>>u>>v, cout<<lca.dist(u,v)<<endl;
	return 0;
}
