#include <iostream>
using namespace std;
class Container {
   int m_data;
public:
   Container(int data = 0):m_data(data) {}
   ostream& display(ostream& os)const {
      return os << m_data;
   }
   Container operator+(const Container& R)const {
      return Container(m_data + R.m_data);
   }
};
ostream& operator<<(ostream& os, const Container& C) {
   return C.display(os);
}



int sum(int x, int y) {
   return x + y;
}
double sum(double x, double y) {
   return x + y;
}
Container sum(Container x, Container y) {
   return x + y;
}


int main() {
   int a, b = 10;
   double e, f = 10.2;
   Container C, D = 50;
   a = sum(b, 20);
   cout << a << endl;
   e = sum(f, 20.3);
   cout << e << endl;
   C = sum(D, Container(100));
   cout << C << endl;
   return 0;
}