#include <bits/stdc++.h>
using namespace std;

struct node{
    int x, y, xay, sua;
} ;
vector<node> ve;


int n, m;

int pa[200005];

void init(){
    for(int i = 1; i<=n; i++){
        pa[i] = i;
    }
}
int find(int i){
    if(i == pa[i]) return i;
    int p = find(pa[i]);
    pa[i] = p;
    return p;
}

int Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return 0;
    else{
        if(a > b) swap(a, b);
        pa[b] = a;
        return 1;
    }
}

bool cmp(node a, node b){
    if(a. xay != b.xay) return a.sua < b.sua;
    else return a.xay < b.xay;
}

void Krukal(){
    sort(ve.begin(), ve.end(), cmp);
    long long tong = 0;
    for(auto u: ve){
        if(Union(u.x, u.y)){
            tong += u.xay;
        }
        else{
            tong += min(u.xay, u.sua);
        }
    }
    cout << tong<<'\n';
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        init();
        while(m--){
            int a, b, xay, sua;
            cin >> a >> b >> xay >> sua;
            ve.push_back({a, b, xay, sua});
        }
        Krukal();
        ve.clear();
    }  
}