package LocusGraphDatabase;

import java.util.ArrayList;
import java.util.List;

import org.apache.log4j.PropertyConfigurator;

public class GraphDatabase {
	private final DBSingleton singleton;	
	public GraphDatabase(DBSingleton dbSingleton) throws Exception{
		this.singleton = dbSingleton;
	}
	
	public void addRelationship(String relationshipFrom, String relationshipTo, String relationshipType, List<Attribute> attributeList) throws Exception{
		String sql = "INSERT INTO edges(relationship_from, relationship_to, relationship_type) VALUES ('"+relationshipFrom+"', '"+relationshipTo+"', '"+relationshipType+"')";
		int edge_id = singleton.insertData(sql);
		for(Attribute attribute : attributeList){
			sql = "INSERT INTO attributes(attribute_name, attribute_value, edge_id) VALUES ('"+ attribute.getAttributeType() +"', '"+ attribute.getAttributeValue() +"', "+edge_id+")";
			singleton.insertData(sql);
		}
	}
	
	public List<String> fdLinkage(String name, String relationshipType, List<Attribute> attributeList) throws Exception{
		String attributeCondition = "";
		for(Attribute attribute : attributeList){
			attributeCondition += " and (A.attribute_name = '" + attribute.getAttributeType() + "' and A.attribute_value = '" + attribute.getAttributeValue() + "')";
		}
		String sql = "Select * from edges as E inner join attributes as A on E.edge_id = A.edge_id where E.relationship_from = '"
				+ name + "' and E.relationship_type = '" + relationshipType + "'";
		sql += attributeCondition;
		List<String> friendsList = singleton.getData(sql);
		return friendsList;
	}
	
	public static void main(String[] args) throws Exception
	{	
//		String log4jConfPath = "/Users/sarvesh/log4j.properties";
//		PropertyConfigurator.configure(log4jConfPath);
		Constants constants = new Constants();
		GraphDatabase graphDb = new GraphDatabase(new DBSingleton(constants.getDriverTest(), constants.getDatabaseTest(), 
				constants.getUsernameTest(), constants.getPasswordTest()));
//		GraphDatabase graphDb = new GraphDatabase(new DBSingleton(constants.getDriverProd(), constants.getDatabaseProd(), 
//				constants.getUsernameProd(), constants.getPasswordProd()));
		List<Attribute> attributeList = new ArrayList<Attribute>();
		attributeList.add(new Attribute("CoWorkers Since", "2012"));
//		graphDb.addRelationship("Sarvesh", "Ram", "CoWorkers", attributeList);
		List<String> friendsList = graphDb.fdLinkage("Sarvesh", "CoWorkers", attributeList);
		String friendsName = "";
		for(String friendName : friendsList){
			friendsName += friendName + "\t";
		}
		System.out.println(friendsName);
	}

}
 