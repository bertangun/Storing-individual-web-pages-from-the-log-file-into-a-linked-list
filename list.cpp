#include <iostream>
#include <string>
#include <fstream>
#include "list.h"

using namespace std;

list::list() {

	head = NULL;
	tail = NULL;
}

void list::nodegen(string fileName)  //texten okunan filName'leri link liste yerleþtiren function
{
	node *temp = new node;
	temp->data = fileName;



	temp->next = NULL;
	if (head == NULL)   //link list boþ,ilk fileName linkliste yerleþtirilecek.
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

void list::display() // en büyük 10 filName'i ekrana basan function.
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

void list::duprem(node *head) {   //duplicateleri silip count'ý bir arttýran function.

	
		while (head != NULL){

		node* prev = head;
		node* current;
		while (prev->next != NULL ) {

			current = prev->next;
			if (head->data == current->data) {   //duplicate bulundu
				head->count++;                   //count arttýrýldý
					prev->next = current->next;      //current silinecek, pasif duruma getir.

					//delete(current);    // 6-7 sn hýzlandý.
			}
			else
			{
				prev = current;  //duplicate yok ilk deger current
			}
		}

		head = head->next; //diger nodelara geç 
		
		}

}
			

void list::sorter() // En büyük fileName'i sýralayan function.(artandan azalana,bubble sort)
{
	node * ending = NULL;
	while (ending != head)
	{
		
		node *temp = new node;//swap için t1,t2 ve temp kullanýlacak.
		node* t1;
		t1 = head;               //initial koþulumuz,t1 temp'de önce karþýlaþýlan deger.
		while (t1->next != ending)
		{
			if (t1->count < t1->next->count)   // count'u büyük olaný öne al 
			{
				node *t2 = t1->next;   // t2,t1'den sonra gelen deger
				t1->next = t2->next;   //linklist'e t1 ve t2'yi ptr(t2->next) yardýmýyla yerini degitirdik.(t2 öne gelicek)
				t2->next = t1;        
				if (t1 == head)   // en büyük deger t1(head) ise t2(t1'in countundan daha büyük) ile swap yap.
				{
					head = t2;    //swap iþlemleri(en büyük degeri t1'e atýyor )
					t1 = t2;      
				}
				else 
				{
					t1 = t2;     //swap iþlemleri 
					temp->next = t2;   //t2den daha büyük node veya node'lar var.
				}
			}
			temp = t1;         //esit veya t1 daha büyükse NULL degeri bulana kadar devam et.
			t1 = t1->next;
		}

		ending = t1;  // t1 update edildi.(son sýrada)
	}
}
