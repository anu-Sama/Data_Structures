#pragma once

template <typename T>
class Array
{
public:
	Array();
	~Array();

	void add(T);
	void remove(int);
	T pop();
	T at(int);

private:

	void allocateElements();
	void reallocateElements();

	int size = 2;
	int count = 0;
	T* elements;

};

