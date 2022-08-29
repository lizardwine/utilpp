#include <iostream>
#include <vector>

using namespace std;

class print{
    public:
        print(const char *toPrint,string end = "\n"){
            cout << toPrint<<end;
        }
        print(string toPrint,string end = "\n"){
            cout << toPrint<<end;
        }
        print(float toPrint,string end = "\n"){
            cout << toPrint<<end;
        }
        print(double toPrint,string end = "\n"){
            cout << toPrint<<end;
        }
        print(int toPrint,string end = "\n"){
            cout << toPrint<<end;
        }
        print(unsigned int toPrint,string end = "\n"){
            cout << toPrint<<end;
        }
        print(unsigned long toPrint,string end = "\n"){
            cout << toPrint<<end;
        }
        print(long toPrint,string end = "\n"){
            cout << toPrint<<end;
        }
        print(long long toPrint,string end = "\n"){
            cout << toPrint<<end;
        }
        print(unsigned long long toPrint,string end = "\n"){
            cout << toPrint<<end;
        }
        print(long double toPrint,string end = "\n"){
            cout << toPrint<<end;
        }
        print(short toPrint,string end = "\n"){
            cout << toPrint<<end;
        }
        print(unsigned short toPrint,string end = "\n"){
            cout << toPrint<<end;
        }
        
       

};