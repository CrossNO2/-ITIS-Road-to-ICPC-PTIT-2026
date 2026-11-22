#include <bits/stdc++.h>
using namespace std;

int a[100005][4];
long long F[100005][4];
int main(){
    int n;
    cin >> n;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=3; j++) cin >> a[i][j];
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=3; j++){
            if(i == 1) F[i][j] = a[i][j];
            else{
                if(j == 1) F[i][j] = max(F[i-1][2] + a[i][j], F[i-1][3] + a[i][j]);
                else if(j == 2) F[i][j] = max(F[i-1][3] + a[i][j], F[i-1][1] + a[i][j]);
                else F[i][j] = max(F[i-1][2] + a[i][j], F[i-1][1] + a[i][j]);
            }
        }
    }
    long long res = -1;
    for(int i = 1; i<=3; i++){
        res = max(F[n][i], res);
    }
    cout << res;
}