#include <iostream>
#include <vector>


class LongInt {
public:
    LongInt();
    LongInt(std::string string);
    LongInt(signed int number);
    LongInt(unsigned int number);
    LongInt(signed long number);
    LongInt(unsigned long number);
    LongInt(signed long long number);
    LongInt(unsigned long long number);
    static std::string to_string(LongInt number);
    friend std::ostream& operator <<(std::ostream& ostream, const LongInt& number);
    friend bool operator ==(LongInt number_first, LongInt number_second);
    friend bool operator !=(LongInt number_first, LongInt number_second);
    friend bool operator >(LongInt number_first, LongInt number_second);
    friend bool operator <(const LongInt& number_first, const LongInt& number_second);
    friend bool operator >=(const LongInt& number_first, const LongInt& number_second);
    friend bool operator <=(const LongInt& number_first, const LongInt& number_second);
    static LongInt abs(LongInt number_first);
    static bool even(LongInt number);
    static bool odd(LongInt number);
    static long long size(LongInt number);
    static LongInt max(LongInt number_first, LongInt number_second);
    static LongInt min(LongInt number_first, LongInt number_second);
    friend LongInt operator +(LongInt number_first, LongInt number_second);
    LongInt operator +=(LongInt number);
    LongInt operator ++();
    LongInt operator ++(int);
    friend LongInt operator -(LongInt number_first, LongInt number_second);
    LongInt operator -=(LongInt number);
    LongInt operator --();
    LongInt operator --(int);
    friend LongInt operator *(const LongInt& number_first, const LongInt& number_second);
    LongInt operator *=(const LongInt& number);
    friend LongInt operator /(LongInt number_first, LongInt number_second);
    LongInt operator /=(LongInt number);
    friend LongInt operator %(LongInt number_first, LongInt number_second);
    LongInt operator %=(LongInt number);
    static LongInt pow(LongInt number_first, LongInt number_second);
    static LongInt factorial(LongInt number);
    static LongInt gcd(LongInt number_first, LongInt number_second);
    static LongInt lcm(LongInt number_first, LongInt number_second);
    static LongInt isqrt(const LongInt& number);
    static LongInt icbrt(LongInt number);
    static LongInt random(long long number_length);
private:
    std::vector<int> _digits;
    bool _sign;
    static const int _base = 1000000000;
    static const int _base_length = 9;
    static const int _length_maximum_for_default_multiply = 128;
    static std::vector<int> _string_convert_to_vector(const std::string& string);
    static LongInt _zeroes_leading_remove(LongInt number);
    static LongInt _shift_right(LongInt number, long long shift_power);
    static LongInt _shift_left(LongInt number, long long shift_power);
    static LongInt _multiply_karatsuba(LongInt number_first, LongInt number_second, bool iteration_thirst);
    static LongInt _factorial_tree(LongInt number_first, const LongInt& number_second);
};


/* Рациональное число, представленное числителем и знаменателем дроби */
class Rational {
public:
    Rational(long n = 0, long d = 1);
    /* Конструктор.
     * Первый агрумент - числитель, второй - знаменатель, по умолчанию
     * равный единице
     */
    Rational(const LongInt &n, const LongInt &d = 1);
    /* Конструктор на основе строки
     * Строка должна содержать либо целое число, которое будет
     * присвоено числителю дроби, либо выражение n / d, где
     * n и d - числитель и знаменатель, целые числа
     */
    Rational(const std::string &s);

    /* Преобразовать дробь в строку n/d */
    static std::string to_string(const Rational &r);

    /* Сократить дробь */
    Rational &normalize();

    Rational &operator+= (const Rational & r);
    Rational &operator-= (const Rational & r);
    Rational &operator*= (const Rational & r);
    Rational &operator/= (const Rational & r);

    friend Rational operator+ (const Rational &a, const Rational &b);
    friend Rational operator- (const Rational &a, const Rational &b);
    friend Rational operator* (const Rational &a, const Rational &b);
    friend Rational operator/ (const Rational &a, const Rational &b);

    Rational pow(LongInt p) const;

    bool operator==(const Rational & r) const;
    bool operator!=(const Rational & r) const;
    bool operator>=(const Rational & r) const;
    bool operator<=(const Rational & r) const;
    bool operator>(const Rational & r) const;
    bool operator<(const Rational & r) const;

    friend std::ostream& operator <<(std::ostream& ostream, const Rational& number);

private:
    LongInt numerator;
    LongInt denominator;
};
