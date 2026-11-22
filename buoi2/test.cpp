#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAXN 200000

int main() {
    boost;
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin >> a[i];
    int l=0,r=n-1;
    int f=0;
    while(l<=r) {
        if(a[l]+a[r]==k) cout << a[l] << " " << a[r] << endl;
        if(a[l]+a[r] > k) r--;
        if(a[l] + a[r] < k) l++;
    }
    return 0;
}