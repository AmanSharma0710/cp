#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, m;
    cin>>n>>m;
    int v[n+1];
    for(int i=1; i<=n; i++){
        cin>>v[i];
    }
    bitset<1001> pref[n+1];
    for(int i=0; i<=n; i++){
        for(int j=1; j<1001; j++){
            if(i==0){
                pref[i][j]=0;
            }
            else{
                pref[i][j]=pref[i-1][j]^(v[i]==j);
            }
        }
    }
    for(int qq=0; qq<m; qq++){
        int type;
        cin>>type;
        if(type==1){
            int x, y;
            cin>>x>>y;
            for(int i=x; i<n+1; i++){
                pref[i][v[x]].flip();
            }
            v[x]=y;
            for(int i=x; i<n+1; i++){
                pref[i][v[x]].flip();
            }
        }
        else{
            int l, r;
            cin>>l>>r;
            bitset<1001> ans=pref[r]^pref[l-1];
            cout<<ans.count()<<endl;
        }
    }
    return 0;
}