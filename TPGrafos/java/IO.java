import java.io.*;
public class IO {
	public int [] readfile(string filename) throws Exception {
		// pass the path to the file as a parameter
		FileReader fr = new FileReader(filename);

		int i;
		while ((i=fr.read()) != -1) {
			System.out.print((char) i);
		}
	}
}
