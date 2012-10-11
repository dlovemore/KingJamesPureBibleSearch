#include <QtGui/QApplication>
#include "KJVCanOpener.h"

#include "dbstruct.h"

#include <assert.h>
#include <QLocale>

const char *g_constrDatabaseFilename = "../KJVCanOpener/db/kjvtext.s3db";


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CKJVCanOpener w;
    w.show();

    QLocale::setDefault(QLocale(QLocale::English, QLocale::UnitedStates));

//BuildDatabase(g_constrDatabaseFilename);
ReadDatabase(g_constrDatabaseFilename);
return 0;

//    if (argc > 1) {
//        if (stricmp(argv[1], "builddb") == 0) {
//            BuildDatabase();
//            return 0;
//        }
//    }
//
//    return a.exec();
}
