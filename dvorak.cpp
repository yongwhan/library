#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string qwerty=" `1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
	string dvorak=" `123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";
	map<char,char> mp;
	int n=qwerty.size();
	for (int i=0; i<n; i++)
		mp[qwerty[i]]=dvorak[i];
	string s;
	while(getline(cin,s)) {
		string t;
		for (auto ch : s) t+=mp[ch];
		cout << t << endl;
	}
	return 0;
}
