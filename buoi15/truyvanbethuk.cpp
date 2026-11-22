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

//1e9 = 2^30;

struct node{
    int child[2];
    int cnt;

    node() {
        child[0] = child[1] = -1;
        cnt = 0;
    }
};

struct trie{
    vector<node> nodes;

    trie() {
        nodes.push_back(node());
    }

    int new_node() {
        nodes.push_back(node());
        return nodes.size()-1;
    }

    void add_num(int x) {
        int pos = 0;
        for(int i=30;i>=0;--i) {
            int bit = (x>>i) &1;
            if(nodes[pos].child[bit] == -1) nodes[pos].child[bit] = new_node();
            pos = nodes[pos].child[bit];
            nodes[pos].cnt++;
        }
    }

    int find_num(int k) {
        int pos = 0;
        int ans = 0;

        for(int i=30;i>=0;--i) {
            int left = nodes[pos].child[0];

            int left_cnt = 0;
            if(left != -1) {
                left_cnt = nodes[left].cnt;
            }
            if(left_cnt >= k) pos = left;
            else {
                k -= left_cnt;
                pos = nodes[pos].child[1];
                ans |= (1 << i);
            }
        }
        return ans;
    }
};

int main() {
    boost;
    int q;
    cin >> q;
    trie cay;
    while(q--) {
        int t,x;
        cin >> t >> x;
        if(t == 1) cay.add_num(x);
        else cout << cay.find_num(x) << endl;
    }
    return 0;
}

/*
    Hav a nice day xD
    Author Bạch Ngọc Đức - Cross
*/