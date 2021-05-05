#include "Integral.h"
#include "cmath"
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

double Integral::calcIntegral(double x, int counter) const {

  double integral = 0.0;

  if (x > b) {
    return 0;
  }

  for (int j = 0; j < expression.size(); j++) {
    integral +=
        ((expression.at(j).getCoef() * (pow(x, expression.at(j).getExp())) +
          expression.at(j).getConst()));
  }
  if (x != a || x != b) {
    if ((counter % 2) == 0) {
      integral *= 4;
    } else {
      integral *= 2;
    }
  }

  return (integral * (DX / 3)) + (calcIntegral(x + DX, counter + 1));
}

double Integral::calculateFTC() {

  double upperIntegral = 0.0;
  double lowerIntegral = 0.0;

  for (int j = 0; j < expression.size(); j++) {

    upperIntegral +=
        (((expression.at(j).getCoef() * (1 / (expression.at(j).getExp() + 1)) *
               (pow(b, (expression.at(j).getExp() + 1))) +
           (expression.at(j).getConst() * b))));
  }

  for (int j = 0; j < expression.size(); j++) {

    lowerIntegral +=
        (((expression.at(j).getCoef() * (1 / (expression.at(j).getExp() + 1)) *
               (pow(a, (expression.at(j).getExp() + 1))) +
           (expression.at(j).getConst() * a))));
  }

  return upperIntegral - lowerIntegral;
}

void Integral::print() {
  cout << "integral (" << a << " -> " << b << ") ";
  for (int j = 0; j < expression.size(); j++) {
    if (expression.at(j).getExp() == 1) {
      if (expression.at(j).getCoef() == 1) {
        cout << "x + ";
      } else {
        cout << expression.at(j).getCoef() << "x + ";
      }
    }

    else if (j == expression.size() - 1) {
      if (expression.at(j).getConst() == 0) {
        cout << "dx = ";

      } else {
        cout << expression.at(j).getConst() << " dx = ";
      }
    } else {
      if (expression.at(j).getCoef() == 1) {
        cout << "x^(" << expression.at(j).getExp() << ") + ";
      } else {
        cout << expression.at(j).getCoef() << "x^(" << expression.at(j).getExp()
             << ") + ";
      }
    }
  }
  cout << calcIntegral(a, 1) << " (Simpson's Rule) or " << calculateFTC()
       << " (FTC)" << endl;
}
