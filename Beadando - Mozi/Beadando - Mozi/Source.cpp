#include "MySQLDB.hpp"

void main() {
	setlocale(LC_ALL, "");
	system("TITLE MOZI");
	MySQLDB sql;

	sql.menu();
}