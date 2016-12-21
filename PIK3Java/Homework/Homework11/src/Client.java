import java.io.DataInputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.Scanner;

public class Client {

	public static void main(String args[]) throws IOException {
		String name, egn;

		Scanner scan = new Scanner(System.in);
		System.out.println("Enter the name: ");
		name = scan.nextLine();
		System.out.println("Enter the egn: ");
		egn = scan.nextLine();

		Person p1 = new Person(name, egn);

		Socket s = new Socket("127.0.0.1", 1914);
		Scanner scan2 = new Scanner(s.getInputStream());

		ObjectOutputStream oos = new ObjectOutputStream(s.getOutputStream());
		DataInputStream in = new DataInputStream(s.getInputStream());
		try {

			oos.writeObject(p1);

		} catch (Exception e) {
			System.out.println("FAIL");
		}

		int age = in.readInt();
		System.out.println("Your person is " + age + " years old");

		if (s != null)
			s.close();
		if (scan != null)
			scan.close();
		if (scan2 != null)
			scan2.close();
	}
}
