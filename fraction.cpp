#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	if(!b) return a;
	else return gcd(b, a%b);
}

struct frac {
	ll a,b;
	frac(ll a_, ll b_=1) {
		ll g=gcd(a_,b_);
		a=a_/g; b=b_/g;
	}

	frac operator*(const frac &y) {
		ll c=a*y.a, d=b*y.b, g=gcd(abs(c),abs(d));
		return frac(c/g, d/g);
	}

	frac operator+(const frac &y) {
		ll c=a*y.b+b*y.a, d=b*y.b, g=gcd(abs(c),abs(d));
		return frac(c/g, d/g);
	}

	frac operator-(const frac &y) {
		ll c=a*y.b-b*y.a, d=b*y.b, g=gcd(abs(c),abs(d));
		return frac(c/g, d/g);
	}

	frac operator/(const frac &y) {
		ll c=a*y.b, d=b*y.a, g=gcd(abs(c),abs(d));
		return frac(c/g, d/g);
	}

	bool operator<(const frac &y) {
		return a*y.b<b*y.a;
	}

	bool operator==(const frac &y) {
		return a*y.b==b*y.a;
	}
};

struct cmp : public std::binary_function<frac, frac, bool> {
	bool operator()(const frac &x, const frac &y) const {
		return x.a*y.b<x.b*y.a;
	}
};

frac flip(frac a) {
	return frac(a.b, a.a);
}

std::ostream &operator<<( std::ostream &stm , const frac &rhs ) {
	if( rhs.b == 1 ) return( stm << rhs.a);
	return( stm << rhs.a << '/' << rhs.b);
}

int main() {
	return 0;
}
