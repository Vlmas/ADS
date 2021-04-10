#include<iostream>
#include<vector>

#define ll long long

using namespace std;

const int N=31;

void initPows(vector<ll>& pws) {
    pws[0]=1;

    for(int i=1;i<pws.size();i++) {
        pws[i]=pws[i-1]*N;
    }
}

ll getHash(string s,vector<ll>& pws) {
    ll res=0;

    for(int i=0;i<s.size();i++) {
        res+=s[i]*pws[i];
    }

    return res;
}

vector<ll> getAllHashes(string s,vector<ll> pws) {
    vector<ll> res(s.size());
    res[0]=s[0];    

    for(int i=1;i<s.size();i++) {
        res[i]=res[i-1]+(s[i]*pws[i]);
    }

    return res;
}

int main() {
    string s,t;
    cin>>t>>s;

    vector<ll> pws(t.size());
    initPows(pws);
    vector<ll> all_hashes=getAllHashes(t,pws);

    ll str_hash=getHash(s,pws);
    ll cur_hash;

    for(int i=0;i<=t.size()-s.size();i++) {
        cur_hash=all_hashes[i+s.size()-1];

        if(i) {
            cur_hash-=all_hashes[i-1];
        }

        if(str_hash*pws[i]==cur_hash) {
            cout<<i<<" ";
        }
    } 


    return 0;
}