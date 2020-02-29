#pragma once
/* Class that deals with database queries*/
//#include <mysql.h>
#include <string>
using namespace std;

class DBconnection
{
	public:
		DBconnection();
		void add_username(string username);
	private:
		void key_functions();
		int qstate;
		/*MYSQL* conn;
		MYSQL_ROW row;
		MYSQL_RES* res;
	*/
	
};

