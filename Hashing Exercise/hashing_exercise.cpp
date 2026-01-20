#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <string>

// Define the HashNode
struct HashNode {
    std::string key;
    std::string value;
    HashNode* next;

    HashNode(std::string key, std::string value) : key(key), value(value), next(nullptr) {}
};

// Define the HashTable
class HashTable {
private:
    std::vector<HashNode*> table;
    int capacity;
    int size;

    // Hash function to compute index
    int hashFunction(const std::string& key) {
        int hash = 0;
        for (char c : key) {
            hash = hash * 31 + c;
        }
        return hash % capacity;
    }

public:
    // Constructor
    HashTable(int size) : capacity(size), size(0) {
        table.resize(capacity, nullptr);
    }

    // Destructor
    ~HashTable() {
        for (int i = 0; i < capacity; i++) {
            HashNode* entry = table[i];
            while (entry != nullptr) {
                HashNode* prev = entry;
                entry = entry->next;
                delete prev;
            }
            table[i] = nullptr;
        }
        table.clear();
    }

    // Insert method
    void insert(const std::string& key, const std::string& value) {
        int bucketIndex = hashFunction(key);
        HashNode* newNode = new HashNode(key, value);
        HashNode* head = table[bucketIndex];

        while (head != nullptr) {
            if (head->key == key) {
                head->value = value;
                return;
            }
            head = head->next;
        }

        size++;
        head = table[bucketIndex];
        newNode->next = head;
        table[bucketIndex] = newNode;
    }

    // Find method
    std::string find(const std::string& key) {
        int bucketIndex = hashFunction(key);
        HashNode* head = table[bucketIndex];

        while (head != nullptr) {
            if (head->key == key) {
                return head->value;
            }
            head = head->next;
        }
        return "Not Found";
    }

    // Delete method
    bool remove(const std::string& key) {
        int bucketIndex = hashFunction(key);
        HashNode* head = table[bucketIndex];
        HashNode* prev = nullptr;

        while (head != nullptr) {
            if (head->key == key) {
                if (prev == nullptr) {
                    table[bucketIndex] = head->next;
                } else {
                    prev->next = head->next;
                }
                delete head;
                size--;
                return true;
            }
            prev = head;
            head = head->next;
        }
        return false;
    }
};

// Main function to test HashTable
int main() {
    HashTable ht(10);
    std::string filepath = "path_to_your_csv_file.csv"; // Change to your CSV file path
    std::ifstream file(filepath);
    std::string line, name, breakfast;

    // Read from the file and insert into hash table
    if (file.is_open()) {
        getline(file, line); // Skip header
        while (getline(file, line)) {
            std::stringstream ss(line);
            getline(ss, name, ',');
            getline(ss, breakfast);
            ht.insert(name, breakfast);
        }
        file.close();
    }

    // Demo find
    std::string searchKey = "Ma Tianyu";
    std::cout << "Breakfast for " << searchKey << ": " << ht.find(searchKey) << std::endl;

    // Demo delete
    ht.remove(searchKey);
    std::cout << "After deletion, breakfast for " << searchKey << ": " << ht.find(searchKey) << std::endl;

    return 0;
}
