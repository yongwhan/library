#include<iomanip>
#include<iostream>
#include<vector>
#include<math.h>
#include<stack>
using namespace std;

void print(stack<int> stk) {
	while(!stk.empty()) {
		cout << stk.top() << " "; stk.pop();
	}
	cout << endl;
}

int main() {
	int n; cin>>n;
	stack<int> stk;
	stk.push(n);
	while(!stk.empty()) {
		print(stk);

		int cur=0, mod=0;
		while(!stk.empty()) {
			int val=stk.top(); stk.pop(); cur+=val;
			if(val!=1) { mod=val; break; }
		}

		if(!mod) break;
		mod--;

		while(1) {
			if(cur<mod) break;
			stk.push(mod); cur-=mod;
		}
		if(cur) stk.push(cur);
	}
	return 0;
}
