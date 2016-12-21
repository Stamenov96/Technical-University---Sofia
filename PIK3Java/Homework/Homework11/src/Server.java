import java.io.DataOutputStream;
import java.io.ObjectInputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {

	@SuppressWarnings("resource")
	public static void main(String[] args) throws Exception {

		Person p1 = null;

		ServerSocket server = new ServerSocket(1914);
		Socket socket = server.accept();

		ObjectInputStream oip = new ObjectInputStream(socket.getInputStream());
		DataOutputStream out= new DataOutputStream(socket.getOutputStream());
		
		p1 = (Person )oip.readObject();
		
		
		int years = Integer.parseInt(p1.egn.substring(0, 2));

		if (years > 90 && years < 99) {
			out.writeInt(2016-(1900+years));
		
		} else {
			throw new Exception("Your person is out of ragne 1990-1999");
		}
		server.close();
	}

}
