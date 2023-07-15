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
int power(int x, int y){
    int res = 1; 
    x = x;  
    while (y > 0){
        if (y & 1)
            res = (res*x);
        y = y>>1;
        x = (x*x);
    }
    return res;
}


int query(int x){
    assert(x>0);
    cout<<"- "<<x<<endl;
    cout.flush();
    int res;
    cin>>res;
    if(res==-1){
        exit(0);
    }
    return res;
}
void solve(){
    int n=0;
    int cnt, cnt1, res=0, steps=1;
    cin>>cnt;
    while(cnt){
        cnt1 = query(1 + res);
        steps++;
        assert(steps<31);
        int pos = cnt1 - cnt + 1;
        res = power(2, pos) - 1;
        n+=power(2, pos);
        cnt--;
    }
    cout<<"! "<<n<<endl;
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
