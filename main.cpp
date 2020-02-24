#include <iostream>
#include <vector>

#include "utils.h"

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

    int maxCollision = findCollision(buckets);
    std::cout << "\nmaxCollision = " << maxCollision << std::endl;

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

void print(std::vector<float> container) {
    for (auto item : container) {
        std::cout << item << " ";
    }
}

int findCollision(std::vector<float>* container) {
    int max = 0;
    int collisionNumber;

    for(int i = 0; i < BucketNumber; i++) {
        collisionNumber = container[i].size();
        if (collisionNumber > max) {
            max = collisionNumber;
        }
    }
    return max;
}