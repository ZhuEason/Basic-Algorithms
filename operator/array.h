/*************************************************************************
	> File Name: array.h
	> Author: zhuyisong
	> Mail: zhuyisong1994@gmail.com
	> Created Time: Mon 05 Jan 2015 15:48:22 HT
 ************************************************************************/

#ifndef ARRAY
#define ARRAY

#include <iostream>
using namespace std;

class Array {
	friend ostream& operator<< (ostream&, const Array&);
	friend istream& operator>> (istream&, Array&);

public:
	Array(int = 10);
	Array( const Array& );
	~Array();
	int getSize() const;
	int operator[](int);
	const Array &operator= (const Array &);
	bool operator==(const Array&) const;
	bool operator!=(const Array&) const;
	static int getArrayCount();

private:
	int size;
	int *ptr;
	static int arrayCount;
}

#endif
