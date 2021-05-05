class polynomial {
public:
  polynomial();
  polynomial(double exponent, double constant, double coefficient);
  double getExp() const { return exponent; }
  double getConst() const { return constant; }
  double getCoef() const { return coefficient; }

private:
  double coefficient;
  double exponent;
  double constant;
};
