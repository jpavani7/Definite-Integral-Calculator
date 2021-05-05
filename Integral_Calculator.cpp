#include "Integral.h"
#include <cmath>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

const int DEFAULT_N = 74850;

int main() {

  double lowerBound;
  double upperBound;
  int partitions;

  int numTerms;
  double exp;
  double cons;
  double coef;

  Integral integral;

  cout << "Lower-Bound: ";
  cin >> lowerBound;
  cout << "Upper-Bound: ";
  cin >> upperBound;
  cout
      << "Number of parts (Enter a negative number to use the deafult value): ";
  cin >> partitions;
  cout << endl;

  if (partitions < 0 || partitions > DEFAULT_N || (partitions % 2) != 0) {
    integral.setN(DEFAULT_N);
  } else {
    integral.setN(partitions);
  }

  integral.setA(lowerBound);
  integral.setB(upperBound);
  integral.setDX();

  cout << "Number of terms of the polynomial: ";
  cin >> numTerms;
  cout << endl;

  for (int i = 0; i < numTerms; i++) {

    if (i == (numTerms - 1)) {
      cout << "Enter the constant for the polynomial: ";
      cin >> cons;
      coef = 0;
      exp = 0;
    }

    else {
      cout << "Enter the coefficient of this term: ";
      cin >> coef;

      cout << "Enter the exponent of this term: ";
      cin >> exp;

      cons = 0;
    }

    cout << endl;

    polynomial term(exp, cons, coef);

    integral.addTerm(term);
  }

  integral.print();

  cout << endl;

  return 0;
}
