#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "GUI_test_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    return a.exec(); // Keep only one exec() call at the end
}
