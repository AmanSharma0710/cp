#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>




void solve(){
    int r, c;
    cin>>r>>c;
    for(int i=0; i<2*r+1; i++){
        for(int j=0; j<2*c+1; j++){
            if(i<2 && j<2){
                cout<<".";
            }
            else if(i%2==0){
                if(j%2==0){
                    cout<<"+";
                }
                else{
                    cout<<"-";
                }
            }
            else{
                if(j%2==0){
                    cout<<"|";
                }
                else{
                    cout<<".";
                }
            }
        }
        cout<<endl;
    }

    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1, tc = 1;
    cin>>t;
    while (t--){
        cout<<"Case #"<<tc++<<":"<<endl;
        solve();       
    }
    return 0;
}
