#include "store_xml_data.h"
#include "gm_xml_parser.h"
#include "store_xml_data.h"
#include <QCoreApplication>
#include <QDebug>

// repeating fuctions to be modify 1)size

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    bool check;
    QString path = "F:/PTG-india/project/GM_xml_schema/hmic.xml";

    my_xml_parser *parser = new my_xml_parser();

    check = parser->xmlParser(path);

    if(! check){
        return a.exec();
    }
    qDebug()<<"Done Reading";
    // for display tag elemets
    for(int d=0 ; d<(parser->ob_GMXML->display.count()) ; d++){

        qDebug()<<"\nDisplay tag"<<d+1<<"\nDisplay ID = "<<parser->ob_GMXML->display.at(d)->DisplayID;
        qDebug()<<"Size tag"<<"\nSizeW = "<<parser->ob_GMXML->display.at(d)->size.SizeW<<"\nSizeH = "<<parser->ob_GMXML->display.at(d)->size.SizeH;

        //for view tag elemnts
        for(int v=0 ; v<(parser->ob_GMXML->display.at(d)->view.count()) ; v++){
            qDebug()<<"View Tag "<<v+1<<"\nView ID = "<<parser->ob_GMXML->display.at(d)->view.at(v)->ViewID;
            qDebug()<<"Zorder = "<<parser->ob_GMXML->display.at(d)->view.at(v)->ZOrder;

            // for screen tag elements
            for(int s=0 ; s<(parser->ob_GMXML->display.at(d)->view.at(v)->screen.count()) ; s++)
            {
                qDebug()<<"Screen Tag "<<s+1<<"\nScreen ID = "<<parser->ob_GMXML->display.at(d)->view.at(v)->screen.at(s)->ScreenID;

                // for includeview tag elements
                for(int inv=0 ; inv<(parser->ob_GMXML->display.at(d)->view.at(v)->screen.at(s)->includeview.count()); inv++){
                    qDebug()<<"includeView Tag "<<inv+1<<"\nView ID = "<<parser->ob_GMXML->display.at(d)->view.at(v)->screen.at(s)->includeview.at(inv)->ViewID;
                    qDebug()<<"Screen ID = "<<parser->ob_GMXML->display.at(d)->view.at(v)->screen.at(s)->includeview.at(inv)->ScreenID;
                    qDebug()<<"";
                }

                // for imagewidget tag elements
                for(int imw=0 ; imw<(parser->ob_GMXML->display.at(d)->view.at(v)->screen.at(s)->imagewidget.count()); imw++){
                    qDebug()<<"ImageWidget Tag "<<imw+1<<"\nID = "<<parser->ob_GMXML->display.at(d)->view.at(v)->screen.at(s)->imagewidget.at(imw)->ID;
                    qDebug()<<" Location "<<"\nLocationX = "<<parser->ob_GMXML->display.at(d)->view.at(v)->screen.at(s)->imagewidget.at(imw)->location.LocationX;
                    qDebug()<<"LocationY = "<<parser->ob_GMXML->display.at(d)->view.at(v)->screen.at(s)->imagewidget.at(imw)->location.LocationY;
                    qDebug()<<"Size \nSizeH = "<<parser->ob_GMXML->display.at(d)->view.at(v)->screen.at(s)->imagewidget.at(imw)->size.SizeH;
                    qDebug()<<"SizeW = "<<parser->ob_GMXML->display.at(d)->view.at(v)->screen.at(s)->imagewidget.at(imw)->size.SizeW;
                    qDebug()<<"TabOrder \nTabV = "<<parser->ob_GMXML->display.at(d)->view.at(v)->screen.at(s)->imagewidget.at(imw)->taborder.TabV;
                    qDebug()<<"TabH = "<<parser->ob_GMXML->display.at(d)->view.at(v)->screen.at(s)->imagewidget.at(imw)->taborder.TabH;
                    qDebug()<<"NormalUrl = "<<parser->ob_GMXML->display.at(d)->view.at(v)->screen.at(s)->imagewidget.at(imw)->NormalURL;
                    qDebug()<<"FocusURL = "<<parser->ob_GMXML->display.at(d)->view.at(v)->screen.at(s)->imagewidget.at(imw)->FocusURL;
                    qDebug()<<"Alpha = "<<parser->ob_GMXML->display.at(d)->view.at(v)->screen.at(s)->imagewidget.at(imw)->Alpha;
                    qDebug()<<"Zorder = "<<parser->ob_GMXML->display.at(d)->view.at(v)->screen.at(s)->imagewidget.at(imw)->ZOrder;
                    qDebug()<<"OnFocusCallback = "<<parser->ob_GMXML->display.at(d)->view.at(v)->screen.at(s)->imagewidget.at(imw)->OnFocusCallback;
                    for(int inmap = 0;  inmap<(parser->ob_GMXML->display.at(d)->view.at(v)->screen.at(s)->imagewidget.at(imw)->inputwidgetmapping.count()) ; inmap++){
                        qDebug()<<"inputwidgetmapping "<<inmap+1;
                        for(int inmapx = 0;  inmapx<(parser->ob_GMXML->display.at(d)->view.at(v)->screen.at(s)->imagewidget.at(imw)->inputwidgetmapping.at(inmap)->UserInput.count()) ; inmapx++){
                            qDebug()<<"user input = "<<inmapx+1<<" = "<<parser->ob_GMXML->display.at(d)->view.at(v)->screen.at(s)->imagewidget.at(imw)->inputwidgetmapping.at(inmap)->UserInput.at(inmapx);
                            qDebug()<<"user input = "<<inmapx+1<<" = "<<parser->ob_GMXML->display.at(d)->view.at(v)->screen.at(s)->imagewidget.at(imw)->inputwidgetmapping.at(inmap)->WidgetCallback.at(inmapx);
                            qDebug()<<"";
                        }
                        qDebug()<<"";
                    }
                    qDebug()<<"";
                }
                qDebug()<<"";
            }
            qDebug()<<"";
        }
        qDebug()<<"";
    }


    return a.exec();

}


