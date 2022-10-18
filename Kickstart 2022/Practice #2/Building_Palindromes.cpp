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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<vector<int>> prefix(26, vector<int>(n+1, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            prefix[j][i+1] = prefix[j][i];
            if(s[i] == 'A' + j) prefix[j][i+1]++;
        }
    }
    int ans = 0;
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        int x = 0;
        for(int j = 0; j < 26; j++){
            x += (prefix[j][r] - prefix[j][l-1])%2;
        }
        if(x<=1){
            ans++;
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
