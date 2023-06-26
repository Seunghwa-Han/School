import util.Token;
import util.Token.State;

public class Parser{

	Lexer myLexer;
	String input;
	Token t;

	boolean isType(){
		if(t.str.equals("integer"))
			return true;
		return false;
	}

	Parser(){
		myLexer = new Lexer();
		this.t = new Token();
	}

	Token getToken(){
		if(t.str.length() == input.strip().length()){
			return new Token();
		}
		input = input.stripLeading();
		input = input.substring(t.str.length());
		input = input.stripLeading();
		return myLexer.singleLex(input);
	}

	void run(String input){
		this.input = input;
		this.t = getToken();
		
		while(true){
			if(t.state == State.START){
				System.out.println("Parsing OK");
				break;
			}
			start();
		}
	}

	void match(Token expectedT, String error){
		if(expectedT.state!=State.IDENTIFIER && t.str.equals(expectedT.str) || expectedT.state == State.IDENTIFIER && t.state == expectedT.state){
			t = getToken();
		}
		else{
			System.out.println("Parsing Error");
			System.out.println("\t"+error);
			System.exit(0);
		}
	}

	void start(){
		match(new Token(State.KEYWORD, "program"), "missing or wrong keyword: program");
		match(new Token(State.IDENTIFIER, ""), "missing identifier for program");
		match(new Token(State.KEYWORD, "program_begin"), "missing or wrong keyword: program_begin");
		while((!t.str.equals("program_end") || t.state!=State.START) && input.strip().length()-t.str.length() >0){
			stmt();
		}
		match(new Token(State.KEYWORD, "program_end"), "missing or wrong keyword: program_end");
	}

	void stmt(){ 
		if(t.str.equals("if"))
			ifStmt();
		else if(t.str.equals("while"))
			whileStmt();
		else if(t.state == State.KEYWORD){
			if(isType())
				defineStmt();
			else
				atomicStmt();
		}
		else
			assignStmt();
	}

	void atomicStmt(){
		if(t.str.equals("display")){
			match(t, "");
			match(new Token(State.SPECIAL_CHAR, "("), "missing open parenthesis");
			if(!t.str.equals(")")){
				match(new Token(State.STRING_LITERAL, t.str), "");
			}
			match(new Token(State.SPECIAL_CHAR, ")"), "missing close parenthesis");
		}
		else if(t.str.equals("continue")){
			match(t, "");
		}
		else if(t.str.equals("break")){
			match(t, "");
		}
		match(new Token(State.STATEMENT_TERMINATOR, ";"), "missing statement terminator");
		
	}

	void defineStmt(){
		String error = "In define Statement, missing ";
		match(t, error);
		match(new Token(State.IDENTIFIER, ""), error+"identifier");
		if(t.str.equals("=")){
			match(t, error);
			exp();
		}
		while(t.str.equals(",")){
			match(t, error);
			match(new Token(State.IDENTIFIER, ""), error+"identifier");
			if(t.str.equals("=")){
				match(t, error);
				exp();
			}
		}
		match(new Token(State.STATEMENT_TERMINATOR, ";"), error+";");
	}

	void whileStmt(){
		String error = "In while statement, there is no ";
		match(t, error+"while");
		match(new Token(State.SPECIAL_CHAR, "("), error+"(");
		exp();
		match(new Token(State.SPECIAL_CHAR, ")"), error+")");
		match(new Token(State.KEYWORD, "begin"), error+"begin [missing keyword]");
		while(!t.str.equals("end") && t.state!=State.START){
			stmt();
		}
		match(new Token(State.KEYWORD, "end"), error+"end [missing keyword]");
	}

	void ifStmt(){ 
		String error = "In if statement, there is no ";
		match(new Token(State.KEYWORD, "if"), error+"if");
		match(new Token(State.SPECIAL_CHAR, "("), error+"(");
		exp();
		match(new Token(State.SPECIAL_CHAR, ")"), error+")");
		match(new Token(State.KEYWORD, "begin"), error+"begin [missing keyword]");
		while(!t.str.equals("end") && t.state!=State.START){
			stmt();
		}
		match(new Token(State.KEYWORD, "end"), error+"end [missing keyword]");

		while(t.str.equals("elseif")){
			match(t, error);
			match(new Token(State.SPECIAL_CHAR, "("), error+"(");
			exp();
			match(new Token(State.SPECIAL_CHAR, ")"), error+")");
			match(new Token(State.KEYWORD, "begin"), error+"begin [missing keyword]");
			while(!t.str.equals("end") && t.state!=State.START){
				stmt();
			}
			match(new Token(State.KEYWORD, "end"), error+"end [missing keyword]");
		}

		if(t.str.equals("else")){
			match(t, error);
			match(new Token(State.KEYWORD, "begin"), error+"begin [missing keyword]");
			while(!t.str.equals("end") && t.state!=State.START){
				stmt();
			}
			match(new Token(State.KEYWORD, "end"), error+"end [missing keyword]");
		}
	}

	void assignStmt(){ // assignStmt -> id = exp ; 
		String error = "In assignment statement, missing ";
		// if(t.str.equals("(")){
		// 	System.out.println("missing keyword if or while");
		// 	System.exit(0);
		// }

		match(new Token(State.IDENTIFIER, ""), error+"identifier");
		if(t.state == State.IDENTIFIER){
			System.out.println("Parser Error\n\twrong keyword for type");
			System.exit(0);
		}
		match(new Token(State.OPERATOR, "="), error+"=");
		exp();
		if(t.str.equals(",")){
			System.out.println("Parser Error\n\tmissing keyword for type");
			System.exit(0);
		}
		match(new Token(State.STATEMENT_TERMINATOR, ";"), error+";");
	}

	void exp(){ // exp -> simpleExp { compop simple_exp }
		String error = "In expression(exp), COMPOP";
		simpleExp();
		while(t.state == State.COMPOP){
			match(t, error);
			simpleExp();
		}
	}

	void simpleExp(){ // simpleExp -> term { addop term }
		String error = "In simpleExp, ADDOP";
		term();
		while(t.state == State.ADDOP){ // + || -
			match(t, error);  
			term();
		}
	}

	void term(){ // term -> factor { mulop factor }
		String error = "In term, MULOP";
		factor();
		while(t.state == State.MULOP){
			match(t, error);
			factor();
		}
	}

	void factor(){ // factor -> ( exp ) | number | id
		String error = "factor error: no ";
		if(t.str.equals("(")){
			match(new Token(State.SPECIAL_CHAR, "("), error+"( in expression");
			exp();
			match(new Token(State.SPECIAL_CHAR, ")"), error+") in expression");
		}
		else if(t.state == State.NUMBER){
			match(t, error+"number");
		}
		else if(t.state == State.IDENTIFIER){
			match(t, error+"idenfier");
		}
		else{
			System.out.println("Parser Error\n\tfactor error: there is no appropriate id or number or expression");
			System.exit(0);
		}
	}

}