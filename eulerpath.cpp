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

#define MAX 505
int conn[MAX][MAX];
int deg[MAX];

int pos=0;
int path[2000];

void find_circuit(int x) {
	if(!deg[x]) {
		path[pos++]=x;
	} else {
		while(1) {
			if(!deg[x]) break;
			for (int y=0; y<MAX; y++) {
				if(conn[x][y]) {
					deg[x]--; deg[y]--;
					conn[x][y]--; conn[y][x]--;
					find_circuit(y);
				}
			}
		}
		path[pos++]=x;
	}
}

int main() {
	for (int i=0; i<MAX; i++) {
		deg[i]=0;
		for (int j=0; j<MAX; j++)
			conn[i][j]=0;
	}

	int m; cin>>m;
	for (int i=0; i<m; i++) {
		int x,y; fin>>x>>y;
		deg[x]++; deg[y]++;
		conn[x][y]++; conn[y][x]++;
	}

	int cur=-1;
	for (int i=0; i<MAX; i++)
		if(deg[i]%2) { cur=i; break; }

	if(cur==-1) {
		for (int i=0; i<MAX; i++)
			if(deg[i]) { cur=i; break; }
	}

	find_circuit(cur);

	for (int i=0; i<pos; i++) cout << path[pos-1-i] << endl;
	return 0;
}
