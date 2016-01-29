all: mytest.exe

mytest.exe: kf5-kurifilterdata-test.cpp
	g++ -Wall -o $@ -g -fPIC -I /usr/include/KF5/KI18n -I /usr/include/KF5/kio -I /usr/include/KF5/KIOCore/  -I /usr/include/KF5/KIOWidgets/ -I /usr/include/KF5/KCoreAddons/ `pkg-config --cflags --libs Qt5Core Qt5Gui Qt5Widgets` $< -lKF5KIOWidgets -lKF5I18n -lKF5CoreAddons
