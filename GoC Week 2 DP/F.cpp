#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){                //to sort vii by second element use sort(v.begin(), v.end(), sortbysec);
    return (a.second < b.second);
}
#define MOD 1000000007


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s, t;
    cin>>s>>t;
    int n=s.length(), m=t.length();
    int dp[n+1][m+1];
    //dp[i][j] has the length of maximum lcs until position i and j
    //if(s[i]==t[j]) dp[i][j] = 1+dp[i-1][j-1]
    //else dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    for(int i=0; i<=m; i++){
        dp[0][i]=0;
    }
    for(int j=0; j<=n; j++){
        dp[j][0]=0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string ans = "";
    int i=n, j=m;
    while(i>0 && j>0){
        if(dp[i][j]== 1+dp[i-1][j-1]){
            ans.push_back(s[i-1]);
            i--; j--;
        }
        else if(dp[i][j]==dp[i-1][j]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
    return 0;
}
