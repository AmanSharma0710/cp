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

vector<int> parent;
vector<int> children;
vector<int> active_children;
vector<vector<int>> tree;
vector<int> val;
void dfs(int node, int par){
    if(par!=-1){
        parent[node] = par;
        children[par]++;
    }
    for(auto child: tree[node]){
        if(child!=par){
            dfs(child, node);
        }
    }
    return;
}


void solve(){
    int n;
    cin>>n;
    parent.assign(n, -1);
    active_children.assign(n, 0);
    tree.assign(n, vector<int>());
    val.assign(n, 0);
    children.assign(n, 0);
    rep(i,0,n-1){
        int u, v;
        cin>>u>>v;
        u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(0, -1);
    int act_edges = n-1;
    int q;
    cin>>q;
    for(int i=0; i<q; i++){
        int type;
        cin>>type;
        if(type==1){
            int node;
            cin>>node;
            node--;
            //Node is a leaf node
            if(children[node]==0){
                if(val[node]==0){
                    val[node] = 1;
                    if(parent[node]!=-1){
                        active_children[parent[node]]++;
                        act_edges--;
                    }
                }
            }
            //Node is not a leaf node
            else{
                if(val[node]==0){
                    if(active_children[node]==children[node]){
                        val[node] = 1;
                        if(parent[node]!=-1){
                            active_children[parent[node]]++;
                            act_edges--;
                        }
                    }
                }
            }
        }
        else{
            if(val[0]==0){
                cout<<act_edges<<endl;
            }
            else{
                cout<<(n-1)<<endl;
            }
        }
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
