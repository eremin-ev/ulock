/*
 * This source code is licensed under the GNU General Public License,
 * Version 2.  See the file COPYING for more details.
 */

import QtQuick 2.0
import Sailfish.Silica 1.0
import cpp.my.components 1.0

Rectangle {
    id: page
    width: 10;          // Won't work in Lipstick
    height: 10;         // Won't work in Lipstick
    color: Theme.overlayBackgroundColor

    Text {
        id: loginLabelId
        color: Theme.primaryColor
        text: "Login: "
        anchors.top: page.top
        anchors.topMargin: 20
        width: page.width / 2;
        font.pointSize: 30
    }

    Text {
        id: passwdLabelId
        color: Theme.primaryColor
        text: "Password: "
        anchors.top: loginLabelId.bottom
        anchors.topMargin: 40
        width: page.width / 2;
        font.pointSize: 30
    }

    TextInput {
        id: loginInputId
        color: Theme.highlightColor
        text: authId.login
        font.pointSize: 30
        anchors.left: loginLabelId.right
        anchors.leftMargin: 5
        width: page.width / 2;
        onActiveFocusChanged: {
                if (activeFocus)
                        selectAll()
        }
        onAccepted: authId.login = text
    }

    TextInput {
        id: passwdInputId
        color: Theme.highlightColor
        text: authId.passwd
        font.pointSize: 30
        anchors.left: passwdLabelId.right
        anchors.verticalCenter: passwdLabelId.verticalCenter
        anchors.leftMargin: 5
        width: page.width / 2;
        onActiveFocusChanged: {
                if (activeFocus)
                        selectAll()
        }
        onAccepted: authId.passwd = text
    }

    Button {
        text: "Log in"
        anchors.top: passwdLabelId.bottom
        anchors.topMargin: 40
        onPressed: {
                authId.buttonClicked();
        }
    }

    Auth {
        id: authId
    }
}

// vim:et:ts=4:ft=javascript:
