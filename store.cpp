#include "store.h"

// function definations of GlobalVarId class

GlobalVarId::GlobalVarId(){
    qDebug()<<"creating global";
}

GlobalVarId::~GlobalVarId(){
    qDebug()<<"distroying global";
}

void GlobalVarId ::getID(int id){
    ID = id;
}

void GlobalVarId ::gettxt(QString txt){
    text = txt;
}

int GlobalVarId::showID(){
    return ID;
}

QString GlobalVarId::showtxt(){
    return text;
}

// function definations of question class

void question::getID(int id){
    ID = id;
}
void question::getquestxt(QString questxt){
    questext = questxt;
}

void question::getanstxt(QString anstxt){
    anstext = anstxt;
}

int question::showID(){
    return ID;
}

QString question::showquestxt(){
    return questext;
}

QString question::showanstxt(){
    return anstext;
}

question::question(){
    qDebug()<<"creating ";
}

question::~question(){
    qDebug()<<"distroying ";
}

