#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    bool valid;
    unsigned long long int matches;
    int children[2];
    Node(){
        valid = false;
        children[0] = -1;
        children[1] = -1;
        matches = 0;
    }
};

class Trie{
    public:
    vector<Node> trie;
    Trie(){
        trie.clear();
        //push root into it
        Node root;
        trie.push_back(root);
    }
    void insert(string s){
        int idx = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='*'){
                trie[idx].valid = true;
                break;
            }
            if(trie[idx].children[s[i]-'0'] == -1){
                trie[idx].children[s[i]-'0'] = trie.size();
                Node temp;
                trie.push_back(temp);
            }
            idx = trie[idx].children[s[i]-'0'];
        }
    }

    void process(int idx, unsigned long long m){
        if(m==0){
            trie[idx].matches = 1;
            return;
        }
        for(auto child: {0, 1}){
            if(trie[idx].children[child]==-1) trie[idx].matches += 1ll<<(m-1);
            else{
                process(trie[idx].children[child], m-1);
                if(trie[trie[idx].children[child]].valid == false){
                    trie[idx].matches += trie[trie[idx].children[child]].matches;
                }
            }
        }
    }

    void print(string s){
        int idx = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='*'){
                cout<<trie[idx].matches<<endl;
                return;
            }
            if(trie[idx].children[s[i]-'0'] == -1){
                trie[idx].children[s[i]-'0'] = trie.size();
                Node temp;
                trie.push_back(temp);
            }
            idx = trie[idx].children[s[i]-'0'];
        }
    }
};

int main(){
    int n, m;
    cin>>n>>m;
    while(!(n==0 && m==0)){
        Trie t;
        string s;
        t.insert("*");
        for(int i=0; i<n; i++){
            cin>>s;
            t.insert(s);
        }
        t.process(0, m);
        int q;
        cin>>q;
        for(int i=0; i<q; i++){
            cin>>s;
            t.print(s);
        }
        cout<<endl;
        cin>>n>>m;
    }
}