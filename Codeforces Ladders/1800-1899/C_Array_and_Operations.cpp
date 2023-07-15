#include<bits/stdc++.h>
using namespace std;
#define int long long int

int n, m; 
vector<bool>isPrime;
vector<int>primes;
vector<vector<int>>pairs;
vector<pair<int, int>>vertices; //(node, prime)
vector<vector<int>>g;
vector<int>mt;
vector<bool>used;
bool try_kuhn(int v) {
    if (used[v])
        return false;
    used[v] = true;
    for (int to : g[v]) {
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    isPrime.assign(100001, true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i*i<=100000; i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j=i*i; j<=100000; j+=i){
                isPrime[j] = false;
            }
        }
    }
    isPrime.swap(vector<bool>());
    cin>>n>>m;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<m; i++){
        int u, v; cin>>u>>v;
        u--;
        v--;
        pairs.push_back({u, v});
    }
    for(int i=0; i<n; i++){
        int node = i;
        int j=0;
        while(j<primes.size() && primes[j]<arr[node]){
            if(arr[node]%primes[j]==0){
                vertices.push_back({node, primes[j]});
                arr[node] /= primes[j];
            }
            else{
                j++;
            }
        }
    }
    arr.swap(vector<int>());
    g.assign(vertices.size(), vector<int>());
    for(int i=0; i<m; i++){
        int u = pairs[i][0];
        int v = pairs[i][1];
        int x = lower_bound(vertices.begin(), vertices.end(), make_pair(u, 0LL)) - vertices.begin();
        int y = lower_bound(vertices.begin(), vertices.end(), make_pair(v, 0LL)) - vertices.begin();
        for(int j=x; j<vertices.size(); j++){
            if(vertices[j].first!=u){
                break;
            }
            for(int k=y; k<vertices.size(); k++){
                if(vertices[k].first!=v){
                    break;
                }
                if(vertices[j].second==vertices[k].second){
                    g[j].push_back(k);
                    g[k].push_back(j);
                }
            }
        }
    }
    n = vertices.size();

    return 0;
}
