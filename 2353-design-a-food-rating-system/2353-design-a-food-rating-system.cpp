class FoodRatings {
public:
//     unordered_map<string, set<pair<int, string>>>cousine_rating;
//     unordered_map<string, string>food_cousine;
//     unordered_map<string, int>food_rating;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            c[cuisines[i]].insert({-ratings[i], foods[i]});
            b[foods[i]]=cuisines[i];
            a[foods[i]]=ratings[i];
        }    
    }
    
    void changeRating(string food, int newRating) {
        string cousine=b[food];
        c[cousine].erase({-a[food], food});
        c[cousine].insert({-newRating, food});
        a[food]=newRating;
    }
    
    string highestRated(string cuisine) {
        return c[cuisine].begin()->second;
    }
    map<string,int>a;
map<string,string>b;
map<string,set<pair<int,string>>>c;
// FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings)
// {
// int n=foods.size();
// for(int i=0;i<n;i++)
// {
// a[foods[i]]=ratings[i];
// b[foods[i]]=cuisines[i];
// c[cuisines[i]].insert({-ratings[i],foods[i]}); 
// }
// }

// void changeRating(string food, int newRating) 
// {
//     int cp=a[food];
//     a[food]=newRating;
//     string cuis=b[food];
// 	c[cuis].erase(c[cuis].find({-cp,food}));
//     c[cuis].insert({-newRating,food});
// }

// string highestRated(string cuisine) {
//     return c[cuisine].begin()->second;
    
// }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */