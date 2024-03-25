#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order
// order_of_key

typedef long long ll;

vector<int> mobius_1_to_n(int n) {
  vector<int> mobius(n+1,0);
  mobius[1]=1;
  for (int i=1; i<=n; i++)
    if(mobius[i])
      for (int j=i*2; j<=n; j+=i)
        mobius[j]-=mobius[i];
  return mobius;
}

int main() {
  return 0;
}
