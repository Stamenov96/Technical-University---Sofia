import java.io.IOException;

public class Main {

	public static void main(String[] args) throws IOException {

		ProductLoader pl = new  ProductLoader();
		System.out.println(pl.getNumberOfRows());
		pl.importDataFromFile();
	}

}
