#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;

vector<int> manacher_odd(string &s) {
  int n = s.size();
  s = "$" + s + "^";
  vector<int> p(n + 2);
  int l = 1, r = 1;
  for(int i = 1; i <= n; i++) {
    p[i] = max(0, min(r - i, p[l + (r - i)]));
    while(s[i - p[i]] == s[i + p[i]]) {
      p[i]++;
    }
    if(i + p[i] > r) {
      l = i - p[i], r = i + p[i];
    }
  }
  return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string &s) {
  string t;
  for(auto c: s) {
    t += string("#") + c;
  }
  t+="#";
  auto res = manacher_odd(t);
  return vector<int>(begin(res) + 1, end(res) - 1);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
  string s; cin>>s;
  vector<int> ret=manacher(s);
  vector<int> d_even, d_odd;
  for (int i=0; i<ret.size(); i++)
    if(i%2) d_even.push_back((ret[i]-1)/2);
    else d_odd.push_back(ret[i]/2);
  int ans=0;
  for (auto &e : d_odd)
    ans=max(ans,e*2-1);
  for (auto &e : d_even)
    ans=max(ans,e*2);
  cout<<ans<<"\n";
  return 0;
}
