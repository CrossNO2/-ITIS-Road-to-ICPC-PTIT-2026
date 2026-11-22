#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
#define FOR(i, l, r) for (ll i = l; i <= r; i++)
#define FORD(i, l, r) for (ll i = l; i >= r; i--)
#define fre(NAME) freopen(NAME".inp","r",stdin); freopen(NAME".out","w",stdout)
#define ALL(a) a.begin(), a.end()
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pii pair<ll,ll>
#define ldb long double
#pragma GCC optimize("O3")
#define ull unsigned long long
const ll MAXN = 3005;
const ll INF = 4e18;
const ll MOD = 1e9+7;

//ITIS

struct node {
    int data;
    struct node *next;
};

//tạo node
node *makeNode(int x) {
    node *newNode = new node();
    newNode -> data = x;
    newNode -> next = NULL;
    return newNode;
}

//thêm node vào đầu DSLK
void pushfront(node *(*head), int x) {
    node *newNode = makeNode(x);
    newNode -> next = *head;
    *head = newNode;
}

//duyệt DSLK
void browse(node *head) {
    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
}

//thêm vào cuối DSLK
void pushback(node *(*head),int x) {
    node *tmp = *head;
    node *newNode = makeNode(x);
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    while(tmp -> next != NULL) {
        tmp = tmp -> next;
    }
    tmp -> next = newNode;
}

//thêm vào giữa DSLK
void pushheap(node *(*head), int x, int k) {
    int n = size(*head);
    if(k<1 || k>n) return;
    if(k==1) {
        pushfront(head,x);
        return;
    }
    node *temp = *head;
    for(int i=1;i<=k-2;++i) temp = temp -> next;
    node *newNode = makeNode(x);
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

int main() {
    boost;
    
    return 0;
}

/*
    Hav a nice day xD
    Author Bạch Ngọc Đức - Cross
*/