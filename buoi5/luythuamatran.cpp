#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define maxn 200000
#define mod 1000000007
#define ull unsigned long long
#pragma GCC optimize("O3")

int n,k;

struct matrix {
    ll v[11][11];
    
    matrix operator * (const matrix& b) {
        matrix res;
        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) {
                res.v[i][j] = 0;
                for(int k=0;k<n;++k) {
                    res.v[i][j] = (res.v[i][j] + v[i][k] * b.v[k][j])%mod;
                }
            }
        }return res;
    }
};

matrix pow(matrix a, int k) {
    if(k==1) return a;
    matrix ans = pow(a,k/2);
    if(k%2==0) return ans*ans;
    return a*(ans*ans);
}

int main() {
    boost
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        matrix a;
        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) cin >> a.v[i][j];
        }
        matrix res = pow(a,k);
        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) {
                cout << res.v[i][j] << " ";
            }cout << endl;
        }
    }
    return 0;
}