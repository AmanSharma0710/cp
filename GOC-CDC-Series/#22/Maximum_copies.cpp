#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){
    string s, t;
    cin>>s>>t;
    vector<int>cnt1(26, 0), cnt2(26, 0);
    for (auto i:s) cnt1[i-'a']++;
    for (auto i:t) cnt2[i-'a']++;
    int ans = INT_MAX;
    for (int i=0; i<26; i++){
        if (cnt2[i] == 0) continue;
        ans = min(ans, cnt1[i]/cnt2[i]);
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
