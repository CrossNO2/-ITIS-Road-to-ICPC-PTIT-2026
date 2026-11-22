/*
I, Phép toán bit

1. phép AND: 
1&1 = 1

2. phép OR:
0 | 0 = 0

3. phép XOR:
0^1 = 1
0^0 = 0
1^1 = 0

4. phép NOT:
~1 = 0;

5. dịch bit trái/phải
+) dịch trái: << 
a << k = a.(2^k)

+) dịch phải: >> 
a >> k = a - (2^k)

II, các thao tác thường dùng

1. Kiểm tra bit
ktra bật tắt thì dùng phép and
a & 1 << i-1

2. bật bit i
a = a | 1<< i-1

3. tắt bit i
a = a &~ (1<<j-1)

4. lật bit 
a = a ^ 1<<j-1


III, ứng dụng bitmask vào dp
+) nguyên tắc 3 bước
-B1: dp[mask], dp[mask][u].... định nghĩa mảng dp
-B2: kết quả
-B3; chuyển trạng thái và base case

hàm __builtin_popcount(int), nếu cout __builtin_popcount(5) sẽ in ra 2
tương ứng với việc số 5 có 2 bit 1

IV, Quy hoạch động chữ số (Dp Digit)

V, Quy hoạch động tổ hợp




*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 5;
    for(int i=1;i<=3;++i) {
        if(a&(1<<(i-1))) cout << i << " ";
    }
    return 0;
}

