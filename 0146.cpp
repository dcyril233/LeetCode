#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class LRUCache {
private:
    int cap; // the maximum capacity
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> hash;
public:
    LRUCache(int capacity): cap(capacity) {}
    
    int get(int key) {
        auto it = hash.find(key);
        if(it == hash.end()) return -1; // didn't find key
        cache.splice(cache.begin(), cache, it->second); // move the node to the head
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = hash.find(key);
        if(it != hash.end()){ // find the key, change its value and move its position in the cache
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
            return;
        }
        else {
            cache.push_front({key, value});
            hash[key] = cache.begin();

            if(hash.size() > cap) {
                hash.erase(cache.back().first);
                cache.pop_back();
            }
        }
    }
};

#ifdef LEETCODE
int main() {
    LRUCache lRUCache = LRUCache(2);
    lRUCache.put(1, 1);
    lRUCache.put(2, 2);
    lRUCache.get(1);
    lRUCache.put(3, 3);
    lRUCache.get(2);
    lRUCache.put(4, 4);
    lRUCache.get(1);
    lRUCache.get(3);
    lRUCache.get(4);
    return 0;
}
#endif