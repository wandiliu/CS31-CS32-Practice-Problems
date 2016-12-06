#include <iostream>
#include <cassert>
using namespace std;

class SLL{
 public:
    SLL() {head = nullptr;}
    bool insert(int new_num) {
        Node* ptr = head;
        if (ptr == nullptr) {  // edge case: if the set was empty
            Node* new_node = new Node(new_num);
            head = new_node;
            return true;
        }
        while (ptr->m_next && ptr->m_next->get_num() < new_num) {
            // while the number isn't the largest
            // and the next number is smaller than the new one
            ptr = ptr->m_next;  // go to the next number
        }
        if (!ptr->m_next) {
            // if we're at the end of the set --
            // (biggest number, but still smaller than the new one),
            // insert the new number at the end
            Node* new_node = new Node(new_num);
            ptr->m_next = new_node;
            return true;
        } else if (ptr->m_next->get_num() == new_num) {
            // if the new number is the same as the next number in the set, don't insert it
            return false;
        }  // else, insert the new node before the next number!
            Node* new_node = new Node(new_num);
            Node* tmp = ptr->m_next;
            ptr->m_next = new_node;
            new_node->m_next = tmp;
            return true;
    }
    
 private:
    struct Node{
     public:
        explicit Node(int n) : m_num(n) {  // node is initalized to point to NULL
            m_next = nullptr;
        }
        int get_num() {return m_num;}
        Node* m_next;
     private:
        int m_num;
    };
    Node* head;
};

int main() {
    SLL c;
    assert(c.insert(3)==1);  // inserts & returns true
    assert(c.insert(5)==1);  // inserts & returns true
    assert(c.insert(8)==1);  // inserts & returns true
    assert(c.insert(4)==1);  // inserts & returns true
    assert(c.insert(5)==0);  // already in set, returns false!
    cout << "All tests passed" << endl;
}



