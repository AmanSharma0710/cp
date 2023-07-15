#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    vector<int>sv=v;
    sort(sv.begin(), sv.end());
    map<int, int>mp;
    int ans = 0;
    for(int i=0; i<n; i++){
        mp[v[i]]++;
        if(mp[v[i]]==0) mp.erase(v[i]);
        mp[sv[i]]--;
        if(mp[sv[i]]==0) mp.erase(sv[i]);
        if(mp.empty()) ans++;
    }
    cout<<ans<<endl;
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
