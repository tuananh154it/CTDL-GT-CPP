#include<iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

void listInit(Node* &ptr_head){
    ptr_head = new Node;
    ptr_head = nullptr;
    cout<<"danh sach duoc khoi tao !!!"<<endl;
}
bool isEmpty(Node* ptr_head){
    if(ptr_head->next == nullptr){
        return true;
    }
    return false;
}

void printList(Node* ptr_head){
    Node* temp = ptr_head;
    while(temp->next!=nullptr){
        temp->next;
        cout<<temp->val<<" ";
    }
}

int main(){

    Node *head;
    listInit(head);
    

    return 0;
}