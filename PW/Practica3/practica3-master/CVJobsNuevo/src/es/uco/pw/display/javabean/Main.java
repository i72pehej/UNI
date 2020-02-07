package es.uco.pw.display.javabean;

import java.util.ArrayList;
import java.util.Enumeration;
import java.util.Hashtable;

import es.uco.pw.data.dao.CVDao;
import es.uco.pw.data.dao.PerfilDao;

public class Main {

	public static void main(String[] args) {
		ComentarioBean comen= new ComentarioBean();
		PerfilDao cv = new PerfilDao();
		
		comen.setCorreoUsuario("i72arvei@uco.es");
		comen.setPuntuacion("7");
		comen.setComentario("Esto es una prueba");
		cv.insertarComentario(comen);
		
		System.out.println("Insertado");
		ArrayList<ComentarioBean> listado = cv.listarComentariosUsuario("i72arvei@uco.es");
		/*String ID= listado.get("ID");
		String puntuacion= listado.get("puntuacion");
		String comentario = listado.get("comentarios");*/
		for(int i=0;i<listado.size();i++){
            String [] datos = new String[3];
            datos[0] = listado.get(i).getPuntuacion();
            datos[1] = listado.get(i).getComentario();
            System.out.println( listado.get(i).getPuntuacion());
            System.out.println( listado.get(i).getComentario()); 
        }
		
		comen.setCorreoUsuario("i72arvei@uco.es");
		comen.setPuntuacion("3");
		comen.setComentario("Esto es una prueba para modificar");
		//cv.modificarComentario(comen);
		
		System.out.println("Modificado");
		
		ArrayList<ComentarioBean> listado2 = cv.listarComentariosUsuario("i72arvei@uco.es");
		/*String ID= listado.get("ID");
		String puntuacion= listado.get("puntuacion");
		String comentario = listado.get("comentarios");*/
		for(int i=0;i<listado2.size();i++){
            String [] datos = new String[3];
            datos[0] = listado2.get(i).getPuntuacion();
            datos[1] = listado2.get(i).getComentario();
            System.out.println( listado2.get(i).getPuntuacion());
            System.out.println( listado2.get(i).getComentario());
            
        }   
		

	}

}
