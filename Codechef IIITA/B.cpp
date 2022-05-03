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

vector<int>dp(100001,0);

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=1;
    for(int i=0; i<n-1; i++){
        if(s[i]!=s[i+1]){
            ans++;
        }
    }
    cout<<(!dp[ans]?"RAMADHIR":"SAHID")<<endl;
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    dp[1]=1;
    dp[2]=0;
    for(int i=3; i<=100000; i++){
        dp[i]= (dp[i-1]==0 || dp[i-2]==0);
    }
    int t=1;
    cin>>t;
    while (t--){
        solve();       
    }
    return 0;
}
