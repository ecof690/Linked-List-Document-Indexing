//  Created by Ercan COŞ on 09.05.2020


#include "IndexLinkedList.h"



IndexLinkedList::IndexLinkedList() {
	for (int i = 0; i < 26; i++) {
		accelaration_services *temp = new accelaration_services('z' - i);
		temp->next = head;
		head = temp;
	}

}//End of defualt-constructor.



void IndexLinkedList::DebugPrint() {
	cout << endl << endl << "DEBUG PROCESS START !" << endl << endl;


	accelaration_services *iter = head;

	while (iter != NULL) {
		cout << "Letter : " << iter->letter;
		cout << " Head : " << iter->head << endl;
		iter = iter->next;
	}


	cout << endl << endl << "DEBUG PROCESS END !" << endl << endl;

}//End of DEBUG - method.



void IndexLinkedList::addWord(const string & word, const string & fileName) {
	WordTypeNode *res = NULL;
	accelaration_services *iter = head;

	//static int DEBUG_TEST = 0;	//DEBUG PURPOSE, WILL BE DELETED.
	//cout<<endl<<word <<endl;	//DEBUG PURPOSE, WILL BE DELETED.

	res = search(word);
	if (res != NULL) {
		res->wordFreq = res->wordFreq + 1;
		//DEBUG_TEST++;	//DEBUG PURPOSE, WILL BE DELETED.

		FileNameNode *iter_file = res->fileListHead;
		FileNameNode *prev;

		while (iter_file->next != NULL)
			iter_file = iter_file->next;

		if (iter_file->fileName != fileName) {
			FileNameNode *temp3_1 = new FileNameNode(fileName);
			iter_file->next = temp3_1;
		}

	}
	else {
		for (int i = 0; i < 26; i++) {

			if (iter == NULL)
				return;

			if (word[0] == iter->letter) {
				break;
			}
			else
				iter = iter->next;
		}//End of for-loop.

		if (iter->head != NULL) {
			WordTypeNode *iter2 = iter->head;
			WordTypeNode *word_creation = new WordTypeNode(word);
			FileNameNode *file_Creation = new FileNameNode(fileName);

			word_creation->wordFreq = 1;
			word_creation->fileListHead = file_Creation;

			while (iter2->next != NULL)
				iter2 = iter2->next;

			iter2->next = word_creation;
		}
		else {
			WordTypeNode *word_creation = new WordTypeNode(word);
			FileNameNode *file_Creation = new FileNameNode(fileName);

			word_creation->wordFreq = 1;
			word_creation->fileListHead = file_Creation;

			iter->head = word_creation;
		}//End of inner-if-statement.

		//DEBUG_TEST++;	//DEBUG PURPOSE, WILL BE DELETED./

	}//End of if-statement.

	//cout << endl << " [Success !!!!!" << endl;	//DEBUG PURPOSE, WILL BE DELETED.
	//cout << endl << " [Success !!!!!	" << DEBUG_TEST << endl;	//DEBUG PURPOSE, WILL BE DELETED.

}//End of method.



void IndexLinkedList::printListOfFiles(const string & singleWordQuery) const {
	WordTypeNode *res = NULL;
	res = search(singleWordQuery);
	if (res == NULL) {
		cout << endl << endl << "There is no word like : " << singleWordQuery << endl << endl;
		return;
	}
	else {
		FileNameNode *iter = res->fileListHead;

		cout << "Choosed word : " << singleWordQuery << endl;
		cout << "List of file names that includes your word ;" << endl;
		while (iter != NULL) {
			cout << "->	" << iter->fileName << endl;
			iter = iter->next;
		}//End of while-loop.

	}//End of if-statement.

}//End of method.



void IndexLinkedList::printMostFrequentWords(int topWhat) {
	WordTypeNode **arr = new WordTypeNode*[topWhat];

	int test = 0;

	accelaration_services *iter = head;

	if (iter == NULL)
		return;


	for (int i = 0; i < 26; i++) {

		WordTypeNode *temp = iter->head;

		while (temp != NULL) {

			if (test < topWhat) {
				arr[test] = temp;
				test++;
				arranger(arr, test, true);
			}
			else {
				if (arr[0]->wordFreq < temp->wordFreq) {
					arr[0] = temp;
					arranger(arr, test, true);
				}
			}//End of if-statement.

			temp = temp->next;
		}//End of while-loop.

		iter = iter->next;
	}//End of for-loop.


	if (test < (topWhat - 1)) {
		cout << endl << endl << "There are not enough data that you asked." << endl;
		cout << "There are only " << test + 1 << " words in structure ." << endl << endl;
	}

	cout << endl << "					" << char(244);
	cout << "Most Frequent Words" << char(245) << endl;

	test--; //Prevent overflow on 2D array. -IMPORTANT-

	while (test > 0) {
		cout << " Word : " << arr[test]->word;

		for (int k = 16 - arr[test]->word.size(); k > 0; k--) {
			cout << char(32);
		}//End of for-loop.

		cout << " Frequency : " << arr[test]->wordFreq << endl;

		test--;
	}//End of while-loop.

}//End of method.


void IndexLinkedList::arranger(WordTypeNode **arr, int size, bool mode) {

	int i, j, n;
	WordTypeNode *temp;

	if (mode) {
		for (i = 1; i < size; i++) {
			n = i;
			for (j = i - 1; j >= 0; j--) {
				if (arr[n]->wordFreq < arr[j]->wordFreq) {
					temp = arr[j];
					arr[j] = arr[n];
					arr[n] = temp;
					n--;
				}//End of if-statement.
			}//End of inner-for-loop.
		}//End of for-loop.
	}
	else {
		for (i = 1; i < size; i++) {
			n = i;
			for (j = i - 1; j >= 0; j--) {
				if (arr[n]->wordFreq > arr[j]->wordFreq) {
					temp = arr[j];
					arr[j] = arr[n];
					arr[n] = temp;
					n--;
				}//End of if-statement.
			}//End of inner-for-loop.
		}//End of for-loop.
	}

}//End of method.


void IndexLinkedList::printLeastFrequentWords(int topWhat) {
	WordTypeNode **arr = new WordTypeNode*[topWhat];

	int test = 0;

	accelaration_services *iter = head;

	if (iter == NULL)
		return;


	for (int i = 0; i < 26; i++) {

		WordTypeNode *temp = iter->head;

		while (temp != NULL) {

			if (test < topWhat) {
				arr[test] = temp;
				test++;
				arranger(arr, test, false);
			}
			else {
				if (arr[0]->wordFreq > temp->wordFreq) {
					arr[0] = temp;
					arranger(arr, test, false);
				}
			}//End of if-statement.

			temp = temp->next;
		}//End of while-loop.

		iter = iter->next;
	}//End of for-loop.


	if (test < (topWhat - 1)) {
		cout << endl << endl << "There are not enough data that you asked." << endl;
		cout << "There are only " << test + 1 << " words in structure ." << endl << endl;
	}

	cout << endl << "					" << char(244);
	cout << "Least Frequent Words" << char(245) << endl;

	test--; //Prevent overflow on 2D array. -IMPORTANT-

	while (test > 0) {
		cout << " Word : " << arr[test]->word;

		for (int k = 16 - arr[test]->word.size(); k > 0; k--) {
			cout << char(32);
		}//End of for-loop.

		cout << " Frequency : " << arr[test]->wordFreq << endl;

		test--;
	}//End of while-loop.

}//End of method.



WordTypeNode * IndexLinkedList::search(const string & word)const {
	accelaration_services *iter_search = head;

	if (iter_search == NULL)
		return NULL;

	for (int i = 0; i < 26; i++) {

		if (word[0] == iter_search->letter) {
			break;
		}
		else
			iter_search = iter_search->next;

	}//End of for-loop.

	WordTypeNode *iter2_search = iter_search->head;

	while (iter2_search != NULL) {
		if (word == iter2_search->word)
			return iter2_search;

		iter2_search = iter2_search->next;
	}//End of while-loop.

	return NULL;
}//End of func.


