#include <iostream>
#include <conio.h>
#include <string.h>
#include<stdlib.h>
using namespace std;

struct Node {
	char nama[30];
	Node *next;
};

Node *head = NULL, *tail = NULL;
int count = 0, maxstack = 5;

void push() {
	if(count == maxstack)
		cout<<"Maaf Push tidak bisa dilakukan karena Stack penuh!\n";
	else {
		char namabuku[30];
		cout<<"Nama Buku : "; 
		cin>>namabuku;
		Node *baru = new Node;
		strcpy(baru->nama, namabuku);
		
		if(head == NULL) {
			baru->next = NULL;
			head = baru;
			tail = baru;
		} else {
			baru->next = NULL;
			tail->next = baru;
			tail = baru;
		} 
		cout<<"berhasil push Buku "<<namabuku<<endl;
		++(count);
		cout << "" << endl;

	}
	
}

void pop() {
	if(head == NULL)
		cout<<"gagal pop, stack kosong\n" << endl;
	else {
		cout<<"berhasil pop "<<head->nama<<endl;
		if(head == tail) {
			delete head;
			head = NULL;
			tail = NULL;
		} else {
			Node *bantu = head;
			while(bantu->next != tail) {
				bantu = bantu->next;
			}
			bantu->next = NULL;
			delete tail;
			tail = bantu;
		} --(count);
	
	}
}

void print() {
	Node *bantu = head;
	while(bantu!=NULL) {
		cout<< "-- Nama : "<<bantu->nama<<endl;
		bantu = bantu->next;
	}
	
}

void keluar() {
	cout << "" << endl;
	cout << "Terimakasih telah menggunakan" << endl;
	cout << "@2022" << endl;
}

void clear() {
	system("cls");
}
int main() {
	int pilih;
	do {
		cout << "" << endl;
		cout<<"Operasi - operasi Stack :\n";
		cout<<"1. Push\n";
		cout<<"2. Pop\n";
		cout<<"3. Print\n";
		cout<<"4. Keluar\n";
		cout <<"5. Clear Terminal\n";
		cout<<"-- Pilih operasi : "; cin>>pilih;
		system("cls");
	
		
		if(pilih==1) push();
		if(pilih==2) pop();
		if(pilih==3) print();
		if(pilih==4) keluar();
		if(pilih==5) clear();
	
	} while(pilih!=4);
	



	return 0;
}