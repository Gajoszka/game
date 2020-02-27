#pragma once
/* Establishing connection to database*/
#include <mysql.h>
class DBconnection
{
	public:
		DBconnection();
		int qstate;
		MYSQL* conn;
		MYSQL_ROW row;
		MYSQL_RES* res;
};

