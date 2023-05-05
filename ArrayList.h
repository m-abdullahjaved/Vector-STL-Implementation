#pragma once
#include<ostream>
#include<fstream>
using namespace std;

template<typename Type>
class ArrayList
{
	Type* Arr;
	int  Size{};
	int Cap{};
public:
	ArrayList() :Arr(new Type[2]{}), Size(0) , Cap(2)
	{
	}
	ArrayList(int size) :Arr(nullptr), Size(size) , Cap(size)
	{
		this->Arr = new Type[size]{};
	}
	void PushBack(Type value)
	{
		if (this->Size == this->Cap)
		{
			this->Cap += Cap / 2;
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
	friend ostream& operator << (ostream& Cwritter, const ArrayList & Other)
	{
		for (int i = 0; i < Other.Size; ++i)
			Cwritter << Arr[i] << ' ';
		Cwritter << endl;;
		return Cwritter;
	}
	~ArrayList()
	{
		delete[] this->Arr;
	}
};

