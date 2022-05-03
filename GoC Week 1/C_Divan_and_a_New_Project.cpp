#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){                //to sort vii by second element use sort(v.begin(), v.end(), sortbysec);
    return (a.second > b.second);
}
#define MOD 1000000007


void solve(){
    int n;
    cin>>n;
    vii pairs;
    rep(i,0,n){
        int x;
        cin>>x;
        pairs.push_back({i+1,x});
    }
    sort(pairs.begin(), pairs.end(), sortbysec);
    int ans=1, sign=0;
    vector<int> position(n+1);
    position[0]=0;
    for(int i=0; i<n; i++){
        if(sign){
            position[pairs[i].first]=ans;
        }
        else{
            position[pairs[i].first]= -ans;
        }
        if(sign){
            ans++;
        }
        sign=!sign;
    }
    ans=0;
    for(int i=0; i<n; i++){
        ans+= abs(pairs[i].second*position[pairs[i].first]);
    }
    cout<< 2*ans <<endl;
    for(int i=0; i<=n; i++){
        cout<<position[i]<<" ";
    }
    cout<<endl;
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
