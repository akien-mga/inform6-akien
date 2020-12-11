# Bibliothèques francophones pour Inform 6

Ces bibliothèques sont destinées à être utilisées avec Inform 6 pour la
réalisation de jeux d'aventures textuels en français.

- [Site officiel](https://informfr.tuxfamily.org) et téléchargement de la
  dernière version stable
- [Code source](https://bitbucket.org/informfr/i6-french-language), pour
  tester la version de développement ou voir l'historique
- [IFiction-FR](http://ifiction.free.fr): carrefour francophone de la fiction
  interactive (jeux, articles, forum, etc.).


## Contenu des bibliothèques

- `French.h`: 2ème personne du pluriel, présent.
- `FrenchG.h`: 2ème personne du pluriel, présent (grammaire).
- `French1PSP.h`: Variante à la 1ère personne du singulier, passé, à utiliser
  à la place de `French.h`. Cette version fut initialement réalisée pour un
  jeu inspiré des travaux de H. P. Lovecraft, et n'est donc pas aussi neutre
  que la version à la 2ème personne du pluriel, présent.


## Utilisation

Si vous ignorez comment compiler un jeu avec Inform 6, la rubrique Articles
du site [IFiction-FR](http://ifiction.free.fr) contient de nombreuses
informations ainsi qu'un kit de démarrage rapide, et le forum est réactif.


## Licence

Tous les fichiers de ce dépôt sont distribués sous la licence Aristic 2.0,
telle que décrite dans le fichier [ARTISTIC](/ARTISTIC) ainsi que les
en-têtes de chaque fichier des bibliothèques francophones.

Se référer au fichier [COPYING](/COPYING) pour de plus amples détails.


## Historique des modifications

### Version 2.4-dev

**Changements dans le code :**

Changement de la façon dont les accents sont pris en compte : désormais on
enlève tous les accents par défaut, i.e. si la variable gardeaccents est à 0.
Les name avec des accents créent un bug sur l'objet. Le joueur n'est plus
obligé de taper des mots avec accents : c'est mieux pour les anglophones, les
joueurs sur smartphones, et ça évite de rejeter toute une commande parce
qu'il manque un accent. Si vous voulez absolument que le joueur tape tous les
accents (mauvaise idée en termes d'utilisabilité), mettez gardeaccents à 2,
mais la bibliothèque n'est pas totalement compatible avec ça de toute façon ;
si vous voulez que les accents ne soient enlevés que si le mot n'est pas
reconnu (l'ancien comportement), mettez-la à 1. La dernière solution n'est
pas franchement satisfaisante, et à vos risques et périls : si vous écrivez
"cles" 10 fois et "clés" une fois, ça crée 10 bugs sur les objets que vous
"n'avez pas modifié. De même si vous écrivez 'à' par erreur dans un name
encore pire, ça casse les verbes de la bibliothèque aussi - "parler à" et
tous les trucs dans le même genre).
La bibli a été corrigée et n'a aucun mot ('clé', 'là' et 'à') avec accent
dans la grammaire ; c'est le comportement voulu, vu que aucun des verbes n'a
d'accents ("déverrouiller", "goûter", "écouter", etc.).

**Correction de bugs :**

- Correction d'un bug qui écrit des actions implicites comme
  "(de le passeport)". Ce fix n'est pas forcément satisfaisant, parce qu'il
  duplique du code de PrintCommand (si jamais ce code est modifié, par
  exemple si un bug est corrigé, il faudra modifier ce code à la main), mais
  bon, ça marche. Il a aussi fallu compléter LanguageVerb.
- IsOrAre et IsOrAreNot ont été mal traduits (en anglais, pluriel ou player
  c'est pareil, c'est "are", mais pas en français)
- Descendre noun correspondait à Enter ; "descendre du noun" est Exit,
  "descendre dans/vers/au noun" est Enter (choix critiquable mais bon). Le
  plus gros problème c'est que "descendre noun" renvoie "mais vous êtes déjà
  sur noun", ce qui n'est vraiment pas ce qu'on veut. Désormais, "descendre
  noun" correspond à ExitOrEnter, qui Exit si on est sur le nom, et Enter
  sinon. Mais peut-être aurait-il fallu utiliser IndirectlyContains ? 
- enleve_accents permet maintenant de traiter toutes les lettres de la table
  2B du DM4 (dont les ligatures)
- "accents on" et "accents off" ne marchaient pas ; désormais c'est "accents
  strict", "accents on" et "accents off"
- Une ligne dans "sortir" n'était jamais exécutée : la ligne 'sortir X de Y'
  était avant 'sortir de Y', et le parser essayait d'inférer X, avec des
  résultats peu probants. L'ordre a été changé.
- "pronouns" n'avait pas été traduit, et dans la réponse il y avait les
  mauvais guillemets.
- Ajout de synonymes (humer, farfouiller, ok, ouais, yep, ouaip).
- Ajout de la tournure "poser une question sur X à Y".
- Retrait de 'complet score' et 'detaille', mauvaises traductions de
  l'anglais.
- La grammaire de "regarder" acceptait "atravers" en un seul mot.

**Changements dans les messages :**

- Les messages de l'interpréteur et de l'analyseur syntaxique apparaissent
  désormais entre crochets.
- La plupart des points d'exclamation ont été enlevés (ils étaient
  relativement abrupts voire méchants pour le joueur).
- CrierSansPrecision, Donner à vous-même, Sauter, Chanter, Goûter, Toucher,
  Agiter, Saluer : une action était faite automatiquement, ce qui n'est pas
  forcément cohérent en fonction de la situation. Plutôt que de laisser à
  l'auteur le plaisir de se poser ces questions  (ou plutôt d'oublier de se
  les poser et de laisser des bugs passer), on change les réponses.
- Ecouter et Sentir : écouter (général) ne devrait pas donner la même réponse
  que écouter objet ; en particulier, "vous n'entendez rien de particulier"
  quand on écoute une table dans une discothèque, c'est pas la bonne réponse.
- Montrer : "not impressed" est un intraduisible
- Penser : réponse trop sarcastique, enfin je trouve
- Take, 2: "physique quantique" si je veux faire un jeu qui se passe au
  Moyen-Age c'est un anachronisme (alors certes, on brise le 4ème mur à ce
  moment-là donc on pourrait dire que ça compte pas ; mais y'a moyen de faire
  la même chose sans anachronisme alors on change).
- Neutralisation du genre de certaines réponses par défaut. La seule dont je
  ne suis pas vraiment fier, c'est l'alternative à "aussi beau que
  d'habitude" ; j'ai pensé à "aussi moche que d'habitude", qui est rigolote,
  et à "votre physique est aussi agréable que d'habitude".
- typo dans Miscellany 20
- les bons guillemets français au lieu des ~trucs~
- IS__TX, ARE__TX : utilisés par WriteListFrom (bit ISORARE_BIT) : si le bit
  est mis, ça donne "dans (the supporter) IS__TX/ARE__TX objets". C'est
  utilisé dans la bibli anglaise, mais pas dans la bibli française, où ça a
  été reformulé pour éviter des formulations pas correctes comme "dans le
  placard est une boîte de biscuits". Mais quand même, il vaut mieux bien le
  traduire : si on copie-colle un code anglophone, ou si on traduit de
  l'anglais (ce problème a été détecté pendant la traduction de Shade), ou
  juste parce que ça peut être pratique après tout. On met "se trouve" (dans
  le placard se trouve une boîte de biscuits), "il y a" c'est moins correct.
- Take 3 (prendre un animate) : rapproché de la version anglaise, plus
  précise
- Take 10 (prendre un scenery) : ajout de "c'est" dans "c'est trop difficile
  à transporter"
- Insert 8 (réussir à insérer) : "d'accord", comme Take
- Homogénéisation du style des réponses à sauver et charger (ce sont les
  seules de la bibliothèque à avoir des --- et plein de retours à la ligne)
- Remove : 1 et 2 ne prenaient pas le genre en compte ; la réponse de 2
  n'était pas très élégante.


### Version 2.3 - 5 septembre 2008

- Modification de la réponse standard pour fouiller, selon qu'on tente de
  fouiller un animé ou un inanimé.
- Correction de crashs liés aux verbes parler, demander et interroger.
- Amélioration et modification des verbes de communication avec les
  personnages :
  * Création de l'action "ParlerSansPrecision" permettant des formulations
    telles que : "parler à personnage". C'est une spécificité de la lib
    francophone car une telle action n'existe pas en anglais par défaut.
    Il est INDISPENSABLE de gérer cette action pour les personnages non
    joueurs, en plus des actions traditionnelles Ask, Tell et Answer.
    Y penser en cas de compilation d'un jeu ancien avec cette version (ou
    ultérieure) de la bibliothèque francophone.
  * Ajout des équivalents ? et ! pour interroger et parler, ainsi que
    compréhension des commandes "? sujet" et "! sujet", signifiant
    respectivement "interroger sur sujet" et "parler de sujet".
  * Comme dans la version anglaise le verbe demander renvoie l'action AskFor
    si suivi d'un nom (noun) reconnu par le jeu, en revanche s'il est suivi
    d'un texte non reconnu (topic), cela devient l'action Answer, comme pour
    le verbe dire.
- Saluer est maintenant un verbe transitif : "saluer personnage" est
  maintenant une formulation reconnue, avec un message par défaut ("Vous
  saluez le personnage.").
- suppression des verbes peler, éplucher, décortiquer, qui renvoyaient Take,
  en tant que traduction de "peel off". Remplacés par le verbe "décoller"
  (un post-it, un chewing gum...).
- Ajout d'un verbe : version fr / vf / version francaise indiquant quelle
  version de la bibliothèque francophone est utilisée.
- Pour le verbe dire et quelques autres, lorsque le destinataire est
  déterminé automatiquement, affichage de la préposition "->" au lieu de "à"
  qui pose problème pour "à le barman" ou "à le conducteur".
- Ajout de "regarder autour" équivalent à "regarder"
- Version passé à la première personne du singulier (1PSP, issue du jeu Lieux
  Communs) : la version French1PSP.h est maintenant à peu près au niveau de
  la version standard, même si elle n'est pas aussi neutre dans les
  formulations. Suppression de FrenchG1PSP.h, fusionné avec FrenchG.h. Pour
  utiliser la forme 1PSP, il suffit d'inclure French1PSP.h au lieu de French.h
- Ajout des verbes utiliser et creuser sans rien preciser (actions VagueDo et
  VagueDig) : ils ne font que demander au joueur d'utiliser une formulation
  plus précise.
- Correction du message par défaut pour l'action Drink : l'action demande
  toujours un objet, le message "Il n'y a rien de buvable ici" n'était donc
  pas adapté et souvent faux. Remplacé par "Ceci n'a rien de buvable".
- Lorsqu'on tente de "goûter" un objet ayant l'attribut 'animate', on a
  maintenant le message "Cela ne serait pas très convenable." plutôt que
  "Vous ne remarquez rien de particulier" qui suggère qu'on l'a effectivement
  goûté.
- Message misc 49 : "Pouvez-vous préciser le nom de l'objet à utiliser ?^"
  changé en "Pouvez-vous préciser l'objet concerné par cette action, ou à
  utiliser ?^" 
- Action "Rub" (frotter) : différenciation entre l'action selon qu'elle est
  sur un animate ou un objet, et passage du message au futur pour ce dernier
  (vous n'arriverez à rien comme ça) pour éviter de suggérer que l'action a
  réussi.
- Modification du verbe "chercher" qui était équivalent à "fouiller" dans
  la pratique. Comme on peut vouloir utiliser le verbe chercher un peu
  différemment (exemple : chercher des puces dans le chien) et que chercher
  est un verbe pas assez terre à terre (un peu comme "trouver" ou
  "résoudre"), il renvoie maintenant VagueSearch qui dit "utilisez plutôt
  'fouiller'"
- amélioration de la grammaire du verbe "grimper/escalader/gravir" avec ajout
  des prépositions suivantes en plus de 'sur' : à, a, au, aux, par (exemple :
  grimper aux arbres, grimper à l'échelle. La préposition par n'est pas
  indispensable mais ne fait pas de mal au cas où on pourrait la rencontrer)
- modification de la grammaire du verbe "fouiller" pour qu'on puisse
  "fouiller dans" quelque chose
