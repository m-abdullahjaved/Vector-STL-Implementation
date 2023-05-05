#pragma once
#include<iostream>
#include<fstream>
using namespace std;

template<typename Type>
class AutoGrowingArray
{
	Type* Arr;
	int  Size{};
public:
	AutoGrowingArray() :Arr(nullptr), Size(0)
	{
	}
	AutoGrowingArray(int size) :Arr(nullptr), Size(size)
	{
		this->Arr = new Type[size];
	}
	void PushBack(Type value)
	{
		Type* temp = new Type[this->Size + 1]{};
		for (int i = 0; i < this->Size; ++i)
			temp[i] = this->Arr[i];
		delete[] this->Arr;
		temp[this->Size++] = value;
		this->Arr = temp;
	}
	Type operator[](int index)
	{
		if (index >= 0 && index < this->Size)
			return this->Arr[index];
	}
	Type& operator[](int index)const
	{
		if (index >= 0 && index < this->Size)
			return this->Arr[index];
	}
	friend ostream& operator << (ostream& Cwritter, const AutoGrowingArray & Other)
	{
		for (int i = 0; i < Other.Size; ++i)
			Cwritter << Arr[i] << ' ';
		Cwritter << endl;;
		return Cwritter;
	}
	~AutoGrowingArray()
	{
		delete[] this->Arr;
	}
};