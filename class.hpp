#include <iostream>
//#include <MemoryLeaks>
#include <cstring>
#include <math.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <limits>
#include <vector>
#include <iterator>
using namespace std;

int gcd(int a, int b) ;
/*{
    a = fabs(a);
    b = fabs(b);
    while (a != 0 && b != 0){
        if (a > b)a = a % b;
        else b = b % a;
    }
    return (a + b);
} */

class CRat
{
public:
    vector<int> numerator;
    vector<int> denominator;
    int len;
    CRat() { SetZero(); }
    CRat(int len){this->len = len; }
    virtual ~CRat() { Clean(); }
    void SetZero() { len = 0; }
    void CopyOnly(const CRat& b) { len = b.len; for(int i=0;i<len;i++){numerator.push_back(b.numerator[i]);denominator.push_back(b.denominator[i]);} }
    void InPut(int a,int b){numerator.push_back(a); denominator.push_back(b); len = len + 1;}   
    void SetLen(int len){this->len=len;}
    virtual void Clean() { SetZero(); } 
    CRat(const CRat& b) { CopyOnly(b); }
    CRat& operator = (const CRat& b) { if (this != &b) { Clean(); CopyOnly(b); } return *this; }
    CRat operator +(const CRat& b);
    CRat operator-(const CRat& b);
    double operator*(const CRat& b);
    void reduction();
    static void Input(string& filename, vector<CRat*> &rat);
    friend ostream& operator <<(ostream& cout, const CRat& b);
    virtual void Output(string& filename);
    virtual void Output(){cout<<"\n";}

   };

class CRat1:public CRat{
public:
	string Name;
    CRat1() :CRat() {}
    CRat1(int len) :CRat(len) {}
	void SetName(string &name){this->Name=name;}	
    void Output(string& filename);
	void Output(){Output(Name);}
	~CRat1(){}
};
class CRat2:public CRat{
public:
	string Name;
    CRat2():CRat() {}
    CRat2(int len):CRat(len) {}
	void SetName(string &name){this->Name=name;}
    void Output(string& filename);
	void Output(){Output(Name);}
	~CRat2(){}
};
