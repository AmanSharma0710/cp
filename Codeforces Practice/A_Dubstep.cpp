#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    cin>>s;
    for(int i=0; i<(int)s.length()-2; i++){
        if(s[i]=='W' && s[i+1]=='U' && s[i+2]=='B'){
            s[i] = s[i+1] = s[i+2] = ' ';
        }
    }
    bool first=true, space=false;
    for(int i=0; i<s.length(); i++){
        if(s[i]!=' '){
            if(space && !first){
                cout<<" ";
            }
            if(first){
                first=false;
            }
            cout<<s[i];
            space=false;
        }
        else{
            space=true;
        }
    }
    return 0;
}
