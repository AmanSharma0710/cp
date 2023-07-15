#include<bits/stdc++.h>
using namespace std;
#define int long long int


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    n++;
    int ans = 0;
    for(int i=1; i<32; i++){
        int x = 1<<i;
        if(x>n) break;
        int y = (n+1)/x;
        ans += y;
    }
    cout<<ans<<endl;
    return 0;
}
