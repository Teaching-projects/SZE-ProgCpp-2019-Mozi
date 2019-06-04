#include "MySQLDB.hpp"

int qstate;

void MySQLDB::menu() {
	char choice;
	int ok = 0;

	puts("Kérem válasszon az alábbi menüpontok közül:\n");
	puts("1: Bejelentkezés");
	puts("2: Demo üzemmód (login nélkül)");
	puts("3: Készítõk");
	puts("4: Kilépés");

	do {
		printf("\nA választott menüpont: ");
		cin >> choice;
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

	puts("Kapcsolódás az adatbázishoz...");
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "root", "MOZI", 3306, NULL, 0);

	if (conn) {
		puts("Sikeres kapcsolódás!\n");
		char user[255];
		string user2;
		short megvan = 0;
		int ok = 0;
		int ok1 = 0;
		int kilep = 0;


		do {
			printf("E-mail cím: ");
			cin >> user;
			user2 = user;
			megvan = lekerdez(conn, "SELECT email FROM login", user2);
			if (user2.compare("EXIT") == 0 || user2.compare("exit") == 0) {
				ok = 1;
				ok1 = 1;
				kilep = 1;
			}
			else if (megvan < 0) {
				puts("Hiba a felhasználó lekérdezése során!");
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
					megvan = lekerdez(conn, "SELECT jelszo FROM login WHERE email = '" + user2 + "'", pass2);
					if (pass2.compare("EXIT") == 0 || pass2.compare("exit") == 0) {
						ok1 = 1;
						kilep = 1;
					}
					else if (megvan < 0) {
						puts("Hiba a jelszó lekérdezése során!");
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
			puts("Sikeres bejelentkezés!\n");
			if (!megvan) {
				usermenu();
			}
			else if (megvan < 0) {
				puts("Sikertelen admin lekérdezés!");
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
	puts("Készítették:\n");
	puts("Orbán Máté - FL8F6V");
	puts("Szekendi Balázs - FBET1V");
	puts("Zsigmond Richárd Tamás - PJ92ND");
	puts("\nVisszatérés a fõmenübe.");
	menu();
}

void MySQLDB::adminmenu(MYSQL* conn) {
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
	int ok = 0;

	puts("Kérem válasszon az alábbi menüpontok közül:\n");
	puts("1: Program indítása");
	puts("2: Kijelentkezés");

	do {
		printf("A választott menüpont: ");
		cin >> choice;
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
	int ok = 0;

	puts("Felhasználó módosítása\n");
	puts("1: E-mail cím módosítása");
	puts("2: Jelszó módosítása");
	puts("3: Jogosultság módosítása");
	puts("4: Vissza az admin menübe");

	do {
		printf("A választott menüpont: ");
		cin >> choice;
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
	int ok = 0;

	printf("Adja meg a módosítandó felhasználó E-mail címét: ");
	cin >> user;
	user2 = user;
	megvan = lekerdez(conn, "SELECT email FROM login", user2);
	if (megvan < 0) {
		puts("Hiba a felhasználó lekérdezése során!");
	}
	else if (!megvan)
		puts("Nem található ilyen felhasználó!");
	else {
		do {
			printf("Az új E-mail cím: ");
			char newuser[255];
			string newuser2;
			cin >> newuser;
			newuser2 = newuser;
			if (!emaile(newuser))
				printf("Hiba: ");
			else {
				ok = 1;
				megvan = modositmail(conn, user2, newuser2);
			}
		} while (!ok);
	}

	if (!megvan) {
		puts("Sikertelen módosítás");
	}
	else if (megvan < 0) {
		puts("Sikertelen módosítás (lekérdezés hiba)!");
	}
	else {
		puts("Sikeres módosítás!");
		modusermenu(conn);
	}
}

void MySQLDB::modpass(MYSQL* conn) {
	char user[255];
	string user2;
	short megvan = 0;
	int ok = 0;
	int ok1 = 0;

	printf("Adja meg a módosítandó felhasználó E-mail címét: ");
	cin >> user;
	user2 = user;
	megvan = lekerdez(conn, "SELECT email FROM login", user2);
	if (megvan < 0) {
		puts("Hiba a felhasználó lekérdezése során!");
	}
	else if (!megvan) {
		puts("Nem található ilyen felhasználó!");

	}
	else {
		do {
			printf("Adja meg a módosítandó felhasználó régi jelszavát: ");
			char oldpass[33];
			string oldpass2;
			cin >> oldpass;
			oldpass2 = oldpass;
			megvan = lekerdez(conn, "SELECT jelszo FROM login WHERE email = '" + user2 + "'", oldpass2);
			if (megvan < 0) {
				puts("Hiba a régi jelszó lekérdezése során!");
			}
			else if (!megvan) {
				puts("Helytelen jelszó!");
			}
			else {
				ok = 1;
				printf("Az új jelszó: ");
				char newpass[33];
				string newpass2;
				cin >> newpass;
				newpass2 = newpass;
				megvan = modositpass(conn, oldpass2, newpass2);
			}
		} while (!ok);
	}

	if (!megvan) {
		puts("Sikertelen módosítás");
	}
	else if (megvan < 0) {
		puts("Sikertelen módosítás (lekérdezés hiba)!");
	}
	else {
		puts("Sikeres módosítás!");
		modusermenu(conn);
	}
}

void MySQLDB::modperm(MYSQL* conn) {
	char user[255];
	string user2;
	short megvan = 0;
	int ok = 0;
	int ok1 = 0;

	printf("Adja meg a módosítandó felhasználó E-mail címét: ");
	cin >> user;
	user2 = user;
	megvan = lekerdez(conn, "SELECT email FROM login", user2);
	if (megvan < 0) {
		puts("Hiba a felhasználó lekérdezése során!");
	}
	else if (!megvan) {
		puts("Nem található ilyen felhasználó!");
	}
	else {
		do {
			printf("Adja meg a módosítandó felhasználó jelszavát: ");
			char pass[33];
			string pass2;
			cin >> pass;
			pass2 = pass;
			megvan = lekerdez(conn, "SELECT jelszo FROM login WHERE email = '" + user2 + "'", pass2);
			if (megvan < 0) {
				puts("Hiba a jelszó lekérdezése során!");
			}
			else if (!megvan) {
				puts("Helytelen jelszó!");
			}
			else {
				ok = 1;
				do {
					printf("Adja meg az új jogosultságot! [0 - User, 1 - Admin]: ");
					char admin[5];
					cin >> admin;
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

	if (!megvan) {
		puts("Sikertelen módosítás");
	}
	else if (megvan < 0) {
		puts("Sikertelen módosítás (lekérdezés hiba)!");
	}
	else {
		puts("Sikeres módosítás!");
		modusermenu(conn);
	}
}

void MySQLDB::adduser(MYSQL* conn) {
	char email[255];
	string email2;
	int ok = 0;
	int ok1 = 0;
	int ok2 = 0;
	short megvan;
	int megsem = 0;

	puts("Felhasználó hozzáadása\n");

	do {
		printf("E-mail cím: ");
		cin >> email;
		if (!emaile(email))
			printf("Hiba: ");
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
			}
			else if (megvan > 0) {
				puts("Már található ilyen felhasználó!");
			}
			else {
				ok = 1;
				char pass[33];
				string pass2;
				do {
					printf("Jelszó: ");
					cin >> pass;
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
							printf("Admin [0 - Nem, 1 - Igen]: ");
							cin >> admin;
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
		}
		else if (megvan == 0) {
			puts("Sikertelen lekérdezés!");
		}
		else {
			puts("Sikeres rögzítés!");
			adminmenu(conn);
		}
	}
}

void MySQLDB::deluser(MYSQL* conn) {
	short megvan;
	int ok = 0;
	int megsem = 0;

	do {
		printf("Adja meg a törölni kívánt felhasználónevet: ");
		char user[255];
		string user2;
		cin >> user;
		user2 = user;
		megvan = lekerdez(conn, "SELECT email FROM login", user2);
		if (user2.compare("CANCEL") == 0 || user2.compare("cancel") == 0) {
			ok = 1;
			megsem = 1;
		}
		else if (megvan < 0) {
			puts("Hiba a felhasználó lekérdezése során!");
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
		}
		else if (megvan == 0) {
			puts("Sikertelen lekérdezés!");
		}
		else {
			puts("Sikeres törlés!");
			adminmenu(conn);
		}
	}
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
	int temp = 0;
	int i = 0;

	if (s[strlen(s) - 1] == '.') {
		printf("Nem végzõdet ponttal a cím!");
		return 0;
	}
	if (s[0] == '.') {
		printf("Nem kezdõdhet ponttal a cím!");
		return 0;
	}

	while (s[i] != '\0') {
		if (s[i] == '@')
			temp++;
		i++;
	}
	if (!temp) {
		printf("Hiányzó '@' karakter!");
		return 0;
	}
	else if (temp > 1) {
		printf("Túl sok '@' karakter!");
		return 0;
	}
	else {
		i = 0;
		temp = 0;

		while (s[i] != '\0') {
			if (s[i] == '.') {
				if (s[i + 1] == '.') {
					printf("Nem állhat több pont egymás mellett!");
					return 0;
				}
			}
			i++;
		}

		i = 0;
		while (s[i] != '@')
			i++;
		if (s[i - 1] == '.') {
			printf("Nem állhat '.' a '@' karakter elõtt!");
			return 0;
		}
		else if (s[i + 1] == '.') {
			printf("Nem állhat '.' a '@' karakter után!");
			return 0;
		}
		else {
			i = 0;

			while (s[i] != '@') {
				if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') || (s[i] == '.') || (s[i] == '@'))) {
					printf("Helytelen felhasználónév!");
					return 0;
				}
				i++;
			}

			i++;
			while (s[i] != '\0') {
				if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] == '.'))) {
					printf("Helytelen domainnév!");
					return 0;
				}
				i++;
			}
		}
	}
	return 1;
}
