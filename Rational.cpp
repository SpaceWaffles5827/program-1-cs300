#include "Rational.h"

Rational::Rational() {
    n = 0;
    d = 1;
}

Rational::Rational(int num, int denom) {
    n = num;
    d = denom;
}

Rational::Rational(const Rational& r) {
    n = r.n;
    d = r.d;
}

void Rational::Set(int num, int denom) {
    n = num;
    d = denom;
}

void Rational::Get(int& num, int& denom) const {
    num = n;
    denom = d;
}

bool Rational::isValid() const {
    return d != 0;
}

void Rational::Set(const char* s) {
    int num;
    int denom;
    sscanf(s, "%d/%d", &num, &denom);
    n = num;
    d = denom;
}

Rational& Rational::operator= (const Rational &r) {
    n = r.n;
    d = r.d;
    return *this;
}

bool Rational::operator!= (const Rational &r) const {
    return (*this != r);
}

bool Rational::operator> (const Rational &r) const {
    return n * r.d > d * r.n;
}

bool Rational::operator< (const Rational &r) const {
    return n * r.d < d * r.n;
}

bool Rational::operator>= (const Rational &r) const {
    return n * r.d >= d * r.n;
}

bool Rational::operator<= (const Rational &r) const {
    return n * r.d <= d * r.n;
}

Rational& Rational::operator+= (int i) {
    n += i * d;
    return *this;
}

Rational& Rational::operator-= (int i) {
    n -= i * d;
    return *this;
}

Rational Rational::operator+ (int i) const {
    Rational r(*this);
    r += i;
    return r;
}

Rational Rational::operator- (int i) const {
    Rational r(*this);
    r -= i;
    return r;
}

Rational Rational::operator++ (int) {
    Rational r(*this);
    n += d;
    return r;
}

Rational& Rational::operator++ () {
    n += d;
    return *this;
}

Rational Rational::operator-- (int) {
    Rational r(*this);
    n -= d;
    return r;
}

Rational& Rational::operator-- () {
    n -= d;
    return *this;
}

Rational& Rational::operator+= (const Rational& r) {
    n = n * r.d + d * r.n;
    d *= r.d;
    return *this;
}

Rational& Rational::operator-= (const Rational& r) {
    n = n * r.d - d * r.n;
    d *= r.d;
    return *this;
}

Rational Rational::operator+ (const Rational& r) const {
    Rational result(*this);
    result += r;
    return result;
}

Rational Rational::operator- (const Rational& r) const {
    Rational result(*this);
    result -= r;
    return result;
}

Rational operator+ (int i, const Rational& r) {
    Rational result(r);
    result += i;
    return result;
}

Rational operator- (int i, const Rational& r) {
    Rational result(i, 1);
    result -= r;
    return result;
}

std::ostream& operator<< (std::ostream& os, const Rational &r) {
    os << r.n << "/" << r.d;
    return os;
}

const char* Rational::toString() const {
    static char buf[16];
    printf(buf, "%d/%d", n, d);
    return buf;
}