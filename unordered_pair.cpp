#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
template <> struct hash<std::pair<int, int>> {
	inline size_t operator()(const std::pair<int, int> &v) const {
		std::hash<int> int_hasher;
		return int_hasher(v.first) ^ int_hasher(v.second);
	}
};

int main() {
	unordered_set<ii> ust;
	return 0;
}
