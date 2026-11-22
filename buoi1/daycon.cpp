#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int main() {
    boost;
    int n,m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> s(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    s[0] = a[0];
    for(int i=1;i<n;i++) s[i] = s[i-1] +a[i];
    for(int i=0;i<m;i++) {
        ll q;
        cin >> q;
        ll l=0,r=n-1,res=0;
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(s[mid] <= q) {
                res = mid+1;
                l = mid+1;
            }else r=mid-1;
        }cout << res << (i==m-1 ? "":" ");
    }return 0;
}