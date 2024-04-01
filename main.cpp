#include "TrackballWidget.h"
#include <qapplication.h>


int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	TrackballWidget w;
	w.loadMesh("C:\\Users\\SewerVUE\\source\\DataFolder\\100550866632272\\crown_2.stl");
	w.show();
	return a.exec();
}


