#include <QApplication>
#include <declarations.h>
#include <user_info_wizard.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QApplication app(argc, argv);


#ifndef QT_NO_TRANSLATION
    QString translatorFileName = QLatin1String("qtbase_");
    translatorFileName += QLocale::system().name();
    QTranslator *translator = new QTranslator(&app);
    if (translator->load(translatorFileName, QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
        app.installTranslator(translator);
#endif

    UserInfoWizard *userInfoWizard;
    userInfoWizard = new UserInfoWizard;
    userInfoWizard->exec();

    return app.exec();
}
