#include "MySQLDB.hpp"

int qstate;

void MySQLDB::menu() {
	char choice;
	bool ok = 0;

	system("cls");
	puts("K�rem v�lasszon az al�bbi men�pontok k�z�l:\n");
	puts("1: Bejelentkez�s");
	puts("2: Demo �zemm�d (login n�lk�l)");
	puts("3: K�sz�t�k");
	puts("4: Kil�p�s");

	do {
		std::cout << "\nA v�lasztott men�pont: ";
		std::cin >> choice;
		if (choice == '1') {
			login();
			ok = 1;
		}
		else if (choice == '2') {
			start();
			ok = 1;
		}
		else if (choice == '3') {
			keszitok();
			ok = 1;
		}
		else if (choice == '4') {
			exit;
			ok = 1;
		}
		else
			puts("�rv�nytelen karakter!");
	} while (!ok);
}

void MySQLDB::login() {
	MYSQL* conn;

	system("CLS");
	puts("Kapcsol�d�s az adatb�zishoz...");
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "root", "MOZI", 3306, NULL, 0);

	if (conn) {
		puts("Sikeres kapcsol�d�s!\n");
		char user[255];
		string user2;
		short megvan = 0;
		bool ok = 0;
		bool ok1 = 0;
		bool kilep = 0;


		do {
			std::cout << "E-mail c�m: ";
			std::cin >> user;
			user2 = user;
			megvan = lekerdez(conn, "SELECT email FROM login", user2);
			if (user2.compare("EXIT") == 0 || user2.compare("exit") == 0) {
				ok = 1;
				ok1 = 1;
				kilep = 1;
			}
			else if (megvan < 0) {
				puts("Hiba a felhaszn�l� lek�rdez�se sor�n!");
				mysql_close;
				puts("Visszat�r�s a f�men�be 5 m�sodperc m�lva.");
				system("TIMEOUT /T 5");
			}
			else if (!megvan)
				puts("Nem l�tezik ilyen E-mail c�m!");
			else {
				ok = 1;
				char pass[33];
				string pass2;
				do {
					megvan = 0;
					std::cout << "Jelsz�: ";
					std::cin >> pass;
					pass2 = pass;
					megvan = lekerdez(conn, "SELECT jelszo FROM login WHERE email = '" + user2 + "'", pass2);
					if (pass2.compare("EXIT") == 0 || pass2.compare("exit") == 0) {
						ok1 = 1;
						kilep = 1;
					}
					else if (megvan < 0) {
						puts("Hiba a jelsz� lek�rdez�se sor�n!");
						mysql_close;
						puts("Visszat�r�s a f�men�be 5 m�sodperc m�lva.");
						system("TIMEOUT /T 5");
					}
					else if (!megvan)
						puts("Hib�s jelsz�!");
					else {
						ok1 = 1;
						megvan = admine(conn, "SELECT admin FROM login WHERE email = '" + user2 + "' AND jelszo = '" + pass2 + "'");
					}
				} while (!ok1);
			}
		} while (!ok && !ok1);

		if (kilep)
			menu();
		else {
			system("CLS");
			puts("Sikeres bejelentkez�s!\n");
			if (!megvan) {
				mysql_close;
				usermenu();
			}
			else if (megvan < 0) {
				puts("Sikertelen admin lek�rdez�s!");
				mysql_close;
				puts("Visszat�r�s a f�men�be 5 m�sodperc m�lva.");
				system("TIMEOUT /T 5");
			}
			else {
				adminmenu(conn);
			}
		}
	}
	else {
		puts("Sikertelen kapcsol�d�s.\n");
	}
}

void MySQLDB::start() {
	puts("start");
}

void MySQLDB::keszitok() {
	system("CLS");
	puts("K�sz�tett�k:\n");
	puts("Orb�n M�t� - FL8F6V");
	puts("Szekendi Bal�zs - FBET1V");
	puts("Zsigmond Rich�rd Tam�s - PJ92ND");
	puts("\nVisszat�r�s a f�men�be 10 m�sodperc m�lva.");
	system("TIMEOUT /T 10");
	menu();
}

void MySQLDB::adminmenu(MYSQL* conn) {
	char choice;
	bool ok = 0;

	system("CLS");
	puts("K�rem v�lasszon az al�bbi men�pontok k�z�l:\n");
	puts("1: Program ind�t�sa");
	puts("2: Felhaszn�l� hozz�ad�sa");
	puts("3: Felhaszn�l� m�dos�t�sa");
	puts("4: Felhaszn�l� t�rl�se");
	puts("5: Kijelentkez�s");

	do {
		std::cout << "A v�lasztott men�pont: ";
		std::cin >> choice;
		if (choice == '1') {
			start();
			ok = 1;
		}
		else if (choice == '2') {
			adduser(conn);
			ok = 1;
		}
		else if (choice == '3') {
			modusermenu(conn);
			ok = 1;
		}
		else if (choice == '4') {
			deluser(conn);
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

void MySQLDB::usermenu() {
	char choice;
	bool ok = 0;

	puts("K�rem v�lasszon az al�bbi men�pontok k�z�l:\n");
	puts("1: Program ind�t�sa");
	puts("2: Kijelentkez�s");

	do {
		std::cout << "A v�lasztott men�pont: ";
		std::cin >> choice;
		if (choice == '1') {
			start();
			ok = 1;
		}
		else if (choice == '2') {
			menu();
			ok = 1;
		}
		else
			puts("�rv�nytelen karakter!\n");
	} while (!ok);
}

void MySQLDB::modusermenu(MYSQL* conn) {
	char choice;
	bool ok = 0;

	system("CLS");
	puts("Felhaszn�l� m�dos�t�sa\n");
	puts("1: E-mail c�m m�dos�t�sa");
	puts("2: Jelsz� m�dos�t�sa");
	puts("3: Jogosults�g m�dos�t�sa");
	puts("4: Vissza az admin men�be");

	do {
		std::cout << "A v�lasztott men�pont: ";
		std::cin >> choice;
		if (choice == '1') {
			modmail(conn);
			ok = 1;
		}
		else if (choice == '2') {
			modpass(conn);
			ok = 1;
		}
		else if (choice == '3') {
			modperm(conn);
			ok = 1;
		}
		else if (choice == '4') {
			adminmenu(conn);
			ok = 1;
		}
		else
			puts("�rv�nytelen karakter!");
	} while (!ok);
}

void MySQLDB::modmail(MYSQL* conn) {
	char user[255];
	string user2;
	short megvan = 0;
	bool ok = 0;

	system("CLS");
	std::cout << "Adja meg a m�dos�tand� felhaszn�l� E-mail c�m�t: ";
	std::cin >> user;
	user2 = user;
	megvan = lekerdez(conn, "SELECT email FROM login", user2);
	if (megvan < 0) {
		puts("Hiba a felhaszn�l� lek�rdez�se sor�n!");
		mysql_close;
		puts("Visszat�r�s a felhaszn�l� m�dos�t�sa men�be 5 m�sodperc m�lva.");
		system("TIMEOUT /T 5");
	}
	else if (!megvan)
		puts("Nem tal�lhat� ilyen felhaszn�l�!");
	else {
		do {
			std::cout << "Az �j E-mail c�m: ";
			char newuser[255];
			string newuser2;
			std::cin >> newuser;
			newuser2 = newuser;
			if (!emaile(newuser))
				std::cout << "Hiba: ";
			else {
				ok = 1;
				megvan = modositmail(conn, user2, newuser2);
			}
		} while (!ok);
	}

	system("CLS");
	if (!megvan) {
		puts("Sikertelen m�dos�t�s");
		mysql_close;
		puts("Visszat�r�s a felhaszn�l� m�dos�t�sa men�be 5 m�sodperc m�lva.");
		system("TIMEOUT /T 5");
	}
	else if (megvan < 0) {
		puts("Sikertelen m�dos�t�s (lek�rdez�s hiba)!");
		mysql_close;
		puts("Visszat�r�s a felhaszn�l� m�dos�t�sa men�be 5 m�sodperc m�lva.");
		system("TIMEOUT /T 5");
	}
	else {
		puts("Sikeres m�dos�t�s!");
		system("TIMEOUT /T 2");
		modusermenu(conn);
	}
	mysql_close;
}

void MySQLDB::modpass(MYSQL* conn) {
	char user[255];
	string user2;
	short megvan = 0;
	bool ok = 0;
	bool ok1 = 0;

	system("CLS");
	std::cout << "Adja meg a m�dos�tand� felhaszn�l� E-mail c�m�t: ";
	std::cin >> user;
	user2 = user;
	megvan = lekerdez(conn, "SELECT email FROM login", user2);
	if (megvan < 0) {
		puts("Hiba a felhaszn�l� lek�rdez�se sor�n!");
		puts("Visszat�r�s a felhaszn�l� m�dos�t�sa men�be 5 m�sodperc m�lva.");
		system("TIMEOUT /T 5");
		modusermenu(conn);
	}
	else if (!megvan) {
		puts("Nem tal�lhat� ilyen felhaszn�l�!");
		puts("Visszat�r�s a felhaszn�l� m�dos�t�sa men�be 5 m�sodperc m�lva.");
		system("TIMEOUT /T 5");
		modusermenu(conn);
	}
	else {
		do {
			std::cout << "Adja meg a m�dos�tand� felhaszn�l� r�gi jelszav�t: ";
			char oldpass[33];
			string oldpass2;
			std::cin >> oldpass;
			oldpass2 = oldpass;
			megvan = lekerdez(conn, "SELECT jelszo FROM login WHERE email = '" + user2 + "'", oldpass2);
			if (megvan < 0) {
				puts("Hiba a r�gi jelsz� lek�rdez�se sor�n!");
				puts("Visszat�r�s a felhaszn�l� m�dos�t�sa men�be 5 m�sodperc m�lva.");
				system("TIMEOUT /T 5");
				modusermenu(conn);
			}
			else if (!megvan) {
				puts("Helytelen jelsz�!");
			}
			else {
				ok = 1;
				std::cout << "Az �j jelsz�: ";
				char newpass[33];
				string newpass2;
				std::cin >> newpass;
				newpass2 = newpass;
				megvan = modositpass(conn, oldpass2, newpass2);
			}
		} while (!ok);
	}

	system("CLS");
	if (!megvan) {
		puts("Sikertelen m�dos�t�s");
		puts("Visszat�r�s a felhaszn�l� m�dos�t�sa men�be 5 m�sodperc m�lva.");
		system("TIMEOUT /T 5");
		modusermenu(conn);
	}
	else if (megvan < 0) {
		puts("Sikertelen m�dos�t�s (lek�rdez�s hiba)!");
		puts("Visszat�r�s a felhaszn�l� m�dos�t�sa men�be 5 m�sodperc m�lva.");
		system("TIMEOUT /T 5");
		modusermenu(conn);
	}
	else {
		puts("Sikeres m�dos�t�s!");
		system("TIMEOUT /T 2");
		modusermenu(conn);
	}
	mysql_close;
}

void MySQLDB::modperm(MYSQL* conn) {
	char user[255];
	string user2;
	short megvan = 0;
	bool ok = 0;
	bool ok1 = 0;

	system("CLS");
	std::cout << "Adja meg a m�dos�tand� felhaszn�l� E-mail c�m�t: ";
	std::cin >> user;
	user2 = user;
	megvan = lekerdez(conn, "SELECT email FROM login", user2);
	if (megvan < 0) {
		puts("Hiba a felhaszn�l� lek�rdez�se sor�n!");
		system("TIMEOUT /T 3");
		modusermenu(conn);
	}
	else if (!megvan) {
		puts("Nem tal�lhat� ilyen felhaszn�l�!");
		system("TIMEOUT /T 3");
		modusermenu(conn);
	}
	else {
		do {
			std::cout << "Adja meg a m�dos�tand� felhaszn�l� jelszav�t: ";
			char pass[33];
			string pass2;
			std::cin >> pass;
			pass2 = pass;
			megvan = lekerdez(conn, "SELECT jelszo FROM login WHERE email = '" + user2 + "'", pass2);
			if (megvan < 0) {
				puts("Hiba a jelsz� lek�rdez�se sor�n!");
				puts("Visszat�r�s a felhaszn�l� m�dos�t�sa men�be 5 m�sodperc m�lva.");
				system("TIMEOUT /T 5");
				modusermenu(conn);
			}
			else if (!megvan) {
				puts("Helytelen jelsz�!");
			}
			else {
				ok = 1;
				do {
					std::cout << "Adja meg az �j jogosults�got! [0 - User, 1 - Admin]: ";
					char admin[5];
					std::cin >> admin;
					if (strlen(admin) != 1)
						puts("Csak egy karaktert adhat meg!");
					if (!((admin[0] == '0') || (admin[0] == '1')))
						puts("Nem megengedett karakter!");
					else {
						ok1 = 1;
						megvan = modositjog(conn, user2, admin);
					}
				} while (!ok1);
			}
		} while (!ok);
	}

	system("CLS");
	if (!megvan) {
		puts("Sikertelen m�dos�t�s");
		puts("Visszat�r�s a felhaszn�l� m�dos�t�sa men�be 5 m�sodperc m�lva.");
		system("TIMEOUT /T 5");
		modusermenu(conn);
	}
	else if (megvan < 0) {
		puts("Sikertelen m�dos�t�s (lek�rdez�s hiba)!");
		puts("Visszat�r�s a felhaszn�l� m�dos�t�sa men�be 5 m�sodperc m�lva.");
		system("TIMEOUT /T 5");
		modusermenu(conn);
	}
	else {
		puts("Sikeres m�dos�t�s!");
		system("TIMEOUT /T 5");
		modusermenu(conn);
	}
	mysql_close;
}

void MySQLDB::adduser(MYSQL* conn) {
	char email[255];
	string email2;
	bool ok = 0;
	bool ok1 = 0;
	bool ok2 = 0;
	short megvan;
	bool megsem = 0;

	system("CLS");
	puts("Felhaszn�l� hozz�ad�sa\n");

	do {
		std::cout << "E-mail c�m: ";
		std::cin >> email;
		if (!emaile(email))
			std::cout << "Hiba: ";
		else {
			email2 = email;
			megvan = lekerdez(conn, "SELECT email FROM login", email2);
			if (email2.compare("CANCEL") == 0 || email2.compare("cancel") == 0) {
				ok = 1;
				ok1 = 1;
				ok2 = 1;
				megsem = 1;
			}
			else if (megvan < 0) {
				puts("Hiba a felhaszn�l� lek�rdez�se sor�n!");
				mysql_close;
				puts("Visszat�r�s az adminmen�be 5 m�sodperc m�lva.");
				system("TIMEOUT /T 5");
				adminmenu(conn);
			}
			else if (megvan > 0) {
				puts("M�r tal�lhat� ilyen felhaszn�l�!");
			}
			else {
				ok = 1;
				char pass[33];
				string pass2;
				do {
					std::cout << "Jelsz�: ";
					std::cin >> pass;
					pass2 = pass;
					if (pass2.compare("CANCEL") == 0 || pass2.compare("cancel") == 0) {
						ok1 = 1;
						ok2 = 1;
						megsem = 1;
					}
					else {
						ok1 = 1;
						do {
							char admin[10];
							std::cout << "Admin [0 - Nem, 1 - Igen]: ";
							std::cin >> admin;
							if (strcmp(admin, "CANCEL") == 0 || strcmp(admin, "cancel") == 0) {
								ok1 = 1;
								ok2 = 1;
								megsem = 1;
							}
							else if (strlen(admin) != 1)
								puts("Csak egy karaktert adhat meg!");
							else if (!((admin[0] == '0') || (admin[0] == '1')))
								puts("Nem megengedett karakter!");
							else {
								ok2 = 1;
								megvan = rogzit(conn, email2, pass2, admin[0]);
							}
						} while (!ok2);
					}
				} while (!ok1);
			}
		}
	} while (!ok && !ok1 && !ok2);

	if (megsem) {
		adminmenu(conn);
	}
	else {
		if (megvan == -1) {
			puts("Sikertelen r�gz�t�s(lek�rdez�s hiba)!");
			puts("Visszat�r�s az adminmen�be 5 m�sodperc m�lva.");
			system("TIMEOUT /T 5");
			adminmenu(conn);
		}
		else if (megvan == 0) {
			puts("Sikertelen lek�rdez�s!");
			puts("Visszat�r�s az adminmen�be 5 m�sodperc m�lva.");
			system("TIMEOUT /T 5");
			adminmenu(conn);
		}
		else {
			puts("Sikeres r�gz�t�s!");
			system("TIMEOUT /T 2");
			adminmenu(conn);
		}
	}
	mysql_close;
}

void MySQLDB::deluser(MYSQL* conn) {
	short megvan;
	bool ok = 0;
	bool megsem = 0;

	system("CLS");
	do {
		std::cout << "Adja meg a t�r�lni k�v�nt felhaszn�l�nevet: ";
		char user[255];
		string user2;
		std::cin >> user;
		user2 = user;
		megvan = lekerdez(conn, "SELECT email FROM login", user2);
		if (user2.compare("CANCEL") == 0 || user2.compare("cancel") == 0) {
			ok = 1;
			megsem = 1;
		}
		else if (megvan < 0) {
			puts("Hiba a felhaszn�l� lek�rdez�se sor�n!");
			mysql_close;
			puts("Visszat�r�s az adminmen�be 5 m�sodperc m�lva.");
			system("TIMEOUT /T 5");
			adminmenu(conn);
		}
		else if (megvan == 0) {
			puts("Nem tal�lhat� ilyen felhaszn�l�!");
		}
		else {
			ok = 1;
			megvan = torol(conn, user2);
		}
	} while (!ok);

	if (megsem) {
		adminmenu(conn);
	}
	else {
		if (megvan == -1) {
			puts("Sikertelen r�gz�t�s(lek�rdez�s hiba)!");
			puts("Visszat�r�s az adminmen�be 5 m�sodperc m�lva.");
			system("TIMEOUT /T 5");
			adminmenu(conn);
		}
		else if (megvan == 0) {
			puts("Sikertelen lek�rdez�s!");
			puts("Visszat�r�s az adminmen�be 5 m�sodperc m�lva.");
			system("TIMEOUT /T 5");
			adminmenu(conn);
		}
		else {
			puts("Sikeres t�rl�s!");
			system("TIMEOUT /T 2");
			adminmenu(conn);
		}
	}
	mysql_close;
}

int MySQLDB::admine(MYSQL* conn, string query) {
	MYSQL_ROW row;
	MYSQL_RES *res;
	const char* q;

	q = query.c_str();
	qstate = mysql_query(conn, q);
	if (!qstate) {
		res = mysql_store_result(conn);
		row = mysql_fetch_row(res);
		if (!strcmp(row[0], "1"))
			return 1;
		else
			return 0;
	}
	else {
		return -1;
	}
}

int MySQLDB::lekerdez(MYSQL* conn, string query, string mit) {
	MYSQL_ROW row;
	MYSQL_RES *res;
	const char* q;

	q = query.c_str();
	qstate = mysql_query(conn, q);
	if (!qstate) {
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res)) {
			if (mit.compare(row[0]) == 0)
				return 1;
		}
		return 0;
	}
	else {
		return -1;
	}
}

int MySQLDB::modositjog(MYSQL* conn, string mit, string mire) {
	MYSQL_ROW row;
	MYSQL_RES *res;
	const char* q;
	string query = "UPDATE login SET admin = " + mire + " WHERE email = '" + mit + "'";

	q = query.c_str();
	qstate = mysql_query(conn, q);
	if (!qstate) {
		res = mysql_store_result(conn);
		if (!res) {
			return 1;
		}
		else
			return 0;
	}
	else
		return -1;
}

int MySQLDB::modositmail(MYSQL* conn, string mit, string mire) {
	MYSQL_ROW row;
	MYSQL_RES *res;
	const char* q;
	string query = "UPDATE login SET email = '" + mire + "' WHERE email = '" + mit + "'";

	q = query.c_str();
	qstate = mysql_query(conn, q);
	if (!qstate) {
		res = mysql_store_result(conn);
		if (!res) {
			return 1;
		}
		else
			return 0;
	}
	else
		return -1;
}

int MySQLDB::modositpass(MYSQL* conn, string mit, string mire) {
	MYSQL_ROW row;
	MYSQL_RES *res;
	const char* q;
	string query = "UPDATE login SET jelszo = '" + mire + "' WHERE jelszo = '" + mit + "'";

	q = query.c_str();
	qstate = mysql_query(conn, q);
	if (!qstate) {
		res = mysql_store_result(conn);
		if (!res) {
			return 1;
		}
		else
			return 0;
	}
	else
		return -1;
}

int MySQLDB::rogzit(MYSQL* conn, string email, string jelszo, char admin) {
	MYSQL_ROW row;
	MYSQL_RES *res;
	const char* q;
	string query = "INSERT INTO login (email, jelszo, admin) VALUES ('" + email + "', '" + jelszo + "', " + admin + ")";

	q = query.c_str();
	qstate = mysql_query(conn, q);
	if (!qstate) {
		res = mysql_store_result(conn);
		if (!res) {
			return 1;
		}
		else
			return 0;
	}
	else
		return -1;
}

int MySQLDB::torol(MYSQL* conn, string kit) {
	MYSQL_ROW row;
	MYSQL_RES *res;
	const char* q;
	string query = "DELETE FROM login WHERE email = '" + kit + "'";

	q = query.c_str();
	qstate = mysql_query(conn, q);
	if (!qstate) {
		res = mysql_store_result(conn);
		if (!res) {
			return 1;
		}
		else
			return 0;
	}
	else
		return -1;
}

int MySQLDB::emaile(char s[]) {
	unsigned short temp = 0;
	unsigned short i = 0;

	if (s[strlen(s) - 1] == '.') {
		std::cout << "Nem v�gz�det ponttal a c�m!";
		return 0;
	}
	if (s[0] == '.') {
		std::cout << "Nem kezd�dhet ponttal a c�m!";
		return 0;
	}

	while (s[i] != '\0') {
		if (s[i] == '@')
			temp++;
		i++;
	}
	if (!temp) {
		std::cout << "Hi�nyz� '@' karakter!";
		return 0;
	}
	else if (temp > 1) {
		std::cout << "T�l sok '@' karakter!";
		return 0;
	}
	else {
		i = 0;
		temp = 0;

		while (s[i] != '\0') {
			if (s[i] == '.') {
				if (s[i + 1] == '.') {
					std::cout << "Nem �llhat t�bb pont egym�s mellett!";
					return 0;
				}
			}
			i++;
		}

		i = 0;
		while (s[i] != '@')
			i++;
		if (s[i - 1] == '.') {
			std::cout << "Nem �llhat '.' a '@' karakter el�tt!";
			return 0;
		}
		else if (s[i + 1] == '.') {
			std::cout << "Nem �llhat '.' a '@' karakter ut�n!";
			return 0;
		}
		else {
			i = 0;

			while (s[i] != '@') {
				if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') || (s[i] == '.') || (s[i] == '@'))) {
					std::cout << "Helytelen felhaszn�l�n�v!";
					return 0;
				}
				i++;
			}

			i++;
			while (s[i] != '\0') {
				if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] == '.'))) {
					std::cout << "Helytelen domainn�v!";
					return 0;
				}
				i++;
			}
		}
	}
	return 1;
}
