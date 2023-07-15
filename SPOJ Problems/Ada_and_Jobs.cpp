#include<bits/stdc++.h>
using namespace std;


int toidx(char c){
    if(c>='a' && c<='z'){
        return c-'a';
    }
    if(c>='A' && c<='Z'){
        return c-'A' + 26;
    }
    assert(c>='0' && c<='9');
    return c-'0' + 52;
}


class Automaton{
    class Vertex{
        public:
        vector<int> next;
        int pidx = -1;
        int pchar = -1;
        int suffix = -1;
        int output = INT_MAX;
        Vertex(){
            next.assign(62, -1);
        }
    };
    public:
    vector<Vertex> tree;
    Automaton(){
        tree.emplace_back();
    }
    void insert(string &s, int num){
        int idx = 0;
        for(char _c:s){
            int c = toidx(_c);
            if(tree[idx].next[c]==-1){
                tree[idx].next[c] = tree.size();
                tree.emplace_back();
                tree.back().pidx = idx;
                tree.back().pchar = c;
            }
            idx = tree[idx].next[c];
        }
        tree[idx].output = min(tree[idx].output, num);
    }

    void compute(){
        tree[0].suffix = 0;
        queue<int> q;
        for(int i=0; i<62; i++){
            if(tree[0].next[i]!=-1){
                q.push(tree[0].next[i]);
                tree[tree[0].next[i]].suffix = 0;
            }
            else{
                tree[0].next[i] = 0;
            }
        }
        while(!q.empty()){
            int v = q.front();
            q.pop();
            int u = tree[v].suffix;
            for(int c=0; c<62; c++){
                int child = tree[v].next[c];
                if(child!=-1){
                    q.push(child);
                    tree[child].suffix = tree[u].next[c];
                    tree[child].output = min(tree[child].output, tree[tree[child].suffix].output);
                }
                else{
                    tree[v].next[c] = tree[u].next[c];
                }
            }
        }
    }
};


int main(){
    int q;
    cin>>q;
    Automaton aut;
    vector<pair<int, string>> queries;
    for(int i=0; i<q; i++){
        int t;
        string s;
        cin>>t>>s;
        if(t==0){
            aut.insert(s, i);
        }
        else{
            queries.emplace_back(i, s);
        }
    }
    aut.compute();
    for(auto &p:queries){
        int idx = 0;
        int ans = INT_MAX;
        for(char c:p.second){
            idx = aut.tree[idx].next[toidx(c)];
            ans = min(ans, aut.tree[idx].output);
        }
        if(ans<p.first){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}