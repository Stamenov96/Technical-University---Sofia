import java.util.Arrays;
import java.util.Random;

public class ArrayClass {

	public static final int min = 3;
	public static final int max = 20;

	int[] array = new int[randInt()];

	public ArrayClass() {

		for (int i = 0; i < array.length; i++) {
			array[i] = randInt();
		}
		System.out.println("INITIAL ARRAY");
		print();

	}

	public synchronized void edit() {
		for (int i = 0; i < array.length; i++) {
			array[i] *= 10;

		}
		System.out.println("EDDITED ARRAY");
		print();
	}

	public synchronized void sort() {

		Arrays.sort(this.array);
		System.out.println("Sorted Array");
		print();
	}

	
	private int randInt() {
		Random random = new Random();
		int size = random.nextInt(max - min + 1) + min;
		return size;

	}

	public void print() {
		for (int i = 0; i < array.length; i++) {
			System.out.println(array[i] + "");
		}
	}

}
