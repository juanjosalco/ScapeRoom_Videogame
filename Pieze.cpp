#include <iostream>
#include "Pieze.h"

Piece::Piece()
{
}

Piece::Piece(std::string name_,std::string dest_,int id_,bool use_ ):Item(name_,dest_)
{
    id=id_;
    use=use_;
}
std::string Piece::getDescripcionLarga(){
    return Item::getDescripcionLarga()+"\n"+"Usos"+std::to_string(use);
}
