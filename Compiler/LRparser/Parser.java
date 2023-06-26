import util.Token;
import util.Token.State;
import util.ParsingTable;
import java.util.*;

public class Parser{

	Lexer myLexer; /* scanner */
	String input;  /* input string */
	Token t;       /* token from scanner */
	ParsingTable parsingTable; 
	Stack<String> parsingStack; /* parsing stack for LR parser */

	public Parser(){
		myLexer = new Lexer();
		this.t = new Token();
		parsingStack = new Stack<>();
		parsingTable = new ParsingTable();
	}

	void printStack(){
		String values = Arrays.toString(parsingStack.toArray());
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
	String getToken2(String s){
		if(t.state == State.IDENTIFIER){
			return "id";
		}
		else if(t.state == State.NUMBER){
			return "number";
		}
		else if(t.state == State.STRING_LITERAL){
			return "stringLiteral";
		}
		else if((s.equals("17")||s.equals("54")) && t.str.equals("=")){
			return "=";
		}
		else if(t.state == State.OPERATOR){
			return "op";
		}
		else if(t.state == State.COMPOP){
			return "compop";
		}
		else if(t.state == State.POSTOP){
			return "postop";
		}
		else if(t.state == State.ADDOP){
			return "addop";
		}
		else if(t.state == State.MULOP){
			return "mulop";
		}
		else{
			return t.str;
		}
	}
	
	void exitByError(){
		System.out.println(">> Parsing Failed");
		System.exit(0);
	}

	/* run LR parser */
	public void run(String input){
		this.input = input;
		parsingStack.push("$");
		parsingStack.push("0"); /* starting state */

		int accept = 0;
		int go_to = 0;
		String go_to_what = "";

		String out =""; 
		String s;
		String action ="";

		t = getToken();
		action = getToken2("");
		while(accept == 0)
		{
			s = parsingStack.peek();

			if(go_to == 0){
				out = parsingTable.M(s, action, go_to);
				printStack();
			}
			else if(go_to == 1)
				out = parsingTable.M(s, go_to_what, go_to);

			// shift
			if(out.startsWith("s")){
				parsingStack.push(action);
				parsingStack.push(out.substring(1));
				t = getToken();
				action = getToken2(s);
				// System.out.println("[Shift "+action+" - "+out.substring(1)+"]");
			}
			// reduce 
			else if(out.startsWith("r")){
				int rule = Integer.parseInt(out.substring(1));
				go_to = 1;
				go_to_what = reduceTo(rule);
			}
			// accept
			else if(out.equals("accept")){
				accept = 1;
			}
			// error 
			else if(out.startsWith("error")){
				System.out.println("\n"+out.substring(5));
				exitByError();
			}
			// go to 
			else {
				parsingStack.push(go_to_what);
				parsingStack.push(out);
				go_to = 0;
				// System.out.println("[Reduce to "+go_to_what+" and goto "+out+"]");
			}
		}

		System.out.println("\n>> Parsing OK");
	}

	String reduceTo(int rule){
		String ret;
		switch(rule){
			case 0:{
				ret = "SS"; break;
			}
			case 1:{
				ret = "S"; break;
			}
			case 2: case 3: case 4: case 5: case 6: case 7:{
				ret = "ST"; break;
			}
			case 8: case 9:{
				ret = "L"; break;
			}
			case 10:{
				ret = "BE"; break;
			}
			case 11: case 12:{
				ret = "I"; break;
			}
			case 13: case 14:{
				ret = "IT"; break;
			}
			case 15:{
				ret = "W"; break;
			}
			case 16:{
				ret = "FO"; break;
			}
			case 17: case 18:{
				ret = "FU"; break;
			}
			case 19:{
				ret = "AS"; break;
			}
			case 20:{
				ret = "D"; break;
			}
			case 21: case 22:{
				ret = "DT"; break;
			}
			case 23: case 24:{
				ret = "V"; break;
			}
			case 25: case 26: case 27: case 28:{
				ret = "AT"; break;
			}
			case 29:{
				ret = "CE"; break;
			}
			case 30: case 31:{
				ret = "E"; break;
			}
			case 32: case 33:{
				ret = "T"; break;
			}
			case 34: case 35: case 36:{
				ret = "F"; break;
			}
			default:{
				ret = "ERROR"; break;
			}
		}
		int num;
		if(rule==0||rule==2||rule==3||rule==4||rule==9||rule==11||rule==17||rule==22||rule==23||rule==25||rule==26||rule==31||rule==33||rule==35||rule==36){
			num = 1;
		}
		else if(rule==5||rule==6||rule==7||rule==8||rule==18||rule==20){
			num = 2;
		}
		else if(rule==10||rule==12||rule==19||rule==21||rule==24||rule==27||rule==29||rule==30||rule==32||rule==34){
			num = 3;
		}
		else if(rule==28){
			num = 4;
		}
		else if(rule==14||rule==15||rule==1){
			num = 5;
		}
		else if(rule==13){
			num = 6;
		}
		else if(rule==16){
			num = 9;
		}
		else num = 0;

		for(int i=0; i<num*2; i++)
			parsingStack.pop();
		return ret;
	}

}