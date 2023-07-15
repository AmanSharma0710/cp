#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int n;
vector<vector<int>> a;
vector<long long> dp;

int ways(int man, int women){
    if(man==n) return 1;
    if(dp[women]!=-1) return dp[women];
    //Need to set the man-th man with a woman
    int woman;
    long long total_ways = 0;
    for(int i=0; i<n; i++){
        woman = 1<<i;
        if(women&woman) continue;
        if(a[man][i]){
            total_ways += ways(man+1, women|woman);
        }
    }
    return dp[women] = total_ways%MOD;
}

int main(){
    cin>>n;
    a.assign(n, vector<int>(n));
    dp.assign(1<<(n+1), -1);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    } 
    cout<<ways(0, 0)<<endl;
    return 0;
}