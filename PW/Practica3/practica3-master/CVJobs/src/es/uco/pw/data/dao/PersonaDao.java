package es.uco.pw.data.dao;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;

import es.uco.pw.display.javabean.UsuarioBean;

public class PersonaDao extends ConexionDao {
	
	public ArrayList<UsuarioBean> listarPersonas(String tipoCV1, String tipoCV2, String profesion) {
		Statement stmt = null; 
		ArrayList<UsuarioBean> result = new ArrayList<>();
		String sentencia=null;
		try {
			Connection con=getConnection();
			stmt = con.createStatement();
			if(tipoCV2==null){
				sentencia = "select id, correo, nombre, rama, experiencia_laboral, situacion_laboral from Registro where tipo_cv = '"+tipoCV1+"'and profesion='"+ profesion+"'";
			}else{
				sentencia = "select id, correo, nombre, rama, experiencia_laboral, situacion_laboral from Registro where tipo_cv = '"+tipoCV1+"'and profesion='"+ profesion+"' or tipo_cv ='"+tipoCV2+"'"; 
			}
		    ResultSet rs = stmt.executeQuery(sentencia);
		    while (rs.next()) {
		    	int id = rs.getInt("id");
		    	String correo = rs.getString("correo");
		    	String nombre = rs.getString("nombre");
		    	String rama = rs.getString("rama");
		    	String experienciaLaboral= rs.getString("experiencia_laboral");
		    	String situacionLaboral = rs.getString("situacion_laboral");
		        UsuarioBean user = new UsuarioBean();
		        user.setCorreo(correo);
		        user.setNombre(nombre);
		        user.setRama(rama);
		        user.setExperienciaLaboral(experienciaLaboral);
		        user.setSituacionLaboral(situacionLaboral);
		        result.add(user);
		    }
		    if (stmt != null) 
		    	stmt.close(); 
		} catch (Exception e) {
			System.out.println(e);
		} 
		return result;
	}

}
