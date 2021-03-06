
#include <iostream>
#include <string>

class Complex
{
	private:
		double _real, _img;
	public:
		Complex(double real, double img)
			: _real(real), _img(img) {}
		Complex(const Complex& c)
		{
			_real = c._real;
			_img = c._img;
		}

		Complex operator+(const Complex& c) const;
		Complex operator-(const Complex& c) const;
		Complex operator*(const Complex& c) const;
		Complex operator/(const Complex& c) const;
		
		Complex& operator=(const Complex& c);

		void print()
		{
			std::cout << "( " << _real << " , " << _img << " )" << std:: endl;
		}
};

Complex& Complex::operator=(const Complex& c)
{
	_real = c._real;
	_img = c._img;
	return *this;
}

Complex	Complex::operator+(const Complex& c) const
{
	Complex temp(_real +c._real, _img+c._img);
	return temp;
}

Complex Complex::operator-(const Complex& c)const
{
	Complex temp(_real-c._real, _img-c._img);
	return temp;
}

Complex Complex::operator*(const Complex& c) const {
  Complex temp(_real * c._real - _img * c._img, _real * c._img + _img * c._real);
  return temp;
}

Complex Complex::operator/(const Complex& c) const {
  Complex temp(
    (_real * c._real + _img * c._img) / (c._real * c._real + c._img * c._img),
    (_img * c._real - _real * c._img) / (c._real * c._real + c._img * c._img));
  return temp;
}

int main()
{
	Complex a(1.0, 2.0);
	Complex b(3.0, -2.0);
	Complex d(0.0, 0.0);
	Complex c = a*b;
	
	d = a*b+a / b + a + b;

	d.print();
}

