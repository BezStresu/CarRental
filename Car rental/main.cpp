#include <stdio.h>
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <map>
#include <string>
#include <time.h>
#include <cstdlib>
#include "Car.h"
#include "CarBase.h"
#include "Customer.h"
#include "CustomerBase.h"
#include "Rent.h"
#include "RentBase.h"
#include "Screen.h"

using namespace std;
void main_menu();
void m1_admin();
void m2_admin();
void adding_car(CarBase& c_base);
void delating_car();
void m1_user();
void loggin_in();
void user_menu();
void registration(RentBase& r_base, CustomerBase& c_base);
bool car_available(shared_ptr<Car>& abc);

CarBase CAR_base;
CustomerBase CUS_base;
RentBase RENT_base;
Rent Ren;

void main_menu() {
	while (true) {
		string a;
		Boarder();
		art();
		gotoxy(50, 34);
		cout << "1. Admin" << endl;
		gotoxy(50, 35);
		cout << "2. User" << endl;
		gotoxy(50, 36);
		cout << "3. Car Base" << endl;
		gotoxy(50, 37);
		cout << "4. Exit" << endl;
		gotoxy(50, 41);
		cout << "INPUT: ";
		cin >> a;
		vector<string> ans;
		ans.push_back("1");
		ans.push_back("2");
		ans.push_back("3");
		ans.push_back("4");
		if(check_option(a,ans) == true){
			if (a == "1") {
				m1_admin();
			}
			else if (a == "2") {
				m1_user();
			}
			else if (a == "3") {
				Boarder();
				art();
				CAR_base.upload_base();
				CAR_base.show_base();
				gotoxy(30,56);
				system("pause");
				main_menu();
			}
			else if (a == "4") {
				exit_imag();
				break;
			}

		}
		else
		{
			continue;
		}
	}
	
};

void m1_admin() {
	int atempt = 0;
	while (true) {
		if (atempt == 3) {
			Boarder();
			gotoxy(30, 30);
			cout << "Unfortunately, you have exceeded the possible number of attempts" << endl;
			gotoxy(30, 32);
			cout << "You will be taken to the main menu";
			gotoxy(30, 35);
			cout << "Before the next login attempt, make sure you know the data necessary to";
			gotoxy(30, 36);
			cout << "access the rental from the admin level";
			Sleep(5000);	
			main_menu();
			break;

		}
		string a = "";
		string b = "";
		bool admin = false;
		bool pass = false;
		Boarder();
		art();
		gotoxy(30, 34);
		cout << "Welcome to the admin menu where you can add and remove cars" << endl;
		gotoxy(30, 35);
		cout << "as well as access and manage the user database." << endl;
		gotoxy(30, 36);
		cout << "Enter the correct login and password, after entering the relevant data three times" << endl;
		gotoxy(30, 37);
		cout << "you will be taken to the main menu" << endl;
		gotoxy(30, 48);
		cout << "Type q in login to back to main menu";
		gotoxy(30, 40);
		cout << "Login: ";
		cin >> a;
		if(a == "q"){
			main_menu();
		}
		gotoxy(40, 40);
		cout << "\t" << "Password: ";
		cin >> b;

		if (a == "admin") {
			admin = true;
		}
		if (b == "1234") {
			pass = true;
		}
		if (admin && pass) {
			m2_admin();
		}
		else
		{
			++atempt;
			continue;
		}
		gotoxy(30, 40);


		system("pause");
	};
};

void m2_admin(){
	pre_login();
	Boarder();
	art();
	string a;
	vector<string> ans;
	ans.push_back("1"); 
	ans.push_back("2"); 
	ans.push_back("3"); 
	ans.push_back("4"); 
	ans.push_back("5"); 
	ans.push_back("q"); 
	gotoxy(30,34);
	cout << "1. Add car to car's base"; 
	gotoxy(30,35);
	cout << "2. Delate car from car's base";
	gotoxy(30,36);
	cout << "3. Show car's base";
	gotoxy(30,37);
	cout << "4. Show rent's base";
	gotoxy(30,38);
	cout << "5. Show customer's base";
	gotoxy(30,39);
	cout << "Type q to go back to main menu";
	gotoxy(30,41);
	cout << "INPUT: ";
	cin >> a;
	if(check_option(a,ans)){
		if(a == "1"){
			adding_car(CAR_base);
		}
		else if(a == "2"){
			delating_car();
		}
		else if(a == "3"){
			Boarder();
			art();
			CAR_base.upload_base();
			CAR_base.show_base();
			gotoxy(30,56);
			system("pause");
			m2_admin();
		}
		else if(a == "4"){
			Boarder();
			art();
			RENT_base.upload_rent_base();
			RENT_base.show_whole_base();
			gotoxy(30,56);
			system("pause");
			m2_admin();
		}
		else if(a == "5"){
			Boarder();
			art();
			CUS_base.upload_cus_base();
			CUS_base.show_cus_base();
			gotoxy(30,56);
			system("pause");
			m2_admin();
		}
		else if(a == "q"){
			main_menu();
		}
	}
};


void adding_car(CarBase& c_base){
	shared_ptr<Car> n_car = make_shared<Car>();
	string line;
	Boarder();
	art();
	gotoxy(30, 35);
	cout << "Plate: "; cin >> line; n_car->set_plate(line);
	gotoxy(30, 36);
	cout << "Class: "; cin >> line; n_car->set_class(line);
	gotoxy(30, 37);
	cout << "Type: "; cin >> line; n_car->set_type(line);
	gotoxy(30, 38);
	cout << "Brand: "; cin >> line; n_car->set_type(line);
	gotoxy(30, 39);
	cout << "Model : "; cin >> line; n_car->set_model(line);
	gotoxy(30, 40);
	cout << "Color : "; cin >> line; n_car->set_color(line);
	gotoxy(30, 41);
	cout << "Fuel : "; cin >> line; n_car->set_fuel(line);
	gotoxy(30, 42);
	cout << "Transmission : "; cin >> line; n_car->set_transmission(line);
	gotoxy(30, 43);
	cout << "Year : "; cin >> line; n_car->set_year(line);
	gotoxy(30, 44);
	cout << "Engine : "; cin >> line; n_car->set_engine(line);
	gotoxy(30, 45);
	cout << "Horse power : "; cin >> line; n_car->set_hp(line);
	gotoxy(30, 46);
	cout << "Number of seats : "; cin >> line; n_car->set_seats(line);
	gotoxy(30, 47);
	cout << "Price per 24 hours : "; cin >> line; n_car->set_price(line);
	n_car->set_borrowed(false);
	c_base.add_car(n_car);
	gotoxy(30,50);
	cout << "Car has been added successfully";
	Sleep(3000);		
	m2_admin();
};

void delating_car(){
	Boarder();
	art();
	gotoxy(30,33);
	string a;
	cout << "Type a number plate of car you want to delate, type q if you want go back";
	CAR_base.show_base();
	gotoxy(30,50);
	cout << "INPUT: "; cin >> a;
	vector<string> ans;
	if(a == "q"){
		m2_admin();
	}
	for(size_t i = 0; i < CAR_base.get_base_size(); ++i){
		ans.push_back(CAR_base.get_car(i)->get_plate());
	}

	if(check_option(a,ans)){
		CAR_base.delate_car(a);
		Boarder();
		art();
		gotoxy(30,35);
		cout << "Car has been delated successfully";
		Sleep(3000);	
		m2_admin();
	}
	else
	{
		Boarder();
		art();
		gotoxy(30,36);
		cout << "We don't have car with this plate, please look to the list and";
		gotoxy(30,37);
		cout << "choose one of existing car";
		Sleep(3000);	
		delating_car();
	}

};

void m1_user(){
	Boarder();
	art();
	gotoxy(30,34);
	string a;
	vector<string> ans;
	ans.push_back("1");
	ans.push_back("2");
	cout << "Welcone to user menu, you can log in if you have created an account already";
	gotoxy(30,35);
	cout << "or you can create a new account in our system, type q to back to main menu";
	gotoxy(30,38);
	cout << "1. Log in to existing account";
	gotoxy(30,39);
	cout << "2. Register a new account";
	gotoxy(30,42);
	cout << "INPUT: ";
	cin >> a;
	if(a == "q"){
		main_menu();
	}
	else if(check_option(a,ans)){
		if(a == "1"){
			loggin_in();
		};

		if (a == "2")
		{
			registration(RENT_base, CUS_base);
		}
		
	}
	else
	{
		m1_user();
	}

};

int numofuser;

void loggin_in(){
	int atemp;
	string a = "";
	string b = "";
	vector<string> ans;
	bool login = false;
	bool pass = false;
	Boarder();
	art();
	for(size_t i = 0; i < RENT_base.get_base_size(); ++i){
		ans.push_back(RENT_base.get_one_rent(i)->get_rent_cus()->get_id());

	}
	while(true){
		if(atemp == 3){
			Boarder();
			art();
			gotoxy(30,34);
			cout << "you have used all possible approaches, remember the data and enter it";
			Sleep(3000);	
			m1_user();
		};
		gotoxy(30, 34);
		cout << "Welcome to the log in menu where you can get acces to your account" << endl;
		gotoxy(30, 35);
		cout << "if we do not have a given account in our database, you will be" << endl;
		gotoxy(30, 36);
		cout << "informed about it, entering the wrong password will also activate the" << endl;
		gotoxy(30, 37);
		cout << "message, after 3 unsuccessful attempts you will be transferred to the main menu" << endl;
		gotoxy(30, 38);
		cout << "Type q in login to back to main menu";
		gotoxy(30, 40);
		cout << "Login: ";
		cin >> a;
		if(a == "q"){
			main_menu();
		}
		gotoxy(40, 40);
		cout << "\t" << "Password: ";
		cin >> b;
		for(size_t i = 0; i < RENT_base.get_base_size(); ++i){
			RENT_base.get_one_rent(i)->get_rent_cus()->get_id();
			if(a == RENT_base.get_one_rent(i)->get_rent_cus()->get_id() && b == RENT_base.get_one_rent(i)->get_rent_cus()->get_password()){
				login = true;
				pass = true;
				numofuser = i;
				break;
			}
			else if(a == RENT_base.get_one_rent(i)->get_rent_cus()->get_id() && b != RENT_base.get_one_rent(i)->get_rent_cus()->get_password()){
				login = true;
				pass = false;
			}
			else
			{

				login = false;
				pass = false;
			}
		}

		if(login == true && pass == true){
			user_menu();
		}
		else if(login == true && pass == false)
		{

			Boarder();
			art();
			gotoxy(30,36);
			cout << "The password is wrong, try again";
			++atemp;
		}
		else if(login == false && pass == false){
			Boarder();
			art();
			gotoxy(30, 36);
			cout << "We haven't registered yet, do it now";
			Sleep(3000);	
			m1_user();
		}


	}



};

void user_menu(){
	Boarder();
	art();
	gotoxy(30,34);
	cout << "Hello " << RENT_base.get_one_rent(numofuser)->get_rent_cus()->get_fname() << " it is nice to see you" << endl;
	string a;
	vector<string> ans;
	ans.push_back("1");
	ans.push_back("2");
	ans.push_back("3");
	ans.push_back("4");
	ans.push_back("q");
	gotoxy(30, 37);
	cout << "1. Rent a car";
	gotoxy(30, 38);
	cout << "2. Return a car";
	gotoxy(30, 39);
	cout << "3. Show rented cars";
	gotoxy(30, 40);
	cout << "4. Show my data";
	gotoxy(30, 41);
	cout << "Type q to logout";
	gotoxy(30, 43);
	cout << "INPUT: ";
	cin >> a;
	if(check_option(a, ans)){
		if(a == "1"){
			string b;
			vector<string> bns;
			Boarder();
			art();
			CAR_base.show_base();
			gotoxy(30,45);
			cout << "Choose car by number";
			gotoxy(30,46);
			cout << "Type q to quit";
			gotoxy(30,47);
			cout << "INPUT: ";
			cin >> b;
			bns.push_back("q");
			if(b == "q"){
				user_menu();
			}
			bns.push_back("1");
			bns.push_back("2");
			bns.push_back("3");
			bns.push_back("4");
			bns.push_back("5");
			bns.push_back("6");
			bns.push_back("7");
			bns.push_back("8");
			bns.push_back("9");
			bns.push_back("11");
			bns.push_back("12");
			bns.push_back("13");
			bns.push_back("14");
			bns.push_back("15");
			bns.push_back("16");
			if(check_option(b,bns)){

				int p = stoi(b) - 1;
				if(car_available(CAR_base.get_car(p))){
					CAR_base.get_car(p)->set_borrowed(true);
					RENT_base.get_one_rent(numofuser)->get_rent_cars().push_back(CAR_base.get_car(p));
					CAR_base.update_base();
					RENT_base.update_rent_base();
					Boarder();
					art();
					gotoxy(30,35);
					cout << "Car rented succesfully" << endl;
					Sleep(5000);	
					user_menu();
				}
				else
				{
					Boarder();
					art();
					gotoxy(30,35);
					cout << "Car is rented, you can't rent it" << endl;
					Sleep(3000);
					user_menu();
				}
			}
			else
			{
				user_menu();
			}


		}
		else if (a == "2")
		{
			
			string c;
			vector<string> cns;
			Boarder();
			art();
			RENT_base.get_one_rent(numofuser)->show_rent();
			gotoxy(30,45);
			cout << "Choose car by number";
			gotoxy(30,46);
			cout << "Type q to quit";
			gotoxy(30,47);
			cout << "INPUT: ";
			cin >> c;
			cns.push_back("q");
			if(c == "q"){
				user_menu();
			}
			cns.push_back("1");
			cns.push_back("2");
			cns.push_back("3");
			cns.push_back("4");
			cns.push_back("5");
			cns.push_back("6");
			cns.push_back("7");
			cns.push_back("8");
			cns.push_back("9");
			cns.push_back("11");
			int p1 = stoi(c) - 1;
			if(check_option(c,cns)){
				int p1 = stoi(c) - 1;
				Boarder();
				art();
				for(int i = 0; i < CAR_base.get_base_size(); ++i){
					if(RENT_base.get_one_rent(numofuser)->get_one_rent_car(p1)->get_plate() == CAR_base.get_car(i)->get_plate()){
						CAR_base.get_car(i)->set_borrowed(false);
						RENT_base.get_one_rent(numofuser)->get_rent_cars().erase(RENT_base.get_one_rent(numofuser)->get_rent_cars().begin() + p1);
						break;
					}
				}
				CAR_base.update_base();
				RENT_base.update_rent_base();
				gotoxy(30,35);
				cout << "Car returned succesfully" << endl;
				Sleep(5000);
				user_menu();

			}
			else
			{
				user_menu();
			}
		}
		else if (a == "3")
		{
			Boarder();
			art();
			RENT_base.get_one_rent(numofuser)->show_rent();
			gotoxy(30, 50);
			system("pause");
			user_menu();
		}
		else if (a == "4")
		{
			Boarder();
			art();
			gotoxy(30,34);
			cout << RENT_base.get_one_rent(numofuser)->get_rent_cus()->get_id();
			gotoxy(30,35);
			cout << RENT_base.get_one_rent(numofuser)->get_rent_cus()->get_password();
			gotoxy(30,36);
			cout << RENT_base.get_one_rent(numofuser)->get_rent_cus()->get_fname();
			gotoxy(30,37);
			cout << RENT_base.get_one_rent(numofuser)->get_rent_cus()->get_lname();
			gotoxy(30,38);
			cout << RENT_base.get_one_rent(numofuser)->get_rent_cus()->get_age();
			gotoxy(30,39);
			cout << RENT_base.get_one_rent(numofuser)->get_rent_cus()->get_mail();
			gotoxy(30,40);
			cout << RENT_base.get_one_rent(numofuser)->get_rent_cus()->get_phone_number() << endl;
			gotoxy(30,50);
			system("pause");
			user_menu();
		}
		else if (a == "q")
		{
			loggin_in();
		}
		
		
	}
	else{
		user_menu();
	}
};


void registration(RentBase& r_base, CustomerBase& c_base){
	shared_ptr<Rent> new_rent = make_shared<Rent>();
	shared_ptr<Customer> new_cus = make_shared<Customer>();
	vector<shared_ptr<Car>> new_cars;
	string line;
	Boarder();
	art();
	gotoxy(30,35);
	cout << "Welcome to registration menu, you can create your's private account in our system";
	gotoxy(30,36);
	cout << "Plase enter all required data";
	gotoxy(30,38); 
	cout << "First name: "; cin >> line; new_cus->set_fname(line);
	gotoxy(30,39); 
	cout << "Last name: "; cin >> line; new_cus->set_lname(line);
	gotoxy(30,40); 
	cout << "Age: "; cin >> line; new_cus->set_age(line);
	gotoxy(30,41); 
	cout << "Adress e-mail: "; cin >> line; new_cus->set_mail(line);
	gotoxy(30,42); 
	cout << "Password: "; cin >> line; new_cus->set_password(line);
	gotoxy(30,43); 
	cout << "Phone number: "; cin >> line; new_cus->set_phone_number(line);
	new_cus->create_uniqe_id();
	new_rent->set_rent_cus(new_cus);
	new_rent->set_rent_cars(new_cars);
	c_base.add_customer(new_rent->get_rent_cus());
	r_base.add_rent(new_rent);
	Boarder();
	art();
	gotoxy(30,34);
	cout << "Congratulations, you have created an account in our";
	gotoxy(30,35);
	cout << "system and from now on you can rent cars, you will be taken to the login menu";
	gotoxy(30,36);
	cout << "Your login is your uniq ID: " << new_rent->get_rent_cus()->get_id() << endl;
	Sleep(3000); 
	gotoxy(30,40);
	system("pause");
	loggin_in();


};

bool car_available(shared_ptr<Car>& abc){
	if(abc->get_borrowed() == true){
		return false;
	}
	else
	{
		return true;
	}
};






int main()
{
	CAR_base.upload_base();
	CUS_base.upload_cus_base();		
	RENT_base.upload_rent_base();
	setlocale(LC_CTYPE, "Polish");
	system("COLOR 2");
	fullscreen();
	Boarder();
	main_menu_load();
	welcome();
	main_menu();

};

