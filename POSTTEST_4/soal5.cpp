#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void exchangeHeadAndTail(Node*& head_ref) {
    // Hanya berjalan jika ada 2 node atau lebih
    if (head_ref == nullptr || head_ref->next == head_ref) {
        return;
    }

    Node* head = head_ref;
    Node* tail = head_ref->prev; // Tail adalah prev dari head

    // Buat kondisi jika hanya 2 node, cukup swap head_ref
    if (head->next == tail && tail->prev == head) {
        head_ref = tail; // Swap
        return;
    }

    // Simpan neighbor ( yaitu head_next dan tail_prev)
    Node* head_next = head->next;
    Node* tail_prev = tail->prev;

    // Update koneksi: tail_prev <-> tail <-> head_next
    tail_prev->next = head;
    head_next->prev = tail;

    // Update koneksi: head_next <- ... -> tail_prev <-> head <-> tail_prev
    head->prev = tail_prev;
    head->next = tail;

    tail->prev = head;
    tail->next = head_next;

    // terakhir Update head_ref
    head_ref = tail;
}

void printList(Node* head_ref) {
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    Node* current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

void insertEnd(Node*& head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};

    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node* tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main() {
    Node* head = nullptr;

    // Buat list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head);

    exchangeHeadAndTail(head);

    cout << "List setelah exchange head dan tail: ";
    printList(head); // Output: 5 2 3 4 1

    return 0;
}