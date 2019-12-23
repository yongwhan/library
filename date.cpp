#include<bits/stdc++.h>
using namespace std;

string month[]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

map<string,int> month_to_number;

struct dat {
	int y,m,d;
	dat(int y_, int m_, int d_) {
		y=y_, m=m_, d=d_;
	}
};

int days[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leap(int x) {
	return (x%400==0)||((x%100)&&(x%4==0));
}

dat next(dat x) {
	x.d++;
	int day=days[x.m-1];
	if(leap(x.y) && x.m==2) day++;
	if(x.d>day)
		x.d-=day, x.m++;
	if(x.m>12)
		x.m-=12, x.y++;
	return x;
}

dat prev(dat x) {
	x.d--;
	if(x.d==0) {
		int month=x.m-1;
		if(month==0) {
			month=12;
			int year=x.y-1;
			int day=days[month-1];
			if(leap(year)&&month==2) day++;
			return dat(year,month,day);
		} else {
			int day=days[month-1];
			if(leap(x.y)&&month==2) day++;
			return dat(x.y,month,day);
		}
	} else return x;
}

int s2n(string &s) {
	stringstream ss(s); int ret; ss>>ret; return ret;
}

string n2s(int x, int l) {
	stringstream ss; ss<<x;
	string ret=ss.str();
	while(ret.size()<l) ret='0'+ret;
	return ret;
}

bool equal(dat &a, dat &b) {
	return a.y==b.y&&a.m==b.m&&a.d==b.d; 
}

dat s2d(string &s) {
	string y=s.substr(0,4), m=s.substr(5,2), d=s.substr(8,2);
	return dat(s2n(y),s2n(m),s2n(d));
}

string d2s(dat &d) {
	return n2s(d.y,4)+":"+n2s(d.m,2)+":"+n2s(d.d,2);
}

bool later(dat &s, dat &t) {
	if(s.y==t.y) {
		if(s.m==t.m) return s.d>t.d;
		else return s.m>t.m;
	} else return s.y>t.y;
}

int main() {
	for (int i=0; i<12; i++) month_to_number[month[i]]=i+1;

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	string s="2012:01:01",t="2014:01:01";
	dat begin=s2d(s), end=s2d(t);
	map<string,int> mp;
	dat cur=begin;
	int idx=0;
	while(1) {
		string key=d2s(cur);
		mp[key]=idx++;
		if(equal(cur,end)) break;
		cur=next(cur);
	}

	map<int,int> people;
	int n,ret=0; fin>>n;
	for (int i=0; i<n; i++) {
		int m,d,p,t; fin>>m>>d>>p>>t;
		cur=dat(2013,m,d);
		string key=d2s(cur);
		for (int j=1; j<=t; j++)
			people[mp[key]-j]+=p, ret=max(ret,people[mp[key]-j]);
	}
	fout << ret << endl;
	return 0;
}
