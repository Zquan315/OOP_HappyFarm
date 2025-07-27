#pragma once
#include <string>
using namespace std;
#include <ctime>
class Animal
{
protected:

	string type;
	double old, weight, id, tuoitho;
	double a/*do no = 100*/;
public:
	Animal();
	virtual ~Animal() = 0;
	virtual time_t CURRENT_TIME()=0; // thoi gian luc con vat duoc tao ra
	virtual void  Ini() =0; // la ham khoi tao cac dac tinh con vat
	virtual double getTuoitho() = 0; // tuoi to cua con vat
	virtual pair<int, int> getViTri() =0; // vi tri con vat
	virtual int  getID()=0; // lat ID cua con vat
	virtual int getOld()=0;  // lay tuoi cua con vat
	virtual string getType()=0; // lay loai cua con vat
	virtual void speak() = 0; // tieng keu cua cua con vat
	virtual double& Full() = 0; // do no cua con vat, tahy doi len xuong theo thoie gian nen tham chieu
	virtual void getWeight()=0 ;// lay can nang cua con vat
	virtual void update(const time_t curr) = 0; // update cac dac tinh cua con vat sau 1 khaong thoi gian 
	virtual void xuat() = 0; // xuat cac dac tinh cua con vat
	virtual double S_of_move() =0; // quang duong di chuyen lan dau va sau 1 khoang thoi gian 
	
};