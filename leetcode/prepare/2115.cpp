/*
https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string> avaiSupplies(supplies.begin(), supplies.end());

        unordered_map<string,int> recipeIndex;
        unordered_map<string, vector<string>> dependencyGraph;      
        vector<int> inDegree(n, 0);

        for (int i = 0; i < n; ++i) {
            recipeIndex[recipes[i]] = i; // build recipe to index map
            for (string& ing: ingredients[i]) {
                if (!avaiSupplies.count(ing)) {
                    dependencyGraph[ing].push_back(recipes[i]); // add recipes[i] to list recipes that depends on ing
                    inDegree[i]++; // add 1 to rank of recipes, rank 0 mean no dependecies
                }
            }
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i); // process rank 0 recipes first
            }
        }

        vector<string> createdRecipes;
        while (!q.empty()) {
            int recipeIdx = q.front(); q.pop();
            string recipe = recipes[recipeIdx];
            createdRecipes.push_back(recipe);

            // If there is no recipe that depends on this recipe, skip
            if (!dependencyGraph.count(recipe)) continue;

            // Reduce degree of all depended recipes of this recipe by 1
            for (string& dRecipe: dependencyGraph[recipe]) {
                if (--inDegree[recipeIndex[dRecipe]] == 0) {
                    q.push(recipeIndex[dRecipe]); // next creatable recipe with rank 0
                }
            }
        }
        return createdRecipes;
    }
};
