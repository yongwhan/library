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

#define MAX 100
#define MOD 1000000007

typedef long long ll;

ll mat[MAX][MAX], res[MAX][MAX];

int getmul(ll res[MAX][MAX], ll mat[MAX][MAX], int n) {
	ll tmp[MAX][MAX];
	for (int i=0; i<n; i++)
	for (int j=0; j<n; j++) tmp[i][j]=0;

	for (int i=0; i<n; i++)
	for (int j=0; j<n; j++)
	for (int k=0; k<n; k++) tmp[i][j]=(tmp[i][j]+res[i][k]*mat[k][j])%MOD;

	for (int i=0; i<n; i++)
	for (int j=0; j<n; j++) res[i][j]=tmp[i][j];

	return 0;
}

int getexp(ll mat[MAX][MAX], int n, int e) {
	for (int i=0; i<n; i++)
	for (int j=0; j<n; j++) {
		if(i==j) res[i][j]=1;
		else res[i][j]=0;
	}
	while(e) {
		if(e%2) getmul(res,mat,n);
		getmul(mat,mat,n);
		e/=2;
	}
	return 0;
}

int main() {
	// getexp(mat,n,e) - initialize mat, n=dim, e=desired exp; hold results in res
	return 0;
}
