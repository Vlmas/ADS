#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void merge(vector<int>& v,int l,int m,int r) {
    int n1=m-l+1;
    int n2=r-m;

    vector<int> v1(n1);
    vector<int> v2(n2);

    for(int i=0;i<n1;i++) {
        v1[i]=v[l+i];
    }
    for(int i=0;i<n2;i++) {
        v2[i]=v[m+i+1];
    }

    int p1=0;
    int p2=0;
    int k=l;

    while(p1<n1 && p2<n2) {
        if(v1[p1]<=v2[p2]) {
            v[k++]=v1[p1++];
        } else {
            v[k++]=v2[p2++];
        }
    }

    while(p1<n1) {
        v[k++]=v1[p1++];
    }
    while(p2<n2) {
        v[k++]=v2[p2++];
    }
}

void mergeSort(vector<int>& v,int l,int r) {
    if(l<r) {
        int m=(l+r)/2;
        mergeSort(v,l,m);
        mergeSort(v,m+1,r);
        merge(v,l,m,r);
    }
}

int main() {
    int n;
    cin>>n;

    vector<int> v(n);

    for(int i=0;i<n;i++) {
        cin>>v[i];
    }

    mergeSort(v,0,v.size()-1);

    for(auto& i : v) {
        cout<<i<<" ";
    }


    return 0;
}