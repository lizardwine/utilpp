//sudo apt-get install libmysql++-dev
//g++ databases.cpp -lmysqlclient

#include <iostream>
#include <string>
#include <cassert>
#include <map>
#include "./resource/include/mysql.h"

using namespace std;

MYSQL* databases(string host, string username, string password, string dbName, int port) {
	MYSQL *conn;

	conn = mysql_init(0);
	conn = mysql_real_connect(conn, host.c_str(), username.c_str(), password.c_str(), dbName.c_str(), port, NULL, 0);

	return conn;
}

bool insert(MYSQL* conn, string query) {
	if(!mysql_query(conn, query.c_str())) return true;
	else return false;
}

map<int, MYSQL_ROW> query(MYSQL* conn, string query) {
	MYSQL_ROW row;
	MYSQL_RES *res;
	
	int status = mysql_query(conn, query.c_str());
	map<int, MYSQL_ROW> result;

	if(!status) {
		res = mysql_store_result(conn);
		for(int index = 0; row = mysql_fetch_row(res); index++) {
			result.insert({index, row});
			index++;
		}
		
		return result;
	}else  {
		throw("Error");
	}
}


/**
 * Example
 * */


/*
#include <iostream>
#include <string>
#include "./util++/databases/databases.cpp"

using namespace std;

int main(int argc, char const *argv[]){
    string host = "localhost";
    string username = "root";
    string password = "";
    string dbName = "dbname";

    //----------------------Connection----------------------//
    MYSQL* conn = databases(host, username, password, dbName, 0);
    if(&conn) {
        cout << "Connected with success" << endl;
    }else {
        cout << "Failed to connect" << endl;
    }

    //------------------------Insert------------------------//
    string insert_query = "INSERT INTO `usernames` (name) VALUES (\"Jose\");";
    if(!insert(conn, insert_query)) {
        cout << "Error" << endl;
    }else {
        cout << "Correct" << endl;
    }
    
    //-------------------------Read-------------------------//
    string read_query = "SELECT * FROM `usernames`";
    map<int, MYSQL_ROW> read_result = query(conn, read_query);
    cout << read_result[0][1] << endl;

    //-------------------------Find-------------------------//
    string find_query = "SELECT * FROM `usernames` WHERE `id`=1";
    map<int, MYSQL_ROW> find_result = query(conn, find_query);
    cout << find_result[0][1] << endl;


    return 0;
}
*/