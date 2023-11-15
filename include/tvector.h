#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>

using namespace std;
typedef unsigned int T;


template <class T>
class TVector
{
protected:
  T* data;
  int size;
public:
  TVector(int _size = 0);
  TVector(const TVector& p);
  //TVector(const TVector&& p);
  ~TVector();

   TVector operator + (const TVector& p);
  TVector operator - (const TVector& p);
  T operator * (const TVector& p);

  TVector<T>& operator = (const TVector<T>& p);
  T& operator[](int pos);
  //TVector<T> operator = (TVector<T>&& p);

  TVector operator + (double a);
  TVector operator - (double a);
  TVector operator * (double a);

  bool operator == (const TVector& p) const;
  bool operator != (const TVector& p) const;

  void resize(int newSize);
  int GetSize() { return size; }
  //T* operator [];

  //iostream& operator << (iostream&);
  friend ostream& operator<<(ostream& out, const TVector& p)
  {
    for (int i = 0; i < p.size; i++)
      out << p.data[i] << ' ';
    return out;
  }
};

#endif

template <class T> TVector<T>::TVector(const int _size = 1)
{
  if (_size < 0)
    throw "-1";
  if (_size == 0)
    data = nullptr;
  size = _size;
  data = new T[size];
}

template <class T> TVector<T>::TVector(const TVector<T>& p)
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

//template <class T> TVector<T>::TVector(const TVector<T>&& p)
//{
//    data = p.data;
//    size = p.size;
//    p.data = nullptr;
//    p.size = 0;
//    }

template <class T> TVector<T>::~TVector()
{
  if (data != nullptr)
  {
    delete[] data;
    data = nullptr;
  }
  else 
    throw "empty";
}

template <class T> TVector<T> TVector<T>::operator+(double a)
{
  TVector<T> temp(size);
  for (int i = 0; i < size; i++)
    temp[i] = data[i] + a;
  return temp;
}

template <class T> TVector<T> TVector<T>::operator-(double a)
{
  TVector<T> temp(size);
  for (int i = 0; i < size; i++)
    temp[i] = data[i] - a;
  return temp;
}

template <class T> TVector<T> TVector<T>::operator*(double a)
{
  TVector<T> temp(size);
  for (int i = 0; i < size; i++) { temp[i] = data[i] * a; }
  return temp;
}

template <class T> TVector<T> TVector<T>::operator + (const TVector<T>& p)
{
  if (p.size != size)
    throw "-1";
  TVector<T> res(size);
  for (int i = 0; i < size; i++)
    res.data[i] = data[i] + p.data[i];
  return res;
}

template <class T> TVector<T> TVector<T>::operator - (const TVector<T>& p)
{
  if (p.size != size) throw "-1";
  TVector<T> res(size);
  for (int i = 0; i < size; i++)
    res.data[i] = data[i] - p.data[i];
  return res;
}

template <class T> T TVector<T>::operator * (const TVector<T>& p)
{
  if (p.size != size) throw "-1";
  int result = 0;
  for (int i = 0; i < size; i++)
    result += data[i] * p.data[i];
  return result;
}

template <class T> TVector<T>& TVector<T>::operator = (const TVector<T>& p)
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

template <class T> T& TVector<T>::operator[](int pos)
{
  if (pos < 0 || pos > size)
    throw "-1";
  return data[pos];
}

//template <class T> TVector<T>::operator = (TVector<T> &&p)
//{
//  if (data != 0)
//    delete data;
//  data = p.data;
//  size = p.size;
//  p.data = nullptr;
//  p.size = 0;
//  return *this;
//}

template <class T> bool TVector<T>::operator == (const TVector& p) const
{
  if (size != p.size) return 0;
  for (int i = 0; i < size; i++)
    if (data[i] == p.data[i]) 
      return 1;
}

template <class T> bool TVector<T>::operator != (const TVector& p) const
{
  return !(*this == p);
}

template <class T> void resize(int newSize)
{
  if (newSize <= 0) throw "- 1";
  int newData = new T[newSize];
  for (int i = 0; i < std::min(newSize, size); i++)
    newData[i] = data[i];
  delete[] data;
  data = newData;
}


//template <class T> ostream& operator<<(ostream& ostr, const TVector& bf) // вывод
//{
//    ostr << bf.size;
//    for (int i = 0; i < bf.size; i++)
//    {
//        ostr << 0;
//    }
//    return ostr;
//}