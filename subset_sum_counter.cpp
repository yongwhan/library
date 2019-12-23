#include<iostream>
#include<vector>
using namespace std;

const int mx=1e5+5;
typedef long long ll;

ll dp[mx];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	dp[0]=1;

	int n; cin>>n;
	vector<ll> v(n);
	ll sum=0;
	for (int i=0; i<n; i++)
		cin>>v[i], sum+=v[i];

	if(sum%2) { cout << 0 << endl; return 0; }
	sum/=2;

	ll cur=0;
	for (int i=0; i<n; i++) {
		cur+=v[i];
		for (int j=min(sum,cur); j>=v[i]; j--)
			dp[j]+=dp[j-v[i]];
	}
	cout << dp[sum]/2 << endl;
	return 0;
}
