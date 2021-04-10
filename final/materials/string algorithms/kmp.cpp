#include<iostream>
#include<vector>

using namespace std;

vector<int> prefixFunction(string s) {
    vector<int> res(s.size());
    res[0]=0;

    for(int i=1;i<s.size();i++) {
        int j=res[i-1];

        while(j && s[i]!=s[j]) {
            j=res[j-1];
        }

        if(s[i]==s[j]) {
            j++;
        }
        res[i]=j;
    }

    return res;
}

int main() {
    string s,t;
    cin>>t>>s;

    t=s+'#'+t;

    vector<int> v=prefixFunction(t);

    for(int i=0;i<v.size();i++) {
        if(v[i]==s.size()) {
            cout<<i-2*s.size()<<" ";
        }
    }


    return 0;
}