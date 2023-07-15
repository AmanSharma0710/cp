#include<bits/stdc++.h>
using namespace std;
#define int long long int

vector<vector<int>>dp;

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    dp.assign(n, vector<int>(n, 0));
    // dp[i][j] stores the length of the longest palindromic subsequence in the substring s[i...j]
    for(int i=0; i<n; i++){
        dp[i][i]=1;
    }
    for(int i=0; i<n-1; i++){
        if(s[i]==s[i+1]){
            dp[i][i+1]=2;
        }
        else{
            dp[i][i+1]=1;
        }
    }
    for(int i=2; i<n; i++){
        for(int j=0; j<n-i; j++){
            if(s[j]==s[j+i]){
                dp[j][j+i]=2+dp[j+1][j+i-1];
            }
            else{
                dp[j][j+i]=max(dp[j+1][j+i], dp[j][j+i-1]);
            }
        }
    }
    int l = -1, r = -1;
    for(int i=0; i<n; i++){
        if(s[i]=='A'){
            if(l==-1){
                l=i;
            }
            r=i;
        }
    }
    if(l==-1){
        cout<<0<<" ";
    }
    else{
        cout<<dp[l][r]<<" ";
    }
    l = -1, r = -1;
    for(int i=0; i<n; i++){
        if(s[i]=='G'){
            if(l==-1){
                l=i;
            }
            r=i;
        }
    }
    if(l==-1){
        cout<<0<<endl;
    }
    else{
        cout<<dp[l][r]<<endl;
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
