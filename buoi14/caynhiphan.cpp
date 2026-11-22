#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
#define FOR(i, l, r) for (ll i = l; i <= r; i++)
#define FORD(i, l, r) for (ll i = l; i >= r; i--)
#define fre(NAME) freopen(NAME".inp","r",stdin); freopen(NAME".out","w",stdout)
#define ALL(a) a.begin(), a.end()
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pii pair<ll,ll>
#define ldb long double
#pragma GCC optimize("O3")
#define ull unsigned long long
const ll MAXN = 3005;
const ll INF = 4e18;
const ll MOD = 1e9+7;

//ITIS

struct node {
    int data;
    node *left, *right;
    
    node(int x) {
        data = x;
        left = right = NULL;
    }
};

void insert(node *root, int u, int v, char c) {
    if(root != NULL) {
        if(root -> data == u) {
            if(c == 'L') root -> left = new node(v);
            else root -> right = new node(v);
        }else {
            insert(root -> left,u,v,c);
            insert(root -> right,u,v,c);
        }
    }
}

void preOrder(node *root) {
    if(!root) return;
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

node *insertBST(node *root, int x) {
    if(root == NULL) return new node(x);
    if(x < root -> data) {
        root -> left = insertBST(root -> left,x);
    }
    if(x > root -> data) {
        root -> right = insertBST(root -> right,x);
    }
    return root;
}

int main() {
    boost;
    
    return 0;
}

/*
    Hav a nice day xD
    Author Bạch Ngọc Đức - Cross
*/