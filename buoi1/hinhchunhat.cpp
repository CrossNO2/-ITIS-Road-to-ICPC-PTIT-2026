#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

ll a[1010][1010];
ll d[1010][1010];

int main() {
    boost;
    int n, m, q;
    cin >> n >> m >> q;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin >> a[i][j];
        }
    }while (q--) {
        int x1, y1, x2, y2;
        ll v;
        cin >> x1 >> y1 >> x2 >> y2 >> v;

        d[x1][y1] += v;
        d[x1][y2 + 1] -= v;
        d[x2 + 1][y1] -= v;
        d[x2 + 1][y2 + 1] += v;
    }for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            d[i][j] = d[i][j] + d[i-1][j] + d[i][j-1] - d[i-1][j-1];
            cout << a[i][j] + d[i][j] << (j == m ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}