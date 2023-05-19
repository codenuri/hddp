#include <iostream>

class Array
{
public:
	int arr[5];

	int size() { return 5; }

	int& operator[](int idx) { return arr[idx]; }
};

int main()
{
	Array a1 = { 1,2,3,4,5 };
	
	a1[0] = 10; // 
}