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
    ll n;
    cin >> n;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    for(int i=0;i<n;++i) {
        ll x;
        cin >> x;
        pq.push(x);
    }ll sumfake = 0;
    while(pq.size() > 1) {
        ll min1 = pq.top();
        pq.pop();
        ll min2 = pq.top();
        pq.pop();
        ll sum = (min1 + min2)%mod;
        sumfake = (sum + sumfake)%mod;
        pq.push(sum);
    }cout << sumfake << endl;
    return 0;
}