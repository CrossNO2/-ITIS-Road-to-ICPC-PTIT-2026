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
int path[105];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i : g[u]) {
        if(!visited[i]) {
            visited[i] = true;
            path[i] = u;
            q.push(i);
            }
        }
    }
}

void print(int s, int t) {
    if(!visited[t]) {
        cout << -1;
        return;
    }vector<int> ans;
    for(int i = t; i!=0;i = path[i]) {
        ans.push_back(i);
        if(i==s) break;
    }reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();++i) {
        cout << ans[i];
        if(i<ans.size()-1) cout << " -> ";
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
            path[i] = -1;
        }
        for(int i=0;i<e;++i) {
            int x,y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        int x,y;
        cin >> x >> y;
        bfs(x);
        print(x,y);
        cout << endl;
    }
    return 0;
}