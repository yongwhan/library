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

// set up left and right sets

int r[MAX][MAX], m[MAX], m1[MAX], v[MAX], N,M;

int dfs(int a) {
	if(a<0) return(1);
	if(v[a]) return(0);
	v[a]=1;
	int i;
	for(i=0;i<M;i++) if(r[a][i]) {
		if(dfs(m1[i]))
		{
			m[a]=i;m1[i]=a;
			return(1);
		}
	}
	return(0);
}

int dfsExp(int a) {
	int i;
	for(i=0;i<N;i++) v[i]=0;
	return dfs(a);
}

int bipMatch() {
	int i;
	int ans=0;
	for(i=0;i<N;i++) m[i]=-1;
	for(i=0;i<M;i++) m1[i]=-1;
	for(i=0;i<N;i++) if(m[i]<0) ans+=dfsExp(i);
	return(ans);
}
