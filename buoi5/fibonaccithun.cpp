#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define maxn 200000
#define mod 1000000007
#define ull unsigned long long
#pragma GCC optimize("O3")

struct matrix {
    ll v[2][2];
    matrix operator * (const matrix& res) const {
        matrix c = {{{0,0},{0,0}}};
        for(int i=0;i<2;++i) {
            for(int j=0;j<2;++j) { 
                for(int k=0;k<2;++k) {
                    c.v[i][j] = (c.v[i][j] + v[i][k] * res.v[k][j])%mod;
                }
            }
        }return c;
    }
};

matrix pow(matrix a, ll b) {
    matrix r = {{{1,0},{0,1}}};
    while(b>0) {
        if(b&1) r = r*a;
        a = a*a;
        b >>= 1;
    }return r;
}

int main() {
    boost
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        if(n==0) cout << 0 << endl;
        else {
            matrix a = {{{1,1}, {1,0}}};
            matrix r = pow(a,n);
            cout << r.v[0][1] << endl;
        }
    }
    return 0;
}