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
    vector<int> p1(4), p2(4), p3(4);
    rep(i,0,4) cin>>p1[i];
    rep(i,0,4) cin>>p2[i];
    rep(i,0,4) cin>>p3[i];
    vector<int> available(4);
    rep(i,0,4) available[i] = min(p1[i], min(p2[i], p3[i]));
    if(accumulate(available.begin(), available.end(), 0ll)<1000000){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    int total=0, done=0;
    for(int i=0; i<4; i++){
        if(done){
            available[i] = 0;
        }
        total+=available[i];
        if(total>=1000000){
            total-=available[i];
            available[i] = 1000000-total;
            done = 1;
        }
        cout<<available[i]<<" ";
    }
    cout<<endl;
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1, tc=1;
    cin>>t;
    while (t--){
        cout<<"Case #"<<tc++<<": ";
        solve();       
    }
    return 0;
}
