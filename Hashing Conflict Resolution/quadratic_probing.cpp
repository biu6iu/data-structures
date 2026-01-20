#include <iostream>
#include <vector>

const int TABLE_SIZE = 151;  // Increased size to a prime number to accommodate 50 entries and reduce collisions

class HashMap {
private:
    struct HashEntry {
        int key;
        std::string value;
        bool isOccupied = false;  // To check if a slot is occupied
    };

    std::vector<HashEntry> table;

    int hashFunction(int key) {
        return key % 10;
    }

public:
    HashMap() : table(TABLE_SIZE) {}  // Resize the table to the defined size

    void insert(int key, const std::string& value) {
        int index = hashFunction(key);
        int counter = 1;  // Used for quadratic probing

        // Quadratic probing for collision resolution
        while (table[index].isOccupied) {
            if (counter >= TABLE_SIZE) {
                return;
            }
            index = (index + counter * counter) % TABLE_SIZE;
            counter++;
        }
        table[index].key = key;
        table[index].value = value;
        table[index].isOccupied = true;
    }

    bool find(int key, std::string& value) {
        int index = hashFunction(key);
        int counter = 1;  // Used for quadratic probing

        // write your own find function
        while (table[index].isOccupied) {
            if (table[index].key == key) {
                value = table[index].value;
                return true;
            }
            if (counter >= TABLE_SIZE) {
                return false;
            }
            index = (index + counter * counter) % TABLE_SIZE;
            counter++;
        }
        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);
        int counter = 1;  // Used for quadratic probing

        // write your own remove function
        while (table[index].isOccupied) {
            if (table[index].key == key) {
                table[index].isOccupied = false;
                return;
            }

            if (counter >= TABLE_SIZE) {
                break;
            }
            index = (index + counter * counter) % TABLE_SIZE;
            counter++;
        }
        return;
    }
};

int main() {
    HashMap map;

    // Insert 50 entries
    map.insert(1, "John Doe");
    map.insert(2, "Jane Smith");
    map.insert(3, "James Brown");
    // Generating some names for demonstration purposes
    for (int i = 4; i <= 50; ++i) {
        map.insert(i, "Person " + std::to_string(i));
    }

    // Example of finding a value associated with a key
    std::string value;
    if (map.find(25, value)) {
        std::cout << "Value associated with key 25: " << value << std::endl;
    } else {
        std::cout << "Key 25 not found." << std::endl;
    }

    return 0;
}
