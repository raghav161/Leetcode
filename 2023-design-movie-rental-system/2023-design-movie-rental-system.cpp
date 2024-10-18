class MovieRentingSystem {
public:
    map<int, multiset<pair<int, int>>> cheapest_shops;
    map<pair<int, int>, int> avail_renting;
    multiset<vector<int>> cheapest_movies;
    MovieRentingSystem(int n, vector<vector<int>>& entries)
    {
        for(int i=0;i<entries.size();i++)
        {
            cheapest_shops[entries[i][1]].insert({entries[i][2], entries[i][0]});
            avail_renting[{entries[i][0], entries[i][1]}]=entries[i][2];
        }
    }
    
    vector<int> search(int movie)
    {
        vector<int> ans;
        auto& details=cheapest_shops[movie];
        int k=0;
        for(auto i:details)
        {
            ans.push_back(i.second);
            k++;
            if(k==5)
                return ans;
        }
        return ans;
    }
    
    void rent(int shop, int movie)
    {
        if(!avail_renting.count({shop, movie}))
            return;
        int price=avail_renting[{shop, movie}];
        cheapest_movies.insert({price, shop, movie});
        avail_renting.erase({shop, movie});
        cheapest_shops[movie].erase({price, shop});
    }

    void drop(int shop, int movie) {
        for(auto it:cheapest_movies)
        {
            if(it[1]==shop and it[2]==movie)
            {
                int price=it[0];
                cheapest_movies.erase({price, shop, movie});
                avail_renting[{shop, movie}] = price;
                cheapest_shops[movie].insert({price, shop});
                return;
            }
        }
    }
    
    vector<vector<int>> report() {
        int count=0;
        vector<vector<int>> ans;
        for(auto i:cheapest_movies)
        {
            ans.push_back({i[1], i[2]});
            count++;
            if(count==5)
                return ans;
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */