#pragma once
class Hole
{
private:
	int size;
	int startingAddress;
	int num;
public:
	Hole();
	void setSize(unsigned int x);
	int getSize();
	void setStartingAddress(int x);
	int getStartingAddress();
	void setNum(unsigned int x);
	unsigned int getNum();
};

