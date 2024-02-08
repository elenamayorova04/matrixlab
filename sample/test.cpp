#include "tmatrix.h"

int main()
{
  cout << "==VECTORTEST==" << endl;

  TVector<int> v0(3);
  TVector<int> v1(3);
  TVector<int> v2(3);
  TVector<int> v3;

  cout << "v0: " << v0 << endl;

  cout << "\nv1:" << endl;
  cin >> v1;

  cout << "\nv2:" << endl;
  cin >> v2;

  cout << "\nv1 = " << v1 << endl;

  cout << "\nv2 = " << v2 << endl;

  v3 = v1;
  cout << "\nv3 = v1 = " << v3 << endl;

  cout << "\nv1 + v2 = " << v1 + v2 << endl;

  cout << "\nv1 - v2 = " << v1 - v2 << endl;

  cout << "\nv1 * v2 = " << v1 * v2 << endl;

  cout << "\nv1 + 4 = " << v1 + 4 << endl;

  cout << "\nv1 - 4 = " << v1 - 4 << endl;

  cout << "\nv1 * 4 = " << v1 * 4 << endl;

  if (v1 == v2)
    cout << "\nv1 is equal to v2" << endl;
  if (v1 != v2)
    cout << "\nv1 is not equal to v2" << endl;

  TVector<int> v4(v1);
  cout << "\nv4(v1) = " << v4 << endl;

  v1.resize(2);
  cout << "\nresize v1 to 2: " << v1 << endl;

  cout << "\ngetcount v1 = " << v1.getSize() << endl;

//////////////////////////////////////////////////////////////////////////////////////////////
  cout << "\n==MATRIXTEST==" << endl;

  TMatrix<int> matr(5);
  cout << "matr \n" << matr;

  TMatrix<int> matr1(3);
  cout << "\nenter matrix: " << endl;
  cin >> matr1;

  TMatrix<int> matr2(3);
  cout << "\nenter matrix: " << endl;
  cin >> matr2;

  cout << "\nmatr1 \n" << matr1;
  cout << "\nmatr2 \n" << matr2;

  TMatrix<int> matrcopy(matr1);
  cout << "\nmatr1copy \n" << matrcopy;

  cout << "\nmatr1 + matr2 = \n" << matr1 + matr2;

  cout << "\nmatr1 - matr2 = \n" << matr1 - matr2;

  cout << "\nmatr1 * matr2 = \n" << matr1 * matr2;

  cout << "\nmatr1 * 2 = \n" << matr1 * 2;

  TMatrix<int> matreq;
  matreq = matr1;
  cout << "\nmatr eq matr1 = \n" << matreq;

  matreq.matrResize(2);
  cout << "\nmatreq resize 2 = \n" << matreq;
}