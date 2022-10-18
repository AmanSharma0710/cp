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


void solve(){
    int r, c;
    cin>>r>>c;
    vector<vector<int>> dp(r, vector<int>(c, INT_MAX));
    for(int i=0; i<r; i++){
        string s;
        cin>>s;
        for(int j=0; j<c; j++){
            if(s[j]=='1'){
                dp[i][j]=0;
            }
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
                if(i-1>=0){
                    dp[i][j]=min(dp[i][j], dp[i-1][j]+1);
                }
                if(j-1>=0){
                    dp[i][j]=min(dp[i][j], dp[i][j-1]+1);
                }
        }
    }
    for(int i=r-1; i>=0; i--){
        for(int j=c-1; j>=0; j--){
                if(i+1<r){
                    dp[i][j]=min(dp[i][j], dp[i+1][j]+1);
                }
                if(j+1<c){
                    dp[i][j]=min(dp[i][j], dp[i][j+1]+1);
                }
        }
    }
    for(int i=0; i<c; i++){
        for(int j=r-1; j>=0; j--){
            if(j<r-1){
                    dp[j][i]=min(dp[j][i], dp[j+1][i]+1);
                }
                if(i>=1){
                    dp[j][i]=min(dp[j][i], dp[j][i-1]+1);
                }
        }
    }
    for(int i=0; i<r; i++){
        for(int j=c-1; j>=0; j--){
            if(j<c-1){
                    dp[i][j]=min(dp[i][j], dp[i][j+1]+1);
                }
                if(i>=1){
                    dp[i][j]=min(dp[i][j], dp[i-1][j]+1);
                }
        }
    }
    int ans=INT_MIN;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            ans=max(ans, dp[i][j]);
        }
    }
    vector<vector<int>> dp1(r, vector<int>(c, INT_MAX));
    //choose point to add a new centre
    for(int x = 0; x < r; x++){
        for(int y = 0; y < c; y++){
            if(dp[x][y]==0){
                continue;
            }
            int dist = 0;
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    dp1[i][j]=dp[i][j];
                }
            }
            dp1[x][y]=0;
            
            for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
                    if(i-1>=0){
                        dp1[i][j]=min(dp1[i][j], dp1[i-1][j]+1);
                    }
                    if(j-1>=0){
                        dp1[i][j]=min(dp1[i][j], dp1[i][j-1]+1);
                    }
            }
        }
        for(int i=r-1; i>=0; i--){
            for(int j=c-1; j>=0; j--){
                    if(i+1<r){
                        dp1[i][j]=min(dp1[i][j], dp1[i+1][j]+1);
                    }
                    if(j+1<c){
                        dp1[i][j]=min(dp1[i][j], dp1[i][j+1]+1);
                    }
            }
        }
        for(int i=0; i<c; i++){
            for(int j=r-1; j>=0; j--){
                if(j<r-1){
                        dp1[j][i]=min(dp1[j][i], dp1[j+1][i]+1);
                    }
                    if(i>=1){
                        dp1[j][i]=min(dp1[j][i], dp1[j][i-1]+1);
                    }
            }
        }
        for(int i=0; i<r; i++){
            for(int j=c-1; j>=0; j--){
                if(j<c-1){
                        dp1[i][j]=min(dp1[i][j], dp1[i][j+1]+1);
                    }
                    if(i>=1){
                        dp1[i][j]=min(dp1[i][j], dp1[i-1][j]+1);
                    }
            }
        }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                dist = max(dist, dp1[i][j]);
            }
        }
        ans = min(ans, dist);
        }
    }
    cout<<ans<<endl;
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1, tc = 1;
    cin>>t;
    while (t--){
        cout<<"Case #"<<tc++<<": ";
        solve();       
    }
    return 0;
}
