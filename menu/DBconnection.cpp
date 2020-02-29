#include "DBconnection.h"
#include <mysql.h>
#include <string>
#include <iostream>
using namespace std;

DBconnection::DBconnection() {

	conn = mysql_init(0);

	conn = mysql_real_connect(conn, "localhost", "agata", "DanonkI09", "roguelike", 3306, NULL, 0);

	if (conn) {
		puts("Successful connection to databse");
	} else {
 puts("Connection to database failed");
	}
}

void DBconnection::key_functions() {
	string query = "SELECT * FROM keyFun";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q); 
	if (!qstate) {
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res)) {
			/*for (int i = 0; i < 11; i++) {
				printf("Key: %s- %s\t\n", row[i]);
			}*/
			printf("Key: %s- %s\t\n", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8], row[9], row[10]);
		}
	}
	else {
		cout << "Query failed: " << mysql_error(conn) << endl;
	}
}

void DBconnection::add_username(string username) {
	string query = "INSERT INTO scores VALUES(username) " + username;
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);

}