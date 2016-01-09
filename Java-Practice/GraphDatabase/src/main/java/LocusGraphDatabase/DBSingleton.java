package LocusGraphDatabase;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

import org.apache.log4j.Logger;

public class DBSingleton{
	private final Connection connInstance;
	final static Logger logger = Logger.getLogger(Class.class);
	
	public DBSingleton(String driverName, String databaseName, String username, String password) throws Exception {
		this.connInstance = getConnInstance(driverName, databaseName, username, password);
	} 
	
	private static Connection getConnInstance(String driverName, String databaseName, String username, String password) throws Exception {
		try {
			Class.forName(driverName);
		} catch (ClassNotFoundException e) {
			logger.error("Where is your PostgreSQL JDBC Driver? "
					+ "Include in your library path!");
			e.printStackTrace();
			throw e;
		}
		logger.info("SQLite JDBC Driver Registered!");
		Connection connection = null;
		try {
			connection = DriverManager.getConnection(
					databaseName, username, password);
		} catch (SQLException e) {
			logger.error("Connection Failed! Check output console");
			e.printStackTrace();
			throw e;
		}
		if (connection != null) {
			logger.info("You made it, take control your database now!");
		} else {
			logger.error("Failed to make connection!");
		}
		return connection;
	}

	public int insertData(String sql) throws Exception {
		Connection conn = this.connInstance;
		Statement stmt = conn.createStatement();
		stmt.execute(sql);
		ResultSet rs = stmt.getGeneratedKeys();
		int edge_id = 0;
		while(rs.next()){
			edge_id = rs.getInt(1);
		}
		return edge_id;
	}

	public List<String> getData(String sql) throws Exception {
		Connection conn = this.connInstance;
		Statement stmt = conn.createStatement();
		ResultSet rs = stmt.executeQuery(sql);
		List<String> friendsList = new ArrayList<String>();
		while(rs.next()){
			String name = rs.getString("relationship_to");
			friendsList.add(name);
	    }
		return friendsList;
	}
}