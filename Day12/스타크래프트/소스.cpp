// ���� �����
#include <string.h>
#include <iostream>

class Marine {
  public:
	static int marine_num;
	int hp, coord_x, coord_y, damage;
	bool is_dead;
	// char name[50];
	
	Marine(int x, int y); // ������ �����ε�
	// Marine(int x, int y, const char* name);
	// Marine(int x, int y, const char* name);
	~Marine(); // �Ҹ���
	int attack(); // �������� �����Ѵ�.
	void be_attacked(int damage_earn); // �Դ� ������
	void move(int x, int y); // ���ο� ��ġ

	void show_status(); // ���¸� �����ش�.
};
Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50), damage(5), is_dead(false) { marine_num++; }
/* Marine::Marine(int x, int y, const char* marine_name) {
	coord_x = x; coord_y = y;
	strcpy_s(name, sizeof(name), marine_name);

	hp = 50; damage = 5; is_dead = false;
	marine_num++;
} */
Marine::~Marine() { marine_num--; }
int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0) { is_dead = true; }
}
void Marine::move(int x, int y) {
	coord_x = x; coord_y = y;
}
void Marine::show_status() {
	std::cout << std::endl << "Hp : " << hp << std::endl;
	std::cout << "Location : (" << coord_x << ", " << coord_y << ")" << std::endl << std::endl;
}
int Marine::marine_num = 0;

int main() {
	Marine* marines[100];

	marines[0] = new Marine(2, 3);
	std::cout << "��ü ���� �� : " << Marine::marine_num << std::endl;
	marines[1] = new Marine(3, 5);
	std::cout << "��ü ���� �� : " << Marine::marine_num << std::endl;

	marines[0]->show_status();
	marines[1]->show_status();

	std::cout << std::endl << "���� 1�� ���� 2�� ����! " << std::endl;

	marines[1]->be_attacked(marines[0]->attack());

	marines[0]->show_status();
	marines[1]->show_status();

	return 0;
}