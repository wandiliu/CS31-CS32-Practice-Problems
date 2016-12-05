
## CS32
### Linked Set 
*Contributed by Wandi Liu*

Given the following skeleton of a singly-linked-list class, implement a function *insert()* that:
- take in a new *int*
- check if it's already in the set (is a duplicate), if so, return _false_.
- insert the new _int_ into the set, sorted in ascending order, from smallest to largest. 
- return _true_ if the _int_ was inserted

```cpp
#include <iostream>
using namespace std;

class SLL{
 public:
    SLL() {head = nullptr;}
    bool insert(int new_num) {
        Node* ptr = head;
        // YOUR CODE HERE
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

```

#### Example 

```cpp
int main() {
  SLL c;
  c.insert(3);  // inserts & returns true
  c.insert(5);  // inserts & returns true
  c.insert(8);  // inserts & returns true
  c.insert(4);  // inserts & returns true
  c.insert(5);  // already in set, returns false!
}
```
####### c should now contain: {3,4,5,8}

#### Solution 

```cpp
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

```

