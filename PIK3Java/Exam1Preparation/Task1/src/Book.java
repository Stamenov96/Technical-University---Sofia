
public class Book extends Product{

	
	public Book(String inventoryNum, double price, int quantity, Provider pr) {
		super(inventoryNum, price, quantity, pr);
	}

	String autor,title;
	
	
	
	@Override
	public double getPromotionalPrice() {
		return this.price*0.5;
	}

	@Override
	public boolean sellProduct(int price) {
		// TODO Auto-generated method stub
		return false;
	}

	public String getAutor() {
		return autor;
	}

	public void setAutor(String autor) {
		this.autor = autor;
	}

	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

}
