
#include "store.h"
#include "xmlparser.h"
#include <QCoreApplication>
#include <QXmlStreamReader>
#include <QDebug>
#include <QXmlStreamReader>
#include <QFile>
#include <QDir>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString path = "F:\\Qt_Workspace\\files\\xmls\\test.xml";
    //QFile file(path);
    my_xml_parser parser;
    parser.xmlParser(path);
    return a.exec();
}


