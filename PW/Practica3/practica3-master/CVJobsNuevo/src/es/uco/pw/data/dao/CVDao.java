package es.uco.pw.data.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import es.uco.pw.display.javabean.ComentarioBean;

public class CVDao extends ConexionDao {
	

//Usar para las tablas del CV, los comentarios no se editan
/*public boolean modificarComentario(ComentarioBean comen) {
	boolean bandera=false;
	try {
        Connection con = getConnection();
        String sentencia = " UPDATE comentarios SET puntuacion='" + comen.getPuntuacion() + "', "
                + "comentario='" + comen.getComentario()+"' where "
                + "ID ='" + comen.getId() + "';";
        System.out.println(sentencia);
        Statement st = con.createStatement();
        st.executeUpdate(sentencia);
        bandera=true;
        st.close();
        con.close();
    } catch (SQLException ex) {
        throw new RuntimeException(ex.getMessage());
    }
	return bandera;
}*/

} 
