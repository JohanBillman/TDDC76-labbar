//Lektion 2

//tips inför lab2
//implementering av prefix (++i) och postfix(i++) inkrementering
//prefix räknar upp först och returnerar det nya. Postfix sparar undan 

//prefix i någon klass
int& operator++();
//postfix
int operator++(int);

//för float blir det bara ändrad returtyp, postfix tar dock ändå in en int
//
//I labinstruktionen om lvalues och rvalues
//"Informel definiton" rvalue = värde som kan användas till HÖGER
//lvalue = värdesom kan användas till vänster

int x;
x = 7; //inget konstigt. x är ett lvalue
7 = x; //7 är ett rvalue, alltså 7an kan vara stå till höger
(7 + 7) = 5; //Även resultat från beräkningen är ett rvalue

int test(){ //skriver man const så blir man säkrare på att det är ett rvalue
	return 7;
}

x = test();
test() = x; //här är resultatet av test() ett rvalue
//rvalues är typiskt vid funktioner som returnerar kopior
int y = 8;
int& test2(){ //lvalue
	return y;
}
test2() = x; //fungerar. returnerar en referens till y som vi kan sätta till något.


smart_pointer sp(new Interger{1});
{
	class smart_pointer{
	private: //är ju default
		Interger* p = nullptr;

	public:
		smart_pointer(Interger* p) /* Initieringslistan efter parentesen innan fiskmåsen, separera med kommatecken*/ : p(p)/*Tilldela p i klassen till värde vi får in*/{
			this->p = p; //Detta är onödigt med det ovan
		}

		~smart_pointer(){ //#1 av the big five, destruktorn
			delete p;
		}

		smart_pointer(const	smart_pointer& orig){ //#2 av the big five, kopieringskonstruktorn
			this->p = copy(orig.p);
		}

		smart_pointer(smart_pointer&& trash){ //#3 av the big five, kopiering med movesemantik
			std::swap(this->p,trash.p);
		}

		smart_pointer& operator=(const smart_pointer& orig){//#4 av the big five, tilldelningsoperatorn
			smart_pointer temp(orig); //skapar en kopia av orig och lägger den i temp. Temp kommer upphöra att existera när vi lämnar funktionen
			this->swap(temp); //swap är hjälpfunktion som byter allt väsentligt i klassen.
			return *this;
		}

		smart_pointer& operator=(smart_pointer&& trash){//#5 av the big 5, tilldelningsoperator med movesemantik
			if (this == &trash){ //& i början ger en pekare till datan som variablen refererar
				return *this;
			}
			delete p;
			this->p = trash.p;
			trash.p = nullptr;
			return *this;
		}

		//för att nyttja en inbyggd, kopieringskonstruktorn nedan t.ex.
		//i h filen
		//smart_pointer(const smart_pointer&) = default;
		//för att inte skapa någon konstruktor
		//smart_pointer(const smart_pointer&) = delete;
	};
}


//explicit, för att hindra något från att användas explicit och inte implicit.
//ibland kan kompilatorn fatta att använderen underförstått försöker göra en konvertering.
//explicit hindrar det
void test3(smart_pointer x){
	...
}

test3(new Interger{7}); //explicit framför konstruktorn skulle göra att detta inte hindrar.
//annars skulle det fungera

