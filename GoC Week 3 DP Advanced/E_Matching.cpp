#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){                //to sort vii by second element use sort(v.begin(), v.end(), sortbysec);
    return (a.second < b.second);
}
#define MOD 1000000007

int n;
vector<vi> match;
vector<vi> dp;
int solve(int curr_man, int mask){
    if(curr_man==n){
        return 1;
    }
    int women = 0;
    for(int j=0; j<n; j++){
        if(mask & (1<<j)){
            women++;
        }
    }
    assert(n-curr_man == women);
    if(dp[curr_man][mask]!=-1){
        return dp[curr_man][mask];
    }
    int ans = 0;
    for(int j=0; j<n; j++){
        if((mask & (1<<j)) && match[curr_man][j]){
            ans += solve(curr_man+1, mask ^ (1<<j));
            ans%=MOD;
        }
    }
    return dp[curr_man][mask] = ans;
}

signed main(){
    time_t start, end;
    time(&start);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    match.assign(n, vector<int>(n));
    dp.assign(n, vector<int>(1<<n, -1));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>match[i][j];
        }
    }
    cout<<solve(0, (1<<n)-1)<<endl;
    time(&end);
    double time_taken = double(end-start);
    cout<< setprecision(10) << time_taken <<endl;
    return 0;
}
