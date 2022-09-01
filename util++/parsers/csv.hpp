#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "json.hpp"

using namespace std;
using namespace nlohmann;
namespace csv{
int count(char c, string &str)
{
    int count = 0;

    for (char i : str)
        if (i == c)
            count++;

    return count;
}

class opencsv{
    private:
        string filename;
    public:
        opencsv(const char*);
        vector<vector<string>> read_to_vector(char,bool);
        vector<json> read_to_json(char);

};

opencsv::opencsv(const char* filename_){
    filename = string(filename_);
}

vector<vector<string>> opencsv::read_to_vector(char delimiter,bool ignore_header = false){
    vector<vector<string>> result;
    ifstream file(filename);
    if(ignore_header){
        string line;
        getline(file, line);
    }
    while(!file.eof()){
        vector<string> current_line;
        string line;
        getline(file, line);
        int stop = count(delimiter,line);
        stringstream ss(line);
        for(int i = 0;i<=stop;i++){
            string subline;
            getline(ss, subline,delimiter);
            current_line.push_back(subline);
        }
        result.push_back(current_line);
    }
    file.close();
    return result;
}
vector<json> opencsv::read_to_json(char delimiter){
    vector<vector<string>> csv = read_to_vector(delimiter);
    vector<string> headers = csv[0];
    vector<json> result;
    for(int i=1; i<csv.size();i++){
        json cjson;
        for(int j=0;j<headers.size();j++){
            cjson[headers[j]] = csv[i][j];
        }
        result.push_back(cjson);
    }
    return result;
}  
}
