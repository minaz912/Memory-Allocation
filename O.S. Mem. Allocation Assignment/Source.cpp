#include <iostream>
#include <vector>
#include <algorithm>
#include "Hole.h"
#include "Process.h"

using namespace std;

void firstFit();
void bestFit();
void displayInfo(int num);
int main();

vector<Process> processVector;
vector<Hole> HoleVector;
vector<Hole> temp;
int selection;

bool sortBySize(Hole x, Hole y)
{
	return x.getSize() < y.getSize();
}

bool sortByNum(Hole x, Hole y)
{
	return x.getNum() < y.getNum();
}

void selectAlgorithm()
{
	cout << "Now, select Allocation Method:\n" << endl;
	cout << "1. First Fit" << endl;
	cout << "2. Best Fit" << endl;
	cin >> selection;

	switch (selection)
	{
	case 1:
		system("CLS");
		firstFit();
		break;
	case 2:
		system("CLS");
		bestFit();
		break;
	default:
		cout << "Wrong Entry, Try Again" << endl;
		selectAlgorithm();
		break;
	}
}

void firstFit()
{
	temp = HoleVector;

	cout << "Initial State:" << endl;
	displayInfo(processVector.size());
	cout << endl;

	for (unsigned int i = 0; i < processVector.size(); i++)
	{
		for (unsigned int j = 0; j < temp.size(); j++)
		{
			if (temp[j].getSize() >= processVector[i].getSize())
			{
				int x = temp[j].getStartingAddress();
				int y = temp[j].getSize();
				processVector[i].setStartingAddress(x);
				temp[j].setStartingAddress(processVector[i].getSize() + x);
				temp[j].setSize(y - processVector[i].getSize());
				break;
			}
			
		}
		HoleVector = temp;
		displayInfo(i+1);
	}

	cout << "NOTE: Processes with Starting Address -1 are unallocated" << endl;
	
	cout << "\n1. Start Over" << endl;
	cout << "2. Exit" << endl;
	cin >> selection;
	switch (selection)
	{
	case 1:
		system("CLS");
		main();
		break;
	case 2:
		exit(EXIT_SUCCESS);
	default:
		break;
	}
}

void bestFit()
{
	temp = HoleVector;
	sort(temp.begin(), temp.end(), sortBySize);

	cout << "Initial State:" << endl;
	displayInfo(processVector.size());
	cout << endl;

	for (unsigned int i = 0; i < processVector.size(); i++)
	{
		for (unsigned int j = 0; j < temp.size(); j++)
		{
			if (temp[j].getSize() >= processVector[i].getSize())
			{
				int x = temp[j].getStartingAddress();
				int y = temp[j].getSize();
				processVector[i].setStartingAddress(x);
				temp[j].setStartingAddress(processVector[i].getSize() + x);
				temp[j].setSize(y - processVector[i].getSize());
				break;
			}
		}
		//sort(temp.begin(), temp.end(), sortByNum);
		//HoleVector = temp;
		cout << "After Process " << i + 1 << " Entry:" << endl;
		displayInfo(i + 1);
	}

	cout << "NOTE: Processes with Starting Address -1 are unallocated" << endl;

	cout << "\n1. Start Over" << endl;
	cout << "2. Exit" << endl;
	cin >> selection;
	switch (selection)
	{
	case 1:
		system("CLS");
		main();
		break;
	case 2:
		exit(EXIT_SUCCESS);
	default:
		break;
	}
}

//TODO: either modify display info to display line "Hole temp.getnum()" OR add swap code inside if statement (or for loop??)
// i think 2nd option is non-viable

// ^^ done

void displayInfo(int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << "Process " << i + 1 << " Starting Address " << processVector[i].getStartingAddress() << ", Size: " << 
			processVector[i].getSize() << endl;
	}
	/*for (int i = 0; i < processVector.size(); i++)
	{
		cout << "Hole " << i + 1 << " Starting Address " << HoleVector[i].getStartingAddress() << ", Size: " << 
			HoleVector[i].getSize() << endl;
	}*/

	//
	for (unsigned int i = 0; i < temp.size(); i++)
	{
		for (unsigned int j = 0; j < temp.size(); j++)
		{
			if (temp[j].getNum() == i)
			{
				cout << "Hole " << temp[j].getNum() + 1 << " Starting Address " << temp[j].getStartingAddress() << ", Size: " <<
					temp[j].getSize() << endl;
			}
		}	
	}
	//
	cout << endl;
}


int main()
{
	processVector.clear();
	HoleVector.clear();
	int n, size;

	int currentAddress = 0;
	cout << "Please enter Number of Holes:" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Hole y;
		cout << "Enter Hole " << i + 1 << " size:" << endl;
		cin >> size;
		y.setSize(size);
		y.setStartingAddress(currentAddress);
		y.setNum(i);
		currentAddress += size;
		HoleVector.push_back(y);
	}

	cout << endl;

	cout << "Please enter Number of Processes:" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Process x;
		cout << "Enter Process " << i + 1 << " size:" << endl;
		cin >> size;
		x.setSize(size);
		processVector.push_back(x);	
	}

	selectAlgorithm();

	return 0;
}

