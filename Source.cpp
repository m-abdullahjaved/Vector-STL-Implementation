#include<iostream>
#include<algorithm>
#include"ArrayList.h"
#include"Vector.h"
#include"AutoGrowingArray.h"
#include<string>
#include<time.h>
using namespace std;

template<typename Type>
int BinarySearch(Type* arr, int start, int end, Type key);
template<typename Type>
int BinarySearch(Type * arr, int size, Type key);
template<typename Type>
int LinearSearch(Type* arr, int size, Type key);
void CreateRandomFile(string filename, int Size, int RN = 100);
template<typename Type>
long long TimeTaken(Type& obj, string filename);
void FINDNUMBERS(string filename);

int main()
{ 
	AutoGrowingArray<int> autogrowingarray;
	Vector<int> vector;
	ArrayList<int> arraylist;
	//CreateRandomFile("OUTPUT.txt", 2);
	cout << "AutoGrowingArray Takes " << TimeTaken(autogrowingarray, "OUTPUT.txt") << " sec!!!\n";
	cout << "Vector Takes " << TimeTaken(vector, "OUTPUT.txt") << " sec!!!\n";
	cout << "ArrayList Takes " << TimeTaken(arraylist, "OUTPUT.txt") << " sec!!!\n";
	//FINDNUMBERS("OUTPUT.txt");
	cout << endl;
	return 0;
}
template<typename Type>
int BinarySearch(Type* arr, int start, int end, Type  key)
{
	if (start > end)
		return -1;
	int mid = (start + end) / 2;
	if (arr[mid] == key)
		return mid;
	return (arr[mid] < key) ? BinarySearch(arr, mid + 1, end, key) : BinarySearch(arr, start, mid - 1, key);
}
template<typename Type>
int BinarySearch(Type * arr, int size, Type key)
{
	int start{}, end{ size }, mid{};
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (arr[mid] == key)
			return mid;
		(key < arr[mid]) ? end = mid - 1 : start = mid + 1;
	}
	return -1;
}
template<typename Type>
int LinearSearch(Type* arr, int size, Type key)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == key)
			return i;
	}
	return  -1;
}
void CreateRandomFile(string filename, int Size, int RN)
{
	srand(time(0));
	ofstream fout(filename);
	for (int i = 0; i < Size * 1024 * 1024; ++i)
		fout << rand()* RN << " ";
}
template<typename Type>
long long TimeTaken(Type& obj, string filename)
{
	int temp{};
	long long StartTime = time(0);
	ifstream fin(filename);
	if (!fin.is_open())
		cout << "SOMETHING WRONG IN OPENING THE FILE!!!" << endl;
	do 
	{
		fin >> temp;
		if (fin.eof())
			break;
		obj.PushBack(temp);
	} while (!fin.eof());
	long long EndTime = time(0);
	return EndTime - StartTime;
}
void FINDNUMBERS(string filename)
{
	ifstream fin(filename);
	int size = 1024 * 1024 * 2;
	int* arr = new int[size]{};
	for (int i = 0; i < size; ++i)
		fin >> arr[i];
	sort(arr, arr + size, less<int>());
	long long start = time(0);
	cout << " USING BINARY SEARCH at index:: " << BinarySearch(arr, size, 55) << " and its takes " << time(0) - start << " sec \n";
	start = time(0);
	cout << " USING LINEAR SEARCH at index:: " << LinearSearch(arr, size, 55) << " and its takes " << time(0) - start << " sec \n";
}