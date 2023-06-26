package util;
public class Token {

	public static enum State{
		START, ILLEGAL, 
		KEYWORD, IDENTIFIER, NUMBER, 
		STRING_LITERAL, PRE_LITERAL,
		STATEMENT_TERMINATOR, SPECIAL_CHAR, OPERATOR, ADDOP, MULOP, COMPOP
	}

	public State state;
	public String str;

	public Token(){
		state = State.START;
		str = "";
	}
	public Token(State s, String st){
		state = s;
		str = st;
	}
	public String toString(){
		return state + ": " + str;
	}
	public void setState(State s){
		state = s;
	}
	public void addChar(char ch){
		str += Character.toString(ch);
	}	
}
