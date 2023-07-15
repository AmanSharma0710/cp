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

int ans;

vector<int> n1, n2, c1, c2;
vector<int> visit1, visit2;
vector<vector<int>> tree;

int dfs1(int node, int parent){
    int visit_curr = 0;
    for(int child: tree[node]){
        if(child == parent) continue;
        visit_curr |= dfs1(child, node);
    }
    visit_curr |= visit1[node];
    n1[node] = visit_curr;
    return visit_curr;
}
int dfs2(int node, int parent){
    int visit_curr = 0;
    for(int child: tree[node]){
        if(child == parent) continue;
        visit_curr |= dfs2(child, node);
    }
    visit_curr |= visit2[node];
    n2[node] = visit_curr;
    return visit_curr;
}

int dfs11(int node, int parent, int d){
    int dist = INT_MAX;
    for(int child: tree[node]){
        if(child == parent) continue;
        dist = min(dist, dfs11(child, node, d));
    }
    if((visit2[node] == 1) && dist>d){
        dist = d;
    }
    if(dist<=0){
        c1[node] = 1;
    }
    return dist-1;
}
int dfs22(int node, int parent, int d){
    int dist = INT_MAX;
    for(int child: tree[node]){
        if(child == parent) continue;
        dist = min(dist, dfs22(child, node, d));
    }
    if((visit1[node] == 1) && dist>d){
        dist = d;
    }
    if(dist<=0){
        c2[node] = 1;
    }
    return dist-1;
}

void dfs13(int node, int parent){
    if((n1[node]||c1[node])==0){
        return;
    }
    for(int child: tree[node]){
        if(child == parent) continue;
        dfs13(child, node);
    }
    if(parent!=-1){
        ans+=2;
    }
    return;
}
void dfs23(int node, int parent){
    if((n2[node]||c2[node])==0){
        return;
    }
    for(int child: tree[node]){
        if(child == parent) continue;
        dfs23(child, node);
    }
    if(parent!=-1){
        ans+=2;
    }
    return;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ans = 0;
    int n, d;
    cin>>n>>d;
    n1.assign(n, 0);
    n2.assign(n, 0);
    c1.assign(n, 0);
    c2.assign(n, 0);
    visit1.assign(n, 0);
    visit2.assign(n, 0);
    //Make tree with root 0 and n nodes
    tree.assign(n, vector<int>());
    rep(i, 0, n-1){
        int u, v;
        cin>>u>>v;
        u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int m1, m2;
    cin>>m1;
    for(int i=0; i<m1; i++){
        int x;
        cin>>x;
        x--;
        visit1[x] = 1; 
    }
    cin>>m2;
    for(int i=0; i<m2; i++){
        int x;
        cin>>x;
        x--;
        visit2[x] = 1;
    }
    dfs1(0, -1);
    dfs2(0, -1);
    dfs11(0, -1, d);
    dfs22(0, -1, d);
    dfs13(0, -1);
    dfs23(0, -1);
    cout<<ans<<endl;
    return 0;
}
