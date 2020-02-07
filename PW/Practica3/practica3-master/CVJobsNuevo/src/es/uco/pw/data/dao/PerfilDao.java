package es.uco.pw.data.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.Hashtable;

import es.uco.pw.display.javabean.ComentarioBean;
import es.uco.pw.display.javabean.UsuarioBean;

public class PerfilDao extends ConexionDao {
	
	public Hashtable<String,String> listarPersona (String correo) {
		Statement stmt = null; 
		Hashtable<String,String> resul = null;
		try {
			Connection con=getConnection();
			stmt = con.createStatement();
		    ResultSet rs = stmt.executeQuery("select nombre, apellidos, edad, experiencia_laboral, profesion, rama, situacion_laboral, descripcion, imagen from Registro where correo = '" + correo+"'");
		    while (rs.next()) {
		    	String nombre = rs.getString("nombre");
		    	String apellidos = rs.getString("apellidos");
		    	String edad = rs.getString("edad");
		    	String experienciaLaboral = rs.getString("experiencia_laboral");
		    	String profesion = rs.getString("profesion");
		    	String rama = rs.getString("rama");
		    	String situacionLaboral = rs.getString("situacion_laboral");
		    	String descripcion = rs.getString("descripcion");
		    	//String imagen = rs.getString("imagen");
		        resul = new Hashtable<String,String>();
		        if(correo!=null) {
		        	resul.put("correo", correo);
		        }
		        if(nombre!=null) {
		        	resul.put("nombre", nombre);
		        }
		        if(apellidos!=null) {
		        	resul.put("apellidos", apellidos);
		        }
		        if(edad!=null) {
		        	resul.put("edad", edad); 
		        }
				if(experienciaLaboral!=null) {
					resul.put("experiencia_laboral", experienciaLaboral);        	
				}
				if(profesion!=null) {
					resul.put("profesion", profesion);
				}
				if(rama!=null) {
					resul.put("rama", rama);
				}
				if(situacionLaboral!=null) {
					resul.put("situacion_laboral", situacionLaboral);	        	
				}
				if(descripcion!=null) {
					resul.put("descripcion", descripcion);
				}
		    }
		    if (stmt != null) 
		    	stmt.close(); 
		} catch (Exception e) {
			System.out.println(e);
		} 
		return resul;
	} 
	
	public boolean modificarPerfil(UsuarioBean usuario) {
		
		try {
			Connection con = getConnection();
			PreparedStatement pst = con.prepareStatement("update Registro set nombre=?, apellidos=?, edad=?, experiencia_laboral=?, profesion=?, rama=?, situacion_laboral=?, descripcion=? where correo=? ");
			pst.setString(1, usuario.getNombre());
			pst.setString(2, usuario.getApellidos());
			pst.setString(3, usuario.getEdad());
			pst.setString(4, usuario.getExperienciaLaboral());
			pst.setString(5, usuario.getProfesion());
			pst.setString(6, usuario.getRama());
			pst.setString(7, usuario.getSituacionLaboral());
			pst.setString(8, usuario.getDescripcion());
			pst.setString(9, usuario.getCorreo());
			if (pst.executeUpdate() == 1) {
				return true;
			}
			pst.close();
			con.close();
		} catch (Exception e) {
			System.out.println(e);
		}
		
		return false;
	}
	
	public boolean insertarComentario(ComentarioBean comen) {
		boolean bandera=false;
		try {
			Connection con = getConnection();
			String sentencia
            = "insert into comentarios (puntuacion, comentario, IDregistro) values("
            + "'" + comen.getPuntuacion() + "','" + comen.getComentario() + "',"
            + "(select ID from Registro where correo= '"+ comen.getCorreoUsuario() +"'));";
			System.out.println(sentencia);
			Statement st = con.createStatement();
			st.executeUpdate(sentencia);
			bandera=true;
			st.close();
			con.close();
		} catch (SQLException ex) {
			 System.out.println(ex);
			throw new RuntimeException(ex.getMessage());
		}
		return bandera;
	}

	public ArrayList<ComentarioBean> listarComentariosUsuario (String correo) {
		Statement stmt = null; 
		ArrayList<ComentarioBean> result = new ArrayList<>();
		try {
			Connection con=getConnection();
			stmt = con.createStatement();
		    ResultSet rs = stmt.executeQuery("select * from comentarios where IDregistro = (select ID from Registro where correo= '" +correo+ "')");
		    while (rs.next()) {
		    	int ID = rs.getInt("ID");
		    	String puntuacion = rs.getString("puntuacion");
		    	String comentario = rs.getString("comentario");
		        ComentarioBean comen = new ComentarioBean();
		        comen.setId(ID);
		        comen.setPuntuacion(puntuacion);
		        comen.setComentario(comentario);
		        result.add(comen);
		    }
		    if (stmt != null) 
		    	stmt.close(); 
		} catch (Exception e) {
			System.out.println(e);
		} 
		return result;
	}

}
