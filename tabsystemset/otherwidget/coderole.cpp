#include "coderole.h"
#include "ui_coderole.h"
#include <QDateTime>
#include <QDate>
#include <QDebug>
#include "tabsystemset/tabsystemdata.h"
#include "globaldef.h"

/****************      构造函数                *******************/
CodeRole::CodeRole(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::coderole)
{
    ui->setupUi(this);

    ui->groupBoxBingLi->setFont(QFont("ZYSong", 12));  //设置字体大小
    ui->groupBoxQuCai->setFont(QFont("ZYSong", 12));   //设置字体大小
    ui->groupBoxImport->setFont(QFont("ZYSong", 12));  //设置字体大小

    initCodeRule();
    changeBingLiCodeRule();
    changQuCaiCodeRule();
}

/****************      析构函数                *******************/
CodeRole::~CodeRole()
{
    delete ui;
}

/****************      改变编码样例内容          *******************/
void CodeRole::changeBingLiCodeRule()
{
    const static int HUNDREDTIME = 100;

    QDate date = QDate::currentDate();

    QString str = ui->lineEditPrefix->text();

    if(ui->checkBoxType->isChecked())
    {
        str += "N";
    }

    if(ui->checkBoxYear->isChecked())
    {
        if(ui->radioButtonTwo->isChecked())
        {
            str += QString::number((date.year() % HUNDREDTIME));
        }
        else
        {
            str += QString::number(date.year());
        }
    }

    if(ui->checkBoxMonth->isChecked())
    {
        str += QString::number(date.month());
    }

    if(ui->checkBoxDay->isChecked())
    {
        str += QString::number(date.day());
    }

    if(!ui->lineEditSpin->text().isEmpty())
    {
        str += ui->lineEditSpin->text();
    }

    for(int i = 0; i < ui->spinBoxLength->value() - 1; i ++)
    {
        str += "0";
    }

    str += "1";

    ui->lineEditBingLiCodeDemo->setText(str);
}

/****************       前缀                   *******************/
void CodeRole::on_lineEditPrefix_textChanged(const QString &arg1)
{
    changeBingLiCodeRule();
}

/****************       类别                   *******************/
void CodeRole::on_checkBoxType_clicked()
{
    changeBingLiCodeRule();
}

/****************       年份                   *******************/
void CodeRole::on_checkBoxYear_clicked()
{
    if(!ui->checkBoxYear->isChecked())
    {
        ui->radioButtonTwo->setEnabled(false);
        ui->radioButtonFour->setEnabled(false);
    }
    else
    {
        ui->radioButtonTwo->setEnabled(true);
        ui->radioButtonFour->setEnabled(true);
    }
    changeBingLiCodeRule();
}

/****************       两位年份                *******************/
void CodeRole::on_radioButtonTwo_clicked()
{
    changeBingLiCodeRule();
}

/****************       四位年份                *******************/
void CodeRole::on_radioButtonFour_clicked()
{
    changeBingLiCodeRule();
}

/****************       月份                   *******************/
void CodeRole::on_checkBoxMonth_clicked()
{
    changeBingLiCodeRule();
}

/****************       日                     *******************/
void CodeRole::on_checkBoxDay_clicked()
{
    changeBingLiCodeRule();
}

/****************       间隔符                  *******************/
void CodeRole::on_spinBoxLength_valueChanged(const QString &arg1)
{
    changeBingLiCodeRule();
}

/****************       流水号长度               *******************/
void CodeRole::on_lineEditSpin_textChanged(const QString &arg1)
{
    changeBingLiCodeRule();
}

/****************       病理号                  *******************/
void CodeRole::on_checkBoxBingLiNumber_clicked()
{
    changQuCaiCodeRule();
}

/****************       连字符                  *******************/
void CodeRole::on_checkBoxHyphen_clicked()
{
    changQuCaiCodeRule();
}

/****************       流水号类型               *******************/
void CodeRole::on_comboBoxNumberType_activated(const QString &arg1)
{
    changQuCaiCodeRule();
}

/****************       取材编码规则             *******************/
void CodeRole::changQuCaiCodeRule()
{
    QString str;

    if(ui->checkBoxBingLiNumber->isChecked())
    {
        str += "病理号";
    }

    if(ui->checkBoxHyphen->isChecked())
    {
        str += "-";
    }

    switch(ui->comboBoxNumberType->currentIndex())
    {
    case NUMBER:       str += "1";  break;
    case SMALLLETTER:  str += "a";  break;
    case BIGLETTER:    str += "A";  break;
    }

    ui->lineEditQuCaiCodeDemo->setText(str);
}

/****************       初始化数据               *******************/
void CodeRole::initCodeRule()
{
    SYSTEMDATA->codeBeginSelectData();
    QMap<QString, QString> mapData = SYSTEMDATA->getCodeBeginSnSetInfo();

    ui->lineEditPrefix->setText(mapData[CUSTOMPREFIX]);
    ui->checkBoxType->setChecked(mapData[USERPREFIX].toInt());
    ui->checkBoxYear->setChecked(mapData[USEYEAR].toInt());

    if(mapData[YEARTYPE].toInt() == 2)
    {
        ui->radioButtonTwo->setChecked(true);
    }
    else
    {
        ui->radioButtonFour->setChecked(true);
    }

    ui->checkBoxMonth->setChecked(mapData[USEMONTH].toInt());
    ui->checkBoxDay->setChecked(mapData[USEDAY].toInt());
    ui->lineEditSpin->setText(mapData[SPIN]);
    ui->spinBoxLength->setValue(mapData[SNLENGTH].toInt());
    ui->checkBoxBingLiNumber->setChecked(mapData[BLNUMBER].toInt());
    ui->checkBoxHyphen->setChecked(mapData[HYPHEN].toInt());
    ui->comboBoxNumberType->setCurrentIndex(mapData[NUMBERTYPE].toInt());
    ui->lineEditSpilt->setText(mapData.value(ITEMSPLIT));
}

/****************       确定按钮                 *******************/
void CodeRole::on_pushButtonOk_clicked()
{
    this->close();

    InsertThread *insertThread = new InsertThread();

    insertThread->customPrefix = ui->lineEditPrefix->text();
    insertThread->usePrefix    = QString::number(ui->checkBoxType->isChecked());
    insertThread->useYear      = QString::number(ui->checkBoxYear->isChecked());
    insertThread->yearType     = ui->radioButtonTwo->isChecked() ? "2" : "4";
    insertThread->useMonth     = QString::number(ui->checkBoxMonth->isChecked());
    insertThread->useDay       = QString::number(ui->checkBoxDay->isChecked());
    insertThread->spin         = ui->lineEditSpin->text();
    insertThread->snLength     = QString::number(ui->spinBoxLength->value());
    insertThread->bLNumber     = QString::number(ui->checkBoxBingLiNumber->isChecked());
    insertThread->hyphen       = QString::number(ui->checkBoxHyphen->isChecked());
    insertThread->numberType   = QString::number(ui->comboBoxNumberType->currentIndex());
    insertThread->itemSplit    = ui->lineEditSpilt->text();

    insertThread->start();

    connect(insertThread, SIGNAL(finished()), insertThread, SLOT(deleteLater()));
}

/****************       取消按钮                 *******************/
void CodeRole::on_pushButtonCancel_clicked()
{
    this->close();
}

/****************       线程构造函数              *******************/
InsertThread::InsertThread()
{

}

/****************       线程运行函数              *******************/
void InsertThread::run()
{
    mutex.lock();

    SYSTEMDATA->codeBeginUpdateData(CUSTOMPREFIX, customPrefix);
    SYSTEMDATA->codeBeginUpdateData(USERPREFIX  , usePrefix);
    SYSTEMDATA->codeBeginUpdateData(USEYEAR     ,useYear);
    SYSTEMDATA->codeBeginUpdateData(YEARTYPE    , yearType);
    SYSTEMDATA->codeBeginUpdateData(USEMONTH    , useMonth);
    SYSTEMDATA->codeBeginUpdateData(USEDAY      , useDay);
    SYSTEMDATA->codeBeginUpdateData(SPIN        , spin);
    SYSTEMDATA->codeBeginUpdateData(SNLENGTH    , snLength);
    SYSTEMDATA->codeBeginUpdateData(BLNUMBER    , bLNumber);
    SYSTEMDATA->codeBeginUpdateData(HYPHEN      , hyphen);
    SYSTEMDATA->codeBeginUpdateData(NUMBERTYPE  , numberType);
    SYSTEMDATA->codeBeginUpdateData(ITEMSPLIT   , itemSplit);

    mutex.unlock();
}
