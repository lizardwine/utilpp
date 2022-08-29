#include <sqlite3.h>
#include <iostream>
#include <typeinfo>

using namespace std;

string getSQLiteError(sqlite3 *db)
{
    return sqlite3_errmsg(db);
    
}

class SQLite{
    private:
        sqlite3 *db;
        string database_name = "";

    public:
        SQLite(string);
        int execute(string);
        string execute(string, bool);
        int execute(string, string&);
        string execute(string, string&, bool);
        sqlite3 *get_manager() { return this->db;}
};  
SQLite::SQLite(string _database_name){
    this->database_name = _database_name;
    sqlite3_open(database_name.c_str(), &this->db);
}
int SQLite::execute(string toExecute){
    return sqlite3_exec(db, toExecute.c_str(), nullptr, nullptr, nullptr);
       
}
string SQLite::execute(string toExecute, bool returned) {
    int err = sqlite3_exec(this->db, toExecute.c_str(), nullptr, nullptr, nullptr);
    if (returned == false) {
        if(err != SQLITE_OK){
            cout<<"ERROR: "<<getSQLiteError(this->db)<<endl;
        }
        return "";
    }
    else{
        if(err != SQLITE_OK){
            return getSQLiteError(db);
        }
        return "";
    }
}
string SQLite::execute(string toExecute, string &data, bool returned){
    int err = sqlite3_exec(this->db, toExecute.c_str(), nullptr, data, nullptr);
    if (returned == false) {
        if(err != SQLITE_OK){
            cout<<"ERROR: "<<getSQLiteError(this->db)<<endl;
        }
        return "";
    }
    else{
        if(err != SQLITE_OK){
            return getSQLiteError(db);
        }
        return "";
    }
}