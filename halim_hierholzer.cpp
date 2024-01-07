#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order
// order_of_key

typedef long long ll;

typedef vector<int> vi;

int N;
vector<vi> AL;                                   // Directed graph

vi hierholzer(int s) {
  vi ans, idx(N, 0), st;
  st.push_back(s);
  while (!st.empty()) {
    int u = st.back();
    if (idx[u] < (int)AL[u].size()) {            // still has neighbor
      st.push_back(AL[u][idx[u]]);
      ++idx[u];
    }
    else {
      ans.push_back(u);
      st.pop_back();
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
