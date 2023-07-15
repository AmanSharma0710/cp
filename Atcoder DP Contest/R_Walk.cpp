#include<bits/stdc++.h>
using namespace std;

long long dp[51][51][65];
const int MOD = 1e9+7;

int main(){
    long long n, K;
    cin>>n>>K;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>dp[i][j][0];
        }
    }
    for(int k=1; k<65; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dp[i][j][k] = 0;
                for(int l=0; l<n; l++){
                    dp[i][j][k] += (dp[i][l][k-1]*dp[l][j][k-1])%MOD;
                    dp[i][j][k]%=MOD;
                }
            }
        }
    }
    vector<vector<long long>>ans(n, vector<long long>(n));
    bool first = true;
    for(int shift = 0; ; shift++){
        long long pow = (1ll)<<shift;
        if(pow>K) break;
        if(pow&K){
            if(first){
                first = false;
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        ans[i][j] = dp[i][j][shift];
                    }
                }
            }
            else{
                vector<vector<long long>>temp(n, vector<long long>(n, 0));
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        for(int l=0; l<n; l++){
                            temp[i][j] += (ans[i][l]*dp[l][j][shift])%MOD;
                            temp[i][j]%=MOD;
                        }
                    }
                }
                ans = temp;
            }
        }
    }
    long long paths = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            paths += ans[i][j];
            paths%=MOD;
        }
    }
    cout<<paths<<endl;
    return 0;
}