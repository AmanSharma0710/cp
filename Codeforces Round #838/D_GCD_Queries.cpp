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

void query(int i, int j){
    cout<<"? "<<i+1<<" "<<j+1<<endl;
    cout.flush();
}


void solve(){
    int n;
    cin>>n;
    int x=0, y=0, max_gcd = 0, i=1;
    while(i<n){
        query(y, i);
        int gcd_;
        cin>>gcd_;
        if(gcd_==-1){
            assert(1);
        }
        if(gcd_>max_gcd){
            max_gcd = gcd_;
            x = y;
            y = i;
        }
        i++;
    }
    if(max_gcd==1){
        i = y+1;
        y = x;
        while(i<n){
            query(y, i);
            int gcd_;
            cin>>gcd_;
            if(gcd_==-1){
                assert(1);
            }
            if(gcd_>max_gcd){
                max_gcd = gcd_;
                x = y;
                y = i;
            }
            i++;
        }
    }
    cout<<"! "<<x+1<<" "<<y+1<<endl;
    int ans;
    cin>>ans;
    if(ans==-1){
        assert(1);
    }
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
