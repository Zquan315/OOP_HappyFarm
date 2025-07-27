#pragma once
#include "Animal.h"
#include <string>
using namespace std;

class Cow :public Animal
{
	
public:
	Cow();
	~Cow();
	void Ini() ;
	time_t CURRENT_TIME();
	int getID();
	int getOld();
	double getTuoitho() ;
	string getType();
	pair<int, int> getViTri();
	void speak() ;
	double& Full() ;
	void getWeight() ; // tang khi cho an
	void xuat();
	void update(const time_t curr);
	double S_of_move();
	
};