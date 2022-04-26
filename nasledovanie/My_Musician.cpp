#include <string>
#include <iostream>
#include "My_Musician.h"


std::string Musician::getFullName() {
	return fullName;
}

std::string Musician::getSpec() 
{
	return "Musician";
}

void Musician::takePlace() 
{
	std::cout << getSpec() << " stood on their place";
}

void Musician::rehearse() 
{
}

void Musician::play()
{
	std::cout << getSpec() << " is playing";
}

Musician::Musician(std::string fullName)
{
	this->fullName = fullName;
}

std::string Conductor::getSpec()
{
	return "Conductor";
}

void Conductor::takePlace()
{
	std::cout << getSpec() << " stood on their place";
}

void Conductor::rehearse()
{
	std::cout << "Attention, please";
}

void Conductor::play()
{
	std::cout << getSpec() << " waving his wand";
}

void WindInstrument::rehearse()
{
	std::cout << getSpec() << " pretenting to be important";
}

void WindInstrument::play()
{
	std::cout << getSpec() << " blows";
}

std::string OboePlayer::getSpec()
{
	return "Oboist";
}

void OboePlayer::rehearse()
{
	std::cout << getSpec() << " takes oboe out and starts preparing";
}

void OboePlayer::play()
{
	std::cout << getSpec() << " is playing beutifully";
}

std::string BassoonPlayer::getSpec()
{
	return "Bassoon player";
}

void BassoonPlayer::rehearse()
{
	std::cout << getSpec() << " is deeply meditating";
}

void BassoonPlayer::play()
{
	std::cout << getSpec() << " is playing bassoon";
}

std::string Flutist::getSpec()
{
	return "Fleutist";
}

void Flutist::rehearse()
{
	std::cout << getSpec() << " uuuuuuuuu";
}

void Flutist::play()
{
	std::cout << getSpec() << " plays goofy ahh flute";
}

