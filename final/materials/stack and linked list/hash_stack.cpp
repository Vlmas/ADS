#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data=data;
        next=NULL;
    }
};

class Stack {
    public:
    Node* top;
    int sz;

    Stack() {
        top=NULL;
        sz=0;
    }

    void push(int data) {
        Node* node=new Node(data);

        node->next=top;
        top=node;

        sz++;
    }

    void pop() {
        if(top!=NULL) {
            Node* tmp=top;
            top=top->next;

            delete tmp;

            sz--;
        } else {
            cout<<"Stack is empty\n";
            throw bad_alloc();
        }
    }

    int size() {
        return this->sz;
    }

    bool isEmpty() {
        return (!this->sz);
    }

    int getTop() {
        if(top!=NULL || sz!=0) {
            return this->top->data;
        }
    }
};

int main() {
    Stack* st=new Stack();

    st->push(5);
    st->push(3);
    cout<<st->getTop()<<"\n";
    st->pop();
    cout<<st->getTop()<<"\n";


    return 0;
}