#include <fstream>
#include <iostream>
using namespace std;
namespace iofiles{
void handle_openv_error(int errvar){
    if(errvar == 0){
        cout<<"No error."<<endl;
    }
    else if(errvar == 1){
        cout<<"Only accept \"w\" and \"wb\" modes."<<endl;
    }
    else if (errvar == 3)
    {
        cout<<"Only accept \"r\" and \"rb\" modes."<<endl;
    }
    else if(errvar == 2){
        cout<<"Fail opening file."<<endl;
    }
    else{
        cout<<"Unknown error."<<endl;
    }

}

class openv{
    private:
        string file = "";
    public:
        openv(string);
        void write(string,string,int&);
        string read(string,int&);

};
openv::openv(string _file){
    file = _file;
}
void openv::write(string data,string mode,int &errvar){
    ofstream filevar;
    if(mode == "w"){
        filevar.open(file.c_str(),ios::out);
    }
    else if(mode == "wb"){
		filevar.open(file,ios::binary);
	}
    else{
        errvar = 1;
        return;
    }
    if(filevar.fail()){
		errvar = 2;
        return;
    }
    errvar = 0;
    filevar<<data;
    filevar.close();
}
string openv::read(string mode,int &errvar){
    ifstream filevar;
	if(mode == "r"){
	    filevar.open(file,ios::in); 
	}
	else if(mode == "rb"){
		filevar.open(file,ios::binary);	 
	}
	else{
        errvar = 3;
		return "";
	}
    if(filevar.fail()){
		errvar = 2;
        return "";
    }
    string lines;	
	while(!filevar.eof()){
		string cline;
		getline(filevar, cline);
		cline += "\n";
		lines += cline;
	}
	filevar.close();
    errvar = 0;
	return lines;
}


}