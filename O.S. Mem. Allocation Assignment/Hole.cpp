#include "Hole.h"


Hole::Hole()
{
	size = 0;
	startingAddress = 0;
}

void Hole::setSize(unsigned int x)
{
	size = x;
}

int Hole::getSize()
{
	return size;
}

void Hole::setStartingAddress(int x)
{
	startingAddress = x;
}

int Hole::getStartingAddress()
{
	return startingAddress;
}

void Hole::setNum(unsigned int x)
{
	num = x;
}

unsigned int Hole::getNum()
{
	return num;
}