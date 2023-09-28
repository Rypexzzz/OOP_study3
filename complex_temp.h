#pragma once
#include <iostream>
template <typename type>
class complex
{
public:

	complex():re(0), im(0) {}
	complex(type re_inp, type im_inp):re(re_inp), im(im_inp) {}
	complex(complex& obj):re(obj.re), im(obj.im) {}

	void set_re(type x) {
		re = x;
	}
	void set_im(type y) {
		im = y;
	}
	type get_re() {
		return re;
	}
	type get_im() {
		return im;
	}

	complex& operator =(const complex& b) {
		re = b.re;
		im = b.im;
		return *this;
	};

	complex& operator +(const complex& a) {
		complex obr;
		obr.re = a.re + re;
		obr.im = a.im + im;
		return obr;
	};

	complex& operator -(const complex& a) {
		complex obr;
		obr.re = re - a.re;
		obr.im = im - a.im;
		return obr;
	};

	complex& operator *(const complex& a) {
		complex obr;
		obr.re = re * a.re - im * a.im;
		obr.im = re * a.im + im * a.re;
		return obr;
	};

	complex& operator /(const complex& a) {
		complex obr;
		if ((a.re == 0) && (a.im == 0)) throw 1;
		obr.re = (re * a.re + im * a.im) / (a.re * a.re + a.im * a.im);
		obr.im = (a.re * im - re * a.im) / (a.re * a.re + a.im * a.im);
		return obr;
	};

	friend std::ostream& operator<<(std::ostream& out, complex& a) {
		out << "(" << a.re << ", " << a.im << ")";
		return out;
	};


private:
	type re, im;
};

