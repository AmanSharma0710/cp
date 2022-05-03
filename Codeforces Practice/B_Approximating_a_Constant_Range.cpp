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
int power(int x, int y, int p){
    int res = 1; 
    x = x % p;  
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
unsigned mod_pow(unsigned a, unsigned b, unsigned mod) {
    unsigned result = 1;
    while (b > 0) {
        if (b & 1)
            result = unsigned(uint64_t(result) * a % mod);
        a = unsigned(uint64_t(a) * a % mod);
        b >>= 1;
    }
    return result;
}

bool isPrime(unsigned n) {
    if (n < 2)
        return false;
    for (unsigned p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29})
        if (n % p == 0)
            return n == p;
    int r = __builtin_ctz(n - 1);
    unsigned d = (n - 1) >> r;
    for (unsigned a : {2, 7, 61}) {
        unsigned x = mod_pow(a % n, d, n);
        if (x <= 1 || x == n - 1)
            continue;
        for (int i = 0; i < r - 1 && x != n - 1; i++)
            x = unsigned(uint64_t(x) * x % n);
        if (x != n - 1)
            return false;
    }
    return true;
}

void solve(){
    int n, query;
    cin>>n>>query;
    vector<vector<int>>adj(n, vector<int>(0));
    for(int i=0; i<n-1; i++){
        int x, y;
        cin>>x>>y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int leafs=0;
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0]=true;
    q.push(-1);
    int black=0, white=0, curr=0;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        if(front!=-1){
            bool isLeaf=true;
            if(curr==0){
                //cout<<"black-"<<front<<endl;
                black++;
            }
            else{
                //cout<<"white-"<<front<<endl;
                white++;
            }
            for(int j=0; j<adj[front].size(); j++){
                if(visited[adj[front][j]]==false){
                    isLeaf=false;
                    visited[adj[front][j]]=true;
                    q.push(adj[front][j]);
                }
            }
            if(isLeaf && !curr){
                leafs++;
                black--;
            }
        }
        else if(!q.empty()){
            curr^=1;
            q.push(-1);
        }
    }
    //cout<<black<<white<<leafs<<endl;
    if(query==1){
        cout<<(abs(white-black)+leafs)<<endl;
    }
    else{
        int a = min(black, white), b=max(black, white);
        if(leafs>(b-a)){
            int temp=a;
            a=b;
            leafs-= b-temp;
            //cout<<leafs<<endl;
            a+= leafs/2;
            b+=leafs-leafs/2;
        //cout<<a<<b<<endl;
        }
        else{
            a+= leafs;
        }
        cout<<abs(a-b)<<endl;
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
