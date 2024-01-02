#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order
// order_of_key

typedef long long ll;

int n, k;
vector<vector<int>> g;
vector<int> mt;
vector<bool> used;

bool try_kuhn(int v) {
  if (used[v])
    return false;
  used[v] = true;
  for (int to : g[v]) {
    if (mt[to] == -1 || try_kuhn(mt[to])) {
      mt[to] = v;
      return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin>>n>>k;
  g.assign(n,vector<int>());
  int m; cin>>m;
  for (int i=0; i<m; i++) {
    int a,b; cin>>a>>b; a--; b--;
    g[a].push_back(b);
  }
  mt.assign(k, -1);
  for (int v = 0; v < n; ++v) {
    used.assign(n, false);
    try_kuhn(v);
  }
  int ret=0;
  for (int i=0; i<k; i++)
    if(mt[i]!=-1) ret++;
  cout<<ret<<"\n";
  for (int i = 0; i < k; ++i)
    if (mt[i] != -1)
      cout<<mt[i]+1<<" "<<i+1<<"\n";
  return 0;
}
