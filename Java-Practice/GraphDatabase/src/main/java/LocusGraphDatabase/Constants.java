package LocusGraphDatabase;

public class Constants {
	private final String DriverProd = "org.postgresql.Driver";
	private final String DatabaseProd = "jdbc:postgresql://localhost:5432/locus";
	private final String UsernameProd = "handyhome";
	private final String PasswordProd = "cloudhome";
	private final String DriverTest = "org.sqlite.JDBC";
	private final String DatabaseTest = "jdbc:sqlite:locus12.db";
	private final String UsernameTest = "";
	private final String PasswordTest = "";
	public String getDriverProd() {
		return DriverProd;
	}
	public String getDatabaseProd() {
		return DatabaseProd;
	}
	public String getUsernameProd() {
		return UsernameProd;
	}
	public String getPasswordProd() {
		return PasswordProd;
	}
	public String getDriverTest() {
		return DriverTest;
	}
	public String getDatabaseTest() {
		return DatabaseTest;
	}
	public String getUsernameTest() {
		return UsernameTest;
	}
	public String getPasswordTest() {
		return PasswordTest;
	}
	
}
