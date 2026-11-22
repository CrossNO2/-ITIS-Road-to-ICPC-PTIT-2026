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
const ll MAXN = 1e6;
const ll INF = 4e18;
const ll MOD = 1e9+7;

//ITIS

vector<ll> a(MAXN+5);
vector<ll> tree(4*MAXN+5);

void build(int idx,int l, int r) {
    if(l == r) {
        tree[idx] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(idx*2,l,mid);
    build(idx*2+1,mid+1,r);
    tree[idx] = tree[idx*2] + tree[idx*2+1];
}

void update(int idx,int l, int r, int pos, int value) {
    if(pos < l || r < pos) return;
    if(l == r) {
        tree[idx] += value;
        return;
    }
    int mid = (l+r)/2;
    update(idx*2,l,mid,pos,value);
    update(idx*2+1,mid+1,r,pos,value);
    tree[idx] = tree[idx*2] + tree[idx*2+1];
}

ll query(int idx,int l, int r,int x,int y) {
    if(y < l || r < x) return 0;
    if(x <= l && r <= y) return tree[idx];
    int mid = (l+r)/2;
    return query(idx*2,l,mid,x,y) + query(idx*2+1,mid+1,r,x,y);
}

int main() {
    boost;
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;++i) cin >> a[i];
    build(1,1,n);
    while(q--) {
        ll type,x,y;
        cin >> type >> x >> y;
        if(type == 1) update(1,1,n,x,y);
        else cout << query(1,1,n,x,y) << endl;
    }
    return 0;
}

/*
    Hav a nice day xD
    Author Bạch Ngọc Đức - Cross
*/