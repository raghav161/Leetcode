class Solution {
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        vector<bool> vec(tiles.size());
        return f(tiles, vec);
    }

    int f(string& tiles, vector<bool>& vec) {
        int count = 0;
        for (int i = 0; i < tiles.size(); i++) {
            if (vec[i] || (i > 0 && tiles[i] == tiles[i - 1] && !vec[i - 1]))
                continue;
            vec[i] = 1;
            count += 1 + f(tiles, vec);
            vec[i] = 0;
        }
        return count;
    }
};