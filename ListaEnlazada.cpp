#include <iostream>
#include <cassert>

template<typename ITEM>
class MyDoublyLinkedList {
    struct Node {
        ITEM item;
        Node* next;
        Node* prev;

        Node(const ITEM& a): item(a), next(nullptr), prev(nullptr) {}
    } *head, *tail;

public:
    MyDoublyLinkedList(): head(nullptr), tail(nullptr) {}

    void append(const ITEM& item) {
        Node* newNode = new Node(item);
        if (!tail) {
            head = tail = newNode; 
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void printForward() const {
        Node* current = head;
        while (current) {
            std::cout << current->item << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void printBackward() const {
        Node* current = tail;
        while (current) {
            std::cout << current->item << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }

    ~MyDoublyLinkedList() {
        while (head) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        }
    }
};

int main() {
    MyDoublyLinkedList<int> list;

    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);

    std::cout << "Lista desde el principio: ";
    list.printForward();

    std::cout << "Lista desde el final: ";
    list.printBackward();

    return 0;
}
