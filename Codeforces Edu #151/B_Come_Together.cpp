#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){
    pair<int, int> a, b, c;
    cin>>a.first>>a.second>>b.first>>b.second>>c.first>>c.second;
    b.first -= a.first;
    b.second -= a.second;
    c.first -= a.first;
    c.second -= a.second;
    int x = 0;
    if(b.first * c.first >=0){
        x = min(abs(b.first), abs(c.first));
    }
    int y = 0;
    if(b.second * c.second >=0){
        y = min(abs(b.second), abs(c.second));
    }
    cout<<1 + x + y<<endl;
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
