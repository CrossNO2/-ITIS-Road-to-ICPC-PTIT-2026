#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAXN 200000
#pragma GCC optimize // auto thêm inline vào trước hàm, chỉ dùng cho máy chấm ptit vì codeforces có sẵn

/*bài toán hôm nay sẽ nói về recursion, hay còn biết đến là đệ quy
đệ quy đơn giản là hàm trong hàm, sử dụng cơ chế stack, hiểu là các ngăn xếp
với cơ chế LIFO (Last In First Out) vào sau ra trước.
muốn hiểu đệ quy thì chạy tay vẽ giấy
vẽ cái stack ra

đệ quy đuôi(tail recursion) là đệ quy mà lệnh gọi đệ quy là lệnh cuối cùng
nó phải thực hiện*/

/*phải hiểu đệ quy để học quay lui*/

/*về bài toán thứ 2, ta sẽ nói về two pointer
có thể là cả 2 đi ngược trên cùng 1 đoạn hoặc cùng đi xuôi
bước 1: khởi tạo 2 con trỏ l r
b2: khởi tạo điều kiện dừng
b3: điều kiện di chuyển con trỏ
b4: cập nhật điều kiện 
bài toán 2 con trỏ chỉ sử dụng trong bài toán nếu bài đó
có 1 trong 2 trường hợp sau
hoặc là 2 con trỏ có 1 hướng di chuyển
hoặc là bài toán có tính đơn điệu(cái gì đó tăng thì cái còn lại tăng)*/