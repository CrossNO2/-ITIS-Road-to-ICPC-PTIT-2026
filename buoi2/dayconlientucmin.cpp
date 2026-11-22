#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAXN 200000
#define MOD 100000007
#define ull unsigned long long

int main() {
    boost;
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        vector<ll> a(n+1);
        vector<ll> s(n+2,0);
        for(int i=1;i<=n;++i) {
            cin >> a[i];
            s[i] = s[i-1] + a[i];
        }
        int l=1,r=1;
        int lf = n+1;
        while(r<=n) {
            if(s[r]-s[l-1] > k) {
                lf = min(lf,r-l+1);
                l++;
            }else r++;
        }if(lf>n) cout << -1 << endl;
        else cout << lf << endl;
    }return 0;
}