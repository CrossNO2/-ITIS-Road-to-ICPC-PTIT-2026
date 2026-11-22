#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;

    while(t--){
        int n;

    cin >> n;

    int a[n + 5];

    for(int i = 1; i <= n; i++) cin >> a[i];

    int l = 1;
    int r = n;

    int check1 = 1;
    int check2 = n;
    int check = 0;

    int ds1 = 0;
    int ds2 = 0;

    while(l <= r){
        
        if(a[l] == check1){
            l++;
            check1++;
        }
        else if(a[l] == check2){
            l++;
            check2--;
        }
        if(a[r] == check1){
            r--;
            check1++;
        }
        else if(a[r] == check2){
            r--;
            check2--;
        }

        if(a[l] != check1 && a[l] != check2 && a[r] != check1 && a[r] != check2){
            ds1 = l;
            ds2 = r;
            check = 1;
            break;
        }
    }

    if(check == 0){
        cout << "-1" << endl;
    }
    else{
        cout << l << " " << r << endl;
    }
    }

    

}