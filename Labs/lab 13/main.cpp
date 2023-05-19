#include <iostream>
#include "funcs.h"

int main()
{
	std::cout << "Task A: " << std::endl;
	std::cout << printRange(-2,10) << std::endl;
	
	std::cout << "Task B: " << std::endl;
	int x = sumRange(1,3);
	std::cout << "This is " << x << std::endl;	// 6
	
	int y = sumRange(-2, 10);
	std::cout << "That is " << y << std::endl;	// 52
	
	std::cout << "Task C: " << std::endl;
	int size = 10;
	int *arr = new int[size]; // allocate array dynamically
	arr[0] = 12;
	arr[1] = 17;
	arr[2] = -5;
	arr[3] = 3;
	arr[4] = 7;
	arr[5] = -15;
	arr[6] = 27;
	arr[7] = 5;
	arr[8] = 13;
	arr[9] = -21;

	int sum1 = sumArray(arr, size);	// Add all elements
	std::cout << "Sum is " << sum1 << std::endl;	// Sum is 43
    
	int sum2 = sumArray(arr, 5);	// Add up first five elements
	std::cout << "Sum is " << sum2 << std::endl;	// Sum is 34

	delete[] arr;	// deallocate it
	
	std::cout << "Task D: " << std::endl;
	std::cout << isAlphanumeric("ABCD") << std::endl;	// true (1)
	std::cout << isAlphanumeric("Abcd1234xyz") << std::endl; // true (1)
	std::cout << isAlphanumeric("KLMN 8-7-6") << std::endl;  // false (0)
	
	std::cout << "Task E: " << std::endl;
	std::cout << nestedParens("((()))") << std::endl;      // true (1)
	std::cout << nestedParens("()") << std::endl;          // true (1)
	std::cout << nestedParens("") << std::endl;            // true (1)
	
	std::cout << nestedParens("(((") << std::endl;         // false (0)
	std::cout << nestedParens("(()") << std::endl;         // false (0)
	std::cout << nestedParens(")(") << std::endl;          // false (0)
	std::cout << nestedParens("a(b)c") << std::endl;       // false (0)
	return 0;
}
