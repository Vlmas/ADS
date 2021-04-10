#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool need_output=false;

class MaxHeap {
    public:
    vector<int> a;

    int parent(int i) {
        return (i-1)/2;
    }

    int left(int i) {
        return (2*i+1);
    }

    int right(int i) {
        return (2*i+2);
    }

    int getMax() {
        return a[0];
    }

    void siftUp(int i) {
        while(i && a[parent(i)]<a[i]) {
            swap(a[i],a[parent(i)]);    
            i=parent(i);
        }
    }

    void siftUp(int i) {
        if(i>a.size()) {
            return;
        }

        if(i && a[parent(i)]<a[i]) {
            swap(a[i],a[parent(i)]);
            siftUp(parent(i));
        } else {
            if(need_output) {
                cout<<i+1<<"\n";
            }
        }
    }
 
    void siftDown(int i) {
        if(a.size()-1<left(i)) {
            return;
        }

        int j=left(i);

        if(right(i)<a.size() && a[right(i)]>a[left(i)]) {
            j=right(i);
        }

        if(a[i]<a[j]) {
            swap(a[i],a[j]);
            siftDown(j);
        }
    }

    void siftDown(int i) {
        int j=i;

        if(left(i)<a.size() && a[left(i)]>a[i]) {
            j=left(i);
        }
        if(right(i)<a.size() && a[right(i)]>a[j]) {
            j=right(i);
        }

        if(j!=i) {
            swap(a[i],a[j]);
            siftDown(j);
        } else {
            if(need_output) {
                cout<<i+1<<"\n";
            }
        }
    }

    void insert(int k) {
        a.push_back(k);
        int i=a.size()-1;
        siftUp(i);
    }

    void printHeap() {
        for(auto& i : a) {
            cout<<i<<" ";
        }
    }

    int extractMax() {
        int mxx=a[0];
        swap(a[0],a[a.size()-1]);
        a.pop_back();

        if(a.size()>0) {
            siftDown(0);
        }

        return mxx;
    }

    int deleteAt(int i) {
        if(i>=a.size() || i<0) {
            return;
        }

        int e=a[i];

        if(a.size()==1) {
            a.pop_back();
            return e;
        }

        swap(a[i],a[a.size()-1]);
        a.pop_back();

        siftUp(i);
        siftDown(i);

        return e;
    }

    void increaseKey(int i,int x) {
        if(i>=a.size() || i<0) {
            return;
        }

        a[i]+=x;
        siftUp(i);
    }

    void decreaseKey(int i,int x) {
        if(i>=a.size() || i<0) {
            return;
        }

        a[i]-=x;
        siftDown(i);
    }
};

int main() {
    MaxHeap* h=new MaxHeap();


    return 0;
}