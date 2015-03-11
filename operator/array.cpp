/*************************************************************************
	> File Name: array.cpp
	> Author: zhuyisong
	> Mail: zhuyisong1994@gmail.com
	> Created Time: Mon 05 Jan 2015 16:14:40 HKT
 ************************************************************************/

#include <array.h>
using namespace std;


int Array::arrayCount = 0;

Array::Array(int size = 10) {
	this->size = size;
}

Array::Array(const Array& newArray) {

	if (&newArray != this) {
		size = newArray.getSize();
		ptr = new int[size];

		for (int i = 0; i < size; i++) {
			ptr[i] = newArray[i];		
		}
	}
}

Array::~Array() {
	size = 0;
	delete[] ptr;
}

int Array::getSize() const {
	return size;
}

int Array::operator[] (int i) {
	return ptr[i];
}

const Array& Array::operator=(const Array& newArray) {
	if (&newArray != this) {
		if (size != newArray.getSize()) {
			size = newArray.getSize();
		}

		delete[] ptr;

		ptr = new int[size];

		for (int i = 0; i < size; i++) {
			ptr[i] = newArray[i];
		}
	}

	return *this;
}

bool Array::operator == (const Array& newArray) const {
	if (size != newArray.getSize()) {
		return false;
	}

	for (int i = 0; i < size; i++) {
		if (newArray[i] != ptr[i]) {
			return false;
		}
	}

	return true;
}

bool Array::operator != (const Array& newArray) const {
	return !(*this == newArray);
}


