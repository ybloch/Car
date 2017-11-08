#include "Car.h"

using namespace std;

Car::Car(){}

Car::Car(string make, string model, string color, size_t year, size_t engineVolume)
{
	
	m_make = !make.empty() ? make : throw exception("invalid maker");
	m_model = !model.empty() ? model : throw exception("invalid model");
	m_color = (!color.empty() && color.length() <= COLOR_LENGTH) ? color : throw exception("invalid color");
	m_year = (year >= YEAR_MIN && year <= YEAR_MAX) ? year : throw exception("invalid year");
	m_engineVolume = (engineVolume >= ENGINE_VOLUME_MIN && engineVolume <= ENGINE_VOLUME_MAX) ? engineVolume : throw exception("invalid engine volume");
}

Car::Car(const Car& myCar):m_color(myCar.m_color), m_engineVolume(myCar.m_engineVolume), m_make(myCar.m_make), m_model(myCar.m_model)
{}

const Car& Car::CompareByYear(const Car& firstCar, const Car& secondCar)
{
	if (NULL == &firstCar || NULL == &secondCar)
	{
		throw exception("the given car is NULL pointer!");
	}
	else
	{
		return (firstCar.m_year >= secondCar.m_year)? firstCar: secondCar;
	}
} 

const Car& Car::CompareByEngineVolume(const Car& firstCar, const Car& secondCar)
{
	if (NULL == &firstCar || NULL == &secondCar)
	{
		throw exception("the given car is NULL pointer!");
	}
	else
	{
		return (firstCar.m_engineVolume >= secondCar.m_engineVolume) ? firstCar : secondCar;
	}
}



void Car::print() const
{
	if (NULL != this)
	{
		cout << "Car:\n"
			<< "Maker: " << m_make << endl
			<< "Model: " << m_model << endl
			<< "Coler: " << m_color << endl
			<< "Year: " << to_string(m_year) << endl
			<< "Engine Volume: " << to_string(m_engineVolume) << endl;
	}
	else
	{
		throw exception("the given car is NULL pointer!");
	}
}

void printMenu()
{
	cout << "enter action:\n"
		<< "1 - add\n"
		<< "2 - compare by year\n"
		<< "3 - compare ny engine volume\n"
		<< "0 - exit\n";
}

void main(void)
{
	int userAction = ACTION_ADD;
	char userMaker[250] = "";
	char userColor[250] = "";
	char userModel[250] = "";
	size_t userYear = 0;
	size_t userEngineVolume = 0;

	try
	{
		while (ACTION_EXIT != userAction)
		{
			printMenu();
			cin >> userAction;

			switch (userAction)
			{
				case ACTION_ADD:
					{
						cout << "enter car maker: ";
						cin >> userMaker;
						cout << "enter car model: ";
						cin >> userModel;
						cout << "enter car color: ";
						cin >> userColor;
						cout << "enter car year: ";
						cin >> userYear;
						cout << "enter car engine volume: ";
						cin >> userEngineVolume;

						const Car car(userMaker, userModel, userColor, userYear, userEngineVolume);
						
						car.print();
						
						break;
					}
				case ACTION_COMP_BY_ENGINE:
				case ACTION_COMP_BY_YEAR:
					{
						cout << "enter first car maker: ";
						cin >> userMaker;
						cout << "enter first car model: ";
						cin >> userModel;
						cout << "enter first car color: ";
						cin >> userColor;
						cout << "enter first car year: ";
						cin >> userYear;
						cout << "enter first car engine volume: ";
						cin >> userEngineVolume;

						const Car car1(userMaker, userModel, userColor, userYear, userEngineVolume);
						cout << "your first car details:\n";
						car1.print();
						cout << "enter second car maker: ";
						cin >> userMaker;
						cout << "enter second car model: ";
						cin >> userModel;
						cout << "enter second car color: ";
						cin >> userColor;
						cout << "enter second car year: ";
						cin >> userYear;
						cout << "enter second car engine volume: ";
						cin >> userEngineVolume;

						const Car car2(userMaker, userModel, userColor, userYear, userEngineVolume);
						cout << "your second car details:\n";
						car2.print();

						const Car car3 = (ACTION_COMP_BY_ENGINE == userAction) ? Car::CompareByEngineVolume(car1, car2) : Car::CompareByYear(car1, car2);
						string strToPrint = ACTION_COMP_BY_ENGINE == userAction ? "the car with the grather Engine is:\n" : "the oldest car:\n";
						cout << strToPrint;
						car3.print();
						break;
					}
					
				case ACTION_EXIT:
					{
						cout << "bay bay...";
						break;
					}
				default:
					break;
			}
		}

	}
	catch (const std::exception& exp)
	{
		cout << exp.what() << endl;
		system("pause");
	}
}
