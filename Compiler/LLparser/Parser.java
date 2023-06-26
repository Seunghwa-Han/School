import util.Token;
import util.Token.State;
import util.ParsingTable;
import util.Symbol;
import static util.ParsingTable.terminals;
import java.util.*;

public class Parser{

	Lexer myLexer; /* scanner */
	String input;  /* input string */
	Token t;       /* token from scanner */
	String s;      /* first symbol of string to be parsed */
	ParsingTable parsingTable; 
	Stack<String> currentStmt; /* to identify What statement parser is currently parsing */
	Stack<String> stackSymbol; /* parsing stack for LL(1) parser */

	Parser(){
		myLexer = new Lexer();
		this.t = new Token();
		stackSymbol = new Stack<>();
		currentStmt = new Stack<>();
		parsingTable = new ParsingTable();
	}

	void printStack(){
		String values = Arrays.toString(stackSymbol.toArray());
   		System.out.println(values);
	}

	/* get token from scanner */
	Token getToken(){
		if(t.str.length() == input.strip().length()){
			return new Token();
		}
		input = input.stripLeading();
		input = input.substring(t.str.length());
		input = input.stripLeading();
		return myLexer.singleLex(input);
	}
	/* get first symbol of string to be parsed */
	void getSymbol(){
		this.t = getToken();
		if(t.state == State.IDENTIFIER)
			this.s = "id";
		else if(t.state == State.NUMBER)
			this.s = "number";
		else if(t.state == State.STRING_LITERAL)
			this.s = "stringLiteral";
		else
			this.s = t.str;
	}
	/* print error message :unmatch */
	void printUnmatchError(String X, String a){
		System.out.println("");

		if(!currentStmt.empty()){
			if(currentStmt.peek().equals("for_init")){
				if(stackSymbol.peek().equals("integer")){
					System.out.println("[integer] keyword not matched in initialization of for loop");
				}
			}
		}

		if(X.equals(";") && s.equals(","))
		{
			System.out.println("; is expected but , is given");
			System.out.println("maybe declaration keyword is missing ..");
		}
		else if(X.equals("(") && s.equals("id"))
		{
			System.out.println("declaration keyword not matched ..");
		}
		else if(X.equals("begin") || X.equals("end"))
		{
			if(!currentStmt.empty())
				System.out.println(X+" keyword is missing in "+currentStmt.peek());
			else
				System.out.println(X+" keyword is missing");
		}
		// String values = Arrays.toString(currentStmt.toArray());
   		// System.out.println(values);
	}
	/* print error message :empty in parsing table */
	void printEmptyError(String X, String a, String out){
		System.out.println("");

		if(!currentStmt.empty()){
			String current = currentStmt.peek();
			switch(current){
				case "for_init":
					System.out.println(out+" in initialization of for loop");
					break;
				case "for_cond":
					System.out.println(out+" in test part of for loop");
					break;
				case "forStmt":
					System.out.println(out+" in for loop");
					break;
				case "assignStmt":
					System.out.println(out+" in assign statement");
					break;
				case "ifStmt":
					System.out.println(out+ "if statement");
					break;
				case "elseif_part":
					System.out.println(out+ "elseif statement");
					break;
				case "else_part":
					System.out.println(out+ "else statement");
					break;
				case "whileStmt":
					System.out.print(out+ "while statement");
					break;
				default:
					System.out.println(out+" in "+current);
			}
			// String values = Arrays.toString(currentStmt.toArray());
			// System.out.println(values);
		}
		else
			System.out.println(out);
	}
	void exitByError(){
		System.out.println(">> Parsing Failed");
		System.exit(0);
	}

	/* run LL(1) parser */
	void run(String input){
		this.input = input;
		stackSymbol.push("$");
		stackSymbol.push("start");

		getSymbol();
		
		while(!stackSymbol.peek().equals("$"))
		{
			String X = stackSymbol.peek(); /* top of the parsing stack */
			printStack();
			// System.out.println(s);

			/* match */
			if(X.equals(s)) 
			{	
				if(!currentStmt.empty()){
					/* add identifier to symboltable */
					if(currentStmt.peek().equals("defineStmt") && X.equals("id") ||
						currentStmt.peek().equals("for_init") && X.equals("id"))
					{
						Symbol tmp = new Symbol(t.str, "id", "integer");
						parsingTable.symboltable.put(tmp.name, tmp);
					}

					/* integer check in for comdition part */
					if(currentStmt.peek().equals("for_cond") && X.equals("id"))
					{
						Symbol tmp = parsingTable.symboltable.get(t.str);
						if(tmp == null){
							System.out.println("error: undefined variable is used in for loop");
							System.exit(0);
						}
						else if(!tmp.type.equals("integer")){
							System.out.println("error: variable in for loop should be an integer");
							System.exit(0);
						}
					}
					
					/* to modify currentStmt */
					if(X.equals(";") && (currentStmt.peek().equals("assignStmt") || 
									currentStmt.peek().equals("defineStmt") ||
									currentStmt.peek().equals("atomicStmt") ||
									currentStmt.peek().equals("for_init") ||
									currentStmt.peek().equals("for_cond")))
					{
						currentStmt.pop();
					}
					else if(X.equals("end") ){
						currentStmt.pop();
					}
				}
				
				/* po the stack and get the next symbol */
				stackSymbol.pop();
				getSymbol();
			}
			/* unmatch */
			else if(terminals.contains(X))
			{	
				printUnmatchError(X, s);
				exitByError();
			}
			/* look for parsing table */
			else{
				String out = parsingTable.M(X, s, currentStmt);

				/* parsingtable is empty -> error */
				if(out.startsWith(ParsingTable.ERROR)){
					printEmptyError(X, s, out);
					exitByError();
				}
				/* parsingtable is not empty -> OK */
				else{
					stackSymbol.pop();
					if(!out.equals(ParsingTable.EPSILON)) 
					{
						String [] Ys = out.split(" ");
						List<String> listYs = Arrays.asList(Ys);
						Collections.reverse(listYs);
						String [] reverseYs = listYs.toArray(Ys);
						for(String Y : reverseYs){
							stackSymbol.push(Y);
						}
					}
				}
			}
		}

		printStack();
		System.out.println("\n>> Parsing OK");
	}

}