#include "KeyFunctions.h"
#include "DBconnection.h"
#include <mysql.h>
#include <iostream>
#include <string>

using namespace std;

void KeyFunctions::connection() {

	int qstate;
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);

	conn = mysql_real_connect(conn, "localhost", "agata", "DanonkI09", "roguelike", 3306, NULL, 0);

	conn = mysql_init(0);

	conn = mysql_real_connect(conn, "localhost", "agata", "DanonkI09", "roguelike", 3306, NULL, 0);

	if (conn) {
		puts("Successful connection to databse");

		string query = "SELECT * FROM keyFun";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate) {
			res = mysql_store_result(conn);
			while (row = mysql_fetch_row(res)) {
				printf("Key: %s- %s\t\n", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8], row[9], row[10] );
			}
		} else {
			cout << "Query failed: " << mysql_error(conn) << endl;
		}
	} else {
		puts("Connection to database failed");
		}
	}
