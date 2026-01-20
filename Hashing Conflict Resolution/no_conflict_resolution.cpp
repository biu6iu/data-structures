#include <iostream>
#include <vector>

const int TABLE_SIZE = 151;

class NaiveHashMap {
private:
    struct HashEntry {
        int key;
        std::string value;
        bool isOccupied = false;
    };

    std::vector<HashEntry> table;

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    NaiveHashMap() : table(TABLE_SIZE) {}

    void insert(int key, const std::string& value) {
        int index = hashFunction(key);
        // write your own insert function
        if (table[index].isOccupied) {
            return;
        }
        table[index].key = key;
        table[index].value = value;
        table[index].isOccupied = true;
    }

    bool find(int key, std::string& value) {
        int index = hashFunction(key);
        if (table[index].isOccupied && table[index].key == key) {
            value = table[index].value;
            return true;
        }
        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);
        if (table[index].isOccupied && table[index].key == key) {
            table[index].isOccupied = false;
        }
    }
};

int main() {
    NaiveHashMap map;

    map.insert(1, "John Doe");
    map.insert(2, "Jane Smith");
    map.insert(3, "James Brown");

    // Overwrite data at key 1 (demonstrates lack of conflict resolution)
    map.insert(1 + TABLE_SIZE, "Overwrite John");

    std::string value;
    if (map.find(1, value)) {
        std::cout << "Value associated with key 1: " << value << std::endl;  // This will print "Overwrite John"
    } else {
        std::cout << "Key 1 not found." << std::endl;
    }

    return 0;
}
