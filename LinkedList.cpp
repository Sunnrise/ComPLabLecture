#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    void append(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    int getSize() {
        return size;
    }

    int recursiveSum(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        else {
            return node->data + recursiveSum(node->next);
        }
    }

    Node* getHead() const {
        return head;
    }

    ~LinkedList() {
        Node* current = head;
        Node* next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList linkedList;

    int size;
    cout << "Enter size: ";
    cin >> size;

    for (int i = 0; i < size; ++i) {
        int data;
        cout << "Enter element #" << i + 1 << ": ";
        cin >> data;
        linkedList.append(data);
    }

    int totalSum = linkedList.recursiveSum(linkedList.getHead());
    cout << "The sum of the elements: " << totalSum << endl;

    return 0;
}
