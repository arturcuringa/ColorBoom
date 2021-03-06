
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
			while(aux!=nullptr){
				aux2=aux->next;
				delete aux;
				aux=aux2;
			}

			
		}
}

void ShipsPaint::ShipsUpdate(sf::Time& deltaTime, sf::Sprite target, bool slow){
		

	if(S_head->next==S_tail){
		return;
	}
	else{
		Shipnode *aux;
		aux=S_head->next;

		while(aux!=S_tail){
			
			if (sqrt(pow(target.getPosition().x+10 - aux->body.getPosition().x, 2) + pow(target.getPosition().y+10 - aux->body.getPosition().y, 2) ) <=	 600.f )
			{
				double tang1 =  atan2(target.getPosition().y+10 - aux->body.getPosition().y  ,  target.getPosition().x+10 - aux->body.getPosition().x);
				//double tang2 = atan2(aux->body.getPosition().x, aux->body.getPosition().y );
				sf::Vector2f rot;
				if(slow){
					rot= sf::Vector2f(10.f * cos(tang1), 10.f * sin(tang1) );
				}
				else{
					rot =sf::Vector2f(150.f * cos(tang1), 150.f * sin(tang1) );
				}
					aux->body.setOrigin(sf::Vector2f(11,0));
					aux->body.setRotation( ( tang1) * 180/3.14 - 90 );
					
					aux->body.move(rot*deltaTime.asSeconds());
				
				//sf::Vector2f rot(10.f * cos(tang), 10.f * sin(tang) );
				
				
			}


			aux = aux->next;			
		}

	}
	
}

void ShipsPaint::ShipsDraw(sf::RenderWindow &myWindow){
		if(S_head->next==S_tail){
		return;
	}
	else{

		Shipnode *aux;
		aux=S_head;

		while(aux->next!=S_tail){
			
			myWindow.draw(aux->next->body);
			aux=aux->next;

		}

	}
}

void ShipsPaint::ShipsRemove(Shipnode* rem){

	rem->next->prev = rem->prev;
	rem->prev->next = rem->next;
	delete rem;
	return;

}

void ShipsPaint::ShipsAdd(sf::Vector2f origin,sf::Color cor){

	Shipnode* aux = new Shipnode;

	S_head->next->prev = aux;
	aux->next = S_head->next;
	
	S_head->next= aux;
	aux->prev = S_head;

	aux->body.setPosition(origin);
	//aux->body.setScale(2);
	aux->body.setOrigin(sf::Vector2f(11.f, 0));
	//aux->body.rotate( static_cast<int>(origin.x + origin.y) % 360 );
	aux->body.setColor(cor);


	return;

}

bool ShipsPaint::empty()
{

	if (S_head->next == S_tail)
	{
		return true;
	}
	return false;
}
void ShipsPaint::clear()
{
	if(S_head->next==S_tail){
			return;
		}
		else{
			Shipnode *aux,*aux2;
			aux=S_head->next;
			while(aux!=S_tail){
				aux2=aux->next;
				ShipsRemove(aux);
				aux=aux2;
			}

			
		}
}
