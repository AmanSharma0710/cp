#include<bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){                //to sort vii by second element use sort(v.begin(), v.end(), sortbysec);
    return (a.second < b.second);
}
#define N 500005

struct node{
    int index;
    node* next;
    node(int x){
        index = x;
        next = NULL;
    }
};


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int q;
    cin>>q;
    vector<pair<node*, node*>> v(N, {NULL, NULL});
    int curr_idx=1;
    for(int i=0; i<q; i++){
        int type;
        cin>>type;
        if(type==1){
            int x;
            cin>>x;
            assert(x>=1 && x<N);
            node* temp = new node(curr_idx++);
            temp->next = v[x].first;
            if(v[x].first==NULL) v[x].second = temp;
            v[x].first = temp;
        }
        else{
            int from, to;
            cin>>from>>to;
            assert(from>=1 && from<N && to>=1 && to<N);
            if(from==to){
                continue;
            }
            if(v[from].first==NULL) continue;
            v[from].second->next = v[to].first;
            v[to].first = v[from].first;
            if(v[to].second==NULL) v[to].second = v[from].second;
            v[from].first = NULL;
            v[from].second = NULL;
        }
    }
    vector<pair<int, int>> v2;
    for(int i=1; i<N; i++){
        while(v[i].first!=NULL){
            v2.push_back({i, v[i].first->index});
            v[i].first = v[i].first->next;
        }
        assert(v[i].first==NULL);
    }
    sort(v2.begin(), v2.end(), sortbysec);
    for(int i=0; i<v2.size(); i++){
        cout<<v2[i].first<<" ";
    }
    cout<<endl;
    return 0;
}
