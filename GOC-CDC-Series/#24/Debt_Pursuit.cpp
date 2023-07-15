#include<bits/stdc++.h>
using namespace std;
#define int long long int

class sqrtDecomposition{
    public:
        int n;
        int len;
        vector<int> a;
        vector<int> b;
        sqrtDecomposition(int n){
            len = (int)sqrt(n+ .0)+1;
            while(n<len*len) n++;
            this->n = n;
            a.assign(n, LLONG_MIN);
            b.assign(len, LLONG_MIN);
        }
        ~sqrtDecomposition(){
            a.clear();
            b.clear();
        }
        void update(int l, int r, int val){
            l = min(l, n-1);
            r = min(r, n-1);
            //only support value updates that are greater than the current value
            int l_block = l/len, r_block = r/len;
            if(l_block == r_block){
                for(int i=l; i<=r; i++) a[i] = max(a[i], val);
                return;
            }
            for(int i=l; i<(l_block+1)*len; i++) a[i] = max(a[i], val);
            for(int i=l_block+1; i<r_block; i++) b[i] = max(b[i], val);
            for(int i=r_block*len; i<=r; i++) a[i] = max(a[i], val);
            return;
        }
        int query(int pos){
            return max(a[pos], b[pos/len]);
        }
};

void solve(){
    int n, p0;
    cin>>n>>p0;
    vector<int> c(n), p(n), d(n);
    for (int i=0; i<n; i++) cin>>c[i];
    for (int i=0; i<n; i++) cin>>p[i];
    for (int i=0; i<n; i++) cin>>d[i];
    sqrtDecomposition sd(n);
    sd.update(0, p0-1, 0);
    for(int i=0; i<n; i++){
        //max money we can get to i
        int max_money = sd.query(i);
        max_money -= c[i];
        //max money we can get to i+p[i]
        sd.update(i+1, i+p[i], max_money);
    }
    int ans = 0, sum = 0;
    for(int i=0; i<n; i++){
        sum += d[i];
        ans = max(ans, sd.query(i)+sum);
    }
    cout<<ans<<endl;
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
