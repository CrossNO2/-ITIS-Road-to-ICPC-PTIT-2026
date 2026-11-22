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

/*nay học về cấu trúc dữ liệu DSU cùng với cây khung nhỏ nhất

DSU: Disjoint Set Union
-Đúng như tên gọi của nó, tác dụng của nó là liên kết các phần tử rời rạc lại với nhau,
liên kết nhiều tp liên thông thành 1 tp liên thông
(Thành phần liên thông là luôn có đường đi từ x đến y và y đến x)
-Có 3 thao tác chính cho thuật toán này:
+:Make_set(a) với a là đỉnh của thuật toán.
tác dụng là tạo ra 1 tập hợp chứa a

+: Union(a,b) gộp hai tập hợp chứa hai đỉnh a và b
có thể là tập hợp chứa nhiều hơn 1 đỉnh

+: find(a): tìm đại diện của tập hợp ấy.

Xây dựng thuật toán:

Make_set(a) là xây dựng set với đỉnh đại diện a
Vì tất cả các đỉnh ban đầu chưa thuộc cái gì nên 
cần 1 cái mảng parent

ý tưởng của make_set là hàm khởi tạo, duyệt từ 1 đến n
nếu 1 phần tử đứng 1 mình thì cha của nó là chính nó.

Find(a): Tìm đại diện của 1 tập hợp.

Ý tưởng của thuật toán:
hàm find này sẽ dừng lại khi tìm cha trả về chính nó.
(trả về người đứng đầu)

khai báo hàm find(đỉnh v) 
nếu v = parent[v] thì dừng lại và trả về chính nó.
ko thì return về find(parent[v])
giống như backtrack quay lui tìm đến khi nào thấy cha của v là chính nó

Union(a,b):gộp 2 phần tử khác nhau vào 1 tập hợp

Ý tưởng của thuật toán:
gán a = cha của nó: a = find(a) trả về cha của a
gán b = cha của nó: b = find(b) trả về cha của b

nếu ta Union 2 đỉnh a b trả về cùng 1 cha thì là đã chung 1 tập hợp,
nếu chúng ko cùng 1 cha thì là a và b đang ko chung 1 tập hợp.

Làm sao để gộp 2 thằng a và b vào 1 tập hợp: chỉ cần gán b là cha của a.

Tối ưu thuật toán:
Thay vì mỗi lần find chỉ trả về cha của nó, giờ ta chỉ cần cho parent của 1 đỉnh
về tổ tiên lớn nhất.

Ý tưởng thuật toán:
Path compression: Nén đường đi.
thay vì return parent[v] thông thường, ta return thẳng parent[v] = find(parent[v])

Gộp theo kích cỡ / độ cao:
Ta sẽ gộp 2 tập hợp dựa trên kích cỡ hoặc độ cao vào nhau,
thêm 1 mảng size để đo kích cỡ của cái mảng,
gán mảng có kích cỡ bé hơn vào mảng kích cỡ lớn hơn
Tại sao lại thế ? vì nếu ta gán tập hợp kích cỡ lớn hơn, ta cần nhiều thao tác
để gán các con của tập hợp đó vào cha của tập hợp bé -> tốn thêm bước -> tốn thời gian.
sau khi gán phải tăng cái kích cỡ tập hợp lớn += tập hợp nhỏ.

Tác dụng của DSU:
+) tìm thành phần liên thông: vì mỗi tập hợp sẽ chỉ có 1 leader làm cha, nếu ta find 
2 thằng ngẫu nhiên trong tập hợp.

+) tìm đường đi

Cây khung nhỏ nhất
(Minium Spanning Tree)

Số cạnh = n-1
K có chu trình
Tất cả các đỉnh của đồ thị

Thuật toán trong cây khung: Kruskal:

B1: Khởi tạo:
MST = rỗng
E = danh sách cạnh
d(MST) = 0
d : trọng số.

B2: Sắp xếp:
Sắp xếp các cạnh tăng dần theo trọng số.

B3:
chạy 1 vòng lặp while(MST < n-1 && E != 0) {
    e = min(E) do sau khi sắp xếp E rồi thì e = min(E) = phần tử đầu tiên
    E = E/e;
    if(e nằm trong cây khung mà nó ko tạo ra chu trình) thì nhét e vào trong
    cây khung và tăng trọng số

}

Thuật toán trong cây khung: Prim:
Cũng là tham lam nhưng khác Kruskal ở chỗ:

2 tập đỉnh: 1 tập nằm trong cây khung và 1 tập đỉnh ko nằm trong cây khung.
Ko giới hạn đỉnh bắt đầu: Prim
Tạo cây khung từ đỉnh nhỏ nhất: Kruskal

Thuật toán:

B1: khởi tạo:







*/




int main() {
    boost;
    
    return 0;
}

/*
    Hav a nice day xD
    Author Bạch Ngọc Đức - Cross
*/