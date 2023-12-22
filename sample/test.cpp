#include "tvector.h"

int main()
{
  TVector<int> v1(3);
  TVector<int> v2(3);
  TVector<int> v3;

  cout << "v1:" << endl;
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

  v1.resize(2);
  cout << "\nresize v1 to 2: " << v1 << endl;

  cout << "\ngetcount v1 = " << v1.getSize();
}