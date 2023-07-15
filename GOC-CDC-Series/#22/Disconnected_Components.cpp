#include<bits/stdc++.h>
using namespace std;
#define int long long int

class DSU{
    public:
    int n;
    vector<int> parent, rank;
    DSU(int n): n(n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    ~DSU(){
        parent.clear();
        rank.clear();
    }
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }
    void merge(int x, int y){
        int s1 = find(x);
        int s2 = find(y);
        if(s1!=s2){
            if(rank[s1]<rank[s2]){
                parent[s1] = s2;
            }
            else if(rank[s1]>rank[s2]){
                parent[s2] = s1;
            }
            else{
                parent[s1] = s2;
                rank[s2]++;
            }
        }
    }
};


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin>>n>>m;
    DSU dsu(n);
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        x--, y--;
        dsu.merge(x, y);
    }
    int k;
    cin>>k;
    vector<int>a(k);
    for(auto &i:a){
        cin>>i;
        i--;
    }
    sort(a.begin(), a.end());
    vector<pair<int, int>>cnt(n, {0, 0});
    for(int i=0; i<n; i++){
        cnt[dsu.find(i)].first++;
        if(binary_search(a.begin(), a.end(), i)){
            cnt[dsu.find(i)].second=1;
        }
    }
    int ans = 0, largest = 0;
    vector<int>ans2;
    for(int i=0; i<n; i++){
        if(cnt[i].second){
            ans2.push_back(cnt[i].first);
        }
        else{
            largest += cnt[i].first;
        }
    }
    sort(ans2.begin(), ans2.end());
    ans2.back() += largest;
    for(auto i:ans2){
        ans += (i*(i-1))/2;
    }
    cout<<ans-m<<endl;
    return 0;
}
