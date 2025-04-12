#include "class.hpp"
void test1(){
     CRat a;
     a.InPut(1,2);a.InPut(2,3);a.InPut(3,4);a.InPut(5,6);
     cout << a;
     CRat b;
     b.InPut(1,2);b.InPut(2,3);b.InPut(4,4);b.InPut(1,3);
     cout << b;
     cout << '\n';
     CRat c;
     CRat d;
     double e;
     c = a + b;
     cout <<"+: " <<c << '\n';
     d = a - b;
     cout <<"-: "<< d <<'\n';
     e = a * b;
     cout <<"*: "<< e << '\n';
}
void test2(){
     string InFile;
	 string OutFile;
     vector<CRat*> rat;
     cout << "Enter the name of Input file: ";
     cin >> InFile;
   //  cout << "Enter the name of Output file: ";
   //  cin >> OutFile;  
     CRat::Input(InFile, rat);
     for (size_t i = 0; i < rat.size(); i++){
         rat[i] -> Output();
     } 
     for (size_t i = 0; i < rat.size(); i++) delete rat[i];
}


int main(void){
      test2();
    //  test1();
     return 0;
}

