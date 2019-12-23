#include <fstream>
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
using namespace std;

#define MAX 1000
vector<int> r[MAX];
vector<int> e[MAX];
int dist[MAX][MAX];
int pa[MAX][MAX];
int ct[MAX];
multimap<int,int> h;

int main() {
	int n,p,c; cin>>n>>p>>c;
	for (int i=0; i<MAX; i++) {
		ct[i]=0;
		for (int j=0; j<MAX; j++) pa[i][j]=dist[i][j]=-1;
	}

	for (int i=0; i<n; i++) {
		int x; fin>>x; ct[x]++;
	}

	for (int i=0; i<c; i++) {
		int x,y,z; fin>>x>>y>>z;
		r[x].push_back(y);
		r[y].push_back(x);
		e[x].push_back(z);
		e[y].push_back(z);
	}

	// all-pair shortest path

	for (int s=1; s<=p; s++) {

		// single source (with source s) shortest path

		int d,tmp, v,i,j;
		multimap<int,int>::iterator it;
		dist[s][s]=0;
		h.clear();
		h.insert(multimap<int,int>::value_type(0,s));
		while(!h.empty()) {
			it=h.begin();
			v=(*it).second;
			d=(*it).first;
			h.erase(it);
			for (i=0; i<r[v].size(); i++) {
				tmp=d+e[v][i];
				j=r[v][i];
				if(dist[s][j]<0 || tmp<dist[s][j]) {
					dist[s][j]=tmp;
					pa[s][j]=v;
					h.insert(multimap<int,int>::value_type(tmp,j));
				}
			}
		}
	}

	int ans=-1;
	for (int i=1; i<=p; i++) {
		int cur=0;
		for (int j=1; j<=p; j++) cur+=dist[j][i]*ct[j];
		if(ans==-1) ans=cur;
		else ans=min(ans,cur);
	}
	fout << ans << endl;
	return 0;
}
