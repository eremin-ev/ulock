CFLAGS = -Wall -Werror
CXXFLAGS = $(CFLAGS) -fPIC
QT = Qt5Core Qt5Gui Qt5Quick Qt5Qml

all: ulock

ulock: CXXFLAGS += $(shell pkg-config --cflags $(QT))
ulock: LDFLAGS += $(shell pkg-config --libs $(QT))
ulock: LDLIBS += -lQt5Core -lQt5Gui -lQt5Quick -lQt5Qml
ulock: LDLIBS += -lpam

ulock: auth.o pam.o moc_auth.o

moc_auth.cc: auth.h
	moc $< -o $@

clean:
	rm -vf ulock
	rm -vf moc_auth.cc
	rm -vf *.o
