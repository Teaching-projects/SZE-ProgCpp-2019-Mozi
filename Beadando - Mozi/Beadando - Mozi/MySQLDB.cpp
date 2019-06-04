#include "MySQLDB.hpp"

int qstate;

void MySQLDB::menu() {
	char choice;
	int ok = 0;

	puts("Kérem válasszon az alábbi menüpontok közül:\n");
	puts("1: Bejelentkezés");
	puts("2: Készítõk");
	puts("3: Kilépés");

	do {
		printf("\nA választott menüpont: ");
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
			puts("érvénytelen karakter!");
	} while (!ok);
}

void MySQLDB::loginmenu() {
	char choice;
	int ok = 0;

	puts("Kérem válasszon az alábbi menüpontok közül:\n");
	puts("1: Program indítása");
	puts("2: Felhasználó hozzáadása");
	puts("3: Felhasználó módosítása");
	puts("4: Felhasználó törlése");
	puts("5: Kijelentkezés");

	do {
		printf("A választott menüpont: ");
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
			puts("Érvénytelen karakter!\n");
	} while (!ok);
}

void MySQLDB::login() {
	MYSQL* conn;

	puts("Kapcsolódás az adatbázishoz...");
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "root", "MOZI", 3306, NULL, 0);

	if (conn) {
		puts("Sikeres kapcsolódás!");
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
			printf("E-mail cím: ");
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
				puts("Hiba a lekérdezés során!");
			if (user2.compare("EXIT") == 0 || user2.compare("exit") == 0) {
				ok = 1;
				ok1 = 1;
				kilep = 1;
			}
			else if (!megvan)
				puts("Nem létezik ilyen E-mail cím!");
			else {
				ok = 1;
				char pass[33];
				string pass2;
				do {
					megvan = 0;
					printf("Jelszó: ");
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
						puts("Hiba a lekérdezés során!");
					if (pass2.compare("EXIT") == 0 || pass2.compare("exit") == 0) {
						ok1 = 1;
						kilep = 1;
					}
					if (!megvan)
						puts("Hibás jelszó!");
					else {
						ok1 = 1;


						//itt kéne egy admin-e vagy sem, aztán adminloginmenu, userloginmenu ennek megfelelõen.
					}
				} while (!ok1);
			}
		} while (!ok && !ok1);

		if (kilep)
			menu();
		else {
			puts("Sikeres bejelentkezés!");
		}
	}
	else {
		puts("Sikertelen kapcsolódás.\n");
	}








	loginmenu();
}

void MySQLDB::keszitok() {
	puts("Készítették:\n");
	puts("Orbán Máté - FL8F6V");
	puts("Szekendi Balázs - FBET1V");
	puts("Zsigmond Richárd Tamás - PJ92ND");
	puts("\nVisszatérés a fõmenübe.");
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
