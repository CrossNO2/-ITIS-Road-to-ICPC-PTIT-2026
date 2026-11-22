#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAXN 200000
#define MOD 100000007

ll f(int n) {
    if(n==0) return 0;
    else if(n==1) return 1;
    else return (f(n-1)+f(n-2))%MOD;
} 

int main() {
    boost;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << f(n) << endl;
    }return 0;
}