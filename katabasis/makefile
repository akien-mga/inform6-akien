NAME=katabasis

INFORM=inform
LANG=French
INCLUDEPATH=../lib/inform6lib-6.11,../lib/i6-french-language,../lib/scenic5sens
# Utilisation d'UTF-8 (requiert Inform 6.33+)
ZOPTIONS=-Cu

z8:
	$(INFORM) -v8 \
	+language_name=$(LANG) \
	+include_path=$(INCLUDEPATH) $(NAME).inf $(NAME).z8 -x $(ZOPTIONS)

z5:
	$(INFORM) -v5 \
	+language_name=$(LANG) \
	+include_path=$(INCLUDEPATH) $(NAME).inf $(NAME).z5 -x $(ZOPTIONS)

all:    z5 z8

debug:
	$(INFORM) -v8 \
	+language_name=$(LANG) \
	+include_path=$(INCLUDEPATH) $(NAME).inf $(NAME).z8 -x -D $(ZOPTIONS)

clean:
	rm -fr *.z5
	rm -fr *.z8
