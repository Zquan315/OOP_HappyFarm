#include "Animal.h"
#include "Sheep.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

Sheep::Sheep()
{

}
void Sheep::Ini()
{
	this->type = "Cuu";
	this->old = 0;
	this->weight = 0;
	this->id = rand() % 1001;
	this->a = 50;
	this->tuoitho = 12 + rand() % 4;;
}
Sheep ::~Sheep()
{
	delete this;
}

time_t Sheep::CURRENT_TIME()
{
	time_t now = time(0);
	return now;
}

int Sheep::getID()
{
	return id;
}



string Sheep::getType()
{
	return type;
}

int  Sheep::getOld()
{
	return old;
}
void Sheep::speak()
{
	cout << "Beeeee Beeeee!\n";
}

double ::Sheep::getTuoitho()
{
	return tuoitho;
}

double& Sheep::Full()
{
	return this->a;
}

void Sheep::getWeight()
{
	double a = 1 + rand() % 2;
	this->weight = this->weight + a;
}

void Sheep::xuat()
{
	cout << " " << id << "\t " << type << "\t "  << int(old)/60 << "\t  " << weight << "\t\t  " << tuoitho << "\t\t  " << this->Full() << endl;
}

pair<int, int> Sheep::getViTri()
{
	pair<int, int> a;
	a.first =  rand() % 11;
	a.second =  rand() % 11;
	return a;
}
double Sheep::S_of_move()
{
	pair<int, int> vitri = this->getViTri();
	pair<int, int> after;
	after.first =  rand() % 11;
	after.second =  rand() % 11;
	int x = after.first - vitri.first;
	int y = after.second - vitri.second;
	double s = sqrt(pow(x, 2) + pow(y, 2));
	return s;
}

void Sheep::update(const time_t curr)
{
	if (this->Full() >= 100)
		this->Full() = 100;
	
	time_t now = time(0);
	time_t k = now - curr;
	this->old = int(k);
	
	this->Full() -= (double(old)/ (60 * 8760) * 6 / 8);
	double s = this->S_of_move();
	this->Full() -= (s * 6);
}





