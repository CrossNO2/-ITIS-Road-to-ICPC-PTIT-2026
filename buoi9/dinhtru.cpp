#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define maxn 200000
#define mod 1000000007
#define ull unsigned long long
#pragma GCC optimize("O3")

vector<int> g[105];
bool visited[105];
vector<int> d[105], l[105];
int time;

void dfs(int u) {
    visited[u] = true;
    for(int i : g[u]) {
        if(!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    boost
    int t;
    cin >> t;
    while(t--) {
        int v,e;
        cin >> v >> e;
        for(int i=1;i<=e;++i) {
            int x,y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
    }
    return 0;
}