#include "init_arr.h"
array<char [14], 10> fillJump(const char * path)
{
	array< char[14], 10> arr = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	for (int i = 0; i < 10; i++)
		strcpy(arr[i], (path + to_string(i + 1) + (string)".png").c_str());
	return arr;
}
		
array< char [14], 15> fillWalk(string path)
{
	array< char[14], 15> arr = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	
	for (int i = 0; i < 15; i++)
		strcpy(arr[i], (path + to_string(i + 1) + (string)".png").c_str());
		
	return arr;
}


