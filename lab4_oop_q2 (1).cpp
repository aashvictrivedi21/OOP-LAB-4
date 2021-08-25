/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

class player
{
private:
char Name[40];
char Region[20];
float Batting_Avg;
float Bowling_Avg;


public:
void readData();
//void static generateList(player [], int, player [], int );
void static generateList(player p[5], int size, player p2[5], int &size2)
{
	int i;
		for (i=0;i<size; i++)
	{
		if ((p[i].Batting_Avg > 30) && (p[i].Bowling_Avg < 25))
		{
			strcpy(p2[size2].Name,p[i].Name);
			strcpy(p2[size2].Region,p[i].Region);
			p2[size2].Batting_Avg = p[i].Batting_Avg;
			p2[size2].Bowling_Avg = p[i].Bowling_Avg;
			size2++;			
		}
	}
		
	
}
void static sortList(player p2[5], int size2, player Batting[5], player Bowling[5],int &size3, int &size4)
{ int i,j ;

// sorting basec on batting 
player temp;
	for (i = 0; i<size2;i++)
	{
		for(j=i+1;j<size2;j++)
		{
			
		
		if (p2[i].Batting_Avg > p2[j].Batting_Avg)
		{
			/*strcpy(Batting[size3].Name,p2[i].Name);
			strcpy(Batting[].Region,p2[i].Region);
			Batting[k].Batting_Avg = p2[i].Batting_Avg;
			Batting[k].Bowling_Avg = p2[i].Bowling_Avg;
			k++;
			Batting[size3] = p2[i];
			size3++;*/
			temp =p2[i];
			p2[i]=p2[j];
			p2[j]=temp;			
		}
	}
}
for (i=0;i<size2;i++)
{
	Batting[i] = p2[i];
	 
}
size3 = size2;

//Bowling sort

	for (i = 0; i<size2;i++)
	{
		for(j=i+1;j<size2;j++)
		{
			
		
		if (p2[i].Bowling_Avg > p2[j].Bowling_Avg)
		{
			/*strcpy(Batting[].Name,p2[i].Name);
			strcpy(Batting[k].Region,p2[i].Region);
			Batting[k].Batting_Avg = p2[i].Batting_Avg;
			Batting[k].Bowling_Avg = p2[i].Bowling_Avg;
			k++;
			Bowling[size4] = p2[i];
			size4++;*/
			temp =p2[i];
			p2[i]=p2[j];
			p2[j]=temp;	
						
		}
	}
}
for (i=0;i<size2;i++)
{
	Bowling[i] = p2[i];
	 
}	
size4 = size2;
}
void static displayList(player Batting[5], int size3, player Bowling[5],int size4)
{
	int i;
	cout<<"\nBatting Player List"<<endl;
	for(i=0;i<size3;i++)
	{
		cout<<"\nName:"<<Batting[i].Name;
		cout<<"\nRegion:"<<Batting[i].Region;
		cout<<"\nBatting Average:"<<Batting[i].Batting_Avg;
		
	}
	
	cout<<"\nBowling Player List"<<endl;
	for(i=0;i<size4;i++)
	{
		cout<<"\nName:"<<Bowling[i].Name;
		cout<<"\nRegion:"<<Bowling[i].Region;
		cout<<"\nBowling Average:"<<Bowling[i].Bowling_Avg;
		
	}
}
};

void player::readData()
{
    cout<<"Enter the name of the player:"<<endl;
    cin>>Name;
    cout<<"Enter the region:"<<endl;
    cin>>Region;
    cout<<"Enter the batting average:"<<endl;
    cin>>Batting_Avg;
    cout<<"Enter the bowling average:"<<endl;
    cin>>Bowling_Avg;
}


int main()
{
	player p[5];
	player p2[5];
	player Batting[5];
	player Bowling[5];
	int size3=0;
	int size4=0;
	int size2=0;
	
	int i, size = 5;
	for (i = 0; i< size;i++)
	{
		p[i].readData();
		
	}
	player::generateList(p,size,p2,size2);
	player::sortList(p2,size2,Batting,Bowling, size3,size4);
	player::displayList(Batting, size3, Bowling , size4);
	
	
	
	return 0;
}
