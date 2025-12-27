#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct SplayTree {
  struct Node {
    Node *l, *r, *p;
    int sz, v, flip, dummy;
    Node()
      : Node(0, nullptr) {
      }
    Node(int v)
      : Node(v, nullptr) {
      }
    Node(int v, Node *p)
      : v(v), p(p) {
        l = r = nullptr;
        sz = flip = dummy = 0;
      }
    ~Node() {
      if (l)
        delete l;
      if (r)
        delete r;
    }
  };

  Node *root;
  vector<Node *> ptr;

  SplayTree(int n)
    : root(nullptr), ptr(n + 2, nullptr) {
    }

  ~SplayTree() {
    if (root)
      delete root;
  }

  void init(const vector<int> &a) {
    if (root)
      delete root;
    ptr[0] = root = new Node(-1e9);
    Node *now = root;
    for (int i = 1; i <= (int)a.size(); i++) {
      ptr[a[i - 1]] = now->r = new Node(a[i - 1], now);
      now = now->r;
    }
    ptr[a.size() + 1] = now->r = new Node(1e9, now);
    root->dummy = now->r->dummy = 1;
    for (int i = (int)a.size() + 1; i >= 0; i--) {
      update(ptr[i]);
    }
  }

  void push(Node *x) {
    if (!x || !x->flip)
      return;
    swap(x->l, x->r);
    if (x->l)
      x->l->flip = !x->l->flip;
    if (x->r)
      x->r->flip = !x->r->flip;
    x->flip = 0;
  }

  void update(Node *x) {
    if (!x)
      return;
    x->sz = 1;
    if (x->l)
      x->sz += x->l->sz;
    if (x->r)
      x->sz += x->r->sz;
  }

  void rotate(Node *x) {
    Node *p = x->p;
    push(p);
    push(x);
    Node *y;
    if (x == p->l) {
      p->l = y = x->r;
      x->r = p;
    } else {
      p->r = y = x->l;
      x->l = p;
    }
    x->p = p->p;
    p->p = x;
    if (y)
      y->p = p;
    if (x->p) {
      if (p == x->p->l)
        x->p->l = x;
      else
        x->p->r = x;
    } else {
      root = x;
    }
    update(p);
    update(x);
  }

  void splay(Node *x, Node *g = nullptr) {
    while (x->p != g) {
      Node *p = x->p;
      if (p->p == g) {
        rotate(x);
        break;
      }
      Node *pp = p->p;
      if ((p->l == x) == (pp->l == p)) {
        rotate(p);
      } else {
        rotate(x);
      }
      rotate(x);
    }
    if (!g)
      root = x;
  }

  void kth(int k) {
    Node *now = root;
    push(now);
    while (true) {
      while (now->l && now->l->sz > k) {
        now = now->l;
        push(now);
      }
      if (now->l)
        k -= now->l->sz;
      if (!k)
        break;
      k--;
      now = now->r;
      push(now);
    }
    splay(now);
  }

  Node *gather(int s, int e) {
    kth(e + 1);
    Node *tmp = root;
    kth(s - 1);
    splay(tmp, root);
    return root->r->l;
  }

  void flip(int s, int e) {
    Node *x = gather(s, e);
    x->flip = !x->flip;
  }

  int getidx(int k) {
    splay(ptr[k]);
    return root->l->sz;
  }
};
