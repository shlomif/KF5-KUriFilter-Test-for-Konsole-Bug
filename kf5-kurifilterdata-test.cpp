// KDE headers
#include <QApplication>
#include <QIcon>
#include <QCommandLineParser>
#include <KAboutData>
#include <KLocalizedString>

#include <kurifilter.h>
#include <iostream>

int main(int argc, char * argv[])
{
    QApplication application(argc, argv);

    KLocalizedString::setApplicationDomain("kurifilttest");
    KAboutData aboutData( QStringLiteral("kurifilttest"),
                          i18n("Simple App"),
                          QStringLiteral("0.1"),
                          i18n("A Simple Application written with KDE Frameworks"),
                          KAboutLicense::GPL,
                          i18n("(c) 20013-2014, %{AUTHOR} <%{EMAIL}>"));

    aboutData.addAuthor(i18n("%{AUTHOR}"),i18n("Author"), QStringLiteral("%{EMAIL}"));
    application.setWindowIcon(QIcon::fromTheme("kurifilttest"));
    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();
    aboutData.setupCommandLine(&parser);
    parser.process(application);
    aboutData.processCommandLine(&parser);

#if 0
    %{APPNAME} *appwindow = new %{APPNAME};
    appwindow->show();
    return application.exec();
#endif
    KUriFilterData data;
    data.setData("shlomi fish");
    data.setSearchFilteringOptions(KUriFilterData::RetrievePreferredSearchProvidersOnly);
    bool filtered = KUriFilter::self()->filterSearchUri(data, KUriFilter::NormalTextFilter);
    QStringList l = data.preferredSearchProviders();
    for (int i = 0; i < l.size(); i++)
    {
        std::cout << "Got «" << l.at(i).toLocal8Bit().constData() << "»" << std::endl;
    }
    return 0;
}
