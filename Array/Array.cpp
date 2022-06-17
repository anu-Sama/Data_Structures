#include "Array.h"

template <typename T>
Array<T>::Array() {
	allocateElements();
}

template <typename T>
Array<T>::~Array() {
	delete[] elements;
}

template <typename T>
void Array<T>::add(T data) {
	if (count == (size))
		reallocateElements();
	elements[count] = data;
	count++;
}

template <typename T>
T Array<T>::at(int index) {
	return elements[index];
}

template <typename T>
void Array<T>::remove(int position) {
	int index = position - 1;
	T temp1[index]{};
	T temp2[size - position];
	for (int i = 0; i < index; i++) {
		temp1[i] = elements[i];
	}
	for (int i = position; i < count; i++) {
		temp2[i - position] = elements[i];
	}
	count--;
	for (int i = 0; i < count; i++) {
		if (i < position)
			elements[i] = temp1[i];
		if (i > position)
			elements[i] = temp2[i];
	}
}

template <typename T>
T Array<T>::pop() {
	T ret = elements[count];
	(*this).remove(count);
	return ret;
}

template <typename T>
void Array<T>::allocateElements() {

	elements = new T(sizeof(T) * size);

}

template <typename T>
void Array<T>::reallocateElements() {
	T temp[count];
	for (int i = 0; i < count; i++) {
		temp[i] = elements[i];
	}
	delete[] elements;
	size *= 2;
	allocateElements();
	for (int i = 0; i < count; i++) {
		
		elements[i] = temp[i];
	}
	delete[] temp;
}
