import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;
import java.util.LinkedList;
import java.util.Scanner;

public class CustomerThread extends Thread {

	private Socket socket;
	private String[] bulstats;
	private LinkedList<String> first;
	private LinkedList<String> second;

	public CustomerThread(Socket socket, String[] bulstats, LinkedList<String> First, LinkedList<String> Second) {
		// konstruktor
		this.socket = socket;
		this.bulstats = bulstats;
		this.first = First;
		this.second = Second;
	}

	@Override
	public void run() { // ovveride-va run za sa mojem da kajem na nishkata start 

		try {
			@SuppressWarnings("resource")// mojesh da ne go pishesh na kontrolnoto eclipse go generira
			Scanner scan = new Scanner(socket.getInputStream());
			// scan - promenliva koqto chete ot socket(klienta)
			//getInputStream -vhoden potok ot danni
			PrintStream output = new PrintStream(socket.getOutputStream());
			// otuput - izprashta na socketa(klienta)
			//getOutputStream - stream- a kum klienta
			
			output.println("GET_BULSTAT");// prashtame na klienta zaqvka za bulstat
			String bulstat = scan.nextLine(); // chetem otgovora na klienta

			for (int i = 0; i < bulstats.length; i++) {// obhojdame masiva s bulstatite
				if (bulstat.equals(bulstats[i])) { // proverqvame dali bulstata na klienta se sudurja v masiva
					output.println("GETCODE");// ako se sudurja mu prashtame zaqvka za registracionen kod
					String regcode = scan.nextLine(); //  chetem reg. koda
					//za da razbera koi linked list(spisucite sus zaqvkite na otdelnite firmi)
					//da podam na isRequestAvailable izpolzvam indeksite im v masiva
					if (i == 0) //ako e purviqt prashtam first
						output.println(isRequestAvailable(first, regcode));
					//izprashtame na klienta otgovora koito ni e vurnala isRequestAvailable 
					if (i == 1)// analogichno ako e vtoriqt prashtam second
						output.println(isRequestAvailable(second, regcode));
				}
			}

		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	private static String isRequestAvailable(LinkedList<String> list, String regcode) {

		if(list.contains(regcode)){// proverqva dali podadeniqt mu list sudurja veche tozi registracionen kod
			return "REFUSED";// ako se sudurja vrushta REFUSED
		}else{// ako koda ne e v lista 
			list.addLast(regcode);// dobavq elementa v spisuka
			return "OK";// vrushta OK
		}
		
	}

}
