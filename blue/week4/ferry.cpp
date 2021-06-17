#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <limits>
using namespace std;

static const int LEFT = 0;
static const int RIGHT = 1;

int main()
{
    int c;
    cin >> c;
    while (c--)
    {
        int n, t, m;
        cin >> n >> t >> m;
        
        vector<int> uploadedTime(m);
        vector<queue<pair<int, int> > >cars(2);
        for (int i = 0; i < m; i++)
        {
            int arrivalTime;
            string bank;
            cin >> arrivalTime >> bank;
            if (bank == "left")
                cars[LEFT].push(pair<int, int>(i, arrivalTime));
            else
                cars[RIGHT].push(pair<int, int>(i, arrivalTime));
        }

        int time = 0;
        int side = LEFT;
        while (!(cars[LEFT].empty() && cars[RIGHT].empty()))
        {
            int next_arrival = numeric_limits<int>::max();
            if (!cars[LEFT].empty())
                next_arrival = cars[LEFT].front().second;
            if (!cars[RIGHT].empty())
                next_arrival = min(next_arrival, cars[RIGHT].front().second);
            
            time = max(time, next_arrival);

            int loaded_cnt = 0;
            while (!cars[side].empty()
                && loaded_cnt < n
                && cars[side].front().second <= time)
            {
                uploadedTime[cars[side].front().first] = time + t;
                cars[side].pop();
                ++loaded_cnt;
            }

            time += t;
            side ^= 1;
        }

        for (int i = 0; i < m; i++)
            cout << uploadedTime[i] << endl;
        if (c) cout << endl;
    }
	return 0;
}
