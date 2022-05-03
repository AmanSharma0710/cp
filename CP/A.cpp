#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
bool sortbysec(const pair<int,int> &a, //to sort vii by second element use sort(v.begin(), v.end(), sortbysec);
              const pair<int,int> &b)
{
    return (a.second < b.second);
}



void solve(){
    max = max(max);

    return;

}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   
    int t=1, caseno=1;
    //cin>>t;
    while (t--){
        //cout<<"Case #"<<(caseno++)<<": ";
        solve();       
    }
    return 0;
}
