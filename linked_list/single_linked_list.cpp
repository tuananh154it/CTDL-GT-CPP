#include<iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
};

class LinkedList{
    private:
        Node* head;
    public:
        LinkedList(){
            head = nullptr;
        }
        // thêm một phần tử vào đầu list;
        void pushfront(int val){
            Node* newNode = new Node;
            newNode->value = val;
            newNode->next = head;
            head = newNode;
        }
        // thêm một phần tử vào cuối list
        void pushBack(int val){
            if(head == nullptr){
                pushfront(val);
                return;
            }
            // dịch về cuối
            Node* current = head;
            while(current->next != nullptr){
                current = current->next;
            }
            Node* newNode = new Node;
            newNode->value = val;
            newNode->next = nullptr;
            current->next = newNode;
        } 
        // chèn vào vị trí bất kỳ
        void insert(int idx, int val){
            // chèn vào đầu
            if(idx == 0){
                pushfront(val);
                return;
            }
            // tìm kiếm vị trí idx
            int count = 1; // bắt đầu đếm từ 1, vì đứng ở phhần tử đầu tiên
            Node* current = head;
            while(count != idx && current->next!=nullptr){
                count++;
                current = current->next;
            }
            // kiểm tra biến đếm
            if(count < idx){ // vị trí nằm ngoài phạm vi list
                cout<<"vi tri chen khong hop le !!!\n";
                return;
            } else if(count == idx && current->next == nullptr){// tìm thấy vị trí idx
                pushBack(val);
            } else{
                Node* newNode = new Node;
                newNode->value = val;
                newNode->next = current->next;
                current->next = newNode;
            }

        }
        void printList(){
            cout<<"danh sach: ";
            Node* current = head;
            while (current != nullptr)
            {
                cout<<current->value<<"   ";
                current = current->next;
            }
            cout<<endl;

        }
};

int main(){
    LinkedList list;
    list.pushfront(1);
    list.pushfront(2);
    list.pushfront(3);
    list.pushBack(4);
    list.insert(0, 10);
    list.insert(4, 99);

    list.printList();

    return 0;
}