#include<bits/stdc++.h>
using namespace std;
#define int long long int


int remove_zeros(int x){
    int ans=0, count=1;
    while(x){
        if(x%10){
            ans += count*(x%10);
            count*=10;
        }
        x/=10;
    }
    return ans;
}

void solve(){
    int a, b;
    cin>>a>>b;
    int c = a+b;
    if(remove_zeros(a) + remove_zeros(b) == remove_zeros(c)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1;
    while (t--){
        solve();       
    }
    return 0;
}
