import java.util.regex.Matcher;
import java.util.regex.Pattern;

public interface ValidatePhone {

	
	public static boolean validatePhoneNumber(String phoneNumber) throws WrongPhoneNumberException {
		Pattern pattern;
		Matcher matcher;

		final String PhoneNumberPattern = "[0-9]";

		pattern = Pattern.compile(PhoneNumberPattern);
		matcher = pattern.matcher(phoneNumber);

		if(matcher.matches()==false){
			throw new WrongPhoneNumberException();
		}
		
		return matcher.matches();
		

	}
	}

