#pragma once
#include "Animal.h"
#include <string>
using namespace std;

class Pig :public Animal
{
	
public:

	Pig();
	~Pig();
	void Ini();
	time_t CURRENT_TIME();
	int getID();
	int getOld();
	string getType();
	pair<int, int> getViTri();
	void speak();
	double getTuoitho();
	double& Full();
	void getWeight();
	void xuat();
	void update(const time_t curr);
	double S_of_move();
};