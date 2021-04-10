#include<iostream>

using namespace std;

struct Node {
    Node* next;
    Node* prev;
    int data;

    Node(int data) {
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};

class LinkedList {
    public:
    Node* front;
    Node* tail;
    int sz;

    LinkedList() {
        front=NULL;
        tail=NULL;
        sz=0;
    }

    void pushFront(int data) {
        Node* node=new Node(data);

        if(this->front==NULL) {
            front=node;
            tail=node;
        } else {
            front->prev=node;
            node->next=front;
            front=node;
        }
        sz++;
    }

    void pushBack(int data) {
        Node* node=new Node(data);

        if(this->tail==NULL) {
            tail=node;
            front=node;
        } else {
            node->prev=tail;
            tail->next=node;
            tail=node;
        }
        sz++;
    }

    void insertNode(Node* node,int data) {
        if(node==tail) {
            pushBack(data);
        } else {
            Node* next_node=node->next;
            Node* new_node=new Node(data);
            node->next=new_node;
            new_node->prev=node;
            new_node->next=next_node;
            next_node->prev=new_node;
        }
    }

    void popFront() {
        if(front!=NULL) {
            Node* to_del=front;
            front=front->next;

            if(front!=NULL) {
                front->prev=NULL;
            } else {
                tail=NULL;
            }

            delete to_del;
            sz--;
        }
    }

    void popBack() {
        if(tail!=NULL) {
            Node* to_del=tail;
            tail=tail->prev;

            if(tail!=NULL) {
                tail->next=NULL;
            } else {
                front=NULL;
            }

            delete to_del;
            sz--;
        }
    }

    void deleteNode(Node* node) {
        if(node==tail) {
            popBack();
        }
        else if(node==front) {
            popFront();
        } else {
            Node* tmp=node;
            Node* a=node->prev;
            Node* b=node->next;
            a->next=b;
            b->prev=a;

            delete tmp;
        }
    }

    int getTail() {
        return tail->data;
    }

    int getFront() {
        return front->data;
    }

    bool isEmpty() {
        return !sz;
    }

    int getSize() {
        return sz;
    }
};

int main() {
    LinkedList* lili=new LinkedList();
    
    lili->pushBack(5);
    lili->pushFront(10);
    cout<<lili->getFront()<<" "<<lili->getTail()<<"\n";
    lili->popFront();
    cout<<lili->getFront()<<" "<<lili->getTail()<<"\n";
    lili->popBack();
    cout<<lili->getFront()<<" "<<lili->getTail()<<"\n";


    return 0;
}