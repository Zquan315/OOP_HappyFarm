#include <iostream>
#include "Animal.h"
#include "Cow.h"
#include "Sheep.h"
#include"Pig.h"
#include"Chicken.h"
#include <vector>
#include <ctime>
#include <Windows.h>
using namespace std;


int main()
{
	vector <Animal*> Ani;
	time_t curr;
	pair<int, int > vt;
	int choose;
	do
	{
		cout << "\n\n----------------MENU---------------\n";
		cout << "0. Thoat.\n";
		cout << "1. them 1 con vat vao trang trai.\n";
		cout << "2. Xuat danh sach cac con vat trong trang trai\n";
		cout << "3. Xuat danh sach cac con vat trong trang trai sau t gio\n";
		cout << "4. Cho tat ca cac con vat an.\n";
		cout << "5. Cho vai con vat an theo ID.\n";
		cout << "6. Di chuyen/ update 1 con vat theo ID.\n";
		cout << "Choose: ";
		cin >> choose;
		switch (choose)
		{
		case 0:
			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~THE END~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			return 0;
		case 1:
		{
			string s;
			do {
				cout << "Nhap loai con vat(Bo/Cuu/Heo/Ga): ";
				cin >> s;
				if (s == "Bo")
				{

					Animal* cow = new Cow();
					curr = cow->CURRENT_TIME();
					cow->Ini();
					Ani.push_back(cow);
					cout << "\nDa them 1 con Bo.\n";
					break;
				}
				else if (s == "Cuu")
				{

					Animal* sh = new Sheep();
					curr = sh->CURRENT_TIME();
					sh->Ini();
					Ani.push_back(sh);
					cout << "\nDa them 1 con Cuu.\n";
					break;
				}
				else if (s == "Heo")
				{
					Animal* p = new Pig();
					curr = p->CURRENT_TIME();
					p->Ini();
					Ani.push_back(p);
					cout << "\nDa them 1 con Heo.\n";
					break;
				}
				else if (s == "Ga")
				{
					Animal* ch = new Chicken();
					curr = ch->CURRENT_TIME();
					ch->Ini();
					Ani.push_back(ch);
					cout << "\nDa them 1 con Ga.\n";
					break;
				}
				else
					cout << "Khong the them con " << s << "!\n";
			} while (s != "Bo" && s != "Cuu" && s != "Heo" && s != "Ga");
			break;
		}
		case 2:
			if (Ani.size() == 0)
			{
				cout << "Trong\n";
				break;
			}
			cout << "\n------------------------Bang thong tin----------------------\n";
			cout << "|ID\t|Loai\t|Tuoi\t|Can nang\t|Tuoi Tho\t|Do no|\n";
			for (int i = 0; i < Ani.size(); i++)
			{
				Ani[i]->xuat();
				if (Ani[i]->Full() < 50 && Ani[i]->Full() > 10)
				{
					cout << " " << Ani[i]->getID() << " keu: ";
					Ani[i]->speak();
				}
			}	
			break;
		case 3:
		{
			if (Ani.size() == 0)
			{
				cout << "Trong\n";
				break;
			}
			
			for (int i = 0; i < Ani.size(); i++)
			{

				Ani[i]->update(curr);
				if (Ani[i]->Full() <= 10 || Ani[i]->getOld() == Ani[i]->getTuoitho())
				{
					cout << '\n' << Ani[i]->getID() << " da chet!\n";
					Ani.erase(Ani.begin() + i);
				}
			}
			if (Ani.size() == 0)
			{
				cout << "Trong.\n";
				break;
			}
			cout << "\n---------------Bang thong tin sau t gio---------------------\n";
			cout << "|ID\t|Loai\t|Tuoi\t|Can nang\t|Tuoi Tho\t|Do no|\n";
			for (int i = 0; i < Ani.size(); i++)
			{
					Ani[i]->xuat();
					if (Ani[i]->Full() < 50 && Ani[i]->Full() > 10)
					{
						cout << " " << Ani[i]->getID() << " keu: ";
						Ani[i]->speak(); 
					}
			}
				
			
			break;
		}
			
		case 4:
		{
			if (Ani.size() == 0)
			{
				cout << "Trong\n";
				break;
			}
			int x;
			cout << "Nhap so luong kg muon cho an: "; cin >> x;
			for (int i = 0; i < Ani.size(); i++)
			{
				
				// tang theo tung loai / stop here
				if (Ani[i]->getType() == "Bo")
				{
					Ani[i]->Full() += (x * 20);
					if (Ani[i]->Full() >= 100)
					{
						Ani[i]->Full() = 100;
						Ani[i]->getWeight();
					}
						
				}
				else if (Ani[i]->getType() == "Cuu")
				{
					Ani[i]->Full() += (x * 20) ;
					if (Ani[i]->Full() >= 100)
					{
						Ani[i]->Full() = 100;
						Ani[i]->getWeight();
					}
				}
				else if (Ani[i]->getType() == "Heo")
				{
					Ani[i]->Full() += (x * 30);
					if (Ani[i]->Full() >= 100)
					{
						Ani[i]->Full() = 100;
						Ani[i]->getWeight();
					}
				}
				else if (Ani[i]->getType() == "Ga")
				{
					Ani[i]->Full() += (x * 100/0.2);
					if (Ani[i]->Full() >= 100)
					{
						Ani[i]->Full() = 100;
						Ani[i]->getWeight();
					}
				}
				
			}
			cout << "Da cho tat ca con vat an!\n";
			break;
		}
		case 5:
		{
			
			if (Ani.size() == 0)
			{
				cout << "Trong\n";
				break;
			}
			cout << "\n\n----------------------Bang thong tin-----------------------\n";
			cout << "|ID\t|Loai\t|Tuoi\t|Can nang\t|Tuoi Tho\t|Do no|\n";
			for (int i = 0; i < Ani.size(); i++)
			{
				Ani[i]->xuat();
				
			}
			int s;
			do
			{
				cout << "0. Exit.\n";
				cout << "Chon ma so con vat muon cho an: ";
				cin >> s;
				if (s == 0) break;
				int a;
				cout << "Nhap so luong kg muon cho an: "; cin >> a;
				
				for(int i=0;i<Ani.size();i++)
					if (Ani[i]->getID() == s)
					{
						
						if (Ani[i]->getType() == "Bo")
						{
							Ani[i]->Full() += (a* 20);
							if (Ani[i]->Full() >= 100)
							{
								Ani[i]->Full() = 100;
								Ani[i]->getWeight();
							}
						}
						else if (Ani[i]->getType() == "Cuu")
						{
							Ani[i]->Full() += (a * 20);
							if (Ani[i]->Full() >= 100)
							{
								Ani[i]->Full() = 100;
								Ani[i]->getWeight();
							}
							
						}
						else if (Ani[i]->getType() == "Heo")
						{
							Ani[i]->Full() += (a * 30);
							if (Ani[i]->Full() >= 100)
							{
								Ani[i]->Full() = 100;
								Ani[i]->getWeight();
							}
							
						}
						else if (Ani[i]->getType() == "Ga")
						{
							Ani[i]->Full() += (a * 100/0.2);
							if (Ani[i]->Full() >= 100)
							{
								Ani[i]->Full() = 100;
								Ani[i]->getWeight();
							}
						}
						cout << "Da cho con vat an!\n";
						break;
					}

			} while (1);
			break;
		}
		case 6:
		{
			
			if (Ani.size() == 0)
			{
				cout << "Trong\n";
				break;
			}
			cout << "\n\n------------------------Bang thong tin-----------------------\n";
			cout << "|ID\t|Loai\t|Tuoi\t|Can nang\t|Tuoi Tho\t|Do no|\n";
			for (int i = 0; i < Ani.size(); i++)
			{
				Ani[i]->xuat();
				
			}
			cout << "Nhap ma so con vat: ";
			int ms; cin >> ms;
			int flag = 0;
			for(int i=0;i<Ani.size();i++)
				if (Ani[i]->getID() == ms)
				{
					Ani[i]->update(curr);
					flag = 1;
					cout << "Da di chuyen con vat!\n";
					break;
				}	
			if(flag == 0)
				cout << "\nKhong co con vat mang ID do.\n";
		}
		break;
		}

	}while (1);
	return 0;
}

