#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAX_V=1e5+5, INF=1e15;
typedef pair<ll,ll> ii;
int V;

vector<ii> adj[MAX_V];

map<ll,ll> pa;

vector<ll> dijkstra(ll src) {
	vector<ll> dist(V, INF);
	dist[src]=0;
	priority_queue<ii> pq;
	pq.push(make_pair(0,src));
	while(!pq.empty()) {
		ll cost=-pq.top().first, here=pq.top().second;
		pq.pop();
		if(dist[here]<cost) continue;
		for (int i=0; i<adj[here].size(); i++) {
			ll there=adj[here][i].first, nextDist=cost+adj[here][i].second;
			if(dist[there]>nextDist) {
				dist[there]=nextDist;
				pq.push(make_pair(-nextDist, there));
				pa[there]=here;
			}
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m; cin>>n>>m;
	for (int i=0; i<m; i++) {
		ll a,b,w; cin>>a>>b>>w; a--; b--;
		adj[a].push_back(make_pair(b,w));
		adj[b].push_back(make_pair(a,w));
	}
	V=n;
	vector<ll> dist=dijkstra(0);

	if(dist[n-1]==INF) { cout << -1 << endl; return 0; }

	int cur=n-1;
	vector<ll> ret;
	while(1) {
		ret.push_back(cur+1);
		if(cur==0) break;
		cur=pa[cur];
	}

	int sz=ret.size();
	for (int i=0; i<sz; i++) {
		if(i) cout << " ";
		cout << ret[sz-1-i];
	}
	cout << endl;
	return 0;
}
