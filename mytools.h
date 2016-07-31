#ifndef MYTOOLS_H
#define MYTOOLS_H

#include <QObject>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QtXml>
#include <QtCore>

class MyTools : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE QString getContent(QString fileName);
    Q_INVOKABLE QString getResult(QString fileName);
    void F(QDomElement root);
signals:

public slots:
};

#endif // MYTOOLS_H
