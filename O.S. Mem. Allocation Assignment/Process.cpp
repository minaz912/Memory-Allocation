#include "Process.h"


Process::Process()
{
	size = 0;
	startingAddress = -1;
}

void Process::setSize(unsigned int x)
{
	size = x;
}

int Process::getSize()
{
	return size;
}

void Process::setStartingAddress(int x)
{
	startingAddress = x;
}

int Process::getStartingAddress()
{
	return startingAddress;
}