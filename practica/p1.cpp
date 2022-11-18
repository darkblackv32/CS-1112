#include "p1.h"

ostream& operator<<(ostream& out, folder f)
{
    // out<<f.get_read()<<f.get_write()<<f.get_execute()<<" "<<f.get_name()<<endl;
    out<<f.list();
    return out;
}

ostream& operator<<(ostream& out, entry* f)
{
    out<<f->list();
    return out;
}

void pregunta1()
{
    string path, nombre;
    int aclec, acescr, acejc;
    int el;
 
    cin >> path >> nombre >> aclec >> acescr >>acejc ;
    folder root = folder(nombre, path, aclec, acescr, acejc);

    cin>>el;
    
    string pth, nom;
    int acle, acesc, acejecu;
    string cont;
    for(int i = 0; i < el; i++)
    {
        cin >> pth >> nom >> acle >> acesc >> acejecu;
        entry* new_entry = nullptr;
        
        nom = nombre + "/" + nom;
        if(pth == "D")
            new_entry = new folder(nom,pth,acle,acesc,acejecu);
        else if(pth == "F")
        {
            cin >> cont;
            new_entry = new file(nom,pth,acle,acesc,acejecu,cont);
        }
        root.add_entry(new_entry);
    }
    cout<<root;
}