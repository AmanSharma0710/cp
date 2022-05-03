#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)



signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vi v(n);
    for(auto &i:v)
        cin>>i;
    int nin = *min_element(v.begin(), v.end());
    vector<int> dp(k+1, 0);
    //Basic losing state problem
    //If any of the last possible states is losing, the current is winning
    for(int i=nin; i<=k; i++){
        for(auto &j:v){
            if(i-j >= 0){
                if(dp[i-j]==0){
                    dp[i]=1;
                    break;
                }
            }
        }
    }
    cout<< (dp[k]?"First":"Second") <<endl;
    return 0;
}
