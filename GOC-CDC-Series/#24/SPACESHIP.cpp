#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){
    int n, k;
    cin>>n>>k;
    k--;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin>>a[i];
    int num = a[k];
    vector<int> dp(n, 0);
    for(int i=0; i<n; i++){
        if (a[i] < num) dp[i] = -1;
        if(a[i] > num) dp[i] = 1;
    }
    int ans = 0;
    int sum = 0;
    map<int, int> m;
    for(int i=k; i<n; i++){
        sum += dp[i];
        m[sum]++;
    }
    sum = 0;
    for(int i=k; i>=0; i--){
        sum += dp[i];
        ans += m[-sum];
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
