#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAXN 200000
#define MOD 1000000007

ll factorial(int n) {
    if(n<=1) return 1;
    return(n*factorial(n-1))%MOD;
}

int main() {
    boost;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << factorial(n) << endl;
    }return 0;
}