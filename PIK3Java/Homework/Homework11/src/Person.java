import java.io.Serializable;

@SuppressWarnings("serial")
public class Person implements Serializable {

	String name, egn;

	public Person(String name, String egn) {
		this.name = name;
		this.egn = egn;

	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getEgn() {
		return egn;
	}

	public void setEgn(String egn) {
		this.egn = egn;
	}

}
