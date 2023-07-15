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
    string s;
    cin>>s;
    int n = s.length();
    vector<int> pow = {1, 10, 100, 1000, 10000};
    vector<vector<int>> dp(n+1, vector<int>(5, 0));
    //dp[i+1][j] stores the value till position i if the element at position i is j
    for(int i=0; i<n; i++){
        int x = s[i] - 'A';
        int res = 0;
        int last = 0;
        if(i>0){
            res = dp[i][s[i-1]-'A'];
            last = s[i-1]-'A';
        }
        cout<<res<<" ";
        for(int j=0; j<5; j++){
            if(x<j){
                dp[i+1][j] = res - pow[x];
            }
            else{
                dp[i+1][j] = res + pow[x];
            }
        }
    }
    cout<<endl;
    for(int i=0; i<=n; i++){
        for(int j=0; j<5; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    int final_ans = -1e18;
    int sum = 0;
    int max_till_now = 0;
    for(int i=n-1; i>=0; i--){
        int x = s[i] - 'A';
        int ans;
        for(int j=0; j<5; j++){
            if(j<max_till_now) ans = -pow[j];
            else ans = pow[j];
            ans += dp[i][j];
            ans += sum;
            if(ans>final_ans){
                final_ans = ans;
            }
        }
        if(x<max_till_now) sum -= pow[x];
        else sum += pow[x];
        max_till_now = max(max_till_now, x);
    }
    cout<<final_ans<<endl;
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


/*
DDDDAAADDABECD

DDDDAAADDABEDD


*/