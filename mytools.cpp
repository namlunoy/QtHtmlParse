#include "mytools.h"

QString MyTools::getContent(QString fileName)
{
    QString result;
    QDir dir;

    while(dir.cdUp())
    {
        //dir.currentPath() = dir.cdUp();
        QString path = dir.absolutePath();
        if(path.endsWith("/Qt"))
            break;
    }

    QFile file(dir.filePath("QtHtmlParse/test.html"));
    file.open(QIODevice::Text | QIODevice::ReadOnly);
    QTextStream ss(&file);
    result = ss.readAll();
    file.close();
    return result;
}

QString MyTools::getResult(QString fileName)
{
    QString result;
    QString content = getContent(fileName);
    QStringList list = TextWork::splitQuestion(content);

    for (int i = 1; i < 21; ++i) {
       QString questionSection = list[i];
       QString q = TextWork::getQuestion(questionSection);
       result += QString::number(i) + " - ";
       result += q;
       result += "\n";

       QStringList a = TextWork::getAnswers(questionSection);
       for(auto s : a)
       {
           result += s;
           result += "\n";
       }

       QString ex = TextWork::getExplanation(questionSection);
       result += ex;
       result += "\n";

       result += "\n";
    }

    return result;
}

void MyTools::F(QDomElement root)
{
    if(root.hasChildNodes())
    {
        qDebug() << "1";
        for(QDomNode node = root.firstChild(); node != root.lastChild(); node = node.nextSibling())
        {
            F(node.toElement());
            qDebug() << node.toText().data();
        }
    }
}
