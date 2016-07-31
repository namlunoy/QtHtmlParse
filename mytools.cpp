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
    QString key = "<div class='mtq_question mtq_scroll_item-1'";
    QString result;
    QString content = getContent(fileName);
    QStringList list = content.split(key);

    for (int i = 1; i < 21; ++i) {
        content = list[i];
       qDebug() << content.split("'mtq_question_text'>")[1].split("</")[0];

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
