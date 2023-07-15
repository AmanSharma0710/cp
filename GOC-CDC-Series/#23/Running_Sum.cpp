#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve(){
    int n; cin>>n;
    int x = 0;
    set<int> s;
    for(int i=0; i<n; i++){
        int a; cin>>a;
        x += a;
        s.insert(x);
    }
    cout<< 1-*s.begin() <<endl;
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1;
    cin>>t;
    while (t--){
        solve();       
    }
    return 0;
}
