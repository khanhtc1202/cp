#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int> > minHeap;

vector<int> h;

void minHeapify(int i)
{
	int smallest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;
	if (left < h.size() && h[left] < h[smallest])
	{
		smallest = left;
	}
	if (right < h.size() && h[right] < h[smallest])
	{
		smallest = right;
	}
	if (smallest != i)
	{
		swap(h[i], h[smallest]);
		minHeapify(smallest);
	}
}

void buildHeap(int n)
{
	for (int i = n/2 - 1; i >= 0; i--)
	{
		minHeapify(i);
	}
}

int top()
{
	return h[0];
}

void push(int v)
{
	h.push_back(v);
	int i = h.size() - 1;
	while (i != 0 && h[(i-1)/2] > h[i])
	{
		swap(h[i], h[(i-1)/2]);
		i = (i-1)/2;
	}
	
}

void pop()
{
	if (h.size() == 0)
	{
		return;
	}
	h[0] = h[h.size() - 1];
	h.pop_back();
	minHeapify(0);
}

int main()
{
	return 0;
}
