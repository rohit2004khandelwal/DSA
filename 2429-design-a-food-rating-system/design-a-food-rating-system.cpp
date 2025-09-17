class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>>> cuisine_ratings_food;
    unordered_map<string, string> food_cuisine;
    unordered_map<string, int> food_rating;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        
        for(int i = 0; i<n; i++) {
            string food    = foods[i];
            string cuisine = cuisines[i];
            int rating     = ratings[i];
            
            cuisine_ratings_food[cuisine].insert({-rating, food});
            food_cuisine[food] = cuisine;
            food_rating[food]  = rating;
            
            
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = food_cuisine[food];
        int oldRating  = food_rating[food];
        
        cuisine_ratings_food[cuisine].erase({-oldRating, food});
        cuisine_ratings_food[cuisine].insert({-newRating, food});
        food_rating[food] = newRating;
        
    }
    
    string highestRated(string cuisine) {
        return begin(cuisine_ratings_food[cuisine])->second; 
        
        //first item will have highest absolute rating "we put all ratings in negative" (ordered_set)
        //Why did we not put them in ascending order and just return the last element of ordered_set ?
        //Ans : Because We can have a case like below
        //{(15, abc), (16, ramen), (16, sushi)} -> Order in ordered_set. last element is not lexicographically smaller
        //{(-16, ramen), (-16, sushi), (-15, abc)} -> First element is now lexicographically smaller
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */