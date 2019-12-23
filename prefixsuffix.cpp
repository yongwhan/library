#include <bits/stdc++.h>
using namespace std;

struct kmp{
	string t,p;
	int* b;
	int* m; 
	kmp(string _t, string _p){
		t = _t;
		p = _p;
		b = new int[p.length()+1];
		m = new int[t.length()+1];
	}
	void init(){
		int i=0,j=-1;
		b[0]=-1;
		while(i<p.length()){
			while(j>=0 && p[j] != p[i]) j=b[j];
			i++; j++;
			b[i]=j;
		}
	}
	void match(){
		int i=0,j=0;
		while(i<t.length()){
			while(j>=0 && p[j] != t[i]) j=b[j];
			i++; j++;
			m[i]=j;
			if(j==p.length()){
				cout << "Match: " << i-j << endl;
				j = b[j];
			}
		}
	}
};

int main(){
	string s; cin >> s;
	int n = s.length(), len = 0;
	kmp k("", s);
	k.init();

// gets all substrings that are both prefix and suffix
	for (int j=k.b[n]; j>=0; j=k.b[j])
		cout << s.substr(0,j) << endl;
	return 0;

// gets all substrings that are prefix, suffix, and occurs in the middle.	
	set<int> val;
	for(int i=2;i<n;i++) val.insert(k.b[i]);
	for(int j=k.b[n];j>=0;j=k.b[j])
		if(val.count(j)){
			len = j; break;
		}
	if(len) cout << s.substr(0,len) << endl;
	else cout << "Just a legend" << endl;
	return 0;
}
