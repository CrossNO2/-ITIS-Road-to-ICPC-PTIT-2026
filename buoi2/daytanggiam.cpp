#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAXN 200000
#define MOD 100000007
#define ull unsigned long long

void recursion(int i,int n) {
    if(i>n) return;
    cout << i << " ";
    if(i<n) {
        recursion(i+1,n);
        cout << i << " ";
    }
}

int main() {
    boost;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        recursion(1,n);
        cout << endl;
    }return 0;
}