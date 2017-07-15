#ifndef XMLPARSER_H
#define XMLPARSER_H

#include "store.h"
#include <QCoreApplication>
#include <QXmlStreamReader>
#include <QDebug>
#include <QXmlStreamReader>
#include <QFile>
#include <QDir>



class my_xml_parser;
const QString GlobalVar   = "GlobalVar";
const QString QuestionSet = "QuestionSet";
const QString Question    = "Question";
const QString Text        = "Text";
const QString Answer      = "Answer";


class my_xml_parser{
public:
    void xmlParser(QString path);
    void readquestion(QXmlStreamReader xml);
};

#endif // XMLPARSER_H
