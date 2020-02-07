package es.uco.pw.display.javabean;

public class ProduccionCientificaBean {
	int ID;
	String publicacion;
	String portfolio;
	String correoUsuario;
	
	public ProduccionCientificaBean(){
		
	}
	
	public int getID() {
		return ID;
	}
	public void setID(int iD) {
		ID = iD;
	}
	public String getPublicacion() {
		return publicacion;
	}
	public void setPublicacion(String publicacion) {
		this.publicacion = publicacion;
	}
	public String getPortfolio() {
		return portfolio;
	}
	public void setPortfolio(String portfolio) {
		this.portfolio = portfolio;
	}
	public String getCorreoUsuario() {
		return correoUsuario;
	}
	public void setCorreoUsuario(String correoUsuario) {
		this.correoUsuario = correoUsuario;
	}
	
	
}
