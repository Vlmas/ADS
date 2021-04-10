#include<iostream>

using namespace std;

const int MAXN=1000;

int p[MAXN];

void initPrimes(int x) {
    for(int i=2;i*i<=x;i++) {
        if(!p[i]) {
            int k=i;

            while(k+i<=x) {
                k+=i;
                p[k]=1;
            }
        }
    }
}

int main() {
    int x;
    cin>>x;

    initPrimes(x);

    for(int i=2;i<=x;i++) {
        if(!p[i]) {
            cout<<i<<" ";
        }
    }


    return 0;
}