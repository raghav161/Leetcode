class MyHashSet {
public:
    vector<bool> hash_table;
    MyHashSet() {
        hash_table = vector<bool>(1000001);
    }

    void add(int key) {
        hash_table[key] = 1;
    }

    void remove(int key) {
        hash_table[key] = 0;
    }

    bool contains(int key) {
        return hash_table[key];
    }
};
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */