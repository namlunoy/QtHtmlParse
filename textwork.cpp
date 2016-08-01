#include "textwork.h"

TextWork::TextWork()
{

}

QStringList TextWork::splitQuestion(const QString& input)
{
    QString key = "<div class='mtq_question mtq_scroll_item-1'";
    return input.split(key);
}

/*<span style=\"color: #000000;\"><span style=\"color: #000000;\">
What will happen if we __________ water</span></span>?*/

QString TextWork::correctString(const QString& input2)
{
    QString input(input2);
    int start = input.indexOf('<');
    int end = -1;

    // 1. Get rid of < >
    while(start >= 0){
        end = input.indexOf('>');
        if(end < 0)
            break;
        input.remove(start,end - start + 1);
        qDebug() << input;
        start = input.indexOf('<');
    }

    // 2. Get rid of &nbsp;
    start = input.indexOf("&nbsp;");
    if(start >= 0)
    {
        input.remove(start,6);
    }

    // 3. Trim
    input = input.trimmed();
    return input;
}

QString TextWork::getQuestion(const QString& input)
{
    QString question = input.split("'mtq_question_text'>")[1].split("</div>")[0];
    question = TextWork::correctString(question);
    return question;
}

QStringList TextWork::getAnswers(const QString& input)
{
    QStringList results;
    QString key = "'mtq_answer_text'>";
    QStringList list = input.split(key);
    for (int i = 1; i < list.count(); ++i) {
        QString s = list[i];
        results.push_back(s.split("</div>")[0]);
    }
    return results;
}

QString TextWork::getExplanation(const QString &input)
{
    QString key = "'mtq_explanation-text'>";
    QString result = (input.split(key)[1]).split("</div>")[0];
    return result.trimmed();
}
