# Akien's Inform 6 interactive fictions

(French version below.)

This repository includes French language interactive fictions written in
2008-2009 by Rémi Verschelde (Akien) as part of the French Interactive Fiction
community [IFiction-FR](http://www.fiction-interactive.fr/).

All finished games are playable online or offline with a Z-machine interpreter.

- [Rats](http://www.fiction-interactive.fr/rats/), 10 August 2008.
- [Brume](http://www.fiction-interactive.fr/brume/), 23 November 2008,
  won the French IF Comp 2008.
- [Récits de grand-père](http://www.fiction-interactive.fr/recits-de-grand-pere/),
  28 December 2008, written in a couple hours for a French Speed-IF jam.

The project in `katabasis/` was never completed.

## Compiling

Requirements:

- Inform 6 compiler, version 6.33 or later. (Earlier versions can work but you
  would have to convert encoding back to ISO-8859-15 instead of UTF-8.)
- GNU make

Run `make` either in the root folder of this repository to build all projects,
or in the folder of the specific project you want to build.

If your Inform 6 compiler is not available via the `inform` command, you can
run:

```
make INFORM=/path/to/inform/compiler
```

The compiled games will be `.z8` files (or `.z5` if you run `make z5`).

## Playing

An Inform Z-machine interpreter is needed to play the games in `.z8` or `.z5`
format. I can recommend the beautiful [Gargoyle](http://ccxvii.net/gargoyle/)
interpreter.

## License

The two "finished" projects, Rats and Brume, are available under a
[BSD 4-Clause](https://spdx.org/licenses/BSD-4-Clause.html) license.

The cover image for Rats is available under a Creative Commons Attribution -
Non Commercial - Share Alike 2.0 ([CC BY-NC-SA 2.0](
https://creativecommons.org/licenses/by-nc-sa/2.0/)) license, derived from the
photo [*Rats !!!!* by Matthieu Aubry](https://www.flickr.com/photos/matthieu-aubry/440634859/).

The cover image for Brume is derived from the photo [*Fire Fog* by Alex McCombie](
https://www.flickr.com/photos/nylongbow/369355047/), all rights reserved, used
with permission from the artist.

Récits and Katabasis do not include license terms yet, so until I add one, they
are proprietary.

-----

# Fictions interactives en Inform 6 d'Akien

(Version anglaise ci-dessus.)

Ce dépôt contient des fictions interactives en langue française écritent en
2008-2009 par Rémi Verschelde (Akien) au sein de la communauté francophone de
fiction interactive [IFiction-FR](http://www.fiction-interactive.fr/).

Tous les jeux sont jouables en ligne ou hors-ligne avec un interpréteur
Z-machine.

- [Rats](http://www.fiction-interactive.fr/rats/), 10 août 2008.
- [Brume](http://www.fiction-interactive.fr/brume/), 23 novembre 2008,
  lauréat de la French IF Comp 2008.
- [Récits de grand-père](http://www.fiction-interactive.fr/recits-de-grand-pere/),
  28 décembre 2008, écrit en deux heures pour une Speed-IF francophone.

Le projet dans `katabasis/` n'a jamais été complété.

## Compilation

Prérequis:

- Compilateur Inform 6, version 6.33 ou plus. (Les versions précédentes peuvent
  marcher, mais vous devrez re-convertir l'encodage en ISO-8859-15 à la place
  d'UTF-8.)
- GNU make

Lancez `make` soit dans le dossier principal de ce dépôt pour compiler tous les
projets, soit dans le dossier d'un projet spécique que vous voulez compiler.

Si votre compilateur Inform 6 n'est pas accessible via la commande `inform`,
vous pouvez lancer :

```
make INFORM=/chemin/vers/compilateur/inform
```

Les jeux compilés seront des fichiers `.z8` (ou `.z5` si vous lancez `make z5`).

## Jouer

Un interpréteur de Z-machine Inform est nécessaire pour jouer aux jeux au
format `.z8` ou `.z5`. Je peux recommender l'élégant interpréteur
[Gargoyle](http://ccxvii.net/gargoyle/).

## Licence

Les deux projets "finis", Rats et Brume, sont disponibles sous une licence
[BSD 4-Clause](https://spdx.org/licenses/BSD-4-Clause.html).

L'image de couverture de Rats est disponible sous une license Creative Commons
Paternité - Pas d'Utilisation Commerciale - Partage des Conditions Initiales à
l'Identique 2.0 ([CC BY-NC-SA 2.0](https://creativecommons.org/licenses/by-nc-sa/2.0/)),
dérivée de la photo [*Rats !!!!* de Matthieu Aubry](https://www.flickr.com/photos/matthieu-aubry/440634859/).

L'image de couverture de Brume est dérivée de la photo [*Fire Fog* d'Alex McCombie](
https://www.flickr.com/photos/nylongbow/369355047/), tous droits réservés, utilisée
avec la permission de l'artiste.

Récits et Katabasis n'ont pas de licence définie, et sont donc pour l'instant
propriétaires.
