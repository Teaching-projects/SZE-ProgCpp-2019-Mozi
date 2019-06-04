#pragma once

#include <iostream>
#include <mysql.h>
#undef max

using std::string;

class MySQLDB {
public:
	MySQLDB::MySQLDB() {

	}

	MySQLDB::~MySQLDB() {

	}

	static void menu();

private:
	static int emaile(char s[]);
	static void adminmenu(MYSQL* conn);
	static void usermenu();
	static void modusermenu(MYSQL* conn);
	static void login();
	static void keszitok();
	static void adduser(MYSQL* conn);
	static void deluser(MYSQL* conn);
	static void modperm(MYSQL* conn);
	static void modmail(MYSQL* conn);
	static void modpass(MYSQL* conn);
	static int lekerdezes(MYSQL* conn, string query, bool param);
	static int lekerdezes(MYSQL* conn, string query, string mit);
};
