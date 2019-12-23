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
#define MAX 205
using namespace std;

bool conn[MAX][MAX];
int dist[MAX];

int bfs(int init) {
	memset(dist, -1, sizeof(dist));
	dist[init]=0;
	queue<int> q; q.push(init);

	int val=0;
	while(!q.empty()) {
		int cur=q.front(); q.pop();
		for (int nxt=0; nxt<MAX; nxt++)
		if(conn[nxt][cur] && dist[nxt]==-1) {
			dist[nxt]=dist[cur]+1;
			val=max(val, dist[nxt]);
			q.push(nxt);
		}
	}

	int ans=-1;
	for (int i=0; i<MAX; i++) if(dist[i]==val) ans=i;
	return ans;
}

int get_diam(int cur) {
	bfs(bfs(cur));
	int ans=0;
	for (int i=0; i<MAX; i++) {
		int cur=dist[i];
		if(cur!=-1) ans=max(ans,cur);
	}
	return ans;
}

int main() {
	return 0;
}
