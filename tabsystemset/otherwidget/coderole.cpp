#include "coderole.h"
#include "ui_coderole.h"

CodeRole::CodeRole(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::coderole)
{
    ui->setupUi(this);

    ui->groupBoxBingLi->setFont(QFont("ZYSong", 12)); //设置字体大小
    ui->groupBoxQuCai->setFont(QFont("ZYSong", 12));  //设置字体大小
}

CodeRole::~CodeRole()
{
    delete ui;
}

void CodeRole::controlChanged()
{

}


/****************   初始化信号和槽   *******************/
void CodeRole::initConnect()
{
    connect(ui->lineEditPrefix, SIGNAL(textChanged(QString)), this,SLOT(controlChanged()));
    connect(ui->lineEditPrefix, SIGNAL(textChanged(QString)), this,SLOT(controlChanged()));
    connect(ui->lineEditPrefix, SIGNAL(textChanged(QString)), this,SLOT(controlChanged()));
}

