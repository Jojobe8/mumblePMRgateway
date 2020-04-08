#!/bin/sh

# Makefiles erzeugen.
# Die diversen Fehlermeldungen scheinen normal zu sein weil ein Teil
# der Dateien erst zur Laufzeit gebaut wird?
qmake -recursive main.pro CONFIG+=no-server CONFIG+=no-crash-report CONFIG+=no-update CONFIG+=no-bonjour CONFIG+=optimize

# Bauen:
#make clean
make -j 3
