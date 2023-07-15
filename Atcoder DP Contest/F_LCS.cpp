#include<bits/stdc++.h>
using namespace std;


int main(){
    string s, t;
    cin>>s>>t;
    int n = s.length(), m = t.length();
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(s[i-1]==t[j-1]){
                dp[i][j] = max(dp[i-1][j-1]+1, dp[i][j]);
            }
        }
    }
    string ans = "";
    for(int i=n, j=m; i>0 && j>0;){
        if(s[i-1]==t[j-1] && dp[i][j]==(dp[i-1][j-1]+1)){
            ans+=s[i-1];
            i--;
            j--;
            continue;
        }
        if(dp[i][j]==dp[i-1][j]){
            i--;
            continue;
        }
        if(dp[i][j]==dp[i][j-1]){
            j--;
            continue;
        }
        assert(1);
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
    return 0;
}