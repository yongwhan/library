#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f(ll k) {
	return 0;
}

int main() {
	ll ans=(ll)1e18,lo=1,hi=1e9;
	for (int it=0; it<100; it++) {
		ll mid1 = lo+(hi-lo)/3;
		ll mid2 = hi-(hi-lo)/3;
		if (f(mid1)<ans) ans=f(mid1);
		if (f(mid2)<ans) ans=f(mid2);
		if (f(mid1)>=f(mid2)) lo=mid1;
		else hi=mid2;
	}
	cout << ans << endl;
	return 0;
}
