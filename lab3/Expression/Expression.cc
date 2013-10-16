/*
 * Expression.cc
 */
#include "Expression.h"
#include "Expression_Tree.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>
 using namespace std;



 Expression::Expression(class Expression_Tree*  ptr){
 	topNode = ptr;
 }

/*
 * evaluate()
 */
 long double Expression::evaluate() const{
 	if(topNode == nullptr){
      return 0;
      //throw expression_error("Uttrycket är tomt");
 	}
 	return topNode->evaluate();
 }

/*
 * get_postfix()
 */
 std::string Expression::get_postfix() const{
 	if(topNode == nullptr){
 		return "";
   }
   return topNode->get_postfix();
}

std::string Expression::get_infix() const{
  if(topNode == nullptr){
    return "";
  }
}

/*
 * empty()
 */
 bool Expression::empty() const
 {
 	return topNode == nullptr;
 }

/*
 * print_tree()
 */
 void Expression::print_tree(std::ostream& os) const
 {
 	topNode->print(os);

   os << "Värde..: " << this->evaluate() << endl;
   os << "Postfix: " << this->get_postfix() << endl;
   //os << "Infix..: " << this->get_infix() << endl;
}

/*
 * swap(other)
 */
 void Expression::swap(Expression& tree)
 {
   if(tree.topNode == nullptr){
      tree.topNode = topNode;
      topNode = nullptr;
   }else{
     Expression_Tree* temp = (tree.topNode)->clone();
     tree.topNode = topNode;
     topNode = temp; 
  }

}

Expression_Tree* Expression::get_topNode() const{
	return topNode;
}

void Expression::set_topNode(Expression_Tree* newtopNode){
	topNode = newtopNode;
}

/*
 * swap(x, y)
 */
 void swap(Expression& tree1, Expression& tree2)
 {
   Expression_Tree* temp = (tree1.get_topNode())->clone();
   tree1.set_topNode(tree2.get_topNode());
   tree2.set_topNode(temp);
}

/*
 * make_expression() definieras efter namnrymden nedan.
 */
 Expression make_expression(const string& infix);

// Namrymden nedan innehåller intern kod för infix-till-postfix-omvandling
// och generering av uttrycksträd. En anonym namnrymd begränsar användningen
// av medlemmarna till denna fil.
 namespace
 {
 	using std::vector;
 	using std::map;
 	using std::make_pair;
 	using std::string;

   // Teckenuppsättningar för operander. Används av make_expression_tree().
 	const string letters{"abcdefghijklmnopqrstuvwxyz"};
 	const string digits{"0123456789"};
 	const string integer_chars{digits};
 	const string real_chars{digits + '.'};
 	const string variable_chars{letters};
 	const string operand_chars{letters + digits + '.'};

   // Tillåtna operatorer. Används av make_postfix() och make_expression_tree().
   // Prioritetstabeller, en för inkommandeprioritet och en för stackprioritet. 
   // Högre värde inom input_prio respektive stack_prio anger inbördes prioritetsordning.
   // Högre värde i input_prio jämfört med motsvarande position i stack_prio innebär
   // högerassociativitet, det motsatta vänsterassociativitet. Används av make_postfix(). 
 	using priority_table = map<string, int>;

 	const vector<string> operators{ "^", "*", "/", "+", "-", "=" };
 	const priority_table input_priority{ {"^", 8}, {"*", 5}, {"/", 5}, {"+", 3}, {"-", 3}, {"=", 2} };
 	const priority_table stack_priority{ {"^", 7}, {"*", 6}, {"/", 6}, {"+", 4}, {"-", 4}, {"=", 1} };

   // Hjälpfunktioner för att kategorisera lexikala element.
 	bool is_operator(char token)
 	{
 		return find(begin(operators), end(operators), string{token}) != end(operators);
 	}

 	bool is_operator(const string& token)
 	{
 		return find(begin(operators), end(operators), token) != end(operators);
 	}

 	bool is_operand(const string& token)
 	{
 		return token.find_first_not_of(operand_chars) == string::npos;
 	}

 	bool is_integer(const string& token)
 	{
 		return token.find_first_not_of(integer_chars) == string::npos;
 	}

 	bool is_real(const string& token)
 	{
 		return token.find_first_not_of(real_chars) == string::npos;
 	}

 	bool is_identifier(const string& token)
 	{
 		return token.find_first_not_of(letters) == string::npos;
 	}

   // format_infix tar en sträng med ett infixuttryck och formaterar med ett
   // mellanrum mellan varje symbol; underlättar vid bearbetningen i make_postfix.
 	std::string format_infix(const std::string& infix)
 	{
 		auto bos = begin(infix);
 		auto eos = end(infix);
 		string formated;

 		for (auto it = bos; it != eos; ++it)
 		{
 			if (is_operator(*it) || *it == '(' || *it == ')')
 			{
	    // Se till att det är ett mellanrum före en operator eller parentes
 				if (it != bos && *(it - 1) != ' ' && *(formated.end() - 1) != ' ')
 					formated.append(1, ' ');
 				formated.append(1, *it);
	    // Se till att det är ett mellanrum efter en operator eller parentes
 				if ((it + 1) != eos && *(it + 1) != ' ')
 					formated.append(1, ' ');
 			}
 			else
 			{
 				if (*it != ' ')
 					formated.append(1, *it);
 				else if (it != bos && *(it - 1) != ' ')
 					formated.append(1, *it);
 			}
 		}
 		return formated;
 	}

   // make_postfix tar en infixsträng och returnerar motsvarande postfixsträng.
 	std::string make_postfix(const std::string& infix)
 	{
 		using std::stack;
 		using std::string;
 		using std::istringstream;
 		using std::find;

 		stack<string> operator_stack;
 		string        token;
 		string        previous_token;
 		bool          last_was_operand{false};
 		bool          assignment{false};
 		int           paren_count{0};

 		istringstream is{format_infix(infix)};
 		string        postfix;

 		while (is >> token)
 		{
 			if (is_operator(token))
 			{
 				if (!last_was_operand || postfix.empty() || previous_token == "(")
 				{
 					std::cerr << "operator där operand förväntades\n";
 					exit(EXIT_FAILURE);
 				}

 				if (token == "=")
 				{
 					if (assignment)
 					{
 						std::cerr << "multipel tilldelning";
 						exit(EXIT_FAILURE);
 					}
 					else
 					{
 						assignment = true;
 					}
 				}

 				while (!operator_stack.empty() && operator_stack.top() != "(" &&
 					input_priority.find(token)->second <=
 					stack_priority.find(operator_stack.top())->second)
 				{
 					postfix += operator_stack.top() + ' ';
 					operator_stack.pop();
 				}
 				operator_stack.push(token);
 				last_was_operand = false;
 			}
 			else if (token == "(")
 			{
 				operator_stack.push(token);
 				++paren_count;
 			}
 			else if (token == ")")
 			{
 				if (paren_count == 0)
 				{
 					std::cerr << "vänsterparentes saknas\n";
 					exit(EXIT_FAILURE);
 				}

 				if (previous_token == "(" && !postfix.empty())
 				{
 					std::cerr << "tom parentes\n";
 					exit(EXIT_FAILURE);
 				}

 				while (!operator_stack.empty() && operator_stack.top() != "(")
 				{
 					postfix += operator_stack.top() + ' ';
 					operator_stack.pop();
 				}

 				if (operator_stack.empty())
 				{
 					std::cerr << "högerparentes saknar matchande vänsterparentes\n";
 					exit(EXIT_FAILURE);
 				}
	    // Det finns en vänsterparentes på stacken
 				operator_stack.pop();
 				--paren_count;
 			}
 			else if (is_operand(token))
 			{
 				if (last_was_operand || previous_token == ")")
 				{
 					std::cerr << "operand där operator förväntades\n";
 					exit(EXIT_FAILURE);
 				}

 				postfix += token + ' ';
 				last_was_operand = true;
 			}
 			else
 			{
 				std::cerr << "otillåten symbol\n";
 				exit(EXIT_FAILURE);
 			}

 			previous_token = token;
 		}

 		if (postfix == "")
 		{
 			std::cerr << "tomt infixuttryck!\n";
 			exit(EXIT_FAILURE);
 		}

 		if (!last_was_operand && !postfix.empty())
 		{
 			std::cerr << "operator avslutar\n";
 			exit(EXIT_FAILURE);
 		}

 		if (paren_count > 0)
 		{
 			std::cerr << "högerparentes saknas\n";
 			exit(EXIT_FAILURE);
 		}

 		while (!operator_stack.empty())
 		{
 			postfix += operator_stack.top() + ' ';
 			operator_stack.pop();
 		}

 		if (!postfix.empty())
 		{
 			postfix.erase(postfix.size() - 1);
 		}

 		return postfix;
 	}

   // make_expression_tree tar en postfixsträng och returnerar ett motsvarande 
   // länkat träd av Expression_Tree-noder.
 	Expression_Tree* make_expression_tree(const std::string& postfix)
 	{
 		using std::stack;
 		using std::string;
 		using std::istringstream;

 		stack<Expression_Tree*> tree_stack;
 		string                  token;
 		istringstream           ps{postfix};

 		while (ps >> token)
 		{
 			if (is_operator(token))
 			{
 				if (tree_stack.empty()) 
 				{
 					std::cerr << "felaktig postfix\n";
 					exit(EXIT_FAILURE);
 				}
 				Expression_Tree* rhs{tree_stack.top()};
 				tree_stack.pop();

 				if (tree_stack.empty()) 
 				{
 					std::cerr << "felaktig postfix\n";
 					exit(EXIT_FAILURE);
 				}
 				Expression_Tree* lhs{tree_stack.top()};
 				tree_stack.pop();

 				if (token == "^")
 				{
 					tree_stack.push(new Power{lhs, rhs});
 				}
 				else if (token == "*")
 				{
 					tree_stack.push(new Times{lhs, rhs});
 				}
 				else if (token == "/")
 				{
 					tree_stack.push(new Divide{lhs, rhs});
 				}
 				else if (token == "+")
 				{
 					tree_stack.push(new Plus{lhs, rhs});
 				}
 				else if (token == "-")
 				{
 					tree_stack.push(new Minus{lhs, rhs});
 				}
 				else if (token == "=")
 				{
 					tree_stack.push(new Assign{lhs, rhs});
 				}
 			}
 			else if (is_integer(token))
 			{
 				tree_stack.push(new Integer{std::stoll(token.c_str())});
 			}
 			else if (is_real(token))
 			{
 				tree_stack.push(new Real{std::stold(token.c_str())});
 			}
 			else if (is_identifier(token))
 			{
 				tree_stack.push(new Variable{token});
 			}
 			else
 			{
 				std::cerr << "felaktig postfix\n";
 				exit(EXIT_FAILURE);
 			}
 		}
      // Det ska bara finnas ett träd på stacken om korrekt postfix.

 		if (tree_stack.empty())
 		{
 			std::cerr << "ingen postfix given\n";
 			exit(EXIT_FAILURE);
 		}

 		if (tree_stack.size() > 1)
 		{
 			while (!tree_stack.empty())
 			{
 				delete tree_stack.top();
 				tree_stack.pop();
 			}
 			std::cerr << "felaktig postfix\n";
 			exit(EXIT_FAILURE);
 		}

      // Returnera trädet.
 		return tree_stack.top();
 	}
} // namespace

Expression make_expression(const string& infix)
{
	try{
		return Expression{make_expression_tree(make_postfix(infix))};
	}
	catch(...){
		throw;
	}
}
