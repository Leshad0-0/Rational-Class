#pragma once

#include <sstream>
#include <cassert>

#include "rational.h"

void TestInitialization() {
    std::cout << "TestInitialization" << std::endl;
    Rational r1;
    assert(r1.numerator() == 0 && r1.denominator() == 1);

    Rational r2(5);
    assert(r2.numerator() == 5 && r2.denominator() == 1);

    Rational r3(-10, 2);
    assert(r3.numerator() == -5 && r3.denominator() == 1);

    Rational r4(1, -2);
    assert(r4.numerator() == -1 && r4.denominator() == 2);

    Rational r5(-4, -6);
    assert(r5.numerator() == 2 && r5.denominator() == 3);
    std::cout << "Done!" << std::endl;
}

void TestArithmeticOperations() {
    std::cout << "TestArithmeticOperations" << std::endl;
    Rational r1(1, 3);
    Rational r2(2, 5);

    Rational r3 = r1 + r2;
    assert(r3.numerator() == 11 && r3.denominator() == 15);

    Rational r4 = r1 - r2;
    assert(r4.numerator() == -1 && r4.denominator() == 15);

    Rational r5 = r1 * r2;
    assert(r5.numerator() == 2 && r5.denominator() == 15);

    Rational r6 = r1 / r2;
    assert(r6.numerator() == 5 && r6.denominator() == 6);

    Rational r7(1, 10);
    Rational r8(1, 5);

    Rational r9 = r7 + r8;
    assert(r9.numerator() == 3 && r9.denominator() == 10);

    Rational r10 = r7 - r8;
    assert(r10.numerator() == -1 && r10.denominator() == 10);

    Rational r11 = r7 * r8;
    assert(r11.numerator() == 1 && r11.denominator() == 50);

    Rational r12 = r7 / r8;
    assert(r12.numerator() == 1 && r12.denominator() == 2);

    Rational r13(-4, 7);
    Rational r14(-3, 5);

    Rational r15 = r13 + r14;
    assert(r15.numerator() == -41 && r15.denominator() == 35);

    Rational r16 = r13 - r14;
    assert(r16.numerator() == 1 && r16.denominator() == 35);

    Rational r17 = r13 * r14;
    assert(r17.numerator() == 12 && r17.denominator() == 35);

    Rational r18 = r13 / r14;
    assert(r18.numerator() == 20 && r18.denominator() == 21);
    std::cout << "Done!" << std::endl;
}

void TestUnaryOperators() {
    std::cout << "TestUnaryOperators!" << std::endl;
    Rational r1(3, 5);

    Rational r2 = -r1;
    assert(r2.numerator() == -3 && r2.denominator() == 5);

    Rational r3 = +r1;
    assert(r3.numerator() == 3 && r3.denominator() == 5);

    Rational r4(-1, 3);
    assert(-(-r4) == r4);

    Rational r5(4, 5);
    assert(+r5 == r5);
    std::cout << "Done!" << std::endl;
}

void TestRelationalOperators() {
    std::cout << "TestRelationalOperators!" << std::endl;
    assert(Rational(1, 2) < Rational(3, 4));
    assert(Rational(5, 9) > Rational(1, 3));
    assert(Rational(2, 3) <= Rational(2, 3));
    assert(Rational(4, 5) >= Rational(3, 5));
    assert(Rational(2, 5) != Rational(3, 4));
    assert(Rational(4, 9) == Rational(8, 18));

    assert(Rational(-1, 2) < Rational(-1, 4));
    assert(Rational(-1, 3) > Rational(-5, 9));
    assert(Rational(-2, 3) <= Rational(-2, 3));
    assert(Rational(-3, 5) >= Rational(-4, 5));
    assert(Rational(-2, 5) != Rational(-3, 4));
    assert(Rational(-4, 9) == Rational(-8, 18));

    assert(Rational(-1, 2) < Rational(1, 4));
    assert(Rational(-5, 9) < Rational(1, 3));
    assert(Rational(2, 3) >= Rational(-2, 3));
    assert(Rational(-2, 5) != Rational(-3, 4));
    assert(Rational(-2, 5) != Rational(3, 4));
    assert(Rational(-4, 9) == Rational(8, -18));
    std::cout << "Done!" << std::endl;
}


void TestInputOutputOperations() {
    std::cout << "TestInputOutputOperations!" << std::endl;
    {
        Rational r(2, 3);
        std::ostringstream output;
        output << r;
        assert(output.str() == "2/3");
    }

    {
        std::istringstream input("4/5");
        Rational r;
        input >> r;
        assert(r.numerator() == 4 && r.denominator() == 5);
    }
    std::cout << "Done!" << std::endl;
}