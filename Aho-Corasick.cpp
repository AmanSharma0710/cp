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
        bitset<1000> output;
        Vertex(){
            next.assign(62, -1);
            output.reset();
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
        tree[idx].output.set(num);
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
                    tree[child].output |= tree[tree[child].suffix].output;
                }
                else{
                    tree[v].next[c] = tree[u].next[c];
                }
            }
        }
    }
};


int main(){
    string m;
    cin>>m;
    int n;
    cin>>n;
    vector<string>v(n);
    Automaton aut;
    for(int i=0; i<n; i++){
        cin>>v[i];
        aut.insert(v[i], i);
    }
    aut.compute();
    bitset<1000> ans;
    int idx = 0;
    for(char c:m){
        idx = aut.tree[idx].next[toidx(c)];
        ans |= aut.tree[idx].output;
    }
    for(int i=0; i<n; i++){
        if(ans[i]){
            cout<<"Y"<<endl;
        }
        else{
            cout<<"N"<<endl;
        }
    }
    return 0;
}