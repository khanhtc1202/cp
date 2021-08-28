#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

long long int r3gz3n(int x)
{
    int sum = 0;
    for (int n = x; n > 0; n /= 10)
        sum += n % 10;
    return sum ^ x;
}

int main() 
{
    int n;
    scanf("%d",&n);
    
    map<long long int, int> m;
    
    bool flag = true;
    long long maxvalue = 0;
    long long leastvalue = 100000000000000000;
    long long maxcount = 0;
    
    for(int i =1; i<=n; i++)
    {
        int x;
        scanf("%d",&x);
        long long y = r3gz3n(x);
        
        map<long long int, int>::iterator it = m.find(y);
        
        if (it != m.end())
        {
            it->second = (it->second)+1;
            flag = false;
        }
        
        else
        m[y] = 1;
    }
    
    if(flag)
    {
        for(map<long long int, int>::iterator it = m.begin(); it!=m.end(); it++)
        {
            if(it->first > maxvalue)
            maxvalue = (it->first);
        }
        cout<<maxvalue<<" "<<0;
    }
    
    else
    { int sum1 = 0;
        for(map<long long int, int>::iterator it = m.begin(); it!=m.end(); it++)
        {
            if(it->second > maxcount)
            {
                maxcount = (it->second);
            }
            
            sum1 = sum1 + (it->second)-1;
        }
        
        for(map<long long int, int>::iterator it = m.begin(); it!=m.end(); it++)
        {
            if(it->second == maxcount)
            {
                leastvalue = min(leastvalue, it->first);
            }
        }
        
        cout<<leastvalue<<" "<<sum1;
    }
    
    
	return 0;
}

