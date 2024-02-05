class LRUCache {
public:
    list<pair<int, int>> l; // Doubly linked list to store key-value pairs
    unordered_map<int, list<pair<int, int>>::iterator> m; // Hashmap to store key-to-list iterator mapping
    int size; // Capacity of the LRUCache

    LRUCache(int capacity) {
        size = capacity;
    }

    // Get the value associated with a key
    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1; // Key not found in the cache
        }
        l.splice(l.begin(), l, m[key]); // Move the recently used key to the beginning of the list (mark as most recently used)
        return m[key]->second; // Return the value associated with the key
    }

    // Put a key-value pair into the cache
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            l.splice(l.begin(), l, m[key]); // Move the key to the beginning of the list
            m[key]->second = value; // Update the value associated with the key
            return;
        }
        if (l.size() == size) {
            auto d_key = l.back().first; // Get the key of the least recently used item
            l.pop_back(); // Remove the least recently used item from the list
            m.erase(d_key); // Remove the key from the hashmap
        }
        l.push_front({key, value}); // Add the new key-value pair to the beginning of the list (mark as most recently used)
        m[key] = l.begin(); // Update the hashmap with the new key-to-list iterator mapping
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key, value);
 */
