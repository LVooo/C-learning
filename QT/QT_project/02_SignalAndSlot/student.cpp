#include "student.h"
#include <Qdebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug() << "请老师吃饭";
}

void Student::treat(QString foodName)
{
    // 为了去掉双引号：QString->char* 先转成QByteArray (.toUtf8()) 再转char* (.data())
    qDebug() << "请老师吃饭，老师要吃：" << foodName.toUtf8().data();
}
