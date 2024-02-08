#ifndef __MATRIX_H__
#define __MATRIX_H__

#include"tvector.h"

template <class T>
class TMatrix : public TVector<TVector<T>>
{
public:
  TMatrix(int s = 1);
  TMatrix(const TMatrix& matr);
  TMatrix(TMatrix&& matr);
  //~TMatrix();

  bool operator==(const TMatrix& matr) const;
  bool operator!=(const TMatrix& matr) const;

  TMatrix& operator= (const TMatrix& matr);

  TMatrix operator+ (const TMatrix& matr);
  TMatrix operator- (const TMatrix& matr);
  TMatrix operator* (const TMatrix& matr);
  TMatrix operator* (const double a);

  void matrResize(int newSize);
    
  friend ostream& operator<<(ostream& out, const TMatrix& matr)
  {
    for (int i = 0; i < matr.size; i++)
      out << matr.data[i] << endl;
    return out;
  }
  friend istream& operator >> (istream& in, const TMatrix& matr)
  {
    for (int i = 0; i < matr.size; i++)
      in >> matr.data[i];
    return in;
  }
};

#endif

template <class T>
TMatrix<T>::TMatrix(int s) : TVector<TVector<T>>(s)
{
  if (s < 0)
    throw "-1";

  TVector<T> row(s);

  for (int i = 0; i < size; i++)
    data[i] = row;
}

template <class T>
TMatrix<T>::TMatrix(const TMatrix& matr)
{
  size = matr.size;
  data = new TVector<T>[size];

  for (int i = 0; i < size; i++)
    data[i] = matr.data[i];
}

template <class T>
TMatrix<T>::TMatrix(TMatrix&& matr)
{
  size = matr.size;
  data = new TVector<T>[size];

  for (int i = 0; i < size; i++)
    data[i] = matr.data[i];

  matr.size = 0;
  matr.data = nullptr;
}

template <class T>
bool TMatrix<T>::operator==(const TMatrix<T>& matr) const
{
  if (size != matr.size)
    return false;
  
  for (int i = 0; i < size; i++)
    if (data[i] != matr.data[i])
      return false;
  return true;
}

template <class T>
bool TMatrix<T>::operator!=(const TMatrix<T>& matr) const
{
  return !(*this == matr);
}

template <class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& matr)
{
  if (this != &matr)
    TVector<TVector<T>>::operator=(matr);

  return *this;
}

template <class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& matr)
{
  if (size != matr.size) 
    throw "size";

  TMatrix<T> res(size);

  for (int i = 0; i < size; i++) 
    res.data[i] = data[i] + matr.data[i];

  return res;
}

template <class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& matr)
{
  if (size != matr.size)
    throw "size";

  TMatrix<T> res(size);

  for (int i = 0; i < size; i++)
    res.data[i] = data[i] - matr.data[i];

  return res;
}

template <class T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix<T>& matr)
{
  if (size != matr.size)
    throw "size";

  TMatrix<T> res(size);
  int i = 0;
  int j = 0;

  for (i = 0; i < matr.size; i++)
  {
    res[i][j] = 0;
    for (j = 0; j < size; j++)
      for(int k = 0; k < size; k++)
        res[i][j] = res[i][j] + data[i][k] * matr.data[k][j];
  }

  return res;
}

template <class T>
TMatrix<T> TMatrix<T>::operator* (const double a) 
{
  TMatrix<T> res(size);

  for (int i = 0; i < size; i++)
    res.data[i] = data[i] * a;

  return res;
}

template <class T>
void TMatrix<T>::matrResize(int newSize)
{
  if (newSize <= 0)
    throw "size";

  size = min(newSize, size);

  for (int i = 0; i < size; i++)
    data[i].resize(size);
}