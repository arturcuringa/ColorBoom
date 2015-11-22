#ifndef _PILHA_
#define _PILHA_

#include <iostream>
#include <functional>


template <typename Data>
class PilhaVetor{
	
private:
	Data * stack;
	int _maxSize;
	int miLenght;
public:
	PilhaVetor(int _MAX = 5);
	~PilhaVetor();
	bool push(Data & _newvalue);
	bool pop(Data & _retorno);
	Data top(); 
	bool empty();
	void clear();

};	


#include "pilha.inl"

#endif