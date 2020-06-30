//  Created by Ercan COŞ on 09.05.2020



//Includes..
#include "IndexLinkedList.h"
#include <chrono>
#include <algorithm> //To use transform which makes tolower.
#include <fstream> // To manage file operations.


//Prototypes..
void getValidqueryWord(string&);
void getValidOption(int&);
int  printDecoratedMenu(const string&);
void createIndex(IndexLinkedList&, const string);


void main() {
	string dirName = "AllDocs";
	IndexLinkedList index;
	string idxCreationTime;
	double temp_time;
	int min;

	cout << endl << "	Welcome to CENG 218 Data Structures 2019-2020- Project 1: Document Indexing" << endl;
	cout << "				Created by Ercan COS" << endl << endl;

	//index.DebugPrint(); //DEBUG PURPOSE, WILL BE DELETED.

	/*Start timer to measure duriation of index creation*/
	auto start = chrono::high_resolution_clock::now();
	createIndex(index, dirName);
	/*stop the timer*/
	auto finish = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = finish - start;
	min = elapsed.count() / 60;
	temp_time = elapsed.count() - (min * 60);

	//cout << "TEST_1__ : " << min << " minutes" << endl; //DEBUG PURPOSE, WILL BE DELETED.

	/*convert time into string and store in idxCreationTime*/
	idxCreationTime = to_string(min) + " minutes";
	cout << endl;
	int opt;
	do {
		opt = printDecoratedMenu(idxCreationTime);
		switch (opt) {
		case 1: {
			string queryWord;
			//prompt user to enter single query word
			getValidqueryWord(queryWord);
			index.printListOfFiles(queryWord);
			//cout << queryWord << endl; //Debug purpuse , will be delete.

			//index.printListOfFiles(queryWord);
			break;
		}
		case 2: index.printMostFrequentWords(10); break;
		case 3: index.printLeastFrequentWords(10); break;
		}
	} while (opt != 4);


	cout << endl << endl << "Bye !" << endl << endl;

}//End of main function.


void getValidqueryWord(string &queryWord) {
	string temp;
	bool test = true;
	cout << endl << "Input your keyword(Use only letters.) : ";
	getline(cin, temp);
	while (test) {
		for (string::iterator it = temp.begin(); it != temp.end(); ++it) {
			if ((*it >= 65 && *it <= 90) || (*it >= 97 && *it <= 122)) {
				test = false;
			}
			else {
				test = true;
				break;
			}
		}
		if (test) {
			cout << endl << "You have to input only one word as a single. " << endl;
			cout << "Input your keyword(Use only letters.) : ";
			getline(cin, temp);
		}
	}
	transform(temp.begin(), temp.end(), temp.begin(), tolower);
	temp.erase(remove_if(temp.begin(), temp.end(), isspace), temp.end()); // Could be remove to improve performance.
	queryWord = temp;

}//End of function.


void getValidOption(int &option) {
	bool test = false;
	do {
		if (test) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		cout << endl << "    Option : ";
		cin >> option;

		if (!(option < 5 && option>0))
			test = true;

	} while (!(option < 5 && option>0));
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}//End of function.


int  printDecoratedMenu(const string &indexCreationDuration) {
	cout << endl;
	for (int i = 0; i < 276; i++) {
		if (i == 0)
			cout << char(201);
		else if (i < 90)
			cout << char(205);
		else if (i == 90) {
			cout << char(187) << endl;
			cout << char(186) << "                               ";
			cout << "Simple Document Retrieval System";
			cout << "                          " << char(186) << endl;
			cout << char(186) << "                                        (";
			cout << indexCreationDuration << ")";

			for (int k = 47 - indexCreationDuration.size(); k > 0; k--) {
				cout << char(32);
			}//End of for-loop.

			cout << char(186) << endl;
			cout << char(204);
		}
		else if (i < 180)
			cout << char(205);
		else if (i == 180)
			cout << char(185) << endl;
		else if (i == 181) {
			cout << char(186) << "               ";
			cout << "1. Enter a single keyword to list the document(s)(file names)";
			cout << "             " << char(186) << endl;
		}
		else if (i == 182) {
			cout << char(186) << "               ";
			cout << "2. Print the top 10 words that appeared most frequently";
			cout << "                   " << char(186) << endl;
		}
		else if (i == 183) {
			cout << char(186) << "               ";
			cout << "3. Print the top 10 words that appeared least frequently";
			cout << "                  " << char(186) << endl;
		}
		else if (i == 184) {
			cout << char(186) << "               ";
			cout << "4. Exit ";
			cout << "                                 ";
			cout << "                                 ";
			cout << char(186) << endl;
		}
		else if (i == 185)
			cout << char(200);
		else if (i < 275)
			cout << char(205);
		else if (i == 275)
			cout << char(188) << endl;
	}//End of for-loop.


	int option;
	getValidOption(option);
	return option;
}//End of function.


void createIndex(IndexLinkedList &index, const string directoryOfFiles) {
	string file_name, word;
	fstream f;
	int k = 1, j = 0;
	size_t len;

	int fix;
	string fixed;

	cout << endl << " Processing ";

	for (int i = 1; i < 9599; i++) { //Text file number : 9599

		//Animation of process statement START POINT.
		if (i % 251 == 0) {
			cout << ">" << flush;
			cout << "\b" << flush;
		}
		else if (i % 1049 == 0) {
			cout << ">>" << flush;
			cout << "\b\b" << flush;
		}
		else if (i % 1993 == 0) {
			cout << ">>>" << flush;
			cout << "\b\b\b" << flush;
		}
		else if (i % 2749 == 0) {
			cout << ">>>>" << flush;
			cout << "\b\b\b\b" << flush;
		}
		else if (i % 4639 == 0) {
			cout << ">>>>>" << flush;
			cout << "\b\b\b\b\b" << flush;
		}
		else if (i % 6317 == 0) {
			cout << ">>>>>>" << flush;
			cout << "\b\b\b\b\b\b" << flush;
		}
		else if (i % 8363 == 0) {
			cout << ">>>>>>>" << flush;
			cout << "\b\b\b\b\b\b\b" << flush;
		}

		//Animation of process statement END POINT.

		file_name = "AllDocs/" + to_string(i) + ".txt";

		f.open(file_name, ios::in);
		if (!f) {
			cout << endl << "Error opening input file !" << endl;
			//return -1; -> will be replace a different way.
		}
		else {
			f >> word;
			while (!f.eof()) {
				//cout << "ilk HAL : " << word << endl;	//DEBUG PURPOSE, WILL BE DELETED.
				len = word.length();
				j = 0;
				if (len > 5) {
					fix = len;
					while (j < len) {
						if (!((word[j] > 64 && word[j] < 91) || (word[j] > 96 && word[j] < 123))) {
							word[j] = char(32);
							j++;
						}
						else
							j++;
					}

					for (int y = 0; y < fix; y++) {

						while (word[y] != 32 && y < fix) {
							fixed.push_back(word[y++]);
						}

						if (!fixed.empty()) {
							transform(fixed.begin(), fixed.end(), fixed.begin(), tolower);
							index.addWord(fixed, file_name);
							fixed.clear();
						}

						y++;
					}

				}
				else {
					while (j < len) {
						if (!isalnum(word[j]) || word[j] == ' ' || isdigit(word[j])) {
							word.erase(j, 1);
							len--;
						}
						else
							j++;
					}

					if (!word.empty()) {
						transform(word.begin(), word.end(), word.begin(), tolower);
						//cout << "SON_ HAL : " << word << endl;	//DEBUG PURPOSE, WILL BE DELETED.
						index.addWord(word, file_name);
						//index.DebugPrint(); //DEBUG..
					}
				}
				f >> word;
			}

			f.close();
		}
	}
}//End of function.