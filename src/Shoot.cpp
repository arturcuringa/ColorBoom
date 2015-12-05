
#include "Shoot.h"


ShootPaint::ShootPaint(){
	S_head = new Shootnode;
	S_tail = new Shootnode;	
	

	S_head->next = S_tail;
	S_head->prev = nullptr;

	S_tail->prev = S_head;
	S_tail->next = nullptr;
	
}

ShootPaint::~ShootPaint(){
	if(S_head->next==S_tail){
			delete S_head;
			delete S_tail;
		}
		else{
			Shootnode *aux,*aux2;
			aux=S_head;
			while(aux!=nullptr){
				aux2=aux->next;
				delete aux;
				aux=aux2;
			}

			
		}
}

void ShootPaint::ShootUpdate(sf::Time& deltaTime,sf::Clock &shoottime){
		sf::Time timer;
		timer = shoottime.getElapsedTime();

	if(S_head->next==S_tail){
		return;
	}
	else{
		Shootnode *aux, *aux2;
		aux=S_head->next;

		while(aux!=S_tail){
			
			if(timer.asSeconds()>0.01){
				shoottime.restart();
				aux->ammo.setTextureRect(sf::IntRect(aux->ani,0,21,21));
				aux->ani = (aux->ani + 21) % (13*21);

			}
			
			aux->ammo.move(500.f * cos(aux->tang)*deltaTime.asSeconds(), 500.f * sin(aux->tang)*deltaTime.asSeconds());
			
			aux->total =(sf::Vector2f(500.f * cos(aux->tang)*deltaTime.asSeconds(), 500.f * sin(aux->tang)*deltaTime.asSeconds()) + aux->total );
			
			if( (aux->total.x * aux->total.x + aux->total.y * aux->total.y >400*400) )
			{	
				aux2 = aux->next;
				ShootRemove(aux);
				aux = aux2;
			}
			else
			{
				aux=aux->next;
			}			
		}

	}
	
}

void ShootPaint::ShootDraw(sf::RenderWindow &myWindow){
		if(S_head->next==S_tail){
		return;
	}
	else{

		Shootnode *aux;
		aux=S_head;

		while(aux->next!=S_tail){
			
			myWindow.draw(aux->next->ammo);
			aux=aux->next;

		}

	}
}

void ShootPaint::ShootRemove(Shootnode* rem){

	rem->next->prev = rem->prev;
	rem->prev->next = rem->next;
	delete rem;
	return;

}

void ShootPaint::ShootAdd(double tangente,sf::Vector2f origin,sf::Color cor){

	Shootnode* aux = new Shootnode;

	S_head->next->prev = aux;
	aux->next = S_head->next;
	
	S_head->next= aux;
	aux->prev = S_head;

		aux->ammo.setPosition(origin+sf::Vector2f(21.f * cos(tangente), 21.f * sin(tangente) ) );
		aux->ammo.setRadius(11);
		aux->ammo.setOutlineThickness(1);
		aux->ammo.setFillColor(cor);
		aux->ammo.setOutlineColor(cor);
		aux->ammo.setTexture(&Configuration::textures.get(Configuration::Textures::Shoots));
		aux->ammo.setTextureRect(sf::IntRect(aux->ani,0,21,21));

		aux->total = sf::Vector2f(0.f,0.f);
		aux->tang =tangente;
		aux->ani = 0;

	return;

}

bool ShootPaint::empty()
{

	if (S_head->next == S_tail)
	{
		return true;
	}
	return false;
}

void ShootPaint::clear()
{

	if(S_head->next==S_tail){
			return;
		}
		else{
			Shootnode *aux,*aux2;
			aux=S_head->next;
			while(aux!=S_tail){
				aux2=aux->next;
				ShootRemove(aux);
				aux=aux2;
			}

			
		}
}