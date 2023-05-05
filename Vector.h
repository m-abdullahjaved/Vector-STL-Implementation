#pragma once
#include<iostream>
#include<fstream>
using namespace std;

template<typename Type>
class Vector
{
	Type* Arr;
	int  Size{};
	int Cap{};
public:
	Vector() :Arr(new Type{}), Size(0) , Cap(1)
	{
	}
	Vector(int size) :Arr(nullptr), Size(size) , Cap(size)
	{
		this->Arr = new Type[size]{};
	}
	void PushBack(Type value)
	{
		if (this->Size == this->Cap)
		{
			this->Cap *= 2;
			Type* temp = new Type[this->Cap]{};
			for (int i = 0; i < this->Size; ++i)
				temp[i] = this->Arr[i];
			delete[] this->Arr;
			this->Arr = temp;
		}
		this->Arr[this->Size++] = value;
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
	friend ostream& operator << (ostream& Cwritter, const Vector & Other)
	{
		for (int i = 0; i < Other.Size; ++i)
			Cwritter << Other[i] << ' ';
		Cwritter << endl;
		return Cwritter;
	}
	~Vector()
	{
		delete[] this->Arr;
	}
};