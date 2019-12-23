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

// change this to make arbitrary one

class cmp {
	bool rev;
	public:
		cmp(const bool& revp=false) { rev=rev=revp; }
		bool operator() (const int & a, const int & b) const {
			if(rev) return a>b;
			else return a<b;
		}
};

typedef priority_queue<int, vector<int>, cmp> pqueue;

int main() {
	return 0;
}
