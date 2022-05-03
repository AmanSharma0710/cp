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

vector<vector<int>> jobs;
vector<vector<int>> dp;
int n;

int solve(int curr_job, int mask){
    if(curr_job==n){
        return 0;
    }
    if(dp[curr_job][mask]!=-1){
        return dp[curr_job][mask];
    }
    int answer = INT_MAX;
    for(int j=0; j<n; j++){
        if(mask & (1<<j)){
            answer = min(answer, jobs[j][curr_job] + solve(curr_job+1, mask^(1<<j)));
        }
    }
    return dp[curr_job][mask] = answer;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    jobs.assign(n, vector<int>(n));
    dp.assign(n, vector<int>((1<<n), -1));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>jobs[i][j];
        }
    }
    cout<<solve(0, (1<<n)-1)<<endl;

    return 0;
}
