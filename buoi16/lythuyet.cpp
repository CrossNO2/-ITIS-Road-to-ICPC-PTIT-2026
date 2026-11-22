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

/*
hnay học về segment tree và fenwick tree
về cơ bản, segment tree nó là 1 cây nhị phân, ở các trường hợp nó có thể là 1 cây 
nhị phân đầy đủ (full binary tree)

ứng dụng của nó thường là để cập nhật hoặc thực hiện các truy vấn tìm kiếm trên 
các đoạn con l r mà l r là số rất lớn ( > 1e8) 
giả sử tính tổng đoạn l r mà mỗi truy vấn yêu cầu cập nhật 1 số trong đoạn từ 1 -> n
rồi tính tổng trên đoạn l r đó
prefix sum sẽ làm được nếu l r k quá lớn vì time complexity nó là O(n)
nếu l r lên đến 1e12 là TLE

fenwick tree về cơ bản cũng như segment tree nma nó nhanh hơn
nma những bài nào fenwick làm đc thì segment cũng làm đc
ngược lại thì ko

*/

int main() {
    boost;
    
    return 0;
}

/*
    Hav a nice day xD
    Author Bạch Ngọc Đức - Cross
*/