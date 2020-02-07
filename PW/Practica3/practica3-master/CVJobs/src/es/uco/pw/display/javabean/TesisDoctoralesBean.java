package es.uco.pw.display.javabean;

public class TesisDoctoralesBean {
	int ID;
	String titulo;
	String descripcion;
	String doctorado;
	String desde;
	String hasta;
	String meritos;
	String correoUsuario;
	
	public TesisDoctoralesBean(){
		
	}
	
	public int getID() {
		return ID;
	}
	public void setID(int iD) {
		ID = iD;
	}
	public String getTitulo() {
		return titulo;
	}
	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}
	public String getDescripcion() {
		return descripcion;
	}
	public void setDescripcion(String descripcion) {
		this.descripcion = descripcion;
	}
	public String getDoctorado() {
		return doctorado;
	}
	public void setDoctorado(String doctorado) {
		this.doctorado = doctorado;
	}
	public String getDesde() {
		return desde;
	}
	public void setDesde(String desde) {
		this.desde = desde;
	}
	public String getHasta() {
		return hasta;
	}
	public void setHasta(String hasta) {
		this.hasta = hasta;
	}
	public String getMeritos() {
		return meritos;
	}
	public void setMeritos(String meritos) {
		this.meritos = meritos;
	}
	public String getCorreoUsuario() {
		return correoUsuario;
	}
	public void setCorreoUsuario(String correoUsuario) {
		this.correoUsuario = correoUsuario;
	}
	
	
}
