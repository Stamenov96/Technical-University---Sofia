
public class Electronics extends Product{

	
	public Electronics(String inventoryNum, double price, int quantity, Provider pr) {
		super(inventoryNum, price, quantity, pr);
	}

	String manifacturer,model;
	
	
	@Override
	public double getPromotionalPrice() {
		return this.price-this.price*0.1;
	}

	@Override
	public boolean sellProduct(int price) {
		// TODO Auto-generated method stub
		return false;
	}

	public String getManifacturer() {
		return manifacturer;
	}

	public void setManifacturer(String manifacturer) {
		this.manifacturer = manifacturer;
	}

	public String getModel() {
		return model;
	}

	public void setModel(String model) {
		this.model = model;
	}

}
