#ifndef GLOBALDEF_HPP
#define GLOBALDEF_HPP
#include <QString>

#define  DATA(str)   new QTableWidgetItem(str)

#define SETCENTRALWIDGET(widget)               \
{                                              \
    if(this->centralWidget())                  \
    {                                          \
        this->centralWidget()->setParent(NULL);\
    }                                          \
    this->setCentralWidget(widget);            \
}

#define SAFEDELETE(pointer) \
{                           \
    if(pointer)             \
    {                       \
        delete pointer;     \
    }                       \
    pointer = NULL;         \
}

namespace GLOBALDEF
{
const static int ERROR = -1;                                 //数据库查询失败
const static QString UNUSED = "1";                           //不用使用密码登录
const static QString PRINTFLAGE = "1";                       //已经打印
const static QString SUCCESSIMAGE = ":/image/image/ok.png";  //成功图片
const static QString FAILIMAGE = ":/image/image/fail.png";   //失败图片
const static QString SYSTEMINFO = "系统提示";                 //系统提示


enum DATATYPE
{
    TYPEINSERT,
    TYPEUPDATE,
};


}




#endif // GLOBALDEF_HPP
