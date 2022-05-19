#pragma once

class myVector {
	int size = 0;
	double *data = 0;
	int capacity = 0;
public:
	myVector(int n);
	~myVector();
	myVector(const myVector& v);
	void resize(int newSize);
	myVector& operator=(const myVector& v);
	void push_back(double a);
	void pop_back();
	void erase(int a);
	void erase(int a, int b);
	void insert(int i, double a);

	// test purposes  
	int getSize();
	void print();
	void print(int a);	  
	double& operator[](int i);
	double operator[](int i) const;
};