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
int u,v,e;
bool visited[105];
int cnt = 0;

void bfs(int s) {
    cnt++;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i : g[u]) {
        if(!visited[i]) {
            visited[i] = true;
            q.push(i);
            }
        }
    }
}

int main() {
    boost
    int t;
    cin >> t;
    while(t--) {
        cin >> v >> e;
        for(int i=0;i<105;++i) {
            g[i].clear();
            visited[i] = false;
        }cnt = 0;
        for(int i=0;i<e;++i) {
            int x,y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        for(int i=1;i<=v;++i) {
            if(!visited[i]) {
                bfs(i);
            }
        }
        cout << cnt << endl;
    }
    return 0;
}