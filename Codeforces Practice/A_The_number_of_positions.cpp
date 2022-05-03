#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, a, b, ans=0;
    cin>>n>>a>>b;
    vector<int>possible(n, 0);
    for(int i=a; i<n; i++){
        possible[i]++;
    }
    for(int i=n-b-1; i<n; i++){
        possible[i]++;
        if(possible[i]==2){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}