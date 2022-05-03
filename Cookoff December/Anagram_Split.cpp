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



void solve(){
    int n;
    cin>>n;
    cout<<"? 1 "<<n<<endl;
    cout.flush();
    int a, b;
    cin>>a>>b;
    if(abs(a-b)!=1){
        cout<<"! -1"<<endl;
        return;
    }
    bool flag=false;
    if(a<b){
        swap(a,b);
        flag=true;
    }
    int l=1, r=n, mid;
    while(l<r){
        mid=(l+r)/2;
        cout<<"? 1 "<<mid<<endl;
        cout.flush();
        int a, b;
        if(flag){
            cin>>b>>a;
        }
        else{
            cin>>a>>b;
        }
        if(a>b){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    mid=(l+r)/2;
    cout<<"! "<<mid<<endl;
    cout.flush();
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1;
    cin>>t;
    while (t--){
        solve();       
    }
    return 0;
}
