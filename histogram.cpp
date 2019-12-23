#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
using namespace std;

double h[1048576], max_area;
int n;

int calc_max_area(int r, int left, double low) {
  int next = r+1;
  if (next < n && h[r] < h[next])
    next = calc_max_area(next, next, h[r]+1);
  max_area = max(max_area, (next-left)*h[r]);
  return (next == n || h[next] < low) ? next : calc_max_area(next, left, low);
}

int main()
{
	cin>>n;
	for (int i=0 ; i<n ; i++) cin >> h[i];
	max_area = 0;
	calc_max_area(0, 0, 0);
	cout << max_area << endl;
  return 0;
}
