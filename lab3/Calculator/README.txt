TDDC76 Programmering och datastrukturer, Laboration 3
------------------------------------------------------------------------------
Given kod f�r huvudprogramm och kalkylatorn (G-niv�). �vrig kod finns eller
ska placeras i mapparna ../Expression och ../Variable_Table (VG).

kalkylator.cc  Huvudprogrammet.

Calculator.h   Inkluderingsfil f�r Calculator.

               Klassen Expression, som ska konstrueras i laborationen, �r typen
	       f�r datamedlemmen current_expression_, vilken ska lagra det 
               "aktuella uttrycket" i kalkylatorn.

	       Anm. <iosfwd> �r en "l�ttviktsvariant" av <iostream>, som endast
	       inneh�ller datatyperna som ing�r i <iostream>, inga objekt som
	       exempelvis cin och cout. <iosfwd> kan med f�rdel anv�ndas om vi
	       endast beh�ver deklarera, typiskt, referenser som std::istream&
	       och std::ostream&.

	       Anm: Samtliga "speciella medlemsfunktioner" (defaultkonstruktor, 
	       destruktor, kopieringskonstruktor, flyttkonstruktor, kopierings-
	       tilldelningsoperator och flyttilldelningsoperator �r uttryckligen
	       deklarerade antingen "default" eller "delete". Flyttkonstruktorn
	       och flyttilldelningsoperatorn beh�ver egentligen inte deklareras
	       deleted, eftersom de inte kommer att genereras d� n�gon av
	       kopieringskonstruktorn, kopieringstilldelningsoperator eller
	       destruktorn deklareras. Destruktorn beh�ver egentligen inte 
	       deklareras alls, eftersom den genereras implicit. Att deklarera
	       samtliga kan dock vara ett bra s�tt att dokumentera i kod att alla
               har beaktats vid konstruktionen av Calculator.

Calculator.cc  Implementeringsfil f�r klassen Calculator. Inneh�ller separata
	       definitioner f�r medlemsfunktionerna.

Makefile       Makefil f�r att kompilera och l�nka programmet samt st�da 
	       filkatalogen. F�ljande kommandon kan ges:

               make         kompilerar och l�nkar programmet, det k�rbara 
	       		    programmet erh�lls p� filen 'kalkylator'.

               make clean   tar bort olika kompileringsprodukter, exempelvis
	       	    	    objektkodsfiler (*.o).

               make zap     storst�dar, endast k�llkoden och Makefile blir kvar.

D� det givna programmet kompileras erh�lls ett felmeddelande f�r varje konkret
klass i Expression_Tree-hierarkin (Power, times, osv.), eftersom de givna
klasskeletten f�r hierarkin saknar �verskuggningar av de "pure virtual"-
deklarerade medlemsfunktionerna i basklassen Expression_Tree. Felmeddelanden
h�rr�r fr�n koden i filen Expression.cc, men det �r allts� inget fel d�r som
har med detta att g�ra, utan problemen beror p� ofullst�ndig kod i filerna 
Expression_Tree.h och Expression_Tree.cc. 
------------------------------------------------------------------------------
