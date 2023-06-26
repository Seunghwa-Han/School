package util;
import java.util.*;
import static util.Token.reserved;

public class ParsingTable {

	public HashMap<String, Symbol> symboltable;

	public ParsingTable(){
		symboltable = new HashMap<>();

		/* insert keyword to symbol table */
		for(String item : reserved){
			Symbol s = new Symbol(item, "keyword");
			symboltable.put(s.name, s);
		}
	}

	public static final String EPSILON = "epsilon";
	public static final String ERROR = "error";

	/* list of terminals */
	public static final List<String> terminals = Arrays.asList(
		"(", "number", "id", ")", "+", "-", "*", "/", ">", "<",
		"<=", ">=", "==", ";", ",", "=", "++", "--", "+=", "-=",
		"*=", "/=",
		"program", "program_begin", "program_end", "begin", "end",
		"if", "elseif", "else", "while", "for",
		"integer", 
		"continue", "break", 
		"display",
		"stringLiteral"
	);
	/* list of non-terminals */
	public static final List<String> nonTers = Arrays.asList(
		"start", "stmt", "stmts",
		"ifStmt", "elseif_part", "else_part", 
		"whileStmt",
		"forStmt", "for_cond", "for_update", "for_option",
		"assignStmt",
		"defineStmt", "declarators", "declarators\'", "option",
		"atomicStmt", "disoption",
		"exp", "exp\'",
		"simple_exp", "simple_exp\'",
		"term", "term\'", "factor",
		"compop", "addop", "mulop", "op"
	);

	/* parsing table */
	public String M(String N, String T, Stack<String> currentStmt)
	{
		switch(N){
			case "start":{
				switch(T){
					case "program":
						return "program id program_begin stmts program_end";
					default:
						return ERROR+": [program] keyword not matched";
				}
			}
			case "stmt":{
				switch(T){
					case "id":
						currentStmt.push("assignStmt");
						return "assignStmt";
					case "if":
						currentStmt.push("ifStmt");
						return "ifStmt";
					case "while":
						currentStmt.push("whileStmt");
						return "whileStmt";
					case "for":
						currentStmt.push("forStmt");
						return "forStmt";
					case "integer":
						currentStmt.push("defineStmt");
						return "defineStmt";
					case "continue":
					case "break":
					case "display":
						currentStmt.push("atomicStmt");
						return "atomicStmt";
					default:
						return ERROR;
				}
			}
			case "stmts":{
				switch(T){
					case "id":
					case "if":
					case "while":
					case "for":
					case "integer":
					case "continue":
					case "break":
					case "display":
						return "stmt stmts";
					case "program_end":
					case "end":
						return EPSILON;
					default:{
						if(currentStmt.empty())
							return ERROR+": program_end is expected";
						else
							return ERROR+": end is expected";
					}
				}
			}
			// ------------------------------
			case "forStmt":{
				switch(T){
					case "for":
						currentStmt.push("for_init");
						return "for ( integer id = exp ; for_cond ; for_update ) begin stmts end";
					default:
						return ERROR;
				}
			}
			case "for_cond":{
				switch(T){
					case "id":
					case "(":
					case "number":
						currentStmt.push("for_cond");
						return "simple_exp compop simple_exp";
					default:
						return ERROR;
				}
			}
			case "for_update":{
				switch(T){
					case "id":
					case "(":
					case "number":
						return "exp for_option";
					default:
						return ERROR;
				}
			}
			case "for_option":{
				switch(T){
					case "++":
					case "--":
						return T;
					case "=":
					case "+=":
					case "-=":
					case "/=":
					case "*=":
						return "op exp";
					default:
						return ERROR;
				}
			}
			// ------------------------------
			case "whileStmt":{
				switch(T){
					case "while":
						return "while ( exp ) begin stmts end";
					default:
						return ERROR+"while";
				}
			}
			// ------------------------------
			case "ifStmt":{
				switch(T){
					case "if":
						return "if ( exp ) begin stmts end elseif_part else_part";
					default:
						return ERROR;
				}
			}
			case "elseif_part":{
				switch(T){
					case "elseif":
						currentStmt.push("elseif_part");
						return "elseif ( exp ) begin stmts end elseif_part";
					case "id":
					case "program_end":
					case "end":
					case "if":
					case "else":
					case "while":
					case "for":
					case "integer":
					case "continue":
					case "break":
					case "display":
						return EPSILON;
					default:
						return ERROR;
				}
			}
			case "else_part":{
				switch(T){
					case "else":
						currentStmt.push("else_part");
						return "else begin stmts end";
					case "id":
					case "program_end":
					case "end":
					case "if":
					case "while":
					case "for":
					case "integer":
					case "continue":
					case "break":
					case "display":
						return EPSILON;
					default:
						return ERROR;
				}
			}
			// -------------------------------
			case "atomicStmt":{
				switch(T){
					case "continue":
						return "continue ;";
					case "break":
						return "break ;";
					case "display":
						return "display ( disoption ) ;";
					default:
						return ERROR;
				}
			}
			case "disoption":{
				switch(T){
					case "stringLiteral":
						return "stringLiteral";
					case ")":
						return EPSILON;
					default:
						return ERROR;
				}
			}
			// --------------------------------
			case "assignStmt":{
				switch(T){
					case "id":
						return "id op exp ;";
					default:
						return ERROR;
				}
			}
			// ---------------------------------
			case "defineStmt":{
				switch(T){
					case "integer":
						return "integer declarators ;";
					default:
						return ERROR;
				}
			}
			case "declarators":{
				switch(T){
					case "id":
						return "id option declarators\'";
					default:
						return ERROR;
				}
			}
			case "declarators\'":{
				switch(T){
					case ",":
						return ", id option declarators\'";
					case ";":
						return EPSILON;
					default:
						return ERROR;
				}
			}
			case "option":{
				switch(T){
					case "=":
						return "= exp";
					case ";":
					case ",":
						return EPSILON;
				}
			}
			//---------------------------------------------
			case "exp":{
				switch(T){
					case "(":
					case "number":
					case "id":
						return "simple_exp exp\'";
					default:
						return ERROR;
				}
			}
			case "exp\'":{
				switch(T){
					case ">":
					case "<":
					case "<=":
					case ">=":
					case "==":
						return "compop simple_exp exp\'";
					case ")":
					case ";":
					case ",":
					case "=":
					case "/=":
					case "+=":
					case "-=":
					case "*=":
					case "++":
					case "--":
						return EPSILON;
					default:
						return ERROR;
				}
			}
			case "simple_exp":{
				switch(T){
					case "(":
					case "number":
					case "id":
						return "term simple_exp\'";
					case ";":
						if(currentStmt.peek().equals("for_cond"))
							return ERROR+": syntax error";
					case "stringLiteral":
						return ERROR+": not number";
					default:
						return ERROR;
				}
			}
			case "simple_exp\'":{
				switch(T){
					case "+":
					case "-":
						return "addop term simple_exp\'";
					case ")":
					case ">":
					case "<":
					case "<=":
					case ">=":
					case "==":
					case ";":
					case ",":
					case "=":
					case "/=":
					case "+=":
					case "-=":
					case "*=":
					case "++":
					case "--":
						return EPSILON;
					default:
						return ERROR;
				}
			}
			case "term":{
				switch(T){
					case "(":
					case "number":
					case "id":
						return "factor term\'";
					default:
						return ERROR;
				}
			}
			case "term\'":{
				switch(T){
					case "*":
					case "/":
						return "mulop factor term\'";
					case ")":
					case "+":
					case "-":
					case ">":
					case "<":
					case ">=":
					case "<=":
					case "==":
					case ";":
					case ",":
					case "=":
					case "/=":
					case "+=":
					case "-=":
					case "*=":
					case "++":
					case "--":
						return EPSILON;
					default:
						return ERROR;
				}
			}
			case "factor":{
				switch(T){
					case "(":
						return "( exp )";
					case "number":
						return "number";
					case "id":
						return "id";
					default:
						return ERROR;
				}
			}
			case "compop":{
				switch(T){
					case ">":
					case "<":
					case ">=":
					case "<=":
					case "==":
						return T;
					case ";":
						if(currentStmt.peek().equals("for_cond"))
							return ERROR+": syntax error";
					default:
						return ERROR;
				}
			}
			case "addop":{
				switch(T){
					case "+":
					case "-":
						return T;
					default:
						return ERROR;
				}
			}
			case "mulop":{
				switch(T){
					case "*":
					case "/":
						return T;
					default:
						return ERROR;
				}
			}
			case "op":{
				switch(T){
					case "=":
					case "+=":
					case "-=":
					case "/=":
					case "*=":
						return T;
					case "end":
					case "elseif":
					case "else":
						currentStmt.pop();
						return ERROR+": [end] keyword not matched";
					case "$":
						currentStmt.pop();
						return ERROR+": [program_end] keyword not matched";
					default:
						return ERROR;
				}
			}
			default:
				return ERROR;
		}
	}


}
