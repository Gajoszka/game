#pragma once
#include <mysql.h>
class DBconnection
{
	public:
		DBconnection();
		int qstate;
		MYSQL* conn;
		MYSQL_ROW row;
		MYSQL_RES* res;//ok
};

