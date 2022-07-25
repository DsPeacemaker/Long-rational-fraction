#include "LongInt.hpp"


Rational::Rational(long n, long d)
{
    numerator = n;
    denominator = d;

    normalize();//упрощение дроби
}


Rational::Rational(const LongInt &n, const LongInt & d)
{
    numerator = n;
    denominator = d;

    normalize();
}

Rational::Rational(const std::string & s)
{
    int pos = s.find('/');

    if (pos == std::string::npos) {
        numerator = LongInt(s);
        denominator = 1;
    } else {
        numerator = LongInt(s.substr(0, pos));
        denominator = LongInt(s.substr(pos + 1));

        normalize();
    }
}

std::string Rational::to_string(const Rational & r)
{
    if (r.denominator == 1) {
        return LongInt::to_string(r.numerator);
    } else {
        return LongInt::to_string(r.numerator) + std::string("/") + LongInt::to_string(r.denominator);
    }
}

Rational &Rational::normalize()
{
    if (denominator < 0) {
        /* У LongInt нет унарного минуса */
        numerator = numerator * LongInt(-1);
        denominator = denominator * LongInt(-1);
    }

    LongInt g = LongInt::gcd(numerator, denominator);

    if (g > 1) {
        numerator /= g;
        denominator /= g;
    }

    return *this;
}

Rational & Rational::operator+= (const Rational & r)
{
    LongInt n = numerator * r.denominator + denominator * r.numerator;
    LongInt d = denominator * r.denominator;

    numerator = n;
    denominator = d;

    return normalize();
}

Rational & Rational::operator-= (const Rational & r)
{
    LongInt n = numerator * r.denominator - denominator * r.numerator;
    LongInt d = denominator * r.denominator;

    numerator = n;
    denominator = d;

    return normalize();
}

Rational & Rational::operator*= (const Rational & r)
{
    LongInt n = numerator * r.numerator;
    LongInt d = denominator * r.denominator;

    numerator = n;
    denominator = d;

    return normalize();
}

Rational & Rational::operator/= (const Rational & r)
{
    LongInt n = numerator * r.denominator;
    LongInt d = denominator * r.numerator;

    numerator = n;
    denominator = d;

    return normalize();
}

/* Сложение двух рациональных чисел */
Rational operator+ (const Rational & a, const Rational & b)
{
    LongInt n = a.numerator * b.denominator + a.denominator * b.numerator;
    LongInt d = a.denominator * b.denominator;

    return Rational(n, d).normalize();
}

/* Вычитание двух рациональных чисел */
Rational operator- (const Rational & a, const Rational & b)
{
    LongInt n = a.numerator * b.denominator - a.denominator * b.numerator;
    LongInt d = a.denominator * b.denominator;

    return Rational(n, d).normalize();
}

Rational operator* (const Rational & a, const Rational & b)
{
    LongInt n = a.numerator * b.numerator;
    LongInt d = a.denominator * b.denominator;

    return Rational(n, d).normalize();
}

Rational operator/ (const Rational & a, const Rational & b)
{
    LongInt n = a.numerator * b.denominator;
    LongInt d = a.denominator * b.numerator;

    return Rational(n, d).normalize();
}

Rational Rational::pow(LongInt p) const
{
    if (p > 0) {
        return Rational(LongInt::pow(numerator, p), LongInt::pow(denominator, p)).normalize();
    } else {
        p = LongInt(0) - p;
        return Rational(LongInt::pow(denominator, p), LongInt::pow(numerator, p)).normalize();
    }
}

bool Rational::operator== (const Rational & r) const
{
    return numerator * r.denominator == r.numerator * denominator;
}

bool Rational::operator!= (const Rational & r) const
{
    return numerator * r.denominator == r.numerator * denominator;
}

bool Rational::operator>= (const Rational & r) const
{
    return numerator * r.denominator >= r.numerator * denominator;
}

bool Rational::operator<= (const Rational & r) const
{
    return numerator * r.denominator <= r.numerator * denominator;
}

bool Rational::operator> (const Rational & r) const
{
    return numerator * r.denominator > r.numerator * denominator;
}

bool Rational::operator< (const Rational & r) const
{
    return numerator * r.denominator < r.numerator * denominator;
}

std::ostream& operator <<(std::ostream& ostream, const Rational& number)
{
    return ostream << Rational::to_string(number);
}
