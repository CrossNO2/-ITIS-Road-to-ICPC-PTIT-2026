#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, long long>
#define iii pair<int, pair<long long, long long>>
#define fi first
#define se second

struct diem{
    int ed;
    long long a, d;
    long long cur_a;
    friend bool operator < (diem x,diem y){
        if(x.cur_a != y.cur_a) return x.cur_a > y.cur_a;
        else return x.d > y.d;
    }
};

int n, q, pa[200005];
long long d[200005], vs[200005];
vector<vector<diem>> ve(200005);

void path(int s, int t){
    long long max = -1, sum = 0;
    while(t != s){
        cout << t << endl;
        for(auto x: ve[t]){
            if(x.ed == pa[t]){
                max = fmax(max, x.a);
                sum += x.d;
                break;
            }
        }
        t = pa[t];
    }
    cout << max << " "<< sum;
}

void dijkstra(){
    for(int i = 1; i<=n; i++){
        d[i] = LLONG_MAX;
    }
    d[1] = 0;
    vs[1] = 1;
    priority_queue<diem> qe;
    for(auto x: ve[1]){
        qe.push(x);
        pa[x.ed] = 1;
    }
    while(!qe.empty()){
        diem x =qe.top();
        qe.pop();
        cout << x.ed << " "<< x.a <<" "<<x.d<<endl;
        if(vs[x.ed]) continue;
        
        d[x.ed] = x.cur_a;
        vs[x.ed] = 1;
        for(auto u : ve[x.ed]){
            if(!vs[u.ed]){
                cout << u.ed <<" ";
                if(d[u.ed] > d[x.ed]){
                    d[u.ed] = d[x.ed] + u.a;
                    u.cur_a = d[x.ed] + u.a;
                    qe.push(u);
                    pa[u.ed] = x.ed;
                }
            }
        }
        cout << endl;
    }
    path(1, n);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    while(q--){
        int x, y;
        long long a, d;
        cin >> x >> y >> a>> d;
        ve[x].push_back({y, a, d, a});
        ve[y].push_back({x, a, d, a});
    }
    dijkstra();
}