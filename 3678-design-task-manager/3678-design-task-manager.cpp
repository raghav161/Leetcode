class TaskManager {
public:
    unordered_map<int, vector<int>> mp;
    set<vector<int>, greater<vector<int>>> st;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto& it:tasks)
            add(it[0], it[1], it[2]);
    }

    void add(int userId, int taskId, int priority) {
        mp[taskId] = {priority, taskId, userId};
        st.insert({priority, taskId, userId});
    }

    void edit(int taskId, int newPriority) {
        auto previous = mp[taskId];
        mp.erase(taskId);
        st.erase(previous);
        add(previous[2], taskId, newPriority);
    }

    void rmv(int taskId) {
        auto previous = mp[taskId];
        mp.erase(taskId);
        st.erase(previous);
    }

    int execTop() {
        if(st.size()==0)
            return -1;
        auto it = *st.begin();
        st.erase(st.begin());
        return it[2];
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */