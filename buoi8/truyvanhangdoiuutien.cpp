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
    int n;
    cin >> n;
    priority_queue<ll,vector<ll>,greater<ll>> pq1,pq2;
    while(n--) {
        int t,x;
        cin >> t;
        if(t==1) {
            cin >> x;
            pq1.push(x);
        }else if(t==2) {
            cin >> x;
            pq2.push(x);
        }else {
            while(!pq2.empty() && pq1.top() == pq2.top()) {
                pq1.pop();
                pq2.pop();
            }cout << pq1.top() << endl;
        }
    }
    return 0;
}