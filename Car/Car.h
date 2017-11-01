#pragma once
//  Yinon Bloch
// This class is an imitation of the original String class with some of its functionality

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int COLOR_LENGTH = 10;
const int ENGINE_VOLUME_MAX = 10000;
const int ENGINE_VOLUME_MIN = 100;
const int YEAR_MAX = 2018;
const int YEAR_MIN = 1800;

const int ACTION_ADD = 1;
const int ACTION_COMP_BY_YEAR = 2;
const int ACTION_COMP_BY_ENGINE = 3;
const int ACTION_EXIT = 0;

class  Car
{
public:
	/*
	c-tor init Car
	*/
	Car(string m_make, string m_model, string color, size_t year, size_t engineVolume);
	/*
	d-tor delete Car
	*/
	~Car();
	
	/*
	This method Compare between 2 strings
	agruments: string to Compare with
	return: 0 if equal, -1 if there not same size
	*/
	Car* CompareByYear(Car* firstCar, Car* secondCar);
	/*
	This method Compare between 2 strings
	agruments: string to Compare with
	return: 0 if equal, -1 if there not same size
	*/
	Car* CompareByEngineVolume(Car* firstCar, Car* secondCar);
	
	/*
	This method print the Car details
	agruments: none
	return: void
	*/
	void print();

private:
	
	string m_make;
	string m_model;
	string m_color;
	size_t m_year;
	size_t m_engineVolume;
};


