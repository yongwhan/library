#include<bits/stdc++.h>
using namespace std;

// returns start index, end index, and maximum value in vector.
vector<int> kadane(const vector<int>& v) {
  int sz=v.size(), ans=INT_MIN, ii=-1, jj=-1, cur=0, i=0, j;
  for (j=0; j<sz; j++) {
    cur+=v[j];
    if(cur>ans) ans=cur, ii=i, jj=j;
    if(cur<=0) cur=0, i=j+1;
  }
  return {ii+1,jj+1,ans};
}

int main() {	
  return 0;
}
