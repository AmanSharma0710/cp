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
    int n, k;
    cin>>n>>k;
    //dp[i] = number of ways to make array with ith element as last element
    int dp[n+1], dp2[n+1];
    for(int i=1; i<=n; i++){
        dp[i] = 1;
        dp2[i] = 0;
    }
    for(int i=1; i<k; i++){
        for(int j=1; j<=n; j++){
            for(int k=j; k<=n; k+=j){
                dp2[k] = (dp2[k] + dp[j])%MOD;
            }
        }
        for(int j=1; j<=n; j++){
            dp[j] = dp2[j];
            dp2[j] = 0;
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        ans = (ans + dp[i])%MOD;
    }
    cout<<ans<<endl;
    return 0;
}
