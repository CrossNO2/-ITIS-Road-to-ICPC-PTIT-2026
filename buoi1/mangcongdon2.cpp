#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define MAXN 100000

/*tiếp tục với mảng cộng dồn 2 chiều, ta tốt nhất nên vẽ hình ra và hiểu, s[i][j] là tổng của cái
hình chữ nhật góc trái trên*/

void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> s(n+1, vector<int>(m+1,0));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            int v;
            cin >> v;
            s[i][j] = s[i][j-1] + s[i-1][j] - s[i-1][j-1] + v;
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int x,y;
        cin >> x >> y;
        cout << s[x][y];
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}