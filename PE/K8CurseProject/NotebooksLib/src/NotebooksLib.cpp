//============================================================================
// Name        : NotebooksLib.cpp
// Author      : Ekaterina Stamatova
// Version     :
// Copyright   : Your copyright notice
// Description : Curse project in C++, Ansi-style
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

class Publisher {
private:
	string name;
	string address;
	string phone;
	vector<Textbook> textbooks;

public:
	const string& getAddress() const;
	void setAddress(const string& address);
	const string& getName() const;
	void setName(const string& name);
	const string& getPhone() const;
	void setPhone(const string& phone);
	const vector<Textbook>& getTextbooks() const;
	void setTextbooks(const vector<Textbook>& textbooks);
	Publisher(string name, string address, string phone);
	~Publisher();
};

Publisher::Publisher(string name, string address, string phone) {
	setName(name);
	setAddress(address);
	setPhone(phone);
}
;

Publisher::~Publisher() {
}
;

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

const string& Publisher::getAddress() const {
	return address;
}

void Publisher::setAddress(const string& address) {
	this->address = address;
}

const string& Publisher::getName() const {
	return name;
}

void Publisher::setName(const string& name) {
	this->name = name;
}

const string& Publisher::getPhone() const {
	return phone;
}

const vector<Textbook>& Publisher::getTextbooks() const {
	return textbooks;
}

void Publisher::setTextbooks(const vector<Textbook>& textbooks) {
	this->textbooks = textbooks;

}

void Publisher::setPhone(const string& phone) {
	this->phone = phone;
}

ostream& operator<<(ostream& out, const Date& d) {
	//out << '(' << p.get_x() << ',' << p.get_y() << ')';
	out << d.getDay() << "/" << d.getMonth() << "/" << d.getYear();
	return out;
}

ostream& operator<<(ostream& out, const Publisher& p) {
	//out << '(' << p.get_x() << ',' << p.get_y() << ')';
	out << p.getName() << "\t" << p.getAddress() << "\t" << p.getPhone();
	return out;
}

ostream& operator<<(ostream& out, const Textbook& b) {
	//out << '(' << p.get_x() << ',' << p.get_y() << ')';
	if (b.isApproval()) {
		out << b.getTitle() << " by " << b.getAuthor() << " Edition: "
				<< b.getEdition() << " Issue: " << b.getIssue() << " ISBN: "
				<< b.getIsbn() << " Approved on " << b.getDateofapproval()
				<< " Get out of print on " << b.getOutOfPrint() << " Price:"
				<< b.getPrice();
	} else {
		out << b.getTitle() << " by " << b.getAuthor() << " Edition: "
				<< b.getEdition() << " Issue: " << b.getIssue() << " ISBN: "
				<< b.getIsbn() << " Not approved" << " Get out of print on "
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
	if (year > 0) {
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

void addPublisher(vector<Publisher> &publishers) {

	string name, addres, phone;

	cin.ignore();
	cout << "Please enter the name of the publisher: \n";
	getline(cin, name);
	cout << "Please enter the addres of the publisher: \n";
	getline(cin, addres);
	cout << "Please enter the phone number of the publisher: \n";
	getline(cin, phone);
	Publisher publisher(name, addres, phone);
	publishers.push_back(publisher);

}

void addTextbook(vector<Publisher>& publishers) {

	string approval, title, author, dateOfApproval, ISBN, outOfPrintDate;
	bool app;
	int aday, amonth, ayear, edition, exitday, exitmonth, exityear, issue;
	float price;

	cin.ignore();
	cout << "Please enter the title of the textbook: \n";
	getline(cin, title);
	cout << "Please enter the Author/collective of the textbook: \n";
	getline(cin, author);
	cout << "Please enter the ISBN of the textbook: \n";
	getline(cin, ISBN);
	cout << "Please enter the edition of the textbook: \n";
	cin >> edition;
	cout << "Please enter the issue of the textbook: \n";
	cin >> issue;

	do {
		cout << "Please enter the out of print date in format dd/mm/yyyy"
				<< endl;
		cin >> outOfPrintDate;
		exitday = atoi(outOfPrintDate.substr(0, 2).c_str());
		exitmonth = atoi(outOfPrintDate.substr(3, 2).c_str());
		exityear = atoi(outOfPrintDate.substr(6, 4).c_str());

	} while (!isValidDate(exitday, exitmonth, exityear));

	do {
		cout
				<< "Does the ministry of education approved this textbook? : Yes/No\n";
		cin >> approval;
	} while (approval.compare("Yes") && approval.compare("No")
			&& approval.compare("yes") && approval.compare("no"));

	if (!approval.compare("No")) {
		aday = 0;
		amonth = 0;
		ayear = 0;
		app = false;
	} else {
		do {

			cout
					<< "On which date the textbook has been approved : (dd/mm/yyyy))"
					<< endl;
			cin >> dateOfApproval;
			aday = atoi(dateOfApproval.substr(0, 2).c_str());
			amonth = atoi(dateOfApproval.substr(3, 2).c_str());
			ayear = atoi(dateOfApproval.substr(6, 4).c_str());
		} while (!isValidDate(aday, amonth, ayear));

		app = true;
	}

	do {
		cout << "Please enter the price of the textbook: " << endl;
		cin >> price;
	} while (!isValidPrice(price));

	Textbook textbook(app, title, author, aday, amonth, ayear, edition, ISBN,
			exitday, exitmonth, exityear, issue, price);

	unsigned int i, publ;
	do {

		cout << "Please choose the publisher of the book: " << endl;
		cout << "0.Add a new publisher" << endl;
		for (i = 0; i < publishers.size(); ++i) {
			cout << publishers[i] << endl;
		}
		cout
				<< "Warning! If you choose to add new publisher the information about the new book will be lost."
				<< endl;
		cin >> publ;
	} while (publ < 0 || publ > publishers.size());

	if (publ == 0) {
		addPublisher(publishers);
	} else {
		vector<Textbook> textbooks = publishers[publ - 1].getTextbooks();
		textbooks.push_back(textbook);
		publishers[publ - 1].setTextbooks(textbooks);
	}
	cout << "SIZE AFTER ADD" << publishers[0].getTextbooks().size() << endl;

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

void buy(vector<Publisher>& publishers) {

	float sum = 0.0;
	unsigned int i, publ, book = -1;
	do {

		cout << "Please choose the publisher of the book: " << endl;
		for (i = 0; i < publishers.size(); ++i) {
			cout << publishers[i] << endl;
		}
		cin >> publ;
	} while (publ < 0 || publ > publishers.size());

	//Publisher publisher= ;
	vector<Textbook> textbooks = publishers[publ - 1].getTextbooks();
	cout << "size: " << textbooks.size() << endl;
	cout << "Which textbook you want to buy?" << endl;

	while (book != 0) {
		cout << "0.Done." << endl;
		for (i = 0; i < textbooks.size(); ++i) {
			cout << textbooks[i] << endl;
		}
		cin >> book;

		if (book < 1 || book > textbooks.size()) {
			cout << "Incorrect textbook number!" << endl;
		} else {
			sum += textbooks[book - 1].getPrice();
		}
	}
	cout << "Total: " << sum << endl;
}

void writeToFile(vector<Publisher>& publishers) {

	ofstream myfile;
	myfile.open("example.txt");
	for (unsigned int var = 0; var < publishers.size(); ++var) {

		myfile << publishers[var].getName() << "\t"
				<< publishers[var].getAddress() << "\t"
				<< publishers[var].getPhone() << endl;
		vector<Textbook> temp = publishers[var].getTextbooks();

		for (unsigned int i = 0; i < temp.size(); ++i) {
			myfile << temp[i].isApproval() << "\t" << temp[i].getTitle() << "\t"
					<< temp[i].getAuthor() << "\t"
					<< temp[i].getDateofapproval().getDay() << "\t"
					<< temp[i].getDateofapproval().getMonth() << "\t"
					<< temp[i].getDateofapproval().getYear() << "\t"
					<< temp[i].getEdition() << "\t" << temp[i].getIsbn() << "\t"
					<< temp[i].getOutOfPrint().getDay() << "\t"
					<< temp[i].getOutOfPrint().getMonth() << "\t"
					<< temp[i].getOutOfPrint().getYear() << "\t"
					<< temp[i].getIssue() << "\t" << temp[i].getPrice() << endl;
		}
	}
	myfile.close();
}

void readFromFile(vector<Publisher>& publishers) {

	ifstream infile;
	string line;
	infile.open("example1.txt");
	publishers.clear();
	vector<string> tokens;
	vector<Textbook> textbooks;
	while (getline(infile, line)) {
		split(line, "\t", tokens);
		if (tokens.size() == 3) {

			cout << "TOKENS SIZE 3" << endl;
			Publisher publisher(tokens[0], tokens[1], tokens[2]);
			publishers.push_back(publisher);
			textbooks.clear();

		} else if (tokens.size() == 13) {
			cout << "TOKENS SIZE 13" << endl;
			Textbook textbook(stoi(tokens[0]), tokens[1], tokens[2],
					stoi(tokens[3]), stoi(tokens[4]), stoi(tokens[5]),
					stoi(tokens[6]), tokens[7], stoi(tokens[8]),
					stoi(tokens[9]), stoi(tokens[10]), stoi(tokens[11]),
					stof(tokens[12]));
			textbooks.push_back(textbook);
			cout << "ASSIGN TO PUBLISHEN NUM: "
					<< publishers[publishers.size() - 1] << endl;
			publishers[publishers.size() - 1].setTextbooks(textbooks);
		}
		tokens.clear();
	}
	infile.close();
	cout << "PUBLISHER 0: " << publishers[0].getTextbooks().size() << endl;
}

int main() {

	vector<Textbook> textbooks;
	Textbook textbook(true, "Math", "Stefan", 16, 01, 1996, 1,
			"blabla::blabla", 17, 02, 2000, 2, 10.00);
	Textbook textbook2(true, "Math2", "Stefan", 16, 01, 1996, 1,
			"blabla::blabla", 17, 02, 2000, 2, 12.00);
	Textbook textbook3(true, "Math3", "Stefan", 16, 01, 1996, 1,
			"blabla::blabla", 17, 02, 2000, 2, 15.00);
	Textbook textbook4(true, "Math4", "Stefan", 16, 01, 1996, 1,
			"blabla::blabla", 17, 02, 2000, 2, 20.00);
	Textbook textbook5(true, "Math5", "Stefan", 16, 01, 1996, 1,
			"blabla::blabla", 17, 02, 2000, 2, 25.00);
	textbooks.push_back(textbook);
	textbooks.push_back(textbook2);
	textbooks.push_back(textbook3);
	textbooks.push_back(textbook4);
	textbooks.push_back(textbook5);

	vector<Publisher> publishers;

	Publisher publisher("Stefan", "Raina Knyagina", "0887869634");
	publisher.setTextbooks(textbooks);
	Publisher publisher2("Stefan2", "Raina Knyagina", "0887869634");
	Publisher publisher3("Stefan3", "Raina Knyagina", "0887869634");
	Publisher publisher4("Stefan4", "Raina Knyagina", "0887869634");
	Publisher publisher5("Stefan5", "Raina Knyagina", "0887869634");
	publishers.push_back(publisher);
	publishers.push_back(publisher2);
	publishers.push_back(publisher3);
	publishers.push_back(publisher4);
	publishers.push_back(publisher5);

	int choice;

	do {
		cout << "Main Menu\n";
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
			addTextbook(publishers);
			break;
		case 2:
			addPublisher(publishers);
			break;
		case 3:
			buy(publishers);
			break;
		case 4:
			writeToFile(publishers);
			break;
		case 5:
			readFromFile(publishers);
			break;
		case 6:
			cout << "Goodbye!";
			break;
		default:
			cout << "Main Menu\n";
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

