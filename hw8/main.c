#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
        int data;
        Node* next_node;
        Node(int num){
            data = num;
            next_node = NULL;
        }
};

class LinkedList{
    private: 
        int size;
        Node* head = NULL;
    public:
        void show_list(Node* head){
            while(head){
                cout << "[" << head->data << "]-> ";
                head = head->next_node;
            }
            cout << "null" << endl;
        }
        Node* append_node(int new_data){
            Node* new_node = new Node(new_data);
            if(head){
                Node* p = head;
                while(p->next_node){
                    p = p->next_node;
                }
                p->next_node = new_node;
            }
            else head = new_node;
            show_list(head);
            return head;
        }
        Node* del_node(int n){
            Node* del_head = new Node(0);
            del_head -> next_node = head;
            int count = 0;
            Node* p = del_head;
            while(count != n) {
                p = p->next_node;
                count++;
            }
            Node* del_node = p->next_node;
            p->next_node = del_node->next_node;
            delete del_node;
            show_list(head);
            free_all_node(head);
            return del_head->next_node;
        }
        void free_all_node(Node* head){
            while(head){
                Node* p = head;
                head = head -> next_node;
                cout << "free[" << p->data << "]-> ";
                delete p;
            }
            cout << "null" << endl;
        }
};

int main(){
    LinkedList mylink;
    mylink.append_node(0);
    mylink.append_node(1);
    mylink.append_node(2);
    mylink.append_node(3);
    mylink.del_node(1);
    return 0;
}
