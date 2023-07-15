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

class DisjSet {
    int *rank, *parent, n;
 
public:
    DisjSet(int n)
    {
        rank = new int[n];
        parent = new int[n];
        this->n = n;
        makeSet();
    }

    void makeSet()
    {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
 
        return parent[x];
    }

    void Union(int x, int y)
    {
        int xset = find(x);
        int yset = find(y);
        if (xset == yset)
            return;
        if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        }
        else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        }
        else {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};



void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> p(n);
    for(int i=0; i<n; i++){
        cin>>p[i];
    }
    DisjSet ds(n);
    for(int i=0; i<n; i++){
        ds.Union(i, p[i]-1);
    }
    vector<vector<int>> children(n, vector<int>(0));
    for(int i=0; i<n; i++){
        children[ds.find(i)].push_back(i);
    }
    vector<uint64_t> grps;
    for(int i=0; i<n; i++){
        if(children[i].size() > 0){
            string s1 = s, s2 = s;
            int grpsize = 1;
            for(grpsize=1; grpsize<=children[i].size(); grpsize++){
                //change s1 according to p
                for(int j=0; j<n; j++){
                    s2[j] = s1[p[j]-1];
                }
                s1=s2;
                bool equal = true;
                for(int j=0; j<children[i].size(); j++){
                    if(s1[children[i][j]] != s[children[i][j]]){
                        equal = false;
                        break;
                    }
                }
                if(equal){
                    grps.push_back(grpsize);
                    break;
                }
            }
        }
    }
    uint64_t ans = 1;
    for(int i=0; i<grps.size(); i++){
        assert(grps[i] > 0);
        ans = lcm(ans, grps[i]);
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
