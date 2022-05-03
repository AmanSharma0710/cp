#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k;
    cin>>n>>k;
    vi v(n);
    for(auto &i:v)
        cin>>i;
    vi dp(n, INT_MAX);
    dp[0]=0;
    dp[1] = abs(v[0]-v[1]);
    for(int i=0; i<n-1; i++){
        for(int j=1; j<=k && i+j<n; j++){
            dp[i+j] = min(dp[i+j], dp[i] + abs(v[i] - v[i+j]));
        }
    }
    cout<<dp[n-1]<<endl;
    return 0;
}
