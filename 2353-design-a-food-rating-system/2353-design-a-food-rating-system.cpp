struct cmp {
    bool operator () (pair<int, string> a, pair<int, string> b) const { 
        if(a.first == b.first) {
            return a.second > b.second;
        } else {
            return a.first < b.first;
        }
    }
};
class FoodRatings {
public:
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRating;
    unordered_map<string, set<pair<int, string>, cmp>> mp;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; i++) {
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
            mp[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        int currRating = foodToRating[food];
        string currCuisine = foodToCuisine[food];
        
        mp[currCuisine].erase({currRating, food});
        mp[currCuisine].insert({newRating, food});
        foodToRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return mp[cuisine].rbegin() -> second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */