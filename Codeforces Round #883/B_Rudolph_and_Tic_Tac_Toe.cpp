#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){
    string s[3];
    for(int i=0; i<3; i++) cin>>s[i];
    for(int i=0; i<3; i++){
        char c=s[i][0];
        bool flag=true;
        for(int j=0; j<3; j++){
            if(s[i][j]!=c) flag=false;
        }
        if(flag && c!='.'){
            cout<<c<<endl;
            return;
        }
    }
    for(int i=0; i<3; i++){
        char c=s[0][i];
        bool flag=true;
        for(int j=0; j<3; j++){
            if(s[j][i]!=c) flag=false;
        }
        if(flag && c!='.'){
            cout<<c<<endl;
            return;
        }
    }
    if(s[0][0]==s[1][1] && s[1][1]==s[2][2] && s[1][1]!='.'){
        cout<<s[0][0]<<endl;
        return;
    }
    if(s[0][2]==s[1][1] && s[1][1]==s[2][0] && s[1][1]!='.'){
        cout<<s[0][2]<<endl;
        return;
    }
    cout<<"DRAW\n";
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
