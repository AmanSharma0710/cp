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
    int minn = INT_MAX, ans=0;
    bool multiple = false;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x<minn){
            minn=x;
            ans=i+1;
            multiple=false;
        }
        else if(x==minn){
            multiple=true;
        }
    }
    if(multiple){
        cout<<"Still Rozdil"<<endl;
        return;
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
