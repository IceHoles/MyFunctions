#pragma once
#include <string>
#include <iostream>

class Musician {
protected:
	std::string fullName;
public:
	std::string getFullName();
	virtual std::string getSpec();
	void takePlace();
	virtual void rehearse();
	virtual void play();
	Musician(std::string fullName);
};


class Conductor :public Musician {
public:
	Conductor(std::string fullName) :Musician(fullName) {};
	std::string getSpec();
	void takePlace();
	void rehearse();
	void play();
};


class WindInstrument :public Musician{
protected:
	WindInstrument(std::string fullName) : Musician(fullName) {};
public:
	void rehearse();
	void play();
};


class OboePlayer :public WindInstrument {
public:
	OboePlayer(std::string fullName) : WindInstrument(fullName) {};
	std::string getSpec();
	void rehearse();
	void play();
};


class BassoonPlayer :public WindInstrument {
public:
	BassoonPlayer(std::string fullName) : WindInstrument(fullName) {};
	std::string getSpec();
	void rehearse();
	void play();
};


class Flutist :public WindInstrument {
public:
	Flutist(std::string fullName) : WindInstrument(fullName) {};
	std::string getSpec();
	void rehearse();
	void play();
};


class PercussionPlayer :public Musician {
protected:
	PercussionPlayer(std::string fullName) : Musician(fullName) {};
public:
	
}; 


class Orchestra {
	Musician** orch;
public:
	Orchestra(Musician** ahf) {
		this->orch = ahf;
	}
	void play() {
		for (int i = 0; i < 3; i++) {
			orch[i]->play();
			std::cout << std::endl;
		}
	}
	void rehearse() {
		for (int i = 0; i < 3; i++) {
			orch[i]->rehearse();
			std::cout << std::endl;
		}
	}
	void getSpec() {
		for (int i = 0; i < 3; i++) {
			std::cout << orch[i]->getSpec() << std::endl;
		}
	}
};

