#ifndef TEXTWORK_H
#define TEXTWORK_H

#include <QtCore>
#include <QDebug>

class TextWork
{
public:
    TextWork();
    static QStringList splitQuestion(const QString& input);    // Split the html into question section
    static QString correctString(const QString&  input);    // Get rid of html code in the string
    static QString getQuestion(const QString&  input);      // Get the question in the question section
    static QStringList getAnswers(const QString& input);    // Get the answer from the question section
    static QString getExplanation(const QString& input);    // Get the explanation from the question section
};

#endif // TEXTWORK_H
