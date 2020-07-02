#include <QApplication>
#include <FelgoApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QDebug>

#include "serial.h"


// uncomment this line to add the Live Client Module and use live reloading with your custom C++ code
//#include <FelgoLiveClient>


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  app.addLibraryPath("/bin");
  qDebug() << app.libraryPaths();
  qDebug() << app.applicationDirPath();
  FelgoApplication felgo;
  qmlRegisterType<Serial>("com.Serial",1,0,"Serial");

  // Use platform-specific fonts instead of Felgo's default font
  felgo.setPreservePlatformFonts(true);

  QQmlApplicationEngine engine;
  felgo.initialize(&engine);

  QQuickStyle::setStyle("Material");

  felgo.setMainQmlFileName(QStringLiteral("qrc:/main.qml"));

  // use this instead of the above call to avoid deployment of the qml files and compile them into the binary with qt's resource system qrc
  // this is the preferred deployment option for publishing games to the app stores, because then your qml files and js files are protected
  // to avoid deployment of your qml files and images, also comment the DEPLOYMENTFOLDERS command in the .pro file
  // also see the .pro file for more details
  // felgo.setMainQmlFileName(QStringLiteral("qrc:/qml/Main.qml"));

  engine.load(QUrl(felgo.mainQmlFileName()));

  // to start your project as Live Client, comment (remove) the lines "felgo.setMainQmlFileName ..." & "engine.load ...",
  // and uncomment the line below
  //FelgoLiveClient client (&engine);

  return app.exec();
}
