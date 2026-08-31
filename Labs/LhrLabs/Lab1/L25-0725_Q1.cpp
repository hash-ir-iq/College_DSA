#include<iostream>
#include<cstring>
#include<string>
using namespace std;

void copyData(int* source, int* destination, int size) {
	for (int i = 0; i < size; i++) {
		destination[i] = source[i];
	}
}

class Employee {
private:
	string Name;
	int ID;
	int monthly[6];
	double Final_Salary;
	int overtime[4];
    double performance;

public:
	int Basic_Salary;

	Employee(string c, int Base, int Id, int month[], int over[]) : Name(c), ID(Id), Basic_Salary(Base), Final_Salary(0) {
		copyData(month, monthly, 6);
		copyData(over, overtime, 4);

        // Calculate performance
        int sum = 0;
		for (int i = 0; i < 6; i++) {
			sum += monthly[i];
        }
		performance = sum / 6;

	}

	Employee() {
		Name = "Default";
		ID = -1;
		Basic_Salary = 0;
	}

	double Get_Overtime_Compensation() {
		double Overtime_Compensation = 0;
		for (int i = 0; i < 4; i++) {
			Overtime_Compensation += overtime[i] * 500;
		}
		return Overtime_Compensation;
	}
	double Get_Bonus() {
		if (performance > 90)
			return 0.1 * Basic_Salary;
		else if (performance > 80)
			return 0.7 * Basic_Salary;
		else if (performance > 70)
			return 0.5 * Basic_Salary;
		else
			return 0;
	}

    int get_Id(){
        return ID;
    }

    string get_Name(){
        return Name;
    }

    double get_Performance(){
        return performance;
    }

	virtual double FinalSalary() { return 0; }
};

class Fulltime : public Employee {
private:
	double HRA;
	double Medical_Allowance;
public:

      Fulltime(string c, int Base, int Id, int month[], int over[]) 
        : Employee(c, Base, Id, month, over) {
        HRA = 0.2 * Basic_Salary;
		Medical_Allowance = 0.1 * Basic_Salary;
    }

	Fulltime() : Employee() {
		HRA = 0.2 * Basic_Salary;
		Medical_Allowance = 0.1 * Basic_Salary;
	}

	double FinalSalary() override {
		double Salary = HRA + Medical_Allowance + Get_Bonus() + Get_Overtime_Compensation() + Basic_Salary;
		cout << Salary;
		return Salary;
	}
};


class PartTime : public Employee {
public:

        PartTime(string c, int Base, int Id, int month[], int over[]) 
        : Employee(c, Base, Id, month, over) {  }

	double FinalSalary() override {
		double Salary = Get_Overtime_Compensation() + Basic_Salary + Get_Bonus();
        return Salary;
	}
};


int main()
{
    int emp1_over[4] = { 6, 12, 6, 1 };
    int emp1_performance[6] = { 90, 93, 98, 91, 90, 90 };

    int emp2_over[4] = { 4, 2, 9, 5 };
    int emp2_performance[6] = { 82, 85, 86, 83, 81, 89 };

    Employee* employees[2];
    employees[0] = new Fulltime ( "emp1", 100000, 1 , emp1_performance ,emp1_over);
    employees[1] = new PartTime ( "emp2", 0,2, emp2_performance , emp2_over);

    for (int i = 0; i < 2; i++)
    {
        employees[i]->FinalSalary();
    }

    Employee* best_employee = NULL;

    if(employees[0]->get_Performance() > employees[1]->get_Performance()){
        Employee* best_employee = employees[0];
    }
    else{
        Employee* best_employee = employees[1];
    }

    if( best_employee!=0 )
        cout << "----------------\n";
        cout << "best_employee Performing Employee:" << endl;
        cout << "Employee ID: " <<  best_employee->get_Id() << endl;
        cout << "Name: " << best_employee->get_Name() << endl;
        cout << "Average Performance: " << best_employee->get_Performance() << endl;
    
    for (int i = 0; i < 2; i++) {
        delete employees[i];
    }
}