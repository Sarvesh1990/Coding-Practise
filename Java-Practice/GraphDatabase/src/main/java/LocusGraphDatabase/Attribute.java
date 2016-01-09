package main.java.LocusGraphDatabase;

public class Attribute {
	private String AttributeType;
	private String AttributeValue;
	
	public Attribute(String attributeType, String attributeValue) {
		super();
		AttributeType = attributeType;
		AttributeValue = attributeValue;
	}
	
	public String getAttributeType() {
		return AttributeType;
	}
	public void setAttributeType(String attributeType) {
		AttributeType = attributeType;
	}
	public String getAttributeValue() {
		return AttributeValue;
	}
	public void setAttributeValue(String attributeValue) {
		AttributeValue = attributeValue;
	}
	
}
