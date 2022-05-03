#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){
    int n;
    cin>>n;
    map<string, int> mp;
    for(int i=0; i<n; i++){
        string s;
        int yr;
        cin>>s>>yr;
        mp[s]= max(mp[s], yr);
    }
    string ans ="";
    bool found = false;
    int m, ansyr=INT_MAX;
    cin>>m;
    for(int i=0; i<m; i++){
        string s;
        cin>>s;
        //not used 
        if(mp[s]==0 && !found){
            found=true;
            ans=s;
            ansyr=INT_MIN;
            continue;
        }
        if(mp[s]==0 && found){
            if(s>ans){
                ans=s;
            }
            continue;
        }

        if(mp[s]<ansyr){
            ans=s;
            ansyr=mp[s];
        }
        else if(mp[s]==ansyr){
            if(s>ans){
                ans=s;
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
