#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>
using namespace std;

template <class T>
class TVector
{
protected:
  T* data;
  int size;
public:
  TVector(int _size = 1);
  TVector(const TVector& p);
  TVector(TVector&& p);
  ~TVector();

  TVector<T> operator + (const TVector& p);
  TVector<T> operator - (const TVector& p);
  T operator * (const TVector& p);

  TVector<T> operator + (double a);
  TVector<T> operator - (double a);
  TVector<T> operator * (double a);

  TVector<T>& operator = (const TVector<T>& p);
  TVector<T> operator = (TVector<T>&& p);

  T& operator[](int pos);
  
  bool operator == (const TVector& p);
  bool operator != (const TVector& p);

  void resize(int newSize = 1);
  int getSize();
  T* getData();

  friend istream& operator >> (istream& in, const TVector& p)
  {
    for (int i = 0; i < p.size; i++)
      in >> p.data[i];
    return in;
  }

  friend ostream& operator<<(ostream& out, const TVector& p)
  {
    for (int i = 0; i < p.size; i++)
      out << p.data[i] << ' ';
    return out;
  }
};

#endif

template <class T> 
TVector<T>::TVector(const int _size)
{
  if (_size < 0)
    throw "size";

  if (_size == 0)
    data = nullptr;

  size = _size;
  data = new T[size];

  for (int i = 0; i < size; i++)
    data[i] = 0;
}

template <class T> 
TVector<T>::TVector(const TVector<T>& p)
{
  if (p.data != nullptr)
  {
    size = p.size;
    data = new T[size];
    for (int i = 0; i < size; i++)
      data[i] = p.data[i];
  }
  else
  {
    data = nullptr;
    size = 0;
  }
}

template <class T> 
TVector<T>::TVector(TVector<T>&& p)
{
  data = p.data;
  size = p.size;
  p.data = nullptr;
  p.size = 0;
}

template <class T> 
TVector<T>::~TVector()
{
  if (data != nullptr)
  {
    delete[] data;
    data = nullptr;
  }
  else
    //throw "empty";
    size = 0;
}

template <class T>
TVector<T> TVector<T>::operator+(double a)
{
  TVector<T> temp(size);

  for (int i = 0; i < size; i++)
    temp.data[i] = data[i] + a;

  return temp;
}


template <class T>
TVector<T> TVector<T>::operator-(double a)
{
  TVector<T> temp(size);

  for (int i = 0; i < size; i++)
    temp.data[i] = data[i] - a;

  return temp;
}

template <class T> TVector<T> TVector<T>::operator*(double a)
{
  TVector<T> temp(size);

  for (int i = 0; i < size; i++)
    temp.data[i] = data[i] * a;

  return temp;
}

template <class T> 
TVector<T> TVector<T>::operator + (const TVector<T>& p)
{
  if (p.size != size)
    throw "size";

  TVector<T> res(size);

  for (int i = 0; i < size; i++)
    res.data[i] = data[i] + p.data[i];

  return res;
}

template <class T> 
TVector<T> TVector<T>::operator - (const TVector<T>& p)
{
  if (p.size != size) 
    throw "size";

  TVector<T> res(size);

  for (int i = 0; i < size; i++)
    res.data[i] = data[i] - p.data[i];

  return res;
}

template <class T> 
T TVector<T>::operator * (const TVector<T>& p)
{
  if (p.size != size) 
    throw "size";

  T res = 0;

  for (int i = 0; i < size; i++)
    res += data[i] * p.data[i];

  return res;
}

template <class T> 
TVector<T>& TVector<T>::operator = (const TVector<T>& p)
{
  if (this == &p)
    return *this;

  if (size != p.size)
  {
    size = p.size;
    delete[] data;
    data = new T[size];
  }

  for (int i = 0; i < size; i++)
    data[i] = p.data[i];

  return *this;
}

template <class T> 
TVector<T> TVector<T>::operator = (TVector<T> &&p)
{
  if (data != 0)
    delete [] data;

  data = p.data;
  size = p.size;
  p.data = nullptr;
  p.size = 0;

  return *this;
}

template <class T> 
bool TVector<T>::operator == (const TVector& p)
{
  if (size != p.size) 
    return false;

  for (int i = 0; i < size; i++)
    if (data[i] != p.data[i]) 
      return false;

  return true;
}

template <class T> 
bool TVector<T>::operator != (const TVector& p)
{
  return !(*this == p);
}

template <class T> 
T& TVector<T>::operator[](int i)
{
  if (i < 0 || i > size)
    throw "size";

  return data[i];
}

template <class T> 
void TVector<T>::resize(int newSize)
{
  if (newSize <= 0) 
    throw "size";

  size = min(newSize, size);
  T* newData = new T[size];

  for (int i = 0; i < size; i++)
    newData[i] = data[i];

  delete[] data;
  data = newData;
}

template <class T>
int TVector<T>::getSize()
{
  return size;
}