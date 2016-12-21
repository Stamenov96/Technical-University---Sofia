
public class Main {

	public static void main(String[] args) throws InterruptedException {
	
		ArrayClass arr = new ArrayClass();
		
		Thread t1 = new Thread(new Runnable() {
			 
            @Override
            public void run() {
               arr.edit();
            }
        });
		
		Thread t2 = new Thread(new Runnable() {
			 
            @Override
            public void run() {
               arr.sort();
            }
        });
		
		t1.start();
		t2.start();
		t1.join();
		t2.join();
		
		
	}

}
