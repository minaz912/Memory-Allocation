#pragma once
class Process
{
private:
	int size;
	int startingAddress;
public:
	Process();
	void setSize(unsigned int x);
	int getSize();
	void setStartingAddress(int x);
	int getStartingAddress();
};

