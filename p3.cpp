#include <bits/stdc++.h>
using namespace std;

class employee_t {
private:
    string first_name, last_name;  
    char currency;
    double salary;
public:
    employee_t(){}
    employee_t(string fn, string ln, char curr, double s): first_name{fn}, last_name{ln}, currency{curr}, salary{s} {}
 
    string get_fullname(){return first_name + " " + last_name;}
    string get_first_name(){ return first_name; }
    string get_last_name(){ return last_name; }
    double get_salary(){ return salary; }
    char get_currency(){ return currency; }
};

int main()
{
    vector<employee_t*> employees;
    int N; cin >> N;
    string fn, ln;
    char c;
    double s;
    for (size_t i = 0; i < N; i++)
    {
        cin >> fn >> ln >> c >> s;
        employees.push_back(new employee_t(fn, ln , c, s));
    }
    
    for (employee_t* e : employees)
        cout << e->get_fullname() << " - " << e->get_salary() << ((e->get_currency() == 'S')?" Soles":" Dolares") << endl;
    
    vector<employee_t*>::iterator beg = employees.begin(), en = end(employees);
    while (beg != en)
    {
        cout << (*(*beg)).get_fullname() << " - " << (*beg)->get_salary() << (((*beg)->get_currency() == 'S')?" Soles":" Dolares") << endl;
        beg++;
    }   
}

/**
 * vars, __dict_
 * type hints
 * ternary operator
 * decorators
*/