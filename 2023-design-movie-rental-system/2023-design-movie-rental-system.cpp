class MovieRentingSystem {
public:
    map<int, multiset<pair<int, int>>> cheapest_shops;  // movie -> set of {price, shop}
    map<pair<int, int>, int> avail_renting;  // {shop, movie} -> price
    multiset<vector<int>> cheapest_movies;  // {price, shop, movie}

    // Constructor to initialize the system with given entries
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (int i = 0; i < entries.size(); i++) {
            int shop = entries[i][0];
            int movie = entries[i][1];
            int price = entries[i][2];
            cheapest_shops[movie].insert({price, shop});
            avail_renting[{shop, movie}] = price;
        }
    }

    // Search for the 5 cheapest shops that have the movie
    vector<int> search(int movie) {
        vector<int> ans;
        auto& details = cheapest_shops[movie];
        int k = 0;
        for (auto i : details) {
            ans.push_back(i.second);  // Add the shop ID
            k++;
            if (k == 5) {
                return ans;
            }
        }
        return ans;
    }

    // Rent a movie from the specified shop
    void rent(int shop, int movie) {
        if (!avail_renting.count({shop, movie})) return;  // Movie not available to rent

        int price = avail_renting[{shop, movie}];
        cheapest_movies.insert({price, shop, movie});  // Add to rented list
        avail_renting.erase({shop, movie});  // Remove from availability
        cheapest_shops[movie].erase({price, shop});  // Remove from available shops
    }

    // Drop (return) a movie to the specified shop
    void drop(int shop, int movie) {
        // Find the movie in the rented list
        for (auto it = cheapest_movies.begin(); it != cheapest_movies.end(); it++) {
            if ((*it)[1] == shop && (*it)[2] == movie) {
                int price = (*it)[0];  // Fetch the price from the rented list
                cheapest_movies.erase(it);  // Remove from rented list
                avail_renting[{shop, movie}] = price;  // Mark it available again
                cheapest_shops[movie].insert({price, shop});  // Add back to available shops
                return;
            }
        }
    }

    // Report the 5 cheapest rented movies
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int count = 0;
        for (auto i : cheapest_movies) {
            ans.push_back({i[1], i[2]});  // Add {shop, movie}
            count++;
            if (count == 5) {
                return ans;
            }
        }
        return ans;
    }
};

/**
 * Example usage:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop, movie);
 * obj->drop(shop, movie);
 * vector<vector<int>> param_4 = obj->report();
 */
