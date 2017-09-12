#include "gm_xml_parser.h"
#include "xml_elemets_list.h"
#include "store_xml_data.h"




bool my_xml_parser::xmlParser(QString path){
    //qDebug()<<"\nGoing Inside xmlParser function\n";

    QFile* file = new QFile(path);
    if(!file->open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"\n"<<"Unable to open the file maybe file "<<path<<" is not present or maybe corrupted ";
        return false;
    }
    QXmlStreamReader *xml = new QXmlStreamReader(file);
    QXmlStreamReader::TokenType token = xml->readNext();
        if(token == QXmlStreamReader::StartDocument){
            xml->readNextStartElement();
            if(! (xml->name() == my_GMXML)){
               qDebug()<<"\n"<<"Not GMXML ";
               return false;
            }
            readxml(xml);
        }

    return true;
}//function


// method where reading starts an object of GMXML is created
void my_xml_parser::readxml(QXmlStreamReader *xml){
    if(xml->tokenType() != QXmlStreamReader::StartElement && xml->name() != my_GMXML ){
        qDebug()<<"\n" << "error not GMXML still reading  ";
        return;
    }
     ob_GMXML = new GMXML;
     while(!xml->atEnd() && !xml->hasError()){
         xml->readNextStartElement();
         if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_Display){
             _display_(xml );
         }

     }//while
     return;
}//  readxml end


// this function is to read a complete Display element
void my_xml_parser::_display_(QXmlStreamReader *xml){
   if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_Display){
       ob_Display = new Display;
       ob_GMXML->display<<ob_Display;
   }
   xml->readNextStartElement();
   if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_DisplayID){
        xml->readNext();
        ob_Display->DisplayID = xml->text().toString().toInt();
   }
   xml->readNextStartElement();
   xml->readNextStartElement();
   if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_Size){
        _size_(xml ,ob_Display);
   }
   while ( !(xml->tokenType() == QXmlStreamReader::EndElement && xml->name() == my_Display)){
   xml->readNextStartElement();
   if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_View){
        _view_(xml);
   }
 }// while end
   return;
} // _display_ end

// reading View tag from display
void my_xml_parser::_view_(QXmlStreamReader *xml){
    if(xml->tokenType() != QXmlStreamReader::StartElement && xml->name() != my_View){
        qDebug()<<"\n" << "Called XML parseviewElement " << "without a View Element in the XML stream!";
        return;
    }
    if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_View){
        ob_View = new View;
        ob_Display->view<<ob_View;
    }
 // view id and zorder r outside the the loop coz they have to read once only for one view tag
    xml->readNextStartElement();
    if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_ViewID){
         xml->readNext();
         ob_View->ViewID = xml->text().toString();
        }
    xml->readNextStartElement();
    xml->readNextStartElement();
    if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_ZOrder){
        xml->readNext();
        ob_View->ZOrder = xml->text().toString().toInt();
        }
    while ( !(xml->tokenType() == QXmlStreamReader::EndElement && xml->name() == my_View)){
        xml->readNextStartElement();
        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_Screen){
            _screen_(xml);
            }
      }// whlie end
//done reading view!
    return;
}//_view_ end

// reading Screen tag from view
void my_xml_parser::_screen_(QXmlStreamReader *xml){
    if(xml->tokenType() != QXmlStreamReader::StartElement && xml->name() != my_Screen){
        qDebug()<<"\n" << "Called XML parsescreenElement " << "without a screen Element in the XML stream!";
        return;
    }
    if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_Screen){
        ob_Screen = new Screen;
        ob_View->screen<<ob_Screen;
    }
    while ( !(xml->tokenType() == QXmlStreamReader::EndElement && xml->name() == my_Screen)){
    xml->readNextStartElement();
        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_ScreenID){
            xml->readNext();
             ob_Screen->ScreenID = xml->text().toString();
            }
        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_UUID){
            xml->readNext();
             ob_Screen->UUID = xml->text().toString();
            }
        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_includeView){
            _includeiew_(xml);
            }
        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_ImageWidget){
            _imagewidget_(xml);
            }
      }// whlie end
//done reading Screen!
    return;
}//_screen_ end


void my_xml_parser::_includeiew_(QXmlStreamReader *xml){
    if(xml->tokenType() != QXmlStreamReader::StartElement && xml->name() != my_includeView){
        qDebug()<<"\n" << "Called XML parseincludeiewElement " << "without a includeiew Element in the XML stream!";
        return;
    }
    if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_includeView){
        ob_includeView = new includeView;
        ob_Screen->includeview<<ob_includeView;
    }
    while ( !(xml->tokenType() == QXmlStreamReader::EndElement && xml->name() == my_includeView)){
    xml->readNextStartElement();
        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_ViewID){
            xml->readNext();
             ob_includeView->ViewID = xml->text().toString();
            }
        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_ScreenID){
            xml->readNext();
             ob_includeView->ScreenID= xml->text().toString();
            }
      }// whlie end
//done reading includeiew!
    return;
}//_includeiew_ end

void my_xml_parser::_imagewidget_(QXmlStreamReader *xml){
    if(xml->tokenType() != QXmlStreamReader::StartElement && xml->name() != my_ImageWidget){
        qDebug()<<"\n" << "Called XML parseimagewidgetElement " << "without a imagewidget Element in the XML stream!";
        return;
    }
    if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_ImageWidget){
        ob_ImageWidget = new ImageWidget;
        ob_Screen->imagewidget<<ob_ImageWidget;

    }
    while ( !(xml->tokenType() == QXmlStreamReader::EndElement && xml->name() == my_ImageWidget)){

    xml->readNextStartElement();

        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_ID){

            xml->readNext();
             ob_ImageWidget->ID = xml->text().toString();
            }

        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_UUID){

            xml->readNext();
             ob_ImageWidget->UUID = xml->text().toString();
            }

        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_Location){
             _location_(xml , ob_ImageWidget);
            }

        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_Size){
             _size_(xml , ob_ImageWidget);
            }
        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_TabOrder){
             _taborder_(xml , ob_ImageWidget);
            }

        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_NormalURL){

            xml->readNext();
             ob_ImageWidget->NormalURL = xml->text().toString();
            }

        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_FocusURL){

            xml->readNext();
             ob_ImageWidget->FocusURL = xml->text().toString();
            }

        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_Alpha){

            xml->readNext();
             ob_ImageWidget->Alpha = xml->text().toInt();
            }

        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_InputWidgetMapping){
             _inputwidgetmapping_(xml);
            }

        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_OnFocusCallback){

            xml->readNext();
             ob_ImageWidget->OnFocusCallback = xml->text().toString();
            }
        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_ZOrder){

            xml->readNext();
             ob_ImageWidget->ZOrder = xml->text().toInt();
            }

        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_SelectorState){
             _selectorstate_(xml);
            }

        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_BehaviorState){
             _behaviorstatetype_(xml);
            }


      }// whlie end
//done reading imagewidget!
    return;
}//_imagewidget_ end


void my_xml_parser::_inputwidgetmapping_(QXmlStreamReader *xml){
    if(xml->tokenType() != QXmlStreamReader::StartElement && xml->name() != my_InputWidgetMapping){
        qDebug()<<"\n" << "Called XML parser inputwidgetmapping Element " << "without a imagewidget Element in the XML stream!";
        return;
    }

    if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_InputWidgetMapping){
        ob_InputWidgetMapping = new InputWidgetMapping;
        ob_ImageWidget->inputwidgetmapping<<ob_InputWidgetMapping;

    }
     while ( !(xml->tokenType() == QXmlStreamReader::EndElement && xml->name() == my_InputWidgetMapping)){

    xml->readNextStartElement();

        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_UserInput){

            xml->readNext();
             ob_InputWidgetMapping->UserInput<< xml->text().toString();
            }

        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_WidgetCallback){

            xml->readNext();
             ob_InputWidgetMapping->WidgetCallback<< xml->text().toString();
            }
}
//done reading inputwidgetmapping!
    return;
}//_inputwidgetmapping_ end

void my_xml_parser::_selectorstate_(QXmlStreamReader *xml){
    if(xml->tokenType() != QXmlStreamReader::StartElement && xml->name() != my_SelectorState){
        qDebug()<<"\n" << "Called XML parser selectorstate Element " << "without a selectorstate Element in the XML stream!";
        return;
    }

    if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_SelectorState){
        ob_ImageWidgetState = new ImageWidgetState;
        ob_ImageWidget->SelectorState<<ob_ImageWidgetState;

    }
    xml->readNextStartElement();

        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_DataValue){

            xml->readNext();
             ob_ImageWidgetState->DataValue = xml->text().toInt();
            }

        xml->readNextStartElement();
        xml->readNextStartElement();

        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_NormalURL){

            xml->readNext();
             ob_ImageWidgetState->NormalURL = xml->text().toString();
            }

        xml->readNextStartElement();
        xml->readNextStartElement();

        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_FocusURL){

            xml->readNext();
             ob_ImageWidgetState->FocusURL = xml->text().toString();
            }


//done reading selectorstate!
    return;
}//_selectorstate_ end

void my_xml_parser::_behaviorstatetype_(QXmlStreamReader *xml){
    if(xml->tokenType() != QXmlStreamReader::StartElement && xml->name() != my_BehaviorState){
        qDebug()<<"\nCalled XML parser behaviorstatetype Element " << "without a behaviorstatetype Element in the XML stream!";
        return;
    }

    if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_BehaviorState){
        ob_BehaviorStateType = new BehaviorStateType;
        ob_ImageWidget->BehaviorState<<ob_BehaviorStateType;

    }
    xml->readNextStartElement();

        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_BehaviorStateValue){

            xml->readNext();
             ob_BehaviorStateType->BehaviorStateValue = xml->text().toInt();
            }

        xml->readNextStartElement();
        xml->readNextStartElement();

        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_BehaviorProperty){

            xml->readNext();
             ob_BehaviorStateType->BehaviorProperty = xml->text().toInt();
            }

        xml->readNextStartElement();
        xml->readNextStartElement();

        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_BehaviorPropertyValue){

            xml->readNext();
             ob_BehaviorStateType->BehaviorPropertyValue = xml->text().toInt();
            }

        xml->readNextStartElement();
        xml->readNextStartElement();

        if(xml->tokenType() == QXmlStreamReader::StartElement && xml->name() == my_ChangeAnimation){

            xml->readNext();
             ob_BehaviorStateType->ChangeAnimation = xml->text().toInt();
            }



//done reading behaviorstatetype!
    return;
}//_behaviorstatetype_ end
