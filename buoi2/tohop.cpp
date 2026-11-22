#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAXN 200000
#define MOD 100000007
#define ull unsigned long long

ll combination(int n,int k) {
    if(k==0) return 1;
    return (ll) 1*n*combination(n-1,k-1)/k;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        cout << combination(n,k) << endl;
    }return 0;
}