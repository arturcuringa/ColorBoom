
#include "pilha.h"
	
	template <typename Data>
	bool PilhaVetor<Data>::empty(){ //pergunta se está vazio
		if (miLenght == 0)
		{
			return true;
		}
		return false;
	}

	template <typename Data>
	PilhaVetor<Data>::PilhaVetor( int _MAX){ // inicia e determina tamanho da pilha

		if (_MAX < 0)
		{
			throw std::invalid_argument( "[PilhaVetor()]: Tamanho de Pilha invalido!" );
		}
		_maxSize = _MAX;
		stack = new Data [_MAX];

	}

	template <typename Data>
	PilhaVetor<Data>::~PilhaVetor(){ //destruidor
		delete [] stack;
	}


	template<typename Data>
	bool PilhaVetor<Data>::push(Data & _newvalue){//adiciona novo valor a pilha

		if (miLenght == _maxSize)
		{
			throw std::invalid_argument("[PilhaVetor]: OVerflow!");
		}

		if (miLenght == 0)
		{
			stack[0] = _newvalue;
			miLenght++;
			return true;
		}
		miLenght++;
		stack[miLenght-1] = _newvalue;
		

		return true;


	}
	

	template<typename Data>
	bool PilhaVetor<Data>::pop(Data & _retorno){//retira ultimo valor da pilha

		if (miLenght == 0)
		{
			throw std::invalid_argument("[PilhaVetor]: Pilha Vazia 'Underflow'! ");
		}

		_retorno = stack[miLenght-1];
		miLenght--; 

		return true;
	}	

	template <typename Data>
	Data PilhaVetor<Data>::top(){//retorna ultimo valor da pilha

		if (miLenght == 0)
		{
			throw std::invalid_argument("[PilhaVetor]: Pilha Vazia 'Underflow'! ");
		}

		return stack[miLenght-1];

	}
	template <typename Data>
	void PilhaVetor<Data>::clear(){
		Data destroy;
		while(miLenght != 0){
			pop(destroy);
		}

	}

