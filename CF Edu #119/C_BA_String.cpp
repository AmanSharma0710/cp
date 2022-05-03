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
    int n, k, x;
    cin>>n>>k>>x;
    string s;
    cin>>s;
    int as = 0;
    for(int i=0; i<n; i++){
        if(s[i]=='a'){
            as++;
        }
    }
    vector<int> v(as+1, 1);
    int idx = 0;
    for(int i=0; i<n; i++){
        if(s[i]=='a'){
            idx++;
        }
        else{
            v[idx]+= k;
        }
    }
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
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
