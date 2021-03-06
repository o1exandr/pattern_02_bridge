/*
Завдання 2. Виконати на вибір одне із завдань з використанням патерну Міст.
Створити програму для обчислення вартості праці програміста. 
Програміст може працювати на фрілансі чи(і) бути працівником  компанії.
Програміст може виконувати завдання на певній мові програмування(С++, C#  та ін.). 
Кожна година роботи оплачується залежно від мови програмування.
Працівник компанії додатково із заробленої суми платить податки.
*/


#include "stdafx.h"
#include <iostream> 
#include <string>

using namespace std;

class CostWork
{
public:

	CostWork()
	{
	}

	virtual ~CostWork()
	{
	}

	virtual void Cost(string language, int costOneHour, int hours) = 0;
};

class Employee
{
protected:

	CostWork * work;

public:

	Employee(CostWork* pWork)
	{
		work = pWork;
	}

	virtual ~Employee()
	{
		if (work)
			delete work;
	}

	virtual void CostEmployee() const = 0;
};

class Programmer :	public Employee
{
private:

	string language;
	int costOneHour;
	int hours;

public:

	Programmer(string pLanguage, int pCostOneHour, int pHours, CostWork* pWork) :Employee(pWork)
	{
		language = pLanguage;
		costOneHour = pCostOneHour;
		hours = pHours;
	}

	virtual ~Programmer()
	{
	}

	void CostEmployee() const
	{
		work->Cost(language, costOneHour, hours);
	}

};

class Freelancer : public CostWork
{
public:

	Freelancer()
	{
	}

	virtual ~Freelancer()
	{
	}

public:

	virtual void Cost(string language, int costOneHour, int hours)
	{
		cout << "Freelancer on " << language << "\n- - - - - - - - - -\nCost one hour: $" << costOneHour << 
			"\nWorked: " << hours << " hours\nGet a salary: $" << hours * costOneHour << "\n\t_ _ _\n\n";
	}
};

class EmployeeCompany :public CostWork
{

public:

	EmployeeCompany()
	{
	}

	virtual ~EmployeeCompany()
	{
	}

public:

	virtual void Cost(string language, int costOneHour, int hours)
	{
		cout << "Employee of company on " << language << "\n- - - - - - - - - -\nCost one hour: $" << costOneHour << 
			"\nWorked: " << hours << " hours\nGet a salary: $" << hours * costOneHour * 0.8 << "\n\t_ _ _\n\n"; //припустимо податок 20%
	}
};

int main()
{
	Employee* freelancerCPP = new Programmer("C++", 10, 160, new Freelancer());
	Employee* employeeCompanyCPP = new Programmer("C++", 10, 160, new EmployeeCompany());
	Employee* freelancerCSharp = new Programmer("C#", 12, 172, new Freelancer());

	freelancerCPP->CostEmployee();
	employeeCompanyCPP->CostEmployee();
	freelancerCSharp->CostEmployee();

	delete freelancerCPP;
	delete employeeCompanyCPP;
	delete freelancerCSharp;


	cout << endl;
	system("pause");
	return 0;
}