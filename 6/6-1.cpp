#include <iostream>
#include <string>

class Employee
{
    private:
        std::string _name;
        int _age;

        std::string _pos; // 직책(이름)
        int _rank;       // 직책 순위(클수록 높음)

    public:
        Employee(std::string name, int age, std::string pos, int rank)
        : _name(name), _age(age), _pos(pos), _rank(rank) {}

        // 복사 생성자
        Employee(const Employee& employee)
        {
            _name = employee._name;
            _age  = employee._age;
            _pos  = employee._pos;
            _rank = employee._rank;
        }

        // 디폴트 생성자
        Employee() {}

        void print_info()
        {
            std::cout << _name << " (" << _pos << " , " << _age << ") ==> "
            << calcul_pay() << "만원" <<std::endl;
        }
        int calcul_pay()
        {
            return (200+_rank*50);
        }
};

class EmployeeList
{
    private:
        int alloc_emp;
        int curr_emp;
        Employee** emp_list;
    public:
        EmployeeList(int alloc_emp) : alloc_emp(alloc_emp)
        {
            emp_list = new Employee*[alloc_emp];
            curr_emp = 0;
        }

        void add_emp(Employee* emp)
        {
             
            emp_list[curr_emp] = emp;
            curr_emp++;
        }

        int curr_emp_num() { return curr_emp; }

        void print_emp_info()
        {
            int total_pay = 0;
            for (int i= 0; i <  curr_emp; i++)
            {
                emp_list[i]->print_info();
                total_pay += emp_list[i]->calcul_pay();
            }
            std::cout << "total pay : " << total_pay << "만원 " << std::endl;
        }

        ~EmployeeList()
        {
            for (int i=0; i < curr_emp; i++)
            {
                delete emp_list[i];
            }
            delete[] emp_list;
        }
};

int main()
{
    Employee s1("junyopar", 123, "high", 123);
    Employee s2("elonmusk", 122, "mid", 122);

    s1.print_info();
    s2.print_info();

    EmployeeList emp_list(10);
    emp_list.add_emp(new Employee("노홍철", 34, "평사원", 1));
    emp_list.add_emp(new Employee("하하", 34, "평사원", 1));
    emp_list.add_emp(new Employee("유재석", 41, "부장", 7));
    emp_list.add_emp(new Employee("정준하", 43, "과장", 4));
    emp_list.add_emp(new Employee("박명수", 43, "차장", 5));
    emp_list.add_emp(new Employee("정형돈", 36, "대리", 2));
    emp_list.add_emp(new Employee("길", 36, "인턴", -2));
    emp_list.print_emp_info();
    while (1)
    ;
}