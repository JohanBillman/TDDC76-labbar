TDDC76 Programmering och datastrukturer, Laboration 3
------------------------------------------------------------------------------
Given kod för huvudprogramm och kalkylatorn (G-nivå). Övrig kod finns eller
ska placeras i mapparna ../Expression och ../Variable_Table (VG).

kalkylator.cc  Huvudprogrammet.

Calculator.h   Inkluderingsfil för Calculator.

               Klassen Expression, som ska konstrueras i laborationen, är typen
	       för datamedlemmen current_expression_, vilken ska lagra det 
               "aktuella uttrycket" i kalkylatorn.

	       Anm. <iosfwd> är en "lättviktsvariant" av <iostream>, som endast
	       innehåller datatyperna som ingår i <iostream>, inga objekt som
	       exempelvis cin och cout. <iosfwd> kan med fördel användas om vi
	       endast behöver deklarera, typiskt, referenser som std::istream&
	       och std::ostream&.

	       Anm: Samtliga "speciella medlemsfunktioner" (defaultkonstruktor, 
	       destruktor, kopieringskonstruktor, flyttkonstruktor, kopierings-
	       tilldelningsoperator och flyttilldelningsoperator är uttryckligen
	       deklarerade antingen "default" eller "delete". Flyttkonstruktorn
	       och flyttilldelningsoperatorn behöver egentligen inte deklareras
	       deleted, eftersom de inte kommer att genereras då någon av
	       kopieringskonstruktorn, kopieringstilldelningsoperator eller
	       destruktorn deklareras. Destruktorn behöver egentligen inte 
	       deklareras alls, eftersom den genereras implicit. Att deklarera
	       samtliga kan dock vara ett bra sätt att dokumentera i kod att alla
               har beaktats vid konstruktionen av Calculator.

Calculator.cc  Implementeringsfil för klassen Calculator. Innehåller separata
	       definitioner för medlemsfunktionerna.

Makefile       Makefil för att kompilera och länka programmet samt städa 
	       filkatalogen. Följande kommandon kan ges:

               make         kompilerar och länkar programmet, det körbara 
	       		    programmet erhålls på filen 'kalkylator'.

               make clean   tar bort olika kompileringsprodukter, exempelvis
	       	    	    objektkodsfiler (*.o).

               make zap     storstädar, endast källkoden och Makefile blir kvar.

Då det givna programmet kompileras erhålls ett felmeddelande för varje konkret
klass i Expression_Tree-hierarkin (Power, times, osv.), eftersom de givna
klasskeletten för hierarkin saknar överskuggningar av de "pure virtual"-
deklarerade medlemsfunktionerna i basklassen Expression_Tree. Felmeddelanden
härrör från koden i filen Expression.cc, men det är alltså inget fel där som
har med detta att göra, utan problemen beror på ofullständig kod i filerna 
Expression_Tree.h och Expression_Tree.cc. 
------------------------------------------------------------------------------
