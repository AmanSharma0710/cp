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
    vi v(n), left(0), right(0);
    rep(i,0,n){
        cin>>v[i];
    }
    string s;
    cin>>s;
    int l=0, r=0;
    for(int i=0; i<n; i++){
        if(s[i]=='B'){
            left.push_back(v[i]);
            l++;
        }
        else{
            right.push_back(v[i]);
            r++;
        }
    }
    if(l>0){
        sort(left.begin(), left.end());
    }
    if(r>0){
        sort(right.begin(), right.end());
    }
    vector<bool> filled(n+1, false);
    int start=1;
    for(int i=0; i<l; i++){
        if(left[i]>=start){
            filled[start]=true;
        }
        start++;
    }
    int end=n;
    for(int i=r-1; i>=0; i--){
        if(right[i]<=end){
            filled[end]=true;
        }
        end--;
    }
    for(int i=1; i<=n; i++){
        if(!filled[i]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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
