#include "KeyFunctions.h"
#include "DBconnection.h"
#include <mysql.h>
#include <iostream>
#include <string>
using namespace std;

void KeyFunctions::connection() {

	DBconnection db;
		string query = "SELECT * FROM keyFun";
		const char* q = query.c_str();
		db.qstate = mysql_query(db.conn, q);
		if (!db.qstate) {
			db.res = mysql_store_result(db.conn);
			while (db.row = mysql_fetch_row(db.res)) {
				printf("Key: %s- %s\t\n", db.row[0], db.row[1], db.row[2], db.row[3], db.row[4], db.row[5], db.row[6], db.row[7], db.row[8], db.row[9], db.row[10]);
			}
		} else {
			cout << "Query failed: " << mysql_error(db.conn) << endl;
		}

	}