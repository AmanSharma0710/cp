#include<bits/stdc++.h>
using namespace std;
#define int long long int



void solve(){
    int n, ans=0;
    cin>>n;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        if(b<a) ans++;
    }
    cout<<ans<<"\n";
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
