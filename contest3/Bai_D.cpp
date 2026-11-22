#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
#define FOR(i, l, r) for (ll i = l; i <= r; i++)
#define FORD(i, l, r) for (ll i = l; i >= r; i--)
#define fre(NAME) freopen(NAME".inp","r",stdin); freopen(NAME".out","w",stdout)
#define ALL(a) a.begin(), a.end()
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pii pair<ll,ll>
#define ldb long double
#pragma GCC optimize("O3")
#define ull unsigned long long
const ll MAXN = 3005;
const ll INF = 4e18;
const ll MOD = 1e9+7;

//ITIS

int t;

int main() {
    boost;
    
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int a[n + 5];
        int s[n + 5];

        for(int i = 1; i <= n; i++) cin >> a[i];

        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

        long long ds = 0;

        for(int i = 1; i <= n; i++){
            ds += a[i] * (s[n] - s[i]);
        }

        cout << ds << endl;
    }

    return 0;
}

/*
    Hav a nice day xD
    Author Bạch Ngọc Đức - Cross
*/