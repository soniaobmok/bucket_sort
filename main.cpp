#include <iostream>
#include <vector>

void insertionSort(std::vector<float>);
void print(const std::vector<float>&);

const int BucketNumber = 100;

int main() {
    auto *sourceArray = new float();
    int count = 0;

    float num;
    std::cin >> num;
    while(num != 0) {
        sourceArray[count] = num;
        count++;
        std::cin >> num;
    }

    auto *buckets = new std::vector<float>[BucketNumber];

    for (int i = 0; i < count; i++) {
        int whole = static_cast<int>(sourceArray[i]);
        buckets[whole].push_back(sourceArray[i]);
    }

    for (int i = 0; i < BucketNumber; i++) {
        if (!buckets[i].empty()) {
            insertionSort(buckets[i]);
        }
    }

    return 0;
}

void insertionSort(std::vector<float> container) {
    for (int i = 0; i < container.size(); i++) {
        int j = i;
        while (j > 0 && container[j - 1] > container[j]) {
            std::swap(container[j - 1], container[j]);
            j--;
        }
    }
    print(container);
}

void print(const std::vector<float>& container) {
    for (auto item : container) {
        std::cout << item << " ";
    }
}
