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
    int n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i=0;i<n;++i) cin >> a[i];
    deque<ll> dq;
    vector<ll> ans(n);
    for(int i=0;i<k;++i) {
        while(!dq.empty() && a[i] >= a[dq.back()]) {
            dq.pop_back();
        }dq.push_back(i);
    }cout << a[dq.front()] << " ";
    for(int i=k;i<=n-1;++i) {
        if(dq.front() <= i-k) dq.pop_front();
        while(!dq.empty() && a[i] >= a[dq.back()]) dq.pop_back();
        dq.push_back(i);
        cout << a[dq.front()] << " ";
    }
    return 0;
}