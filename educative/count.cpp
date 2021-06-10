#include <iostream>
using namespace std;

template <class T>
class Score
{
private:
    T value;
public:
    static int counter;
    Score()  {counter++;}
};
 
template<class T>
int Score<T>::counter = 0;
 
int main()
{
    Score<int> x;
    Score<int> y;
    Score<double> z;
    cout << Score<int>::counter<< endl;
    cout << Score<double>::counter<< endl;
    return 0;
}
