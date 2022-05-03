#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve(){
    int n, m;
    cin>>n>>m;
    vector<int> v(m);
    for(int i=0; i<m; i++){
        cin>>v[i];
    }
    int house=1;
    unsigned int ans=0;
    for(int i=0; i<m; i++){
        if(v[i]>=house){
            ans+= v[i]-house;
            house=v[i];
        }
        else if(v[i]<house){
            ans+= n - (house-v[i]);
            house=v[i];
        }
    }
    cout<<ans<<endl;
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1;
    //cin>>t;
    while (t--){
        solve();       
    }
    return 0;
}
