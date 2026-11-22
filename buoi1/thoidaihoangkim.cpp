#include <stdio.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int a[2100] = {0};

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 1955; i <= 2027; i++) a[i] = 0;
    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        a[l]++;
        a[r + 1]--;
    }
    int m = 0;
    int c = 0;
    int r = 1955;
    for (int i = 1955; i <= 2026; i++) {
        c += a[i];
        if (c > m) {
            m = c;
            r = i;
        }
    }
    printf("%d\n", r);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}