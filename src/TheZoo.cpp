#include <iostream>
#include <jni.h>
#include <vector>
#include <iomanip>
#include <fstream>
#include "Animal.h"
#include "Bat.h"
#include "Crocodile.h"
#include "Goose.h"
#include "Mammal.h"
#include "Oviparous.h"
#include "Pelican.h"
#include "SeaLion.h"
#include "Whale.h"

using namespace std;

void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
	JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
	JNIEnv *env;                      // Pointer to native interface
	//================== prepare loading of Java VM ============================
	JavaVMInitArgs vm_args;                        // Initialization arguments
	JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
	options[0].optionString = (char*) "-Djava.class.path=";   // where to find java .class
	vm_args.version = JNI_VERSION_1_6;             // minimum Java version
	vm_args.nOptions = 1;                          // number of options
	vm_args.options = options;
	vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
	//=============== load and initialize Java VM and JNI interface =============
	jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
	delete options;    // we then no longer need the initialisation options.
	if (rc != JNI_OK) {
		// TO DO: error processing...
		cin.get();
		exit(EXIT_FAILURE);
	}
	//=============== Display JVM version =======================================
	cout << "JVM load succeeded: Version ";
	jint ver = env->GetVersion();
	cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

	jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
	if (cls2 == nullptr) {
		cerr << "ERROR: class not found !";
	}
	else {                                  // if class found, continue
		cout << "Class MyTest found" << endl;
		jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
		if (mid == nullptr)
			cerr << "ERROR: method void createZooFile() not found !" << endl;
		else {
			env->CallStaticVoidMethod(cls2, mid);                      // call method
			cout << endl;
		}
	}


	jvm->DestroyJavaVM();
	cin.get();
}

//Checks if current entered track number has already been taken
bool isTrackNumTaken(vector<Animal*>& zoo, int trackNum)
{
	//checks all track numbers, and returns true if user track number already exists
	for (int i = 0; i < zoo.size(); i++) {
		if (zoo[i]->trackNumber == trackNum) {
			return true;
		}
	}
	return false;
}

//Handles creating animal objects for user input animals
Animal* makeAnimal(int trackNum, string name, string type, string subType, int eggs, int nurse) {
	if (subType == "Crocodile") {
		Crocodile* a = new Crocodile(eggs);
		a->trackNumber = trackNum;
		a->name = name;
		return a;
	}
	else if (subType == "Goose") {
		Goose* a = new Goose(eggs);
		a->trackNumber = trackNum;
		a->name = name;
		return a;
	}
	else if (subType == "Pelican") {
		Pelican* a = new Pelican(eggs);
		a->trackNumber = trackNum;
		a->name = name;
		return a;
	}
	else if (subType == "Bat") {
		Bat* a = new Bat(nurse);
		a->trackNumber = trackNum;
		a->name = name;
		return a;
	}
	else if (subType == "Whale") {
		Whale* a = new Whale(nurse);
		a->trackNumber = trackNum;
		a->name = name;
		return a;
	}
	else if (subType == "SeaLion") {
		SeaLion* a = new SeaLion(nurse);
		a->trackNumber = trackNum;
		a->name = name;
		return a;
	}
}

//Allows the user to input values and add the animal to the zoo
void AddAnimal(vector<Animal*>& zoo)
{
	//vars used to store user data
	bool taken;
	string name, type, subType;
	int eggs = 0, nurse = 0, trackNum;

	cout << "---------------------" << endl;
	cout << "Enter -1 to abort." << endl;

	//Asks user for track number
	do {
		cout << "Please enter a valid Track#: " << endl;
		cin >> trackNum;

		taken = isTrackNumTaken(zoo, trackNum);
		if (taken) {
			cout << "Track# already in use. Please choose another." << endl;
		}

		if (trackNum == -1)
			return;
	} while (!(trackNum >= 1 && trackNum <= 999999 && !taken));


	//Asks user for name
	cout << "Please enter a name: " << endl;
	cin.ignore();
	getline(cin, name);
	if (name == "-1")
		return;


	//Asks users for type and subtype
	do {
		cout << "Please enter a valid type: " << endl;
		cin >> type;
		if (type == "-1")
			return;

		if (type == "Oviparous") {
			do {
				cout << "Please enter a valid sub-type: " << endl;
				cin.ignore();
				cin >> subType;
				if (subType == "-1")
					return;
			} while (!(subType == "Crocodile" || subType == "Goose" || subType == "Pelican"));
		}
		else if (type == "Mammal") {
			do {
				cout << "Please enter a valid sub-type: " << endl;
				cin.ignore();
				cin >> subType;
				if (subType == "-1")
					return;
			} while (!(subType == "Bat" || subType == "Whale" || subType == "SeaLion"));
		}
	} while (!(type == "Oviparous" || type == "Mammal"));


	//Asks user about eggs if Oviparous
	if (type == "Oviparous") {
		do {
			cout << "Please enter the number of eggs: " << endl;
			cin >> eggs;
			if (eggs == -1)
				return;
		} while (!(eggs >= 0));
	}

	//Asks user about nursing if Mammal
	else if (type == "Mammal") {
		do {
			cout << "Please enter the number of nurse: " << endl;
			cin >> nurse;
			if (nurse == -1)
				return;
		} while (!(nurse >= 0));
	}

	//Confirms user wants to save current animal
	cout << "Do you wish to save this animal? (Y/N):" << endl;
	Animal* a = makeAnimal(trackNum, name, type, subType, eggs, nurse);
	a->display();
	cout << "Y/N" << endl;
	char input;
	cin >> input;

	//if user says yes, animal is saved
	if (input == 'Y' || input == 'y') {
		zoo.push_back(a);
		cout << "Animal successfully added." << endl;
	}
}

//Handles removing animals from the zoo
void RemoveAnimal(vector<Animal*>& zoo)
{
	//Get tracking number from user
	int trackingNum;
	cout << "Enter the tracking number of the animal to be removed:" << endl;
	cin >> trackingNum;


	//Finds location of tracking number in the zoo
	int location = -1;
	for (auto i = 0; i < zoo.size(); i++) {
		if (zoo[i]->trackNumber == trackingNum)
			location = i;
	}

	if (location == -1) {
		cout << "Invalid tracking number." << endl;
		return;
	}

	//Confirms with user that they would like to delete animal
	else {
		cout << "Are you sure you wish to delete:" << endl;
		zoo[location]->display();
		cout << "Y/N" << endl;
		char input;
		cin >> input;

		//if user says yes, delete animal
		if (input == 'Y' || input == 'y') {
			delete zoo[location];
			zoo.erase(zoo.begin()+location);
			cout << "Animal successfully deleted." << endl;
		}
	}
}

//Handles loading animal data from file on system
void LoadDataFromFile(vector<Animal*>& zoo)
{
	//empty current zoo to get ready for loading new values
	zoo.clear();

	//vars to store animal values in
	string name, type, subType;
	int eggs, nurse, prevTrackNum, trackNum = -1;

	//Open input.txt file and make sure it exists
	ifstream fin("input.txt");
	if (!fin.is_open()) {
		cout << "File not found" << endl;
	}
	else {
		//Read info from file and fill vars
		while (!fin.eof() ) {
			prevTrackNum = trackNum;
			fin >> trackNum;
			fin >> name;
			fin >> type;
			fin >> subType;
			fin >> eggs;
			fin >> nurse;

			//Detects if the input is at the end of the file
			if (trackNum == prevTrackNum)
				break;

			//adds animals to zoo
			zoo.push_back(makeAnimal(trackNum, name, type, subType, eggs, nurse));
		}

		//close the input file
		fin.close();
		cout << "Load successful." << endl;
	}
}

//Handles saving current zoo data to file on system
void SaveDataToFile(vector<Animal*>& zoo)
{
	//Opens file and confirms it exists
	ofstream fout("input.txt");
	if (!fout.is_open()) {
		cout << "File not found" << endl;
		return;
	}
	else {
		//Writes all the animals in the zoo to the output file
		for (int i = 0; i < zoo.size(); i++) {
			if (zoo[i]->type == "Oviparous") {
				Oviparous* temp = (Oviparous*)zoo[i];
				fout << temp->trackNumber<<endl;
				fout << temp->name << endl;
				fout << temp->type << endl;
				fout << temp->subType << endl;
				fout << temp->getNumberOfEggs() << endl;
				fout << "0" << endl;
			}
			else if (zoo[i]->type == "Mammal") {
				Mammal* temp = (Mammal*)zoo[i];
				fout << temp->trackNumber << endl;
				fout << temp->name << endl;
				fout << temp->type << endl;
				fout << temp->subType << endl;
				fout << "0" << endl;
				fout << temp->getNurse() << endl;
			}

		}

		cout << "Save successfully completed." << endl;
	}
}

//Handles displaying the UI to the user
void DisplayMenu()
{
	cout << "----------------------" << endl;
	cout << "Make a Selection:" << endl;
	cout << "0: Load Data from File" << endl;
	cout << "1: Display Animal Data" << endl;
	cout << "2: Add Animal" << endl;
	cout << "3: Delete Animal" << endl;
	cout << "4: Save Data to File" << endl;
	cout << "5: Generate Data" << endl;
	cout << "6: Exit" << endl;
	cout << "----------------------" << endl;
	cout << "Selection: ";
}

//Handles making the table and printing animal data in easily readable format
void displayAnimalData(vector<Animal*>& zoo) {
	//Creates table heading with spacing
	cout << left << setfill(' ') <<	setw(16) << "Track#" << setw(16) << "Name" << setw(16) << "Type" << setw(16)
			<< "Sub-type" << setw(10) << "Eggs" << setw(10) << "Nurse" << endl;

	//Calls the display() method of each animal
	for (int i = 0; i < zoo.size(); i++) {
		zoo[i]->display();
	}

}

//Main method: Handles running application and managing users choice loop
int main()
{
	//vars for zoo and user choice
	vector <Animal*> zoo;
	int choice = -1;

	//user input loop
	do {
		DisplayMenu();
		cin >> choice;
		switch (choice) {
		case 0:
			LoadDataFromFile(zoo);
			break;
		case 1:
			displayAnimalData(zoo);
			break;
		case 2:
			AddAnimal(zoo);
			break;
		case 3:
			RemoveAnimal(zoo);
			break;
		case 4:
			SaveDataToFile(zoo);
			break;
		case 5:
			GenerateData();
			break;
		case 6:
			cout << "Exiting Application" << endl;
			break;
		default:
			cout << "Invalid input! Please try again." << endl;
			break;
		}
	} while (choice != 6);

	return 1;
}
