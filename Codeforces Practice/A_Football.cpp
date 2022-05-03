#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){
    int n;
    cin>>n;
    map<string, int> mp;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        mp[s]++;
    }
    int goals = INT_MIN;
    string ans = "";
    for(auto pr:mp){
        if(pr.second>goals){
            goals=pr.second;
            ans = pr.first;
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
