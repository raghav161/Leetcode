class Solution {
public:
    int minOperations(int n, int m) {
        auto isPrime = [](int x) {
            if (x < 2) 
                return false;
            for (int i = 2; i * i <= x; ++i) {
                if (x % i == 0) 
                    return false;
            }
            return true;
        };
        if(isPrime(n) or isPrime(m))
            return -1;
        string source = to_string(n), target = to_string(m);
        unordered_set<string> visited;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        pq.push({n, source});
        visited.insert(source);
        while (!pq.empty()) {
            auto [cost, current] = pq.top();
            pq.pop();
            if (current == target) 
                return cost;
            for (int i = 0; i < current.size(); ++i) {
                char original = current[i];
                if (original != '9') {
                    current[i]++;
                    int value = stoi(current);
                    if (!isPrime(value) && !visited.count(current)) {
                        visited.insert(current);
                        pq.push({cost + value, current});
                    }
                    current[i]--;
                }

                if (original != '0') {
                    if(i == 0 && original == '1') 
                        continue;
                    current[i]--;
                    int value = stoi(current);
                    if (!isPrime(value) && !visited.count(current)) {
                        visited.insert(current);
                        pq.push({cost + value, current});
                    }
                    current[i]++;
                }
            }
        }

        return -1;
    }
};