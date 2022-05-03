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
    int n;
    cin>>n;
    vii pairs;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        pairs.push_back({a,b});
    }
    sort(pairs.begin(), pairs.end());
    int ans=0;
    for(int i=0; i<n; i++){
        if(min(pairs[i].first, pairs[i].second)>=ans){
            ans=min(pairs[i].first, pairs[i].second);
        }
        else{
            ans=max(pairs[i].first, pairs[i].second);
        }
    }
    cout<<ans<<endl;
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1;
    //cin>>t;
    while (t--){
        solve();       
    }
    return 0;
}
