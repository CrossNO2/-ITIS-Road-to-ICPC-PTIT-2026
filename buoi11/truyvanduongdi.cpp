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

int n,q;
int parent[100000];
int Size[100000];

void make_set() {
    for(int i=1;i<=n;++i) {
        parent[i] = i;
        Size[i] = 1;
    }
}

int find(int v) {
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

void Union(int a, int b) { 
    a = find(a);
    b = find(b);

    if(a != b) {
        if(Size[a] < Size[b]) swap(a,b);
        parent[b] = a;
        Size[a] += Size[b];
    }
}

int main() {
    boost;
    cin >> n >> q;
    make_set();
    while(q--) {
        int a,x,y;
        cin >> a >> x >> y;
        if(a == 1) {
            Union(x,y);
        }
        else {
            if(find(x) != find(y)) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }
    return 0;
}

/*
    Hav a nice day xD
    Author Bạch Ngọc Đức - Cross
*/