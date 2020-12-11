! ==============================================================================
!   French.h:  Language Definition File (Second Person Plural - Present)
!
!   Supplied for use with Inform 6 -- Release 6/11 -- Serial number 040227
!
! ------------------------------------------------------------------------------
!
!   This file is originally based off the English Definition File (english.h) of
!   the Inform 6 Library (https://github.com/DavidGriffith/inform6lib) by Graham
!   Nelson. In compliance with the license of the Inform 6 Library, this file is
!   licensed under the Artistic License version 2.0 (see COPYING and ARTISTIC).
!
!   Copyright Communauté IFiction-FR 2004-2016
!   Copyright Jean-Luc Pontico 2001-2004
!   Copyright Graham Nelson 1993-2004
!
! ------------------------------------------------------------------------------
!
!   This file is automatically included in your game file by "parserm".
!   Strictly, "parserm" includes the file named in the "language__" variable,
!   whose contents can be defined by +language_name=XXX compiler setting (with a
!   default of "english").
!
! ==============================================================================



!===============================================================================
! Hacks dans les routines de la bibliothèque


!======================================
! Quand il y a les prépositions 'a'/'au'/'aux' et 'de'/'du'/'des'/'d^', et qu'il faut
!    compléter le motif, le parser prend toujours la première préposition pour l'affichage
!    ce qui donne "se servir (de le passeport)"

Replace PrintCommand;

[ PrintCommand from i k spacing_flag variante_flag prep;
    if (from == 0) {
        i = verb_word;
        if (LanguageVerb(i) == 0)
            if (PrintVerb(i) == 0) print (address) i;
        from++; spacing_flag = true;
    }

	variante_flag = 0;
    for (k=from : k<pcount : k++) {
        i = pattern-->k;
        if (i == PATTERN_NULL) continue;
        if (spacing_flag && variante_flag == 0) print (char) ' ';
        if (i ==0 ) { print (string) THOSET__TX; jump TokenPrinted; }
        if (i == 1) { print (string) THAT__TX;   jump TokenPrinted; }
        if (i >= REPARSE_CODE) {
			prep = No__Dword(i-REPARSE_CODE);
            if (prep == 'de' || prep == 'a//') {
				if (prep == 'de') { variante_flag = 1;} else { variante_flag = 2;}
				! On skippe, on affichera tout ça au tour suivant
			}
			else { print (address) prep; }
		}
        else {
            if (i in compass && LanguageVerbLikesAdverb(verb_word))
                LanguageDirection (i.door_dir); ! the direction name as adverb
            else
                if (variante_flag > 0) {
					if (variante_flag == 1) { print (DeDuDes) i;}
					else { print (to_the) i; }
					variante_flag = 0;
				}
				else { print (the) i;}
		}
      .TokenPrinted;
        spacing_flag = true;
    }
];


! --------------------------------------
! la bibliothèque


Constant LibReleaseFR      "6.11.4dev";
Message		"[Compilé avec la version 6.11.4dev de la bibliothèque francophone.]";
!Message		"[Compilé avec la version ", (string) LibReleaseFR, " de la bibliothèque francophone.]";
! note : "message" ne permet pas d'inclure une constante, cela doit être d'un seul bloc
! sinon cela ne compile pas. C'est dommage cela aurait été pratique...

System_file;

! ------------------------------------------------------------------------------
!   Part I.   Preliminaries
! ------------------------------------------------------------------------------

!*! Constant EnglishNaturalLanguage;    ! Needed to keep old pronouns mechanism

Class   CompassDirection
  with  number 0, article "le",
        description [;
            if (location provides compass_look && location.compass_look(self)) rtrue;
            if (self.compass_look()) rtrue;
            L__M(##Look, 7, self);
        ],
        compass_look false,
  has   scenery;

Object Compass "compass" has concealed;

#Ifndef WITHOUT_DIRECTIONS;
CompassDirection -> n_obj "nord"
                    with door_dir n_to, name 'n//' 'nord';
CompassDirection -> s_obj "sud"
                    with door_dir s_to, name 's//' 'sud';
CompassDirection -> e_obj "est"
                    with door_dir e_to, name 'e//' 'est',
                    article "l'";
CompassDirection -> w_obj "ouest"
                    with door_dir w_to, name 'o//' 'w//' 'ouest',
                    article "l'";
CompassDirection -> ne_obj "nord-est"
                    with door_dir ne_to, name 'ne' 'nordest';
CompassDirection -> nw_obj "nord-ouest"
                    with door_dir nw_to, name 'no' 'nw' 'nordouest';
CompassDirection -> se_obj "sud-est"
                    with door_dir se_to, name 'se' 'sudest';
CompassDirection -> sw_obj "sud-ouest"
                    with door_dir sw_to, name 'so' 'sw' 'sudouest';
CompassDirection -> u_obj "haut"
                    with door_dir u_to, name 'h//' 'haut' 'plafond' 'ciel';
CompassDirection -> d_obj "bas"
                    with door_dir d_to, name 'b//' 'd//' 'bas' 'sol';
#endif; ! WITHOUT_DIRECTIONS

CompassDirection -> in_obj "intérieur"
                    with door_dir in_to, name 'dedans' 'interieur',
                    article "l'";
CompassDirection -> out_obj "extérieur"
                    with door_dir out_to, name 'dehors' 'exterieur',
                    article "l'";

! ------------------------------------------------------------------------------
!   Part II.   Vocabulary
! ------------------------------------------------------------------------------

Constant AGAIN1__WD   = 'encore';
Constant AGAIN2__WD   = 'g//';
Constant AGAIN3__WD   = 'c//';
Constant OOPS1__WD    = 'oops';
Constant OOPS2__WD    = 'euh';
Constant OOPS3__WD    = 'euh';
Constant UNDO1__WD    = 'undo';
Constant UNDO2__WD    = 'annule';
Constant UNDO3__WD    = 'annuler';

Constant ALL1__WD     = 'tous';
Constant ALL2__WD     = 'toutes';
Constant ALL3__WD     = 'tout';
Constant ALL4__WD     = 'tout';
Constant ALL5__WD     = 'tout';
Constant AND1__WD     = 'et';
Constant AND2__WD     = 'et';
Constant AND3__WD     = 'et';
Constant BUT1__WD     = 'mais pas'; ! FIXME : ne fonctionne pas
Constant BUT2__WD     = 'excepte';
Constant BUT3__WD     = 'sauf';
Constant ME1__WD      = 'moi';
Constant ME2__WD      = 'toi'; !*! nous ? moi-même ?
Constant ME3__WD      = 'vous';
Constant OF1__WD      = 'de';
Constant OF2__WD      = 'de';
Constant OF3__WD      = 'de';
Constant OF4__WD      = 'de';
Constant OTHER1__WD   = 'autre';
Constant OTHER2__WD   = 'autre';
Constant OTHER3__WD   = 'autre';
Constant THEN1__WD    = 'alors';
Constant THEN2__WD    = 'puis';
Constant THEN3__WD    = 'ensuite';

Constant NO1__WD      = 'n//';
Constant NO2__WD      = 'non';
Constant NO3__WD      = 'non';
Constant YES1__WD     = 'o//';
Constant YES2__WD     = 'y//';
Constant YES3__WD     = 'oui';

Constant AMUSING__WD  = 'amusing';
Constant FULLSCORE1__WD = 'fullscore';
Constant FULLSCORE2__WD = 'full';
Constant QUIT1__WD    = 'q//';
Constant QUIT2__WD    = 'quitter';
Constant RESTART__WD  = 'recommencer';
Constant RESTORE__WD  = 'charger';

Array LanguagePronouns table

   !  word       possible GNAs                   connected
   !             to follow:                      to:
   !             a     i
   !             s  p  s  p
   !             mfnmfnmfnmfn

      ! Object pronouns
      '-le'    $$100000100000                    NULL
      '-la'    $$010000010000                    NULL
      '-les'   $$000110000110                    NULL
      '-lui'   $$110000110000                    NULL
      '-leur'  $$000110000110                    NULL        ! tirets remis
!      'le'    $$100000100000                    NULL        ! car l'article le/la/les vient parfois interférer
!      'la'    $$010000010000                    NULL        ! par exemple "mange la pomme" est compris comme "mange-la" si "pomme" est inconnu, d'où des messages d'erreur troublants pour le joueur
!      'les'   $$000110000110                    NULL
!      'lui'   $$110000110000                    NULL ! dans "donne-lui", "lui" est m ou f
!      'leur'  $$000110000110                    NULL

      ! Disjunctive pronouns
!*! ! féminin accepté pour 'luy' (mot bidon) pour traiter les cas 'dedans', 'dessus', 'l^'... (genre inconnu)
!   en fait, '-lui' pourrait jouer le même rôle
      'luy'    $$110000110000                    NULL ! "l'ouvrir" devient "ouvrir luy", "luy" étant m ou f
      'lui'    $$100000100000                    NULL
      'elle'   $$010000010000                    NULL
      'eux'    $$000110000110                    NULL
      'elles'  $$000010000010                    NULL;

Array LanguageDescriptors table

   !  word       possible GNAs   descriptor      connected
   !             to follow:      type:           to:
   !             a     i
   !             s  p  s  p
   !             mfnmfnmfnmfn

      'mon'    $$100000100000    POSSESS_PK      0  !*! ce qui suit ne doit pas fonctionner souvent
      'ma'     $$010000010000    POSSESS_PK      0  !*! du moins je l'espère car mon/ma/mes devrait
      'mes'    $$000110000110    POSSESS_PK      0  !*! changer en fonction du type de parole
      'ton'    $$100000100000    POSSESS_PK      0  !*!
      'ta'     $$010000010000    POSSESS_PK      0  !*! (quoique ça a l'air tres tolerant)
      'tes'    $$000110000110    POSSESS_PK      0  !*!
      'notre'  $$110000110000    POSSESS_PK      0  !*!
      'nos'    $$000110000110    POSSESS_PK      0  !*!
      'votre'  $$110000110000    POSSESS_PK      0  !*!
      'vos'    $$000110000110    POSSESS_PK      0  !*!
      'son'    $$100000100000    POSSESS_PK      '-lui'        ! tirets remis
      'sa'     $$010000010000    POSSESS_PK      '-lui'
      'ses'    $$000110000110    POSSESS_PK      '-lui'
      'leur'   $$110000110000    POSSESS_PK      '-les'
      'leurs'  $$000110000110    POSSESS_PK      '-les'
!      'son'    $$100000100000    POSSESS_PK      'lui'
!      'sa'     $$010000010000    POSSESS_PK      'lui'
!      'ses'    $$000110000110    POSSESS_PK      'lui'
!      'leur'   $$110000110000    POSSESS_PK      'les'
!      'leurs'  $$000110000110    POSSESS_PK      'les'

      'le'     $$100000100000    DEFART_PK       NULL
      'la'     $$010000010000    DEFART_PK       NULL
      'l^'     $$110000110000    DEFART_PK       NULL
      'les'    $$000110000110    DEFART_PK       NULL
      'un'     $$100000100000    INDEFART_PK     NULL
      'une'    $$010000010000    INDEFART_PK     NULL
      'des'    $$000110000110    INDEFART_PK     NULL

     'allumé'  $$100000100000    light           NULL
     'allumée' $$010000010000    light           NULL
     'éteint'  $$100000100000    (-light)        NULL
     'éteinte' $$010000010000    (-light)        NULL;

Array LanguageNumbers table
    'un' 1 'une' 1 'deux' 2 'trois' 3 'quatre' 4 'cinq' 5
    'six' 6 'sept' 7 'huit' 8 'neuf' 9 'dix' 10
    'onze' 11 'douze' 12 'treize' 13 'quatorze' 14 'quinze' 15
    'seize' 16 'dix-sept' 17 'dix-huit' 18 'dix-neuf' 19 'vingt' 20
    'vingt et un' 21 'vingt-deux' 22 'vingt-trois' 23 'vingt-quatre' 24
   'vingt-cinq' 25 'vingt-six' 26 'vingt-sept' 27 'vingt-huit' 28
   'vingt-neuf' 29 'trente' 30
;

! ------------------------------------------------------------------------------
!   Part III.   Translation
! ------------------------------------------------------------------------------


! Routines utiles pour reconnaître les versions accentuées d'une lettre
[ IsAnA c;
    ! aàáâãäæå + majuscules
    #Ifdef TARGET_ZCODE;
    if (c == 'a' or 'A' or 155 or 158 or 169 or 175 or 181 or 186 or 191 or 196 or 201 or 202 or 205 or 208 or '@ae' or 212) return true;
    #Ifnot; ! TARGET_GLULX    - donc il faut les valeurs Unicode !
    if ((c == 'a' or 'A') || (c > 191 && c < 199) || (c > 223 && c < 231)) return true;
    #Endif; ! TARGET_
    return false;
];
[ IsAnE c;
    ! eéèêë + majuscules
    #Ifdef TARGET_ZCODE;
    if (c == 'e' or 'E' or 164 or 167 or 170 or 176 or 182 or 187 or 192 or 197 ) return true;
    #Ifnot; ! TARGET_GLULX    - donc il faut les valeurs Unicode !
    if ((c == 'e' or 'E') || (c > 199 && c < 204) || (c > 231 && c < 236)) return true;
    #Endif; ! TARGET_
    return false;
];
[ IsAnI c;
    ! iïíìî + majuscules
    #Ifdef TARGET_ZCODE;
    if (c == 'i' or 'I' or 165 or 168 or 171 or 177 or 183 or 188 or 193 or 198 ) return true;
    #Ifnot; ! TARGET_GLULX    - donc il faut les valeurs Unicode !
    if ((c == 'i' or 'I') || (c > 203 && c < 208) || (c > 235 && c < 240)) return true;
    #Endif; ! TARGET_
    return false;
];
[ IsAnO c;
    ! oóòôõö oe + majuscules
    #Ifdef TARGET_ZCODE;
    if (c == 'o' or 'O' or 156 or 159 or 172 or 178 or 184 or 189 or 194 or 199 or 203 or 204 or 207 or 210 or '@oe' or 221 ) return true;
    #Ifnot; ! TARGET_GLULX    - donc il faut les valeurs Unicode !
            ! les valeurs 338 et 339 (oe et OE) seront transformées automatiquement en ? par Glulx avant même cette fonction, donc ça ne marchera pas
    if ((c == 'o' or 'O') || (c > 209 && c < 215) || (c == 216 or 248 or 338 or 339) || (c > 241 && c < 247)) return true;
    #Endif; ! TARGET_
    return false;
];
[ IsAnU c;
    ! uüùúû + majuscules
    #Ifdef TARGET_ZCODE;
    if (c == 'u' or 'U' or 157 or 160 or 173 or 179 or 185 or 190 or 195 or 200 ) return true;
    #Ifnot; ! TARGET_GLULX    - donc il faut les valeurs Unicode !
    if ((c == 'u' or 'U') || (c > 216 && c < 221) || (c > 248 && c < 253)) return true;
    #Endif; ! TARGET_
    return false;
];



! La fonction enleve_accents enlève les accents de l'input ; de cette manière,
! le joueur peut utiliser les accents ou non. Pour cela le jeu doit définir les
! mots sans accent, par exemple :
!   object set_of_keys "trousseau de clés"
!   with name 'trousseau' 'cles';
! Si le joueur demande : "examiner cles", le mot est compris directement.
! S'il demande : "examiner clés", les accents sont enlevés et on retombe sur le
! cas précédent.

! Note : les ligatures (@oe et @ae) sont considérées comme des accents (vu que
! c'est le même principe : des lettres qui existent mais que tout le monde ne
! va pas utiliser tout le temps, et il faut pouvoir reconnaître les deux formes).

! On peut modifier ce comportement en modifiant la variable "gardeaccents" :
!   1 = l'accent est enlevé uniquement si le mot n'est pas dans le dictionnaire
!       (attention: "clés" dans un name et "cles" dans 10 autres fera un bug sur les 10 autres)
!       Commande de déboguage : accents on
!   2 = les accents ne sont jamais enlevés
!       (pas compatible avec la bibliothèque, puisque les verbes n'ont pas d'accents)
!       Commande de déboguage : accents strict

global gardeaccents=0;


! Cette fonction transforme le buffer pour enlever les accents et convertir les ligatures
! Elle renvoie 0 si on ne change rien, 1 si on a changé 1 lettre en une autre, 2 si on a
!   remplacé la lettre par deux lettres (pour les ligatures)
!
! Note: la conversion en minuscules se fait avant l'appel à cette fonction ; pas besoin de
!   tester les versions majuscules des lettres, donc

[ convertir_lettre i ;
    ! on traite les ligatures en premier pour les séparer des a et des o accentués
#IfDef TARGET_ZCODE;
    if (buffer->i == '@ae') { buffer->i='a'; LTI_Insert(++i, 'e'); return 2;}
    if (buffer->i == '@oe') { buffer->i='o'; LTI_Insert(++i, 'e'); return 2;}
#IfNot; ! TARGET_GLULX;
    if (buffer->i == 198 or 230) { buffer->i='a'; LTI_Insert(++i, 'e'); return 2; }
    ! pas d'équivalent pour oe, zut! Le code Unicode étant >255, c'est automatiquement transformé en '?', avant même cette routine...
#Endif;
    ! les autres lettres accentuées
    if (IsAnA(buffer->i)) { buffer->i='a'; return 1; }
    if (IsAnE(buffer->i)) { buffer->i='e'; return 1; }
    if (IsAnI(buffer->i)) { buffer->i='i'; return 1; }
    if (IsAnO(buffer->i)) { buffer->i='o'; return 1; }
    if (IsAnU(buffer->i)) { buffer->i='u'; return 1; }
    switch(buffer->i) {
        'ÿ': buffer->i='y'; return 1;
	'ý': buffer->i='y'; return 1;
	'ñ': buffer->i='n'; return 1;
        'ç': buffer->i='c'; return 1;
    }
    return 0;
];


! Cette fonction enlève les accents et les ligatures dans buffer

[ enleve_accents x i word at len lettresremplacees ;

    #Ifdef DEBUG; affiche_buffer(buffer, "  [ enleve_accents :^  - Buffer reçu : "); #Endif;

    if (gardeaccents ~= 2) {
	for (x=0:x<NbMots():x++) ! pour chaque mot
	{
            word=Mot(x);
		at=PositionMot(x);
		len=LongueurMot(x);
		if ( gardeaccents == 0 || (gardeaccents == 1 && word==0) )
		{
	#Ifdef DEBUG;
                    if (parser_trace>=7 && gardeaccents == 1)
			{
				print "    NON COMPRIS : |";
				for (i=at:i<at+len:i++) print (char) buffer->i;
				print "|^";
			}
	#Endif;
			for (i=at:i<at+len:i++)
			{	lettresremplacees = convertir_lettre(i);
                                ! si on a remplacé æ par ae, la longueur a augmenté
                                if (lettresremplacees == 2) { len++; }
			}


			Tokenise__(buffer,parse);
		}
        }
    }

    #Ifdef DEBUG; affiche_buffer(buffer, "  - Buffer sans accents : "); #Endif;
];

! enlève le tiret de départ des mots qui ne sont pas dans le dictionnaire
[ enleve_tirets x i word at len;
    i=NULL; ! pour retirer warning a la compilation glulxe

    #Ifdef DEBUG; affiche_buffer(buffer, "  [ enleve_tirets :^  - Buffer reçu : "); #Endif;

    for (x=0:x<NbMots():x++) ! pour chaque mot
    {
        word=Mot(x);
        at=PositionMot(x);
        len=LongueurMot(x);
        if (word==0) ! non compris
        {
#Ifdef DEBUG;
            if (parser_trace>=7)
            {
                print "    NON COMPRIS : |";
                for (i=at:i<at+len:i++) print (char) buffer->i;
                print "|^";
            }
#Endif;

            if (buffer->at=='-') buffer->at=' ';
            Tokenise__(buffer,parse);
        }
    }

    #Ifdef DEBUG; affiche_buffer(buffer, "  - Buffer sans tirets : "); #Endif;
];

[ NbMots; ! nombre de mots dans parse
#Ifdef TARGET_ZCODE;
    return parse->1;
#Ifnot; ! TARGET_GLULX
    return parse-->0;
#Endif; ! TARGET_
];

[ NbChars; ! nombre de chars dans buffer
#Ifdef TARGET_ZCODE;
    return buffer->1;
#Ifnot; ! TARGET_GLULX
    return buffer-->0;
#Endif; ! TARGET_
];

[ Mot n; ! valeur (dictionnaire) du mot numéro n de parse
#Ifdef TARGET_ZCODE;
    return parse-->(n*2 + 1);
#Ifnot; ! TARGET_GLULX
    return parse-->(n*3 + 1);
#Endif; ! TARGET_
];

[ PositionMot n; ! position dans buffer du mot numéro n de parse
#Ifdef TARGET_ZCODE;
    return parse->(n*4 + 5);
#Ifnot; ! TARGET_GLULX
    return parse-->(n*3 + 3);
#Endif; ! TARGET_
];

[ LongueurMot n;   ! longueur (en chars) dans buffer du mot numéro n de parse
#Ifdef TARGET_ZCODE;
    return parse->(n*4 + 4);
#Ifnot; ! TARGET_GLULX
    return parse-->(n*3 + 2);
#Endif; ! TARGET_
];

[ EcraseMot n i;        ! écrase avec des espaces dans buffer le mot numéro n
    for(i=0:i<LongueurMot(n):i++)
        buffer->(PositionMot(n)+i) = ' ';
];

[ DernierMot n; ! vrai si le mot numéro n est le dernier ou suivi d'un "point" (THEN1__WD, ...)
    if (n==NbMots()-1) ! le mot numéro n est-il le dernier ?
        return true;
    else        ! est-il suivi d'un "point" ?
        return (Mot(n+1) == THEN1__WD or THEN2__WD or THEN3__WD);
];

[ LanguageToInformese i word wordsuiv at b RangVerbe RangDernier;

    Tokenise__(buffer,parse);
    #Ifdef DEBUG; affiche_buffer(buffer, "[ LanguageToInformese:^* Buffer reçu : "); #Endif;

    ! On enlève les accents de la commande
    !   le seul side-effect de le faire si tôt, c'est "là sortir de" est compris comme "sortir-la de"
    !   on peut penser qu'un joueur qui tape "là sortir de" pour "sortir de là" ne mérite pas qu'on le comprenne
    !                  qu'un joueur qui tape "là sortir de la boîte" mérite qu'on le corrige en "la sortir de la boîte" et qu'on le comprenne
    !   bref, c'est aussi une amélioration
    enleve_accents();

    for (i=0:i<NbMots():i++) ! balayer toute la phrase
    {
         word = Mot(i);
         if (DernierMot(i)) wordsuiv=THEN1__WD; else wordsuiv=Mot(i+1);
         at = PositionMot(i); ! position du mot numéro i dans buffer
         if (word == 'dessus')
         {   LTI_Insert(at, ' '); ! remplace
             buffer->at     = 's';
             buffer->(at+1) = 'u';
             buffer->(at+2) = 'r';
             buffer->(at+3) = '-'; ! contrairement à 'lui', '-lui' peut être féminin !*! mais pas pluriel...
             buffer->(at+4) = 'l';
             buffer->(at+5) = 'u';
             buffer->(at+6) = 'i';
             Tokenise__(buffer,parse);
             i = -1; continue; ! on reprend la passe au début de la phrase
         }
         if (word == 'dessous')
         {   LTI_Insert(at, ' '); ! remplace
             buffer->at     = 's';
             buffer->(at+1) = 'o';
             buffer->(at+2) = 'u';
             buffer->(at+3) = 's';
             buffer->(at+4) = '-'; ! contrairement à 'lui', '-lui' peut être féminin !*! mais pas pluriel...
             buffer->(at+5) = 'l';
             buffer->(at+6) = 'u';
             buffer->(at+7) = 'i';
             Tokenise__(buffer,parse);
             i = -1; continue; ! on reprend la passe au début de la phrase
         }
!*! pas forcément une bonne idée car "dedans" est aussi une direction !*! mais "mets-le dedans" ?
!         if (word == 'dedans') !*! dehors ?
!         {   LTI_Insert(at, ' '); ! remplace
!             LTI_Insert(at, ' ');
!             buffer->at     = 'd';
!             buffer->(at+1) = 'a';
!             buffer->(at+2) = 'n';
!             buffer->(at+3) = 's';
!             buffer->(at+4) = ' ';
!             buffer->(at+5) = 'l';
!             buffer->(at+6) = 'u';
!             buffer->(at+7) = 'y';
!             Tokenise__(buffer,parse);
!             i = -1; continue; ! on reprend la passe au début de la phrase
!         }

         ! "nord-est" ou "nord est" devient "nordest"
         if ( (word=='nord-est'or'nord-ouest') || ((word=='nord')&&(wordsuiv=='est'or'ouest')) )
         {
             buffer->at     = ' '; ! décale
             buffer->(at+1) = 'n';
             buffer->(at+2) = 'o';
             buffer->(at+3) = 'r';
             buffer->(at+4) = 'd';
             Tokenise__(buffer,parse);
             i = -1; continue; ! on reprend la passe au début de la phrase
         }
         ! "sud-est" ou "sud est" devient "sudest"
         if ( (word=='sud-est'or'sud-ouest') || ((word=='sud')&&(wordsuiv=='est'or'ouest')) )
         {
             buffer->at     = ' '; ! décale
             buffer->(at+1) = 's';
             buffer->(at+2) = 'u';
             buffer->(at+3) = 'd';
             Tokenise__(buffer,parse);
             i = -1; continue; ! on reprend la passe au début de la phrase
         }
     }

    !  insertion d'un espace avant chaque tiret et après chaque apostrophe
    for (i=WORDSIZE:i<WORDSIZE+NbChars():i++) {
        if (buffer->i == '-') LTI_Insert(i++, ' ');
        if (buffer->i == ''') LTI_Insert(++i, ' '); ! ''' !*! autre notation ? '\'' par exemple ?
    }
    Tokenise__(buffer,parse);

    ! Suppression de 'je' ou 'j^' en début de phrase.
    ! Par exemple, "je vais au nord" devient "vais au nord".
    if (Mot(0) == 'je' or 'j^') {
        EcraseMot(0);
        Tokenise__(buffer,parse);
    }

    !*! ce qui suit ne tient pas bien compte des commandes s'adressant à quelqu'un ("machin, fais ceci")
    ! Transformation de phrases à l'infinitif commençant par un ou deux pronoms suivis d'un mot (verbe, probablement)
    ! Ex : "le lui donner" devient "donner -le -lui"
    ! Etape A : "le/la/l'/les" (suivi éventuellement de "lui/leur") passe après le verbe. Ex : "lui donner -le"
    word=Mot(0); ! 1er mot
    if ((NbMots()>=2)&&(Mot(1)=='lui'or'leur')) RangVerbe=2; else RangVerbe=1; ! verbe = 2e ou 3e mot ?
    b=PositionMot(RangVerbe)+LongueurMot(RangVerbe); ! juste après le verbe = position du verbe + longueur du verbe
    if (~~DernierMot(RangVerbe-1)) { ! ne rien faire si la phrase ne comporte pas de verbe
        if (word == 'le')
        {
            EcraseMot(0);
            LTI_Insert(b, ' ');
            LTI_Insert(b+1, '-');
            LTI_Insert(b+2, 'l');
            LTI_Insert(b+3, 'e');
        }
        if (word == 'la')
        {
            EcraseMot(0);
            LTI_Insert(b, ' ');
            LTI_Insert(b+1, '-');
            LTI_Insert(b+2, 'l');
            LTI_Insert(b+3, 'a');
        }
        if (word == 'l^' or 'y//') ! exemple : "y aller" !*! 'y' à déplacer ?
        {
            EcraseMot(0); !*! imprécision : en fait 'l^' est équivalent à '-le' ou '-la'
            LTI_Insert(b, ' '); ! '-lui' est masculin ou féminin
            LTI_Insert(b+1, '-');
            LTI_Insert(b+2, 'l'); !*! 'y' donne '-y' ? et 'en' ?
            LTI_Insert(b+3, 'u');
            LTI_Insert(b+4, 'i');
        }
        if (word == 'les')
        {
            EcraseMot(0);
            LTI_Insert(b, ' ');
            LTI_Insert(b+1, '-');
            LTI_Insert(b+2, 'l');
            LTI_Insert(b+3, 'e');
            LTI_Insert(b+4, 's');
        }
    }
    Tokenise__(buffer,parse);

    ! Etape B : "lui/leur" passe après le verbe. Ex : "lui donner -le" devient "donner -le -lui"
    word=Mot(0); ! 1er mot
    ! RangDernier est le rang du dernier mot du bloc : verbe + "-le/-la/-les"
    if ((NbMots()>=3)&&(Mot(2)=='-le'or'-la'or'-les' or'-lui')) RangDernier=2; else RangDernier=1; ! "-le/-la/-les" après le verbe ?
    b=PositionMot(RangDernier)+LongueurMot(RangDernier); ! juste après bloc = position du dernier + longueur du dernier
    if (~~DernierMot(0)) { ! ne rien faire si la phrase ne comporte pas de verbe
        if (word == 'lui')
        {
            EcraseMot(0);
            LTI_Insert(b, ' ');
            LTI_Insert(b+1, '-');
            LTI_Insert(b+2, 'l');
            LTI_Insert(b+3, 'u');
            LTI_Insert(b+4, 'i');
        }
        if (word == 'leur')
        {
            EcraseMot(0);
            LTI_Insert(b, ' ');
            LTI_Insert(b+1, '-');
            LTI_Insert(b+2, 'l');
            LTI_Insert(b+3, 'e');
            LTI_Insert(b+4, 'u');
            LTI_Insert(b+5, 'r');
        }
    }
    Tokenise__(buffer,parse);

    if ( (word == 'me' or 'm^' or 'te' or 't^' or 'se' or 's^' or 'nous' or 'vous')
            && ~~DernierMot(0) ) ! sinon gènerait "se", abréviation de "sud-est"
    {
        EcraseMot(0);
        LTI_Insert(b, ' ');
        LTI_Insert(b+1, 'v');
        LTI_Insert(b+2, 'o');
        LTI_Insert(b+3, 'u');
        LTI_Insert(b+4, 's');
    }
    Tokenise__(buffer,parse);

    ! maintenant que les traitements sur l'infinitif ont été faits,
    ! enlever le tiret en début de mot pour ceux qui n'existent pas dans le dictionnaire
    ! (conserve '-lui','-le','-la'... et les mots prévus par le joueur)
    enleve_tirets();

    ! Avertir ceux qui oublient de mettre des traits d'union entre les pronons et le verbe
    ! à l'impératif et corriger les cas les plus simples : !*! le plus possible
    if ( ((NbMots()==2)&&(Mot(1)=='le'or'la'or'les'or'lui'or'leur')) || ! "parle lui" devient "parle-lui"
            ((NbMots()>=2)&&(Mot(1)=='lui')) || ! "donne lui la pomme" devient "donne-lui la pomme" (pas de confusion possible avec l'article)
            ((NbMots()>=4)&&(Mot(1)=='le'or'la'or'les'or'lui'or'leur')&&(Mot(2)=='a//'or'au'or'aux'or'de'or'du'or'des'or'dans'or'sur')) ) ! "donne le aux moutons" devient "donne-le aux moutons"
    {
        LTI_Insert(PositionMot(1), '-');
        print "[N'oubliez pas de mettre un trait d'union entre le pronom et le verbe à l'impératif.]^";
    }
    if ((NbMots()==3)&&(Mot(1)=='le'or'la'or'les'or'-le'or'-la'or'-les')&&(Mot(2)=='lui'or'leur')) { ! "donne le lui" ou "donne-le lui" devient "donne-le-lui"
        if (Mot(1)=='le'or'la'or'les') LTI_Insert(PositionMot(1), '-');
        LTI_Insert(PositionMot(2), '-');
        print "[N'oubliez pas de mettre un trait d'union entre chaque pronom et le verbe à l'impératif.]^";
    }

    ! remplacer "toi/vous/nous" en 2e position par "vous"
    if ((Mot(1) == 'moi' or 'toi' or 'nous')) !*! pas sûr encore, sert à gérer "réveillons nous" -> "réveillons vous"
    {
        EcraseMot(1); !*! fiable mais le buffer est agrandi de 3 ou 4 caractères : pas grave ?
        LTI_Insert(PositionMot(1)  , 'v');
        LTI_Insert(PositionMot(1)+1, 'o');
        LTI_Insert(PositionMot(1)+2, 'u');
        LTI_Insert(PositionMot(1)+3, 's');
    }

    Tokenise__(buffer,parse);

    #Ifdef DEBUG; affiche_buffer(buffer, "* Buffer traduit en informese : "); #Endif;
];

#Ifdef DEBUG;
[ affiche_buffer buffer msg i len;
    if (parser_trace>=7)
    {
#Ifdef TARGET_ZCODE;
        len=buffer->1;
#Ifnot; ! TARGET_GLULX
        len=buffer-->0;
#Endif; ! TARGET_
        print (string) msg,"|";
              for(i=WORDSIZE:i<WORDSIZE+len:i++) print (char) buffer->i;
        print "|^";
    }
];
#Endif;

! ------------------------------------------------------------------------------
!   Part IV.   Printing
! ------------------------------------------------------------------------------

Constant LanguageAnimateGender   = male;
Constant LanguageInanimateGender = male;

Constant LanguageContractionForms = 2;     ! French has two:
                                           ! 0 = starting with a consonant
                                           ! 1 = starting with a vowel
                                           !     or mute h
[ LanguageContraction text;
    if (IsAnA(text->0) || IsAnE(text->0) || IsAnI(text->0) || IsAnO(text->0) || IsAnU(text->0) || text->0 == 'h' or 'H') return 1;
    return 0;
];

Array LanguageArticles -->

 !   Contraction form 0:     Contraction form 1:
 !   Cdef   Def    Indef     Cdef   Def    Indef

     "Le "  "le "  "un "     "L'"   "l'"   "un "          ! 0: masc sing
     "La "  "la "  "une "    "L'"   "l'"   "une "         ! 1: fem sing
     "Les " "les " "des "    "Les " "les " "des ";        ! 2: plural

                   !             a           i
                   !             s     p     s     p
                   !             m f n m f n m f n m f n

Array LanguageGNAsToArticles --> 0 1 0 2 2 2 0 1 0 2 2 2;

[ LanguageDirection d;
    switch(d)
    {
        n_to: print "nord";
        s_to: print "sud";
        e_to: print "est";
        w_to: print "ouest";
        ne_to: print "nord-est";
        nw_to: print "nord-ouest";
        se_to: print "sud-est";
        sw_to: print "sud-ouest";
        u_to: print "haut";
        d_to: print "bas";
        in_to: print "dedans";
        out_to: print "dehors";
        default: return RunTimeError(9,d);
    }
];

[ LanguageNumber n s f;
    ! L'argument "s" sert à spécifier si on n'est pas en train de construire la fin du nombre(c-à-d les 3 derniers chiffres). Si s == 1, alors on est à l'intérieur du nombre et on ne peut pas ajouter un "s" à "cent" et à "quatre-vingt".
    if (n == 0)    { print "zéro"; rfalse; }
    if (n < 0)     { print "moins "; n = -n; }
    #Iftrue (WORDSIZE == 4);
    if (n >= 1000000000)
    {
        LanguageNumber(n/1000000000, 1); print " ";
        print "milliard";
        if (n/1000000000 > 1) { print "s"; }
        f = 1;
        n = n%1000000000;
    }
    if (n >= 1000000)
    {
        if (f == 1) { print " "; }
        LanguageNumber(n/1000000, 1); print " ";
        print "million";
        if (n/1000000 > 1) { print "s"; }
        f = 1;
        n = n%1000000;
    }
    #Endif;
    if (n >= 1000)
    {
        if (f == 1) { print " "; }
        if (n/1000 ~= 1) { LanguageNumber(n/1000, 1); print " "; }
        print "mille";
        f = 1;
        n = n%1000;
    }
    if (n >= 100)
    {
        if (f == 1) { print " "; }
        if (n/100 ~= 1) { LanguageNumber(n/100); print " "; }
        print "cent";
        if (n%100 == 0 && n/100 > 1 && s == 0) {print "s"; }
        f = 1;
        n = n%100;
    }
    if (n >= 20)
    {
        if (f == 1) { print " "; }
        switch(n/10)
        {
        2: print "vingt";
        3: print "trente";
        4: print "quarante";
        5: print "cinquante";
        6: print "soixante";
        7: print "soixante";
             if (n == 71) { print " et onze"; return; }
        8: print "quatre-vingt"; if (n == 80 && s == 0) { print "s"; } if (n == 81) { print "-un"; return; }
        9: print "quatre-vingt";
        }
        if (n%10 == 1) { print " et "; }
        if (n%10 > 1) { print "-"; }
        n = n%10;
        f=0;
    }
    if (f == 1) { print " "; }
    ! Attention, il faut skipper le "une" dans la table !
    ! ("une" est là à cause de NumberWord, qui doit la reconnaître comme 1 ; par contre on aurait pu considérer la bouger à la fin de la table, mais bon)
    if (n == 1) { print "un"; } else { print (address) LanguageNumbers-->(2*n+1); }
    return;
];


[ LanguageTimeOfDay hours mins;
    print hours/10, hours%10, "h", mins/10, mins%10;
];

! Cette routine est utilisée par PrintCommand, qui affiche la commande tapée par le joueur
!            ("Je n'ai compris que : XXX")
[ LanguageVerb i;
    switch (i) {
      'i//','inv','inventaire':
               print "afficher l'inventaire";
      'r//':   print "regarder";
      'x//':   print "examiner";
      'z//':   print "attendre";
      'v//':   print "regarder";
      'a//':   print "attendre";
      '!//':   print "dire";
      '?//':   print "demander";
      'q//':   print "quitter";
      'pr':    print "prendre";
      ! Les mots du dictionnaire d'Inform n'ont que 9 lettres au maximum
      !    Il faut donc indiquer comment afficher un verbe à 10 lettres ou plus
      'verrouiller':	print "verrouiller";
      'deverrouiller':	print "déverrouiller";
      'introduire':	print "introduire";
      'transferer':	print "transférer";
      'abandonner':	print "abandonner";
      'farfouiller':	print "farfouiller";
      'depoussierer':	print "dépoussierer";
      'questionner':	print "questionner";
      'interroger':	print "interroger";
      ! On n'écrit pas les accents dans un verbe pour plus de facilité pour le joueur (cf enleve_accents)
      !    Il faut donc réécrire les accents pour les verbes qui en ont besoin
      'inserer':	print "insérer";
      'transferer':	print "transférer";
      'decoller': 	print "décoller";
      'lacher': 	print "lâcher";
      'oter': 		print "ôter";
      'revetir': 	print "revêtir";
      'vetir':		print "vêtir";
      'deguiser':	print "déguiser";
      'devorer':	print "dévorer";
      'bruler':		print "brûler";
      'detruire':	print "détruire";
      'ecraser':	print "écraser";
      'elaguer':	print "élaguer";
      'decrire':	print "décrire";
      'ecouter':	print "écouter";
      'gouter':		print "goûter";
      'tater':		print "tâter";
      'trainer':	print "traîner";
      'deplacer':	print "déplacer";
      'regler':		print "régler";
      'devisser':	print "dévisser";
      'eteindre':	print "éteindre";
      'arreter':	print "arrêter";
      'demarrer':	print "démarrer";
      'recurer':	print "récurer";
      'repondre':	print "répondre";
      'reveiller':	print "réveiller";
      'eveiller':	print "éveiller";
      'etreindre':	print "étreindre";
      'reflechir':	print "réfléchir";
      ! y'a pas que les verbes qui sont accentués !
      'a':		print "à";
      'derriere':	print "derrière";
      'cle':		print "clé";
      default: rfalse;
    }
    rtrue;
];

! ----------------------------------------------------------------------------
!  LanguageVerbIsDebugging is called by SearchScope.  It should return true
!  if word w is a debugging verb which needs all objects to be in scope.
! ----------------------------------------------------------------------------

#Ifdef DEBUG;
[ LanguageVerbIsDebugging w;
    if (w == 'purloin' or 'tree' or 'abstract'
                       or 'gonear' or 'scope' or 'showobj')
        rtrue;
    rfalse;
];
#Endif;

! ----------------------------------------------------------------------------
!  LanguageVerbLikesAdverb is called by PrintCommand when printing an UPTO_PE
!  error or an inference message.  Words which are intransitive verbs, i.e.,
!  which require a direction name as an adverb ('walk west'), not a noun
!  ('I only understood you as far as wanting to touch /the/ ground'), should
!  cause the routine to return true.
! ----------------------------------------------------------------------------
!*!
[ LanguageVerbLikesAdverb w;
    if (w == 'look' or 'go' or 'push' or 'walk')
        rtrue;
    rfalse;
];

! ----------------------------------------------------------------------------
!  LanguageVerbMayBeName is called by NounDomain when dealing with the
!  player's reply to a "Which do you mean, the short stick or the long
!  stick?" prompt from the parser. If the reply is another verb (for example,
!  LOOK) then then previous ambiguous command is discarded /unless/
!  it is one of these words which could be both a verb /and/ an
!  adjective in a 'name' property.
! ----------------------------------------------------------------------------
!*!
[ LanguageVerbMayBeName w;
    if (w == 'long' or 'short' or 'normal'
                    or 'brief' or 'full' or 'verbose')
        rtrue;
    rfalse;
];

Constant NKEY__TX     = "S = suivant";
Constant PKEY__TX     = "P = précédent";
Constant QKEY1__TX    = "        Q = retour"; !huit espaces pour aligner à droite
Constant QKEY2__TX    = "Q = menu précédent";
Constant RKEY__TX     = "ENTRÉE = lire sujet";

Constant NKEY1__KY    = 'S';
Constant NKEY2__KY    = 's';
Constant PKEY1__KY    = 'P';
Constant PKEY2__KY    = 'p';
Constant QKEY1__KY    = 'Q';
Constant QKEY2__KY    = 'q';

Constant SCORE__TX    = "Score : ";
Constant MOVES__TX    = "Tours : ";
Constant TIME__TX     = "Heure : ";
Constant CANTGO__TX   = "Vous ne pouvez pas aller dans cette direction.";
Constant FORMER__TX   = "votre ancien vous";
Constant YOURSELF__TX = "vous-même";
Constant YOU__TX      = "Vous";
Constant DARKNESS__TX = "L'obscurité";

Constant THOSET__TX   = "ces choses-là";
Constant THAT__TX     = "cela";
Constant OR__TX       = " ou ";
Constant NOTHING__TX  = "rien";
! Potentiellement utilisés par WriteListFrom (bit ISARE_BIT), mais pas dans la bibli française
Constant IS__TX       = " se trouve";  ! Constant IS__TX       = "est ";   ! ancienne version
Constant ARE__TX      = " se trouvent";  ! Constant ARE__TX      = "sont ";  ! ancienne version
! Ne pas changer ceux-là, ils sont utilisés dans WriteAfterEntry, qui liste l'inventaire notamment
!      (et sont déjà bien faits, cf ListMiscellany plus bas)
Constant IS2__TX      = "";  ! dans/sur lequel " est"  => contenant/supportant
Constant ARE2__TX     = "";  ! dans/sur lequel " sont" => contenant/supportant
Constant AND__TX      = " et ";
Constant WHOM__TX     = "";  ! dans/sur "lequel " est  => contenant/supportant
Constant WHICH__TX    = "";  ! dans/sur "lequel " est  => contenant/supportant
Constant COMMA__TX      = ", ";


![ ThatorThose obj;   ! ex : vous n'allez pas manger ça (accusatif) (utile ?)
!  print "ça";
!];
[ ItorThem obj; ! ex : avant de pouvoir vous/le/la/les poser... (accusatif ?)
    if (obj == player) { print "vous"; return; }
    if (obj has pluralname)  { print "les"; return;}
    if (obj has female) { print "la"; return; }
    else { print "le"; return; }
];

[ IsorAre obj;
    if (obj has pluralname) print "sont";
    else {
         if (obj == player) print "êtes";
         else print "est";
    }
];
[ IsorAreNot obj;
    if (obj has pluralname) print "ne sont pas";
    else {
         if (obj == player) print "n'êtes pas";
         else print "n'est pas";
    }
];

[ CThatorThose obj;   ! il/ils/elle/elles semble(nt) ouvert(e) (nominatif)
    ! if (obj == player) { print "Vous"; return; } !*! utile ?
    if (obj has pluralname) {
        if (obj has female) {print "Elles"; return; }
        else { print "Ils"; return; }
    }
    if (obj has female) { print "Elle"; return; }
    else { print "Il"; return; }
    ];
[ CTheyreorThats obj;
    if (obj == player) { print "Vous êtes"; return; }
    if (obj has pluralname) {
        if (obj has female) { print "Elles sont"; return; }
        else { print "Ils sont"; return; }
    }
    if (obj has female) { print "Elle est"; return; }
    else { print "Il est"; return; }
];

! Quelques fonctions additionnelles...
[ es obj; ! ex: fermé(es), ouvert(es)
    if (obj has female) print "e";
    if (obj has pluralname) print "s";
    !*! attention : pris, prise, pris, prises
];
[ s obj; ! ex: vide(s)
    if (obj has pluralname) print "s";
];
[ DeDuDes obj; ! ex : descendre... sortir...
    if (obj == player) { print "de vous"; return; }
    if (obj has pluralname)  { print "des ", (name) obj; return;}
    if (obj has female or proper) { print "de ", (the) obj; return;} ! ex : de la voiture, de Paris
    !*! test ci-dessous à effectuer avec @output_stream (ZCode) et avec PrintAnyToArray (Glulx) ?
    ! if ((the)obj="l'...") {print "de ", (the) obj; return;} ! ex : de l'avion
    print "du ", (name) obj; return; ! ex : du train, du Nautilus (le Nautilus ne doit donc pas être considéré comme proper !*!)
];
! (Stormi) Cette fonction permet d'afficher correctement "à la" "à l'" "au" ou "aux"
! selon le contexte.
[ to_the obj;
    if (obj has pluralname) {
        print "aux ", (name) obj;
    }
    else if (obj has proper) {
        print "à ", (name) obj;
    }
    else {
        ! Les lignes qui suivent sont copiées de la fonction PrefaceByArticle de parserm.h
        ! afin de connaître la valeur de LanguageContraction pour le nom affiché de l'objet
        ! Je suis le seul à trouver cela atrocement compliqué ?
#ifdef TARGET_ZCODE;
        StorageForShortName-->0 = 160;
        @output_stream 3 StorageForShortName;
        print (PSN__) noun;
        @output_stream -3;
        if (obj has male && LanguageContraction(StorageForShortName + 2)==0) {
             print "au ", (name) obj;
        }
        else {
            print "à ", (the) obj;
        }
#ifnot; ! TARGET_GLULX;
		print "à quelqu'un : ", (name) obj;
#endif;
    }
];
[ nt obj; ! ex: semble(nt)
    if (obj has pluralname) print "nt";
    !*! attention :  paraît, paraissent (etc)
];

[ LanguageLM n x1;
    Answer, Ask:    "Pas de réponse.";
!    Ask:      see Answer
    Attack:         "La violence n'est pas une solution ici.";
    Blow:           "Vous ne pouvez pas utilement souffler dedans.";
    Burn:           "Cet acte dangereux ne mènerait pas à grand-chose.";
    Buy:            print (The) x1;
                    if (x1 has pluralname) print " ne sont ";
                    else print " n'est ";
                    "pas à vendre.";
    Climb:          "Je ne pense pas que l'on puisse arriver à grand-chose de cette manière.";
    Close: switch (n) {
        1:  "Vous ne pouvez pas fermer cela.";
        2:  print (ctheyreorthats) x1, " déjà fermé";
            if (x1 has female) "e.";
            ".";
        3:  "Vous fermez ", (the) x1, ".";
    }
    CommandsOff: switch (n) {
        1:  "[Enregistrement des commandes désactivé.]";
        #Ifdef TARGET_GLULX;
        2:  "[Enregistrement des commandes déjà désactivé.]";
        #Endif; ! TARGET_
    }
    CommandsOn: switch (n) {
        1:  "[Enregistrement des commandes activé.]";
        #Ifdef TARGET_GLULX;
        2:  "[Les commandes sont actuellement en train d'être rejouées.]";
        3:  "[Enregistrement des commandes déjà activé.]";
        4:  "[Echec d'enregistrement des commandes.]";
        #Endif; ! TARGET_
    }
    CommandsRead: switch (n) {
        1:  "[Rejouer les commandes.]";
        #Ifdef TARGET_GLULX;
        2:  "[Les commandes sont déjà en train d'être rejouées.]";
        3:  "[Rejouer les commandes a échoué.  L'enregistrement des commandes est activé.]";
        4:  "[Rejouer les commandes a échoué.]";
        5:  "[Rejouer les commandes achevé.]";
        #Endif; ! TARGET_
    }
!    Consult:        "Vous ne découvrez rien d'intéressant dans ", (the) x1, ".";
    Consult:        if (x1 has animate || x1 has talkable) {
                        if (x1 has pluralname) print (The) x1, " ne sont pas consultables de cette manière.^";
                        else print (The) x1, " n'est pas consultable de cette manière.^";
                    }
                    else {
                        print "Vous ne découvrez rien. Soit ", (the) x1;
                        if (x1 has pluralname) print " ne sont pas consultables ";
                        else print " n'est pas consultable ";
                        "ainsi, soit vous tentez de consulter sur le mauvais sujet.";
                    }
    CrierSansPrecision : "Cela ne mènerait à rien.";
    Cut:            "Allons, couper ", (the) x1, " ne mènerait pas à grand-chose.";
    Dig:            if (noun==0) "Creuser ne mènerait à rien ici.";
                    else "Creuser cela ne mènerait à rien.";
    Disrobe: switch (n) {
        1:  "Vous ne ", (itorthem) x1, " portez pas.";
        2:  "Vous enlevez ", (the) x1, ".";
    }
    Drink:          "Ceci n'a rien de buvable.";
    Drop: switch (n) {
        1:  if (x1 has pluralname) print (The) x1, " sont ";
            else print (The) x1, " est ";
            "déjà ici.";
        2:  "Vous n'avez pas cela sur vous.";
        3: "(vous prenez d'abord ", (the) x1, ")";
        4:  "D'accord."; ! ok
    }
    Eat: switch (n) {
        1:  print_ret (The) x1, " ", (isorare) x1,
            " non comestible",(s) x1,", selon toute évidence.";
        2:  "Vous mangez ", (the) x1, ". Pas mauvais.";
    }
    EmptyT: switch (n) {
        1:  if (x1==player) print_ret "En voilà une idée.";
            print (The) x1;
            if (x1 has pluralname) print " ne sont pas ";
            else print " n'est pas ";
            print_ret "un récipient que l'on peut vider.";
        2:  print_ret (The) x1, " ", (isorare) x1, " fermé",(es) x1,".";
        3:  print_ret (The) x1, " ", (isorare) x1, " déjà vide",(s) x1,".";
        4:  "Ceci ne viderait rien.";
    }
    Enter: switch (n) {
        1:  print "Vous êtes déjà ";
            if (x1 has supporter) print "sur "; else print "dans ";
            print_ret (the) x1, ".";
        2:  print "Vous ne pouvez pas ";
            switch (verb_word) {
                'entrer':    "y entrer.";
                'asseoir':    "vous y asseoir.";
                'allonger':    "vous y allonger.";
                'coucher':    "vous y coucher.";
                'monter':    "y monter.";
                default:  "y aller."; ! plutôt que "y entrer." !*!
            }
        3:  "Vous ne pouvez entrer dans ", (the) x1, " fermé",(es) x1,".";
        4:  print "Vous ne pouvez pas ";
            if (x1 has supporter) print "y monter";
                             else print "y entrer";
            " si ce n'est pas posé.";
                        ! sur pieds, non encastré (freestanding)
        5:  print "Vous ";
            if (x1 has supporter) print "montez sur "; else print "entrez dans ";
            print_ret (the) x1, ".";
        6:  print "(";
            if (x1 has supporter) print "descendant "; else print "sortant ";
            print (DeDuDes) x1; ")";
        7:  if (x1 has supporter) "(montant sur ", (the) x1, ")^";
            if (x1 has container) "(entrant dans ", (the) x1, ")^";
            "(entrant dans ", (the) x1, ")^";
    }
    Examine: switch (n) {
        1:  "Vous ne pouvez rien voir.";
        2:  "Rien de particulier concernant ", (the) x1, ".";
        3:  print (The) x1, " ", (isorare) x1, " actuellement ";
            if (x1 has on) "allumé",(es) x1,"."; else "éteint",(es) x1,".";
    }
    Exit: switch (n) {
        1:  "Vous n'êtes à l'intérieur de rien pour le moment.";
        2:  print "Vous ne pouvez pas sortir ";
            print_ret (dedudes) x1, " fermé", (es) x1, ".";
        3:  print "Vous ";
            if (x1 has supporter) print "descendez "; else print "sortez ";
            print_ret (dedudes) x1, ".";
        4:  print "Vous n'êtes pas ";
            if (x1 has supporter) print "sur "; else print "dans ";
            print_ret (the) x1, ".";
    }
    Fill:   "Cela ne vous avancerait pas.";
    FullScore: switch(n) {
        1:  if (deadflag) print "Le score était ";
            else          print "Le score est ";
            "composé comme suit :^";
        2:  "trouver divers objets";
        3:  "visiter différents endroits";
        4:  print "total (sur ", MAX_SCORE; ")";
    }
    GetOff:         "Vous n'êtes pas sur ", (the) x1, " en ce moment.";
    Give: switch (n) {
        1:  "Vous n'avez pas en main ", (the) x1, ".";
        2:  "Vous vous remerciez pour ce cadeau.";
        3:  print (The) x1;
            if (x1 has pluralname)
                print " n'ont pas l'air intéressé";
            else print " n'a pas l'air intéressé";
            ".";
    }
    Go: switch (n) {
        1:  print "Vous devez d'abord ";
            if (x1 has supporter) print "descendre "; else print "sortir ";
            print_ret (dedudes) x1, ".";
        2:  "Vous ne pouvez pas aller par là.";
        3:  "Vous êtes incapable de gravir ", (the) x1, ".";
        4:  "Vous êtes incapable de descendre par ", (the) x1, ".";
        5:  "Vous ne pouvez pas, puisque ", (the) x1, " ", (isorare) x1,
            " sur votre chemin.";
        6:  print "Vous ne pouvez pas, puisque ", (the) x1;
            if (x1 has pluralname) " ne mènent nulle part.";
            " ne mène nulle part.";
    }
    Insert: switch (n) {
        1:  "Vous devez avoir en main ", (the) x1,
            " avant de pouvoir ", (itorthem) x1,
            " mettre dans autre chose.";
        2:  if (x1 has pluralname)
            print_ret (The) x1, " ne peuvent pas contenir d'objet.";
            else
            print_ret (The) x1, " ne peut pas contenir d'objet.";
        3:  print_ret (The) x1, " ", (isorare) x1, " fermé",(es) x1,".";
        4:  "Vous avez besoin de ", (itorthem) x1, " prendre d'abord.";
        5:  "Vous ne pouvez pas mettre un objet à l'intérieur de lui-même.";
        6:  "(vous ", (itorthem) x1, " prenez d'abord)^";
        7:  "Il n'y a plus de place dans ", (the) x1, ".";
        8:  "D'accord.";
        9:  "Vous mettez ", (the) x1, " dans ", (the) second, ".";
    }
    Inv: switch (n) {
        1:  "Vous n'avez rien.";
        2:  print "Vous avez";
        3:  print " :^";
        4:  print ".^";
    }
    Jump:           "Sauter sur place ne vous avancerait en rien.";
    JumpOver:       "Vous n'arriverez à rien comme ça.";
    Kiss:           "Concentrez-vous sur le jeu.";
    Listen:
        if (x1 == 0) "Vous n'entendez rien de particulier.";
        else print_ret (The) x1, "ne semble", (nt) x1, " pas produire de son particulier.";
    ListMiscellany: switch (n) {
         1: print " (allumé",(es) x1,")";
         2: print " (qui ", (isorare) x1, " fermé",(es) x1,")";
         3: print " (fermé",(es) x1," et allumé",(es) x1,")";
         4: print " (qui ", (isorare) x1, " vide",(s) x1,")";
         5: print " (vide",(s) x1," et allumé",(es) x1,")";
         6: print " (qui ", (isorare) x1, " fermé",(es) x1," et vide",(s) x1,")";
         7: print " (fermé",(es) x1,", vide",(s) x1," et allumé",(es) x1,")";
         8: print " (allumé",(es) x1," et porté",(es) x1;
         9: print " (allumé",(es) x1;
        10: print " (porté",(es) x1;
        11: print " (qui ", (isorare) x1, " ";
        12: print "ouvert",(es) x1;
        13: print "ouvert",(es) x1," mais vide",(s) x1;
        14: print "fermé",(es) x1;
        15: print "fermé",(es) x1," et verrouillé",(es) x1;
        16: print " et vide",(s) x1;
        17: print " (qui ", (isorare) x1, " vide",(s) x1,")";
        18: print " contenant ";
        19: print " (supportant "; ! " (sur ";
        20: print " supportant ";  ! " sur ";
        21: print " (contenant ";  ! " (dans ";
        22: print " contenant ";   ! " dans ";
    }
    LMode1:         " est passé en mode description normale ; seuls les lieux
                      visités pour la première fois sont décrits en détail.";
    LMode2:         " est passé en mode description longue ; tous les lieux,
                      même déjà visités, sont décrits en détail.";
    LMode3:         " est passé en mode description courte ; tous les lieux,
                      même non visités, sont décrits brièvement.";
    Lock: switch (n) {
        1:  "Vous ne pouvez pas verrouiller cela.";
        2:  print_ret (ctheyreorthats) x1, " verrouillé en ce moment.";
        3:  "Vous devez fermer ", (the) x1, " d'abord.";
        4:  "Cela ne rentre pas dans la serrure.";
        5:  "Vous verrouillez ", (the) x1, ".";
    }
    Look: switch (n) {
        1:  print " (sur ", (the) x1, ")";
        2:  print " (dans ", (the) x1, ")";
        3:  print " (comme ", (object) x1, ")";
        4:  print "^Sur ", (the) x1, ", ";
            WriteListFrom(child(x1),
                ENGLISH_BIT + RECURSE_BIT + PARTINV_BIT
                + TERSE_BIT + CONCEAL_BIT);
            ".";
        5,6:
            if (x1 ~= location) {
                if (x1 has supporter) print "^Sur "; else print "^Dans ";
                print (the) x1, " vous";
            }
            else print "^Vous";
            print " pouvez voir ";
            if (n == 5) print "aussi ";
            WriteListFrom(child(x1),
              ENGLISH_BIT+RECURSE_BIT+PARTINV_BIT+TERSE_BIT+CONCEAL_BIT+WORKFLAG_BIT);
            ".";
        7:  "Vous ne voyez rien de particulier dans cette direction.";
    }
    LookUnder: switch (n) {
        1:  "Vous n'y voyez rien dans le noir.";
        2:  "Votre action ne produit aucune découverte notable.";
    }
    Mild:           "Assez.";
    Miscellany: switch (n) {
        1:  "(affichage des seize premiers)^";
        2:  "Il n'y a rien à faire.";
        3:  print " Vous avez perdu ";
        4:  print " Vous avez gagné ";
        5:  print "^Voulez-vous RECOMMENCER, CHARGER une partie sauvegardée";
            #IFDEF DEATH_MENTION_UNDO;
            print ", ANNULER votre dernière action";
            #ENDIF;
            if (TASKS_PROVIDED==0)
                print ", obtenir le score détaillé pour cette partie (FULLSCORE)";
            if (deadflag==2 && AMUSING_PROVIDED==0)
                print ", lire quelques suggestions amusantes (AMUSING)";
            " ou QUITTER ?"; !*!
        6:  "[Votre interpréteur ne permet pas d'@<< annuler @>>. Désolé !]";
        #Ifdef TARGET_ZCODE;
        7:  "@<< Annuler @>> a échoué.  [Tous les interpréteurs ne le permettent pas.]";
        #Ifnot; ! TARGET_GLULX
        7:  "[Vous ne pouvez pas @<< Annuler @>> plus que cela.]";
        #Endif; ! TARGET_
        8:  "Faites un choix parmi les propositions ci-dessus.";
        9:  "^Vous êtes à présent dans le noir total.";
        10: "[Je vous demande pardon ?]";
        11: "[Vous ne pouvez pas annuler alors que rien n'a encore été fait.]";
        12: "[Impossible d'annuler deux fois de suite. Désolé !]";
        13: "[Action précédente annulée.]";
        14: "[Désolé, impossible de corriger.]";
        15: "N'y pensez même pas."; !*! "Think nothing of it."; !*!
        16: "[@<< Oops @>> ne peut corriger qu'un seul mot.]";
        17: "Il fait noir, et vous ne pouvez rien voir.";
        18: print "vous-même";
        19: "Votre apparence est aussi agréable qu'à l'accoutumée.";
        20: "[Pour répéter une commande comme @<< grenouille, saute @>>, dites seulement
            @<< encore @>>, et pas @<< grenouille, encore @>>.]";
        21: "[Vous pouvez difficilement répéter cela.]";
        22: "[Vous ne pouvez pas commencer par une virgule.]";
        23: "[Vous semblez vouloir parler à quelqu'un, mais je ne vois pas à qui.]";
        24: "Vous ne pouvez pas discuter avec ", (the) x1, ".";
            ! "parler à" serait mieux mais délicat (ex: à l'oiseau)
        25: "[Pour parler à quelqu'un, essayez @<< quelqu'un, bonjour @>> ou quelque chose dans le genre.]";
        26: "(vous prenez d'abord ", (the) not_holding, ")";
        27: "[Je ne comprends pas cette phrase.]";
        28: print "Merci de reformuler. Je n'ai compris que : ";
        29: "[Je n'ai pas compris ce nombre.]";
        30: "Vous ne voyez rien de tel, à moins que cela ne soit sans grande importance.";
        31: "[Vous semblez en avoir dit trop peu.]";
        32: "Vous ne l'avez pas dans vos mains.";
        33: "[Vous ne pouvez pas employer le mot @<< tout @>> (ou une liste) avec ce verbe.]";
        34: "[Vous ne pouvez utiliser le mot @<< tout @>> (ou une liste) qu'une fois par ligne.]";
        35: "[Je ne suis pas sûr de ce à quoi @<< ", (address) pronoun_word,
            " @>> se réfère.]";
        36: "[Vous avez exclu quelque chose qui n'était de toute façon pas compris dans la liste.]";
        37: "[Vous ne pouvez agir ainsi qu'avec une chose animée.]";
        38: "[Je ne connais pas ce verbe.]";
        39: "[Ce n'est pas une chose à laquelle vous aurez à vous référer au cours du jeu.]";
        40: "Vous ne pouvez voir @<< ", (address) pronoun_word,
            " @>> (", (the) pronoun_obj, ") pour l'instant.";
        41: "Impossible de comprendre la fin de la phrase.";
        42: if (x1==0) print "Aucun de disponible.";
            else print "Il en reste seulement ", (number) x1, ".";
        43: "Il n'y a rien à faire.";
        44: "Rien n'est disponible.";
        45: print "[Précisez : "; !*!
        46: print "[Précisez : "; !*!
        47: "[Désolé, vous pouvez seulement avoir un objet ici. Lequel voulez-vous exactement ?]";
        48: print "[Pouvez-vous préciser qui est concerné par cette action ?]^"; !*!
        49: print "[Pouvez-vous préciser l'objet concerné par cette action, ou à utiliser ?]^"; !*!
        50: print "Votre score vient ";
            if (x1 > 0) print "d'augmenter"; else { x1 = -x1; print "de diminuer"; }
            print " de ", (number) x1, " point";
            if (x1 > 1) print "s";
        51: "(Comme quelque chose de dramatique vient de se produire,
            votre liste de commandes a été raccourcie.)";
        52: "^Tapez un nombre entre 1 et ", x1,
            ", 0 pour réafficher ou appuyez sur ENTRÉE.^";
        53: "^[Appuyez sur ESPACE.]"; !*! SVP
        54: "[Commentaire enregistré.]";
        55: "[Commentaire NON enregistré.]";
        56: print ".]^";  ! L__M 28
        57: print " ?]^"; ! L__M 45 et 46
    }
    Yes, No:        "Mmmh ?";
    NotifyOff:      "[Notification du score désactivée.]";
    NotifyOn:       "[Notification du score activée.]";
    Objects: switch(n) {
        1:  "Objets ayant été portés :^";
        2:  "Aucun.";
        3:  print "   (sur le corps)";
        4:  print "   (dans l'inventaire)";
        5:  print "   (abandonné",(es) x1,")";
        6:  print "   (", (name) x1, ")";
        7:  print "   (dans ", (the) x1, ")";
        8:  print "   (dans ", (the) x1, ")";
        9:  print "   (sur ", (the) x1, ")";
        10: print "   (perdu",(es) x1,")";
    }
    Open: switch (n) {
        1:  print_ret "Vous ne pouvez pas ouvrir ", (the) x1,".";
        2:  print_ret (cthatorthose) x1," semble",(nt) x1,
            " être fermé",(es) x1," à clé.";
        3:  print_ret (ctheyreorthats) x1, " déjà ouvert",(es) x1, ".";
        4:  print "Vous ouvrez ", (the) x1, ", révélant ";
            if (WriteListFrom(child(x1),
                ENGLISH_BIT + TERSE_BIT + CONCEAL_BIT)==0) "rien du tout.";
                ".";
        5:  "Vous ouvrez ", (the) x1, ".";
    }
    Order:  print (The) x1;
            if (x1 has pluralname) print " ont";
            else print " a";
            " mieux à faire.";
    ParlerIncorrect : "[Soyez plus précis dans votre communication, ou reformulez.]";
    ParlerSansPrecision :   if (x1==player) "Vous ne savez pas quoi vous dire que vous ne sachiez déjà.";
                            else "Pas de réponse.";
    Places: switch (n) {
        1:  print "Vous avez visité : ";
        2:  print ".^";
    }
    Pray:   "Rien de concret ne résulte de votre prière.";
    Prompt:   print "^>";
    Pronouns: switch (n) {
        1:  print "En ce moment, ";
        2:  print "signifie ";
        3:  print "n'est pas défini";
        4:  "aucun pronom n'est connu du jeu.";
        5:  ".";
    }
    Pull,Push,Turn: switch (n) {
        1:  "C'est fixé sur place.";
        2:  "Vous en êtes incapable.";
        3:  "Rien d'évident ne se produit.";
        4:  "Cela serait moins que courtois.";
    }
! Push: see Pull
    PushDir: switch (n) {
        1:  "Vous ne pouvez donc rien imaginer de mieux ?";
        2:  "[Ce n'est pas une direction.]";
        3:  "Vous ne pouvez pas dans cette direction.";
    }
    PutOn: switch (n) {
        1:  "Vous devez avoir en main ", (the) x1,
            " avant de pouvoir ", (itorthem) x1,
            " mettre sur quelque chose d'autre.";
        2:  "Vous ne pouvez pas poser un objet sur lui-même.";
        3:  "Poser des objets sur ", (the) x1, " ne mènerait à rien.";
        4:  "Vous manquez de dextérité.";
        5:  "(vous ", (itorthem) x1, " prenez d'abord)^";
        6:  "Il n'y a plus assez de place sur ", (the) x1, ".";
        7:  "C'est fait.";
        8:  "Vous mettez ", (the) x1, " sur ", (the) second, ".";
    }
    Quit: switch (n) {
        1:  print "Répondez par oui ou par non, je vous prie.";
        2:  print "Voulez-vous vraiment quitter ? (O/N) ";
    }
    Remove: switch (n) {
        1:  if (x1 has pluralname) {
		if (x1 has female) { "Elles sont malheureusement fermées."; }
		else { "Ils sont malheureusement fermés."; }
	    } else {
		if (x1 has female) { "Elle est malheureusement fermée."; }
		else { "Il est malheureusement fermé."; }
	    }
        2:  if (x1 has pluralname) {
		if (x1 has female) { print "Elles"; } else { print "Ils"; }
		print " n'y sont pas";
	    } else {
		print "Ça n'y est pas";
	    }
            ".";
        3:  "D'accord."; ! Ok
    }
    Restart: switch (n) {
        1: print "Voulez-vous vraiment recommencer ? (O/N) ";
        2: "Raté.";
    }
    Restore: switch (n) {
        1: "[Échec du chargement.]";
        2: "[La partie a bien été restaurée.]^"; ! ok.
    }
    Rub: if (x1 has animate) "Tenez donc vos mains tranquilles.";
         else "Vous n'arriverez à rien comme ça.";
    Save: switch (n) {
        1: "[La sauvegarde a échoué.]";
        2: "[La partie a bien été sauvegardée.]"; ! ok.
    }
    Score: switch (n) {
        1:  if (deadflag) print "Dans cette partie vous avez obtenu "; else print "Vous avez jusqu'à présent obtenu ";
            print score, " sur un score possible de ", MAX_SCORE, ", en ", turns, " tour";
            if (turns ~= 1) print "s";
            return;
        2:  "Il n'y a pas de score dans cette histoire.";
    }
    ScriptOff: switch (n) {
        1:  "[Aucune transcription en cours.]";
        2:  "^[Fin de transcription.]";
        3:  "[Impossible de terminer la transcription.]";
    }
    ScriptOn: switch (n) {
        1:  "[Transcription déjà en cours.]";
        2:  "Début d'une transcription de...";
        3:  "[Impossible de commencer la transcription.]";
    }
    Search: switch (n) {
        1:  "Vous n'y voyez rien dans le noir.";
        2:  "Il n'y a rien sur ", (the) x1, ".";
        3:  print "Sur ", (the) x1, ", vous voyez ";
            WriteListFrom(child(x1),
                TERSE_BIT + ENGLISH_BIT + CONCEAL_BIT);
            ".";
        4:  if (x1 has animate) "Tenez donc vos mains tranquilles.";
            else "Vous ne trouvez rien d'intéressant.";
        5:  "Vous ne pouvez pas voir à l'intérieur, puisque ", (the) x1, " ",
            (isorare) x1, " fermé",(es) x1,".";
        6:  print_ret (The) x1, " ", (isorare) x1, " vide",(s) x1,".";
        7:  print (The) x1;
            if (x1 has pluralname) print " contiennent ";
            else print " contient ";
            WriteListFrom(child(x1),
                TERSE_BIT + ENGLISH_BIT + CONCEAL_BIT);
            ".";
    }
    SeLever:        "Inutile.";
    Set:            "Non, vous ne pouvez pas ", (itorthem) x1, " régler.";
    SetTo:          "Non, vous ne pouvez ", (itorthem) x1, " régler sur rien.";
    Show: switch (n) {
        1:  "Vous n'avez pas ", (the) x1, ".";
        2:  print (The) x1;
            if (x1 has pluralname)
                print " n'ont pas l'air intéressé";
            else print " n'a pas l'air intéressé";
            ".";
    }
    Sing:           "Vous ne chantez pas si bien que ça, alors vous n'osez pas.";
    Sleep:          "Vous n'avez pas particulièrement sommeil.";
    Smell:
       if (x1 == 0) "Vous ne sentez rien de particulier.";
       else print_ret "Aucune odeur particulière n'émane ", (dedudes) x1, ".";
    Sorry:          "Pas grave.";
    Squeeze: switch (n) {
        1:  "Surveillez vos mains.";
        2:  "Vous n'arriverez à rien ainsi.";
    }
    Strong:         "Vous n'avez pas besoin de ce genre de langage pour finir l'aventure.";
    Swim:           "Il n'y a pas assez d'eau pour nager dedans.";  ! swim desactive par defaut dans I7
    Swing:          "Ce n'est pas une chose à laquelle il est utile de se balancer.";
    SwitchOff: switch (n) {
        1:  "Vous ne pouvez pas allumer ou éteindre cela.";
        2:  print_ret (ctheyreorthats) x1,
            " déjà éteint",(es) x1,".";
        3:  "Vous éteignez ", (the) x1, ".";
    }
    SwitchOn: switch (n) {
        1:  "Vous ne pouvez pas allumer cela.";
        2:  print_ret (ctheyreorthats) x1,
            " déjà allumé",(es) x1,".";
        3:  "Vous allumez ", (the) x1, ".";
    }
    Take:    switch(n) {
        1:  "D'accord."; ! ok.
        2:  "Vous vous possédez vous-même. Voilà une problématique sur laquelle les philosophes n'ont pas dû passer beaucoup de temps.";
        3:  print "Je ne pense pas qu'"; if (x1 has female) {print "elle";} else {print "il";}
                   if (x1 has pluralname) {print "s apprécieraient";} else {print " apprécierait";} ".";
        4:  print "Vous devez d'abord ";
            if (x1 has supporter) print "descendre "; else print "sortir ";
            print_ret (dedudes) x1, ".";
        5:  "Vous l'avez déjà.";
        6:  "Cela semble appartenir ", (to_the) x1, ".";
        7:  "Cela semble faire partie ", (dedudes) x1, ".";
        8:  print_ret (Cthatorthose) x1, " ", (isorarenot) x1,
            " disponible", (s) x1, ".";
        9:  print_ret (The) x1, " ", (isorarenot) x1, " ouvert",(es) x1,".";
        10: "C'est trop difficile à transporter.";
        11: "C'est fixé sur place.";
        12: "Vous transportez déjà trop d'objets.";
        13: "(vous mettez ", (the) x1, " dans ", (the) SACK_OBJECT,
            " pour faire de la place)";
    }
    Taste: if (x1 has animate) "Cela ne serait pas très convenable.";
           else "Vous préférez ne pas goûter n'importe quoi. On ne sait jamais où ça a pu traîner.";
    Tell: switch (n) {
        1:  "Vous discutez avec vous-même pendant un bon moment...";
        2:  "Pas de réaction.";
    }
    Think:          "Vous réfléchissez un peu, mais aucune idée ne vous vient à l'esprit.";
    ThrowAt: switch (n) {
        1:  "Futile.";
        2:  "Vous hésitez au moment crucial.";
    }
    Tie:  "Vous n'arriverez à rien comme ça.";
    Touch: switch (n) {
        1:  "Tenez vos mains tranquilles.";
        2:  "Vous préférez ne pas mettre vos mains n'importe où.";
        3:  "Si vous pensez que ça peut aider.";
    }
!    Turn: see Pull.
    Unlock:  switch (n) {
        1:  "Vous ne pouvez pas déverrouiller cela.";
        2:  print_ret (ctheyreorthats) x1,
            " déjà déverrouillé", (es) x1, ".";
        3:  "Cela ne rentre pas dans la serrure.";
        4:  "Vous déverrouillez ", (the) x1, ".";
    }
    VagueConsult :  "[Précisez sur quel sujet vous souhaitez consulter ", (the) x1, ".]";
    VagueDo: "[Soyez plus précis.]";
    VagueGo: "[Vous devez donner la direction dans laquelle aller.]";
    VagueSearch: "[Utilisez plutôt @<< fouiller @>>.]";
    VagueTie:  "[Reformulez : ", (address) verb_word, " ... avec ...]";
    VagueUse: "Veuillez indiquer un verbe plus précis.";
    Verify: switch (n) {
        1: "[Le fichier semble intact.]";
        2: "[Le fichier est certainement corrompu !]";
    }
    Wait:           "Le temps passe...";
    Wake:           "Il ne s'agit pas d'un rêve."; !plus neutre que la formule précédente
    WakeOther:      "Cela ne semble pas nécessaire.";
    Wave: switch (n) {
        1: "Vous n'avez pas cela.";
        2: "Vous auriez l'air ridicule en agitant ", (the) x1, ".";
    }
    WaveHands:
        if (x1 == 0 || x1 == player) "Vous auriez l'air bête en agitant vos mains devant vous.";
        else "Votre timidité prend le dessus au dernier moment.";
    Wear: switch (n) {
        1: "Vous ne pouvez pas porter cela.";
        2: "Vous n'avez pas cela.";
        3: "Vous ", (itorthem) x1, " portez déjà.";
        4: "Vous mettez ", (the) x1, ".";
    }
!    Yes:  see No.
];


! Affichage des pronoms - avec les guillemets français
[ PronomsSub x y c d;
    L__M(##Pronouns, 1);

    c = (LanguagePronouns-->0)/3;
    if (player ~= selfobj) c++;

    if (c == 0) return L__M(##Pronouns, 4);

    for (x=1,d=0 : x<=LanguagePronouns-->0 : x=x+3) {
        print "@<< ", (address) LanguagePronouns-->x, " @>> ";
        y = LanguagePronouns-->(x+2);
        if (y == NULL) L__M(##Pronouns, 3);
        else {
            L__M(##Pronouns, 2);
            print (the) y;
        }
        d++;
        if (d < c-1) print (string) COMMA__TX;
        if (d == c-1) print (string) AND__TX;
    }
    if (player ~= selfobj) {
        print "@<< ", (address) ME1__WD, " @>> "; L__M(##Pronouns, 2);
        c = player; player = selfobj;
        print (the) c; player = c;
    }
    L__M(##Pronouns, 5);
];



! ==============================================================================

Constant LIBRARY_FRENCH;       ! for dependency checking.

! ==============================================================================
