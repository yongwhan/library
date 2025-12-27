#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;

struct Blossom {
    int n;
    vector<vector<int>> adj;
    vector<int> match, parent, base;
    vector<bool> in_queue, in_path, in_blossom;
    queue<int> q;

    Blossom(int n_)
        : n(n_), adj(n), match(n, -1), parent(n), base(n),
          in_queue(n), in_path(n), in_blossom(n) {
        iota(base.begin(), base.end(), 0);
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int lca(int u, int v) {
        fill(in_path.begin(), in_path.end(), false);
        while (true) {
            u = base[u];
            in_path[u] = true;
            if (match[u] == -1)
                break;
            u = parent[match[u]];
        }
        while (true) {
            v = base[v];
            if (in_path[v])
                return v;
            v = parent[match[v]];
        }
    }

    void mark_path(int v, int b, int children) {
        while (base[v] != b) {
            in_blossom[base[v]] = in_blossom[base[match[v]]] = true;
            parent[v] = children;
            children = match[v];
            v = parent[match[v]];
        }
    }

    void contract(int u, int v) {
        int b = lca(u, v);
        fill(in_blossom.begin(), in_blossom.end(), false);
        mark_path(u, b, v);
        mark_path(v, b, u);
        for (int i = 0; i < n; i++) {
            if (in_blossom[base[i]]) {
                base[i] = b;
                if (!in_queue[i]) {
                    q.push(i);
                    in_queue[i] = true;
                }
            }
        }
    }

    bool find_path(int root) {
        fill(parent.begin(), parent.end(), -1);
        fill(in_queue.begin(), in_queue.end(), false);
        iota(base.begin(), base.end(), 0);
        while (!q.empty())
            q.pop();
        q.push(root);
        in_queue[root] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (base[u] == base[v] || match[u] == v)
                    continue;
                if (v == root || (match[v] != -1 && parent[match[v]] != -1)) {
                    contract(u, v);
                } else if (parent[v] == -1) {
                    parent[v] = u;
                    if (match[v] == -1) {
                        int cur = v;
                        while (cur != -1) {
                            int next = match[parent[cur]];
                            match[cur] = parent[cur];
                            match[parent[cur]] = cur;
                            cur = next;
                        }
                        return true;
                    }
                    v = match[v];
                    in_queue[v] = true;
                    q.push(v);
                }
            }
        }
        return false;
    }

    int max_matching() {
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (match[i] == -1) {
                if (find_path(i)) {
                    result++;
                }
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;

    Blossom blossom(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        blossom.add_edge(u, v);
    }

    cout << blossom.max_matching() << "\n";
    return 0;
}
