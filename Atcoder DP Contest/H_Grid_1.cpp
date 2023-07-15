#include<bits/stdc++.h>
using namespace std;


int main(){
    int h, w;
    cin>>h>>w;
    vector<string> v(h);
    for(int i=0; i<h; i++) cin>>v[i];
    vector<vector<int>> dp(h, vector<int>(w, 0));
    dp[0][0] = 1;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(v[i][j]=='#')continue;
            if(i-1>=0) dp[i][j] += dp[i-1][j];
            if(j-1>=0) dp[i][j] += dp[i][j-1];
            dp[i][j]%=(int)1e9 + 7;
        }
    }
    cout<<dp[h-1][w-1]<<endl;
}