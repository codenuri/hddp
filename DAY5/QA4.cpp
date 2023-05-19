#include <iostream>

class Array
{
public:
	int arr[5];

	int size() { return 5; }


//	int& operator[](int idx) { return arr[idx]; }
//	const int& operator[](int idx) const { return arr[idx]; }

	template<typename T>
	auto& operator[](this  T& self, int idx)
	{
		return self.arr[idx];
	}
};
int main()
{
	Array a1 = { 1,2,3,4,5 };
	const Array a2 = { 1,2,3,4,5 };

	int n1 = a1[0];	// a1.operator[](0)			
	int n2 = a2[0];	// a2.operator[](0)			
	a1[0] = 10;		//				
	a2[0] = 10;		//				

	
}



