#include <bits/stdc++.h>
using namespace std;
int x, y;
int mod = 1e9 + 7;

map<long long, long long> mp, vs;
long long fb(int n){
    if(n == 1) return x;
    if(n == 2) return y;
    if(vs[n] == 1) return mp[n];
    long long res = fb(n-1) - fb(n-2);
    if(res > 0) res%=mod;
    else res = (res + mod) %mod;
    mp[n] = res;
    vs[n] = 1;
    return res;
}

int main(){
    cin >> x >> y;
    long long n;
    cin >> n;
    long long tmp = fb(n);
    // cout << fb(n);
    if(tmp < 0) cout << (tmp + mod)%mod;
    else cout << tmp;
}