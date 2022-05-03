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
vector<int> rank_of_element;

int find_set(int x){
    if(parent[x] == x) return x;
    return parent[x] = find_set(parent[x]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank_of_element[a] < rank_of_element[b])
            swap(a, b);
        parent[b] = a;
        if (rank_of_element[a] == rank_of_element[b])
            rank_of_element[a]++;
    }
}

void solve(){
    int n, m;
    cin>>n>>m;
    vector<pair<int, int>> edges(m);
    rep(i,0,m){
        cin>>edges[i].first>>edges[i].second;
        edges[i].first--;
        edges[i].second--;
    }
    parent.assign(n, -1);
    rank_of_element.assign(n, 0);
    iota(parent.begin(), parent.end(), 0);
    set<pair<int, int>> possible_critical_edges;
    for(int i=0; i<m; i++){
        int a = edges[i].first;
        int b = edges[i].second;
        if(find_set(a) != find_set(b)){
            union_sets(a, b);
            possible_critical_edges.insert(edges[i]);
        }
    }
    iota(parent.begin(), parent.end(), 0);
    rank_of_element.assign(n, 0);
    for(int i=0; i<m; i++){
        if(possible_critical_edges.find(edges[i]) == possible_critical_edges.end()){
            int a = edges[i].first;
            int b = edges[i].second;
            if(find_set(a) != find_set(b)){
                union_sets(a, b);
            }
        }
    }
    vector<int> parent_archive = parent;
    vector<int> rank_of_element_archive = rank_of_element;
    vector<pair<int, int>> critical_edges(possible_critical_edges.begin(), possible_critical_edges.end());
    vector<pair<int, int>> ans;
    for(int i=0; i<critical_edges.size(); i++){
        parent = parent_archive;
        rank_of_element = rank_of_element_archive;
        for(int j=0; j<critical_edges.size(); j++){
            if(j==i){
                continue;
            }
            int a = critical_edges[j].first;
            int b = critical_edges[j].second;
            if(find_set(a) != find_set(b)){
                union_sets(a, b);
            }
        }
        if(find_set(critical_edges[i].first) != find_set(critical_edges[i].second)){
            ans.push_back({min(critical_edges[i].first, critical_edges[i].second), max(critical_edges[i].first, critical_edges[i].second)});
        }
    }
    sort(ans.begin(), ans.end());
    if(ans.size()==0){
        cout<<"Sin bloqueos"<<endl;
    }
    else{
        cout<<ans.size()<<endl;
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
        }
    }
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1, caseno = 1;
    cin>>t;
    while (t--){
        cout<<"Caso #"<<caseno++<<endl;
        solve();       
    }
    return 0;
}
