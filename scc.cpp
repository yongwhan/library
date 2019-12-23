
using namespace std;
#include <bits/stdc++.h>

#define mx 200000
#define mod 1000000007ll

typedef long long ll;
typedef vector<int> vi;
#define mem(x,val) memset((x),(val),sizeof(x));
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define sz(x) ((int)x.size())
#define pb push_back

vi edge[mx];
int _low[mx], _dtime[mx], _dfstime, _stack[mx], _size, _comp[mx], _comps;
bool _instack[mx];

void tarjan(int u){
    _low[u]=_dtime[u]=++_dfstime;
    _stack[_size++]=u;
    _instack[u]=true;

    rep(i,sz(edge[u])){
        int v=edge[u][i];
        if(_dtime[v]==-1) tarjan(v), _low[u]=min(_low[u],_low[v]);
        else if(_instack[v]) _low[u]=min(_low[u],_dtime[v]);
    }

    if(_dtime[u]==_low[u]){
        _comps++;
        int v=-1;
        do{
            v=_stack[--_size];
            _instack[v]=false;
            _comp[v]=_comps;
        }while(u!=v);
    }
}

void scc(int n){
    _comps=_dfstime=_size=0;
    mem(_dtime,-1);
    mem(_low,0);
    mem(_stack,0);
    mem(_comp,0);
    mem(_instack,0);
    rep(i,n) if(_dtime[i]==-1)tarjan(i);
}

int main(){
    int n,m;
    scanf("%d %d",&n, &m);
    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);
        assert(1<=u && u<=n);
        assert(1<=v && v<=n);
        u--,v--;
        edge[u].pb(v);
    }
    scc(n);

		for (int i=0; i<n; i++)
			cout << i << " " << _comp[i] << endl;

// _comp: SCC component label

	return 0;
}
