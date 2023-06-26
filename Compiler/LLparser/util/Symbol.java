package util;

public class Symbol {

	public String name; 
	public String terminal; // id or keyword
	public String type;     // type of id
	
	/* name: Time_10_24, terminal: id, type: integer */
	/* name: program, terminal: keyword */

	public Symbol(String name, String terminal) {
		this.name = name;
		this.terminal = terminal;
	}
	public Symbol(String name, String terminal, String type) {
		this.name = name;
		this.terminal = terminal;
		this.type = type;
	}
}
