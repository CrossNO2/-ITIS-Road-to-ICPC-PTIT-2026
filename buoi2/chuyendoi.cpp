#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAXN 200000
#define MOD 100000007
#define ull unsigned long long

void recursion(int n) {
    if(n>1) recursion(n/2);
    cout << n%2;
}

int main() {
    boost;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        recursion(n);
        cout << endl;
    }return 0;
}