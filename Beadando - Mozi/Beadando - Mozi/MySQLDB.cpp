#include "MySQLDB.hpp"

int qstate;

void MySQLDB::menu() {
	char choice;
	bool ok = 0;

	system("cls");
	puts("Kérem válasszon az alábbi menüpontok közül:\n");
	puts("1: Bejelentkezés");
	puts("2: Demo üzemmód (login nélkül)");
	puts("3: Készítõk");
	puts("4: Kilépés");

	do {
		std::cout << "\nA választott menüpont: ";
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
			puts("érvénytelen karakter!");
	} while (!ok);
}

void MySQLDB::login() {
	MYSQL* conn;

	system("CLS");
	puts("Kapcsolódás az adatbázishoz...");
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "root", "MOZI", 3306, NULL, 0);

	if (conn) {
		puts("Sikeres kapcsolódás!\n");
		char user[255];
		string user2;
		short megvan = 0;
		bool ok = 0;
		bool ok1 = 0;
		bool kilep = 0;


		do {
			std::cout << "E-mail cím: ";
			std::cin >> user;
			user2 = user;
			megvan = lekerdez(conn, "SELECT email FROM login", user2);
			if (user2.compare("EXIT") == 0 || user2.compare("exit") == 0) {
				ok = 1;
				ok1 = 1;
				kilep = 1;
			}
			else if (megvan < 0) {
				puts("Hiba a felhasználó lekérdezése során!");
				mysql_close;
				puts("Visszatérés a fõmenübe 5 másodperc múlva.");
				system("TIMEOUT /T 5");
			}
			else if (!megvan)
				puts("Nem létezik ilyen E-mail cím!");
			else {
				ok = 1;
				char pass[33];
				string pass2;
				do {
					megvan = 0;
					std::cout << "Jelszó: ";
					std::cin >> pass;
					pass2 = pass;
					megvan = lekerdez(conn, "SELECT jelszo FROM login WHERE email = '" + user2 + "'", pass2);
					if (pass2.compare("EXIT") == 0 || pass2.compare("exit") == 0) {
						ok1 = 1;
						kilep = 1;
					}
					else if (megvan < 0) {
						puts("Hiba a jelszó lekérdezése során!");
						mysql_close;
						puts("Visszatérés a fõmenübe 5 másodperc múlva.");
						system("TIMEOUT /T 5");
					}
					else if (!megvan)
						puts("Hibás jelszó!");
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
			puts("Sikeres bejelentkezés!\n");
			if (!megvan) {
				mysql_close;
				usermenu();
			}
			else if (megvan < 0) {
				puts("Sikertelen admin lekérdezés!");
				mysql_close;
				puts("Visszatérés a fõmenübe 5 másodperc múlva.");
				system("TIMEOUT /T 5");
			}
			else {
				adminmenu(conn);
			}
		}
	}
	else {
		puts("Sikertelen kapcsolódás.\n");
	}
}

void MySQLDB::start() {
	puts("start");
}

void MySQLDB::keszitok() {
	system("CLS");
	puts("Készítették:\n");
	puts("Orbán Máté - FL8F6V");
	puts("Szekendi Balázs - FBET1V");
	puts("Zsigmond Richárd Tamás - PJ92ND");
	puts("\nVisszatérés a fõmenübe 10 másodperc múlva.");
	system("TIMEOUT /T 10");
	menu();
}

void MySQLDB::adminmenu(MYSQL* conn) {
	char choice;
	bool ok = 0;

	system("CLS");
	puts("Kérem válasszon az alábbi menüpontok közül:\n");
	puts("1: Program indítása");
	puts("2: Felhasználó hozzáadása");
	puts("3: Felhasználó módosítása");
	puts("4: Felhasználó törlése");
	puts("5: Kijelentkezés");

	do {
		std::cout << "A választott menüpont: ";
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
			puts("Érvénytelen karakter!\n");
	} while (!ok);
}

void MySQLDB::usermenu() {
	char choice;
	bool ok = 0;

	puts("Kérem válasszon az alábbi menüpontok közül:\n");
	puts("1: Program indítása");
	puts("2: Kijelentkezés");

	do {
		std::cout << "A választott menüpont: ";
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
			puts("Érvénytelen karakter!\n");
	} while (!ok);
}

void MySQLDB::modusermenu(MYSQL* conn) {
	char choice;
	bool ok = 0;

	system("CLS");
	puts("Felhasználó módosítása\n");
	puts("1: E-mail cím módosítása");
	puts("2: Jelszó módosítása");
	puts("3: Jogosultság módosítása");
	puts("4: Vissza az admin menübe");

	do {
		std::cout << "A választott menüpont: ";
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
			puts("Érvénytelen karakter!");
	} while (!ok);
}

void MySQLDB::modmail(MYSQL* conn) {
	char user[255];
	string user2;
	short megvan = 0;
	bool ok = 0;

	system("CLS");
	std::cout << "Adja meg a módosítandó felhasználó E-mail címét: ";
	std::cin >> user;
	user2 = user;
	megvan = lekerdez(conn, "SELECT email FROM login", user2);
	if (megvan < 0) {
		puts("Hiba a felhasználó lekérdezése során!");
		mysql_close;
		puts("Visszatérés a felhasználó módosítása menübe 5 másodperc múlva.");
		system("TIMEOUT /T 5");
	}
	else if (!megvan)
		puts("Nem található ilyen felhasználó!");
	else {
		do {
			std::cout << "Az új E-mail cím: ";
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
		puts("Sikertelen módosítás");
		mysql_close;
		puts("Visszatérés a felhasználó módosítása menübe 5 másodperc múlva.");
		system("TIMEOUT /T 5");
	}
	else if (megvan < 0) {
		puts("Sikertelen módosítás (lekérdezés hiba)!");
		mysql_close;
		puts("Visszatérés a felhasználó módosítása menübe 5 másodperc múlva.");
		system("TIMEOUT /T 5");
	}
	else {
		puts("Sikeres módosítás!");
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
	std::cout << "Adja meg a módosítandó felhasználó E-mail címét: ";
	std::cin >> user;
	user2 = user;
	megvan = lekerdez(conn, "SELECT email FROM login", user2);
	if (megvan < 0) {
		puts("Hiba a felhasználó lekérdezése során!");
		puts("Visszatérés a felhasználó módosítása menübe 5 másodperc múlva.");
		system("TIMEOUT /T 5");
		modusermenu(conn);
	}
	else if (!megvan) {
		puts("Nem található ilyen felhasználó!");
		puts("Visszatérés a felhasználó módosítása menübe 5 másodperc múlva.");
		system("TIMEOUT /T 5");
		modusermenu(conn);
	}
	else {
		do {
			std::cout << "Adja meg a módosítandó felhasználó régi jelszavát: ";
			char oldpass[33];
			string oldpass2;
			std::cin >> oldpass;
			oldpass2 = oldpass;
			megvan = lekerdez(conn, "SELECT jelszo FROM login WHERE email = '" + user2 + "'", oldpass2);
			if (megvan < 0) {
				puts("Hiba a régi jelszó lekérdezése során!");
				puts("Visszatérés a felhasználó módosítása menübe 5 másodperc múlva.");
				system("TIMEOUT /T 5");
				modusermenu(conn);
			}
			else if (!megvan) {
				puts("Helytelen jelszó!");
			}
			else {
				ok = 1;
				std::cout << "Az új jelszó: ";
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
		puts("Sikertelen módosítás");
		puts("Visszatérés a felhasználó módosítása menübe 5 másodperc múlva.");
		system("TIMEOUT /T 5");
		modusermenu(conn);
	}
	else if (megvan < 0) {
		puts("Sikertelen módosítás (lekérdezés hiba)!");
		puts("Visszatérés a felhasználó módosítása menübe 5 másodperc múlva.");
		system("TIMEOUT /T 5");
		modusermenu(conn);
	}
	else {
		puts("Sikeres módosítás!");
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
	std::cout << "Adja meg a módosítandó felhasználó E-mail címét: ";
	std::cin >> user;
	user2 = user;
	megvan = lekerdez(conn, "SELECT email FROM login", user2);
	if (megvan < 0) {
		puts("Hiba a felhasználó lekérdezése során!");
		system("TIMEOUT /T 3");
		modusermenu(conn);
	}
	else if (!megvan) {
		puts("Nem található ilyen felhasználó!");
		system("TIMEOUT /T 3");
		modusermenu(conn);
	}
	else {
		do {
			std::cout << "Adja meg a módosítandó felhasználó jelszavát: ";
			char pass[33];
			string pass2;
			std::cin >> pass;
			pass2 = pass;
			megvan = lekerdez(conn, "SELECT jelszo FROM login WHERE email = '" + user2 + "'", pass2);
			if (megvan < 0) {
				puts("Hiba a jelszó lekérdezése során!");
				puts("Visszatérés a felhasználó módosítása menübe 5 másodperc múlva.");
				system("TIMEOUT /T 5");
				modusermenu(conn);
			}
			else if (!megvan) {
				puts("Helytelen jelszó!");
			}
			else {
				ok = 1;
				do {
					std::cout << "Adja meg az új jogosultságot! [0 - User, 1 - Admin]: ";
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
		puts("Sikertelen módosítás");
		puts("Visszatérés a felhasználó módosítása menübe 5 másodperc múlva.");
		system("TIMEOUT /T 5");
		modusermenu(conn);
	}
	else if (megvan < 0) {
		puts("Sikertelen módosítás (lekérdezés hiba)!");
		puts("Visszatérés a felhasználó módosítása menübe 5 másodperc múlva.");
		system("TIMEOUT /T 5");
		modusermenu(conn);
	}
	else {
		puts("Sikeres módosítás!");
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
	puts("Felhasználó hozzáadása\n");

	do {
		std::cout << "E-mail cím: ";
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
				puts("Hiba a felhasználó lekérdezése során!");
				mysql_close;
				puts("Visszatérés az adminmenübe 5 másodperc múlva.");
				system("TIMEOUT /T 5");
				adminmenu(conn);
			}
			else if (megvan > 0) {
				puts("Már található ilyen felhasználó!");
			}
			else {
				ok = 1;
				char pass[33];
				string pass2;
				do {
					std::cout << "Jelszó: ";
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
			puts("Sikertelen rögzítés(lekérdezés hiba)!");
			puts("Visszatérés az adminmenübe 5 másodperc múlva.");
			system("TIMEOUT /T 5");
			adminmenu(conn);
		}
		else if (megvan == 0) {
			puts("Sikertelen lekérdezés!");
			puts("Visszatérés az adminmenübe 5 másodperc múlva.");
			system("TIMEOUT /T 5");
			adminmenu(conn);
		}
		else {
			puts("Sikeres rögzítés!");
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
		std::cout << "Adja meg a törölni kívánt felhasználónevet: ";
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
			puts("Hiba a felhasználó lekérdezése során!");
			mysql_close;
			puts("Visszatérés az adminmenübe 5 másodperc múlva.");
			system("TIMEOUT /T 5");
			adminmenu(conn);
		}
		else if (megvan == 0) {
			puts("Nem található ilyen felhasználó!");
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
			puts("Sikertelen rögzítés(lekérdezés hiba)!");
			puts("Visszatérés az adminmenübe 5 másodperc múlva.");
			system("TIMEOUT /T 5");
			adminmenu(conn);
		}
		else if (megvan == 0) {
			puts("Sikertelen lekérdezés!");
			puts("Visszatérés az adminmenübe 5 másodperc múlva.");
			system("TIMEOUT /T 5");
			adminmenu(conn);
		}
		else {
			puts("Sikeres törlés!");
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
		std::cout << "Nem végzõdet ponttal a cím!";
		return 0;
	}
	if (s[0] == '.') {
		std::cout << "Nem kezdõdhet ponttal a cím!";
		return 0;
	}

	while (s[i] != '\0') {
		if (s[i] == '@')
			temp++;
		i++;
	}
	if (!temp) {
		std::cout << "Hiányzó '@' karakter!";
		return 0;
	}
	else if (temp > 1) {
		std::cout << "Túl sok '@' karakter!";
		return 0;
	}
	else {
		i = 0;
		temp = 0;

		while (s[i] != '\0') {
			if (s[i] == '.') {
				if (s[i + 1] == '.') {
					std::cout << "Nem állhat több pont egymás mellett!";
					return 0;
				}
			}
			i++;
		}

		i = 0;
		while (s[i] != '@')
			i++;
		if (s[i - 1] == '.') {
			std::cout << "Nem állhat '.' a '@' karakter elõtt!";
			return 0;
		}
		else if (s[i + 1] == '.') {
			std::cout << "Nem állhat '.' a '@' karakter után!";
			return 0;
		}
		else {
			i = 0;

			while (s[i] != '@') {
				if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') || (s[i] == '.') || (s[i] == '@'))) {
					std::cout << "Helytelen felhasználónév!";
					return 0;
				}
				i++;
			}

			i++;
			while (s[i] != '\0') {
				if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] == '.'))) {
					std::cout << "Helytelen domainnév!";
					return 0;
				}
				i++;
			}
		}
	}
	return 1;
}
