#include "Polynomial.h"
#include <vector>

using namespace std;

class Integral {
public:
  void setDX() { DX = (b - a) / n; }
  void setN(int n) { this->n = n; }
  void setA(double a) { this->a = a; }
  void setB(double b) { this->b = b; }
  void addTerm(polynomial term) { expression.push_back(term); }
  double calcIntegral(double x, int counter) const;
  double calculateFTC();
  void print();

private:
  double a;
  double b;
  double DX;
  int n;
  vector<polynomial> expression;
};
