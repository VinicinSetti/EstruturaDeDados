#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

template <typename T>
class LinkedListNode {
public:
    T data;
    LinkedListNode<T>* next;
    LinkedListNode<T>* prev;
    LinkedListNode(T data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

template <typename T>
class LinkedList {
private:
    LinkedListNode<T>* head;
    LinkedListNode<T>* tail;
    int size;

public:
    LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }
    ~LinkedList() {
        LinkedListNode<T>* entry = head;
        while (entry != nullptr) {
            LinkedListNode<T>* prev = entry;
            entry = entry->next;
            delete prev;
        }
    }

    void insert(T data) {
        LinkedListNode<T>* entry = new LinkedListNode<T>(data);
        if (head == nullptr) {
            head = entry;
            tail = entry;
        } else {
            tail->next = entry;
            entry->prev = tail;
            tail = entry;
        }
        size++;
    }

    void remove(T data) {
        LinkedListNode<T>* entry = head;
        while (entry != nullptr) {
            if (entry->data == data) {
                if (entry->prev == nullptr) {
                    head = entry->next;
                } else {
                    entry->prev->next = entry->next;
                }
                if (entry->next == nullptr) {
                    tail = entry->prev;
                } else {
                    entry->next->prev = entry->prev;
                }
                delete entry;
                size--;
                break;
            }
            entry = entry->next;
        }
    }

    T get(int index) {
        LinkedListNode<T>* entry = head;
        for (int i = 0; i < index; i++) {
            entry = entry->next;
        }
        return entry->data;
    }

    int getSize() {
        return size;
    }
};

#endif
