package es.uco.pw.data.dao;

import java.sql.Connection;
import java.sql.DriverManager;

public class ConexionDao  {

	public static Connection getConnection(){
		Connection con=null;
		try {
		  Class.forName("com.mysql.jdbc.Driver");
		  con= DriverManager.getConnection("jdbc:mysql://oraclepr.uco.es:3306/i72carif","i72carif","123456");
		} catch(Exception e) {
		  System.out.println(e);
		}
		return con;
	}
	
}
