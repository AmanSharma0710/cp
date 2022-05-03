#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){
    int n, d;
    cin>>n>>d;
    vector<pair<int, int>>friends(n);
    for(int i=0; i<n; i++){
        cin>>friends[i].first>>friends[i].second;
    }    
    sort(friends.begin(), friends.end());
    int ans=0, l=0, friendship=0, money=0;
    for(int i=0; i<n; i++){
        money = friends[l].first;
        friendship += friends[i].second;
        while(friends[i].first - money >= d){
            friendship-= friends[l].second;
            l++;
            money = friends[l].first;
        }
        ans=max(ans, friendship);
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
