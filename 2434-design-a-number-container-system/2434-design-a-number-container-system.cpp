class NumberContainers {
public:
    unordered_map<int, int> idxNum;
    unordered_map<int, set<int>> numIdx;
    NumberContainers() {}
    void change(int index, int number) {
        if (idxNum.find(index) != idxNum.end()) {
            int old_num = idxNum[index];
            idxNum[index] = number;
            numIdx[old_num].erase(index);
            numIdx[number].insert(index);

            if (numIdx[old_num].size() == 0)
                numIdx.erase(old_num);
        } else {
            idxNum[index] = number;
            numIdx[number].insert(index);
        }
    }

    int find(int number) {
        if (numIdx.find(number) != numIdx.end())
            return *numIdx[number].begin();
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */