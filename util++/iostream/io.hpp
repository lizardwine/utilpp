#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


string input(string message){
    cout<<message;
    string var;
    cin>>var;
    return var;
}
int inputI(string message){
    cout<<message;
    int var;
    cin>>var;
    return var;
}
float inputF(string message){
    cout<<message;
    float var;
    cin>>var;
    return var;
}
double inputD(string message){
    cout<<message;
    double var;
    cin>>var;
    return var;
}

const char* inputCCa(string message){
    const char* var = input(message).c_str();
    return var;
}
char inputC(string message){
    cout<<message;
    char var;
    cin>>var;
    return var;
}
char* inputCa(string message){
    cout<<message;
    char* var;
    cin>>var;
    return var;
}
unsigned int inputUI(string message){
    cout<<message;
    unsigned int var;
    cin>>var;
    return var;
}
unsigned long inputUL(string message){
    cout<<message;
    unsigned long var;
    cin>>var;
    return var;
}

long inputL(string message){
    cout<<message;
    long var;
    cin>>var;
    return var;
}

class print{
    public:
        print(const char *toPrint,string end = "\n"){
            cout << toPrint<<end;
        }
	print(char toPrint,string end = "\n"){
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
