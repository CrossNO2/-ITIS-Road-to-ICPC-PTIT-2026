#include <bits/stdc++.h>
using namespace std;
int m;
string s;

int check(string s){
    for(int i = 0; i<s.size(); i++){
        if(isalpha(s[i])) return 0;
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m;
    stack<long long> st;
    while(cin >> s){
        if(check(s)){
            int tmp = stoi(s);
            st.push(tmp);
        }
        else{
            if(s == "a"){
                if(st.size() < 2) continue;
                else{
                    long long a = st.top();
                    st.pop();
                    long long b = st.top();
                    st.push(a);
                    st.push(a + b);
                }
            }
            else if(s == "e"){
                if(!st.empty()){
                long long a = st.top();
                st.push(a*2);
                }
            }
            else if(s == "r"){
                if(!st.empty()) st.pop();
            }
        }
    }
    long long sum = 0;
    while(!st.empty()){
        sum += st.top();
        st.pop();
    }
    if(abs(sum - m) <= 2) cout << "OK";
    else cout << "KO";
}