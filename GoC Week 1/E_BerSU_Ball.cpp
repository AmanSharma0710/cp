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
    int n, m;
    cin>>n;
    vi boys(n);
    for(int i=0; i<n; i++){
        cin>>boys[i];
    }
    cin>>m;
    vi girls(m);
    for(int i=0; i<m; i++){
        cin>>girls[i];
    }
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());
    int b=0, g=0, ans=0;
    while(b<n && g<m){
        if(abs(boys[b]-girls[g])<=1){
            b++;
            g++;
            ans++;
        }
        else{
            if(boys[b]<girls[g]){
                b++;
            }
            else{
                g++;
            }
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
