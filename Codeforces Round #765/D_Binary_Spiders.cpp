#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){                //to sort vii by second element use sort(v.begin(), v.end(), sortbysec);
    return (a.second < b.second);
}
#define MOD 1000000007


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k;
    cin>>n>>k;
    int x = (1ll<<32)-1;
    x = x<< (31 - __builtin_clz(k));
    set<int> s;
    rep(i,0,n){
        int a;
        cin>>a;
        s.insert(a&x);
    }
    for(int i=0; i<n; i++){
        if(s.find(i))
    }
    return 0;
}
