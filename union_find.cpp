#include<bits/stdc++.h>
using namespace std;

const int mx=1e6+5;

int par[mx], rnk[mx];

void init(int n) {
	for (int i=0; i<n; i++)
		par[i]=i, rnk[i]=0;
}

int find(int x) {
	if(par[x]==x) return x;
	else return par[x]=find(par[x]);
}

void unite(int x, int y) {
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(rnk[x]<rnk[y]) par[x]=y;
	else {
		par[y]=x;
		if(rnk[x]==rnk[y]) rnk[x]++;
	}
}

bool same(int x, int y) {
	return find(x)==find(y);
}

int main() {
	int n,m; scanf("%d %d", &n, &m);
	init(n+1);
	for (int i=0; i<m; i++) {
		int c,x,y; scanf("%d %d %d", &c, &x, &y);
		if(c) {
			if(same(x,y)) printf("YES\n");
			else printf("NO\n");
		} else unite(x,y);
	}
	return 0;
}
