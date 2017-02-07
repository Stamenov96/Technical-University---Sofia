import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.LinkedList;


public class Server {

	public static String[] bulstats  = {"1454743","3432656"};
	public static LinkedList<String> First;// list na zaqvkite vuv purvata firma
	public static LinkedList<String> Second;// lis na zaqvkite vuv vtorata firma
	
	public static void main(String[] args) {

		try {
			ServerSocket ss = new ServerSocket(1211); // Slusha na 1211 port

			while (true) {
				Socket socket = ss.accept(); // priema potrebitel kogato se vurje s nego
				CustomerThread customer = new CustomerThread(socket,bulstats,First,Second); // suzdava nova nishka
				customer.start();// startira nishkata
				ss.close();// zatvarq vruzkata s klienta sled prikliuchvane na rabota
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
