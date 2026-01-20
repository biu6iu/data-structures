#include <iostream>
#include <vector>
#include <list>

class HashTable {
public:
    HashTable(int initialSize) : tableSize(initialSize) {
        table.resize(initialSize);
    }

    // TODO: Implement a custom hash function that returns an index
    int customHash(const std::string& key) {
        // You can use a simple hash function for this exercise.
        // Example: Calculate the sum of ASCII values of characters in the key.
        int hashValue = 0;

        // TODO: Complete the hash function

        return hashValue % tableSize;
    }

    // TODO: Implement rehashing to resize the table and redistribute elements
    void rehash(int newSize) {
        // TODO: Resize the table to newSize and redistribute elements

    }

    void insert(const std::string& key, const std::string& value) {
        int index = customHash(key);
        table[index].push_back(std::make_pair(key, value));
    }

    // Display the contents of the hash table
    void display() {
        for (int i = 0; i < tableSize; ++i) {
            std::cout << "Bucket " << i << ": ";
            for (auto& pair : table[i]) {
                std::cout << "(" << pair.first << ", " << pair.second << ") ";
            }
            std::cout << std::endl;
        }
    }

private:
    int tableSize;
    std::vector<std::list<std::pair<std::string, std::string>>> table;
};

int main() {
    // Create a hash table with an initial size
    HashTable hashTable(5);

    // Insert key-value pairs
    hashTable.insert("apple", "red");
    hashTable.insert("banana", "yellow");
    hashTable.insert("cherry", "red");
    hashTable.insert("date", "brown");
    hashTable.insert("fig", "purple");

    // Display the initial contents of the hash table
    std::cout << "Initial Hash Table:\n";
    hashTable.display();

    // TODO: Perform rehashing to resize the table to a larger size
    // and redistribute the elements

    // Display the updated contents of the hash table after rehashing
    std::cout << "\nAfter Rehashing:\n";
    hashTable.display();

    return 0;
}
