/*
 * This source code is licensed under the GNU General Public License,
 * Version 2.  See the file COPYING for more details.
 */

#include <QtQuick/QQuickView>
#include <QGuiApplication>

#include "auth.h"

int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);

    Auth auth;

    qmlRegisterType<Auth>("org.test.ulock", 1, 0, "Auth");

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl("ulock.qml"));
    view.show();

    return app.exec();
}
