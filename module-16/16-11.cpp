// Diving Board: You are building a diving board by placing a bunch of planks of wood end-to-end. There are two types of planks, one of length shorter and one of length longer. You must use exactly K planks of wood. Write a method to generate all possible lengths  r the diving board.


// source boonoOfPlanks


// optimal

#include <iostream>
#include <set>
 
std::set<int> getAllLengths(int noOfPlanks, int shorter, int longer)
{
	std::set<int> lengths;
	for (int s = 0; s <= noOfPlanks; s++)
	{
		int l = noOfPlanks - s;
		int total = s * shorter + l * longer;
		lengths.insert(total);
	}
	return lengths;
}
 
int main(int argc, char** argv)
{
	std::set<int> lengths = getAllLengths(5, 1, 3);
 
	for (int l : lengths)
		std::cout << l << " ";
	std::cout << std::endl;
	
	return 0;
} 
