#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){                //to sort vii by second element use sort(v.begin(), v.end(), sortbysec);
    return (a.second < b.second);
}
#define MOD 1000000007

vector<int> factors;

void solve(){
    int x;
    cin>>x;
    cout<<(binary_search(factors.begin(), factors.end(), x)?"YES":"NO")<<endl;
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1;
    cin>>t;
    factors.push_back(0);
    for(int i=3; i<1000; i++){
        if(((i-2)*180)%i==0){
            factors.push_back(((i-2)*180)/i);
        }
    }
    sort(factors.begin(), factors.end());
    while (t--){
        solve();       
    }
    return 0;
}
