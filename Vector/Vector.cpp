#include "Vectors.h"
#include <iomanip>
using namespace std;

template <typename T>
Vectorr<T>::Vectorr() {
	ptr = 0;
	cnt = 0;
}

template <typename T>
Vectorr<T>::Vectorr(int CountElem = 5) {
	cnt = CountElem;
	ptr = new T[cnt];
	for (int i = 0; i < cnt; i++) {
		ptr[i] = 0;
	}
}

template <typename T>
Vectorr<T>::Vectorr(Vectorr & a) {
	Vectorr res(a.cnt);

	for (int i = 0; i < a.cnt; i++) {
		res.ptr[i] = a.ptr[i];
	}
}

template <typename T>
Vectorr<T>::~Vectorr() {  }

template <typename T>
int Vectorr<T>::addElement(T newElement) {
	T *tmp;
	tmp = new T[cnt + 1];
	if (tmp == nullptr) { return 0; }
	for (int i = 0; i < cnt; i++) {
		tmp[i] = ptr[i];
	}
	tmp[cnt] = newElement;
	delete ptr;
	cnt++;
	ptr = tmp;
	return 1;
}

template <typename T>
int Vectorr<T>::DelElement(int indexDelElement) {
	T *tmp;
	tmp = new T[cnt - 1];
	if (tmp == nullptr) { return 0; }
	for (int i = 0; i < indexDelElement; i++) {
		tmp[i] = ptr[i];
	}
	for (int i = indexDelElement+1; i < cnt; i++) {
		tmp[i-1] = ptr[i];
	}
	delete ptr;
	cnt--;
	ptr = tmp;
	return 1;
}

template <typename T>
Vectorr<T> operator+ (Vectorr<T>& t, Vectorr<T>& u) {
	if ((t.cnt == u.cnt) || (t.cnt > u.cnt)) {
		Vectorr res(u.cnt);

		for (int i = 0; i < u.cnt; i++) {
			res.addElement( t.ptr[i] + u.ptr[i]);
		}
		return res;
	}

	else if (t.cnt < u.cnt) {
		Vectorr res(t.cnt);

		for (int i = 0; i < t.cnt; i++) {
			res.ptr[i] = t.ptr[i] + u.ptr[i];
		}
		return res;
	}
	else {
		Vectorr res(0);
		return res;
	}
}

template <typename T>
Vectorr<T> operator- (Vectorr<T>& t, Vectorr<T>& u) {
	if ((t.cnt == u.cnt)|| (t.cnt > u.cnt)) {
		Vectorr res(u.cnt);

		for (int i = 0; i < u.cnt; i++) {
			res.ptr[i] = t.ptr[i] - u.ptr[i];
		}
		return res;
	}

	else if (t.cnt < u.cnt) {
		Vectorr res(t.cnt);

		for (int i = 0; i < t.cnt; i++) {
			res.ptr[i] = t.ptr[i] - u.ptr[i];
		}
		return res;
	}
	else {
		Vectorr res(0);
		return res;
	}
}

template <typename T>
Vectorr<T> operator* (Vectorr<T>& t, Vectorr<T>& u) {

	if ((t.cnt == u.cnt) || (t.cnt > u.cnt)) {
		Vectorr res(u.cnt);

		for (int i = 0; i < u.cnt; i++) {
			res.ptr[i] = t.ptr[i] * u.ptr[i];
		}
		return res;
	}

	else if (t.cnt < u.cnt) {
		Vectorr res(t.cnt);

		for (int i = 0; i < t.cnt; i++) {
			res.ptr[i] = t.ptr[i] * u.ptr[i];
		}
		return res;
	}
	else {
		Vectorr res(0);
		return res;
	}
}

template <typename T>
Vectorr<T> operator/ (Vectorr<T>& t, Vectorr<T>& u) {
	if ((t.cnt == u.cnt) || (t.cnt > u.cnt)) {
		Vectorr res(u.cnt);

		for (int i = 0; i < u.cnt; i++) {
			res.ptr[i] = t.ptr[i] / u.ptr[i];
		}
		return res;
	}

	else if (t.cnt < u.cnt) {
		Vectorr res(t.cnt);

		for (int i = 0; i < t.cnt; i++) {
			res.ptr[i] = t.ptr[i] / u.ptr[i];
		}
		return res;
	}
	else {
		Vectorr res(0);
		return res;
	}
}

template <typename T>
Vectorr<T> operator+ (Vectorr<T>& t, T u) {
	Vectorr res(t.cnt);

	for (int i = 0; i < t.cnt; i++) {
		res.ptr[i] = t.ptr[i] + u;
	}
	t.SetPtr(res.ptr, t.cnt);
	return res;
}

template <typename T>
Vectorr<T> operator+ (T u, Vectorr<T>& t) {
	Vectorr res(t.cnt);

	for (int i = 0; i < t.cnt; i++) {
		res.ptr[i] = t.ptr[i] + u;
	}
	t.SetPtr(res.ptr, t.cnt);
	return res;
}

template <typename T>
Vectorr<T> operator- (Vectorr<T>& t, int u) {
	t.DelElement(u);
	return 0;
}

template <typename T>
Vectorr<T> operator* (Vectorr<T>& t, T u) {
	Vectorr res(t.cnt);

	for (int i = 0; i < t.cnt; i++) {
		res.ptr[i] = t.ptr[i] * u;
	}
	t.SetPtr(res.ptr, t.cnt);
	return res;
}

template <typename T>
Vectorr<T> operator* (T u, Vectorr<T>& t) {
	Vectorr res(t.cnt);

	for (int i = 0; i < t.cnt; i++) {
		res.ptr[i] = t.ptr[i] * u;
	}
	t.SetPtr(res.ptr, t.cnt);
	return res;
}

template <typename T>
Vectorr<T> Vectorr<T>::operator= (Vectorr<T>& t) {
	if (this == &t) {
		return *this;
	}
	if (t.GetCnt() > 0) {
		int cnt = t.GetCnt();
		ptr = new T[cnt];

		for (int i = 0; i < cnt; i++) {
			ptr[i] = t.ptr[i];
		}

	}
	return *this;
}

template <typename T>
bool Vectorr<T>::operator== (Vectorr<T>& t) {
	for (int i = 0; i < t.cnt; i++) {
		if (ptr[i] != t.ptr[i]) {
			return false;
		}
	}
	return true;
}

template <typename T>
int Vectorr<T>::GetCnt() {
	return cnt;
}

template <typename T>
T *Vectorr<T>::GetPtr() {
	return ptr;
}

template <typename T>
int Vectorr<T>::SetCnt(int newCnt) {
	cnt = newCnt;
	return cnt;
}

template <typename T>
int Vectorr<T>::SetPtr(T *newptr, int n) {
	for (int i = 0; i < n; i++) {
		ptr[i] = newptr[i];
	}
	return 1;
}

template <typename T>
std::ostream& operator<< (std::ostream &out, Vectorr<T>& t) {

	out << "Vector: (";
	for (int i = 0; i < t.cnt; i++) {
		out << t.ptr[i] << "; ";
	}
	out << ") ";
	return out;
}

template <typename T>
std::istream& operator >> (std::istream &in, Vectorr<T>& t) {
	int arraySize;
	cout << "Enter a length for the vector: ";
	cin >> arraySize;

	for (int i = 0; i < arraySize; i++) {
		int b;
		in >> b;
		t.addElement(b);
	}
	return in;
}
