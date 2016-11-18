
public abstract class Product {

	String inventoryNumber;
	double price;
	int quantity;
	Provider pr;
	
	
	public Product(String inventoryNum,double price,int quantity,Provider pr){
		setInventoryNumber(inventoryNum);
		setPr(pr);
		setPrice(price);
		setQuantity(quantity);
		
	}
	
	public abstract double getPromotionalPrice();
	public abstract boolean sellProduct(int price);
	
	
	
	public String getInventoryNumber() {
		return inventoryNumber;
	}
	public void setInventoryNumber(String inventoryNumber) {
		this.inventoryNumber = inventoryNumber;
	}
	public double getPrice() {
		return price;
	}
	public void setPrice(double price) {
		this.price = price;
	}
	public int getQuantity() {
		return quantity;
	}
	public void setQuantity(int quantity) {
		this.quantity = quantity;
	}
	public Provider getPr() {
		return pr;
	}
	public void setPr(Provider pr) {
		this.pr = pr;
	}
	
	
}
