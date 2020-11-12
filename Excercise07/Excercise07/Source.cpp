#include "Person.h"
#include "Address.h"
#include "Date.h"
#include <fstream>
#include <sstream>

void save() {
	Person persons[3];

	Date date1(1, 3, 1995);
	Address address1("street1", "city1", 1);
	Person person1("person1", "person1", address1, date1);
	persons[0] = person1;

	Date date2(10, 9, 1984);
	Address address2("street2", "city2", 2);
	Person person2("person2", "person2", address2, date2);
	persons[1] = person2;

	Date date3(9, 8, 1962);
	Address address3("street3", "city3", 3);
	Person person3("person3", "person3", address3, date3);
	persons[2] = person3;

	std::ofstream write;
	write.open("output.txt");
	for (int i = 0; i < 3; i++) {
		write << persons[i] << std::endl;
	}
	write.close();
}

void load() {
	int numberOfLines = 0;
	std::string line;
	std::ifstream read("output.txt");

	while (std::getline(read, line))
		++numberOfLines;

	read.clear();
	read.seekg(0);
	
	Person* persons = new Person[numberOfLines];
	for (int i = 0; i < numberOfLines; i++) {
		std::getline(read, line);
		std::istringstream stream(line);
		Person p;
		stream >> p;
		persons[i] = p;
	} 

	for (int i = 0; i < numberOfLines; i++) {
		std::cout << persons[i] << std::endl;
	}

	delete[] persons;
}

void saveBin() {
	Person persons[3];

	Date date1(1, 3, 1995);
	Address address1("street1", "city1", 1);
	Person person1("person1", "person1", address1, date1);
	persons[0] = person1;

	Date date2(10, 9, 1984);
	Address address2("street2", "city2", 2);
	Person person2("person2", "person2", address2, date2);
	persons[1] = person2;

	Date date3(9, 8, 1962);
	Address address3("street3", "city3", 3);
	Person person3("person3", "person3", address3, date3);
	persons[2] = person3;

	std::ofstream wf("output.dat", std::ios::out | std::ios::binary);
	for (int i = 0; i < 3; i++) {
		wf.write((char*)&persons[i], sizeof(Person));
	}
		

	wf.close();
}

void loadBin() {
	std::ifstream rf("output.dat", std::ios::out | std::ios::binary);
	Person persons[3];
	for (int i = 0; i < 3; i++)
		rf.read((char*)&persons[i], sizeof(Person));
	rf.close();

	for (int i = 0; i < 3; i++)
		std::cout << persons[i] << std::endl;
	
}

int main(char** argv, int argc) {
	save();
	load();
	saveBin();
	loadBin();
	return 0;
}