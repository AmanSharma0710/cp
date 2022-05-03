#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vi v(n);
    for(auto &i:v)
        cin>>i;
    vi dp(n, INT_MAX);
    dp[0]=0;
    dp[1] = abs(v[0]-v[1]);
    for(int i=2; i<n; i++){
        dp[i] = min(dp[i-1] + abs(v[i]-v[i-1]), dp[i-2] + abs(v[i]-v[i-2]));
    }
    cout<<dp[n-1]<<endl;
    return 0;
}
