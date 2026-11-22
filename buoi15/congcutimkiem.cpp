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

struct node{
    int child[26];
    int MAX;
    string suggest;

    node() {
        memset(child,-1,sizeof(child));
        MAX = -1;
        suggest = "";
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

    void add_string(string s,int w) {
        int pos = 0;
        for(auto f : s) {
            int c = f - 'a';
            if(nodes[pos].child[c] == -1) {
                nodes[pos].child[c] = new_node();
            }
            pos = nodes[pos].child[c];
            if(w > nodes[pos].MAX) {
                nodes[pos].MAX = w;
                nodes[pos].suggest = s;
            }
        }
    }

    string find_string(string s) {
        int pos = 0;
        for(auto f : s) {
            int c = f - 'a';
            if(nodes[pos].child[c] == -1) return "No suggestion!";
            pos = nodes[pos].child[c];
        }
        return nodes[pos].suggest;
    }
};

int main() {
    boost;
    int n,q;
    cin >> n >> q;
    trie cay;
    while(n--) {
        string s;
        int x;
        cin >> s >> x;
        cay.add_string(s,x);
    }
    while(q--) {
        string s1;
        cin >> s1;
        cout << cay.find_string(s1) << endl;
    }
    return 0;
}

/*
    Hav a nice day xD
    Author Bạch Ngọc Đức - Cross
*/