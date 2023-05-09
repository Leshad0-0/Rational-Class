#pragma once

#include <iostream>
#include <numeric>
#include <string>

class Rational {
public:
    Rational() = default;

    explicit Rational(int numerator) : numerator_(numerator), denominator_(1) {
    }

    Rational(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) {
        normalize();
    }

    [[nodiscard]] int numerator() const {
        return numerator_;
    }

    [[nodiscard]] int denominator() const {
        return denominator_;
    }

    Rational &operator+=(Rational right) {
        numerator_ = numerator_ * right.denominator() + right.numerator() * denominator_;
        denominator_ *= right.denominator();
        normalize();
        return *this;
    }

    Rational &operator-=(Rational right) {
        numerator_ = numerator_ * right.denominator() - right.numerator() * denominator_;
        denominator_ *= right.denominator();
        normalize();
        return *this;
    }

    Rational &operator*=(Rational right) {
        numerator_ *= right.numerator();
        denominator_ *= right.denominator();
        normalize();
        return *this;
    }

    Rational &operator/=(Rational right) {
        numerator_ *= right.denominator();
        denominator_ *= right.numerator();
        normalize();
        return *this;
    }

private:
    void normalize() {
        if (denominator_ < 0) {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
        const int divisor = std::gcd(numerator_, denominator_);
        numerator_ /= divisor;
        denominator_ /= divisor;
    }

    int numerator_ = 0;
    int denominator_ = 1;
};

std::ostream& operator<<(std::ostream& output, const Rational& r) {
    output << r.numerator() << "/" << r.denominator();
    return output;
}

std::istream& operator>>(std::istream& input, Rational& r) {
    int x, y;
    char c;
    input >> x >> c >> y;
    r = Rational{x, y};
    return input;
}

Rational operator+(Rational left, Rational right) {
    return left += right;
}

Rational operator-(Rational left, Rational right) {
    return left -= right;
}

Rational operator*(Rational left, Rational right) {
    return left *= right;
}

Rational operator/(Rational left, Rational right) {
    return left /= right;
}

Rational operator-(const Rational& rational) {
    return {-rational.numerator(), rational.denominator()};
}

Rational operator+(const Rational& rational) {
    return rational;
}

bool operator==(Rational left, Rational right) {
    return (left.numerator() * right.denominator() == left.denominator() * right.numerator());
}

bool operator!=(Rational left, Rational right) {
    return !(left == right);
}

bool operator<(Rational left, Rational right) {
    return (left.numerator() * right.denominator() < left.denominator() * right.numerator());
}

bool operator>(Rational left, Rational right) {
    return !(left < right);
}

bool operator<=(Rational left, Rational right) {
    return (left.numerator() * right.denominator() <= left.denominator() * right.numerator());
}

bool operator>=(Rational left, Rational right) {
    return !(left <= right);
}