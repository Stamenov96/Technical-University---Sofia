#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <iomanip>

using namespace std;

/*
 * - Person Name, Position(group),
 * - groups Student,Prophesor,Dean,Director
 * - canteen
 * - food - type(milk,meat)expire date
 * - date - day month year
 */

class Person {
private:
	string name;
	string phone;
	string addres;

public:
	const string& getAddres() const;
	void setAddres(const string& addres);
	const string& getName() const;
	void setName(const string& name);
	const string& getPhone() const;
	void setPhone(const string& phone);
	Person(string name, string phone, string addres);
	~Person();

};

Person::Person(string name, string phone, string address) {

	setName(name);
	setPhone(phone);
	setAddres(address);

}
Person::~Person() {
}
;

class Group {
private:
	string title;
	float discount;
	vector<Person> persons;

public:
	float getDiscount() const;
	void setDiscount(float discount);
	const vector<Person>& getPersons() const;
	void setPersons(const vector<Person>& persons);
	const string& getTitle() const;
	void setTitle(const string& title);
	Group(string title, float discount);
	~Group();

};

Group::Group(string title, float discount) {

	setTitle(title);
	setDiscount(discount);

}
;

Group::~Group() {
}
;

class Food {
private:
	string name;
	string description;
	float price;

public:
	const string& getDescription() const;
	void setDescription(const string& description);
	float getPrice() const;
	void setPrice(float price);
	const string& getName() const;
	void setName(const string& name);
	Food(string title, string description, float price);
	~Food();
};

Food::Food(string name, string description, float price) {

	setName(name);
	setDescription(description);
	setPrice(price);

}
;

Food::~Food() {
}
;

const string& Person::getAddres() const {
	return addres;
}

void Person::setAddres(const string& addres) {
	this->addres = addres;
}

const string& Person::getName() const {
	return name;
}

void Person::setName(const string& name) {
	this->name = name;
}

const string& Person::getPhone() const {
	return phone;
}

void Person::setPhone(const string& phone) {
	this->phone = phone;
}

float Group::getDiscount() const {
	return discount;
}

void Group::setDiscount(float discount) {
	this->discount = discount;
}

const vector<Person>& Group::getPersons() const {
	return persons;
}

void Group::setPersons(const vector<Person>& persons) {
	this->persons = persons;
}

const string& Group::getTitle() const {
	return title;
}

void Group::setTitle(const string& title) {
	this->title = title;
}

const string& Food::getDescription() const {
	return description;
}

void Food::setDescription(const string& description) {
	this->description = description;
}

float Food::getPrice() const {
	return price;
}

void Food::setPrice(float price) {
	this->price = price;
}

const string& Food::getName() const {
	return name;
}

void Food::setName(const string& name) {
	this->name = name;
}

ostream& operator<<(ostream& out, const Food& f) {
	out << f.getName() << "\t" << f.getDescription() << "\t" << f.getPrice()
			<< endl;
	return out;
}

ostream& operator<<(ostream& out, const Person& p) {
	out << p.getName() << "\t" << p.getPhone() << "\t" << p.getAddres();
	return out;
}

ostream& operator<<(ostream& out, const Group& g) {
	out << "Group: " << g.getTitle() << "\t has discount: " << g.getDiscount()
			<< "%" << endl;

	for (unsigned int i = 0; i < g.getPersons().size(); ++i) {
		out << g.getPersons()[i] << endl;
	}
	return out;
}

bool isValidNumber(string phone) {
	for (unsigned int i = 0; i < phone.length(); i++) {
		if (!(phone[i] >= '0' && phone[i] <= '9')) {
			return false;
		}
	}
	return true;

}

bool isNotEmpty(vector<Group> &groups){
	unsigned int i;
	for (i = 0; i < groups.size(); ++i) {
		if(groups[i].getPersons().size()!=0){
			return true;
		}
	}
	return false;


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

void addPerson(vector<Group> &groups) {

	unsigned int choice;

	do {
		cout << "In which group you want to add a person?" << endl;
		for (unsigned int i = 0; i < groups.size(); ++i) {
			cout << i + 1 << "." << groups[i].getTitle() << endl;
		}
		cin >> choice;

	} while (choice < 1 || choice > groups.size());

	string name, addres, phone;

	cin.ignore();
	cout << "Please enter the name of the Person: \n";
	getline(cin, name);
	cout << "Please enter the addres of the Person: \n";
	getline(cin, addres);
	do {
		cout << "Please enter the phone number of the Person: \n";
		getline(cin, phone);
	} while (!isValidNumber(phone));
	Person person(name, addres, phone);
	vector<Person> temp = groups[choice - 1].getPersons();
	temp.push_back(person);
	groups[choice - 1].setPersons(temp);

}

void addGroup(vector<Group> &groups) {

	string title;
	float discount;

	cout << "Please enter the title of the group" << endl;
	cin.ignore();
	getline(cin, title);
	cout << "Please enter the discount of this group in percents" << endl;
	cin >> discount;
	Group gr(title, discount);
	groups.push_back(gr);

}

void addFood(vector<Food> &foods) {
	string title, description;
	float price;

	cout << "Please enter the title of the food" << endl;
	cin.ignore();
	getline(cin, title);
	cout << "Please enter short description" << endl;
	getline(cin, description);
	cout << "Please enter the price" << endl;
	cin >> price;
	Food f(title, description, price);
	foods.push_back(f);

}

void order(vector<Group> &groups, vector<Food> &foods) {

	unsigned int choice;
	float sum, discount;
	bool match = false;
	string name, reg;


	do {
		cout << "Are you registered?  Yes/No:" << endl;
		cin >> reg;
	} while (reg.compare("Yes") && reg.compare("No") && reg.compare("yes")
			&& reg.compare("no"));
	if (!reg.compare("Yes") || !reg.compare("yes")) {
		if(!isNotEmpty(groups)){
			cout<<"Still no registered Persons, please first go register yourself!"<<endl;
		}else{

		cout
				<< "Who are you? Please enter the name that you have been registered in the system. Options:"
				<< endl;
		while (!match) {
			for (unsigned int i = 0; i < groups.size(); ++i) {
				for (unsigned int x = 0; x < groups[i].getPersons().size();
						++x) {
					cout << groups[i].getPersons()[x].getName() << endl;
				}
			}
			cin.ignore();
			getline(cin, name);
			for (unsigned int i = 0; i < groups.size(); ++i) {
				for (unsigned int x = 0; x < groups[i].getPersons().size();
						++x) {
					if (!(groups[i].getPersons()[x].getName().compare(name))) {
						discount = groups[i].getDiscount();
						match = true;
					}
				}
			}
			if (match == false) {
				cout << "Invalid input name!" << endl;
			}
		}
	}
	} else {
		cout << "Please first go and register!" << endl;
	}

	if(match){
	do {
			cout << "Please choose what you want to buy: " << endl;
			for (unsigned int var = 0; var < foods.size(); ++var) {
				cout << var + 1 << "." << foods[var].getName() << "\t"
						<< foods[var].getDescription() << "\t"
						<< foods[var].getPrice() << endl;
			}
			cout << foods.size() + 1 << ".Finish order." << endl;
			cin >> choice;

			if (choice < 1 || choice > foods.size() + 1) {
				cout << "Incorrect choice!\n" << endl;
			} else if (choice == foods.size() + 1) {
				break;
			} else {
				sum += foods[choice - 1].getPrice();
			}

		} while (choice != foods.size() + 1);


		cout << "\n The sum you have to pay is: ";
		cout<<fixed;
		cout<<setprecision(2);
		cout<<(sum - ((sum * discount) / 100));
		cout<< " You have "<< discount<<"% discount" << endl;

	}
}
;

void writeToFile(vector<Group> groups) {

	ofstream myfile;
	myfile.open("output.txt");

	for (unsigned int i = 0; i < groups.size(); ++i) {
		myfile << groups[i].getTitle() << "\t" << groups[i].getDiscount()
				<< endl;
		for (unsigned int x = 0; x < groups[i].getPersons().size(); ++x) {
			myfile << groups[i].getPersons()[x].getName() << "\t"
					<< groups[i].getPersons()[x].getPhone() << "\t"
					<< groups[i].getPersons()[x].getPhone() << endl;
		}
	}
	myfile.close();
}

void readFromFile(vector<Group> &groups) {

	ifstream infile;
	string line;
	infile.open("input.txt");
	groups.clear();
	vector<string> tokens;
	while (getline(infile, line)) {
		split(line, "\t", tokens);
		if (tokens.size() == 2) {
			Group gr(tokens[0], stof(tokens[1]));
			groups.push_back(gr);
		} else if (tokens.size() == 3) {
			Person person(tokens[0], tokens[1], tokens[2]);
			//cout<<"TOKENS: "<<tokens[0]<<" , "<<tokens[1]<<" , "<<tokens[2]<<endl;
			vector<Person> persons = groups[groups.size() - 1].getPersons();
			persons.push_back(person);
			groups[groups.size() - 1].setPersons(persons);

		}
		tokens.clear();
	}
	infile.close();
}

int main() {

	vector<Group> groups;
	vector<Food> foods;

	Food food("Garash", "Shokoladova torta garash", 3.40);
	Food food1("Oriz s meso i zelenchuci", "Kitaiski oriz s pileshko", 5.20);
	Food food2("Banitsa", "Banitsa s praz", 1.20);
	Food food3("Banan", "Banan za desert", 0.80);
	Food food4("Bob s nadenica", "Bob s nadenica zapechen na furna", 7.20);
	foods.push_back(food);
	foods.push_back(food1);
	foods.push_back(food2);
	foods.push_back(food3);
	foods.push_back(food4);

	Group student("Students", 5.0);
	Group assistant("Assistant", 15.0);
	Group dean("Dean", 20.0);

	groups.push_back(student);
	groups.push_back(assistant);
	groups.push_back(dean);

	int choice;

	do {
		cout << "Main Menu\n";
		cout << "Please make your selection\n";
		cout << "1 - Add a person\n";
		cout << "2 - Add a group\n";
		cout << "3 - Make order\n";
		cout << "4 - Write to file\n";
		cout << "5 - Read from file\n";
		cout << "6 - Add a food\n";
		cout << "7 - Quit\n";
		cout << "Selection: ";
		cin >> choice;

		switch (choice) {
		case 1:
			addPerson(groups);
			break;
		case 2:
			addGroup(groups);
			break;
		case 3:
			order(groups, foods);
			break;
		case 4:
			writeToFile(groups);
			break;
		case 5:
			readFromFile(groups);
			break;
		case 6:
			addFood(foods);
			break;
		case 7:
			cout << "Goodbye!";
			break;
		default:
			cout << "Main Menu\n";
			cout << "Please make your selection\n";
			cout << "1 - Add a person\n";
			cout << "2 - Add a group\n";
			cout << "3 - Make order\n";
			cout << "4 - Write to file\n";
			cout << "5 - Read from file\n";
			cout << "6 - Add a food\n";
			cout << "7 - Quit\n";
			cout << "Selection: ";
			cin >> choice;
		}
	} while (choice != 7);

	return 0;
}

