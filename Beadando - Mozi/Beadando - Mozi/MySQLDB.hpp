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
	static void loginmenu();
	static void login();
	static void keszitok();
	static void start();
	static int adduser();
	static int moduser();
	static int deluser();

private:
	
};

