#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
	string line;
	while (getline(cin, line))
	{
		if(line == "0 Fuel consumption 0") break;
		
		double curr = 0.0, tank = 0.0;
		int dist = 0, consumption = 0, leak = 0;;
		do
		{
            istringstream sin(line);
			int n , c;
			string s,trash;
			sin >> n >> s;
			if(s == "Fuel" || s == "Gas") sin>>trash;
            if(s == "Fuel") sin >> c;

			curr += leak * (n-dist);
			curr += (consumption/100.0) * (n - dist);
			tank = max(curr, tank);

			if ( s == "Goal") break;
			if ( s == "Fuel") consumption = c;
			else if ( s == "Leak") leak++;
			else if (s == "Mechanic") leak = 0;
			else if (s == "Gas") curr = 0.0;
			dist = n;

		} while(getline(cin, line));

		cout << fixed << setprecision(3) << tank<< endl;
	}
}