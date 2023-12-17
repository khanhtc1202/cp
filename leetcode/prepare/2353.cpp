/*
https://leetcode.com/problems/design-a-food-rating-system/
*/
#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
    unordered_map<string, int> foodRating;
    unordered_map<string, string> foodCuisine;
    unordered_map<string, set<pair<int, string>>> cuisineFoodMap;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            foodRating[foods[i]] = ratings[i];
            foodCuisine[foods[i]] = cuisines[i];
            // Since set is min set, push (-1 * rating, name) to the set as max rating first
            cuisineFoodMap[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto cuisine = foodCuisine[food];

        // Delete old rating
        auto oldEle = cuisineFoodMap[cuisine].find({-foodRating[food], food});
        cuisineFoodMap[cuisine].erase(oldEle);

        // Update rating
        foodRating[food] = newRating;

        // Insert new rating
        cuisineFoodMap[cuisine].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        // Top of the set is highest rating
        auto ans = *cuisineFoodMap[cuisine].begin();
        return ans.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
