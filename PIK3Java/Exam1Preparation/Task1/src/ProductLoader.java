import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.function.ToDoubleFunction;

public class ProductLoader implements ImportData {

	
	public int getNumberOfRows() throws IOException {
		
		FileReader fr = new FileReader("salesproducts.txt");
		BufferedReader reader = new BufferedReader(fr);

		int lines = 0;
		while (reader.readLine() != null)
			lines++;
		reader.close();
		return lines;
	}

	@Override
	public Object[] importDataFromFile() throws IOException {

		int numOfRows = getNumberOfRows();
		Product[] data = new Product[numOfRows];
		FileReader fr = new FileReader("salesproducts.txt");
		BufferedReader reader = new BufferedReader(fr);
		
		for (int i = 0; i < numOfRows; i++) {
			String[] tokens = reader.readLine().split("#");
			
			if(tokens[0].equals("1")){
				data[i] = new Electronics(tokens[3],Double.parseDouble(tokens[4]),Integer.parseInt(tokens[5]), new Provider(tokens[1],tokens[2]));
				
			}
			if(tokens[0].equals("2")){
				data[i] = new Book(tokens[3],Double.parseDouble(tokens[4]),Integer.parseInt(tokens[5]), new Provider(tokens[1],tokens[2]));
			System.out.println("New Book : "+tokens[3]+" "+Double.parseDouble(tokens[4])+" "+Integer.parseInt(tokens[5])+" With provider: "+tokens[1]+" "+tokens[2]);
			}
				
		}
		
		return data;
	}

}
