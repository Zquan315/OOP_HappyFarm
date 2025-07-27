#include "Animal.h"
#include "Cow.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

Cow::Cow()
{
	
}
void Cow::Ini()
{
	this->type = "Bo";
	this->old = 0;
	this->weight = 0;
	this->id = rand() % 1001;
	this->a = 50;
	this->tuoitho = 18 + rand() % 3;;
}
Cow ::~Cow()
{
	delete this;
}


time_t Cow::CURRENT_TIME()
{
	time_t now = time(0);
	return now;
}

int Cow::getID()
{
	return id;
}

string Cow::getType()
{
	return type;
}

int  Cow::getOld()
{
	return old;
}
void Cow::speak()
{
	cout << "Boooo Booo!\n";
}


double& Cow::Full()
{
	
	return this->a;
}

double ::Cow::getTuoitho()
{
	return tuoitho;
}
void Cow::getWeight()
{
	double a = 1 + rand() % 3;
	this->weight = this->weight + a;
	
}

void Cow:: xuat()
{
	cout << " " << id << "\t " << type << "\t " << int(old)/60 << "\t  " << weight << "\t\t  " << tuoitho << "\t\t  " << this->Full() << endl;
}

pair<int, int> Cow::getViTri()
{
	pair<int, int> a;
	a.first =  rand() % 11;
	a.second =  rand() % 11;
	return a;
}
double Cow::S_of_move()
{
	pair<int, int> vitri = this->getViTri() ;
	pair<int, int> after;
	after.first =  rand() % 11;
	after.second =  rand() % 11;
	int x = after.first - vitri.first;
	int y = after.second - vitri.second;
	double s = sqrt(pow(x, 2) + pow(y, 2));
	return s;
}

void Cow::update(const time_t curr)
{
	if (this->Full() >= 100)
		this->Full() = 100;
	time_t now = time(0);
	time_t k = now - curr;
	this->old = int(k);
	this->Full() -= (double(old)/(60*8760) * 5 / 8);
	double s = this->S_of_move();
	this->Full() -= (s * 5);

}




