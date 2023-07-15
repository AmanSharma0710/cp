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


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q;
    cin>>n>>q;
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    vi presum(n+1, 0);
    rep(i,0,n){
        presum[i+1] = presum[i] + a[i];
    }
    for(int i=0; i<q; i++){
        int x, y;
        cin>>x>>y;
        int ans = presum[n+(y-x)] - presum[n-x];
        cout<<ans<<endl;
    }
    return 0;
}
