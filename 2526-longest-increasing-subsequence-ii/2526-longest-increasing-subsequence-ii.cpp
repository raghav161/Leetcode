class MaxSegmentTree {
public:
    int n;
    vector<int> tree;
    MaxSegmentTree(int n_){
        n=n_;
        tree = vector<int>(4*n_);
    }

    int max_value() { 
        return tree[0]; 
    }

    int query_util(int i, int qL, int qR, int l, int r) {
        if (l >= qL && r <= qR)
            return tree[i];
        if (l > qR || r < qL)
            return INT_MIN;
        int m = (l + r) / 2;
        return max(query_util(2*i+1, qL, qR, l, m), query_util(2*i+2, qL, qR, m+1, r));
    }
    
    int query(int l, int r) { 
        return query_util(0, l, r, 0, n - 1); 
    }

    void update_util(int i, int l, int r, int pos, int val) {
        if (pos < l || pos > r)
            return;
        if (l == r) {
            tree[i] = max(val, tree[i]);
            return;
        }

        int m = (l + r) / 2;
        update_util(2 * i + 1, l, m, pos, val);
        update_util(2 * i + 2, m + 1, r, pos, val);
        tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
    }
    void update(int i, int val){ 
        update_util(0, 0, n - 1, i, val); 
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        MaxSegmentTree tree(*max_element(nums.begin(), nums.end())+1);
        for (int i : nums) {
            int lower = max(0, i - k);
            int cur = 1 + tree.query(lower, i - 1);
            tree.update(i, cur);
        }

        return tree.max_value();
    }
};