// This Widget is use Marble framework under the LGPL license 

#include <QApplication>
#include <QtQuick/QQuickView>
#include "MapItem.h"

class Mainwindow: public QQuickView
{
public:
	Mainwindow(){

		viewer = new QQuickView;
        qmlRegisterType<MapItem>("MapItem", 1, 0, "MapItem");
	    viewer->setSource(QUrl("./main.qml"));
	    viewer->show();

	}
	~Mainwindow(){};

private:
	QQuickView * viewer;

};

int main(int argc, char  *argv[])
{
	QApplication app(argc,argv);
	QQuickView *  viewer = new QQuickView;
    //viewer.setOrientation(QQuickView::ScreenOrientationAuto);
	Mainwindow w;
	return app.exec();
}

