#pragma once

#include <iostream>
#include <mysql.h>
#include <string.h>

using namespace std;

class MySQLDB{
public:
	MySQLDB::MySQLDB() {

	}

	MySQLDB::~MySQLDB() {

	}
	
	static void menu();
	static int emaile(char s[]);
	static void adminmenu(MYSQL* conn);
	static void usermenu();
	static void start();
	static void modusermenu(MYSQL* conn);
	static void login();
	static void keszitok();
	static int admine(MYSQL* conn, string query);
	static void adduser(MYSQL* conn);
	static void deluser(MYSQL* conn);
	static int lekerdez(MYSQL* conn, string query, string mit);
	static int modositmail(MYSQL* conn, string mit, string mire);
	static int modositpass(MYSQL* conn, string mit, string mire);
	static int modositjog(MYSQL* conn, string mit, string mire);
	static int torol(MYSQL* conn, string kit);
	static void modperm(MYSQL* conn);
	static void modmail(MYSQL* conn);
	static void modpass(MYSQL* conn);
	static int rogzit(MYSQL* conn, string email, string jelszo, char admin);

private:
	
};

