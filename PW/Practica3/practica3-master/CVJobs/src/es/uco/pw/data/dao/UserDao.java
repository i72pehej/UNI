package es.uco.pw.data.dao;

import java.sql.*;
import java.util.Hashtable;

public class UserDao extends ConexionDao {
public static int save(int id, String last, String first, int age){
	int status=0;
	try{
		// PreparedStament ser� m�s r�pido (si es uso recurrente) y permite invocaci�n a par�metros
		// Lo habitual es que las consultas y sentencias SQL est�n en un fichero de propiedades aparte, no en c�digo
		PreparedStatement ps= getConnection().prepareStatement("insert into User (id,last,first,age) values(?,?,?,?)");
		// El orden de los par�metros debe coincidir con las '?' del c�digo SQL
		ps.setInt(1,id);
		ps.setString(2,last);
		ps.setString(3,first);
		ps.setInt(4,age);
		status = ps.executeUpdate();
	// Importante capturar las excepciones. Si nuestra aplicaciones tiene m�s opciones de fallo,
	// podemos capturar directamente SQLException
	}catch(Exception e){System.out.println(e);}
	// El invocante siempre deber�a tener informaci�n del resultado de la sentencia SQL
	return status;
}

//M�todo para actualizar un usuario
public static int update(int id, String last, String first, int age){
	int status=0;
	try{
		Connection con=getConnection();
		PreparedStatement ps=con.prepareStatement("update User set last=?,first=?,age=? where id=?");
		ps.setString(1,last);
		ps.setString(2,first);
		ps.setInt(3,age);
		// En este caso, 'id' va despu�s, conforme al orden de la sentencia SQL
		ps.setInt(4,id);
		status=ps.executeUpdate();
	}catch(Exception e){System.out.println(e);}
	return status;
}

//Para la consulta, se ha tomado una estructura Hash (columna-tabla, valor)
public static Hashtable<String,String> queryById (int id) {
	Statement stmt = null; 
	Hashtable<String,String> resul = null;
	try {
		Connection con=getConnection();
		// En consultas, se hace uso de un Statement 
		stmt = con.createStatement();
	    ResultSet rs = stmt.executeQuery("select last, first, age from User where id = " + id);
	    while (rs.next()) {
	    	String last = rs.getString("last");
	        String first = rs.getString("first");
	        int age = rs.getInt("age");
	        resul = new Hashtable<String,String>();
	        resul.put("id", Integer.toString(id));
	        resul.put("last", last);
	        resul.put("first", first);
	        resul.put("age", Integer.toString(age));        
	        System.out.println(id + "\t" + last +
	                               "\t" + first + "\t" + age);
	    }
	    // Se debe tener precauci�n con cerrar las conexiones, uso de auto-commit, etc.
	    if (stmt != null) 
	    	stmt.close(); 
	} catch (Exception e) {
		System.out.println(e);
	} 
	return resul;
} 

public static int delete(int id){
	int status=0;
	try{
		Connection con=getConnection();
		PreparedStatement ps=con.prepareStatement("delete from User where id=?");
		ps.setInt(1,id);
		status=ps.executeUpdate();
	}catch(Exception e){System.out.println(e);}

	return status;
}
}