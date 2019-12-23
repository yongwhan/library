#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin>>s;
  int n=s.size();
  vector<vector<int>> adj(n);
  vector<vector<bool>> pal(n, vector<bool>(n,false));
  for (int i=0; i<n; i++)
    pal[i][i]=true;
  for (int l=2; l<=n; l++) {
    for (int i=0; i<=n-l; i++) {
      int j=i+l-1, ii=i+1, jj=j-1;
      pal[i][j]=true;
      if(s[i]!=s[j]) pal[i][j]=false;
      if(ii<=jj&&!pal[ii][jj]) pal[i][j]=false;
    }
  }
  for (int i=0; i<n; i++)
    for (int j=i; j<n; j++)
      if(pal[i][j])
        adj[i].push_back(j+1);
  vector<int> memo(n+1,inf);
  memo[n]=0;
  vector<int> par(n+1,-1);
  for (int i=n-1; i>=0; i--) {
    int cur=inf;
    for (auto j : adj[i]) {
      int val=memo[j]+1;
      if(cur>val) cur=val, par[i]=j;
    }
    memo[i]=cur;
  }
  cout<<memo[0]<<endl;
  return 0;
}
