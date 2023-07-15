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
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    int v[n];
    rep(i,0,n){
        v[i] = s[i] - '0';
    }
    int start=0, end=0;
    for(int i=0; i<n; i++){
        if(v[i]==1){
            start = i;
            break;
        }
    }
    for(int i=n-1; i>=0; i--){
        if(v[i]==1){
            end = n-1-i;
            break;
        }
    }
    int ans = count(v, v+n, 1)*11;
    if(ans==0){
        cout<<0<<endl;
        return;
    }
    if(k>=start+end && ans>11){
        ans-=11;
    }
    else{
        if(k>=end){
            ans-=10;
        }
        else if(k>=start){
            ans-=1;
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
