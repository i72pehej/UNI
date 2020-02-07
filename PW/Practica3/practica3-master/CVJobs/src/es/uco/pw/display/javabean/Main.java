package es.uco.pw.display.javabean;

import java.util.ArrayList;

import es.uco.pw.data.dao.PersonaDao;


public class Main {

	public static void main(String[] args) {
		PersonaDao p = new PersonaDao();

		
		System.out.println("Insertado");
		ArrayList<UsuarioBean> listado = p.listarPersonas("1", "Profesional I+D", "2");
		/*String ID= listado.get("ID");
		String puntuacion= listado.get("puntuacion");
		String comentario = listado.get("comentarios");*/
		for(int i=0;i<listado.size();i++){
           /* String [] datos = new String[3];
            datos[0] = listado.get(i).getPuntuacion();
            datos[1] = listado.get(i).getComentario();*/
            System.out.println( listado.get(i).getNombre());
            System.out.println( listado.get(i).getProfesion()); 
            System.out.println( listado.get(i).getRama());
            System.out.println( listado.get(i).getExperienciaLaboral()); 
        }
		
 
		

	}

}
