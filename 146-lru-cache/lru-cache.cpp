class LRUCache {
public:
    list < pair<int, int>> ls;
    unordered_map < int, list<pair<int, int>>::iterator> umap;
    int cap;

    LRUCache(int capacity) { cap = capacity; }

    int get(int key) {

        if (umap.find(key) == umap.end())
            return -1;

        ls.splice(ls.begin(), ls, umap[key]);

        return umap[key]->second;
    }

    void put(int key, int value) {

        if (umap.find(key) != umap.end()) {

            ls.splice(ls.begin(), ls, umap[key]);
            umap[key]->second = value; return;
        }

        if (ls.size() == cap) {
            auto isKey = ls.back().first;
            ls.pop_back();
            umap.erase(isKey);
        }

        ls.push_front({key, value});
        umap[key] = ls.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */