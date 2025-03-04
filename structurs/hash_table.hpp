#pragma once

#include <vector>
#include <list>
#include <functional>

template <typename K, typename V>
class HashTable {
public:
    HashTable() : size_(10) {data_.resize(10);}
    HashTable(int size) : size_(10) {data_.resize(size);}
    void add(const K& key, V& val);
    V find(const K& key);

private:
    int hashFun(const K& key) {return std::hash<K>{}(key) % size_;}

    int size_;
    std::vector<std::list<std::pair<K, V>>> data_;
};

template <typename K, typename V>
V HashTable<K, V>::find(const K& key) {
    int index = hashFun(key);
    const auto& list = data_.at(index);

    auto p_first = list.begin();
    auto p_last = list.end();
    for (; p_first != p_last; ++p_first)
        if ((*p_first).first == key)
            return (*p_first).second;
     
    return (*p_last).second;
}

template <typename K, typename V>
void HashTable<K, V>::add(const K& key, V& val) {
    int index = hashFun(key);
    data_.at(index).push_back({key, val});
};
