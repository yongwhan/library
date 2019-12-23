#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<string>
#include<math.h>
#include<iomanip>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;

vector<int> inter(vector<int> a, vector<int> b) {
	vector<int> ans(min(a.size(), b.size()));
	vector<int>::iterator it=set_intersection(a.begin(), a.end(), b.begin(), b.end(), ans.begin());
	int sz=it-ans.begin();
	ans.resize(sz);
	return ans;
}

vector<int> diff(vector<int> a, vector<int> b) {
	vector<int> ans(a.size());
	vector<int>::iterator it=set_difference(a.begin(), a.end(), b.begin(), b.end(), ans.begin());
	int sz=it-ans.begin();
	ans.resize(sz);
	return ans;
}
