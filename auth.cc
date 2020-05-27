/*
 * This source code is licensed under the GNU General Public License,
 * Version 2.  See the file COPYING for more details.
 */

#include <QDebug>

#include "auth.h"
#include "pam.h"

Auth::Auth(QObject *parent) :
	QObject(parent),
	m_login(""),
	m_passwd(""),
	m_state(AUTH_FAILED)
{
}

const QString Auth::login()
{
	return m_login;
}

const QString Auth::passwd()
{
	return m_passwd;
}

void Auth::setLogin(const QString &login)
{
	if (m_login != login) {
		m_login = login;
		emit loginChanged();
		qDebug() << "Auth login:" << m_login;
	}
}

void Auth::setPasswd(const QString &passwd)
{
	if (m_passwd != passwd) {
		m_passwd = passwd;
		emit passwdChanged();
		qDebug() << "Auth passwd:" << m_passwd;
	}
}

void Auth::buttonClicked()
{
	if (m_login.isEmpty() || m_passwd.isEmpty()) {
		qDebug() << "Auth: empty login or passwd";
		return;
	}

	if (m_state == AUTH_SUCCESS) {
		qDebug() << "Auth: already authenticated";
		return;
	}

	m_state = do_auth(m_login.toUtf8().constData(),
			  m_passwd.toUtf8().constData()) ?
			  AUTH_SUCCESS : AUTH_FAILED;
}
