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

//build trie
struct node{
    int child[30]; //mảng lưu stt trong bảng chữ cái, child[0] = a, child[26] = z;
    int exist; //có bao nhiêu xâu kết thúc ở đỉnh hiện tại
    int cnt; //có bao nhiêu xâu tiền tố qua đỉnh hiện tại
};

struct trie{
    node nodes[1000000];
    int cur;

    trie() {
        cur = 0;
        memset(nodes[0].child,-1,sizeof(nodes[0].child));
        nodes[0].exist = 0;
        nodes[0].cnt = 0;
    }

    int new_node() {
        cur++;
        memset(nodes[cur].child,-1,sizeof(nodes[cur].child));
        nodes[cur].exist = nodes[0].cnt = 0;
        return cur;
    }

    void add_string(string s) {
        int pos = 0;
        for(auto f : s) {
            int c = f - 'a';
            if(nodes[pos].child[c] == -1) nodes[pos].child[c] = new_node();
            pos = nodes[pos].child[c];
            nodes[pos].cnt++;
        }
        nodes[pos].exist++;
    }

    bool find_string(string s) {
        int pos = 0;
        for(auto f : s) {
            int c = f - 'a';
            if(nodes[pos].child[c] == -1) return false;
            pos = nodes[pos].child[c];
        }
        return true;
    }

    void delete_string(string s) {
        if(find_string(s) == false) return;
        delete_string_recursive(0,s,0);
    }

    bool delete_string_recursive(int pos,string &s, int i) {
        if(i != s.size()) {
            int c = s[i] - 'a';
            bool isChildDeleted = delete_string_recursive(nodes[pos].child[c],s,i+1);
            if(isChildDeleted) nodes[pos].child[c] = -1;
        }
        else nodes[pos].exist--;
        if(pos != 0){
            nodes[pos].cnt--;
            if(nodes[pos].cnt == 0) return true;
        }
        return false;
    }
};

int main() {
    boost;
    int q;
    cin >> q;
    trie cay;
    while(q--) {
        int x;
        string s;
        cin >> x >> s;
        if(x == 1) {
            cay.add_string(s);
        }
        else if(x == 2) {
            if(cay.find_string(s)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}

/*
    Hav a nice day xD
    Author Bạch Ngọc Đức - Cross
*/