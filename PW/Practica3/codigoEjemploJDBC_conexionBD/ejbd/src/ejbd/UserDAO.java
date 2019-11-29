// En la práctica, la clase debería ir en <es.uco.pw.data.dao>
package ejbd;

import java.sql.*;
import java.util.Hashtable;

// Sería recomendable tener una clase DAO que guardara los métodos comunes (p.ej. getConnection()) y
// de la que heredase esta clase y el resto de DAOs
public class UserDAO {
  // Método que establece la conexión con la base de datos
  // NOTA: Los métodos estáticos no son obligatorios (ni siquiera los más apropiados):
  // Se ha escrito de esta manera únicamente para facilitar la ejecución
  public static Connection getConnection(){
	// En primer lugar, obtenemos una instancia del driver de MySQL
	Connection con=null;
	try {
	  Class.forName("com.mysql.jdbc.Driver");
	  // Introducir correctamente el nombre y datos de conexión - Idealmente, estos datos se
	  // indican en un fichero de propiedades
	  con= DriverManager.getConnection("jdbc:mysql://oraclepr.uco.es:3306/basedatos","usuario","password");
	// Importante capturar
	} catch(Exception e) {
	  System.out.println(e);
	}
	return con;
  }

  // Método para insertar una fila
  // En ningún caso es recomendable el paso por parámetro de los valores individuales
  // Se recomienda utilizar el UserBean o una clase envoltorio User que tenga estas propiedades
  public static int save(int id, String last, String first, int age){
	int status=0;
	try{
		Connection con=getConnection();
		// PreparedStament será más rápido (si es uso recurrente) y permite invocación a parámetros
		// Lo habitual es que las consultas y sentencias SQL estén en un fichero de propiedades aparte, no en código
		PreparedStatement ps=con.prepareStatement("insert into User (id,last,first,age) values(?,?,?,?)");
		// El orden de los parámetros debe coincidir con las '?' del código SQL
		ps.setInt(1,id);
		ps.setString(2,last);
		ps.setString(3,first);
		ps.setInt(4,age);
		status = ps.executeUpdate();
	// Importante capturar las excepciones. Si nuestra aplicaciones tiene más opciones de fallo,
	// podemos capturar directamente SQLException
	}catch(Exception e){System.out.println(e);}
	// El invocante siempre debería tener información del resultado de la sentencia SQL
	return status;
}

// Método para actualizar un usuario
public static int update(int id, String last, String first, int age){
	int status=0;
	try{
		Connection con=getConnection();
		PreparedStatement ps=con.prepareStatement("update User set last=?,first=?,age=? where id=?");
		ps.setString(1,last);
		ps.setString(2,first);
		ps.setInt(3,age);
		// En este caso, 'id' va después, conforme al orden de la sentencia SQL
		ps.setInt(4,id);
		status=ps.executeUpdate();
	}catch(Exception e){System.out.println(e);}
	return status;
}

// Para la consulta, se ha tomado una estructura Hash (columna-tabla, valor)
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
	    // Se debe tener precaución con cerrar las conexiones, uso de auto-commit, etc.
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
