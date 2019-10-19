#ifndef VECTORS_H_INCLUDED
#define VECTORS_H_INCLUDED
#include <iostream>
#include <iomanip>
using namespace std; 

template <typename T>
class Vectorr {
public:
	Vectorr();
	Vectorr(Vectorr & a);
	Vectorr(int CountElem);
	friend Vectorr operator+(Vectorr& t, Vectorr& u);
	friend Vectorr operator-(Vectorr& t, Vectorr& u);
	friend Vectorr operator*(Vectorr& t, Vectorr& u);
	friend Vectorr operator/(Vectorr& t, Vectorr& u);
	friend Vectorr operator+ (Vectorr& t, T u);
	friend Vectorr operator+ (T u, Vectorr& t);
	friend Vectorr operator- (Vectorr& t, int u);
	friend Vectorr operator* (Vectorr& t, T u);
	friend Vectorr operator* (T u, Vectorr& t);
	 Vectorr operator= (Vectorr& t);
	 bool operator== (Vectorr& t);
	~Vectorr();
	int GetCnt();
	int SetCnt(int newCnt);
	T *GetPtr();
	int SetPtr(T *newptr, int n);

	int addElement(T newElement);
	int DelElement(int indexDelElement);
	friend std::ostream& operator<< (std::ostream &out, Vectorr& t);
	friend std::istream& operator >> (std::istream &in, Vectorr& t);

private:
	T *ptr;
	int cnt;
};


#endif // VECTOR_H_INCLUDED

