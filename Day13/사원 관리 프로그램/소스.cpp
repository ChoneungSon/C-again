#include <iostream>
#include <string>

class Employee {
protected:
	std::string name, position;
	int age, rank;
public:
	Employee(std::string name, int age, std::string position, int rank)
		: name(name), age(age), position(position), rank(rank) {}
	Employee(const Employee& em) {
		name = em.name; age = em.age; position = em.position; rank = em.rank;
	}
	Employee() {}
	void print_info() {
		std::cout << name << " (" << position << ", " << age << ") ==> " << calcul_pay() << " 만원" << std::endl;
	}
	int calcul_pay() { return 200 + rank * 50; }
};
class Manager : public Employee {
	int year_of_service;
public:
	Manager(std::string name, int age, std::string position, int rank, int year_of_service)
		: Employee(name, age, position, rank), year_of_service(year_of_service) {}
	Manager(const Manager& em) : Employee(em.name, em.age, em.position, em.rank) {
		year_of_service = em.year_of_service;
	}
	Manager() : Employee() {}
	int calcul_pay() { return 200 + rank * 50 + 5 * year_of_service; }
	void print_info() {
		std::cout << name << " (" << position << ", " << age << ", "
			<< year_of_service << "년차) ==> " << calcul_pay() << " 만원" << std::endl;
	}
};
class Employee_list {
	Employee** emp_list;
	Manager** man_list;
	int curemp_num, curman_num, all_employee;
public:
	Employee_list(int all_employee) : all_employee(all_employee) {
		emp_list = new Employee * [all_employee];
		man_list = new Manager * [all_employee];
		curemp_num = curman_num = 0;
	}
	void add_employee(Employee* employee) {
		emp_list[curemp_num] = employee;
		curemp_num++;
	}
	void add_manager(Manager* manager) {
		man_list[curman_num] = manager;
		curman_num++;
	}
	int current_employee_num() { return curemp_num + curman_num; }
	void print_employee_info() {
		int total_pay = 0;
		for (int i = 0; i < curemp_num; i++) {
			emp_list[i]->print_info();
			total_pay += emp_list[i]->calcul_pay();
		}
		for (int i = 0; i < curman_num; i++) {
			man_list[i]->print_info();
			total_pay += man_list[i]->calcul_pay();
		}
		std::cout << "총 비용 : " << total_pay << " 만원" << std::endl;
	}
	~Employee_list() {
		for (int i = 0; i < curemp_num; i++) delete emp_list[i];
		for (int i = 0; i < curman_num; i++) delete man_list[i];
		delete[] emp_list; delete[] man_list;
	}
};
int main() {
	Employee_list emp_list(10);
	emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
	emp_list.add_employee(new Employee("하하", 34, "평사원", 1));
	emp_list.add_manager(new Manager("유재석", 41, "부장", 7, 12));
	emp_list.add_manager(new Manager("정준하", 43, "과장", 4, 15));
	emp_list.add_manager(new Manager("박명수", 43, "차장", 5, 13));
	emp_list.add_employee(new Employee("정형돈", 36, "대리", 2));
	emp_list.add_employee(new Employee("길", 36, "인턴", -2));
	emp_list.print_employee_info();
	return 0;
}