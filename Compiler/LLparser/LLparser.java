import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;

public class LLparser{

	public static void main(String[] args){
		LLparser runner = new LLparser();
		runner.run(args);
	}

	public void run(String[] filename){
		try{
			BufferedReader reader = new BufferedReader(
				new FileReader(filename[0])
			);	

			String line, res="";
			Parser myParser = new Parser();

			while((line = reader.readLine()) != null)
			{
				res += line+"\n";
			}
			
			myParser.run(res+"$\n");
			reader.close();
		}
		catch (FileNotFoundException e){
			e.printStackTrace();
		}
		catch (IOException e){
			e.printStackTrace();
		}
	}
}