#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	string param,law,name,swap,exit;
	bool fin=0,ccheck1=0,endfile=0,ccheck2=0;
	int countb=0, countm=1,z=0,i=1,memold=1,defrulecheck=0;
	setlocale(LC_ALL, "ru");
	string base = "����.txt";
	string memory = "������.txt";
	string check1 = "(defrule";
	string arrow = "=>";
	string basecheck;
	ifstream din;
	ofstream dout;
	/*din.open(memory);
	if(!din.is_open())
	{
		cout << "net" << endl;
	}
	else
	{
		cout << "da"<< endl;
	} */
	din.open(memory);
	while (!din.eof()) {
		memold++;
		std::getline(din, param);
	} // ������� ��������� ���������� �������� ������
	din.close();
	din.open(base);
	while (!din.eof()) {
		param = "";
		din >> param;
		if (param == check1)
		{
			basecheck.append("0");
		}
	}// ������� ��� ������� ������ ������ ���������� ������������� ������
	din.close();
	while (z == 0) {
		din.open(memory);
		for (i = 1; countm >= i; i++) {
			std::getline(din, param);
		}// ��������� � ����� ��������� ����� ������
		countm++;
		i = 0;
		if (exit==param) {
				z = 1;
		} //��������� �������
		exit = param;
		din.close();
		din.open(base);
		if (z == 0)
		{
			while (!din.eof() && fin == 0) {
			
				if (law == check1 ) {
					if (basecheck[defrulecheck] == '0') {//����������� � ������ ���� ������������ ������� ������� �� ���� ������������ 
						
						defrulecheck++;
						ccheck1 = 1;
						std::getline(din, law);
						countb++;
					}
					else {
						defrulecheck++;
						std::getline(din, law);
						countb++;
						if (law.length() > 8) {
							name = law;
							name.erase(0, 9);
							law.erase(8, law.length());
						}
					}
				}
				else //���� ������ ������� ���������� ���������� ��� ��� 
				{
					std::getline(din, law);
					countb++;
					if (law.length()>8){
					name = law;
					name.erase(0, 9);
					law.erase(8, law.length());
					 }
				}// ����� ��� ����
				if (law == param && ccheck1 == 1) {  //������ ���� ������ 
					swap = "1";
					ccheck2 = 1; }
				if (ccheck1 ==1 && ccheck2 ==0) {
					std::getline(din, swap);
					countb++;
					if (swap == param) { ccheck2 = 1; swap = law; }
				}
				if (ccheck1 == 1 && ccheck2 == 1) {
					if (memold < countm && swap != "1") { law = swap; }
					else { std::getline(din, law);
					countb++;
					}
					
					while (endfile == 0) {
						if (law == arrow) { //���� ������� ������� ��������� ������� 
							din >> law;
							std::getline(din, law);
							law.erase(0, 1);
							countb++;
							law.erase(law.length() - 1, 2);
							
							cout << name << " -> "; 
							din.close();
							dout.open(memory, ofstream::app);
							basecheck[defrulecheck - 1] = '1';
							dout << "\n" << law;
							dout.close();
							din.open(base);
							for (i = 1; countb >= i; i++) {
								std::getline(din, law);
							}
							endfile = 1;
							ccheck1 = 0;
							ccheck2 = 0;
							i = 0;

						}
						else {
							if (i == 0) {
								param = law;
								din.close();
								din.open(memory);
								i = 1;
								std::getline(din, law);
							}
							if (param == law) {
								din.close();
								din.open(base);
								
								for (i = 1; countb >= i; i++) {
									std::getline(din, law);
								}
								countb++;
								i = 0;

							}
							
							if (din.eof() && param != law) {
								endfile = 1;
								ccheck1 = 0;
								ccheck2 = 0;
								i = 0;
								din.close();
								din.open(base);
								for (i = 1; countb >=i; i++) {
									std::getline(din, law);
								}
								
							}
							std::getline(din, law);
						}
					}
					endfile = 0;
				}
				else {
					if (ccheck1 == 1) {
						ccheck1 = 0;

					}
				}


			}
		}
		fin = 0;
		ccheck1 = 0;
		ccheck2 = 0;
		endfile = 0;
		countb = 0;
		defrulecheck = 0;
		if (din.eof()) {
			din.close();
		}

	}
	cout << " the end " << endl;
	system("pause");
     return 0;
}