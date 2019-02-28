#include "libvideo/Rational.hpp"

using namespace av;

Rational::Rational()
: m_num(0), m_den(0)
{}

Rational::Rational(int num, int den)
: m_num(num), m_den(den)
{}

Rational::~Rational()
{}


int Rational::num() {
    return m_num;
}

int Rational::den() {
    return m_den;
}

void Rational::num(int num) {
    this->m_num = num;
}

void Rational::den(int den) {
    this->m_den = den;
}