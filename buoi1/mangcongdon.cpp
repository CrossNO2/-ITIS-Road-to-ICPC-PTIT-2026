#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define MAXN 100000
#define ll long long

/*mảng cộng dồn ngoài cách xây dựng vòng for thông thường, ta còn có thể sử dụng hàm có sẵn trong c++
cú pháp: partial_sum(a.begin(),a.end(),s.begin()) với a là vector nhập vào, s là vector tổng sum*/

/*ngoài việc có mảng cộng dồn 1 chiều, ta còn có mảng cộng dồn 2 chiều với ý tưởng là tính cộng dồn theo 
hình chữ nhật i j
cách xây dựng: bên file mangcongdon2*/

// int main() {
//     int t;
//     cin >> t;
//     while(t--) {
//         vector<int> a = {2,3,5,9};
//         vector<int> s(a.size());
//         partial_sum(a.begin(),a.end(),s.begin());
//         for(auto &x : s) cout << x << " ";
//     }
// }
bool f[MAXN];
ll s[MAXN+1];

void sieve() {
    for(int i=0;i<=MAXN;i++) f[i] = true;
    f[0] = f[1] = false;
    for(int i=2;i*i<=MAXN;i++) {
        if(f[i]) {
            for(int j = i*i;j<=MAXN;j+=i) {
                f[j] = false;
            }
        }
    }for(int i=1;i<=MAXN;i++) {
        s[i] = s[i-1] + (f[i] ? 1:0);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    sieve();
    while(t--) {
        int n;
        cin >> n;
        cout << s[n]<< endl;
    }return 0;
}
