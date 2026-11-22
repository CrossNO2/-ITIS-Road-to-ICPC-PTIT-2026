#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define maxn 200000
#define mod 1000000007
#define ull unsigned long long
#pragma GCC optimize("O3")

struct Element {
    int leftMax, rightMax, maxSub, totalSum;
};

Element solve(vector<int> &array, int left, int right) {
    if (left == right) return {array[left], array[left], array[left], array[left]};
    int mid = (left + right) / 2;
    Element leftPart = solve(array, left, mid);
    Element rightPart = solve(array, mid + 1, right);
    Element result;
    result.leftMax = max(leftPart.leftMax, leftPart.totalSum + rightPart.leftMax);
    result.rightMax = max(rightPart.rightMax, rightPart.totalSum + leftPart.rightMax);
    result.maxSub = max({leftPart.maxSub, rightPart.maxSub, leftPart.rightMax + rightPart.leftMax});
    result.totalSum = leftPart.totalSum + rightPart.totalSum;
    return result;
}

int main() {
    boost
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;++i) cin >> a[i];
        cout << solve(a,0,n-1).maxSub << endl;
    }
    return 0;
}