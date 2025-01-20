#pragma warning(disable: 4996) // DISABLING THE WARNING FOR GETTING THE CURRENT DATE.
#pragma warning(disable: 4244) // DISABLING THE WARNING FOR CREATING RNG. e.g. LOSING DATA.
#pragma warning(disable: 4267) // DISABLING THE WARNING FOR using line.subtr.

// THESE PRAGMA(S) CAN BE REMOVE OR NOT DEPENDS ON THE USER IDE, SINCE I TRY TO AVOID SUCH ERRORS AND WANT TO CREATE A SYSTEM THAT RUNS IN EVERY COMPILER
// I ADDED THESE, THESE ARE OPTIONALS.

#include <string>   // THESE THREE HEADER USED TO MANIPULATE STRINGS.
#include <cstring>  // (.e.g.line.substr, toupper, and 
#include <cctype>   // line.length)
#include <iomanip>  // HEADER FOR USING setw() FOR COLUMNS
#include <stdlib.h> // HEADER FOR USING 'STOI', CONVERTING INT TO STRING, AND FRO SYSTEM COLOR
#include <stdio.h>  // I FORGOT THE USE OF THIS, IF I RECALL, I WAS THINKING TO USE goto statements BUT I DIDN'T, MAYBE IT'S ALSO FOR FILE HANDLING.
#include <ctime>    // GETTING CURRENT TIME
#include <cstdlib>  // RNG, MY PLAN IS TO USE POINTERS FOR REFERENCE BUT SINCE I FACED SOME DIFFICULTIES, I SWITCHED TO USING RNG INSTEAD.
#include <fstream>  // FILE HANDLING
#include <sstream>  // THIS HEADER IS USED TO CONVERT INT TO STRING (CODE FOR APPOINTMENT AND SERVICES)
#include <iostream> // MOST COMMON HEADER

using namespace std;

void systemlock() {

	string userName;
	string userPassword;
	int loginAttempt = 0;
	int chance = 4;

	while (loginAttempt < 5)
	{
		system("cls");
		cout << endl << endl << endl;
		cout << "\t\t\t                            TAILORING SHOP.                            " << endl << endl;
		cout << "\t\t\t                    WE PROTECT OUR CLIENTS DETAILS.                    " << endl << endl << endl;
		cout << "\t\t\t  LOGIN SYSTEM  " << endl;
		cout << "\t\t\t_______________________________________________________________________" << endl << endl;
		cout << "\t\t\t  USERNAME. : ";
		getline(cin, userName);
		cout << "\t\t\t  PASSWORD. : ";
		getline(cin, userPassword);
		cout << "\t\t\t_______________________________________________________________________" << endl << endl;
		if (userName == "GROUP4" && userPassword == "201P")
		{
			cout << "\t\t\t                                WELCOME                                " << endl;
			cout << "\t\t\t_______________________________________________________________________" << endl << endl << "\t" << "\t" << "\t";
			system("pause");
			break;
		}
		else
		{
			cout << "\t\t\t                        INVALID LOG IN ATTEMPT.                        " << endl;
			cout << "\t\t\t_______________________________________________________________________" << endl << endl;
			cout << "\t\t\t YOU ONLY HAVE [" << chance << "] ATTEMPT(S) LEFT" << endl;
			cout << "\t\t\t_______________________________________________________________________" << endl << endl << "\t" << "\t" << "\t";
			system("pause");
			loginAttempt++;

			chance = chance - 1;
		}
	}
	if (loginAttempt == 5) {
		exit(0);
	}
}
//  SECURE THE SYSTEM DATA
const int commissions = 100;

string commissioncodex[commissions] = {};  //  USING STRINGS TO STORE IT ON .TXT
string servicetype[commissions] = {};
string ownername[commissions] = {};
string ownernumb[commissions] = {};
string owneraddress[commissions] = {};
string deadline[commissions] = {};
string itemdescription[commissions] = {};
string itemstobe[commissions] = {};
string commissionprice[commissions] = {};
string commissionstatus[commissions] = {};
string datereceive[commissions] = {};
string modeofpayment[commissions] = {};
string receivername[commissions] = {};
string commissionservice[commissions] = {};

string dresscode[commissions] = {};
string typeofcloth[commissions] = {};
string design[commissions] = {};

string neckcircumference[commissions] = {};  //  UNFORTUNATELY I'M UNABLE TO DO 2D ARRAYS FOR THE CUSTOMER'S ITEM(S)
string shoulderlength[commissions] = {};     //  THE COMPILER TOOK ALMOST A MINUTES TO RUN THE PROGRAM.
string bicepcircumference[commissions] = {}; //  THEN THE SYSTEM SUGGETING TO USE heap INSTEAD.
string armslength[commissions] = {};
string bustorchestcircumference[commissions] = {};
string waistcircumference[commissions] = {};
string backlength[commissions] = {};
string hipcircumference[commissions] = {};
string legcircumference[commissions] = {};
string inseamorinsideleg[commissions] = {};
string calf[commissions] = {};
string legslenght[commissions] = {};

void opencommissionsfile() {

	string line;

	ifstream myfile("commission.txt");

	if (myfile.is_open()) {
		int x = 0;
		while (getline(myfile, line)) {

			int l = line.length();
			dresscode[x] = line.substr(0, 23);
			typeofcloth[x] = line.substr(25, 23);
			design[x] = line.substr(50, 33);

			neckcircumference[x] = line.substr(85, 3);
			shoulderlength[x] = line.substr(90, 3);
			bicepcircumference[x] = line.substr(95, 3);
			armslength[x] = line.substr(100, 3);
			bustorchestcircumference[x] = line.substr(105, 3);
			waistcircumference[x] = line.substr(110, 3);
			backlength[x] = line.substr(115, 3);
			hipcircumference[x] = line.substr(120, 3);
			legcircumference[x] = line.substr(125, 3);
			inseamorinsideleg[x] = line.substr(130, 3);
			calf[x] = line.substr(135, 3);
			legslenght[x] = line.substr(140, 3);

			ownername[x] = line.substr(145, 22);
			ownernumb[x] = line.substr(169, 13);
			owneraddress[x] = line.substr(184, 43);
			deadline[x] = line.substr(229, 22);
			itemdescription[x] = line.substr(253, 118);
			itemstobe[x] = line.substr(373, 13);
			commissionprice[x] = line.substr(388, 28);
			commissionstatus[x] = line.substr(418, 23);
			commissioncodex[x] = line.substr(443, 7);
			receivername[x] = line.substr(452, 22);
			modeofpayment[x] = line.substr(476, 17);
			datereceive[x] = line.substr(495, 22);
			commissionservice[x] = line.substr(519, 6);
			servicetype[x] = line.substr(527, l - 527);

			x++;
		}
	}
	else {
		cout << "no data found..." << endl;
	}
}
void commission();
void project();
void repair();
void searchcommission(string searching);
void receipt(string toreceipt);
void deletecommission(string removes);
void savecommissionsfile() {

	int list = 0;
	ofstream myfile;
	myfile.open("commission.txt");

	for (int x = 0; x < commissions; x++) {
		if (servicetype[x] != "\0") {

			list++;

			myfile << left << setw(23) << dresscode[x] << ", " << setw(23) << typeofcloth[x] << ", " << setw(33) << design[x] << ", ";

			myfile << setw(3) << neckcircumference[x] << ", " << setw(3) << shoulderlength[x] << ", " << setw(3) << bicepcircumference[x] << ", ";
			myfile << setw(3) << armslength[x] << ", " << setw(3) << bustorchestcircumference[x] << ", " << setw(3) << waistcircumference[x] << ", ";
			myfile << setw(3) << backlength[x] << ", " << setw(3) << hipcircumference[x] << ", " << setw(3) << legcircumference[x] << ", ";
			myfile << setw(3) << inseamorinsideleg[x] << ", " << setw(3) << calf[x] << ", " << setw(3) << legslenght[x] << ", ";

			myfile << setw(22) << ownername[x] << ", " << setw(13) << ownernumb[x] << ", " << setw(43) << owneraddress[x] << ", " << setw(22) << deadline[x] << ", ";
			myfile << setw(118) << itemdescription[x] << ", " << setw(13) << itemstobe[x] << ", " << setw(28) << commissionprice[x] << ", " << setw(23) << commissionstatus[x] << ", ";
			myfile << setw(7) << commissioncodex[x] << ", " << setw(22) << receivername[x] << ", " << setw(17) << modeofpayment[x] << ", " << setw(22) << datereceive[x] << ", ";
			myfile << setw(6) << commissionservice[x] << ", " << servicetype[x] << endl;

		}
	}
	if (list == 0) {
		cout << endl;
	}
}

const int records = 100;

string appointmentcode[records] = {};
string clientname[records] = {};
string clientnumber[records] = {};
string appointmentsite[records] = {};
string appointmentschedule[records] = {};
string appointmentstatus[records] = {};

void openappointmentfile() {

	string line;

	ifstream savingmyfile("appointment.txt");

	if (savingmyfile.is_open()) {
		int x = 0;
		while (getline(savingmyfile, line)) {

			int l = line.length();
			clientname[x] = line.substr(0, 24);
			appointmentstatus[x] = line.substr(26, 22);
			clientnumber[x] = line.substr(50, 12);
			appointmentsite[x] = line.substr(64, 50);
			appointmentcode[x] = line.substr(116, 10);
			appointmentschedule[x] = line.substr(128, l - 128);
			x++;
		}
	}
	else {
		cout << "no data found..." << endl;
	}
}
void appointment();
void addschedule();
void cancel(string removing);
void resched(string rescheduling);
void search(string searching);
void saveappointmentfile() {

	int list = 0;
	ofstream savingmyfile;
	savingmyfile.open("appointment.txt");

	for (int x = 0; x < records; x++) {
		if (clientname[x] != "\0") {

			list++;

			savingmyfile << left << setw(24) << clientname[x] << ", " << setw(22) << appointmentstatus[x] << ", " << setw(12) << clientnumber[x]
				<< ", " << setw(50) << appointmentsite[x] << ", " << setw(10) << appointmentcode[x] << ", " << appointmentschedule[x] << endl;
		}
	}
	if (list == 0) {
		cout << endl;
	}
}

int main() {

	char choice;

	system("COLOR E0");
	systemlock();
	opencommissionsfile();
	openappointmentfile();

	time_t ttime = time(0);   //  GETTING CURRENT DATE AND TIME.
	char* dt = ctime(&ttime);

	do {
		system("cls");
		cout << endl << endl;
		cout << "\t\t\tCURRENT DATE AND TIME. : " << dt << endl << endl;
		cout << "\t\t\t                        TAILOR SUIT HOME SCREEN                        " << endl << endl;
		cout << "\t\t\t_______________________________________________________________________" << endl << endl;
		cout << "\t\t\t MAIN MENU. " << endl << endl;
		cout << "\t\t\t  [1] | COMMISSIONS " << endl << endl;
		cout << "\t\t\t  [2] | APPOINTMENT SCHEDULES" << endl << endl;
		cout << "\t\t\t  [3] | EXIT PROGRAM" << endl;
		cout << "\t\t\t_______________________________________________________________________" << endl << endl;
		cout << "\t\t\t SELECT OPTION ABOVE. : ";
		cin >> choice;

		switch (choice) {

		case '1':commission();
			break;

		case '2':appointment();
			break;
		}
	} while (choice != '3');
	cout << "\t\t\t_______________________________________________________________________" << endl << endl;
	cout << "\t\t\t                        CEIT-37-201P : GROUP #4                        " << endl;
	cout << "\t\t\t                   THANK YOU FOR TRYING OUR PROGRAM.                   " << endl;
	cout << "\t\t\t                       FROM 2022-2023 BSIT BATCH.                      " << endl;
	cout << "\t\t\t_______________________________________________________________________" << endl << endl;
	savecommissionsfile();
	saveappointmentfile();
	return 0;
}
void commission() {  //  COMMISSION INTERFACE

	int list = 0;
	char choice;
	string service, line;

	string shortitemdescription[commissions] = {};
	string shortname[commissions] = {};
	string shortdealine[commissions] = {};

	do {
		system("cls");
		cout << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t                                          PENDING AGENDA LIST                                           " << endl << endl;
		cout << "\t+-------------------+--------------------------------+------------------------+------------------------+" << endl;
		cout << "\t| TYPES OF SERVICE  | DESCRIPTIONS                   | OWNER(S)               | DEADLINE               |" << endl;
		cout << "\t+-------------------+--------------------------------+------------------------+------------------------+" << endl;

		for (int q = 0; q < commissions; q++) {
			if (ownername[q] != "\0") {

				list++;

				shortitemdescription[q] = itemdescription[q].substr(0, 30); // SUBTITUTING THESE SO IT'LL FIT.
				shortname[q] = ownername[q].substr(0, 22);
				shortdealine[q] = deadline[q].substr(0, 22);

				cout << "\t| " << left << setw(17) << servicetype[q] << setw(3) << " | " << setw(30) << shortitemdescription[q] << setw(3) << " | ";
				cout << setw(22) << shortname[q] << setw(3) << " | " << setw(22) << shortdealine[q] << " |" << endl;
			}
		}
		if (list == 0) {
			cout << endl;
			cout << "\t                                         NO RECENT APPOINTMENT                                        " << endl << endl;
		}
		cout << "\t+-------------------+--------------------------------+------------------------+------------------------+" << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t  [1] | DRESS/CODE PROJECT        [3] | SEARCH COMMISSION        [5] | BACK TO MAIN MENU                " << endl;
		cout << "\t  [2] | REPAIR CLOTHE(S)          [4] | CANCEL COMMISION                                                " << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t  [?] SELECT ABOVE OPTION. : ";
		cin >> choice;
		cout << "\t________________________________________________________________________________________________________" << endl << endl;

		switch (choice) {

		case '1':system("cls");
			project();
			break;

		case '2':repair();
			break;

		case '3':
			cin.ignore();
			cout << "\t                                        SEARCH FOR COMMISSION                                          " << endl << endl;
			cout << "\t  ENTER SERVICE. : ";
			getline(cin, service);
			searchcommission(service);
			break;

		case '4':
			cin.ignore();
			cout << "\t                                         DELETING COMMISSION                                          " << endl << endl;
			cout << "\t  ENTER SERVICE. : ";
			getline(cin, service);
			deletecommission(service);
			break;
		}
	} while (choice != '5');
}
void project() {

	int codex;
	string switches, service = "TAILOR";
	string oname, ownernumber, address, duedate;
	string description, tobe;
	string status = "PENDING";

	string orderquan;
	string des;
	string cloth;
	int count = 0;
	string total, paid;
	string concat;

	string neck, shoulder, bicep, lengthofarms, chestorbust;
	string lengthofback, waist, hips, thigh, inseam, binte, leglengths;

	char choice;

	cin.ignore();

	time_t ttime = time(0);
	char* dt = ctime(&ttime);

	cout << endl;
	cout << "\t                                     WELCOME TO TAILORING SUIT SHOP                                     " << endl;
	cout << "\t                             WE WILL HUNT YOU UNTIL WE DRESS/SUITED YOU UP                              " << endl;
	cout << "\t                                   704 BONI AVENUE, MANDALUYONG CITY.                                   " << endl;
	cout << "\t                                         098CENSORED/53CENSORED                                         " << endl << endl;
	cout << "\t________________________________________________________________________________________________________" << endl << endl << endl;
	cout << "\t                                           COMMISSION INVOICE                                           " << endl << endl;
	cout << "\t  COMMISSION CLIENT INFORMATION.                                                                        " << endl << endl;
	cout << "\t   CLIENT NAME.       : ";
	getline(cin, oname);
	cout << "\t   CLIENT NUMBER.     : ";
	getline(cin, ownernumber);
	cout << "\t   PICK-UP/DELIVERED. : ";
	getline(cin, tobe);
	cout << "\t   ADDRESS(OPTIONAL). : ";
	getline(cin, address);
	cout << endl;

	for (int x = 0; x < oname.length(); x++) {  //  TO UPPERING INPUTTED STRINGS
		oname[x] = toupper(oname[x]);
	}
	for (int x = 0; x < address.length(); x++) {
		address[x] = toupper(address[x]);
	}
	for (int x = 0; x < tobe.length(); x++) {
		tobe[x] = toupper(tobe[x]);
	}
	cout << "\t________________________________________________________________________________________________________" << endl << endl;
	cout << "\t  COMMISSION INFO.                                             DATE ISSUED. : " << dt << endl;

	do {
		cout << "\t  WHAT ATTIRE YOU EXACTLY LOOKING FOR?" << endl << endl;
		cout << "\t   [1] SKIRT         [3] COMPLETE UNIFORM    [5] SHORT/LONG SLEEVES POLO       [7] RETURN TO MENU       " << endl;
		cout << "\t   [2] PANTS         [4] COMPLETE SUIT       [6] T-SHIRT                                                " << endl << endl;
		cout << "\t  SELECTION . : ";
		cin >> choice;
		cout << "\t________________________________________________________________________________________________________" << endl << endl;

		if (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7') {
			cout << "\t                       TO AVOID PROGRAM ERROR THE SYSTEM WILL PROMPT BACK TO MENU                       " << endl;
			cout << "\t________________________________________________________________________________________________________" << endl << endl;
			system("pause");
			break;
		}
	} while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7');

	if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5' || choice == '6') {
		for (int q = 0; q < commissions; q++) {
			do {
				codex = 1000000 + (rand() % 9999999);  //  CREATING RANDOM NUMBER.

				stringstream ss;                       //  CONVERTING INT TO STRING, THESE FEATURES CAN ALSO BE FOUND IN FUNCTION FOR CREATING DATAS.

				ss << codex;

				ss >> switches;

				if (switches != commissioncodex[q]) {
					break;
				}
			} while (commissioncodex[q] == switches);

			if (ownername[q] == "\0") {

				commissionstatus[q] = status;
				commissioncodex[q] = switches;
				servicetype[q] = service + "-" + switches;
				ownername[q] = oname;
				ownernumb[q] = ownernumber;
				itemstobe[q] = tobe;
				owneraddress[q] = address;
				datereceive[q] = "";
				modeofpayment[q] = "";
				receivername[q] = "";
				commissionservice[q] = "TAILOR";

				cout << "\t   REFERENCE NO. : " << servicetype[q] << endl;

				break;
			}
		}
	}
	if (choice == '1') {
		cin.ignore();
		cout << "\t   DESIGN OF ATTIRE. : ";
		getline(cin, des);
		cout << "\t   TYPE OF CLOTH.    : ";
		getline(cin, cloth);
		cout << endl;
		cout << "\t   MEASUREMENTS FOR SKIRT. :" << endl;
		cout << "\t    WAIST SIZE (CIRCUMFERENCE). : ";
		getline(cin, waist);
		cout << "\t    HIPS (CIRCUMFERENCE).       : ";
		getline(cin, hips);
		cout << "\t    LEGS/THIGH (CIRCUMFERENCE). : ";
		getline(cin, thigh);
		cout << "\t    INSEAM/INSIDE OF LEGS.      : ";
		getline(cin, inseam);
		cout << "\t    WAIST TO KNEE LENGTH.       : ";
		getline(cin, leglengths);
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t   DESCRIPTION.:                                                                                        " << endl << endl;
		cout << "\t    ";
		getline(cin, description);
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t   DUE DATE. : ";
		getline(cin, duedate);
		cout << endl;
		cout << "\t   TOTAL AMMOUNT.   : ";
		getline(cin, total);
		cout << "\t   AMMOUNT PAID.    : ";
		getline(cin, paid);

		if (paid == total) {
			concat = total + " FULLY PAID.";
		}
		if (paid == "") {
			concat = total + " NOT YET PAID.";
		}
		if (paid != total) {
			concat = total + " NOT FULLY PAID.";
		}
		cout << "\t                      " << concat << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t                                          THANK YOU FOR COMING                                          " << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl;

		for (int l = 0; l < duedate.length(); l++) {
			duedate[l] = toupper(duedate[l]);
		}
		for (int z = 0; z < description.length(); z++) {
			description[z] = toupper(description[z]);
		}
		for (int f = 0; f < des.length(); f++) {
			des[f] = toupper(des[f]);
		}
		for (int g = 0; g < cloth.length(); g++) {
			cloth[g] = toupper(cloth[g]);
		}
		for (int q = 0; q < commissions; q++) {
			if (ownername[q] == oname) {

				deadline[q] = duedate;
				itemdescription[q] = description;
				commissionprice[q] = concat;
				dresscode[q] = "SKIRT";
				typeofcloth[q] = cloth;
				design[q] = des;
				waistcircumference[q] = waist;
				hipcircumference[q] = hips;
				inseamorinsideleg[q] = thigh;
				legcircumference[q] = inseam;
				legslenght[q] = leglengths;

				break;
			}
		}
		cout << "\t";
		system("pause");
	}
	if (choice == '2') {
		cin.ignore();
		cout << "\t   DESIGN OF ATTIRE. : ";
		getline(cin, des);
		cout << "\t   TYPE OF CLOTH.    : ";
		getline(cin, cloth);
		cout << endl;
		cout << "\t   MEASUREMENTS FOR PANTS. :" << endl;
		cout << "\t    WAIST SIZE (CIRCUMFERENCE). : ";
		getline(cin, waist);
		cout << "\t    HIPS (CIRCUMFERENCE).       : ";
		getline(cin, hips);
		cout << "\t    LEGS/THIGH (CIRCUMFERENCE). : ";
		getline(cin, thigh);
		cout << "\t    INSEAM/INSIDE OF LEGS.      : ";
		getline(cin, inseam);
		cout << "\t    CALF (CIRCUMFERENCE).       : ";
		getline(cin, binte);
		cout << "\t    lEG LENGTH.                 : ";
		getline(cin, leglengths);
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t   DESCRIPTION.:                                                                                        " << endl << endl;
		cout << "\t    ";
		getline(cin, description);
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t   DUE DATE. : ";
		getline(cin, duedate);
		cout << endl;
		cout << "\t   TOTAL AMMOUNT.   : ";
		getline(cin, total);
		cout << "\t   AMMOUNT PAID.    : ";
		getline(cin, paid);

		if (paid == total) {
			concat = total + " FULLY PAID.";
		}
		if (paid == "") {
			concat = total + " NOT YET PAID.";
		}
		if (paid != total) {
			concat = total + " NOT FULLY PAID.";
		}
		cout << "\t                      " << concat << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t                                          THANK YOU FOR COMING                                          " << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl;

		for (int l = 0; l < duedate.length(); l++) {
			duedate[l] = toupper(duedate[l]);
		}
		for (int z = 0; z < description.length(); z++) {
			description[z] = toupper(description[z]);
		}
		for (int f = 0; f < des.length(); f++) {
			des[f] = toupper(des[f]);
		}
		for (int g = 0; g < cloth.length(); g++) {
			cloth[g] = toupper(cloth[g]);
		}
		for (int q = 0; q < commissions; q++) {
			if (ownername[q] == oname) {

				deadline[q] = duedate;
				itemdescription[q] = description;
				commissionprice[q] = concat;
				dresscode[q] = "PANTS";
				typeofcloth[q] = cloth;
				design[q] = des;
				waistcircumference[q] = waist;
				hipcircumference[q] = hips;
				inseamorinsideleg[q] = thigh;
				legcircumference[q] = inseam;
				calf[q] = binte;
				legslenght[q] = leglengths;

				break;
			}
		}
		cout << "\t";
		system("pause");
	}
	if (choice == '3') {
		cin.ignore();
		cout << "\t   DESIGN OF ATTIRE. : ";
		getline(cin, des);
		cout << "\t   TYPE OF CLOTH.    : ";
		getline(cin, cloth);
		cout << endl;
		cout << "\t   MEASUREMENTS FOR COMPLETE UNIFORM. :" << endl;
		cout << "\t    NECK (CIRCUMFERENCE).       : ";
		getline(cin, neck);
		cout << "\t    SHOULDER.                   : ";
		getline(cin, shoulder);
		cout << "\t    BICEP (CIRCUMFERENCE).      : ";
		getline(cin, bicep);
		cout << "\t    ARMS LENGTH.                : ";
		getline(cin, lengthofarms);
		cout << "\t    CHEST/BUST (CIRCUMFERENCE). : ";
		getline(cin, chestorbust);
		cout << "\t    BACK LENGTH.                : ";
		getline(cin, lengthofback);
		cout << "\t    WAIST SIZE (CIRCUMFERENCE). : ";
		getline(cin, waist);
		cout << "\t    HIPS (CIRCUMFERENCE).       : ";
		getline(cin, hips);
		cout << "\t    LEGS/THIGH (CIRCUMFERENCE). : ";
		getline(cin, thigh);
		cout << "\t    INSEAM/INSIDE OF LEGS.      : ";
		getline(cin, inseam);
		cout << "\t    CALF (CIRCUMFERENCE).       : ";
		getline(cin, binte);
		cout << "\t    lEG LENGTH.                 : ";
		getline(cin, leglengths);
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t   DESCRIPTION.:                                                                                        " << endl << endl;
		cout << "\t    ";
		getline(cin, description);
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t   DUE DATE. : ";
		getline(cin, duedate);
		cout << endl;
		cout << "\t   TOTAL AMMOUNT.   : ";
		getline(cin, total);
		cout << "\t   AMMOUNT PAID.    : ";
		getline(cin, paid);

		if (paid == total) {
			concat = total + " FULLY PAID.";
		}
		if (paid == "") {
			concat = total + " NOT YET PAID.";
		}
		if (paid != total) {
			concat = total + " NOT FULLY PAID.";
		}
		cout << "\t                      " << concat << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t                                          THANK YOU FOR COMING                                          " << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl;

		for (int l = 0; l < duedate.length(); l++) {
			duedate[l] = toupper(duedate[l]);
		}
		for (int z = 0; z < description.length(); z++) {
			description[z] = toupper(description[z]);
		}
		for (int f = 0; f < des.length(); f++) {
			des[f] = toupper(des[f]);
		}
		for (int g = 0; g < cloth.length(); g++) {
			cloth[g] = toupper(cloth[g]);
		}
		for (int q = 0; q < commissions; q++) {
			if (ownername[q] == oname) {

				deadline[q] = duedate;
				itemdescription[q] = description;
				commissionprice[q] = concat;
				dresscode[q] = "COMPLETE UNIFORM";
				typeofcloth[q] = cloth;
				design[q] = des;
				neckcircumference[q] = neck;
				shoulderlength[q] = shoulder;
				bicepcircumference[q] = bicep;
				armslength[q] = lengthofarms;
				bustorchestcircumference[q] = chestorbust;
				backlength[q] = lengthofback;
				waistcircumference[q] = waist;
				hipcircumference[q] = hips;
				inseamorinsideleg[q] = thigh;
				legcircumference[q] = inseam;
				calf[q] = binte;
				legslenght[q] = leglengths;

				break;
			}
		}
		cout << "\t";
		system("pause");
	}
	if (choice == '4') {
		cin.ignore();
		cout << "\t   DESIGN OF ATTIRE. : ";
		getline(cin, des);
		cout << "\t   TYPE OF CLOTH.    : ";
		getline(cin, cloth);
		cout << endl;
		cout << "\t   MEASUREMENTS FOR COMPLETE SUIT. :" << endl;
		cout << "\t    NECK (CIRCUMFERENCE).       : ";
		getline(cin, neck);
		cout << "\t    SHOULDER.                   : ";
		getline(cin, shoulder);
		cout << "\t    BICEP (CIRCUMFERENCE).      : ";
		getline(cin, bicep);
		cout << "\t    ARMS LENGTH.                : ";
		getline(cin, lengthofarms);
		cout << "\t    CHEST/BUST (CIRCUMFERENCE). : ";
		getline(cin, chestorbust);
		cout << "\t    BACK LENGTH.                : ";
		getline(cin, lengthofback);
		cout << "\t    WAIST SIZE (CIRCUMFERENCE). : ";
		getline(cin, waist);
		cout << "\t    HIPS (CIRCUMFERENCE).       : ";
		getline(cin, hips);
		cout << "\t    LEGS/THIGH (CIRCUMFERENCE). : ";
		getline(cin, thigh);
		cout << "\t    INSEAM/INSIDE OF LEGS.      : ";
		getline(cin, inseam);
		cout << "\t    CALF (CIRCUMFERENCE).       : ";
		getline(cin, binte);
		cout << "\t    lEG LENGTH.                 : ";
		getline(cin, leglengths);
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t   DESCRIPTION.:                                                                                        " << endl << endl;
		cout << "\t    ";
		getline(cin, description);
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t   DUE DATE. : ";
		getline(cin, duedate);
		cout << endl;
		cout << "\t   TOTAL AMMOUNT.   : ";
		getline(cin, total);
		cout << "\t   AMMOUNT PAID.    : ";
		getline(cin, paid);

		if (paid == total) {
			concat = total + " FULLY PAID.";
		}
		if (paid == "") {
			concat = total + " NOT YET PAID.";
		}
		if (paid != total) {
			concat = total + " NOT FULLY PAID.";
		}
		cout << "\t                      " << concat << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t                                          THANK YOU FOR COMING                                          " << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl;

		for (int l = 0; l < duedate.length(); l++) {
			duedate[l] = toupper(duedate[l]);
		}
		for (int z = 0; z < description.length(); z++) {
			description[z] = toupper(description[z]);
		}
		for (int f = 0; f < des.length(); f++) {
			des[f] = toupper(des[f]);
		}
		for (int g = 0; g < cloth.length(); g++) {
			cloth[g] = toupper(cloth[g]);
		}
		for (int q = 0; q < commissions; q++) {
			if (ownername[q] == oname) {

				deadline[q] = duedate;
				itemdescription[q] = description;
				commissionprice[q] = concat;
				dresscode[q] = "COMPLETE SUIT";
				typeofcloth[q] = cloth;
				design[q] = des;
				neckcircumference[q] = neck;
				shoulderlength[q] = shoulder;
				bicepcircumference[q] = bicep;
				armslength[q] = lengthofarms;
				bustorchestcircumference[q] = chestorbust;
				backlength[q] = lengthofback;
				waistcircumference[q] = waist;
				hipcircumference[q] = hips;
				inseamorinsideleg[q] = thigh;
				legcircumference[q] = inseam;
				calf[q] = binte;
				legslenght[q] = leglengths;

				break;
			}
		}
		cout << "\t";
		system("pause");
	}
	if (choice == '5') {
		cin.ignore();
		cout << "\t   DESIGN OF ATTIRE. : ";
		getline(cin, des);
		cout << "\t   TYPE OF CLOTH.    : ";
		getline(cin, cloth);
		cout << endl;
		cout << "\t   MEASUREMENTS FOR LONG/SHORT SLEEVES POLO. :" << endl;
		cout << "\t    NECK (CIRCUMFERENCE).       : ";
		getline(cin, neck);
		cout << "\t    SHOULDER.                   : ";
		getline(cin, shoulder);
		cout << "\t    BICEP (CIRCUMFERENCE).      : ";
		getline(cin, bicep);
		cout << "\t    ARMS LENGTH.                : ";
		getline(cin, lengthofarms);
		cout << "\t    CHEST/BUST (CIRCUMFERENCE). : ";
		getline(cin, chestorbust);
		cout << "\t    BACK LENGTH.                : ";
		getline(cin, lengthofback);
		cout << "\t    WAIST SIZE (CIRCUMFERENCE). : ";
		getline(cin, waist);
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t   DESCRIPTION.:                                                                                        " << endl << endl;
		cout << "\t    ";
		getline(cin, description);
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t   DUE DATE. : ";
		getline(cin, duedate);
		cout << endl;
		cout << "\t   TOTAL AMMOUNT.   : ";
		getline(cin, total);
		cout << "\t   AMMOUNT PAID.    : ";
		getline(cin, paid);

		if (paid == total) {
			concat = total + " FULLY PAID.";
		}
		if (paid == "") {
			concat = total + " NOT YET PAID.";
		}
		if (paid != total) {
			concat = total + " NOT FULLY PAID.";
		}
		cout << "\t                      " << concat << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t                                          THANK YOU FOR COMING                                          " << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl;

		for (int l = 0; l < duedate.length(); l++) {
			duedate[l] = toupper(duedate[l]);
		}
		for (int z = 0; z < description.length(); z++) {
			description[z] = toupper(description[z]);
		}
		for (int f = 0; f < des.length(); f++) {
			des[f] = toupper(des[f]);
		}
		for (int g = 0; g < cloth.length(); g++) {
			cloth[g] = toupper(cloth[g]);
		}
		for (int q = 0; q < commissions; q++) {
			if (ownername[q] == oname) {

				deadline[q] = duedate;
				itemdescription[q] = description;
				commissionprice[q] = concat;
				dresscode[q] = "LONG/SHORT SLEEVES POLO";
				typeofcloth[q] = cloth;
				design[q] = des;
				neckcircumference[q] = neck;
				shoulderlength[q] = shoulder;
				bicepcircumference[q] = bicep;
				armslength[q] = lengthofarms;
				bustorchestcircumference[q] = chestorbust;
				backlength[q] = lengthofback;
				waistcircumference[q] = waist;

				break;
			}
		}
		cout << "\t";
		system("pause");
	}
	if (choice == '6') {
		cin.ignore();
		cout << "\t   DESIGN OF ATTIRE. : ";
		getline(cin, des);
		cout << "\t   TYPE OF CLOTH.    : ";
		getline(cin, cloth);
		cout << endl;
		cout << "\t   MEASUREMENTS FOR T-SHIRT. :" << endl;
		cout << "\t    NECK (CIRCUMFERENCE).       : ";
		getline(cin, neck);
		cout << "\t    SHOULDER.                   : ";
		getline(cin, shoulder);
		cout << "\t    BICEP (CIRCUMFERENCE).      : ";
		getline(cin, bicep);
		cout << "\t    ARMS LENGTH.                : ";
		getline(cin, lengthofarms);
		cout << "\t    CHEST/BUST (CIRCUMFERENCE). : ";
		getline(cin, chestorbust);
		cout << "\t    BACK LENGTH.                : ";
		getline(cin, lengthofback);
		cout << "\t    WAIST SIZE (CIRCUMFERENCE). : ";
		getline(cin, waist);
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t   DESCRIPTION.:                                                                                        " << endl << endl;
		cout << "\t    ";
		getline(cin, description);
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t   DUE DATE. : ";
		getline(cin, duedate);
		cout << endl;
		cout << "\t   TOTAL AMMOUNT.   : ";
		getline(cin, total);
		cout << "\t   AMMOUNT PAID.    : ";
		getline(cin, paid);

		if (paid == total) {
			concat = total + " FULLY PAID.";
		}
		if (paid == "") {
			concat = total + " NOT YET PAID.";
		}
		if (paid != total) {
			concat = total + " NOT FULLY PAID.";
		}
		cout << "\t                      " << concat << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t                                          THANK YOU FOR COMING                                          " << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl;

		for (int l = 0; l < duedate.length(); l++) {
			duedate[l] = toupper(duedate[l]);
		}
		for (int z = 0; z < description.length(); z++) {
			description[z] = toupper(description[z]);
		}
		for (int f = 0; f < des.length(); f++) {
			des[f] = toupper(des[f]);
		}
		for (int g = 0; g < cloth.length(); g++) {
			cloth[g] = toupper(cloth[g]);
		}
		for (int q = 0; q < commissions; q++) {
			if (ownername[q] == oname) {

				deadline[q] = duedate;
				itemdescription[q] = description;
				commissionprice[q] = concat;
				dresscode[q] = "T-SHIRT";
				typeofcloth[q] = cloth;
				design[q] = des;
				neckcircumference[q] = neck;
				shoulderlength[q] = shoulder;
				bicepcircumference[q] = bicep;
				armslength[q] = lengthofarms;
				bustorchestcircumference[q] = chestorbust;
				backlength[q] = lengthofback;
				waistcircumference[q] = waist;

				break;
			}
		}
		cout << "\t";
		system("pause");
	}
	if (choice == '7') {
		cout << "\t                                      ENTERED INFO WILL BE DISCARD                                      " << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl << "\t";
		system("pause");
	}
}
void repair() {

	int codex;
	string switches, service = "REPAIR";
	string oname, ownernumber, address, duedate;
	string description, tobe, concatenate, newswitch;
	string status = "PENDING";

	int num, p = 0, count = 0;
	string quantity, items, total, paid;

	cin.ignore();

	cout << "\t                                     WELCOME TO TAILORING SUIT SHOP                                     " << endl;
	cout << "\t                                 WE WILL HUNT YOU UNTIL WE FIXED YOU UP                                 " << endl;
	cout << "\t                                   704 BONI AVENUE, MANDALUYONG CITY.                                   " << endl;
	cout << "\t                                         098CENSORED/53CENSORED                                         " << endl << endl;
	cout << "\t+------------------------------------------------------------------------------------------------------+" << endl << endl;
	cout << "\t                                             INVOICE TICKET                                             " << endl << endl;
	cout << "\t  CLIENT DETAILS.                                                                                       " << endl << endl;
	cout << "\t   CLIENT NAME.      : ";
	getline(cin, oname);
	cout << "\t   CLIENT NUMBER.    : ";
	getline(cin, ownernumber);
	cout << endl;
	cout << "\t   ITEM(S) TO BE.    : ";
	getline(cin, tobe);
	cout << "\t   CUSTOMER ADDRESS. : ";
	getline(cin, address);
	cout << endl;
	cout << "\t   ITEM(S) QUANTITY. : ";
	getline(cin, quantity);

	time_t ttime = time(0);
	char* dt = ctime(&ttime);

	for (int i = 0; i < quantity.length(); i++) {
		if (isdigit(quantity[i]))
			count++;
	}
	if (count > 0) {

		num = atoi(quantity.c_str());

		cout << endl;
		cout << "\t+------------------------------------------------------------------------------------------------------+" << endl << endl;
		cout << "\t     NO. OF ITEMS                            LIST OF ITEMS.                                             " << endl << endl;

		while (p != num) {
			p++;
			cout << left << "\t         " << "[" << p << "]" << setw(21) << "          -          ";
			getline(cin, items);
		}
		cout << "\n\t+------------------------------------------------------------------------------------------------------+" << endl << endl;
		cout << "\t  ITEM(S) DESCRIPTION. :                                                                                  " << endl << endl;
		cout << "\t  ";
		getline(cin, description);

		cout << "\n\t+------------------------------------------------------------------------------------------------------+" << endl << endl;
		cout << "\t   DATE ISSUED.     : " << dt;
		cout << "\t   DATE OF NEED.    : ";
		getline(cin, duedate);
		cout << endl;
		cout << "\t   TOTAL AMMOUNT.   : ";
		getline(cin, total);
		cout << "\t   AMMOUNT PAID.    : ";
		getline(cin, paid);

		if (paid == total) {
			concatenate = total + " FULLY PAID";
		}
		if (paid == "") {
			concatenate = total + " NOT YET PAID";
		}
		if (paid != total) {
			concatenate = total + " NOT FULLY PAID";
		}
		cout << "\t                      " << concatenate << endl << endl;

		for (int x = 0; x < oname.length(); x++) {
			oname[x] = toupper(oname[x]);
		}
		for (int x = 0; x < address.length(); x++) {
			address[x] = toupper(address[x]);
		}
		for (int x = 0; x < duedate.length(); x++) {
			duedate[x] = toupper(duedate[x]);
		}
		for (int x = 0; x < description.length(); x++) {
			description[x] = toupper(description[x]);
		}
		for (int x = 0; x < tobe.length(); x++) {
			tobe[x] = toupper(tobe[x]);
		}
		for (int x = 0; x < ownernumber.length(); x++) {
			ownernumber[x] = toupper(ownernumber[x]);
		}

		for (int q = 0; q < commissions; q++) {
			do {
				codex = 1000000 + (rand() % 9999999);

				stringstream ss;

				ss << codex;

				ss >> switches;

				if (switches != commissioncodex[q]) {
					break;
				}
			} while (commissioncodex[q] == switches);

			if (ownername[q] == "\0") {

				ownername[q] = oname;
				ownernumb[q] = ownernumber;
				owneraddress[q] = address;
				commissioncodex[q] = switches;
				servicetype[q] = service + "-" + switches;
				deadline[q] = duedate;
				itemdescription[q] = description;
				itemstobe[q] = tobe;
				commissionprice[q] = concatenate;
				commissionstatus[q] = status;
				datereceive[q] = "";
				modeofpayment[q] = "";
				receivername[q] = "";
				commissionservice[q] = "REPAIR";

				cout << "\t   REFERENCE NO. : " << servicetype[q] << endl;

				cout << "\t________________________________________________________________________________________________________" << endl << endl;
				cout << "\t  P.S : SHOW THIS TO THE STAFF TO CLAIM YOUR ITEM(S).                                                   " << endl;
				cout << "\t________________________________________________________________________________________________________" << endl << endl << "\t";
				system("pause");
				break;
			}
		}
	}
	else {
		cout << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t                         TO AVOID PROGRAM ERROR, THE SYSTEM WILL RETURN TO MENU                         " << endl;
		cout << "\t                                      AND DISCARD THE ENTERED INFO                                      " << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl << "\t";
		system("pause");
	}
}
void searchcommission(string search) {

	int list = 0;
	string address, status;

	string neck, shoulder, bicep, lengthofarms, chestorbust;
	string lengthofback, waist, hips, thigh, inseam, binte, leglengths;

	char choicetwo;
	char choice;

	for (int q = 0; q < commissions; q++) {
		if (search == "") {
			break;
		}
		if (servicetype[q] == search) {

			list++;
			do {
				system("cls");
				cout << endl;
				cout << "\t________________________________________________________________________________________________________" << endl << endl;
				cout << "\t                                    SEARCH FOR COMMISSION RESULTS                                       " << endl << endl;
				cout << "\t  CLIENT DETAILS.                                                                                       " << endl << endl;
				cout << "\t  CLIENT NAME.          : " << ownername[q] << endl;
				cout << "\t  CLIENT NUMBER.        : " << ownernumb[q] << endl;
				cout << "\t  PACKAGE TO BE.        : " << itemstobe[q] << endl;
				cout << "\t  SEND TO (ADDRESS).    : " << owneraddress[q] << endl << endl;
				cout << "\t  SERVICE TYPE.         : " << servicetype[q] << endl;
				cout << "\t  PACKAGE STATUS.       : " << commissionstatus[q] << endl;
				cout << "\t________________________________________________________________________________________________________" << endl << endl;
				cout << "\t  ITEMS DESCRIPTION                                                                                     " << endl << endl;
				cout << "\t  " << itemdescription[q] << endl;
				cout << "\t________________________________________________________________________________________________________" << endl << endl;
				cout << "\t  PACKAGE INFO.                                                                                         " << endl << endl;
				cout << "\t  DATE OF NEED.  : " << left << setw(16) << deadline[q] << endl;
				cout << "\t  TOTAL AMMOUNT. : " << left << setw(25) << commissionprice[q] << endl;
				cout << "\t________________________________________________________________________________________________________" << endl << endl;

				if (dresscode[q] == "                       " || dresscode[q] == "") {
					do {
						cout << "\t  [1] | UPDATE STATUS     [2] | BACK TO MAIN MENU  " << endl;
						cout << "\t________________________________________________________________________________________________________" << endl << endl;
						cout << "\t  SELECTION . : ";
						cin >> choicetwo;

					} while (choicetwo != '1' && choicetwo != '2');

					if (choicetwo == '1') {
						for (int q = 0; q < commissions; q++) {
							if (servicetype[q] == search) {

								if (commissionstatus[q] == "CLAIMED" || commissionstatus[q] == "CLAIMED                ") {
									receipt(search);
									cout << "\t________________________________________________________________________________________________________" << endl << endl;
									cout << "\t                                   THE ITEM(S) ARE ALREADY CLAIMED                                      " << endl;
									cout << "\t________________________________________________________________________________________________________" << endl << endl << "\t";
									system("pause");
									break;
								}
								else {
									cin.ignore();

									cout << endl;
									cout << "\n\t  STATUS. : ";
									getline(cin, status);

									for (int x = 0; x < status.length(); x++) {
										status[x] = toupper(status[x]);
									}

									if (status == "CLAIMED") {

										receipt(search);
										system("pause");
										list++;

										servicetype[q] = servicetype[q] + "-D";
										commissionstatus[q] = status;
										break;
									}
									else {

										list++;
										commissionstatus[q] = status;
										break;
									}
									cout << endl;
									cout << "\t________________________________________________________________________________________________________" << endl << endl;
									cout << "\t                                          REQUEST COMPLETE!                                             " << endl;
									cout << "\t________________________________________________________________________________________________________" << endl << endl << "\t";
									system("pause");
									break;
								}
							}
						}
					}
					break;
				}
				else {
					cout << "\t                                          CLIENT SIZE DETAILS.                                          " << endl << endl;
					cout << "\t+------------------------------------------------------------------------------------------------------+" << endl;
					cout << "\t|     BODY PART DESCRIPTION                          |     SIZES                                       |" << endl;
					cout << "\t+------------------------------------------------------------------------------------------------------+" << endl;
					cout << "\t|     - NECK (CIRCUMFERENCE)                         |     " << left << setw(44) << neckcircumference[q] << "|" << endl;
					cout << "\t|     - SHOULDER WIDTH                               |     " << left << setw(44) << shoulderlength[q] << "|" << endl;
					cout << "\t|     - BICEP (CIRCUMFERENCE)                        |     " << left << setw(44) << bicepcircumference[q] << "|" << endl;
					cout << "\t|     - ARMS LENGTH                                  |     " << left << setw(44) << armslength[q] << "|" << endl;
					cout << "\t|     - BUST/CHEST (CIRCUMFERENCE)                   |     " << left << setw(44) << bustorchestcircumference[q] << "|" << endl;
					cout << "\t|     - WAIST (CIRCUMFERENCE)                        |     " << left << setw(44) << waistcircumference[q] << "|" << endl;
					cout << "\t|     - BACK LENGTH                                  |     " << left << setw(44) << backlength[q] << "|" << endl;
					cout << "\t|     - HIP (CIRCUMFERENCE)                          |     " << left << setw(44) << hipcircumference[q] << "|" << endl;
					cout << "\t|     - LEG (CIRCUMFERENCE)                          |     " << left << setw(44) << legcircumference[q] << "|" << endl;
					cout << "\t|     - INSEAM/INSIDE OF THE LEG                     |     " << left << setw(44) << inseamorinsideleg[q] << "|" << endl;
					cout << "\t|     - CALF                                         |     " << left << setw(44) << calf[q] << "|" << endl;
					cout << "\t|     - LEGS LENGTH                                  |     " << left << setw(44) << legslenght[q] << "|" << endl;
					cout << "\t+------------------------------------------------------------------------------------------------------+" << endl;
					cout << "\t|     REQUESTED ATTIRE.   : " << left << setw(75) << dresscode[q] << "|" << endl;
					cout << "\t|     DESIGN OF ATTIRE.   : " << left << setw(75) << design[q] << "|" << endl;
					cout << "\t|     TYPE OF CLOTH USED. : " << left << setw(75) << typeofcloth[q] << "|" << endl;
					cout << "\t+------------------------------------------------------------------------------------------------------+" << endl;
				}
				cout << "\t________________________________________________________________________________________________________" << endl << endl;
				cout << "\t [1] | UPDATE STATUS      [2] | EDIT SIZES      [3] | BACK TO MAIN MENU                                 " << endl;
				cout << "\t________________________________________________________________________________________________________" << endl << endl;
				cout << "\t  SELECTION . : ";
				cin >> choice;

				if (choice == '1') {
					for (int q = 0; q < commissions; q++) {
						if (servicetype[q] == search) {

							if (commissionstatus[q] == "CLAIMED" || commissionstatus[q] == "CLAIMED                ") {
								receipt(search);
								cout << "\t________________________________________________________________________________________________________" << endl << endl;
								cout << "\t                                   THE ITEM(S) ARE ALREADY CLAIMED                                      " << endl;
								cout << "\t________________________________________________________________________________________________________" << endl << endl << "\t";
								system("pause");
								break;
							}
							else {
								cin.ignore();

								cout << endl;
								cout << "\n\t  STATUS. : ";
								getline(cin, status);

								for (int x = 0; x < status.length(); x++) {
									status[x] = toupper(status[x]);
								}

								if (status == "CLAIMED") {

									receipt(search);
									system("pause");

									list++;

									servicetype[q] = servicetype[q] + "-D";
									commissionstatus[q] = status;
									break;
								}
								else {

									list++;
									commissionstatus[q] = status;
									break;
								}
								cout << endl;
								cout << "\t________________________________________________________________________________________________________" << endl << endl;
								cout << "\t                                          REQUEST COMPLETE!                                             " << endl;
								cout << "\t________________________________________________________________________________________________________" << endl << endl << "\t";
								system("\tpause");
								break;
							}
							break;
						}
					}
					break;
				}
				if (choice == '2') {
					for (int q = 0; q < commissions; q++) {
						if (servicetype[q] == search) {

							if (dresscode[q] == "SKIRT" || dresscode[q] == "SKIRT                  ") {

								if (receivername[q] == "" || receivername[q] == "                      ") {
									break;
								}
								else {

									cin.ignore();

									cout << "\t________________________________________________________________________________________________________" << endl << endl;
									cout << "\t   NEW MEASUREMENTS FOR SKIRT.                                        SERVICE CODE. : " << servicetype[q] << endl << endl;
									cout << "\t    WAIST SIZE (CIRCUMFERENCE). : ";
									getline(cin, waist);
									cout << "\t    HIPS (CIRCUMFERENCE).       : ";
									getline(cin, hips);
									cout << "\t    LEGS/THIGH (CIRCUMFERENCE). : ";
									getline(cin, thigh);
									cout << "\t    INSEAM/INSIDE OF LEGS.      : ";
									getline(cin, inseam);
									cout << "\t    WAIST TO KNEE LENGTH.       : ";
									getline(cin, leglengths);

									for (int q = 0; q < commissions; q++) {
										if (servicetype[q] == search) {

											list++;

											waistcircumference[q] = waist;
											hipcircumference[q] = hips;
											inseamorinsideleg[q] = thigh;
											legcircumference[q] = inseam;
											legslenght[q] = leglengths;

											break;
										}
									}
								}
							}
							if (dresscode[q] == "PANTS" || dresscode[q] == "PANTS                  ") {

								if (receivername[q] == "" || receivername[q] == "                      ") {
									break;
								}
								else {

									cin.ignore();

									cout << "\t________________________________________________________________________________________________________" << endl << endl;
									cout << "\t   NEW MEASUREMENTS FOR PANTS.                                        SERVICE CODE. : " << servicetype[q] << endl << endl;
									cout << "\t    WAIST SIZE (CIRCUMFERENCE). : ";
									getline(cin, waist);
									cout << "\t    HIPS (CIRCUMFERENCE).       : ";
									getline(cin, hips);
									cout << "\t    LEGS/THIGH (CIRCUMFERENCE). : ";
									getline(cin, thigh);
									cout << "\t    INSEAM/INSIDE OF LEGS.      : ";
									getline(cin, inseam);
									cout << "\t    CALF (CIRCUMFERENCE).       : ";
									getline(cin, binte);
									cout << "\t    lEG LENGTH.                 : ";
									getline(cin, leglengths);

									for (int q = 0; q < commissions; q++) {
										if (servicetype[q] == search) {

											list++;

											waistcircumference[q] = waist;
											hipcircumference[q] = hips;
											inseamorinsideleg[q] = thigh;
											legcircumference[q] = inseam;
											calf[q] = binte;
											legslenght[q] = leglengths;

											break;
										}
									}
								}
							}
							if (dresscode[q] == "COMPLETE UNIFORM" || dresscode[q] == "COMPLETE UNIFORM       ") {

								if (receivername[q] == "" || receivername[q] == "                      ") {
									break;
								}
								else {

									cin.ignore();

									cout << "\t________________________________________________________________________________________________________" << endl << endl;
									cout << "\t   NEW MEASUREMENTS FOR COMPLETE UNIFORM.                             SERVICE CODE. : " << servicetype[q] << endl << endl;
									cout << "\t    NECK (CIRCUMFERENCE).       : ";
									getline(cin, neck);
									cout << "\t    SHOULDER.                   : ";
									getline(cin, shoulder);
									cout << "\t    BICEP (CIRCUMFERENCE).      : ";
									getline(cin, bicep);
									cout << "\t    ARMS LENGTH.                : ";
									getline(cin, lengthofarms);
									cout << "\t    CHEST/BUST (CIRCUMFERENCE). : ";
									getline(cin, chestorbust);
									cout << "\t    BACK LENGTH.                : ";
									getline(cin, lengthofback);
									cout << "\t    WAIST SIZE (CIRCUMFERENCE). : ";
									getline(cin, waist);
									cout << "\t    HIPS (CIRCUMFERENCE).       : ";
									getline(cin, hips);
									cout << "\t    LEGS/THIGH (CIRCUMFERENCE). : ";
									getline(cin, thigh);
									cout << "\t    INSEAM/INSIDE OF LEGS.      : ";
									getline(cin, inseam);
									cout << "\t    CALF (CIRCUMFERENCE).       : ";
									getline(cin, binte);
									cout << "\t    lEG LENGTH.                 : ";
									getline(cin, leglengths);

									for (int q = 0; q < commissions; q++) {
										if (servicetype[q] == search) {

											list++;

											neckcircumference[q] = neck;
											shoulderlength[q] = shoulder;
											bicepcircumference[q] = bicep;
											armslength[q] = lengthofarms;
											bustorchestcircumference[q] = chestorbust;
											backlength[q] = lengthofback;
											waistcircumference[q] = waist;
											hipcircumference[q] = hips;
											inseamorinsideleg[q] = thigh;
											legcircumference[q] = inseam;
											calf[q] = binte;
											legslenght[q] = leglengths;

											break;
										}
									}
								}
							}
							if (dresscode[q] == "COMPLETE SUIT" || dresscode[q] == "COMPLETE SUIT          ") {

								if (receivername[q] == "" || receivername[q] == "                 ") {
									break;
								}
								else {

									cin.ignore();

									cout << "\t________________________________________________________________________________________________________" << endl << endl;
									cout << "\t   NEW MEASUREMENTS FOR COMPLETE SUIT.                                SERVICE CODE. : " << servicetype[q] << endl << endl;
									cout << "\t    NECK (CIRCUMFERENCE).       : ";
									getline(cin, neck);
									cout << "\t    SHOULDER.                   : ";
									getline(cin, shoulder);
									cout << "\t    BICEP (CIRCUMFERENCE).      : ";
									getline(cin, bicep);
									cout << "\t    ARMS LENGTH.                : ";
									getline(cin, lengthofarms);
									cout << "\t    CHEST/BUST (CIRCUMFERENCE). : ";
									getline(cin, chestorbust);
									cout << "\t    BACK LENGTH.                : ";
									getline(cin, lengthofback);
									cout << "\t    WAIST SIZE (CIRCUMFERENCE). : ";
									getline(cin, waist);
									cout << "\t    HIPS (CIRCUMFERENCE).       : ";
									getline(cin, hips);
									cout << "\t    LEGS/THIGH (CIRCUMFERENCE). : ";
									getline(cin, thigh);
									cout << "\t    INSEAM/INSIDE OF LEGS.      : ";
									getline(cin, inseam);
									cout << "\t    CALF (CIRCUMFERENCE).       : ";
									getline(cin, binte);
									cout << "\t    lEG LENGTH.                 : ";
									getline(cin, leglengths);

									for (int q = 0; q < commissions; q++) {
										if (servicetype[q] == search) {

											list++;

											neckcircumference[q] = neck;
											shoulderlength[q] = shoulder;
											bicepcircumference[q] = bicep;
											armslength[q] = lengthofarms;
											bustorchestcircumference[q] = chestorbust;
											backlength[q] = lengthofback;
											waistcircumference[q] = waist;
											hipcircumference[q] = hips;
											inseamorinsideleg[q] = thigh;
											legcircumference[q] = inseam;
											calf[q] = binte;
											legslenght[q] = leglengths;

											break;
										}
									}
								}
							}
							if (dresscode[q] == "LONG/SHORT SLEEVES POLO") {

								if (receivername[q] == "" || receivername[q] == "                      ") {
									break;
								}
								else {

									cin.ignore();

									cout << "\t________________________________________________________________________________________________________" << endl << endl;
									cout << "\t   NEW MEASUREMENTS FOR LONG/SHORT SLEEVES POLO.                      SERVICE CODE. : " << servicetype[q] << endl << endl;
									cout << "\t    NECK (CIRCUMFERENCE).       : ";
									getline(cin, neck);
									cout << "\t    SHOULDER.                   : ";
									getline(cin, shoulder);
									cout << "\t    BICEP (CIRCUMFERENCE).      : ";
									getline(cin, bicep);
									cout << "\t    ARMS LENGTH.                : ";
									getline(cin, lengthofarms);
									cout << "\t    CHEST/BUST (CIRCUMFERENCE). : ";
									getline(cin, chestorbust);
									cout << "\t    BACK LENGTH.                : ";
									getline(cin, lengthofback);
									cout << "\t    WAIST SIZE (CIRCUMFERENCE). : ";
									getline(cin, waist);

									for (int q = 0; q < commissions; q++) {
										if (servicetype[q] == search) {

											list++;

											neckcircumference[q] = neck;
											shoulderlength[q] = shoulder;
											bicepcircumference[q] = bicep;
											armslength[q] = lengthofarms;
											bustorchestcircumference[q] = chestorbust;
											backlength[q] = lengthofback;
											waistcircumference[q] = waist;

											break;
										}
									}
								}
							}
							if (dresscode[q] == "T-SHIRT" || dresscode[q] == "T-SHIRT                ") {

								if (receivername[q] == "" || receivername[q] == "                      ") {
									break;
								}
								else {

									cin.ignore();

									cout << "\t________________________________________________________________________________________________________" << endl << endl;
									cout << "\t   NEW MEASUREMENTS FOR T-SHIRT.                                      SERVICE CODE. : " << servicetype[q] << endl << endl;
									cout << "\t    NECK (CIRCUMFERENCE).       : ";
									getline(cin, neck);
									cout << "\t    SHOULDER.                   : ";
									getline(cin, shoulder);
									cout << "\t    BICEP (CIRCUMFERENCE).      : ";
									getline(cin, bicep);
									cout << "\t    ARMS LENGTH.                : ";
									getline(cin, lengthofarms);
									cout << "\t    CHEST/BUST (CIRCUMFERENCE). : ";
									getline(cin, chestorbust);
									cout << "\t    BACK LENGTH.                : ";
									getline(cin, lengthofback);
									cout << "\t    WAIST SIZE (CIRCUMFERENCE). : ";
									getline(cin, waist);

									for (int q = 0; q < commissions; q++) {
										if (servicetype[q] == search) {

											neckcircumference[q] = neck;
											shoulderlength[q] = shoulder;
											bicepcircumference[q] = bicep;
											armslength[q] = lengthofarms;
											bustorchestcircumference[q] = chestorbust;
											backlength[q] = lengthofback;
											waistcircumference[q] = waist;

											break;
										}
									}
								}
							}
						}
						cout << endl;
						cout << "\t________________________________________________________________________________________________________" << endl << endl;
						cout << "\t                                      REQUEST ALREADY COMPLETE!                                         " << endl;
						cout << "\t________________________________________________________________________________________________________" << endl << endl << "\t";
						system("\tpause");
						break;
					}
					break;
				}
			} while (choice != '3');
			break;
		}
	}
	if (list == 0) {
		cout << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t                                   PLEASE ENTER EXISTING SCHEDULE.                                      " << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl << "\t";
		system("\tpause");
	}
}
void receipt(string toreceipt) {

	int list = 0;
	char choice;

	string name, mode, date, newprice;

	for (int q = 0; q < commissions; q++) {
		if (servicetype[q] == toreceipt) {

			list++;

			if (commissionservice[q] == "TAILOR") {
				system("cls");

				cout << endl;
				cout << "\t________________________________________________________________________________________________________" << endl << endl;
				cout << "\t                                          COMMISSION'S RECEIPT                                          " << endl << endl;
				cout << "\t  CLIENT DETAILS.                                                                                       " << endl << endl;
				cout << "\t   CLIENT NAME.          : " << ownername[q] << endl;
				cout << "\t   PACKAGE TO BE.        : " << itemstobe[q] << endl;
				cout << "\t   SEND TO (ADDRESS).    : " << owneraddress[q] << endl << endl;
				cout << "\t   SERVICE TYPE.         : " << servicetype[q] << endl;
				cout << "\t   PACKAGE STATUS.       : " << commissionstatus[q] << endl;
				cout << "\t________________________________________________________________________________________________________" << endl << endl;
				cout << "\t  PACKAGE DETAILS.                                                                                      " << endl << endl;
				cout << "\t   TYPE OF CLOTH USED. : " << typeofcloth[q] << endl;
				cout << "\t   REQUESTED ATTIRE.   : " << dresscode[q] << endl;
				cout << "\t   DESIGN OF ATTIRE.   : " << design[q] << endl << endl;
				cout << "\t  PACKAGE DESCRIPTION.   " << endl << endl;
				cout << "\t   " << itemdescription[q] << endl;

				cin.ignore();

				if (receivername[q] == "" || receivername[q] == "                      ") {
					do {
						cout << "\t________________________________________________________________________________________________________" << endl << endl;
						cout << "\t  RECEIVER DETAILS.                                                                                     " << endl << endl;
						cout << "\t   RECEIVER(S) NAME. : ";
						getline(cin, name);
						cout << "\t   DATE OF RECEIVE.  : ";
						getline(cin, date);
						cout << "\t   TOTAL AMMOUNT.    : ";
						getline(cin, newprice);
						cout << endl;
						cout << "\t   MODE OF PAYMENT.  : [1] | CASH PAYMENT                                                               " << endl;
						cout << "\t                       [2] | CHECK PAYMENT                                                              " << endl;
						cout << "\t                       [3] | E-PAYMENT                                                                  " << endl << endl;
						cout << "\t   [?] | SELECTTION. : ";
						cin >> choice;
						cout << "\t________________________________________________________________________________________________________" << endl << endl;
						break;
					} while (choice != '1' && choice != '2' && choice != '3');

					if (choice == '1') {
						cout << "\t                                  WE THANK YOU DEEPLY FOR CHOOSING US.                                  " << endl << endl;
						cout << "\t________________________________________________________________________________________________________" << endl << endl;
						list++;
						datereceive[q] = date;
						modeofpayment[q] = "CASH PAYMENT";
						receivername[q] = name;
						commissionprice[q] = newprice + " FULLY PAID";
						break;
					}
					if (choice == '2') {
						cout << "\t                                  WE THANK YOU DEEPLY FOR CHOOSING US.                                  " << endl << endl;
						cout << "\t________________________________________________________________________________________________________" << endl << endl;
						list++;
						datereceive[q] = date;
						modeofpayment[q] = "CHECK PAYMENT";
						receivername[q] = name;
						commissionprice[q] = newprice + " FULLY PAID";
						break;
					}
					if (choice == '3') {
						cout << "\t                                  WE THANK YOU DEEPLY FOR CHOOSING US.                                  " << endl << endl;
						cout << "\t________________________________________________________________________________________________________" << endl << endl;
						list++;
						datereceive[q] = date;
						modeofpayment[q] = "E-PAYMENT";
						receivername[q] = name;
						commissionprice[q] = newprice + " FULLY PAID";
						break;
					}
				}
				else {
					cout << "\t________________________________________________________________________________________________________" << endl << endl;
					cout << "\t  RECEIVER DETAILS.                                                                                     " << endl << endl;
					cout << "\t   RECEIVER(S) NAME. : " << receivername[q] << endl;
					cout << "\t   MODE OF PAYMENT.  : " << modeofpayment[q] << endl;
					cout << "\t   DATE OF RECEIVE.  : " << datereceive[q] << endl;
					break;
				}
			}
			if (commissionservice[q] == "REPAIR") {
				system("cls");

				cout << endl;
				cout << "\t________________________________________________________________________________________________________" << endl << endl;
				cout << "\t                                          COMMISSION'S RECEIPT                                          " << endl << endl;
				cout << "\t  CLIENT DETAILS.                                                                                       " << endl << endl;
				cout << "\t   CLIENT NAME.          : " << ownername[q] << endl;
				cout << "\t   PACKAGE TO BE.        : " << itemstobe[q] << endl;
				cout << "\t   SEND TO (ADDRESS).    : " << owneraddress[q] << endl << endl;
				cout << "\t   SERVICE TYPE.         : " << servicetype[q] << endl;
				cout << "\t   PACKAGE STATUS.       : " << commissionstatus[q] << endl;
				cout << "\t________________________________________________________________________________________________________" << endl << endl;
				cout << "\t  PACKAGE DESCRIPTION.   " << endl << endl;
				cout << "\t   " << itemdescription[q] << endl;

				cin.ignore();

				if (receivername[q] == "" || receivername[q] == "                      ") {
					do {
						cout << "\t________________________________________________________________________________________________________" << endl << endl;
						cout << "\t  RECEIVER DETAILS.                                                                                     " << endl << endl;
						cout << "\t   RECEIVER(S) NAME. : ";
						getline(cin, name);
						cout << "\t   DATE OF RECEIVE. : ";
						getline(cin, date);
						cout << "\t   TOTAL AMMOUNT.    : ";
						getline(cin, newprice);
						cout << endl;
						cout << "\t   MODE OF PAYMENT.  : [1] | CASH PAYMENT                                                               " << endl;
						cout << "\t                       [2] | CHECK PAYMENT                                                              " << endl;
						cout << "\t                       [3] | E-PAYMENT                                                                  " << endl << endl;
						cout << "\t   [?] | SELECTTION. : ";
						cin >> choice;
						cout << "\t________________________________________________________________________________________________________" << endl << endl;
						break;
					} while (choice != '1' && choice != '2' && choice != '3');

					if (choice == '1') {
						cout << "\t                                  WE THANK YOU DEEPLY FOR CHOOSING US.                                  " << endl << endl;
						cout << "\t________________________________________________________________________________________________________" << endl << endl;
						list++;
						datereceive[q] = date;
						modeofpayment[q] = "CASH PAYMENT";
						receivername[q] = name;
						commissionprice[q] = newprice + " FULLY PAID";
						break;
					}
					if (choice == '2') {
						cout << "\t                                  WE THANK YOU DEEPLY FOR CHOOSING US.                                  " << endl << endl;
						cout << "\t________________________________________________________________________________________________________" << endl << endl;
						list++;
						datereceive[q] = date;
						modeofpayment[q] = "CHECK PAYMENT";
						receivername[q] = name;
						commissionprice[q] = newprice + " FULLY PAID";
						break;
					}
					if (choice == '3') {
						cout << "\t                                  WE THANK YOU DEEPLY FOR CHOOSING US.                                  " << endl << endl;
						cout << "\t________________________________________________________________________________________________________" << endl << endl;
						list++;
						datereceive[q] = date;
						modeofpayment[q] = "E-PAYMENT";
						receivername[q] = name;
						commissionprice[q] = newprice + " FULLY PAID";
						break;
					}
				}
				else {
					cout << "\t________________________________________________________________________________________________________" << endl << endl;
					cout << "\t  RECEIVER DETAILS.                                                                                     " << endl << endl;
					cout << "\t   RECEIVER(S) NAME. : " << receivername[q] << endl;
					cout << "\t   MODE OF PAYMENT.  : " << modeofpayment[q] << endl;
					cout << "\t   DATE OF RECEIVE.  : " << datereceive[q] << endl;
					break;
				}
			}
		}
	}
}
void deletecommission(string removes) {

	int list = 0;

	for (int q = 0; q < commissions; q++) {
		if (removes == "") {
			break;
		}
		if (servicetype[q] == removes) {
			list++;

			servicetype[q] = "";
			ownername[q] = "";
			ownernumb[q] = "";
			owneraddress[q] = "";
			deadline[q] = "";
			itemdescription[q] = "";
			itemstobe[q] = "";
			commissionprice[q] = "";
			commissionstatus[q] = "";
			datereceive[q] = "";
			modeofpayment[q] = "";
			receivername[q] = "";
			commissionservice[q] = "";

			dresscode[q] = "";
			typeofcloth[q] = "";
			design[q] = "";

			neckcircumference[q] = "";
			shoulderlength[q] = "";
			bicepcircumference[q] = "";
			armslength[q] = "";
			bustorchestcircumference[q] = "";
			waistcircumference[q] = "";
			backlength[q] = "";
			hipcircumference[q] = "";
			legcircumference[q] = "";
			inseamorinsideleg[q] = "";
			calf[q] = "";
			legslenght[q] = "";

			cout << endl;
			cout << "\t________________________________________________________________________________________________________" << endl << endl;
			cout << "\t                                          REQUEST COMPLETED                                             " << endl;
			cout << "\t________________________________________________________________________________________________________" << endl << endl << "\t";
			system("pause");
			break;
		}
	}
	if (list == 0) {
		cout << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t                                   PLEASE ENTER EXISTING SCHEDULE.                                      " << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl << "\t";
		system("pause");
	}
}
void appointment() {

	int list = 0;
	char choice;
	string searchsched;

	string shortclientname[records] = {};

	do {
		system("cls");
		cout << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t                                       APPOINTMENT SCHEDULE LIST                                        " << endl << endl;
		cout << "\t+--------------------------+----------------------+---------------------------+------------------------+" << endl;
		cout << "\t|  CLIENT NAME             |  CLIENT CODE         |  SCHEDULE                 |  STATUS                |" << endl;
		cout << "\t+--------------------------+----------------------+---------------------------+------------------------+" << endl;
		for (int q = 0; q < records; q++) {
			if (clientname[q] != "\0") {

				list++;

				shortclientname[q] = clientname[q].substr(0, 24);

				cout << "\t|  " << left << setw(24) << shortclientname[q] << setw(3) << "|  " << setw(19) << appointmentcode[q] << setw(3) << " |  ";
				cout << setw(25) << appointmentschedule[q] << setw(3) << "|  " << setw(22) << appointmentstatus[q] << "|" << endl;
			}
		}
		if (list == 0) {
			cout << endl;
			cout << "\t                                         NO RECENT APPOINTMENT                                        " << endl << endl;
		}
		cout << "\t+--------------------------+----------------------+---------------------------+------------------------+" << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t  [1] | ADD AN APPOINTMENT       [3] | SEARCH APPOINTMENT       [5] | BACK TO MAIN MENU                 " << endl;
		cout << "\t  [2] | RESCHEDULE APPOINTMENT   [4] | CANCEL APPOINTMENT                                                " << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t  [?] SELECT ABOVE OPTION. : ";
		cin >> choice;
		cout << "\t________________________________________________________________________________________________________" << endl << endl;

		switch (choice) {

		case '1':addschedule();
			break;

		case '2':
			cin.ignore();
			cout << "\t                                       RESCHEDULING APOINTMENT                                        " << endl << endl;
			cout << "\t  ENTER SCHEDULE HERE. : ";
			getline(cin, searchsched);
			resched(searchsched);
			break;

		case '3':
			cin.ignore();
			cout << "\t                                         SEARCH APPOINTMENT.                                          " << endl << endl;
			cout << "\t  ENTER SCHEDULE HERE. : ";
			getline(cin, searchsched);
			search(searchsched);
			break;

		case '4':
			cin.ignore();
			cout << "\t                                        CANCELING APOINTMENT.                                        " << endl << endl;
			cout << "\t  ENTER SCHEDULE HERE. : ";
			getline(cin, searchsched);
			cancel(searchsched);
			break;
		}
	} while (choice != '5');
}
void addschedule() {

	int codex;
	string name, cnum, date, time, code, address;
	string newdate, newtime, newschedule, switches, schedule;

	char choice;

	cin.ignore();

	cout << endl;
	cout << "\t                                       SCHEDULING AN APPOINTMENT.                                       " << endl;
	cout << "\n\t  NAME. : ";
	getline(cin, name);
	cout << "\n\t  CONTACT NUMBER. : ";
	getline(cin, cnum);
	cout << "\n\t  DATE. : ";
	getline(cin, date);
	cout << "\n\t  TIME. : ";
	getline(cin, time);
	cout << "\n\t  ADDRESS. : ";
	getline(cin, address);

	schedule = date + ", " + time;

	for (int x = 0; x < name.length(); x++) {
		name[x] = toupper(name[x]);
	}
	for (int x = 0; x < schedule.length(); x++) {
		schedule[x] = toupper(schedule[x]);
	}
	for (int x = 0; x < address.length(); x++) {
		address[x] = toupper(address[x]);
	}

	for (int q = 0; q < records; q++) {

		do {
			codex = 10000000000000 + (rand() % 999999999999);

			stringstream ss;

			ss << codex;

			ss >> switches;

			if (switches != appointmentcode[q]) {
				break;
			}
		} while (appointmentcode[q] == switches);

		if (clientname[q] == "\0") {

			cout << "\n\t  APPOINTMENT CODE. : " << switches << endl;

			clientname[q] = name;
			clientnumber[q] = cnum;
			appointmentsite[q] = address;
			appointmentschedule[q] = schedule;
			appointmentstatus[q] = "PENDING APPOINTMENT";
			appointmentcode[q] = switches;

			cout << endl;
			cout << "\t________________________________________________________________________________________________________" << endl << endl;
			cout << "\t                                          REQUEST COMPLETE!                                             " << endl;
			cout << "\t________________________________________________________________________________________________________" << endl << endl << "\t";
			system("\tpause");

			break;
		}
		if (schedule == appointmentschedule[q]) {
			do {
				cout << "\t________________________________________________________________________________________________________" << endl << endl;
				cout << "\t                                           SYSTEM DETECTION!!                                           " << endl << endl;
				cout << "\t                          THE ENTERED DATE AND TIME HAVE BEEN ALREADY OCCUPIED                          " << endl << endl;
				cout << "\t                                     [1] RESCHEDULE     [2] CANCEL.                                     " << endl << endl;
				cout << "\t                                       [?] SELECT ABOVE OPTION. : ";
				cin >> choice;

			} while (choice != '1' && choice != '2');

			if (choice == '1') {
				cin.ignore();

				cout << endl;
				cout << "\t________________________________________________________________________________________________________" << endl << endl;
				cout << "\t                                        RESCHEDULING APOINTMENT.                                        " << endl;
				cout << "\n\t  ENTER DATE AGAIN. : ";
				getline(cin, newdate);
				cout << "\n\t  ENTER TIME AGAIN. : ";
				getline(cin, newtime);

				newschedule = newdate + ", " + newtime;

				for (int y = 0; y < newschedule.length(); y++) {
					newschedule[y] = toupper(newschedule[y]);
				}

				for (int q = 0; q < records; q++) {
					if (clientname[q] == "\0") {

						clientname[q] = name;
						clientnumber[q] = cnum;
						appointmentsite[q] = address;
						appointmentschedule[q] = newschedule;
						appointmentstatus[q] = "PENDING APPOINTMENT";
						appointmentcode[q] = switches;

						cout << endl;
						cout << "\t________________________________________________________________________________________________________" << endl << endl;
						cout << "\t                                          REQUEST COMPLETE!                                           " << endl;
						cout << "\t________________________________________________________________________________________________________" << endl << endl << "\t";
						system("\tpause");
						break;
					}
				}
				break;
			}
			if (choice == '2') {
				cout << endl;
				cout << "\t________________________________________________________________________________________________________" << endl << endl;
				cout << "\t                                             REQUEST REVOKE                                             " << endl;
				cout << "\t________________________________________________________________________________________________________" << endl << endl << "\t";
				system("\tpause");
				break;
			}
			break;
		}
	}
}
void resched(string rescheduling) {

	int list = 0;
	string date, time, schedule;

	for (int q = 0; q < records; q++) {
		if (rescheduling == "") {
			break;
		}
		if (appointmentschedule[q] == rescheduling) {

			cout << "\n\t  DATE. : ";
			getline(cin, date);
			cout << "\n\t  TIME. : ";
			getline(cin, time);

			schedule = date + ", " + time;

			for (int x = 0; x < schedule.length(); x++) {
				schedule[x] = toupper(schedule[x]);
			}

			list++;

			appointmentschedule[q] = schedule;

			cout << endl;
			cout << "\t________________________________________________________________________________________________________" << endl << endl;
			cout << "\t                                          REQUEST COMPLETE!                                             " << endl;
			cout << "\t________________________________________________________________________________________________________" << endl << endl << "\t";
			system("\tpause");
			break;
		}
	}
	if (list == 0) {
		cout << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t                                   PLEASE ENTER EXISTING SCHEDULE.                                      " << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl << "\t";
		system("\tpause");
	}
}
void search(string searching) {

	int list = 0;
	string address;
	char choice;

	for (int q = 0; q < records; q++) {
		if (searching == "") {
			break;
		}
		if (appointmentschedule[q] == searching) {

			list++;

			do {
				system("cls");
				cout << "\t________________________________________________________________________________________________________" << endl << endl;
				cout << "\t                                      COPY OF APPOINTMENT SLIP.                                         " << endl;
				cout << "\n\t  APPOINTMENT CODE.     : " << appointmentcode[q] << endl;
				cout << "\n\t  CLIENT NAME.          : " << clientname[q] << endl;
				cout << "\n\t  CLIENT NUMBER.        : " << clientnumber[q] << endl;
				cout << "\n\t  APPOINTMENT SCHEDULE. : " << appointmentschedule[q] << endl;
				cout << "\n\t  APPOINTMENT LOCATION. : " << appointmentsite[q] << endl;
				cout << "\n\t  APOINTMENT STATUS.    : " << appointmentstatus[q] << endl;
				cout << "\t________________________________________________________________________________________________________" << endl << endl;
				cout << "\t  [1] UPDATE       [2] EDIT ADDRESS       [3] BACK TO MENU                                              " << endl;
				cout << "\t________________________________________________________________________________________________________" << endl << endl;
				cout << "\t  [?] SELECT OPTION. : ";
				cin >> choice;
			} while (choice != '1' && choice != '2' && choice != '3');

			if (choice == '1') {
				for (int q = 0; q < records; q++) {
					if (appointmentschedule[q] == searching) {

						list++;

						appointmentstatus[q] = "ATTENDED";

						cout << endl;
						cout << "\t________________________________________________________________________________________________________" << endl << endl;
						cout << "\t                                          REQUEST COMPLETE!                                             " << endl;
						cout << "\t________________________________________________________________________________________________________" << endl << endl << "\t";
						system("\tpause");
						break;
					}
				}
			}
			if (choice == '2') {
				for (int q = 0; q < records; q++) {
					if (appointmentschedule[q] == searching) {

						cin.ignore();
						cout << endl;
						cout << "\n\t  ADDRESS. : ";
						getline(cin, address);

						for (int x = 0; x < address.length(); x++) {
							address[x] = toupper(address[x]);
						}

						list++;

						appointmentsite[q] = address;

						cout << endl;
						cout << "\t________________________________________________________________________________________________________" << endl << endl;
						cout << "\t                                          REQUEST COMPLETE!                                             " << endl;
						cout << "\t________________________________________________________________________________________________________" << endl << endl << "\t";
						system("\tpause");
						break;
					}
				}
			}
			if (choice == '3') {
				break;
			}
			break;
		}
	}
	if (list == 0) {
		cout << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t                                   PLEASE ENTER EXISTING SCHEDULE.                                      " << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl << "\t";
		system("\tpause");
	}
}
void cancel(string removing) {

	int list = 0;

	for (int q = 0; q < records; q++) {
		if (removing == "") {
			break;
		}
		if (appointmentschedule[q] == removing) {

			list++;

			clientname[q] = "";
			clientnumber[q] = "";
			appointmentsite[q] = "";
			appointmentschedule[q] = "";
			appointmentstatus[q] = "";
			appointmentcode[q] = "";

			cout << endl;
			cout << "\t________________________________________________________________________________________________________" << endl << endl;
			cout << "\t                                          REQUEST COMPLETED                                             " << endl;
			cout << "\t________________________________________________________________________________________________________" << endl << endl << "\t";
			system("pause");
			break;
		}
	}
	if (list == 0) {
		cout << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl;
		cout << "\t                                   PLEASE ENTER EXISTING SCHEDULE.                                      " << endl;
		cout << "\t________________________________________________________________________________________________________" << endl << endl << "\t";
		system("pause");
	}
}