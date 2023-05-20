#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <string>
#include <iostream>

template <typename K, typename V>
class HashTableNode {
    public:
        K key;
        V value;
        HashTableNode<K, V> *next;
        HashTableNode<K, V> *prev;
        HashTableNode(K key, V value) {
            this->key = key;
            this->value = value;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

template <typename K, typename V>
class HashTable {
    private:
        const int TABLE_SIZE = 10;
        HashTableNode<K, V> **table;
    public:
        HashTable() {
            table = new HashTableNode<K, V>*[TABLE_SIZE];
            for (int i = 0; i < TABLE_SIZE; i++) {
                table[i] = nullptr;
            }
        }
        ~HashTable() {
            for (int i = 0; i < TABLE_SIZE; i++) {
                HashTableNode<K, V> *entry = table[i];
                while (entry != nullptr) {
                    HashTableNode<K, V> *prev = entry;
                    entry = entry->next;
                    delete prev;
                }
            }
            delete[] table;
        }

        int getSize() {
            return TABLE_SIZE;
        }

        int hash(K key) {
            return key % TABLE_SIZE;
        }

        void insert(K key, V value) {
            int hashValue = hash(key);
            HashTableNode<K, V> *prev = nullptr;
            HashTableNode<K, V> *entry = table[hashValue];
            while (entry != nullptr) {
                prev = entry;
                entry = entry->next;
            }
            if (entry == nullptr) {
                entry = new HashTableNode<K, V>(key, value);
                if (prev == nullptr) {
                    table[hashValue] = entry;
                } else {
                    prev->next = entry;
                }
            } else {
                entry->value = value;
            }
        }

        V* get(K key) {
            int hashValue = hash(key);
            HashTableNode<K, V>* entry = table[hashValue];
            while (entry != nullptr) {
                if (entry->key == key) {
                    return &(entry->value);
                }
                entry = entry->next;
            }
            std::cout << "No value found for key: " << key << std::endl;
            return nullptr;
        }

        void remove(K key) {
            int hashValue = hash(key);
            HashTableNode<K, V> *prev = nullptr;
            HashTableNode<K, V> *entry = table[hashValue];
            while (entry != nullptr && entry->key != key) {
                prev = entry;
                entry = entry->next;
            }
            if (entry == nullptr) {
                return;
            } else {
                if (prev == nullptr) {
                    table[hashValue] = entry->next;
                } else {
                    prev->next = entry->next;
                }
                delete entry;
            }
        }
};

#endif