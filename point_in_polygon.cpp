#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const double EPS = 1e-12;

typedef long long ll;

// referenced a code from: https://github.com/meysamaghighi/Kattis/blob/master/Point%20in%20Polygon/a.cpp

// tart from here:
struct pt {
  double x,y;
  pt(double _x, double _y): x(_x), y(_y) {};
  pt operator + (const pt &p) const { return pt(x+p.x, y+p.y); }
  pt operator - (const pt &p) const { return pt(x-p.x, y-p.y); }
  pt operator * (double c) const { return pt(x*c, y*c); }
  pt operator / (double c) const { return pt(x/c, y/c); }
};

double dot(pt p, pt q) { return p.x*q.x + p.y*q.y; }
double dist(pt p, pt q) { return sqrt(dot(p-q , p-q)); }
double cross(pt p, pt q) { return p.x*q.y - p.y*q.x; }

bool segments_parallel(pt a, pt b, pt c, pt d) {
  return abs(cross(a-b,c-d)) < EPS;
}

bool point_on_segment(pt p, pt a, pt b) {
  if (dist(p,a) < EPS) return true;
  if (dist(p,b) < EPS) return true;
  if (segments_parallel(p,a,p,b) && dot(p-a,p-b) < 0) return true;
  return false;
}

bool point_in_polygon(pt p, const vector<pt> &a){
  bool c = false;
  for (int i=0;i<a.size();i++){
    int j = (i+1) % a.size();
    if ( (p.y < a[i].y != p.y < a[j].y) && (p.x < a[i].x + (a[j].x-a[i].x)*(p.y-a[i].y)/(a[j].y-a[i].y)) ) c = !c;
  }
  return c;
}

bool point_on_polygon(pt p, const vector<pt> &a){
  for (int i=0;i<a.size();i++)
    if (point_on_segment(p,a[i],a[(i+1)%a.size()]))
      return true;
  return false;
}
// end here

int main() {
  ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
  int n,m; cin>>n>>m;
  vector<pt> v;
  for (int i=0; i<n; i++) {
    double x,y; cin>>x>>y;
    v.push_back(pt(x,y));
  }
  while(m--) {
    double x,y; cin>>x>>y;
    pt p=pt(x,y);
    if (point_on_polygon(p,v)) cout<<"BOUNDARY";
    else if (point_in_polygon(p,v)) cout<<"INSIDE";
    else cout<<"OUTSIDE";
    cout<<"\n";
  }
  return 0;
}
