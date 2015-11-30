import java.util.HashMap;

public class main 
{
	public static void main(String[] args) 
	{
		SymbolTable st = new SymbolTable();
		st.insert("Coding", "Sarvesh");
		st.insert("Consult", "Aditya");
		st.insert("Trading", "Shakey");
		st.insert("Analytics", "Vijay");
		st.insert("Consult", "Jay");
		st.insert("Analytics", "Surbhi");
		st.insert("Analytics", "Vivek");
		st.insert("Startup", "Nandan");
		st.insert("Google", "Namit");
		st.insert("Google", "Sarvesh");
		st.search("Google");
	}
}
