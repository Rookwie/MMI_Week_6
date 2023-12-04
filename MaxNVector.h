#ifndef MAXNVECTOR_H
#define MAXNVECTOR_H

#include <vector>
#include <stdexcept>

template <typename T, int N>
class MaxNVector {
private:
    std::vector<T> data;

    size_t count(T element) const {
        size_t count = 0;
        for (const auto& item : data) {
            if (item == element) {
                count++;
            }
        }
        return count;
    }

public:
    MaxNVector() = default;
    ~MaxNVector() = default;

    void add(T element) {
        if (count(element) >= N) {
            throw std::runtime_error("ElementTooFrequentException");
        }
        data.push_back(element);
    }

    void removeAt(size_t index) {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range");
        }
        data.erase(data.begin() + index);
    }

    T& operator[](size_t index) {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
};

template <typename T>
T getRarestElement(const T* array, size_t size) {
    if (size == 0) {
        throw std::logic_error("Array is empty");
    }

    T rarestElement = array[0];
    size_t rarestCount = size;

    for (size_t i = 0; i < size; ++i) {
        size_t count = 0;

        for (size_t j = 0; j < size; ++j) {
            if (array[i] == array[j]) {
                count++;
            }
        }

        if (count < rarestCount) {
            rarestElement = array[i];
            rarestCount = count;
        }
    }

    return rarestElement;
}

#endif // MAXNVECTOR_H
