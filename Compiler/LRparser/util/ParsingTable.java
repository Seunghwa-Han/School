package util;
import java.util.*;

public class ParsingTable {
	public static final String ERROR = "error";
	public static final String ACC = "accept";
	Hashtable<Pair, String> table;

	class Pair{
		public String state;
		public String action;
		public String go_to;
		public Pair(String state, String action, String go_to){
			this.state = state;
			this.action = action;
			this.go_to = go_to;
		}
		@Override
		public boolean equals(Object o){
			if (this == o)	return true;
			if (!(o instanceof Pair))	return false;
			Pair si = (Pair)o;
			return state.equals(si.state) && action.equals(si.action) && go_to.equals(si.go_to);
		}
		@Override
		public int hashCode() {
			return Objects.hash(state, action, go_to);
		}
	}

	void put_actions(int state, List<String> item, String value){
		for(String i : item){
			table.put(new Pair(String.valueOf(state), i, ""), value);
		}
	}
	void put_goto(int state, String go_to, String value){
		table.put(new Pair(String.valueOf(state), "", go_to), value);
	}

	void put_action(int state, String action, String value){
		table.put(new Pair(String.valueOf(state), action, ""), value);
	}

	public ParsingTable(){
		table = new Hashtable<Pair, String>();
		put_action(0, program, "s2");
		put_goto(0, S, "1");

		put_action(1, dollar, ACC);

		put_action(2, id, "s3");

		put_action(3, program_begin, "s4");

		put_action(4, id, "s16");
		put_action(4, IF, "s21");
		put_action(4, WHILE, "s14");
		put_action(4, FOR, "s15");
		put_action(4, INTEGER, "s17");
		put_action(4, CONTINUE, "s18");
		put_action(4, BREAK, "s19");
		put_action(4, DISPLAY, "s20");
		put_goto(4, ST, "6");
		put_goto(4, L, "5");
		put_goto(4, I,  "7");
		put_goto(4, IT, "13");
		put_goto(4, W, "8");
		put_goto(4, FO, "9");
		put_goto(4, AS, "10");
		put_goto(4, D, "11");
		put_goto(4, AT, "12");

		put_action(5, id, "s16");
		put_action(5, program_end, "s22");
		put_action(5, IF, "s21");
		put_action(5, WHILE, "s14");
		put_action(5, FOR, "s15");
		put_action(5, INTEGER, "s17");
		put_action(5, CONTINUE, "s18");
		put_action(5, BREAK, "s19");
		put_action(5, DISPLAY, "s20");
		put_goto(5, ST, "23");
		put_goto(5, I,  "7");
		put_goto(5, IT, "13");
		put_goto(5, W, "8");
		put_goto(5, FO, "9");
		put_goto(5, AS, "10");
		put_goto(5, D, "11");
		put_goto(5, AT, "12");

		put_actions(6, Arrays.asList("id", "program_end", "if", "while", 
				"for", "integer", "continue", "break", "display"), "r9");

		put_actions(7, Arrays.asList("id", "program_end", "if", "while", 
				"for", "integer", "continue", "break", "display"), "r2");

		put_actions(8, Arrays.asList("id", "program_end", "if", "while", 
				"for", "integer", "continue", "break", "display"), "r3");

		put_actions(9, Arrays.asList("id", "program_end", "if", "while", 
				"for", "integer", "continue", "break", "display"), "r4");

		put_action(10, terminator, "s24");
		put_action(11, terminator, "s25");
		put_action(12, terminator, "s26");

		put_action(13, ELSE, "s27");
		put_action(13, ELSEIF, "s28");
		put_actions(13, Arrays.asList("id", "program_end", "if", "while", 
			"for", "integer", "continue", "break", "display"), "r11");
		
		put_action(14, open, "s29");
		put_action(15, open, "s30");

		put_action(16, op, "s31");
		put_action(17, id, "s34");
		put_goto(17, DT, "32");
		put_goto(17, V, "33");

		put_action(18, terminator, "r25");
		put_action(19, terminator, "r26");
		
		put_action(20, open, "s35");
		put_action(21, open, "s36");
		put_action(22, dollar, "r1");

		put_actions(23, Arrays.asList("id", "program_end", "if", "while", 
		"for", "integer", "continue", "break", "display"), "r8");
		put_actions(24, Arrays.asList("id", "program_end", "if", "while", 
		"for", "integer", "continue", "break", "display"), "r5");
		put_actions(25, Arrays.asList("id", "program_end", "if", "while", 
		"for", "integer", "continue", "break", "display"), "r6");
		put_actions(26, Arrays.asList("id", "program_end", "if", "while", 
		"for", "integer", "continue", "break", "display"), "r7");

		put_action(27, begin, "s38");
		put_goto(27, BE, "37");

		put_action(28, open, "s39");

		put_action(29, id, "s46");
		put_action(29, open, "s44");
		put_action(29, number, "s45");
		put_goto(29, CE, "40");
		put_goto(29, E, "41");
		put_goto(29, T, "42");
		put_goto(29, F, "43");

		put_action(30, INTEGER, "s17");
		put_goto(30, D, "47");

		put_action(31, id, "s53");
		put_action(31, open, "s51");
		put_action(31, number, "s52");
		put_goto(31, E, "48");
		put_goto(31, T, "49");
		put_goto(31, F, "50");

		put_action(32, terminator, "r20");
		put_action(32, comma, "s54");

		put_actions(33, Arrays.asList(";", ","), "r22");

		put_actions(34, Arrays.asList(";", ","), "r23");
		put_action(34, eq, "s55");

		put_action(35, close, "s56");
		put_action(35, stringLiteral, "s57");

		put_action(36, id, "s46");
		put_action(36, open, "s44");
		put_action(36, number, "s45");
		put_goto(36, CE, "58");
		put_goto(36, E, "41");
		put_goto(36, T, "42");
		put_goto(36, F, "43");

		put_actions(37, Arrays.asList("id", "program_end", "if", "while", 
		"for", "integer", "continue", "break", "display"), "r12");

		put_action(38, id, "s16");
		put_action(38, IF, "s70");
		put_action(38, WHILE, "s68");
		put_action(38, FOR, "s69");
		put_action(38, INTEGER, "s17");
		put_action(38, CONTINUE, "s18");
		put_action(38, BREAK, "s19");
		put_action(38, DISPLAY, "s20");
		put_goto(38, ST, "60");
		put_goto(38, L, "59");
		put_goto(38, I, "61");
		put_goto(38, IT, "67");
		put_goto(38, W, "62");
		put_goto(38, FO, "63");
		put_goto(38, AS, "64");
		put_goto(38, D, "65");
		put_goto(38, AT, "66");

		put_action(39, id, "s46");
		put_action(39, open, "s44");
		put_action(39, number, "s45");
		put_goto(39, CE, "71");
		put_goto(39, E, "41");
		put_goto(39, T, "42");
		put_goto(39, F, "43");

		put_action(40, close, "s72");
		put_action(41, compop, "s73");
		put_action(41, addop, "s74");
		
		put_actions(42, Arrays.asList("compop", "addop"), "r31");
		put_action(42, mulop, "s75");

		put_actions(43, Arrays.asList("compop", "addop", "mulop"), "r33");

		put_action(44, id, "s81");
		put_action(44, open, "s79");
		put_action(44, number, "80");
		put_goto(44, E, "76");
		put_goto(44, T, "77");
		put_goto(44, F, "78");

		put_actions(45, Arrays.asList("compop", "addop", "mulop"), "r35");
		put_actions(46, Arrays.asList("compop", "addop", "mulop"), "r36");

		put_action(47, terminator, "s82");

		put_action(48, terminator, "r19");
		put_action(48, addop, "s83");

		put_actions(49, Arrays.asList(";", "addop"), "r31");
		put_action(49, mulop, "s84");

		put_actions(50, Arrays.asList(";", "addop", "mulop"), "r33");

		put_action(51, id, "s81");
		put_action(51, open, "s79");
		put_action(51, number, "s80");
		put_goto(51, E, "85");
		put_goto(51, T, "77");
		put_goto(51, F, "78");

		put_actions(52, Arrays.asList(";", "addop", "mulop"), "r35");
		put_actions(53, Arrays.asList(";", "addop", "mulop"), "r36");

		put_action(54, id, "s34");
		put_goto(54, V, "86");

		put_action(55, id, "s92");
		put_action(55, open, "s90");
		put_action(55, number, "s91");
		put_goto(55, E, "87");
		put_goto(55, T, "88");
		put_goto(55, F, "89");

		put_action(56, terminator, "r27");

		put_action(57, close, "s93");
		put_action(58, close, "s94");

		put_action(59, id, "s16");
		put_action(59, end, "s95");
		put_action(59, IF, "s70");
		put_action(59, WHILE, "s68");
		put_action(59, FOR, "s69");
		put_action(59, INTEGER, "s17");
		put_action(59, CONTINUE, "s18");
		put_action(59, BREAK, "s19");
		put_action(59, DISPLAY, "s20");
		put_goto(59, ST, "96");
		put_goto(59, I, "61");
		put_goto(59, IT, "67");
		put_goto(59, W, "62");
		put_goto(59, FO, "63");
		put_goto(59, AS, "64");
		put_goto(59, D, "65");
		put_goto(59, AT, "66");

		put_actions(60, Arrays.asList("id", "end", "if", "while", 
		"for", "integer", "continue", "break", "display"), "r9");
		put_actions(61, Arrays.asList("id", "end", "if", "while", 
		"for", "integer", "continue", "break", "display"), "r2");
		put_actions(62, Arrays.asList("id", "end", "if", "while", 
		"for", "integer", "continue", "break", "display"), "r3");
		put_actions(63, Arrays.asList("id", "end", "if", "while", 
		"for", "integer", "continue", "break", "display"), "r4");

		put_action(64, terminator, "s97");
		put_action(65, terminator, "s98");
		put_action(66, terminator, "s99");

		put_actions(67, Arrays.asList("id", "end", "if", "while", 
		"for", "integer", "continue", "break", "display"), "r11");
		put_action(67, ELSE, "s100");
		put_action(67, ELSEIF, "s101");

		put_action(68, open, "s102");
		put_action(69, open, "s103");
		put_action(70, open, "s104");

		put_action(71, close, "s105");

		put_action(72, begin, "s38");
		put_goto(72, BE, "106");

		put_action(73, id, "s81");
		put_action(73, open, "s79");
		put_action(73, number, "s80");
		put_goto(73, E, "107");
		put_goto(73, T, "77");
		put_goto(73, F, "78");

		put_action(74, id, "s46");
		put_action(74, open, "s44");
		put_action(74, number, "s45");
		put_goto(74, T, "108");
		put_goto(74, F, "43");

		put_action(75, id, "s46");
		put_action(75, open, "s44");
		put_action(75, number, "s45");
		put_goto(75, F, "109");

		put_action(76, close, "s110");
		put_action(76, addop, "s111");

		put_actions(77, Arrays.asList(")", "addop"), "r31");
		put_action(77, mulop, "s112");

		put_actions(78, Arrays.asList(")", "addop", "mulop"), "r33");

		put_action(79, id, "s81");
		put_action(79, open, "s79");
		put_action(79, number, "s80");
		put_goto(79, E, "113");
		put_goto(79, T, "77");
		put_goto(79, F, "78");

		put_actions(80, Arrays.asList(")", "addop", "mulop"), "r35");
		put_actions(81, Arrays.asList(")", "addop", "mulop"), "r36");

		put_action(82, id, "s46");
		put_action(82, open, "s44");
		put_action(82, number, "s45");
		put_goto(82, CE, "114");
		put_goto(82, E, "115");
		put_goto(82, T, "42");
		put_goto(82, F, "43");

		put_action(83, id, "s53");
		put_action(83, open, "s51");
		put_action(83, number, "s52");
		put_goto(83, T, "116");
		put_goto(83, F, "50");

		put_action(84, id, "s53");
		put_action(84, open, "s51");
		put_action(84, number, "s52");
		put_goto(84, F, "117");

		put_action(85, close, "s118");
		put_action(85, addop, "s111");

		put_actions(86, Arrays.asList(";", ","), "r21");

		put_actions(87, Arrays.asList(";", ","), "r24");
		put_action(87, addop, "s119");

		put_actions(88, Arrays.asList(";", ",", "addop"), "r31");
		put_action(88, mulop, "s120");

		put_actions(89, Arrays.asList(";", ",", "addop", "mulop"), "r33");

		put_action(90, id, "s81");
		put_action(90, open, "s79");
		put_action(90, number, "s80");
		put_goto(90, E, "121");
		put_goto(90, T, "77");
		put_goto(90, F, "78");

		put_actions(91, Arrays.asList(";", ",", "addop", "mulop"), "r35");
		put_actions(92, Arrays.asList(";", ",", "addop", "mulop"), "r36");

		put_action(93, terminator, "r28");

		put_action(94, begin, "s123");
		put_goto(94, BE, "122");

		put_actions(95, Arrays.asList("id", "program_end", "if", "while", 
		"for", "integer", "continue", "break", "display"), "r10");

		put_actions(96, Arrays.asList("id", "end", "if", "while", 
		"for", "integer", "continue", "break", "display"), "r8");
		put_actions(97, Arrays.asList("id", "end", "if", "while", 
		"for", "integer", "continue", "break", "display"), "r5");
		put_actions(98, Arrays.asList("id", "end", "if", "while", 
		"for", "integer", "continue", "break", "display"), "r6");
		put_actions(99, Arrays.asList("id", "end", "if", "while", 
		"for", "integer", "continue", "break", "display"), "r7");

		put_action(100, begin, "s125");
		put_goto(100, BE, "124");

		put_action(101, open, "s126");

		put_action(102, id, "s46");
		put_action(102, open, "s44");
		put_action(102, number, "s45");
		put_goto(102, CE, "127");
		put_goto(102, E, "41");
		put_goto(102, T, "42");
		put_goto(102, F, "43");

		put_action(103, INTEGER, "s17");
		put_goto(103, D, "128");

		put_action(104, id, "s46");
		put_action(104, open, "s44");
		put_action(104, number, "s45");
		put_goto(104, CE, "129");
		put_goto(104, E, "41");
		put_goto(104, T, "42");
		put_goto(104, F, "43");

		put_action(105, begin, "s123");
		put_goto(105, BE, "130");

		put_actions(106, Arrays.asList("id", "program_end", "if", "while", 
		"for", "integer", "continue", "break", "display"), "r15");

		put_action(107, close, "r29");
		put_action(107, addop, "s111");

		put_actions(108, Arrays.asList("compop", "addop"), "r30");
		put_action(108, mulop, "s75");

		put_actions(109, Arrays.asList("compop", "addop", "mulop"), "r32");
		put_actions(110, Arrays.asList("compop", "addop", "mulop"), "r34");

		put_action(111, id, "s81");
		put_action(111, open, "s79");
		put_action(111, number, "s80");
		put_goto(111, T, "131");
		put_goto(111, F, "78");

		put_action(112, id, "s81");
		put_action(112, open, "s79");
		put_action(112, number, "s80");
		put_goto(112, F, "132");

		put_action(113, close, "s133");
		put_action(113, addop, "s111");

		put_action(114, terminator,"s134");

		put_action(115, compop, "s135");
		put_action(115, addop, "s74");

		put_actions(116, Arrays.asList(";", "addop"), "r30");
		put_action(116, mulop, "s112");

		put_actions(117, Arrays.asList(";", "addop", "mulop"), "r32");
		put_actions(118, Arrays.asList(";", "addop", "mulop"), "r34");

		put_action(119, id, "s92");
		put_action(119, open, "s90");
		put_action(119, number, "s91");
		put_goto(119, T, "136");
		put_goto(119, F, "89");

		put_action(120, id, "s92");
		put_action(120, open, "s90");
		put_action(120, number, "s91");
		put_goto(120, F, "137");

		put_action(121, close, "s138");
		put_action(121, addop, "s111");

		put_actions(122, Arrays.asList("id", "program_end", "else", "elseif", "if", "while", 
		"for", "integer", "continue", "break", "display"), "r14");

		put_action(123, id, "s16");
		put_action(123, IF, "s70");
		put_action(123, WHILE, "s68");
		put_action(123, FOR, "s69");
		put_action(123, INTEGER, "s17");
		put_action(123, CONTINUE, "s18");
		put_action(123, BREAK, "s19");
		put_action(123, DISPLAY, "s20");
		put_goto(123, ST, "60");
		put_goto(123, L, "139");
		put_goto(123, I, "61");
		put_goto(123, IT, "67");
		put_goto(123, W, "62");
		put_goto(123, FO, "63");
		put_goto(123, AS, "64");
		put_goto(123, D, "65");
		put_goto(123, AT, "66");

		put_actions(124, Arrays.asList("id", "end", "if", "while", 
		"for", "integer", "continue", "break", "display"), "r12");

		put_action(125, id, "s16");
		put_action(125, IF, "s70");
		put_action(125, WHILE, "s68");
		put_action(125, FOR, "s69");
		put_action(125, INTEGER, "s17");
		put_action(125, CONTINUE, "s18");
		put_action(125, BREAK, "s19");
		put_action(125, DISPLAY, "s20");
		put_goto(125, ST, "60");
		put_goto(125, L, "140");
		put_goto(125, I, "61");
		put_goto(125, IT, "67");
		put_goto(125, W, "62");
		put_goto(125, FO, "63");
		put_goto(125, AS, "64");
		put_goto(125, D, "65");
		put_goto(125, AT, "66");

		put_action(126, id, "s46");
		put_action(126, open, "s44");
		put_action(126, number, "s45");
		put_goto(126, CE, "141");
		put_goto(126, E, "41");
		put_goto(126, T, "42");
		put_goto(126, F, "43");

		put_action(127, close, "s142");
		put_action(128, terminator, "s143");
		put_action(129, close, "s144");

		put_actions(130, Arrays.asList("id", "program_end", "else", "elseif", "if", "while", 
		"for", "integer", "continue", "break", "display"), "r13");

		put_actions(131, Arrays.asList(")", "addop"), "r30");
		put_action(131, mulop, "s112");

		put_actions(132, Arrays.asList(")", "addop", "mulop"), "r32");
		put_actions(133, Arrays.asList(")", "addop", "mulop"), "r34");

		put_action(134, id, "s147");
		put_goto(134, FU, "145");
		put_goto(134, AS, "146");

		put_action(135, id, "s53");
		put_action(135, open, "s51");
		put_action(135, number, "s52");
		put_goto(135, E, "148");
		put_goto(135, T, "49");
		put_goto(135, F, "50");

		put_actions(136, Arrays.asList(";", ",", "addop"), "r30");
		put_action(136, mulop, "s120");
		put_actions(137, Arrays.asList(";", ",", "addop", "mulop"), "r32");
		put_actions(138, Arrays.asList(";", ",", "addop", "mulop"), "r34");

		put_action(139, id, "s16");
		put_action(139, end, "s149");
		put_action(139, IF, "s70");
		put_action(139, WHILE, "s68");
		put_action(139, FOR, "s69");
		put_action(139, INTEGER, "s17");
		put_action(139, CONTINUE, "s18");
		put_action(139, BREAK, "s19");
		put_action(139, DISPLAY, "s20");
		put_goto(139, ST, "96");
		put_goto(139, I, "61");
		put_goto(139, IT, "67");
		put_goto(139, W, "62");
		put_goto(139, FO, "63");
		put_goto(139, AS, "64");
		put_goto(139, D, "65");
		put_goto(139, AT, "66");

		put_action(140, id, "s16");
		put_action(140, end, "s150");
		put_action(140, IF, "s70");
		put_action(140, WHILE, "s68");
		put_action(140, FOR, "s69");
		put_action(140, INTEGER, "s17");
		put_action(140, CONTINUE, "s18");
		put_action(140, BREAK, "s19");
		put_action(140, DISPLAY, "s20");
		put_goto(140, ST, "96");
		put_goto(140, I, "61");
		put_goto(140, IT, "67");
		put_goto(140, W, "62");
		put_goto(140, FO, "63");
		put_goto(140, AS, "64");
		put_goto(140, D, "65");
		put_goto(140, AT, "66");

		put_action(141, close, "s151");
		put_action(142, begin, "s125");
		put_goto(142, BE, "152");

		put_action(143, id, "s46");
		put_action(143, open, "s44");
		put_action(143, number, "s45");
		put_goto(143, CE, "153");
		put_goto(143, E, "115");
		put_goto(143, T, "42");
		put_goto(143, F, "53");

		put_action(144, begin, "s155");
		put_goto(144, BE, "154");

		put_action(145, close, "s156");
		put_action(146, close, "r17");

		put_action(147, postop, "s157");
		put_action(147, op, "s158");

		put_action(148, terminator, "r29");
		put_action(148, addop, "s83");

		put_actions(149, Arrays.asList("id", "program_end", "else", "elseif", "if", "while", 
		"for", "integer", "continue", "break", "display"), "r10");

		put_actions(150, Arrays.asList("id", "end", "if", "while", 
		"for", "integer", "continue", "break", "display"), "r10");

		put_action(151, begin, "s155");
		put_goto(151, BE, "159");

		put_actions(152, Arrays.asList("id", "end", "if", "while", 
		"for", "integer", "continue", "break", "display"), "r15");

		put_action(153, terminator, "s160");

		put_actions(154, Arrays.asList("id", "end", "else", "elseif", "if", "while", 
		"for", "integer", "continue", "break", "display"), "r14");

		put_action(155, id, "s16");
		put_action(155, IF, "s70");
		put_action(155, WHILE, "s68");
		put_action(155, FOR, "s69");
		put_action(155, INTEGER, "s17");
		put_action(155, CONTINUE, "s18");
		put_action(155, BREAK, "s19");
		put_action(155, DISPLAY, "s20");
		put_goto(155, ST, "60");
		put_goto(155, L, "161");
		put_goto(155, I, "61");
		put_goto(155, IT, "67");
		put_goto(155, W, "62");
		put_goto(155, FO, "63");
		put_goto(155, AS, "64");
		put_goto(155, D, "65");
		put_goto(155, AT, "66");

		put_action(156, begin, "s38");
		put_goto(156, BE, "162");

		put_action(157, close, "r18");

		put_action(158, id, "s81");
		put_action(158, open, "s79");
		put_action(158, number, "s80");
		put_goto(158, E, "163");
		put_goto(158, T, "77");
		put_goto(158, F, "78");

		put_actions(159, Arrays.asList("id", "end", "else", "elseif", "if", "while", 
		"for", "integer", "continue", "break", "display"), "r13");

		put_action(160, id, "s147");
		put_goto(160, FU, "164");
		put_goto(160, AS, "146");

		put_action(161, id, "s16");
		put_action(161, end, "s165");
		put_action(161, IF, "s70");
		put_action(161, WHILE, "s68");
		put_action(161, FOR, "s69");
		put_action(161, INTEGER, "s17");
		put_action(161, CONTINUE, "s18");
		put_action(161, BREAK, "s19");
		put_action(161, DISPLAY, "s20");
		put_goto(161, ST, "96");
		put_goto(161, I, "61");
		put_goto(161, IT, "67");
		put_goto(161, W, "62");
		put_goto(161, FO, "63");
		put_goto(161, AS, "64");
		put_goto(161, D, "65");
		put_goto(161, AT, "66");

		put_actions(162, Arrays.asList("id", "program_end", "if", "while", 
		"for", "integer", "continue", "break", "display"), "r16");

		put_action(163, close, "r19");
		put_action(163, addop, "s111");
		put_action(164, close, "s166");

		put_actions(165, Arrays.asList("id", "end", "else", "elseif", "if", "while", 
		"for", "integer", "continue", "break", "display"), "r10");

		put_action(165, begin, "s125");
		put_goto(165, BE, "167");

		put_actions(167, Arrays.asList("id", "end", "else", "elseif", "if", "while", 
		"for", "integer", "continue", "break", "display"), "r16");
	}

	/* get the parsing table output */
	public String M(String state, String token, int go_to)
	{
		String out;
		if(go_to == 1)
			out = table.get(new Pair(state, "", token));
		else
			out = table.get(new Pair(state, token, ""));
		
		if(out == null){
			String msg = "";
			// System.out.println(state+" "+token+" "+go_to);
			if(state.equals("0")&&token.equals("id")){
				msg = "illegal keyword";
			}
			else if(state.equals("16")&&token.equals("$")){
				msg = "illegal keyword";
			}
			else if(state.equals("15")&&token.equals("id")){
				msg = "declaration error";
			}
			else if(state.equals("52")&&token.equals(",")){
				msg = "keyword missing in declaration";
			}
			else if(state.equals("94")){
				msg = "keyword missing in if statement: begin";
			}
			else if(state.equals("46")&&token.equals(";")){
				msg = "loop conditional syntax error";
			}
			else if(state.equals("150")&&token.equals("program_end")){
				msg = "missing keword: end";
			}
			return ERROR+msg;
		}
		return out;
	}

	public static final String program = "program";
	public static final String id = "id";
	public static final String program_begin = "program_begin";
	public static final String program_end = "program_end";
	public static final String terminator = ";";
	public static final String begin = "begin";
	public static final String end = "end";
	public static final String ELSE = "else";
	public static final String ELSEIF = "elseif";
	public static final String open = "(";
	public static final String close = ")";
	public static final String IF = "if";
	public static final String WHILE = "while";
	public static final String FOR = "for";
	public static final String postop = "postop";
	public static final String op = "op";
	public static final String eq = "=";
	public static final String INTEGER = "integer";
	public static final String comma = ",";
	public static final String CONTINUE = "continue";
	public static final String BREAK = "break";
	public static final String DISPLAY = "display";
	public static final String stringLiteral = "stringLiteral";
	public static final String compop = "compop";
	public static final String addop = "addop";
	public static final String mulop = "mulop";
	public static final String number = "number";
	public static final String dollar = "$";

	public static final String S = "S";
	public static final String ST = "ST";
	public static final String L = "L";
	public static final String BE = "BE";
	public static final String I = "I";
	public static final String IT = "IT";
	public static final String W = "W";
	public static final String FO = "FO";
	public static final String FU = "FU";
	public static final String AS = "AS";
	public static final String D = "D";
	public static final String DT = "DT";
	public static final String V = "V";
	public static final String AT = "AT";
	public static final String CE = "CE";
	public static final String E = "E";
	public static final String T = "T";
	public static final String F = "F";
}
