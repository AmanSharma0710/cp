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
    map<char,int> mp;
    int ans=-1;
    for(char c='a'; c<='z'; c++){
        mp[c] = -1;
    }
    for(int i=0; i<s.length(); i++){
        if(mp[s[i]] == -1){
            mp[s[i]] = i;
        }
        else{
            ans = max(ans, i-mp[s[i]] - 1);
        }
    }
    cout<<ans<<endl;
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
