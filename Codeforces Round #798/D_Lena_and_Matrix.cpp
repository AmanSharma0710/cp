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
    signed n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m)), dp1(n, vector<int>(m, INT_MIN)), dp2(n, vector<int>(m, INT_MIN)), dp3(n, vector<int>(m, INT_MIN)), dp4(n, vector<int>(m, INT_MIN));
    for(signed i=0; i<n; i++){
        string s;
        cin >> s;
        for(signed j=0; j<m; j++){
            v[i][j] = (s[j]=='B');
            if(v[i][j]){
                dp1[i][j] = 0;
                dp2[i][j] = 0;
                dp3[i][j] = 0;
                dp4[i][j] = 0;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            //dp1[i][j] = max(dp1[i-1][j]+1, dp1[i][j-1]+1);
            if(i>0 && j>0){
                dp1[i][j] = max(dp1[i-1][j]+1, dp1[i][j-1]+1);
            }
            else if(i>0){
                dp1[i][j] = dp1[i-1][j]+1;
            }
            else if(j>0){
                dp1[i][j] = dp1[i][j-1]+1;
            }
            dp1[i][j] = max(dp1[i][j], (v[i][j]?0:dp1[i][j]));
        }
    }
    for(int i=0; i<n; i++){
        for(int j=m-1; j>=0; j--){
            //dp2[i][j] = max(dp2[i-1][j]+1, dp2[i][j+1]+1);
            if(i>0 && j<m-1){
                dp2[i][j] = max(dp2[i-1][j]+1, dp2[i][j+1]+1);
            }
            else if(i>0){
                dp2[i][j] = dp2[i-1][j]+1;
            }
            else if(j<m-1){
                dp2[i][j] = dp2[i][j+1]+1;
            }
            dp2[i][j] = max(dp2[i][j], (v[i][j]?0:dp2[i][j]));
        }
    }
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<m; j++){
            //dp3[i][j] = max(dp3[i+1][j]+1, dp3[i][j-1]+1);
            if(i<n-1 && j>0){
                dp3[i][j] = max(dp3[i+1][j]+1, dp3[i][j-1]+1);
            }
            else if(i<n-1){
                dp3[i][j] = dp3[i+1][j]+1;
            }
            else if(j>0){
                dp3[i][j] = dp3[i][j-1]+1;
            }
            dp3[i][j] = max(dp3[i][j], (v[i][j]?0:dp3[i][j]));
        }
    }
    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            //dp4[i][j] = max(dp4[i+1][j]+1, dp4[i][j+1]+1);
            if(i<n-1 && j<m-1){
                dp4[i][j] = max(dp4[i+1][j]+1, dp4[i][j+1]+1);
            }
            else if(i<n-1){
                dp4[i][j] = dp4[i+1][j]+1;
            }
            else if(j<m-1){
                dp4[i][j] = dp4[i][j+1]+1;
            }
            dp4[i][j] = max(dp4[i][j], (v[i][j]?0:dp4[i][j]));
        }
    }
    int val = INT_MAX;
    int ansx = -1, ansy = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int dis = max(max(dp1[i][j], dp2[i][j]), max(dp3[i][j], dp4[i][j]));
            if(dis<=val){
                val = dis;
                ansx = i+1;
                ansy = j+1;
            }
        }
    }
    cout << ansx << " " << ansy << endl;
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1;
    cin>>t;
    while (t--){
        solve();       
    }
    return 0;
}
