#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	freopen("bendin.txt", "r", stdin);
	freopen("bendout.txt", "w", stdout);
	int xa1,ya1,xa2,ya2,xb1,yb1,xb2,yb2;
	cin>>xa1>>ya1>>xa2>>ya2>>xb1>>yb1>>xb2>>yb2;
	int iLeft = max(xa1, xb1), iRight = min(xa2, xb2);
	int iTop = max(ya1, yb1), iBottom = min(ya2, yb2);
  int si = max(0, iRight - iLeft) * max(0, iBottom - iTop);
  int sa = (xa2 - xa1) * (ya2 - ya1);
	int sb = (xb2 - xb1) * (yb2 - yb1);
	cout << sa+sb-si << endl;
	return 0;
}
