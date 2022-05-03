#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve(){
    vector<int> nos(8), ans(8, 0);
    for(int i=0;i<8;i++){
        cin>>nos[i];
    }
    for(int i=0;i<8;i++){
        for(int j=0; j<4; j++){
            ans[i] += nos[(i+j)%8];
        }   
    }
    cout<< *max_element(ans.begin(), ans.end())<<endl;
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
