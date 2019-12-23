#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

// returns start index, end index, and maximum value in vector.

vector<int> kadane(vector<int> & v) {
	int sz=v.size(), ans=-INF, ii=-1, jj=-1, cur=0, i=0, j;
	for (j=0; j<sz; j++) {
		cur+=v[j];
		if(cur>ans) { ans=cur; ii=i; jj=j; }
		if(cur<=0) { cur=0; i=j+1; }
	}
	vector<int> w(3);
	w[0]=ii+1; w[1]=jj+1; w[2]=ans;
	return w;
}

int main() {
	
	return 0;
}
