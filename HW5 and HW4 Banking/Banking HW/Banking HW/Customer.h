#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <string>

/**
The Bank has Customers.  Each Customer has a name, address, age, and telephone number.
Additionally, there are specialized types of Customers: Adult, Senior, and Student.
Each type of Customer has its own checking and savings interest rates,
as well as its own checking and overdraft fees.

@author: Ed Walker
*/
class Customer // FIXME: Complete the implementation!
{
private:
	


protected:
	int age;
	std::string telephone;
	std::string address;
	std::string name;
	std::string cust_type; //used in add_account() function as aparameter relating to inheriting classes of customer type
	std::string account_type; //used in add_account() equals "adult, senior or student" 
public:
	Customer(std::string name, std::string address, std::string telephone, int age, std::string cust_type, std::string account_type) { //Constructor
		this->name = name;
		this->age = age;
		this->cust_type = cust_type;
		this->telephone= telephone;
		this->address = address;
		this->account_type = account_type;
	}

	int getAge() {
		return age;
	}
	void setAge(int age) {
		this->age = age;
	}

	std::string getCustomerNumber() {
		return cust_type;
	}
	void setCustomerNumber(int customer_number) {
		this->cust_type = customer_number;
	}

	std::string getTelephone() {
		return telephone;
	}
	void setTelephoneNumber(std::string telephone) {
		this->telephone = telephone;
	}

	std::string getName() {
		return name;
	}
	std::string setName(std::string name) {
		this->name = name;
	}

	std::string getAddress() {
		return address;
	}
	std::string setAddress(std::string address) {
		this->address = address;
	}

	std::string getCustType(std::string cust_type) { //for fees 
		return cust_type;
	}

	std::string getAccountType(std::string account_type) {
		return account_type;
	}

	virtual double CHECK_CHARGE() = 0;
	virtual double CHECKING_INTEREST() = 0;
	virtual double OVERDRAFT_PENALTY() = 0;
	virtual double SAVINGS_INTEREST() = 0;
};
// use variable cust_type
class Adult : public Customer {
public:
	Adult(std::string name, std::string address,std::string telephone, int age, std::string cust_type, std::string account_type) :Customer(name, address, telephone, age, cust_type, account_type) {}
	
	double CHECKING_INTEREST() {//take amount in checking account and add interest of that amount. return balance

		return NULL;
	}
	double CHECK_CHARGE() {
		return NULL;
	}
	double OVERDRAFT_PENALTY() {
		return NULL;
	}
	double SAVINGS_INTEREST() {
		return NULL;
	}
};

class Student : public Customer {
public:
	Student(std::string name, std::string address, std::string telephone, int age, std::string cust_type, std::string account_type) :Customer(name, address, telephone, age, cust_type, account_type) {}
	
	double CHECKING_INTEREST() {
		return NULL;
	}
	double CHECK_CHARGE() {
		return NULL;
	}
	double OVERDRAFT_PENALTY() {
		return NULL;
	}
	double SAVINGS_INTEREST() {
		return NULL;
	}
};

class Senior : public Customer {
public:
	Senior(std::string name, std::string address, std::string telephone, int age, std::string cust_type, std::string account_type) :Customer(name, address, telephone, age, cust_type, account_type) {}
	
	double CHECKING_INTEREST() {
		return NULL;
	}
	double CHECK_CHARGE() {
		return NULL;
	}
	double OVERDRAFT_PENALTY() {
		return NULL;
	}
	double SAVINGS_INTEREST() {
		return NULL;
	}
};


#endif