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
    vi a(3);
    cin>>a[0]>>a[1]>>a[2];
    sort(a.begin(), a.end());
    if(a[2]> ((a[1]+a[0])*2)){
        cout<<(a[1]+a[0])<<endl;
    }
    else{
        cout<<((a[2]+a[1]+a[0])/3)<<endl;
    }
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
