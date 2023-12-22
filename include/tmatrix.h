#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include"tvector.h"

template <class T>
class TMatrix : public TVector<TVector<T>>
{
public:
  TMatrix(int s = 5);
  TMatrix(const TMatrix& mt);
  TMatrix(const TVector<TVector<T> >& mt);
  bool operator==(const TMatrix& mt) const;
  bool operator!=(const TMatrix& mt) const;
  TMatrix& operator= (const TMatrix& mt);
  TMatrix  operator+ (const TMatrix& mt);
  TMatrix  operator- (const TMatrix& mt);
    
  friend ostream& operator<<(ostream& out, const TMatrix& mt)
  {
    for (int i = 0; i < mt.size; i++)
      out << mt.data[i] << endl;
    return out;
  }
};

template <class T>
TMatrix<T>::TMatrix(int s) : TVector<TVector<T>>(s)
{
  if (s < 0)
    throw "-1";
}

template <class T>
TMatrix<T>::TMatrix(const TMatrix<T>& mt) :
  TVector<TVector<T> >(mt) {}

template <class T>
TMatrix<T>::TMatrix(const TVector<TVector<T> >& mt) :
  TVector<TVector<T> >(mt) {}

template <class T>
bool TMatrix<T>::operator==(const TMatrix<T>& mt) const
{
  if (size != mt.size)
    return false;
  
  for (int i = 0; i < size; i++)
    if (data[i] != mt.data[i])
      return false;
  return true;
}

template <class T>
bool TMatrix<T>::operator!=(const TMatrix<T>& mt) const
{
  return !(*this == mt);
}

template <class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& mt)
{
  if (this != &mt)
    TVector<TVector<T>>::operator=(mt);
  return *this;
}

template <class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& mt)
{
  if (size != mt.size) 
    throw "-1";
    TMatrix<T> res(size);
    for (int i = 0; i < size; i++) 
      res.data[i] = data[i] + mt.data[i];
  return result;
}

template <class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& mt)
{
  if (size != mt.size)
    throw "-1";
  TMatrix<T> res(size);
  for (int i = 0; i < size; i++)
    res.data[i] = data[i] - mt.data[i];
  return res;
}

#endif