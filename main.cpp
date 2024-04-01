#include "TrackballWidget.h"
#include <qapplication.h>


int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	TrackballWidget w;
	w.loadMesh("D:\\DataRepo\\mesh\\upper.stl");
	w.show();
	return a.exec();
}


