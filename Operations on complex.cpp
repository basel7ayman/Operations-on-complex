#include <iostream>
#include <stdexcept>

using namespace std;

class Complex {
  double real;
  double img;

 public:
  Complex(double real = 0, double img = 0) {
    this->real = real;
    this->img = img;
  }
  double getReal() const { return real; }

  double getImg() const { return img; }

  void setComplex(double real, double img) {
    this->real = real;
    this->img = img;
  }

  void getComplex() const {
    if (real == 0 && img == 0) {
      cout << 0 << endl;
      return;
    }

    if (real != 0) {
      cout << real;
    }

    if (img != 0) {
      if (img > 0 && real != 0) {
        cout << "+";
      }
      if (img == 1) {
        cout << "j";
      } else if (img == -1) {
        cout << "-j";
      } else {
        cout << img << "j";
      }
    }
    cout << endl;
  }

  //* ======================= + operator =======================

  Complex operator+(const Complex& other) const {
    return Complex(this->real + other.real, this->img + other.img);
  }
  Complex operator+(int x) const { return Complex(this->real + x, this->img); }

  //* ======================= - operator =======================

  Complex operator-(const Complex& other) const {
    return Complex(this->real - other.real, this->img - other.img);
  }
  Complex operator-(int x) const { return Complex(this->real - x, this->img); }

  //* ======================= * operator =======================

  //! (a + bj) * (c + dj) = [ac + (-bd)]  +  (ad + bc)j

  Complex operator*(const Complex& other) const {
    double a = this->real;
    double b = this->img;
    double c = other.real;
    double d = other.img;

    double mulRl;
    double mulImg;

    mulRl = (a * c) - (b * d);
    mulImg = (a * d) + (b * c);

    return Complex(mulRl, mulImg);
  }
  Complex operator*(double x) const {
    return Complex(this->real * x, this->img * x);
  }

  //* ======================= / operator =======================

  //! (a + bj) / (c + dj) = ([ac + bd] / [c^2 + d^2])  +  ([bc - ad] / [c^2 +
  //! d^2])j

  Complex operator/(const Complex& other) const {
    double a = this->real;
    double b = this->img;
    double c = other.real;
    double d = other.img;

    double divRl;
    double divImg;

    double denominator = ((c * c) + (d * d));

    if (denominator == 0) {
      throw invalid_argument("Division by zero");
    }

    divRl = ((a * c) + (b * d)) / denominator;
    divImg = ((b * c) - (a * d)) / denominator;

    return Complex(divRl, divImg);
  }
  Complex operator/(double x) const {
    if (x == 0) {
      throw invalid_argument("Division by zero");
    }
    return Complex(this->real / x, this->img / x);
  }
};

int main() {
  Complex c4;
  Complex c1(1, 2);
  Complex c2(7, 5);
  Complex c3(2, 3);
  Complex c5(0, 0);

  cout << "================================================" << endl;
  c4.setComplex(1, -1);
  c4.getComplex();
  cout << "================================================" << endl << endl;
  cout << "================================================" << endl;
  c4 = c2 * c1;
  c4.getComplex();
  cout << "================================================" << endl << endl;
  cout << "================================================" << endl;
  c4 = c2 / c1;
  c4.getComplex();
  cout << "================================================" << endl;

  return 0;
}