#include <iostream>
#include <vector>
#include <bitset>
#include <functional>
#include <cmath>

class BloomFilter {
public:
    BloomFilter(int n, double falsePositiveRate) {
        this->falsePositiveRate = falsePositiveRate;
        this->size = calculateSize(n, falsePositiveRate);
        this->hashFunctions = calculateHashFunctions(n, size);
        this->bitArray.resize(size, false);
    }

    void add(const std::string& item) {
        for (const auto& hashFunction : hashFunctions) {
            size_t index = hashFunction(item) % size;
            bitArray[index] = true;
        }
    }

    bool find(const std::string& item) {
        for (const auto& hashFunction : hashFunctions) {
            size_t index = hashFunction(item) % size;
            if (!bitArray[index]) {
                return false;
            }
        }
        return true;
    }

    double getFalsePositiveRate() {
        return pow(1 - exp(-hashFunctions.size() * size / static_cast<double>(size)), hashFunctions.size());
    }

private:
    double falsePositiveRate;
    size_t size;
    std::vector<bool> bitArray;
    std::vector<std::function<size_t(const std::string&)>> hashFunctions;

    size_t calculateSize(int n, double falsePositiveRate) {
        return static_cast<size_t>(-n * log(falsePositiveRate) / (log(2) * log(2)));
    }

    std::vector<std::function<size_t(const std::string&)>> calculateHashFunctions(int n, size_t size) {
        std::vector<std::function<size_t(const std::string&)>> functions;
        functions.push_back(std::hash<std::string>());
        functions.push_back(std::hash<std::string>());

        // You can add more hash functions as needed

        return functions;
    }
};

int main() {
    int n = 10000; // Number of items to insert into the Bloom filter
    double falsePositiveRate = 0.01; // Target false positive rate of 1%

    BloomFilter bloomFilter(n, falsePositiveRate);

    // Insert items into the Bloom filter
    for (int i = 0; i < n; ++i) {
        bloomFilter.add(std::to_string(i));
    }

    int totalQueries = 10000; // Total number of queries to test for false positives
    int falsePositives = 0;

    // Check for false positives
    for (int i = n; i < n + totalQueries; ++i) {
        if (bloomFilter.find(std::to_string(i))) {
            falsePositives++;
        }
    }

    double actualFalsePositiveRate = static_cast<double>(falsePositives) / totalQueries;
    std::cout << "Target False Positive Rate: " << falsePositiveRate << std::endl;
    std::cout << "Actual False Positive Rate: " << actualFalsePositiveRate << std::endl;

    return 0;
}
