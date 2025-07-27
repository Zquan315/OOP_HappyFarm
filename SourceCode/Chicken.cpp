#include "Animal.h"
#include "Chicken.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

Chicken::Chicken()
{

}
void Chicken::Ini()
{
	this->type = "Ga";
	this->old = 0;
	this->weight = 0;
	this->id = rand() % 1001;
	this->a = 50;
	this->tuoitho = 7 + rand() % 2;
}
Chicken ::~Chicken()
{
	delete this;
}

time_t Chicken::CURRENT_TIME()
{
	time_t now = time(0);
	return now;
}

int Chicken::getID()
{
	return id;
}
double ::Chicken::getTuoitho()
{
	return tuoitho;
}

string Chicken::getType()
{
	return type;
}

int  Chicken::getOld()
{
	return old;
}
void Chicken::speak()
{
	cout << "cuc tac cuc tac!\n";
}



double& Chicken::Full()
{
	
	return this->a;
}

void  Chicken::getWeight()
{
	double a = 0.01 + rand() % 1;
	this->weight = this->weight + a;
}

void Chicken::xuat()
{
	cout << " " << id << "\t " << type << "\t "  << int(old)/60 << "\t  " << weight << "\t\t  " << tuoitho << "\t\t  " << this->Full() << endl;
}

pair<int, int> Chicken::getViTri()
{
	pair<int, int> a;
	a.first =  rand() % 11;
	a.second = rand() % 11;
	return a;
}
double Chicken::S_of_move()
{
	pair<int, int> vitri = this->getViTri();
	pair<int, int> after;
	after.first = rand() % 11;
	after.second =  rand() % 11;
	int x = after.first - vitri.first;
	int y = after.second - vitri.second;
	double s = sqrt(pow(x, 2) + pow(y, 2));
	return s;
}

void Chicken::update(const time_t curr)
{
	if (this->Full() >= 100)
		this->Full() = 100;
	
	time_t now = time(0);
	time_t k = now - curr;
	
	this->old = int(k);
	
	this->Full() -= (double(old)/ (60 * 8760) * 10 / 12);
	double s = this->S_of_move();
	this->Full() -= (s * 10);
}




