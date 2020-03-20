#include "DBconnection.h"
#include <string>
#include <iostream>
/* Connetcing to database server*/
using namespace std;

DBconnection::DBconnection() {

	conn = mysql_init(0);

	conn = mysql_real_connect(conn, "localhost", "agata", "DanonkI09", "roguelike", 3306, NULL, 0);

	if (conn) {
		puts("Successful connection to databse");
	}
	else {
		puts("Connection to database failed");
	}
}

// adding username to database
void DBconnection::add_username(string username)
{
	string query = "INSERT INTO scores(username) VALUUES (\"" + username + "\")";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);

	if (!qstate) {
		res = mysql_store_result(conn);
	}
	else {
		cout << "Query failed: " << mysql_error(conn) << endl;
	}
}

// displaying key funcions to the player
void DBconnection::key_functions() {
	string query = "SELECT * FROM keyFun";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q); 
	if (!qstate) {
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res)) {
			printf("Key: %s- %s\t\n", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8], row[9], row[10]);
		}
	}
	else {
		cout << "Query failed: " << mysql_error(conn) << endl;
	}
}