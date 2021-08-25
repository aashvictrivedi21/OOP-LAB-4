#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

class electricity
{
private:
  char consumer_name[50];
  long int consumer_number;
  char consumer_type[15];
  long int current_mreading;
  long int last_mreading;
  char bill_month[10];
  double amount;

public:
  void readData ();
  void calculateBill ();
  void printBill ();
};

//performing outside the class
void electricity::readData ()	//scope resolution 
{
  cout << "Enter the consumer name:" << endl;
  gets(consumer_name);
  
  cout << "Enter the consumer number:" << endl;
  cin >> consumer_number;
  cout << "Enter the consumer type:" << endl;
  cin >> consumer_type;
  cout << "Enter the current meter reading:" << endl;
  cin >> current_mreading;
  cout << "Enter the last meter reading:" << endl;
  cin >> last_mreading;
  cout << "Enter Bill month:" << endl;
  cin >> bill_month;
}

void electricity::calculateBill()
{
  long int units_consumed;
  units_consumed = current_mreading - last_mreading;
  if (strcmp (consumer_type, "Commercial") == 0)
    {
      if (units_consumed <= 200)
	{
	  amount = units_consumed * 5;
	}
      else
	{
	  amount = 200 * 5;
	  amount = amount + (units_consumed - 200) * 10;
	}
    }
  else if (strcmp (consumer_type, "Non-commercial") == 0)
    {
      if (units_consumed <= 100)
	{
	  amount = units_consumed * 3;
	}
      else
	{
	  amount = amount + (units_consumed - 100) * 5;
	}

    }
}

void electricity::printBill ()
{
  cout << "Consumer Name:" << consumer_name << endl;
  cout << "Consumer number:" << consumer_number << endl;
  cout << "Consumer type:" << consumer_type << endl;
  cout << "Current meter reading:" << current_mreading << endl;
  cout << "Last meter reading:" << last_mreading << endl;
  cout << "Bill month:" << bill_month << endl;
  cout << "Amount to pay:" << amount << endl;

}
int main ()				//object creation-call function with object names
{
  electricity e1;
  e1.readData ();
  e1.calculateBill ();
  e1.printBill ();
  return 0;
  
    
}
