/*
 * This source code is licensed under the GNU General Public License,
 * Version 2.  See the file COPYING for more details.
 */

#pragma once

#include <QObject>

class Auth : public QObject {
	Q_OBJECT

	Q_PROPERTY(QString login READ login WRITE setLogin NOTIFY loginChanged)
	Q_PROPERTY(QString passwd READ passwd WRITE setPasswd NOTIFY passwdChanged)

	enum State {
		AUTH_FAILED =	0,
		AUTH_SUCCESS =	1,
	};

public:
	explicit Auth(QObject *parent = 0);
	const QString login();
	const QString passwd();
	void setLogin(const QString &login);
	void setPasswd(const QString &passwd);

signals:
	void loginChanged();
	void passwdChanged();

public slots:
	void buttonClicked();

private:
	QString m_login;
	QString m_passwd;
	int m_state;
};
