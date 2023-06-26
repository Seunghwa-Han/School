import util.Token;
import java.util.*;

public class Parser{

	Lexer myLexer; /* scanner */
	String input;  /* input string */
	Token t;       /* token from scanner */
	Stack<String> stackSymbol; /* parsing stack for LL(1) parser */

	Parser(){
		myLexer = new Lexer();
		this.t = new Token();
		stackSymbol = new Stack<>();
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
	
	void exitByError(){
		System.out.println(">> Parsing Failed");
		System.exit(0);
	}

	/* run LR0 parser */
	void run(String input){
		String go_to = "";
		int accept = 0;
		this.input = input; /* input string */
		stackSymbol.push("$");
		stackSymbol.push("0"); /* starting state */

		while(accept == 0)
		{
			String X = stackSymbol.peek(); /* top of the parsing stack */
			if(go_to.length()==0)
				printStack();

			switch(X)
			{
				case "0":{ // shift
					if(go_to.length()>0){
						stackSymbol.push(go_to);
						stackSymbol.push("1");
						go_to="";
					}
					else{
						// System.out.println("shift");
						t = getToken();
						if(t.str.equals("(")){
							stackSymbol.push("(");
							stackSymbol.push("3");
						}
						else if(t.str.equals("a")){
							stackSymbol.push("a");
							stackSymbol.push("2");
						}
						else{
							System.out.println("0");
							exitByError();
						}
					}
					break;
				}
				case "1":{ // reduce: A' -> A
					// System.out.println("accept");
					accept = 1;
					break;
				}
				case "2":{ // reduce: A -> a
					// System.out.println("reduce A -> a");
					for(int i=0; i<2; i++)
						stackSymbol.pop();
					go_to = "A";
					break;
				}
				case "3":{ // shift
					if(go_to.length()>0){
						stackSymbol.push(go_to);
						stackSymbol.push("4");
						go_to = "";
					}
					else{
						// System.out.println("shift");
						t = getToken();
						if(t.str.equals("(")){
							stackSymbol.push("(");
							stackSymbol.push("3");
						}
						else if(t.str.equals("a")){
							stackSymbol.push("a");
							stackSymbol.push("2");
						}
						else{
							System.out.println("3");
							exitByError();
						}
					}
					break;
				}
				case "4":{ // shift 
					// System.out.println("shift");
					t = getToken();
					if(t.str.equals(")")){
						stackSymbol.push(")");
						stackSymbol.push("5");
					}
					else{
						if(t.str.equals("$"))
							System.out.println("\nclosing parenthesis is lacked.");
						exitByError();
					}
					break;
				}
				case "5":{ // reduce: A -> ( A )
					// System.out.println("reduce A -> ( A )");
					for(int i=0; i<6; i++)
						stackSymbol.pop();
					go_to="A";
					break;
				}
				default:
					System.out.println("de");
					exitByError();
					break;
			}
		}

		t = getToken();
		if(t.str.equals("$"))
			System.out.println("\n>> Parsing OK");
		else{
			System.out.println("\nopening parenthesis is lacked.");
			exitByError();
		}
	}

}