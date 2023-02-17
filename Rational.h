#ifndef RATIONAL_NUMBER_H_ 
#define RATIONAL_NUMBER_H_

#include <iostream> 
 
class Rational 
{ 
public: 
 
  Rational(); 
  Rational(int n,int d); 
  Rational(const Rational&); // copy constructor 
  ~Rational() {} 
 
  void Set(int n,int d); 
  void Get(int& n,int& d) const; 
 
  bool isValid() const; 
  void Set(const char*); 
 
  Rational& operator= (const Rational &); // assignment operator    bool  operator== (const Rational &) const; 
  bool  operator!= (const Rational &) const; 
  bool  operator>  (const Rational &) const;   bool  operator<  (const Rational &) const; 
  bool  operator>= (const Rational &) const; 
  bool  operator<= (const Rational &) const;  
  Rational& operator+= (int); 
  Rational& operator-= (int);  
  Rational  operator+  (int) const; 
  Rational  operator-  (int) const;  
  Rational  operator++ (int); 
  Rational& operator++ ();   Rational  operator-- (int); 
  Rational& operator-- ();    Rational& operator+= (const Rational&); 
  Rational& operator-= (const Rational&);    Rational  operator+  (const Rational&) const; 
  Rational  operator-  (const Rational&) const;    friend Rational operator+ (int,const Rational&); 
  friend Rational operator- (int,const Rational&); 
 
  friend std::ostream& operator<< (std::ostream&,const Rational &); 
 
  const char* toString() const; 
 
  operator const char*() { return toString(); } 
 
private: 
 
  int  n,d; // numerator, denominator 
 
}; 
 
#endif 