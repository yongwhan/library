#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
using namespace std;

const double EPS = 1e-10;

typedef vector<int> VI;
typedef double T;
typedef vector<T> VT;
typedef vector<VT> VVT;

T GaussJordan(VVT &a, VVT &b) {
  const int n = a.size();
  const int m = b[0].size();
  VI irow(n), icol(n), ipiv(n);
  T det = 1;

  for (int i = 0; i < n; i++) {
    int pj = -1, pk = -1;
    for (int j = 0; j < n; j++) if (!ipiv[j])
      for (int k = 0; k < n; k++) if (!ipiv[k])
	if (pj == -1 || fabs(a[j][k]) > fabs(a[pj][pk])) { pj = j; pk = k; }
    if (fabs(a[pj][pk]) < EPS) { cerr << "Matrix is singular." << endl; exit(0); }
    ipiv[pk]++;
    swap(a[pj], a[pk]);
    swap(b[pj], b[pk]);
    if (pj != pk) det *= -1;
    irow[i] = pj;
    icol[i] = pk;

    T c = 1.0 / a[pk][pk];
    det *= a[pk][pk];
    a[pk][pk] = 1.0;
    for (int p = 0; p < n; p++) a[pk][p] *= c;
    for (int p = 0; p < m; p++) b[pk][p] *= c;
    for (int p = 0; p < n; p++) if (p != pk) {
      c = a[p][pk];
      a[p][pk] = 0;
      for (int q = 0; q < n; q++) a[p][q] -= a[pk][q] * c;
      for (int q = 0; q < m; q++) b[p][q] -= b[pk][q] * c;      
    }
  }

  for (int p = n-1; p >= 0; p--) if (irow[p] != icol[p]) {
    for (int k = 0; k < n; k++) swap(a[k][irow[p]], a[k][icol[p]]);
  }

  return det;
}

double getvol() {
	double p,q,r,s,t,u; cin>>p>>q>>r>>s>>t>>u;
	p*=p; q*=q; r*=r; s*=s; t*=t; u*=u;
	VVT a, b;
	VT tmp(5);
	tmp[0]=0; tmp[1]=1; tmp[2]=1; tmp[3]=1; tmp[4]=1; a.push_back(tmp);
	tmp[0]=1; tmp[1]=0; tmp[2]=p; tmp[3]=q; tmp[4]=r; a.push_back(tmp);
	tmp[0]=1; tmp[1]=p; tmp[2]=0; tmp[3]=s; tmp[4]=t; a.push_back(tmp);
	tmp[0]=1; tmp[1]=q; tmp[2]=s; tmp[3]=0; tmp[4]=u; a.push_back(tmp);
	tmp[0]=1; tmp[1]=r; tmp[2]=t; tmp[3]=u; tmp[4]=0; a.push_back(tmp);
	b=a;

	double ans=GaussJordan(a,b);
	return sqrt(ans/288);
}
