#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAXN 200000

int main() {
    boost;
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        vector<ll> s(n);
        for(int i=0;i<n;++i) {
            cin >> a[i];
            if(i==0) s[i] = a[i];
            else s[i] = s[i-1] + a[i];
        }int f =-1;
        for(int i=0;i<n;++i) {
            if(s[i]>k) {
                f = i;
                break;
            }
        }if(f!=-1) cout << f+1 << endl;
        else cout << -1 << endl;
    }return 0;
}