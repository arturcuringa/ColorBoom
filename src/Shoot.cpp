

#include "Shoot.h"


ShootPaint::ShootPaint(){
	S_head = new Shootnode;
	S_tail = S_head->next;
}
ShootPaint::~ShootPaint(){
	if(S_head->next==nullptr){
			delete S_head;
		}
		else{
			Shootnode *aux,*aux2;
			aux=S_head;
			while(aux!=S_tail){
				aux2=aux->next;
				delete aux;
				aux=aux2;
			}
			delete aux;
	}
}

void ShootPaint::ShootUpdate(sf::Time& deltaTime,sf::Clock &shoottime){

	if(S_head->next==nullptr){
		return;
	}

	else{

		sf::Time timer;
		timer = shoottime.getElapsedTime();
		Shootnode *aux;
		aux=S_head;

		while(aux!=S_tail){
			if(timer.asSeconds()>0.01){
				shoottime.restart();
				aux->next->ammo.setTextureRect(sf::IntRect(aux->next->ani,0,21,21));
				aux->next->ani = (aux->next->ani + 21) % (13*21);

			}
			
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

void ShootPaint::ShootDraw(sf::RenderWindow &myWindow){
		if(S_head->next==nullptr){
		return;
	}
	else{
		Shootnode *aux;
		aux=S_head;

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
	}
	else
	{
		S_tail->next= new Shootnode;
		S_tail=S_tail->next;
	}
		S_tail->ammo.setPosition(origin+sf::Vector2f(14.f * cos(tangente), 14.f * sin(tangente) ) );
		S_tail->ammo.setRadius(4);
		S_tail->ammo.setOutlineThickness(1);
		S_tail->ammo.setFillColor(cor);
		S_tail->ammo.setOutlineColor(cor);
		S_tail->ammo.setTexture(&Configuration::textures.get(Configuration::Textures::Shoots));
		S_tail->ammo.setTextureRect(sf::IntRect(S_tail->ani,0,21,21));

		S_tail->total = sf::Vector2f(0.f,0.f);
		S_tail->tang =tangente;
		S_tail->ani = 0;

	return;

}

