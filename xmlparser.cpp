#include "xmlparser.h"
#include "store.h"




void my_xml_parser::xmlParser(QString path){
//create a new file object with the XML file path.
QFile* file = new QFile(path);
//test to see if the file is readable and that it contains text.
if(!file->open(QIODevice::ReadOnly | QIODevice::Text)){
//if you wish to perform some action if the file is inaccessible,//do so here.
    qDebug()<<"Unable to open the file maybe file "<<path<<" is not present or maybe corrupted ";
return;
}
//Create the XML stream reader.
QXmlStreamReader xml(file);
//we’re going to loop over the entire xml document
//using QXmlStreamReader’s atEnd() method, in addition to
//its hasError() method
while(!xml.atEnd() && !xml.hasError()){
//read the next piece of data into the reader.
//this will move the reader “over” or “onto” the next
//valid element, including any attributes it holds as
//well as its value. The returned object is a status object
//which can be tested for EOF, the begging of the file, etc.
QXmlStreamReader::TokenType token = xml.readNext();
//test to see if the token indicates that we’re at the beginning
//of the document. Any calls to the reader’s current data will
//give you the xml version number information.
if(token == QXmlStreamReader::StartDocument){
//we don’t want any of this data, it isn’t any element
//we need.
continue;
}
//what we’re looking for is that start of a valid element
if(token == QXmlStreamReader::StartElement) {
//any global elements or elements of quiz that you wish
//to read in come next
if(xml.name() == GlobalVar){
//here we’ve got globalVar, so I’m going to
//save the ID attribute, and save its text to the
//globalVar
globalvar.ID =
xml.attributes().value("ID").toString().toInt();
//So your XML reader was looking at the GlobalVar
//element, we need to push it forward (such that its
//looking at the value field) so that it reads the
//text of this current element.
xml.readNext();
//now save the xml.text(), this will be the value in
//the globalvar element (<GlobalVar>HERE</GlobalVar>)
globalvar.text = xml.text().toString();
}
//Questionset itself doesn’t do anything for us. We need its//children, so just skip this element
if(xml.name() == QuestionSet){
continue;
}
//This is a question, in the name of good software
//engineering I’m deligating this off to another
//function called “parseQuestion”.
if(xml.name() == Question) {
this->readquestion(xml);
}
}//startElement
}//while
}//function


// method to read question

void my_xml_parser::readquestion(QXmlStreamReader xml){
//check to ensure that we were called in the appropriate spot!
if(xml.tokenType() != QXmlStreamReader::StartElement
&& xml.name() != Question){
qDebug() << "Called XML parseQuestionElement "
<< "without a question Element in the XML stream!";
return;
}

//read the attribute fields in first: You know that currently the
//stream is pointing at the Question element (as was checked by
//the previous if condition), so you can read in the attribute
//fields immediately.
ques[question::quesNo].ID = xml.attributes().value("ID").toString().toInt();
//but now we need to get data from Question's children...
xml.readNext();
//and now the code looks very similar to that of the caller!
//the way to read the while condition is as follows:
//while it isn’t the case that we're at the end of an element and
//(to protect against nested questions) we're not looking at a
//new question element
while(!(xml.tokenType() == QXmlStreamReader::EndElement
&& xml.name() == Question)){
//at the start of an element, otherwise ignore and
//keep reading.
if(xml.tokenType() == QXmlStreamReader::StartElement){
//If the element is a text element, save it
if(xml.name() == Text){
xml.readNext();
ques[question::quesNo].questext =
xml.text().toString();
}
//otherwise if its an answer element, save itif(xml.name() == "Answer"){
xml.readNext();
ques[question::quesNo].anstext =
xml.text().toString();
}
//otherwise we don’t know what it is, so do nothing,
//and read the next thing!
//}
//we’re currently looking at some element feld,
//so read the next element header!
xml.readNext();
}//while
question::quesNo++;
//done!
return;
}//readQuestion: end of question reader function

