

#include "Shoot.h"


ShootPaint::ShootPaint(){
	S_head = new Shootnode;
	S_tail = S_head->next;
}
ShootPaint::~ShootPaint(){
	delete S_head;
}


void ShootPaint::ShootUpdate(sf::Time deltaTime){
	if(S_head->next==nullptr){
		return;
	}
	else{
		Shootnode *aux;
		aux=S_head;

		while(aux!=S_tail){
			
			aux->next->ammo.move(100.f * cos(aux->next->tang)*deltaTime.asSeconds(), 100.f * sin(aux->next->tang)*deltaTime.asSeconds());
			
			aux->next->total =(sf::Vector2f(5.f * cos(aux->next->tang), 5.f * sin(aux->next->tang) ) + aux->next->total );
			
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

}

void ShootPaint::ShootDraw(sf::RenderWindow &myWindow){
		if(S_head->next==nullptr){
		return;
	}
	else{
		Shootnode *aux;
		aux=S_head;
		sf::Vector2f total;
		while(aux!=S_tail){
			
			myWindow.draw(aux->next->ammo);
			aux=aux->next;

		}

	}
}

void ShootPaint::ShootRemove(Shootnode *prev,Shootnode* rem){

	prev->next=rem->next;
	delete rem;
	return;

}

void ShootPaint::ShootAdd(double tangente,sf::Vector2f origin,sf::Color cor){

	if(S_head->next==nullptr)
	{
		S_head->next= new Shootnode;
		S_tail=S_head->next;
		S_tail->ammo.setPosition(origin+sf::Vector2f(20.f * cos(tangente), 20.f * sin(tangente) ) );
		S_head->next->ammo.setRadius(4);
		S_head->next->ammo.setFillColor(cor);
		S_head->next->total = sf::Vector2f(0.f,0.f);
		S_head->next->tang =tangente;

	}
	else
	{
		S_tail->next= new Shootnode;
		S_tail=S_tail->next;
		S_tail->ammo.setPosition(origin+sf::Vector2f(20.f * cos(tangente), 20.f * sin(tangente) ) );
		S_tail->ammo.setRadius(4);
		S_tail->ammo.setFillColor(cor);
		S_tail->total = sf::Vector2f(0.f,0.f);
		S_tail->tang =tangente;

	}
	return;

}

