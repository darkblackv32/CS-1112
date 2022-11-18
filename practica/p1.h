#pragma once
#include <bits/stdc++.h>
using namespace std;

class entry{
protected:
    string name;
    string path;
    int read;
    int write;
    int execute;
    
    // friend ostream operator << (ostream& os, vector<entry*> entries);
public:
    entry(){}
    entry(string nom, string pat, int ro, int wr, int x) : name{nom}, path{pat}, read{ro}, write{wr}, execute{x}{}
    
    char get_write(){
        if (write == 1)
            return 'W';
        return '-';
    }
    char get_read(){
        if (read == 1)
            return 'R';
        return '-';
    }
    char get_execute(){
        if (execute == 1)
            return 'X';
        return '-';
    }

    string get_name(){ return name; }
    virtual int get_size() = 0;
    virtual string list() = 0;
};


class folder : public entry
{
private:
    vector<entry*>entries;
    // friend ostream& operator <<(ostream& out, folder f);
public:
    folder(string n2, string p2, int r2, int w2, int x2) : entry(n2,p2,r2,w2,x2){}
    ~folder(){}

    void add_entry(entry* e) { entries.emplace_back(e); }
    string list()
    {
        string ls;
        ls += this->get_read();
        ls += this->get_write();
        ls += this->get_execute();
        ls += " " + this->name + "\n";

        for (entry* e : entries)
            ls += e->list();

        return ls;
    }
    int get_size() override { return 0; }
};

class file : public entry
{
private:
    string content;
public:
    file(string n, string p, int r, int w, int x1, string con) : entry(n, p, r, w, x1), content{con}{}
    ~file(){}

    string list() 
    {
        string ls;
        ls += this->get_read();
        ls += this->get_write();
        ls += this->get_execute();
        ls += " " + this->name + " " + this->content + "\n";
        return ls;
    } 
    int get_size() override { return content.size(); }
       
};

void pregunta1();