#ifndef STORE_XML_DATA_H
#define STORE_XML_DATA_H

#include <QCoreApplication>
class GMXML;
class Display;
class View;
class Screen;
class includeView;
class TabViewType;
class TabItemLayoutType;
class ImageWidgetState;
class ImageWidget;
class BehaviorStateType;
class LabelWidget;
class LabelWidgetState;
class ProgressBarWidget;
class MapWidget;
class ListWidget;
class ActivityIndicatorWidget;
class Spinner;
class KeyPad;
class EditText;
class KeyWidget;
class ScrollBarWidget;
class Track;
class ImageWidgetWithIDType;
class ButtonWidget;
class EnumButtonWidgetType;
class Value;
class Location;
class Size;
class TabOrder;
class InputWidgetMapping;
class Font;
class RowLayout;
class ListInputWidgetMapping;
class LetterIndexArray;
class AlphaData;
class ImageElement;
class LabelElement;
class InitialData;
class InputScreenMap;
class ButtonValueSelector;
class EnumButtonWidgetStateType;

class GMXML{
public:
    //Display display[] = new Display[];
    QList<Display*>display;
};
class Size{
public:
    int SizeW;
    int SizeH;
};

class TabOrder{
public:
    uint TabV;
    uint TabH;
};

class Display{
public:
    uint DisplayID;
    //View view[] = new View[];
    QList<View*>view;
    Size size;
};

class View{
public:
    QString ViewID;// 50 char limit
    uint ZOrder;
    //Screen screen[] = new Screen[];
    QList<Screen*>screen;
};

class Screen{
public:

        QList<includeView*>includeview;
        QList<TabViewType*>TabView;
        QList<ImageWidget*>imagewidget;
        QList<LabelWidget*>labelwidget;
        QList<ListWidget*>listwidget;
        QList<ProgressBarWidget*>progressbarwidget;
        QList<ButtonWidget*>buttonwidget;
        QList<EnumButtonWidgetType*>EnumButtonWidget;
        QList<ActivityIndicatorWidget*>activityindicatorwidget;
        QList<ScrollBarWidget*>scrollbarwidget;
        QList<KeyPad*>keypad;
        QList<InputScreenMap*>inputscreenmap;
        int Transition;
        TabOrder InitialFocus;
        QList<MapWidget*>mapwidget;
        QString OnFocus; // limit 50 char
        QString OffFocus;// limit 50 char

    QString ScreenID;// limit 50 char
    QString UUID;// limit 50 char

};

class includeView{
public:
    QString ViewID;//limit 50 char
    QString ScreenID;//limit 50 char
};

class Location{
public:
    int LocationX;
    int LocationY;
};


class TabViewType{
public:
    QString ID;// limit 50 char
    QString UUID ;// limit 50 char
    Location location;
    Size size;
    TabOrder taborder;
    int TotalTabCount;
    int TabSpacing;
    QString NormalURL; // limit 200 char
    QString HighlightURL; // limit 200 char
    QString TabSeperatorImageURL; // limit 200 char
    //TabItemLayoutType TabItemLayout[] = new TabItemLayoutType[];
    QList<TabItemLayoutType*>TabItemLayout;
    int ZOrder;
};

class TabItemLayoutType{
public:
    QString TabID;// limit 50 char
    Location location;
    Size size;
    //LabelWidget labelwidget[] = new LabelWidget[];
    QList<LabelWidget*>labelwidget;
    //ImageWidget imagewidget[] = new ImageWidget[];
    QList<ImageWidget*>imagewidget;
    //ButtonWidget ButtonWidget[] = new ButtonWidget[];
    QList<ButtonWidget*>ButtonWidget;
    includeView includeview;
    TabOrder taborder;
};

class ImageWidgetState{
public:
    int DataValue;
    QString NormalURL;// limit 50 char
    QString FocusURL;// limit 50 char
};

class ImageWidget{
public:
    QString ID;// limit 50 char
    QString UUID;// limit 50 char
    Location location;
    Size size;
    TabOrder taborder;
    QString NormalURL;// limit 200 char
    QString FocusURL;// limit 200 char
    int Alpha;
    //InputWidgetMapping inputwidgetmapping[] = new InputWidgetMapping[];
    QList<InputWidgetMapping*>inputwidgetmapping;
    QString OnFocusCallback;// limit 50 char
    uint ZOrder;
    //ImageWidgetState SelectorState[] = new ImageWidgetState[];
    QList<ImageWidgetState*>SelectorState;
    //BehaviorStateType BehaviorState[] = new BehaviorStateType[];
    QList<BehaviorStateType*>BehaviorState;

};

class BehaviorStateType{
public:
    uint BehaviorStateValue;
    int BehaviorProperty;        // from simpleType BehaviorPropertyType enum
    int BehaviorPropertyValue;   // from simpleType BehaviorPropertyValueType
    int ChangeAnimation;         // from simpleType ChangeAnimationType enum

};

class Value{
public:
    int Encoding;
    QString Text;//// limit 1000 char
};


class LabelWidget{
public:
    QString ID;// limit 50 char
    QString UUID;// limit 50 char
    Value value;
    //Font font;
    //Font FocusFont;
    int TextWrap;
    Location location;
    Size size;
    TabOrder taborder;
    int Alpha;
    //InputWidgetMapping inputwidgetmapping = new InputWidgetMapping[];
    QList<InputWidgetMapping*>inputwidgetmapping;
    QString OnFocusCallback;// limit 50 char
    int ZOrder;
    //LabelWidgetState SelectorState[] = new LabelWidgetState;
    QList<LabelWidgetState*>SelectorState;
};

class LabelWidgetState{
        struct labwidsta{
            QString StaticValue;//char
            QString LiteralValue;//char
        };

public:
        uint DataValue;
        labwidsta labelwidgetstate;
        //Font font;
        //Font FocusFont;

};

class ProgressBarWidget{
public:
    QString ID;// limit 50 char
    QString UUID;// limit 50 char
    int ProgressBarValue;
    Location location;
    Size size;
    QString ProgressBarURL;// limit 200 char
    Location ProgressBarURLLocation;
    Size ProgressBarURLSize;
    QString HousingURL;// limit 200 char
    Location HousingURLLocation;
    Size HousingURLSize;
    TabOrder taborder;
    int Alpha;
    //InputWidgetMapping inputwidgetmapping[] = new InputWidgetMapping[];
    QList<InputWidgetMapping*>inputwidgetmapping;
    QString OnFocusCallback[50];
    int ZOrder;
    int Orientation;    // from simpleType Orientation enum
};

class MapWidget{
public:
    Location MapLocation;
    int ZOrder;
    Size MapSize;
};

class RowLayout{
    struct Rlayout{
        Size size;
        int RowSpacing;
        Location location;
        QString NormalURL[200];
        QString FocusURL[200];
        QString RowSeparatorImageURL[200];
    }; // dynamiclly stored
public:
    QList<Rlayout*>ROWLAYOUT;
};

class ListInputWidgetMapping{
public:
    QString UserInput[2];
    int WidgetInput;
    QString EventCallbackString[50];
};

class AlphaData{
public:
    QString ImageURL[150];
    Location BackgroundPosition;
    Size size;
    int ZOrder;
    //LetterIndexArray letterindexarray = new LetterIndexArray[];
    QList<LetterIndexArray*>letterindexarray;
    //Font font;
    Location QStringacterPosition;
};



class ListWidget{
public:
    QString ListID[50];
    QString UUID[];
    Location location;
    Size size;
    int FocusedRow;
    QString BackgroundURL[200];
    RowLayout rowlayout;
    int ZOrder;
    TabOrder taborder;
    int TotalRowCount;
    AlphaData alphadata;
    //InitialData ElementData[] = new InitialData[];
    QList<InitialData*>ElementData;
    //ListInputWidgetMapping listinputwidgetmapping[] = new ListInputWidgetMapping;
    QList<ListInputWidgetMapping*>listinputwidgetmapping;
};

class Spinner{
public:
    Location SpinnerLocation;
    Size SpinnerSize;
    QString SpinnerURL[200];
};


class ActivityIndicatorWidget{
public:
    QString ID[50];
    QString UUID[50];
    Location location;
    Size size;
    TabOrder taborder;
    QString BackgroundURL[200];
    Spinner spinner;
    int Alpha;
    //InputWidgetMapping inputwidgetmapping[] = new InputWidgetMapping[];
    QList<InputWidgetMapping*>inputwidgetmapping;
    QString OnFocusCallback[50];
    int ZOrder;

};

class EditText{
public:
    QString ID[50];
    QString UUID[50];
    ImageWidget imagewidget;
    LabelWidget labelwidget;

};


class KeyPad{
public:
    QString ID[50];
    QString UUID[50];
    EditText edittext;
    //KeyWidget keywidget[] = new KeyWidget[];
    QList<KeyWidget*>keywidget;
};



class KeyWidget{
public:
    QString ID[50];
    QString UUID[50];
    ImageWidget imagewidget;
    LabelWidget labelwidget;

};

class ImageWidgetWithIDType{
public:
    QString ID[50];
    QString ImageWidgetID[50];
    QString UUID[50];
    Location location;
    Size size;
    TabOrder taborder;
    QString NormalURL[200];
    QString FocusURL[200];
    int Alpha;
    //InputWidgetMapping inputwidgetmapping[] = new InputWidgetMapping[];
    QList<InputWidgetMapping*>inputwidgetmapping;
    QString OnFocusCallback[50];
    int ZOrder;
    //ImageWidgetState SelectorState[] = new ImageWidgetState;
    QList<ImageWidgetState*>SelectorState;
    //BehaviorStateType BehaviorState[] = new BehaviorStateType;
    QList<BehaviorStateType*>BehaviorState;
};


class Track{
public:
    ImageWidgetWithIDType TrackHousing;
    ImageWidgetWithIDType ThumbHousing;
};



class ScrollBarWidget{
public:
    QString ID[50];
    QString UUID[50];
    QString ListID[50];
    Location location;
    Size size;
    Track track;
    ImageWidgetWithIDType IncrementArrow;
    ImageWidgetWithIDType DecrementArrow;
    int Alpha;
    int ZOrder;
    TabOrder taborder;
};




class ButtonWidget{
public:
    QString ID[50];
    QString UUID[50];
    ImageWidget imagewidget;
    LabelWidget labelwidget;
};

class EnumButtonWidgetType{
public:
    QString ID[50];
    QString UUID[50];
    //EnumButtonWidgetStateType EnumButtonWidgetState[] = new EnumButtonWidgetStateType[];
    QList<EnumButtonWidgetStateType*>EnumButtonWidgetState;
    int DataValue;
    ImageWidget imagewidget;
    LabelWidget labelwidget;
};





class InputWidgetMapping{
public:
    QList<QString> UserInput;
    QList<QString> WidgetCallback;
};

/*class Font{

};*/


class LetterIndexArray{
public:
    Value QStringacter;
    uint DisplayNumber;
    QString UniqueID[50];
};



class ImageElement{
public:
    uint ColumnID;
    QString ID[50];
    Location location;
    Size size;
    QString NormalURL[200];
    QString FocusURL[200];
    uint Alpha;
    //InputWidgetMapping InputWidgetMapping[] = new InputWidgetMapping[];
    QList<InputWidgetMapping*>inputwidgetmapping;
    QString OnFocusCallback[50];
    //ImageWidgetState SelectorState [] = new ImageWidgetState[];
    QList<ImageWidgetState*>SelectorState;
};

class LabelElement{
public:
    uint ColumnID;
    QString ID[50];
    Value value;
    Location location;
    Size size;
    //Font font;
    //Font FocusFont;
    uint Alpha;
    //InputWidgetMapping inputwidgetmapping [] = new InputWidgetMapping[];
    QList<InputWidgetMapping*>inputwidgetmapping;
    //LabelWidgetState SelectorState[] = new LabelWidgetState[];
    QList<LabelWidgetState*>SelectorState;
};

class InitialData{
public:
    uint RowIndex;
    QString UniqueID[50];
    QString OnFocusCallback[50];
    //ImageElement imageelement[] = new ImageElement[];
    QList<ImageElement*>imageelement;
    //LabelElement labelelement[] = new LabelElement[];
    QList<LabelElement*>labelelement;
};

class InputScreenMap{
public:
    QString UserInput[2];
    int FocusInput;
    QString FocusCallbackStr[50];
};

class ButtonValueSelector{
    struct labwidsta{
        QString StaticValue;
        QString LiteralValue;
    };

public:
    int Encoding;
    labwidsta buttonvalueselector;

};

class EnumButtonWidgetStateType{
public:
    uint DataValue;
    ImageWidget imagewidget;
    LabelWidget labelwidget;
};


#endif // STORE_XML_DATA_H
