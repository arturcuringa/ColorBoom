
#include "Ships.h"


ShipsPaint::ShipsPaint(){
	S_head = new Shipnode;
	S_tail = new Shipnode;	
	

	S_head->next = S_tail;
	S_head->prev = nullptr;

	S_tail->prev = S_head;
	S_tail->next = nullptr;
	
}
ShipsPaint::~ShipsPaint(){
	if(S_head->next==S_tail){
			delete S_head;
			delete S_tail;
		}
		else{
			Shipnode *aux,*aux2;
			aux=S_head;
			while(aux!=S_tail){
				aux2=aux->next;
				delete aux;
				aux=aux2;
			}
			delete S_head;
			delete S_tail;

		}
}

void ShipsPaint::ShipUpdate(sf::Time& deltaTime){
		

	if(S_head->next==S_tail){
		return;
	}
	else{
		Shipnode *aux;
		aux=S_head;

		while(aux!=S_tail){
			
			std::cout<<"Ship!";			
		}

	}
	
}

void ShipsPaint::ShipDraw(sf::RenderWindow &myWindow){
		if(S_head->next==S_tail){
		return;
	}
	else{

		Shipnode *aux;
		aux=S_head;

		while(aux!=S_tail){
			
			myWindow.draw(aux->next->ammo);
			aux=aux->next;

		}

	}
}

void ShipsPaint::ShipRemove(Shipnode *prev,Shipnode* rem){

	prev->next=rem->next;
	rem->next->prev = rem->prev;
	delete rem;
	return;

}

void ShipsPaint::ShipAdd(sf::Vector2f origin,sf::Color cor){

	if(S_head->next==nullptr)
	{
		Shipnode* aux = new Shipnode;

		S_head->next= aux;
		S_tail->prev= aux;
		
		aux->next = S_tail;
		aux->prev = S_head;

		aux->body.setPosition(origin);
	

	}
	else
	{
		S_tail->next= new Shipnode;
		S_tail=S_tail->next;
		S_tail->ammo.setPosition(origin+sf::Vector2f(15.f * cos(tangente), 15.f * sin(tangente) ) );
		S_tail->ammo.setRadius(4);
		S_tail->ammo.setFillColor(cor);
		S_tail->total = sf::Vector2f(0.f,0.f);
		S_tail->tang =tangente;

	}
	return;

}

