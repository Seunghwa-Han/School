import java.util.List;
import java.util.Arrays;
import util.Token;
import util.Token.State;

public class Lexer {

	static final List<String> reserved = Arrays.asList("program", "program_begin", "integer", "if",
		"begin", "display", "end", "elseif", "program_end", "else", "while", "break");

	public boolean isKeyword(Token t){
		for(String s: reserved){
			if(s.equals(t.str)){
				return true;
			}
		}
		return false;
	}

	public void printToken(Token t){
		if (t.state == State.IDENTIFIER){
			if(isKeyword(t))
				t.setState(State.KEYWORD);
		}
		System.out.println(t);
	}

	private State getNextState(State curState, Character ch){
		switch(curState){
			case START:{
				if(Character.isAlphabetic(ch))
					return State.IDENTIFIER;
				else if(Character.isDigit(ch))
					return State.NUMBER;
				else if(ch == '\"')
					return State.PRE_LITERAL;
				else if(Character.isWhitespace(ch))
					return State.START;
				else if(ch == ';')
					return State.STATEMENT_TERMINATOR;
				else if(ch == '+' || ch == '-')
					return State.ADDOP;
				else if(ch == '*' || ch == '/')
					return State.MULOP;
				else if(ch == '>' || ch == '<')
					return State.COMPOP;
				else if(ch == '=')
					return State.OPERATOR;
				else 
					return State.SPECIAL_CHAR;
			}
			case PRE_LITERAL:{
				return ch=='\"' ? State.STRING_LITERAL : State.PRE_LITERAL;
			}
			case IDENTIFIER:{
				return Character.isAlphabetic(ch)||Character.isDigit(ch)||ch=='_' ? State.IDENTIFIER : State.START;
			}
			case NUMBER:{
				if(Character.isDigit(ch))
					return State.NUMBER;
				else if(Character.isAlphabetic(ch) || ch=='_')
					return State.ILLEGAL;
				else
					return State.START;
			}
			case STRING_LITERAL:
			case STATEMENT_TERMINATOR:
			case SPECIAL_CHAR:
			case MULOP:
			case ADDOP:
				return State.START;
			case COMPOP:
			case OPERATOR:
				return ch=='=' ? State.COMPOP : State.START;
			case ILLEGAL:
				return Character.isWhitespace(ch) ? State.START : State.ILLEGAL;
			default:
				return curState;
		}
	}

	public Token singleLex(String line){

		int size = line.length();
		Token t = new Token();
		State curState = State.START;
		State nextState;

		for(int i=0; i<size; i++)
		{
			char ch = line.charAt(i);

			nextState = getNextState(curState, ch);

			if(nextState != State.START){
				t.addChar(ch);
			}

			if(curState != State.START && nextState == State.START){
				if (t.state == State.IDENTIFIER){
					if(isKeyword(t))
						t.setState(State.KEYWORD);
				}
				return t;
				// t.str = "";
				// if(!Character.isWhitespace(ch)) i--;
			}

			curState = nextState;
			t.setState(curState);
			
		}
		return t;
	}

	public void lex(String line){

		int size = line.length();
		Token t = new Token();
		State curState = State.START;
		State nextState;

		for(int i=0; i<size; i++)
		{
			char ch = line.charAt(i);

			nextState = getNextState(curState, ch);

			if(nextState != State.START){
				t.addChar(ch);
			}

			if(curState != State.START && nextState == State.START){
				printToken(t);
				t.str = "";
				if(!Character.isWhitespace(ch)) i--;
			}

			curState = nextState;
			t.setState(curState);
			
		}
	}	
}
