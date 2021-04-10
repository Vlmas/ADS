#include<iostream>

using namespace std;

const int N=26;

struct Node {
    char val;
    Node* ch[N];
    int cnt;

    Node(char val) {
        this->val=val;
        cnt=1;

        for(int i=0;i<N;i++) {
            ch[i]=NULL;
        }
    }
};

class Trie {
    public:
    Node* root;

    Trie() {
        root=new Node(' ');
    }

    void insert(string s) {
        Node* cur=root;

        for(int i=0;i<s.size();i++) {
            if(cur->ch[s[i]-'a']!=NULL) {
                cur=cur->ch[s[i]-'a'];
                cur->cnt++;
            } else {
                Node* node=new Node(s[i]);
                cur->ch[s[i]-'a']=node;
                cur=node;
            }
        }
    }

    void search(Node* node,string s) {
        if(s!="") {
            cout<<s<<": "<<node->cnt<<"\n";
        }

        for(int i=0;i<N;i++) {
            if(node->ch[i]!=NULL) {
                search(node->ch[i],s+node->ch[i]->val);
            }
        }
    }
};

int main() {
    Trie* tr=new Trie();


    return 0;
}