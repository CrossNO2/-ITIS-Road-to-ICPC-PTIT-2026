#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define maxn 200000
#define mod 1000000007
#define ull unsigned long long
#pragma GCC optimize("O3")

int main() {
    boost
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;++i) cin >> a[i];
    ll s;
    cin >> s;
    ll l = 0, r = 0,res = -1;
    ll sum = 0;
    for(r=0;r<n;++r) {
        sum+=a[r];
        while(sum > s && l<=r) {
            sum -= a[l];
            l++;
        }if(sum==s) {
            if(res == -1 || (r-l+1) > res) {
                res = r-l+1;
            }
        }
    }cout << res;
    return 0;
}