
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "list.h"


using namespace std;



void deleteChar(ifstream &in)   //ilk 3 karakteri resetle.(UNICODE problem)
{
	char temp[3] = { 0 };
	in.read(temp, 3);
	if ((unsigned char)temp[0] == 0xEF &&
		(unsigned char)temp[1] == 0xBB &&
		(unsigned char)temp[2] == 0xBF)
	{
		return;
	}
	in.seekg(0);
}

int main() {

	clock_t start = clock();
	list obj;
	cout << "****Please Wait****" << endl;
	cout << "" << endl;
	string txt;
	
	ifstream file;
	file.open("access_log");
	if (!file) {
		cerr << "No File Found";
		system("PAUSE");
	}
	deleteChar(file);
	getline(file, txt, '\r'); // boþluðu tanýmasý için(mac ile alakalý) 2. satýrý almýyor.

	file.close();


	char *c = &txt[0u];

	int n = strlen(c);
	for (int i = 0; i < n; i++) { 
		string temp;
		if (c[i] == 'G' && (c[i + 1]) == 'E'&&c[i + 2] == 'T') {
			i = i + 3;
			while (c[i] != 'H'&&c[i + 1] != 'T'&&c[i + 2] != 'T'&&c[i + 3] != 'P') {

				temp = temp + c[i];
				i++;
			}
		}
		if (temp != "") {

			obj.nodegen(temp);
		}
	}	
	
	obj.display();
	cout << "" << endl;

	clock_t stop = clock();
	double elapsed_time = (double)(stop - start) / CLOCKS_PER_SEC;
	cout << "Total Elapsed Time : " << elapsed_time<<" seconds"<< endl;
	cout << "" << endl;

	system("PAUSE");
	return 0;
}



