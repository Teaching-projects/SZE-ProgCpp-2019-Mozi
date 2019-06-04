#include "MySQLDB.hpp"

int qstate;

void MySQLDB::menu() {
	char choice;
	int ok = 0;

	puts("K�rem v�lasszon az al�bbi men�pontok k�z�l:\n");
	puts("1: Bejelentkez�s");
	puts("2: K�sz�t�k");
	puts("3: Kil�p�s");

	do {
		printf("\nA v�lasztott men�pont: ");
		cin >> choice;
		if (choice == '1') {
			login();
			ok = 1;
		}
		else if (choice == '2') {
			keszitok();
			ok = 1;
		}
		else if (choice == '3') {
			exit;
			ok = 1;
		}
		else
			puts("�rv�nytelen karakter!");
	} while (!ok);
}

void MySQLDB::loginmenu() {
	char choice;
	int ok = 0;

	puts("K�rem v�lasszon az al�bbi men�pontok k�z�l:\n");
	puts("1: Program ind�t�sa");
	puts("2: Felhaszn�l� hozz�ad�sa");
	puts("3: Felhaszn�l� m�dos�t�sa");
	puts("4: Felhaszn�l� t�rl�se");
	puts("5: Kijelentkez�s");

	do {
		printf("A v�lasztott men�pont: ");
		cin >> choice;
		if (choice == '1') {
			start();
			ok = 1;
		}
		else if (choice == '2') {
			adduser();
			ok = 1;
		}
		else if (choice == '3') {
			moduser();
			ok = 1;
		}
		else if (choice == '4') {
			deluser();
			ok = 1;
		}
		else if (choice == '5') {
			menu();
			ok = 1;
		}
		else
			puts("�rv�nytelen karakter!\n");
	} while (!ok);
}

void MySQLDB::login() {
	MYSQL* conn;

	puts("Kapcsol�d�s az adatb�zishoz...");
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "root", "MOZI", 3306, NULL, 0);

	if (conn) {
		puts("Sikeres kapcsol�d�s!");
		MYSQL_ROW row;
		MYSQL_RES *res;
		char user[255];
		string user2;
		string query;
		const char* q;
		int megvan = 0;
		int ok = 0;
		int ok1 = 0;
		int kilep = 0;

		do {
			printf("E-mail c�m: ");
			cin >> user;
			user2 = user;
			query = "SELECT email FROM login";
			q = query.c_str();
			qstate = mysql_query(conn, q);
			if (!qstate) {
				res = mysql_store_result(conn);
				while ((row = mysql_fetch_row(res)) && !megvan) {
					if (user2.compare(row[0]) == 0)
						megvan = 1;
				}
			}
			else
				puts("Hiba a lek�rdez�s sor�n!");
			if (user2.compare("EXIT") == 0 || user2.compare("exit") == 0) {
				ok = 1;
				ok1 = 1;
				kilep = 1;
			}
			else if (!megvan)
				puts("Nem l�tezik ilyen E-mail c�m!");
			else {
				ok = 1;
				char pass[33];
				string pass2;
				do {
					megvan = 0;
					printf("Jelsz�: ");
					cin >> pass;
					pass2 = pass;
					query = "SELECT jelszo FROM login WHERE email = '" + user2 + "' ";
					q = query.c_str();
					qstate = mysql_query(conn, q);
					if (!qstate) {
						res = mysql_store_result(conn);
						row = mysql_fetch_row(res);
						if (pass2.compare(row[0]) == 0)
							megvan = 1;
					}
					else
						puts("Hiba a lek�rdez�s sor�n!");
					if (pass2.compare("EXIT") == 0 || pass2.compare("exit") == 0) {
						ok1 = 1;
						kilep = 1;
					}
					if (!megvan)
						puts("Hib�s jelsz�!");
					else {
						ok1 = 1;


						//itt k�ne egy admin-e vagy sem, azt�n adminloginmenu, userloginmenu ennek megfelel�en.
					}
				} while (!ok1);
			}
		} while (!ok && !ok1);

		if (kilep)
			menu();
		else {
			puts("Sikeres bejelentkez�s!");
		}
	}
	else {
		puts("Sikertelen kapcsol�d�s.\n");
	}








	loginmenu();
}

void MySQLDB::keszitok() {
	puts("K�sz�tett�k:\n");
	puts("Orb�n M�t� - FL8F6V");
	puts("Szekendi Bal�zs - FBET1V");
	puts("Zsigmond Rich�rd Tam�s - PJ92ND");
	puts("\nVisszat�r�s a f�men�be.");
	menu();
}

void MySQLDB::start() {
	puts("start");
}

int MySQLDB::adduser() {
	return 0;
}

int MySQLDB::moduser() {
	return 0;
}

int MySQLDB::deluser() {
	return 0;
}
