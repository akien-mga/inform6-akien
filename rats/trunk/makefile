# Makefile pour centraliser les commandes sous Linux
#
# http://informfr.tuxfamily.org/
# http://ifiction.free.fr/
#
INCLUDEPATH=./,./lib,/usr/local/share/inform/6.31/include/,/usr/local/share/inform/6.31/module/,../../../informfr/inform6-fr/trunk/,../../../informfr/outils/divers/trunk/,../../../informfr/outils/scenic5sens/trunk/I6/
ZOPTIONS='$$MAX_DICT_ENTRIES=5000'

info:
	# make: z8 all
	
all:    z8 

z8:
	# en z8
	inform -v8 \
	+language_name=French \
	+include_path=$(INCLUDEPATH) rats.inf rats.z8 -x $(ZOPTIONS)

debug:
	# en z8
	inform -v8 \
	+language_name=French \
	+include_path=$(INCLUDEPATH) rats.inf rats.z8 -x -D $(ZOPTIONS)


clean:
	-rm -fr *~ 
	-rm -fr .*~ 
	-rm -fr *.z5
	-rm -fr *.z8
