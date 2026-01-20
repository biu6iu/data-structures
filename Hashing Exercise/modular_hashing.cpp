#include <iostream>
#include <string>
#include <list>

const int TABLE_SIZE = 101;      // Use a prime number to reduce collisions
const int PRIME = 31;            // Commonly used prime for polynomial hashing

class HashMap {
private:
    struct HashEntry {
        std::string key;
        std::string value;
    };

    std::list<HashEntry> table[TABLE_SIZE];

    int hashFunction(const std::string& key) {
        // write your own hash function
        
    }

public:
    void insert(const std::string& key, const std::string& value) {
        // write your own insert function
    }

    bool find(const std::string& key, std::string& value) {
        // write your own find function
    }

    void remove(const std::string& key) {
        int index = hashFunction(key);
        table[index].remove_if([&key](const HashEntry& entry) { return entry.key == key; });
    }
};

int main() {
    HashMap map;

    // Using initializer list
    std::initializer_list<std::pair<std::string, std::string>> entries = {
        {"John", "Doe"},
        {"Jane", "Smith"},
        {"James", "Brown"},
        {"Anna", "White"},
        {"Robert", "Red"},
        {"Maria", "Green"},
        {"Chris", "Black"},
        {"Eva", "Gold"},
        {"Sam", "Silver"},
        {"Grace", "Blue"},
        {"Max", "Gray"},
        {"Nina", "Pink"},
        {"Ron", "Yellow"},
        {"Sophie", "Crimson"},
        {"Will", "Magenta"}
    };

    for (const auto & entry: entries) {  // using auto for type inference
        map.insert(entry.first, entry.second);
    }

    std::string value;
    if (map.find("Jane", value)) {
        std::cout << "Value associated with 'Jane': " << value << std::endl;
    } else {
        std::cout << "'Jane' not found." << std::endl;
    }

    if (map.find("Max", value)) {
        std::cout << "Value associated with 'Max': " << value << std::endl;
    } else {
        std::cout << "'Max' not found." << std::endl;
    }

    map.remove("Max");
    if (map.find("Max", value)) {
        std::cout << "Value associated with 'Max' after removal: " << value << std::endl;
    } else {
        std::cout << "'Max' not found after removal." << std::endl;
    }

    return 0;
}
