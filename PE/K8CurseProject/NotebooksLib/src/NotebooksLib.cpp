//============================================================================
// Name        : NotebooksLib.cpp
// Author      : Ekaterina Stamatova
// Version     :
// Copyright   : Your copyright notice
// Description : Course project in C++, Ansi-style
//============================================================================

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isValidName(string);
bool isValidNumber(string);

class Date {

private:
	int day;
	int month;
	int year;

public:
	int getDay() const;
	void setDay(int day);
	int getMonth() const;
	void setMonth(int month);
	int getYear() const;
	void setYear(int year);
	Date(int day, int month, int year);
	~Date();

};

Date::Date(int day, int month, int year) {
	setDay(day);
	setMonth(month);
	setYear(year);
}
;

Date::~Date() {

}

class Textbook {
private:

	bool approval;
	string title;
	string author;
	Date dateofapproval;
	int edition;
	string ISBN;
	Date outOfPrint;
	int issue;
	float price;

public:
	bool isApproval() const;
	void setApproval(bool approval);
	const Date& getDateofapproval() const;
	void setDateofapproval(const Date& dateofapproval);
	int getEdition() const;
	void setEdition(int edition);
	const Date& getOutOfPrint() const;
	void setOutOfPrint(const Date& exitOfPrint);
	const string& getIsbn() const;
	void setIsbn(const string& isbn);
	int getIssue() const;
	void setIssue(int issue);
	const string& getTitle() const;
	void setTitle(const string& title);
	const string& getAuthor() const;
	void setAuthor(const string& author);
	float getPrice() const;
	void setPrice(float price);
	Textbook(bool approval, string title, string author, const int& aday,
			const int& amonth, const int& ayear, int edition, string ISBN,
			const int& exitday, const int& exitmonth, const int& exityear,
			int issue, float price);

	~Textbook();

};

Textbook::Textbook(bool approval, string title, string author, const int& aday,
		const int& amonth, const int& ayear, int edition, string ISBN,
		const int& exitday, const int& exitmonth, const int& exityear,
		int issue, float price) :
		dateofapproval(aday, amonth, ayear), outOfPrint(exitday, exitmonth,
				exityear) {

	setApproval(approval);
	setTitle(title);
	setAuthor(author);
	setEdition(edition);
	setIsbn(ISBN);
	setIssue(issue);
	setPrice(price);

}

Textbook::~Textbook() {

}
;

class Distributor {
private:
	string name;
	string address;
	string phone;

public:
	const string& getAddress() const;
	void setAddress(const string& address);
	const string& getName() const;
	void setName(const string& name);
	const string& getPhone() const;
	void setPhone(const string& phone);
	Distributor(string name, string address, string phone);
	~Distributor();
};

Distributor::Distributor(string name, string address, string phone) {
	setName(name);
	setAddress(address);
	setPhone(phone);
}
;

Distributor::~Distributor() {
};

int Date::getDay() const {
	return day;
}

void Date::setDay(int day) {
	this->day = day;
}

int Date::getMonth() const {
	return month;
}

void Date::setMonth(int month) {
	this->month = month;
}

int Date::getYear() const {
	return year;
}

void Date::setYear(int year) {
	this->year = year;
}

bool Textbook::isApproval() const {
	return approval;
}

void Textbook::setApproval(bool approval) {
	this->approval = approval;
}

const Date& Textbook::getDateofapproval() const {
	return dateofapproval;
}

void Textbook::setDateofapproval(const Date& dateofapproval) {
	this->dateofapproval = dateofapproval;
}

int Textbook::getEdition() const {
	return edition;
}

void Textbook::setEdition(int edition) {
	this->edition = edition;
}

const Date& Textbook::getOutOfPrint() const {
	return outOfPrint;
}

void Textbook::setOutOfPrint(const Date& exitOfPrint) {
	this->outOfPrint = exitOfPrint;
}

const string& Textbook::getIsbn() const {
	return ISBN;
}

void Textbook::setIsbn(const string& isbn) {
	ISBN = isbn;
}

int Textbook::getIssue() const {
	return issue;
}

void Textbook::setIssue(int issue) {
	this->issue = issue;
}

const string& Textbook::getTitle() const {
	return title;
}

const string& Textbook::getAuthor() const {
	return author;
}

void Textbook::setAuthor(const string& author) {
	this->author = author;
}

void Textbook::setTitle(const string& title) {
	this->title = title;
}

float Textbook::getPrice() const {
	return price;
}

void Textbook::setPrice(float price) {
	this->price = price;
}

const string& Distributor::getAddress() const {
	return address;
}

void Distributor::setAddress(const string& address) {
	this->address = address;
}

const string& Distributor::getName() const {
	return name;
}

void Distributor::setName(const string& name) {
	this->name = name;
}

const string& Distributor::getPhone() const {
	return phone;
}

void Distributor::setPhone(const string& phone) {
	this->phone = phone;
}

ostream& operator<<(ostream& out, const Date& d) {
	//out << '(' << p.get_x() << ',' << p.get_y() << ')';
	out << d.getDay() << "/" << d.getMonth() << "/" << d.getYear();
	return out;
}

ostream& operator<<(ostream& out, const Distributor& p) {
	//out << '(' << p.get_x() << ',' << p.get_y() << ')';
	out << "\"" << p.getName() << "\"\t" << p.getAddress() << "\t"
			<< p.getPhone();
	return out;
}

ostream& operator<<(ostream& out, const Textbook& b) {
	//out << '(' << p.get_x() << ',' << p.get_y() << ')';
	if (b.isApproval()) {
		out << b.getTitle() << " by " << b.getAuthor() << " Edition: "
				<< b.getEdition() << " Issue: " << b.getIssue() << " ISBN: "
				<< b.getIsbn() << " Approved on " << b.getDateofapproval()
				<< " Got out of print on " << b.getOutOfPrint() << " Price:"
				<< b.getPrice();
	} else {
		out << b.getTitle() << " by " << b.getAuthor() << " Edition: "
				<< b.getEdition() << " Issue: " << b.getIssue() << " ISBN: "
				<< b.getIsbn() << " Not approved" << " Got out of print on "
				<< b.getOutOfPrint() << " Price:" << b.getPrice();

	}
	return out;
}

bool isValidName(string name) {
	for (unsigned int i = 0; i < name.length(); i++) {
		if (!((name[i] >= 'a' && name[i] <= 'z')
				|| (name[i] >= 'A' && name[i] <= 'Z') || name[i] == '-')) {

			return false;
		}
	}
	return true;

}

bool isValidNumber(string phone) {
	for (unsigned int i = 0; i < phone.length(); i++) {
		if (!(phone[i] >= '0' && phone[i] <= '9')) {
			return false;
		}
	}
	return true;

}
bool isValidDate(int day, int month, int year) {

	bool isAcceptable;
	if (year > 1000) {
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
				|| month == 10 || month == 12) {
			if (day >= 1 && day <= 31) {
				isAcceptable = true;
			}
		} else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day >= 1 && day <= 30) {
				isAcceptable = true;
			}
		} else if (month == 2 && year % 4 == 0) {
			if (day >= 1 && day <= 29) {
				isAcceptable = true;
			}
		} else if (month == 2 && year % 4 != 0) {
			if (day >= 1 && day <= 28) {
				isAcceptable = true;
			}
		} else
			isAcceptable = false;

		if (!isAcceptable) {
			cout << "Invalid Date!" << endl;
		}

	}
	return isAcceptable;

}

bool isValidPrice(float price) {
	if (!(price > 0.00)) {
		cout << "Invalid price value!" << endl;
	}
	return price > 0.00;
}

void addDistributor(vector<Distributor> &distributors) {

	string name, addres, phone;

	cin.ignore();
	cout << "Please enter the name of the Distributor: \n";
	getline(cin, name);
	cout << "Please enter the address of the Distributor: \n";
	getline(cin, addres);
	cout << "Please enter the phone number of the Distributor: \n";
	getline(cin, phone);
	Distributor distributor(name, addres, phone);
	distributors.push_back(distributor);
	cout << "\nDistributor added successfully!\nTotal numbe of distributors: "
			<< distributors.size() << endl;

}

void addTextbook(vector<Textbook>& textbooks) {

	string approval, title, author, dateOfApproval, ISBN, outOfPrintDate;
	bool app;
	int aday, amonth, ayear, edition, exitday, exitmonth, exityear, issue;
	float price;

	cin.ignore();
	cout << "\nPlease enter the title of the textbook: \n";
	getline(cin, title);
	cout << "\nPlease enter the Author/collective of the textbook: \n";
	getline(cin, author);
	cout << "\nPlease enter the ISBN of the textbook: \n";
	getline(cin, ISBN);
	cout << "\nPlease enter the edition of the textbook: \n";
	cin >> edition;
	cout << "\nPlease enter the issue of the textbook: \n";
	cin >> issue;

	do {
		cout << "\nPlease enter the out of print date in format dd/mm/yyyy"
				<< endl;
		cin >> outOfPrintDate;
		exitday = atoi(outOfPrintDate.substr(0, 2).c_str());
		exitmonth = atoi(outOfPrintDate.substr(3, 2).c_str());
		exityear = atoi(outOfPrintDate.substr(6, 4).c_str());

	} while (!isValidDate(exitday, exitmonth, exityear));

	do {
		cout
				<< "\nHas the ministry of education approved this textbook? : Yes/No\n";
		cin >> approval;
	} while (approval.compare("Yes") && approval.compare("No")
			&& approval.compare("yes") && approval.compare("no"));

	if (!approval.compare("No") || !approval.compare("no")) {
		aday = 0;
		amonth = 0;
		ayear = 0;
		app = false;
	} else {
		do {
			cout
					<< "\nOn which date has the textbook been approved : (dd/mm/yyyy))\n"
					<< endl;
			cin >> dateOfApproval;
			aday = atoi(dateOfApproval.substr(0, 2).c_str());
			amonth = atoi(dateOfApproval.substr(3, 2).c_str());
			ayear = atoi(dateOfApproval.substr(6, 4).c_str());
		} while (!isValidDate(aday, amonth, ayear));

		app = true;
	}

	do {
		cout << "\nPlease enter the price of the textbook:\n" << endl;
		cin >> price;
	} while (!isValidPrice(price));

	Textbook textbook(app, title, author, aday, amonth, ayear, edition, ISBN,
			exitday, exitmonth, exityear, issue, price);

	textbooks.push_back(textbook);
	cout << "\nTextbook added successfully!\nTotal number of books: "
			<< textbooks.size() << endl;

}

void split(const string &s, const char* delim, vector<string> & v) {
	char * dup = strdup(s.c_str());
	char * token = strtok(dup, delim);
	while (token != NULL) {
		v.push_back(string(token));
		token = strtok(NULL, delim);
	}
	free(dup);
}

void buy(vector<Distributor>& distributors, vector<Textbook>& textbooks) {

	float sum = 0.0;
	unsigned int i, j, publ, book;
	do {

		cout << "\nPlease choose a Distributor: " << endl;
		for (i = 0; i < distributors.size(); ++i) {
			cout << i + 1 << ". " << distributors[i] << endl;
		}
		cout << "Choice #: ";
		cin >> publ;
	} while (publ < 0 || publ > distributors.size());

	cout << "Which textbook they want to buy?\n" << endl;

	do {

		cout << "\nPlease choose a book: " << endl;
		for (j = 0; j < textbooks.size(); ++j) {
			cout << j + 1 << ". " << textbooks[j] << endl;
		}
		cout << "0. Done" << endl;
		cout << "Choice #: ";
		cin >> book;
		if (book < 0 || book > textbooks.size()) {
			cout << "Incorrect textbook number!\n" << endl;
		} else if (book == 0) {
			break;
		} else {
			sum += textbooks[book - 1].getPrice();
		}
	} while (book != 0);

	cout << "Total sum: " << sum << endl;

}

void writeToFile(vector<Distributor>& distributors,
		vector<Textbook>& textbooks) {

	ofstream myfile;
	myfile.open("example.txt");
	for (unsigned int var = 0; var < distributors.size(); ++var) {

		myfile << distributors[var].getName() << "\t"
				<< distributors[var].getAddress() << "\t"
				<< distributors[var].getPhone() << endl;
	}
	for (unsigned int i = 0; i < textbooks.size(); ++i) {
		myfile << textbooks[i].isApproval() << "\t" << textbooks[i].getTitle()
				<< "\t" << textbooks[i].getAuthor() << "\t"
				<< textbooks[i].getDateofapproval().getDay() << "\t"
				<< textbooks[i].getDateofapproval().getMonth() << "\t"
				<< textbooks[i].getDateofapproval().getYear() << "\t"
				<< textbooks[i].getEdition() << "\t" << textbooks[i].getIsbn()
				<< "\t" << textbooks[i].getOutOfPrint().getDay() << "\t"
				<< textbooks[i].getOutOfPrint().getMonth() << "\t"
				<< textbooks[i].getOutOfPrint().getYear() << "\t"
				<< textbooks[i].getIssue() << "\t" << textbooks[i].getPrice()
				<< endl;
	}

	myfile.close();
}

void readFromFile(vector<Distributor>& distributors,
		vector<Textbook>& textbooks) {

	ifstream infile;
	string line;
	infile.open("example1.txt");
	distributors.clear();
	textbooks.clear();
	vector<string> tokens;
	while (getline(infile, line)) {
		split(line, "\t", tokens);
		if (tokens.size() == 3) {
			Distributor distributor(tokens[0], tokens[1], tokens[2]);
			distributors.push_back(distributor);

		} else if (tokens.size() == 13) {
			Textbook textbook(stoi(tokens[0]), tokens[1], tokens[2],
					stoi(tokens[3]), stoi(tokens[4]), stoi(tokens[5]),
					stoi(tokens[6]), tokens[7], stoi(tokens[8]),
					stoi(tokens[9]), stoi(tokens[10]), stoi(tokens[11]),
					stof(tokens[12]));
			textbooks.push_back(textbook);
		}
		tokens.clear();
	}
	infile.close();
}

int main() {

	vector<Textbook> textbooks;
	vector<Distributor> distributors;

	Textbook textbook(true, "Integrated Math I", "Ivan Ivanov", 16, 01, 1996, 1,
			"ISBN 123456789", 17, 02, 1997, 2, 10.00);
	Textbook textbook2(true, "Integrated Math II", "Petur Petrov", 10, 03, 2000,
			2, "ISBN 123456788", 15, 02, 2001, 2, 12.00);
	Textbook textbook3(true, "Advanced English", "Georgi Georgiev", 22, 07,
			2001, 1, "ISBN 123456787", 23, 07, 2001, 2, 15.00);
	Textbook textbook4(true, "Geography", "Stefan Stefanov", 29, 12, 1998, 3,
			"ISBN 123456786", 01, 02, 1999, 2, 20.00);
	Textbook textbook5(true, "Bulgarian History", "Dimitur Dimitrov", 02, 11,
			1995, 1, "ISBN 123456785", 15, 04, 1997, 2, 25.00);
	textbooks.push_back(textbook);
	textbooks.push_back(textbook2);
	textbooks.push_back(textbook3);
	textbooks.push_back(textbook4);
	textbooks.push_back(textbook5);

	Distributor distributor("TextBookS", "Opalchenska Street", "0876123456");
	Distributor distributor2("Booktraders", "Mladost 1", "0887823498");
	Distributor distributor3("Bookie", "Vitosha Blvd", "0889121214");
	Distributor distributor4("Books for all", "St Kliment Ohridski Street",
			"0887869675");
	Distributor distributor5("BKS", "Rayna Knyaginya Street", "0887865534");
	distributors.push_back(distributor);
	distributors.push_back(distributor2);
	distributors.push_back(distributor3);
	distributors.push_back(distributor4);
	distributors.push_back(distributor5);

	int choice;

	do {
		cout << "\nMain Menu\n";
		cout << "Please make your selection\n";
		cout << "1 - Add a textbook\n";
		cout << "2 - Add a publisher\n";
		cout << "3 - Buy\n";
		cout << "4 - Write to file\n";
		cout << "5 - Read from file\n";
		cout << "6 - Quit\n";
		cout << "Selection: ";
		cin >> choice;

		switch (choice) {
		case 1:
			addTextbook(textbooks);
			break;
		case 2:
			addDistributor(distributors);
			break;
		case 3:
			buy(distributors, textbooks);
			break;
		case 4:
			writeToFile(distributors, textbooks);
			break;
		case 5:
			readFromFile(distributors, textbooks);
			break;
		case 6:
			cout << "Goodbye!\n";
			break;
		default:
			cout << "\nMain Menu\n";
			cout << "Please make your selection\n";
			cout << "1 - Add a textbook\n";
			cout << "2 - Add a publisher\n";
			cout << "3 - Buy\n";
			cout << "4 - Write to file\n";
			cout << "5 - Read from file\n";
			cout << "6 - Quit\n";
			cout << "Selection: ";
			cin >> choice;
		}
	} while (choice != 6);

	return 0;
}

