#include "KeyFunctions.h"
#include "DBconnection.h"
#include "Screen.h"
#include <mysql.h>
#include <conio.h>
#include <iostream>
#include <string>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_END 79

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
				printf("Key: %s- %s\t\n", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8], row[9], row[10]);
			}
		} else {
			cout << "Query failed: " << mysql_error(conn) << endl;
		}
	} else {
		puts("Connection to database failed");
		}
	}

void KeyFunctions::movement() {
	gotoxy(x, y);
	cout << player << endl;
	
	while (inp) {
		char move = _getch(); // keyboard response
		switch (move) {
		case KEY_UP:
			clear();
			y = y - 1;
			gotoxy(x, y);
			cout << player;
			break;
		case KEY_DOWN:
			clear();
			y = y + 1;
			gotoxy(x, y);
			cout << player;
			break;
		case KEY_LEFT:
			clear();
			x = x - 1;
			gotoxy(x, y);
			cout << player;
			break;
		case KEY_RIGHT:
			clear();
			x = x + 1;
			gotoxy(x, y);
			cout << player;
			break;
		case KEY_END:
			inp = false;
		}
	}
}

void KeyFunctions::clear() {
	gotoxy(x, y);
	cout << " ";
}