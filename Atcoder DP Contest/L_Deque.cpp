#include<bits/stdc++.h>
using namespace std;

vector<int>v;
vector<vector<long long>>dp;

long long calc(int l, int r, int chance){
    if(l>r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    if(chance == 0){
        return dp[l][r] = max(v[l] + calc(l+1, r, 1), v[r] + calc(l, r-1, 1));
    }
    return dp[l][r] = min(calc(l+1, r, 0), calc(l, r-1, 0));
}

signed main(){
    int n;
    cin>>n;
    v.resize(n);
    for(int i=0; i<n; i++) cin>>v[i];
    dp.assign(n, vector<long long>(n, -1));
    cout<< (2*calc(0, n-1, 0)-accumulate(v.begin(), v.end(), 0ll))<<endl;
    return 0;
}