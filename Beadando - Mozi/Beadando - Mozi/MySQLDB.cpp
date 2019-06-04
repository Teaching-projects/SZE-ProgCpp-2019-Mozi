#include "MySQLDB.hpp"

int qstate;
string current;

void MySQLDB::menu() {
	char choice;
	bool ok = 0;

	system("CLS");
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
			puts("Érvénytelen karakter!");
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
		char email[255];
		string email2;
		short megvan;
		bool ok = 0;
		bool ok1 = 0;
		bool kilep = 0;


		do {
			std::cout << "E-mail cím: ";
			std::cin >> email;
			email2 = email;
			if (!email2.compare("EXIT") || !email2.compare("exit"))
				kilep = 1;
			else if ((megvan = lekerdezes(conn, "SELECT email FROM login", email2)) < 0) {
				puts("Hiba a felhasználó lekérdezése során!");
				mysql_close;
				system("TIMEOUT /T 5");
				menu();
			}
			else if (!megvan)
				puts("Nem létezik ilyen E-mail cím!");
			else {
				ok = 1;
				current = email2;
				char pass[33];
				string pass2;
				do {
					megvan = 0;
					std::cout << "Jelszó: ";
					std::cin >> pass;
					pass2 = pass;
					if ((megvan = lekerdezes(conn, "SELECT jelszo FROM login WHERE email = '" + email2 + "'", pass2)) < 0) {
						puts("Hiba a jelszó lekérdezése során!");
						mysql_close;
						system("TIMEOUT /T 5");
						menu();
					}
					else if (!megvan)
						puts("Hibás jelszó!");
					else {
						ok1 = 1;
						megvan = lekerdezes(conn, "SELECT admin FROM login WHERE email = '" + email2 + "' AND jelszo = '" + pass2 + "'", 1);
					}
				} while (!ok1);
			}
		} while (!ok && !kilep);

		if (kilep) {
			mysql_close;
			menu();
		}
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
				system("TIMEOUT /T 5");
				menu();
			}
			else
				adminmenu(conn);
		}
	}
	else
		puts("Sikertelen kapcsolódás.\n");
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
		std::cout << "\nA választott menüpont: ";
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
		std::cout << "\nA választott menüpont: ";
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
	char email[255];
	string email2;
	short megvan;
	bool ok = 0;
	bool ok1 = 0;
	bool megsem = 0;

	system("CLS");
	puts("E-mail cím módosítása\n");
	do {
		std::cout << "Adja meg a módosítandó felhasználó E-mail címét: ";
		std::cin >> email;
		email2 = email;
		if (!email2.compare("CANCEL") || !email2.compare("cancel"))
			megsem = 1;
		else {
			if (!emaile(email))
				std::cout << "\n";
			else if ((megvan = lekerdezes(conn, "SELECT email FROM login", email2)) < 0) {
				puts("Hiba a felhasználó lekérdezése során!");
				system("TIMEOUT /T 5");
				modusermenu(conn);
			}
			else if (!megvan)
				puts("Nem található ilyen felhasználó!");
			else {
				ok = 1;
				char newemail[255];
				string newemail2;
				do {
					std::cout << "Az új E-mail cím: ";
					std::cin >> newemail;
					newemail2 = newemail;
					if (!emaile(newemail))
						std::cout << "\n";
					else if ((megvan = lekerdezes(conn, "SELECT email FROM login", newemail2)) < 0) {
						puts("Hiba a felhasználó lekérdezése során!");
						system("TIMEOUT /T 5");
						modusermenu(conn);
					}
					else if (megvan)
						puts("Már található ilyen felhasználónév!");
					else {
						ok1 = 1;
						megvan = lekerdezes(conn, "UPDATE login SET email = '" + newemail2 + "' WHERE email = '" + email2 + "'", 0);
					}
				} while (!ok1);
			}
		}
	} while (!ok && !megsem);

	if (megsem)
		modusermenu(conn);
	else {
		system("CLS");
		if (!megvan) {
			puts("Sikertelen módosítás");
			system("TIMEOUT /T 5");
			modusermenu(conn);
		}
		else if (megvan < 0) {
			puts("Sikertelen módosítás (lekérdezés hiba)!");
			system("TIMEOUT /T 5");
			modusermenu(conn);
		}
		else {
			puts("Sikeres módosítás!");
			system("TIMEOUT /T 2");
			modusermenu(conn);
		}
	}
}

void MySQLDB::modpass(MYSQL* conn) {
	char email[255];
	string email2;
	short megvan;
	bool ok = 0;
	bool ok1 = 0;
	bool megsem = 0;

	system("CLS");
	puts("Jelszó módosítása\n");
	do {
		std::cout << "Adja meg a módosítandó felhasználó E-mail címét: ";
		std::cin >> email;
		email2 = email;
		if (!email2.compare("CANCEL") || !email2.compare("cancel"))
			megsem = 1;
		else {
			if (!emaile(email))
				std::cout << "\n";
			else if ((megvan = lekerdezes(conn, "SELECT email FROM login", email2)) < 0) {
				puts("Hiba a felhasználó lekérdezése során!");
				system("TIMEOUT /T 5");
				modusermenu(conn);
			}
			else if (!megvan)
				puts("Nem található ilyen felhasználó!");
			else {
				ok = 1;
				char oldpass[33];
				string oldpass2;
				do {
					std::cout << "Adja meg a módosítandó felhasználó régi jelszavát: ";
					std::cin >> oldpass;
					oldpass2 = oldpass;
					if ((megvan = lekerdezes(conn, "SELECT jelszo FROM login WHERE email = '" + email2 + "'", oldpass2)) < 0) {
						puts("Hiba a régi jelszó lekérdezése során!");
						system("TIMEOUT /T 5");
						modusermenu(conn);
					}
					else if (!megvan)
						puts("Helytelen jelszó!");
					else {
						ok1 = 1;
						std::cout << "Az új jelszó: ";
						char newpass[33];
						string newpass2;
						std::cin >> newpass;
						newpass2 = newpass;
						megvan = lekerdezes(conn, "UPDATE login SET jelszo = '" + newpass2 + "' WHERE jelszo = '" + oldpass2 + "'", 0);
					}
				} while (!ok1);
			}
		}
	} while (!ok && !megsem);

	if (megsem)
		modusermenu(conn);
	else {
		system("CLS");
		if (!megvan) {
			puts("Sikertelen módosítás");
			system("TIMEOUT /T 5");
			modusermenu(conn);
		}
		else if (megvan < 0) {
			puts("Sikertelen módosítás (lekérdezés hiba)!");
			system("TIMEOUT /T 5");
			modusermenu(conn);
		}
		else {
			puts("Sikeres módosítás!");
			system("TIMEOUT /T 2");
			modusermenu(conn);
		}
	}
}

void MySQLDB::modperm(MYSQL* conn) {
	char email[255];
	string email2;
	short megvan;
	bool ok = 0;
	bool ok1 = 0;
	bool ok2 = 0;
	bool megsem = 0;

	system("CLS");
	puts("Jogosultság megváltoztatása\n");
	do {
		std::cout << "Adja meg a módosítandó felhasználó E-mail címét: ";
		std::cin >> email;
		email2 = email;
		if (!email2.compare("CANCEL") || !email2.compare("cancel"))
			megsem = 1;
		else {
			if (!emaile(email))
				std::cout << "\n";
			else if ((megvan = lekerdezes(conn, "SELECT email FROM login", email2)) < 0) {
				puts("Hiba a felhasználó lekérdezése során!");
				system("TIMEOUT /T 5");
				modusermenu(conn);
			}
			else if (!megvan)
				puts("Nem található ilyen felhasználó!");
			else {
				ok = 1;
				char pass[33];
				string pass2;
				do {
					std::cout << "Adja meg a módosítandó felhasználó jelszavát: ";
					std::cin >> pass;
					pass2 = pass;
					if ((megvan = lekerdezes(conn, "SELECT jelszo FROM login WHERE email = '" + email2 + "'", pass2)) < 0) {
						puts("Hiba a jelszó lekérdezése során!");
						system("TIMEOUT /T 5");
						modusermenu(conn);
					}
					else if (!megvan)
						puts("Helytelen jelszó!");
					else {
						ok1 = 1;
						char admin[5];
						do {
							std::cout << "Adja meg az új jogosultságot! [0 - User, 1 - Admin]: ";
							std::cin >> admin;
							if (strlen(admin) != 1)
								puts("Csak egy karaktert adhat meg!");
							if (!((admin[0] == '0') || (admin[0] == '1')))
								puts("Nem megengedett karakter!");
							else {
								ok2 = 1;
								string admin2 = admin;
								megvan = lekerdezes(conn, "UPDATE login SET admin = " + admin2 + " WHERE email = '" + email2 + "'", 0);
							}
						} while (!ok2);
					}
				} while (!ok1);
			}
		}
	} while (!ok && !megsem);

	if (megsem)
		modusermenu(conn);
	else {
		system("CLS");
		if (!megvan) {
			puts("Sikertelen módosítás");
			system("TIMEOUT /T 5");
			modusermenu(conn);
		}
		else if (megvan < 0) {
			puts("Sikertelen módosítás (lekérdezés hiba)!");
			system("TIMEOUT /T 5");
			modusermenu(conn);
		}
		else {
			puts("Sikeres módosítás!");
			system("TIMEOUT /T 5");
			modusermenu(conn);
		}
	}
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
		email2 = email;
		if (!email2.compare("CANCEL") || !email2.compare("cancel"))
			megsem = 1;
		else if (!emaile(email))
			std::cout << "\n";
		else if ((megvan = lekerdezes(conn, "SELECT email FROM login", email2)) < 0) {
			puts("Hiba a felhasználó lekérdezése során!");
			system("TIMEOUT /T 5");
			adminmenu(conn);
		}
		else if (megvan)
			puts("Már található ilyen felhasználó!");
		else {
			ok = 1;
			char pass[33];
			string pass2;
			std::cout << "Jelszó: ";
			std::cin >> pass;
			pass2 = pass;
			char admin[10];
			do {
				std::cout << "Admin [0 - Nem, 1 - Igen]: ";
				std::cin >> admin;
				if (strlen(admin) != 1)
					puts("Csak egy karaktert adhat meg!");
				else if (!((admin[0] == '0') || (admin[0] == '1')))
					puts("Nem megengedett karakter!");
				else {
					ok1 = 1;
					megvan = lekerdezes(conn, "INSERT INTO login (email, jelszo, admin) VALUES ('" + email2 + "', '" + pass2 + "', " + admin[0] + ")", 0);
				}
			} while (!ok1);
		}
	} while (!ok && !megsem);

	if (megsem)
		adminmenu(conn);
	else {
		if (megvan < 0) {
			puts("Sikertelen rögzítés(lekérdezés hiba)!");
			system("TIMEOUT /T 5");
			adminmenu(conn);
		}
		else if (!megvan) {
			puts("Sikertelen lekérdezés!");
			system("TIMEOUT /T 5");
			adminmenu(conn);
		}
		else {
			puts("Sikeres rögzítés!");
			system("TIMEOUT /T 2");
			adminmenu(conn);
		}
	}
}

void MySQLDB::deluser(MYSQL* conn) {
	short megvan;
	bool ok = 0;
	bool megsem = 0;
	char email[255];
	string email2;

	system("CLS");
	puts("Felhasználó törlése\n");
	do {
		std::cout << "Adja meg a törölni kívánt felhasználónevet: ";
		std::cin >> email;
		email2 = email;
		if (!email2.compare("CANCEL") || !email2.compare("cancel"))
			megsem = 1;
		else if (!emaile(email))
			std::cout << "\n";
		else if (!email2.compare(current))
			puts("Jelenleg bejelentkezett felhasználó nem törölhetõ!");
		else if ((megvan = lekerdezes(conn, "SELECT email FROM login", email2)) < 0) {
			puts("Hiba a felhasználó lekérdezése során!");
			system("TIMEOUT /T 5");
			adminmenu(conn);
		}
		else if (!megvan)
			puts("Nem található ilyen felhasználó!");
		else {
			ok = 1;
			megvan = lekerdezes(conn, "DELETE FROM login WHERE email = '" + email2 + "'", 0);
		}
	} while (!ok && !megsem);

	if (megsem)
		adminmenu(conn);
	else {
		system("CLS");
		if (megvan < 0) {
			puts("Sikertelen rögzítés(lekérdezés hiba)!");
			system("TIMEOUT /T 5");
			adminmenu(conn);
		}
		else if (!megvan) {
			puts("Sikertelen lekérdezés!");
			system("TIMEOUT /T 5");
			adminmenu(conn);
		}
		else {
			puts("Sikeres törlés!");
			system("TIMEOUT /T 2");
			adminmenu(conn);
		}
	}
}

int MySQLDB::lekerdezes(MYSQL* conn, string query, string mit) {
	MYSQL_ROW row;
	MYSQL_RES *res;
	const char* q;

	q = query.c_str();
	qstate = mysql_query(conn, q);
	if (!qstate) {
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res)) {
			if (!mit.compare(row[0]))
				return 1;
		}
		return 0;
	}
	else
		return -1;
}

int MySQLDB::lekerdezes(MYSQL* conn, string query, bool param) {
	MYSQL_ROW row;
	MYSQL_RES *res;
	const char* q;

	q = query.c_str();
	qstate = mysql_query(conn, q);
	if (!qstate) {
		res = mysql_store_result(conn);
		if (param) {
			while (row = mysql_fetch_row(res)) {
				if (!strcmp(row[0], "1"))
					return 1;
			}
			return 0;
		}
		else {
			if (!res)
				return 1;
			else
				return 0;
		}
	}
	else
		return -1;
}

int MySQLDB::emaile(char s[]) {
	short i = 0;
	short temp = 0;

	if (!(temp = strlen(s))) {
		puts("Nem adhat meg üres sort!");
		return 0;
	}
	else if (temp < 5) {
		puts("A címnek legalább 5 karakter hosszúnak kell lennie!");
		return 0;
	}
	else if (temp > 254) {
		puts("A cím szabvány szerint maximum 254 karakter hosszú lehet!");
		return 0;
	}
	else if ((s[0] == '.') || (s[0] == '@') || ((s[0] >= '0') && (s[0] <= '9'))) {
		puts("A cím nem kezdõdhet ponttal, '@' karakterrel vagy számmal!");
		return 0;
	}
	else if ((s[temp - 1] == '@') || (s[temp - 1] == '.') || ((s[temp - 1] >= '0') && (s[temp - 1] <= '9'))) {
		puts("A cím nem végzõdhet ponttal, '@' karakterrel vagy számmal!");
		return 0;
	}
	else {
		temp = 0;
		while (s[i] != '\0') {
			if (s[i] == '@')
				temp++;
			i++;
		}
		if (temp != 1) {
			puts("A cím csak egy '@' karaktert tartalmazhat!");
			return 0;
		}
		else {
			i = 0;
			temp = 0;

			while (s[i] != '\0') {
				if (s[i] == '.')
					temp++;
				i++;
			}
			if (!temp) {
				puts("A címnek legalább egy pontot tartalmaznia kell!");
				return 0;
			}
			else {
				i = 0;
				temp = 0;

				while (s[i] != '@') {
					if (s[i] == '.')
						temp++;
					i++;
				}

				if (temp > 1) {
					puts("A felhasználónév maximum 1 db pontot tartalmazhat!");
					return 0;
				}
				else if (s[i - 1] == '.') {
					puts("A '@' karakter elõtt nem állhat pont!");
					return 0;
				}
				else if (s[i + 1] == '.') {
					puts("A '@' karakter után nem állhat pont!");
					return 0;
				}
				else {
					i = 0;
					temp = 0;

					while (s[i] != '@') {
						if (!(((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >= '0') && (s[i] <= '9')) || (s[i] == '.')))
							temp = 1;
						i++;
					}

					if (temp) {
						puts("A felhasználónév csak [a - z], [0 - 9] karaktereket és pontot tartalmazhat!");
						return 0;
					}
					else {
						i++;
						temp = 0;

						while (s[i] != '\0') {
							if (!(((s[i] >= 'a') && (s[i] <= 'z')) || (s[i] == '.'))) {
								puts("A domain név csak [a - z] karaktereket és pontot tartalmazhat!");
								return 0;
							}
							else {
								if (s[i] == '.')
									temp++;
							}
							i++;
						}

						if (temp != 1) {
							puts("A domain név csak egy pontot tartalmazhat!");
							return 0;
						}
						else
							return 1;
					}
				}
			}
		}
	}
}
