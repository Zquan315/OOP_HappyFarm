#pragma once
#include "Animal.h"
#include <string>
using namespace std;

class Sheep :public Animal
{
	
public:

	Sheep();
	~Sheep();
	void Ini();
	double getTuoitho();
	time_t CURRENT_TIME();
	int getID();
	int getOld();
	string getType();
	pair<int, int> getViTri();
	void speak();
	
	double& Full();
	void  getWeight();
	void xuat();
	void update(const time_t curr);
	double S_of_move();;
	
};