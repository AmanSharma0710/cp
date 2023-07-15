#include<bits/stdc++.h>
using namespace std;

vector<int>a;
vector<long long> prefix;
vector<vector<long long>>dp;

long long cost(int l, int r){
    if(dp[l][r]!=-1) return dp[l][r];
    if(l==r) return 0;
    long long min_cost = 1e18;
    for(int i=l; i<r; i++){
        min_cost = min(min_cost, cost(l, i)+cost(i+1, r)+prefix[r+1]-prefix[l]);
    }
    return dp[l][r] = min_cost;
}

int main(){
    int n;
    cin>>n;
    a.resize(n);
    prefix.assign(n+1, 0);
    for(int i=0; i<n; i++){
        cin>>a[i];
        prefix[i+1] = prefix[i] + a[i];
    }
    dp.assign(n, vector<long long>(n, -1));
    cout<<cost(0, n-1)<<endl;
    return 0;
}