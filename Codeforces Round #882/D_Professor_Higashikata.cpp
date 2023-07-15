#include<bits/stdc++.h>
using namespace std;
#define int long long int

vector<int> tree;
 
int sum(int index, int start_index, int end_index, int query_start, int query_end){
    if(start_index>=query_start && query_end>=end_index){
        return tree[index];
    }
    if(start_index>query_end || query_start>end_index){
        return 0;
    }
    return sum(index*2, start_index, (start_index+end_index)/2, query_start, query_end) + sum(index*2 + 1, (start_index+end_index)/2 + 1, end_index, query_start, query_end);
}
 
void update(int index, int start_index, int end_index, int query_start, int query_end, int val){
    if(start_index>=query_start && query_end>=end_index){
        tree[index] = val;
        return;
    }
    if(start_index>query_end || query_start>end_index){
        return;
    }
    update(index*2, start_index, (start_index+end_index)/2, query_start, query_end, val);
    update(index*2 + 1, (start_index+end_index)/2 + 1, end_index, query_start, query_end, val);
    tree[index] = tree[index*2] + tree[index*2 + 1];
    return; 
}


void solve(){
    int n, m, q;
    cin>>n>>m>>q;
    string s;
    cin>>s;
    int ones = count(s.begin(), s.end(), '1');
    vector<int> mapping(n+1, -1);
    vector<int> store;
    int count=0;
    set<int> st;
    for(int i=1; i<=n; i++){
        st.insert(i);
    }
    for(int i=0; i<m; i++){
        int l, r;
        cin>>l>>r;
        auto it = st.lower_bound(l);
        while(it!=st.end() && *it<=r){
            mapping[*it]=count++;
            store.push_back((s[*it-1]-'0')^1);
            it++;
        }
        st.erase(st.lower_bound(l), st.lower_bound(r+1));
    }
    
    int N = store.size();
    while(N&(N-1)) store.push_back(0), N++;
    tree.assign(2*N, 0);
    for(int i=0; i<N; i++){
        tree[N+i] = store[i];
    }
    for(int i=N-1; i>0; i--){
        tree[i] = tree[i*2] + tree[i*2 + 1];
    }

    for(int i=0; i<q; i++){
        int x;
        cin>>x;
        if(s[x-1]=='1'){    //changing from 1 to 0
            ones--;
            if(mapping[x]!=-1){
                update(1, 0, N-1, mapping[x], mapping[x], 1);
            }
        }
        else{
            ones++;
            if(mapping[x]!=-1){
                update(1, 0, N-1, mapping[x], mapping[x], 0);
            }
        }
        s[x-1] = (s[x-1]-'0')^1 + '0';
        if(ones==0){
            cout<<"0\n";
            continue;
        }
        cout<<sum(1, 0, N-1, 0, min(N-1, ones-1))<<"\n";
    }
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1;
    // cin>>t;
    while (t--){
        solve();       
    }
    return 0;
}
