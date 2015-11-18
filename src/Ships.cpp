
#include "Ships.h"


ShipsPaint::ShipsPaint(){
	S_head = new Shipsnode;
	S_tail = new Shipsnode;	
	

	S_head->next = S_tail;
	S_head->prev = nullptr;

	S_tail->prev = S_head;
	S_tail->next = nullptr;
	
}
ShipsPaint::~ShipsPaint(){
	if(S_head->next==nullptr){
			delete S_head;
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
		

	if(S_head->next==nullptr){
		return;
	}
	else{
		Shipnode *aux;
		aux=S_head;

		while(aux!=S_tail){
			
			aux->next->ammo.move(500.f * cos(aux->next->tang)*deltaTime.asSeconds(), 500.f * sin(aux->next->tang)*deltaTime.asSeconds());
			
			aux->next->total =(sf::Vector2f(500.f * cos(aux->next->tang)*deltaTime.asSeconds(), 500.f * sin(aux->next->tang)*deltaTime.asSeconds()) + aux->next->total );
			
			if( (aux->next->total.x * aux->next->total.x + aux->next->total.y * aux->next->total.y >400*400) )
			{	
				if(aux->next==S_tail)
				{
					S_tail=aux;
				}
				ShootRemove(aux, aux->next);
			}
			else
			{
				aux=aux->next;
			}


		}

	}
	//deltaTime
}

void ShipsPaint::ShipDraw(sf::RenderWindow &myWindow){
		if(S_head->next==nullptr){
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
	delete rem;
	return;

}

void ShipsPaint::ShipAdd(double tangente,sf::Vector2f origin,sf::Color cor){

	if(S_head->next==nullptr)
	{
		S_head->next= new Shipnode;
		S_tail=S_head->next;
		S_tail->ammo.setPosition(origin+sf::Vector2f(15.f * cos(tangente),15.f * sin(tangente) ) );
		S_head->next->ammo.setRadius(4);
		S_head->next->ammo.setFillColor(cor);
		S_head->next->total = sf::Vector2f(0.f,0.f);
		S_head->next->tang =tangente;

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

