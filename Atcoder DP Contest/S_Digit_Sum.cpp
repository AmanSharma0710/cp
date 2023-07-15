#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main(){
    string s;
    cin>>s;
    int n, d;
    cin>>d;
    n = s.length();
    vector<int>v(n);
    for(int i=0; i<n; i++){
        v[i] = s[i]-'0';
    }
    vector<vector<long long>>dp(d, vector<long long>(2));
    dp[0][0] = 1;
    for(int i=0; i<n; i++){
        vector<vector<long long>>temp(d, vector<long long>(2));
        for(int sum=0; sum<d; sum++){
            for(int digit = 0; digit<10; digit++){
                if(digit<v[i]){
                    temp[(sum+digit)%d][1] += dp[sum][0] + dp[sum][1];
                }
                if(digit==v[i]){
                    temp[(sum+digit)%d][0] += dp[sum][0];
                    temp[(sum+digit)%d][1] += dp[sum][1];
                }
                if(digit>v[i]){
                    temp[(sum+digit)%d][1] += dp[sum][1];
                }
                temp[(sum+digit)%d][1]%=MOD;
                temp[(sum+digit)%d][0]%=MOD;
            }
        }
        dp = temp;
    }
    int ans = (dp[0][0] + dp[0][1] - 1 + MOD)%MOD;
    cout<<ans<<endl;
}