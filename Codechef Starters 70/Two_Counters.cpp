#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve(){
    int n, m;
    cin>>n>>m;
    vector<int> v(n, 0), a(m);
    for(int i=0; i<m; i++){
        cin>>a[i];
    }
    for(int i=0; i<m; i++){
        cin>>(v[a[i]-1]);
    }
    int dp[n][3][3];
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                dp[i][j][k]=0;
            }
        }
    }
    int ext=0;
    for(int i=0; i<n; i++){
        if(v[i]==0){
            ext++;
            //Copy from previous
            if(i==0)continue;
            for(int j=0; j<3; j++){
                for(int k=0; k<3; k++){
                    dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }
        if(v[i]==1){
            if(ext%2){
                dp[i][2][0] = dp[i-1][1][0] + 1;
                dp[i][1][0] = max(dp[i-1][0][0], dp[i-1][2][0]) + 1;
                dp[i][0][0] = max(dp[i-1][1][0], dp[i-1][0][1]);
                dp[i][0][1] = max(dp[i-1][0][0], dp[i-1][0][2]);
                dp[i][0][2] = dp[i-1][0][1];
            }
        }
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
