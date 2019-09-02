#include <iostream>
#include <string>
#include <fstream>
#include "list.h"

using namespace std;

list::list() {

	head = NULL;
	tail = NULL;
}

void list::nodegen(string fileName)  //texten okunan filName'leri link liste yerle�tiren function
{
	node *temp = new node;
	temp->data = fileName;



	temp->next = NULL;
	if (head == NULL)   //link list bo�,ilk fileName linkliste yerle�tirilecek.
	{
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else             // head dolu,taile fileNme'i ekleyerek devam et.
	{
		tail->next = temp;
		tail = temp;
	}
}

void list::display() // en b�y�k 10 filName'i ekrana basan function.
{
	duprem(head);
	sorter();
	node *temp = new node;
	temp = head;
	int countFile = 0;
	while (temp != NULL && countFile<10)
	{
		countFile++;
		cout << temp->data << "  " << temp->count << endl;

		temp = temp->next;
	}
}

void list::duprem(node *head) {   //duplicateleri silip count'� bir artt�ran function.

	
		while (head != NULL){

		node* prev = head;
		node* current;
		while (prev->next != NULL ) {

			current = prev->next;
			if (head->data == current->data) {   //duplicate bulundu
				head->count++;                   //count artt�r�ld�
					prev->next = current->next;      //current silinecek, pasif duruma getir.

					//delete(current);    // 6-7 sn h�zland�.
			}
			else
			{
				prev = current;  //duplicate yok ilk deger current
			}
		}

		head = head->next; //diger nodelara ge� 
		
		}

}
			

void list::sorter() // En b�y�k fileName'i s�ralayan function.(artandan azalana,bubble sort)
{
	node * ending = NULL;
	while (ending != head)
	{
		
		node *temp = new node;//swap i�in t1,t2 ve temp kullan�lacak.
		node* t1;
		t1 = head;               //initial ko�ulumuz,t1 temp'de �nce kar��la��lan deger.
		while (t1->next != ending)
		{
			if (t1->count < t1->next->count)   // count'u b�y�k olan� �ne al 
			{
				node *t2 = t1->next;   // t2,t1'den sonra gelen deger
				t1->next = t2->next;   //linklist'e t1 ve t2'yi ptr(t2->next) yard�m�yla yerini degitirdik.(t2 �ne gelicek)
				t2->next = t1;        
				if (t1 == head)   // en b�y�k deger t1(head) ise t2(t1'in countundan daha b�y�k) ile swap yap.
				{
					head = t2;    //swap i�lemleri(en b�y�k degeri t1'e at�yor )
					t1 = t2;      
				}
				else 
				{
					t1 = t2;     //swap i�lemleri 
					temp->next = t2;   //t2den daha b�y�k node veya node'lar var.
				}
			}
			temp = t1;         //esit veya t1 daha b�y�kse NULL degeri bulana kadar devam et.
			t1 = t1->next;
		}

		ending = t1;  // t1 update edildi.(son s�rada)
	}
}
