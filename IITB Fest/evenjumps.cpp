#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    int ans=0, mark=0;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(mark==0){
            ans+=x;
        }
        mark = !mark;
    }
    cout<<ans<<endl;
    return 0;
}
