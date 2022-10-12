// LRU cache implementation


#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {

    int capacity;
    list<int> cache;

    // key: page number, value: iterator to the page in the cache
    unordered_map<int, list<int>::iterator> map;

public:

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {

        if (map.find(key) == map.end()) {
            return -1;
        }

        // remove the page from the current position in the cache
        // and add it to the front of the cache
        cache.erase(map[key]);
        cache.push_front(key);

        // update the iterator to the page in the cache
        map[key] = cache.begin();

        return key;
    }

    void put(int key, int value) {

        // if the page is already in the cache, remove it
        if (map.find(key) != map.end()) {
            
            // remove the page from the current position in the cache
            cache.erase(map[key]);
        }
        // if the cache is full, remove the least recently used page 
        else if (cache.size() == capacity) {
            map.erase(cache.back());
            cache.pop_back();
        }

        // add the page to the front of the cache
        cache.push_front(key);
        map[key] = cache.begin();
    }
};

int main() {

    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);

    cout << cache.get(1) << endl; // 1

    cache.put(3, 3);

    cout << cache.get(2) << endl; // -1

    return 0;
}