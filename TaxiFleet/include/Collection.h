#ifndef COLLECTION_H
#define COLLECTION_H

#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

template <typename T>
class Collection {
private: 
    std::vector<T> items;

public:
    void add(const T& item) {
        items.push_back(item);
    }

    void remove(int index) {
        if (index >= 0 && index < items.size())
            items.erase(items.begin() + index);
    }

    int size() const {
        return items.size();
    }

    const T& get(int index) const{
        return items.at(index);
    }

    void clear(){
        items.clear();
    }

    void print() const{
        for (const auto& item : items) {
            std::cout << item << "\n";
        }
    }

    template <typename Predicate>
    int find(Predicate condition) const{
        for (size_t i = 0; i < items.size(); ++i) {
        if (condition(items[i])) {
            return i;
            }
        }
        return -1;
    }
};

template <typename T, typename Predicate>
    void filterAndPrint(const Collection<T>& col, Predicate condition){
        for (size_t i = 0; i < col.size(); ++i) 
        if (condition(col.get(i))) {
            }
        };

#endif
