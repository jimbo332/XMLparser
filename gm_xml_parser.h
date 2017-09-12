#ifndef GM_XML_PARSER_H
#define GM_XML_PARSER_H

#include <QCoreApplication>
#include <QXmlStreamReader>
#include <QDebug>
#include <QXmlStreamReader>
#include <QFile>
#include <QDir>
#include "store_xml_data.h"
#include "xml_elemets_list.h"



class my_xml_parser{
public:
    bool xmlParser(QString path);
    void readxml(QXmlStreamReader *xml);
    void _display_(QXmlStreamReader *xml );
    //void _size_(QXmlStreamReader *xml, T *t);
    void _view_(QXmlStreamReader *xml);
    void _screen_(QXmlStreamReader *xml);
    void _includeiew_(QXmlStreamReader *xml);
    void _imagewidget_(QXmlStreamReader *xml);
    //void _location_(QXmlStreamReader *xml);
    //void _taborder_(QXmlStreamReader *xml);
    void _inputwidgetmapping_(QXmlStreamReader *xml);
    void _selectorstate_(QXmlStreamReader *xml);
    void _behaviorstatetype_(QXmlStreamReader *xml);


    /*************************common functions starts*********************************/
    template<typename T>
    void _size_(QXmlStreamReader *xml , T *t){
        if(xml->tokenType() != QXmlStreamReader::StartElement && xml->name() != my_Size){
            qDebug()<<"\n" << "Called XML parseSizeElement " << "without a Size Element in the XML stream!";
            return;
        }
        xml->readNextStartElement();
            if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_SizeW){
                xml->readNext();
                t->size.SizeW = xml->text().toString().toInt();
                }
            xml->readNextStartElement();
            xml->readNextStartElement();
            if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_SizeH){
                xml->readNext();
                t->size.SizeH = xml->text().toString().toInt();
                }
    //done reading size!
        return;
    }//_size_ end

    template<typename T1>
    void _location_(QXmlStreamReader *xml , T1 *t){
        if(xml->tokenType() != QXmlStreamReader::StartElement && xml->name() != my_Location){
            qDebug()<<"\n" << "Called XML parseimagewidgetElement " << "without a imagewidget Element in the XML stream!";
            return;
        }
        xml->readNextStartElement();
            if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_LocationX){
                xml->readNext();
                 t->location.LocationX = xml->text().toInt();
                }
            xml->readNextStartElement();
            xml->readNextStartElement();
            if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_LocationY){
                xml->readNext();
                t->location.LocationY = xml->text().toInt();
                }

    //done reading location!
        return;
    }//_location_ end

    template<typename T3>
    void _taborder_(QXmlStreamReader *xml , T3 *t){
        if(xml->tokenType() != QXmlStreamReader::StartElement && xml->name() != my_TabOrder){
            qDebug()<<"\n" << "Called XML parseimagewidgetElement " << "without a imagewidget Element in the XML stream!";
            return;
        }
        while ( !(xml->tokenType() == QXmlStreamReader::EndElement && xml->name() == my_TabOrder)){
        xml->readNextStartElement();

            if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_TabV){

                xml->readNext();
                 t->taborder.TabV = xml->text().toString().toInt();
                }
            if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_TabH){
                xml->readNext();
                 t->taborder.TabH = xml->text().toString().toInt();
                }
        }
    //done reading TabOrder!
        return;
    }//_TabOrder_ end

    /*************************common functions ends*************************************/

      GMXML *ob_GMXML;
      Display *ob_Display;
      View *ob_View;
      Screen *ob_Screen;
      includeView *ob_includeView;
      TabViewType *ob_TabViewType;
      TabItemLayoutType *ob_TabItemLayoutType;
      ImageWidgetState *ob_ImageWidgetState;
      ImageWidget *ob_ImageWidget;
      BehaviorStateType *ob_BehaviorStateType;
      LabelWidget *ob_LabelWidget;
      LabelWidgetState *ob_LabelWidgetState;
      ProgressBarWidget *ob_ProgressBarWidget;
      MapWidget *ob_MapWidget;
      ListWidget *ob_ListWidget;
      ActivityIndicatorWidget *ob_ActivityIndicatorWidget;
      Spinner *ob_Spinner;
      KeyPad *ob_KeyPad;
      EditText *ob_EditText;
      KeyWidget *ob_KeyWidget;
      ScrollBarWidget *ob_ScrollBarWidget;
      Track *ob_Track;
      ImageWidgetWithIDType *ob_ImageWidgetWithIDType;
      ButtonWidget *ob_ButtonWidget;
      EnumButtonWidgetType *ob_EnumButtonWidgetType;
      Value *ob_Value;
      Location *ob_Location;
      Size *ob_Size;
      TabOrder *ob_TabOrder;
      InputWidgetMapping *ob_InputWidgetMapping ;
      Font *ob_Font;
      RowLayout *ob_RowLayout;
      ListInputWidgetMapping *ob_ListInputWidgetMapping;
      LetterIndexArray *ob_LetterIndexArray;
      AlphaData *ob_AlphaData;
      ImageElement *ob_ImageElement;
      LabelElement *ob_LabelElement;
      InitialData *ob_InitialData;
      InputScreenMap *ob_InputScreenMap;
      ButtonValueSelector *ob_ButtonValueSelector;
      EnumButtonWidgetStateType *ob_EnumButtonWidgetStateType;

};


#endif // GM_XML_PARSER_H
