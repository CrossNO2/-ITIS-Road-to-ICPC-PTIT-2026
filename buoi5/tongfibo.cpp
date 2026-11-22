#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define maxn 200000
#define mod 1000000007
#define ull unsigned long long
#pragma GCC optimize("O3")

const ll m = 1e15+7;

ll binmul(ll a,ll b, ll m) {
    ll res = 0;
    a %= m;
    while(b>0) {
        if(b%2==1) res = (res+a)%m;
        a = (a+a)%m;
        b /= 2;
    }return res;
}

struct matrix {
    ll v[2][2];

    matrix operator * (const matrix& b) {
        matrix res;
        for(int i=0;i<2;++i) {
            for(int j=0;j<2;++j) {
                int temp = 0;
                res.v[i][j] = 0;
                for(int k=0;k<2;++k) {
                    res.v[i][j] = (res.v[i][j] + binmul(v[i][k], b.v[k][j],m))%m;
                }
            }
        }return res;
    }
};

matrix pow(matrix a, ll k) {
    if(k==1) return a;
    matrix ans = pow(a, k/2);
    if(k%2==0) return ans*ans;
    return a*ans*ans; 
}

int main() {
    boost
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        matrix a;
        a.v[0][0] = 1;
        a.v[0][1] = 1;
        a.v[1][0] = 1;
        a.v[1][1] = 0;
        matrix res = pow(a,n+1);
        ll res2 = (res.v[0][0] -1 + m)%m;
        cout << res2 << endl;
    }
    return 0;
}