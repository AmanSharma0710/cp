#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)

vector<vi> dp;
//dp[l][r] stores the minimum cost to combine elements from l to r
vector<vi> sum;

int solve(int l, int r){
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    int cost = LLONG_MAX;
    for(int boundary=l; boundary<r; boundary++){
        cost=min(cost, sum[l][r] + solve(l, boundary) + solve(boundary+1, r));
    }
    return dp[l][r]=cost;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vi v(n);
    dp.assign(n, vector<int>(n, -1));
    sum.assign(n, vector<int>(n, 0));
    for(auto &i:v){
        cin>>i;
    }
    for(int i=0; i<n; i++){
        sum[i][i]=v[i];
        dp[i][i]=0;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i<j){
                sum[i][j] = sum[i][j-1] + v[j];
            }
        }
    }
    cout<<solve(0, n-1)<<endl;
    return 0;
}
