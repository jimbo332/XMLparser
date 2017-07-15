#ifndef STORE_H
#define STORE_H

#include <QCoreApplication>
#include <QXmlStreamReader>
#include <QDebug>
#include <QXmlStreamReader>
#include <QFile>
#include <QDir>

class GlobalVarId;
class question;

class GlobalVarId{
public:

    int ID;
    QString text;


    void getID(int id);
    void gettxt(QString txt );
    int showID();
    QString showtxt();
    GlobalVarId();
    ~GlobalVarId();


}globalvar;


class question{
public:

    int ID;
    QString questext;
    QString anstext;

    static int quesNo;
    void getID(int id);
    void getquestxt(QString questxt );
    void getanstxt(QString anstxt );
    int showID();
    QString showquestxt();
    QString showanstxt();
    question();
    ~question();


}ques[2];
int question::quesNo = 0;

#endif // STORE_H
