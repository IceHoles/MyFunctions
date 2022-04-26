#include <string>
#include <vector>
#include<iostream>
#include"My_Musician.h"

int main(){
	//
	//Conductor conductor("asgijho");
	//Flutist flutist2("sfigsjih");
	//Musician* m = &flutist;
	//std::vector<Musician*>arr = { &flutist,&flutist2,&conductor };
																	 
	Musician** Orchesta = new Musician*[3];	

	//for (int i = 0; i < 3; i++) {
	//	std::cout << "Input Musician";
	//	Musician* m 
	//
	//}
	Flutist flutist("Ivan Petrovich");
	Orchesta[0] = &flutist;
	Flutist flutist2("Sergey Petrovich");
	Orchesta[1] = &flutist2;
	Conductor conductor("Nikolay Krotov");
	Orchesta[2] = &conductor;

	Orchestra Nizhegorod(Orchesta);	  

	Nizhegorod.rehearse(); 
	Nizhegorod.play();
	
	std::cout << "Orchestra includes " << std::endl;
	Nizhegorod.getSpec();

	std::cout << "asda";


	delete[] Orchesta;


	return 0 ;
}