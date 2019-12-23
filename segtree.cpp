const int MAX=20;
const int MAX2=(1<<MAX);
int t[MAX2][MAX];
// IDENTITY -- f(IDENTITY, x) = x [0 for sum, inf for min, -inf for max, 0 for gcd]

void init() {
  for (int x = 0; x < N; x++)
    t[x][0] = a[x];
  for (int y = 1; y <= n; y++)
    for (int x = 0; x < N; x+=(1<<y))
      t[x][y] = f(t[x][y-1], t[x+(1<<(y-1))][y-1]);
}

void set(int x, int v) {
  t[x][0] = a[x] = v;
  for (int y = 1; y <= n; y++) {
    int xx = x-(x&((1<<y)-1));
    t[xx][y] = f(t[xx][y-1], t[xx+(1<<(y-1))][y-1]);
  }
}

int get(int i, int j) {
  int res = IDENTITY, h = 0; j++;
  while (i+(1<<h) <= j) {
    while ((i&((1<<(h+1))-1)) == 0 && i+(1<<(h+1)) <= j) h++;
    res = f(res, t[i][h]);
    i += (1<<h);
  }
  while (i < j) {
    while (i+(1<<h) > j) h--;
    res = f(res, t[i][h]);
    i += (1<<h);
  }
  return res;
}
