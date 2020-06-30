#pragma once

//  Created by Ercan COŞ on 09.05.2020



//Includes..
#include<string>
#include<iostream>


using namespace std;


class FileNameNode {
public:
	string fileName;
	FileNameNode *next;
	FileNameNode(const string fname) :fileName(fname), next(NULL) {}
};
class WordTypeNode {
public:
	string word;
	int wordFreq;
	FileNameNode *fileListHead;
	WordTypeNode *next;
	WordTypeNode(const string word) :word(word), next(NULL), fileListHead(NULL) {}
};

class accelaration_services {
public:
	char letter;
	WordTypeNode *head;
	accelaration_services *next;
	accelaration_services(const char temp) : letter(temp), next(NULL), head(NULL) {}
};

class IndexLinkedList {
private:
	accelaration_services *head;
public:
	IndexLinkedList();
	void addWord(const string&, const string&);
	void printListOfFiles(const string &singleWordQuery)const;
	void printMostFrequentWords(int topWhat);
	void printLeastFrequentWords(int topWhat);

	WordTypeNode* search(const string&)const;
	void DebugPrint();
	void arranger(WordTypeNode**, int, bool);
};