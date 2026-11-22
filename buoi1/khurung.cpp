#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int main() {
    boost;
    int n,q;
    cin >> n >> q;
    vector<vector<int>> p(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            char c;
            cin >> c;
            int v = (c=='*'?1:0);
            p[i][j] = v + p[i-1][j] + p[i][j-1] - p[i-1][j-1];
        }
    }while(q--) {
        int y1,x1,y2,x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << p[y2][x2] - p[y1-1][x2] - p[y2][x1-1] + p[y1-1][x1-1] << endl;
    }return 0;
}