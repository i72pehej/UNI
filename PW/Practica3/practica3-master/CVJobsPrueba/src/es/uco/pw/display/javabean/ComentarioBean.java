package es.uco.pw.display.javabean;

public class ComentarioBean {
	private int id;
	private String puntuacion;
	private String comentario;
	private String correoUsuario;
	
	public ComentarioBean() {
		puntuacion=null;
		comentario=null;
	}
	
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getPuntuacion() {
		return puntuacion;
	}
	public void setPuntuacion(String puntuacion) {
		this.puntuacion = puntuacion;
	}
	public String getComentario() {
		return comentario;
	}
	public void setComentario(String comentario) {
		this.comentario = comentario;
	}
	public String getCorreoUsuario() {
		return correoUsuario;
	}
	public void setCorreoUsuario(String correoUsuario) {
		this.correoUsuario = correoUsuario;
	}
	
	
}
