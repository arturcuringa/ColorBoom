#include "Shoot.h"

void ShootPaint::ShootUpdate(){
	if(head->next==nullptr){
		return;
	}
	else{
		Shootnode *aux;
		aux=head;
		sf::Vector2f total;
		while(aux->next!=tail){
			
			aux->next->ammo.move(5.f * cos(aux->next->tang), 5.f * sin(aux->next->tang) );
			
			total =(sf::Vector2f(5.f * cos(aux->next->tang), 5.f * sin(aux->next->tang) ) - aux->next->orig );
			
			if( (total.x<-100 || total.x>100)  &&  (total.y<-100 || total.y>100)){
				ShootRemove(aux, aux->next);
			}



		}

	}

}
void ShootPaint::ShootRemove(Shootnode *prev,Shootnode* rem){

	prev->next=rem->next;
	delete rem;
	return;

}
void ShootPaint::ShootAdd(double tangente,sf::Vector2f origin,sf::Color cor){

	if(head->next==nullptr)
	{
		head->next= new Shootnode;
		tail=head->next;
		head->next->ammo.setPosition(origin);
		head->next->ammo.setRadius(4);
		head->next->ammo.setFillColor(cor);
		head->next->orig = origin;
		head->next->tang =tangente;

	}
	else
	{
		tail->next= new Shootnode;
		tail=tail->next;
		tail->ammo.setPosition(origin);
		tail->ammo.setRadius(4);
		tail->ammo.setFillColor(cor);
		tail->orig = origin;
		tail->tang =tangente;

	}
	return;

}

