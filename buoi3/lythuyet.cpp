#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define maxn 200000
#define mod 100000007
#define ull unsigned long long
#pragma GCC optimize("O3")

/*bài hôm nay sẽ học về thuật toán sinh, đệ quy quay lui
ví dụ về thuật toán sinh, độ phức tạp thời gian là 2^n;
đầu tiên phải xây dựng 1 hàm khởi tạo:
int n; vector<ll> a(n);
int final = 0;
void ktao() {
    for(int i=1;i<=n;++i) a[i] = 0;
}

void sinh() {
    int i = n;
    while(i>=1&&a[i]==1) {
        a[i] = 0;
        --i;
    }if(i==0) {
        final = 1;
    }else {
        a[i] = 1;
    }
}

thuật toán sinh tổ hợp:
đầu tiên cũng phải xây 1 hàm khởi tạo:
int n; vector<ll> a(100);int final = 0;
void ktao() {
    for(int i=1;i<=n;++9) a[i] = i;
}

void sinh() {
    int i = k;
    while(i >= 1 && a[i] == n-k+i) {
        --i;
    }if(i==0) {
        final = 1;
    }else {
        a[i] += 1;
        for(int j=i+1;j<=j;++j) a[j] = a[j-1] + 1;
    }
}

int main() {
    cin >> n >> k;
    ktao();
    while(final == 0) {
        for(int i=1;i<=k;++i) cout << a[i] << " ";
    }cout << endl;
}

thuật toán sinh hoán vị:
cũng xây 1 hàm khởi tạo, thuật toán này có độ phức tạp 
thời gian là n!;
int n; vector<ll> a(100);int final = 0;
tự code nốt
*/

/*tiếp theo là thuật toán quay lui:
bản chất của quay lui là sử dụng đệ quy, ví dụ code dưới đây
*/

int n; vector<ll> a(100);
void in() {
    for(int i=0;i<n;++i) cout << a[i] << " ";
    cout << endl;
}

void ql(int i) {
    //khoảng giá trị của mỗi phần tử
    /*for(x->y) {
        chọn a[i] = j nếu nó thoả mãn điều kiện mà ta mong muốn
        if i == n in ra kq
        q1(i+1)
        xoá cái đk mà ta đánh dấu
    }code mẫu bên dưới*/
    for(int j=0;j<=i;++j) {
        a[i] = j;
        if(i==n) {
            in();
        }else {
            ql(i+1);
        }
    }
}

int main() {
    boost
    
    return 0;
}