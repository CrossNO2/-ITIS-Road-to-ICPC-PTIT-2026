#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int main() {
    boost;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b;
        for(int i=0;i<n;++i) cin >> a[i];
        b=a;
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
        for(int i=0;i<n;++i) {
            cout << lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1 << " ";
        }
        cout << endl;
    }return 0;
}