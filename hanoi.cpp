#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef long long ll;

int cmp(string s, string t) {
	if(s==t) return 0;
	int n=s.size(), m=t.size();
	if(n<m) return -1;
	if(n>m) return 1;
	for (int i=0; i<n; i++) {
		char a=s[i], b=t[i];
		if(a>b) return 1;
		if(a<b) return -1;
	}
}

vector<int> tov(string s) {
	int sz=s.size();
	vector<int> ans(sz,0);
	for (int i=0; i<sz; i++)
		ans[i]=s[sz-1-i]-'0';
	return ans;
}

string tos(vector<int> & v) {
	int sz=v.size();
	string ans;
	for (int i=0; i<sz; i++)
		ans=(char)(v[i]+'0')+ans;
        while(ans[0]=='0') ans=ans.substr(1);
        if(!ans.size()) return "0";
	return ans;
}

string prod(string s, string t) {
	int n=s.size(), m=t.size(), l=n+m+1;
	vector<int> v=tov(s), w=tov(t), ans(l,0);
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			ans[i+j]+=v[i]*w[j];
	for (int i=0; i<l-1; i++) {
		ans[i+1]+=ans[i]/10;
		ans[i]%=10;
	}
	return tos(ans);
}

string sum(string s, string t) {
        int n=s.size(), m=t.size(), l=max(n,m)+1;
        vector<int> v=tov(s), w=tov(t), ans(l,0);
        for (int i=0; i<n; i++)
                ans[i]+=v[i];
        for (int i=0; i<m; i++)
                ans[i]+=w[i];
        for (int i=0; i<l-1; i++) {
                ans[i+1]+=ans[i]/10;
                ans[i]%=10;
        }
        return tos(ans);
}

string diff(string s, string t) {
	char sgn='+';
	if(cmp(s,t)<0) { sgn='-'; swap(s,t); }
	int n=s.size(), m=t.size(), l=max(n,m);
	vector<int> v=tov(s), w=tov(t), ans(l,0);
	for (int i=0; i<n; i++)
		ans[i]+=v[i];
	for (int i=0; i<m; i++)
		ans[i]-=w[i];
	for (int i=0; i<l-1; i++) {
		if(ans[i]<0) {
			ans[i+1]--;
			ans[i]+=10;
		}
	}
	string cur=tos(ans);
	if(sgn=='-') cur=sgn+cur;
	return cur;
}

void print(vector<stack<int> > stk) {
	for (int i=0; i<3; i++) {
		cout << "#" << i+1 << ": ";
		while(!stk[i].empty())
			cout << stk[i].top() << " ", stk[i].pop();
		cout << endl;
	}
}

int main() {
	int n; cin>>n;
	string s="1";
	for (int i=0; i<n; i++)
		s=prod(s,"2");
	cout << diff(s,"1") << endl;

	if(n>20) return 0;

	vector<stack<int> > stk(3);

	for (int i=n; i>=1; i--)
		stk[0].push(i);

	int step=0;
	while(1) {
		if(stk[1].size()==n||stk[2].size()==n) break;
		step++;
		if(step%2) {
			for (int i=0; i<3; i++)
				if(!stk[i].empty() && stk[i].top()==1) {
					int j=(i+1)%3;
					if(n%2) j=(i+2)%3;
					stk[i].pop();
					stk[j].push(1);
					printf("%d %d\n", i+1, j+1);
					break;
				}
		} else {
			bool up=false;
			int j=-1;
			for (int i=0; i<3; i++) {
				if(stk[i].empty()) { j=i; break; }
			}

			if(j!=-1) {
				for (int i=0; i<3; i++) {
					if(!stk[i].empty()) {
						int a=stk[i].top();
						if(a!=1) {
							stk[i].pop();
							stk[j].push(a);
							printf("%d %d\n", i+1, j+1);
							up=true;
							break;
						}
					}
					if(up) break;
				}
			}

			if(!up) {
				for (int i=0; i<3; i++) {
					for (int j=0; j<3; j++) {
						int a=stk[i].top(), b=stk[j].top();
						if(i!=j&&a!=1&&b!=1&&a<b) {
							stk[i].pop();
							stk[j].push(a);
							printf("%d %d\n", i+1, j+1);
							up=true;
							break;
						}
						if(up) break;
					}
					if(up) break;
				}
			}
		}
	}

	return 0;
}
