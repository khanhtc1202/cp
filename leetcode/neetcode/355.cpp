#include <bits/stdc++.h>
using namespace std;

class Twitter {
private:
    unordered_map<int, unordered_map<int, int>> followerships;
    vector<pair<int, int>> posts;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        int cnt = 0;
        for (int i = posts.size() - 1; i >= 0 && cnt < 10; i--) {
            if (posts[i].first == userId || followerships[userId][posts[i].first])
                res.push_back(posts[i].second), cnt++;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followerships[followerId][followeeId] = 1;
    }
    
    void unfollow(int followerId, int followeeId) {
        followerships[followerId][followeeId] = 0;
    }
};
