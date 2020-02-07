package es.uco.pw.data.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import es.uco.pw.display.javabean.*;

public class RegistroLoginDao extends ConexionDao {

	public String Autenticacion(UsuarioBean usuario) {
		Statement stmt = null;
		String nombre=null;
		try {
			Connection con=getConnection();
			String sentencia = "select nombre from Registro where correo= '"+ usuario.getCorreo() +"' and contrasena= '"+usuario.getPass()+"'";
			stmt = con.createStatement();
			ResultSet rs = stmt.executeQuery(sentencia);
			while (rs.next()) {
				nombre = rs.getString("nombre");
				usuario.setNombre(nombre);	
			}
			if(rs.absolute(1)) {
				return nombre;
			}
			rs.close();
			stmt.close();
			con.close();
		} catch (SQLException ex) {
			throw new RuntimeException(ex.getMessage());
		}
		return null;
	}
	
	public boolean comprobarExistencia(String correo) {
		
		Statement stmt = null;
		try {
			Connection con=getConnection();
			String sentencia = "select * from Registro where correo='"+correo+"'";
			stmt = con.createStatement();
			ResultSet rs = stmt.executeQuery(sentencia);
			if(rs.absolute(1)) {
				return true;
			}
			rs.close();
			stmt.close();
			con.close();
		} catch (SQLException ex) {
			throw new RuntimeException(ex.getMessage());
		}
		return false;
	}
	
	public boolean Registro(UsuarioBean usuario) {
		PreparedStatement pst = null;
		try {
			String consulta = "insert into Registro (correo, nombre, apellidos, tipoUsuario, nombreEmpresa, contrasena) values (?,?,?,?,?,?)";
			pst = getConnection().prepareStatement(consulta);
			pst.setString(1, usuario.getCorreo());
			pst.setString(2, usuario.getNombre());
			pst.setString(3, usuario.getApellidos());
			pst.setInt(4, usuario.getTipoUsuario());
			pst.setString(5, usuario.getNombreEmpresa());
			pst.setString(6, usuario.getPass());
			
			if (pst.executeUpdate() == 1) {
				return true;
			}
		} catch (Exception e) {
			// TODO: handle exception
		}finally {
			try {
				if(getConnection()!=null) {	
					getConnection().close();
				}
				if(pst != null) {
					pst.close();
				}
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
		
		return false;
	}
	
	public boolean restaurarContrasena(UsuarioBean usuario){
		
		try {
			Connection con = getConnection();
			PreparedStatement pst = con.prepareStatement("update Registro set contrasena=? where correo=? ");
			pst.setString(1, usuario.getPass());
			pst.setString(2, usuario.getCorreo());

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
}
