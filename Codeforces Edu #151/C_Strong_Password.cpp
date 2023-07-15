#include<bits/stdc++.h>
using namespace std;
#define int long long int



void solve(){
    string s;
    cin>>s;
    int n = s.length();
    int m;
    cin>>m;
    string l, r;
    cin>>l>>r;
    reverse(l.begin(), l.end());
    reverse(r.begin(), r.end());
    vector<int> dp(m+1, INT_MAX);    //dp[i] stores the leftmost index of s that contains the subsequence
    dp[0] = n;
    bool ans = false;
    for(int i=0; i<m; i++){
        vector<int> temp(10, INT_MAX);
        for(int j=0; j<dp[i]; j++){
            if((l[i]<=s[j]) && (s[j]<=r[i])){
                temp[s[j]-'0'] = j;
            }
        }
        for(int j=0; j<10; j++){
            if((l[i]-'0'<=j) && (j<=r[i]-'0')){
                dp[i+1] = min(dp[i+1], temp[j]);
                if(temp[j]==INT_MAX){
                    ans = true;
                }
            }
        }
        if(dp[i+1]==INT_MAX || ans){
            ans = true;
            break;
        }
    }
    if(!ans){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
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
