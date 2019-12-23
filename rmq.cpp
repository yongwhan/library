#define MAX 50010
#define LOGMAX 18

int v[MAX], mm[MAX][LOGMAX];

void init(int n) {
	int i,j,b;
	for (i=0; i<n; i++) mm[i][0]=v[i];
	for (i=1; i<LOGMAX; i++)
		for (j=0; (j+(1<<i)-1)<n; j+=(1<<i))
			mm[j][i]=max(mm[j][i-1], mm[j+(1<<(i-1))][i-1]);
}

int getmax(int a, int b) {
	if(a>b) return -1;
	for (int i=LOGMAX-1; i>=0; i--)
		if((a%(1<<i))==0 && (a+(1<<i)-1)<=b)
			return max(mm[a][i], getmax(a+(1<<i), b));
}
