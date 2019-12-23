#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mx=(1<<8), offset=7;
ll tree[mx][mx][mx];

void update(int x, int y, int z, int val){
	while (x<mx) {
		int y1=y;
		while (y1<mx) {
			int z1=z;
			while (z1<mx) {
				tree[x][y1][z1]+=val;
				z1+=(z1&-z1);
			}
			y1+=(y1&-y1); 
		}
		x+=(x&-x); 
	}
}

ll read(int x, int y, int z) {
	if(x<0||y<0||z<0) return 0;
	ll sum=0;
	while (x>0) {
		int y1=y;
		while (y1>0) {
			int z1=z;
			while(z1>0) {
				sum+=tree[x][y1][z1];
				z1-=(z1&-z1);
			}
			y1-=(y1&-y1);
		}
		x-=(x&-x);
	}
	return sum;
}

ll read(int x1, int y1, int z1, int x2, int y2, int z2) {
	return read(x2,y2,z2)-read(x1-1,y2,z2)
	                     -read(x2,y1-1,z2)
	                     -read(x2,y2,z1-1)
	                     +read(x1-1,y1-1,z2)
	                     +read(x1-1,y2,z1-1)
	                     +read(x2,y1-1,z1-1)
	                     -read(x1-1,y1-1,z1-1);
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,m,x,y,z,k,x1,y1,z1,x2,y2,z2; cin>>n;
	while(cin>>m) {
		if(m==3) break;
		if(m==1) cin>>x>>y>>z>>k, update(x+offset,y+offset,z+offset,k);
		else if(m==2) cin>>x1>>y1>>z1>>x2>>y2>>z2, cout<<read(x1+offset,y1+offset,z1+offset,x2+offset,y2+offset,z2+offset)<<endl;
	}
	return 0;
}
