#include<bits/stdc++.h>
using namespace std;

struct node {
	char val;
	node *left, *right;
	node(char s) : val(s), left(NULL), right(NULL) {}
};

node *find(node *root, char s) {
	queue<node*> q; q.push(root);
	while(!q.empty()) {
		node *cur=q.front(); q.pop();
		if(cur->val==s) return cur;
		if(cur->left!=NULL) q.push(cur->left);
		if(cur->right!=NULL) q.push(cur->right);
	}
	return NULL;
}

void pre(node *root) {
	if(root==NULL) return;
	cout << root->val;
	pre(root->left);
	pre(root->right);
}

void in(node *root) {
	if(root==NULL) return;
	in(root->left);
	cout << root->val;
	in(root->right);
}

void post(node *root) {
	if(root==NULL) return;
	post(root->left);
	post(root->right);
	cout << root->val;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin>>n;
	node *root = new node('A');
	vector<string> v;
	for (int i=0; i<n; i++) {
		string a,b,c; cin>>a>>b>>c;
		v.push_back(a+b+c);
	}

	for (int i=0; i<n; i++) {
		int sz=v.size();
		for (int j=0; j<sz; j++) {
			string t=v[j];
			char a=t[0], b=t[1], c=t[2];
			node *cur=find(root,a);
			if(cur!=NULL) {
				if(b!='.') cur->left=new node(b);
				if(c!='.') cur->right=new node(c);
				v.erase(v.begin()+j); break;
			}
		}
	}

	pre(root);
	cout << endl;
	in(root);
	cout << endl;
	post(root);
	cout << endl;
	return 0;
}
