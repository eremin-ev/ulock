/*
 * This source code is licensed under the GNU General Public License,
 * Version 2.  See the file COPYING for more details.
 */

import QtQuick 2.0
import Sailfish.Silica 1.0
import org.test.ulock 1.0

Rectangle {
    id: page
    width: 10;          // Won't work in Lipstick
    height: 10;         // Won't work in Lipstick
    color: Theme.overlayBackgroundColor

    Column {
        id: content
        width: parent.width

        PageHeader {
            title: "Column Header"
        }

        Item { width: 1; height: Theme.paddingLarge }

        Text {
            id: loginLabelId
            color: Theme.primaryColor
            text: "Login: "
            width: page.width / 2;
            font.pointSize: 30
        }

        TextInput {
            id: loginInputId
            color: Theme.highlightColor
            text: authId.login
            font.pointSize: 30
            width: page.width / 2;
            onActiveFocusChanged: {
                    if (activeFocus)
                            selectAll()
            }
            onAccepted: authId.login = text
        }

        Item { width: 1; height: Theme.paddingLarge }

        Text {
            id: passwdLabelId
            color: Theme.primaryColor
            text: "Password: "
            width: page.width / 2;
            font.pointSize: 30
        }

        TextInput {
            id: passwdInputId
            color: Theme.highlightColor
            text: authId.passwd
            font.pointSize: 30
            width: page.width / 2;
            onActiveFocusChanged: {
                if (activeFocus)
                    selectAll()
            }
            onAccepted: authId.passwd = text
        }

        Button {
            text: "Log in"
            onPressed: {
                authId.buttonClicked();
            }
        }
    }

    Auth {
        id: authId
    }
}
