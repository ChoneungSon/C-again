// 포토캐논
#include <string.h>
#include <iostream>

class Photon_Cannon {
  public :
	int hp, shield, coord_x, coord_y, damage;
	Photon_Cannon(int x, int y);
	Photon_Cannon(const Photon_Cannon& pc);
	~Photon_Cannon();

	void show_status();
};
Photon_Cannon::Photon_Cannon(int x, int y) {
	coord_x = x; coord_y = y;
	hp = shield = 100; damage = 20;
}
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
	hp = pc.hp; shield = pc.shield;
	coord_x = pc.coord_x; coord_y = pc.coord_y;
	damage = pc.damage;
}
void Photon_Cannon::show_status() {
	std::cout << "Photon Cannon " << std::endl;
	std::cout << "Location : (" << coord_x << ", " << coord_y << ")" << std::endl;
	std::cout << "HP : " << hp << std::endl;
}

int main() {
	Photon_Cannon* cannons[100];

	cannons[0] = new Photon_Cannon(3, 3);
	cannons[1] = new Photon_Cannon(*cannons[0]); 

	cannons[0]->show_status();
	cannons[1]->show_status();

	return 0;
}