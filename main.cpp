#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "mytools.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QScopedPointer<MyTools> tools(new MyTools);
    engine.rootContext()->setContextProperty("tools",tools.data());

    return app.exec();
}
