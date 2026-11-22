
/*
Author: Lương Nguyễn Duy Hoàng
Data: 28/09/2007
Task: PrefixSum + DifferenceArray + Rời rạc hóa
Idea:
// ============================== IDEA ==============================
*) Đầu tiên, đây là một bài toán "khá" phực tạp nên ta cần phải xác định
được ý tưởng chính của bài toán:
    -) Đề cho n phép biến đổi cơ sở:
        +) Phép thử i: với mọi x trong khoảng (li, ri)
                a[x] += si.(x - li + 1)
        => Hay nói cách khác là cộng theo "cấp số cộng" của si. Và ta phải
        nhận ra được đây là 1 hàm tuyến tính theo x nếu như muốn giải quyết
        được bài toán này. Ta thấy được là si.(x - li + 1) chính là 1 hàm bậc
        nhất. Ta còn cần phải hiểu khi mà 2 hàm bậc nhất đi qua 1 điểm và
        cộng vào điểm đó thì sẽ có dạng như thế nào. Ví dụ:
            a[x]+=A1.x + B1
            a[x]+=A2.x + B2
        => Thì ta phải biết được rằng cộng các hệ số a[x]+=(A1 + A2)x + (B1 + B2)
        của 2 hàm bậc nhất đi qua 1 điểm x. Điều này rất quan trọng để giải quyết
        bài toán này.
    -) Đề cho m phép biến đổi trực tiếp:
        +) Mỗi phép j trong đoạn chỉ số [Lj, Rj]
        +) Nghĩa là tất cả phép cơ sở i trong đoạn đó được áp dụng thêm 1 lần.
        => Hay có thể hiểu là: biến đổi 2(biến đổi 1).
    -) Đề cho q truy vấn: Tổng(z = X -> Y - 1)a[z] = ?
    => Ta cần phải thấy độ phức tạp "khổng lồ" của bài toán này nên không thể
    nào xây dựng mảng trực tiếp để xử lý được. Nên ta phải nghĩ đến phương pháp
    rời rạc hóa để lưu các điểm quan trọng.
*) Thứ hai, ta cần phải phân tích thật kĩ và làm bài toán theo các bước để có
thể tối ưu hóa bài toán:
    -) Bước 1: Thấy được ngay rằng đây là "trồng(trồng)" của các phép biến đổi
    thật sự là bất khả thi nếu thực hiện từng bước, 1 cách rời rạc ta cần phải
    có 1 cách nào đó ta phải nghĩ đến PrefixSum + differenceArray:
        +) Mỗi phép trực tiếp [Lj, Rj] cộng 1 lần cho phép cơ sở trong đoạn đó.
        +) Ở đây ta cần phải dùng mảng hiệu trên "chỉ số phép cơ sở" như sau:
            .) diff[Lj]++;
            .) diff[Rj + 1]--;
        => Lưu ý ở đây là chỉ số của phép cơ sở nên Lj, Rj <= n thôi nhé!
        +) Sau đó ta sẽ sử dụng PrefixSum để tính xem số lần phép cơ sở thứ "i"
        được thực hiện.
            .) cnt[i] = số lần phép cơ sở i được thực hiện
        => Ở đây ta thấy rằng độ phức tạp chỉ O(n + m) rất nhỏ so với việc thay
        đổi 1 cách trực tiếp từng thao tác 1.
    -) Bước 2(quan trọng): Ta cần phải biến đổi để mỗi phép hàm cơ sở biến thành
    1 hàm tuyết tính trên trục số để ta có thể tính toán 1 cách dễ dàng dựa trên
    "trực tiếp vị trí của nó":
        +) Phép cơ sở "i" sau khi được thực hiện cnt[i] lần sẽ đóng góp cho a[x]
        như sau:
            .) cnt[i].si.(x - li + 1), x trong khoảng [li, ri)
            => Ta thấy x - li + 1 trực giác thì rất đẹp nhưng việc sử lí lại trở
            lên rất khó khăn nên ta cần phải biến đổi thành hàm tuyến tính bằng
            cách khai triển ra để nó phụ thuộc "rõ ràng" vào x.
        +) Ta khai triển hàm như sau:
            .) cnt[i].si.x + cnt[i].si.(1 - li)
        => Nghĩa là trên đoạn [li, ri) có dạng:
            .) Ai.x + Bi
            => Ai = cnt[i].si
            => Bi = cnt[i].si.(1 - li)
        => Lưu ý cốt lõi ở đây ta không tính trực tiếp như này nhé! Mà ta sẽ sử
        dụng toán để có thể tính được 1 cách nhanh chóng.
    -) Bước 3(trái tim của bài toán): Quét theo tọa độ sau khi rời rạc hóa. Bởi
    ta thấy mảng a là vô hạn, ta không thể duyệt từng x được.
        +) Nhận xét:
            .) Giá trị của a[x] chỉ thay đổi theo "cấu trúc" có sẵn của các phép
            biến đổi cơ sở:
                -> li
                -> ri
            .) Và ta cũng chỉ cần biết kết quả tại các điểm truy vấn:
                -> X
                -> Y
            => Từ đây ta thấy được "phải" gom tất cả các tọa độ quan trọng này
            và rời rạc hóa bằng cách: sắp xếp và unique lại => Chỗ này thì nên
            dùng vector để linh hoạt xử lí.
        +) Nhưng ta cần phải hiểu được là tại sao lại có thể "rời rạc hóa" được?
            .) Ta thấy như sau: Giữa 2 mốc liên tiếp d[k] và d[k + 1], tập các đoạn
            đang hoạt động là cố định(d: ở đây là vector sau khi đã được rời rạc hóa)
            => Nghĩa là trên cả đoạn nguyên: [d[k], d[k + 1])
            ta có: a[x] = A.x + B
                => A, B ở đây là tổng hệ số của tất cả các phép cơ sở đang được
                "thực hiện" ở vị trí x.
                => Nếu chưa hiểu có thể thấy như sau
                    long long c = mod(cnt[i]);
                    long long s = mod(a[i].s);
                    long long A = c*s%MOD;
                    long long B = A*mod(1 - a[i].l)%MOD;
                    int li = getid(a[i].l, d);
                    int ri = getid(a[i].r, d);
                    eventA[li] = (eventA[li] + A)%MOD;
                    eventA[ri] = (eventA[ri] - A)%MOD;
                    eventB[li] = (eventB[li] + B)%MOD;
                    eventB[ri] = (eventB[ri] - B)%MOD;
                => Chỗ này ta thể hiện là đến vị trí "i" khi trên vector rời rạc
                hóa thì có những "sự kiện" nào đang được thực hiện. Ta phải nhớ
                đến += (A1 + A2 +...).x + (B1 + B2 +...)
                .) Giả sử ta muốn tính tổng đoạn (d[k], d[k + 1]).
                    -> ta đặt: L = d[k]
                               R = d[k + 1]
                => Ta sẽ tính tổng trên đoạn [L, R) như sau:
                    tmp = Tổng(L -> R - 1)(A.x + B) = A.(Tổng(L -> R - 1)x) + B(R - L) (*)
                    -> Lưu ý đề bài cho phép biến đổi cơ sở chỉ trong khoảng [L, R).
                    Nhưng ta vẫn có thể lấp đầy "trục số" bởi: [L1, R1), [R1, R2), [R2, R3),...
                    -> tmp ở đây là kết quả trong đoạn [L, R) nhé! Để tí nữa ta sẽ dùng
                    PrefixSum để tính tổng. Nếu chưa hiểu hiểu thì có thể thấy xem đoạn sau:
                    tmp1 = là tổng của đoạn [0, L1)
                    tmp2 = tổng của đoạn [L1, L2)
                    ...
                    Nếu muốn tính tổng đoạn [0, Li) = tmp1 + tmp2 + ...+ tmpi
                    -> Đoạn này thì là PrefixSum cơ bản rồi nhé!
                => Ta phân tích (*) kĩ hơn để khi vào bài toán:
                    tmp = A.(R + L - 1)*(R - L)/2 + B*(R - L)
                    -> A.(R + L - 1)*(R - L)/2 dễ dàng tính trong O(1) mà không cần
                    duyệt từng vị trí.
                    -> B*(R - L) cũng dễ dàng tính trong O(1).
    -) Bước 4: Ta chỉ cần Prefixsum theo tiến độ hay theo (*) mà ta đã thể hiện
    ở trên. Nếu không hiểu cách làm hãy xem đoạn sau:

        vector<long long> prefix(k + 5, 0);
        long long tmpA = 0, tmpB = 0;
        for (int i = 0; i < k - 1; i++)
        {
            tmpA = (tmpA + eventA[i])%MOD;
            tmpB = (tmpB + eventB[i])%MOD;
            long long L = d[i];
            long long R = d[i + 1];
            long long len = mod(R - L);
            long long sumx = sum(L, R);
            long long tmp = (tmpA*sumx%MOD + tmpB*len%MOD)%MOD;
            prefix[i + 1] = (prefix[i] + tmp)%MOD; => Chỗ này là PrefixSum mà ta đang nói đến.
        }

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
const long long MOD = 1e9 + 7;
const long long div2 = (MOD + 1)/2;

struct data1
{
    long long l, r, s;
};

struct data2
{
    long long x, y;
};

int getid(long long x, const vector<long long>& d)
{
    int id = lower_bound(d.begin(), d.end(), x) - d.begin();
    return id;
}

long long mod(long long x)
{
    x%=MOD;
    if (x < 0) x+=MOD;
    return x;
}

long long sum(long long L, long long R)
{
    if (L >= R) return 0;
    long long len = mod(R - L);
    long long start = mod(L);
    long long endd = mod(R - 1);
    return (((start + endd)%MOD)*len%MOD)*div2%MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
        // Bước 1:
        int n, m, q;
        cin >> n >> m >> q;
        vector<data1> a(n + 1);
        vector<long long> d;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].l >> a[i].r >> a[i].s;
            d.push_back(a[i].l);
            d.push_back(a[i].r);
        }
        vector<long long> diff(n + 5, 0);
        for (int i = 1; i <= m; i++)
        {
            int L, R;
            cin >> L >> R;
            diff[L]++;
            diff[R + 1]--;
        }
        vector<long long> cnt(n + 5, 0);
        for (int i = 1; i <= n; i++)
            cnt[i] = cnt[i - 1] + diff[i];
        vector<data2> ques(q + 5);
        for (int i = 0; i < q; i++)
        {
            cin >> ques[i].x >> ques[i].y;
            d.push_back(ques[i].x);
            d.push_back(ques[i].y);
        }
        // Bước 2 + Bước 3:
        sort(d.begin(), d.end());
        d.erase(unique(d.begin(), d.end()), d.end());
        int k = (int)d.size();
        vector<long long> eventA(k+ 5, 0), eventB(k + 5, 0);
        for (int i = 1; i <= n; i++)
        {
            if (cnt[i] == 0 || a[i].s == 0) continue;
            long long c = mod(cnt[i]);
            long long s = mod(a[i].s);
            long long A = c*s%MOD;
            long long B = A*mod(1 - a[i].l)%MOD;
            int li = getid(a[i].l, d);
            int ri = getid(a[i].r, d);
            eventA[li] = (eventA[li] + A)%MOD;
            eventA[ri] = (eventA[ri] - A)%MOD;
            eventB[li] = (eventB[li] + B)%MOD;
            eventB[ri] = (eventB[ri] - B)%MOD;
            // => Chỗ này eventB[ri] - B bởi ta thấy rằng nó chỉ cần tính trong
            // khoảng [d[li], d[ri]) thôi nên đến d[ri] là thì ta đã kết thúc
            // quá trình mà hàm tuyến tính cộng vào rồi.
        }
        vector<long long> prefix(k + 5, 0);
        long long tmpA = 0, tmpB = 0;
        for (int i = 0; i < k - 1; i++)
        {
            tmpA = (tmpA + eventA[i])%MOD;
            tmpB = (tmpB + eventB[i])%MOD;
            long long L = d[i];
            long long R = d[i + 1];
            long long len = mod(R - L);
            long long sumx = sum(L, R);
            long long tmp = (tmpA*sumx%MOD + tmpB*len%MOD)%MOD;
            prefix[i + 1] = (prefix[i] + tmp)%MOD;
        }
        // Bước 4:
        for (int i = 0; i < q; i++)
        {
            int idx = getid(ques[i].x, d);
            int idy = getid(ques[i].y, d);
            long long ans = (prefix[idy] - prefix[idx])%MOD;
            if (ans < 0) ans+=MOD;
            cout << ans << "\n";
        }
    return 0;
}
