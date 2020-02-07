package es.uco.pw.display.javabean;

import java.awt.Image;
import java.io.Serializable;

public class UsuarioBean implements Serializable {

	private String nombre;
	private String apellidos;
	private int tipoUsuario;
	private String nombreEmpresa;
	private String correo;
	private String pass;
	private String edad;
	private String experienciaLaboral;
	private String profesion;
	private String rama;
	private String situacionLaboral;
	private String descripcion;
	private Image imagen;
	private String tipoCV;
	private String fechaNacimiento;
	private String nacionalidad;
	private String telefono;
	private String domicilio;
	private String intereses;
	
	public UsuarioBean() {
		nombre=null;
		apellidos=null;
		tipoUsuario=1;
		nombreEmpresa=null;
		correo=null;
		pass=null;
		edad=null;
		experienciaLaboral=null;
		profesion=null;
		rama=null;
		situacionLaboral=null;
		descripcion=null;
		imagen=null;
		tipoCV=null;
		fechaNacimiento=null;
		nacionalidad=null;
		telefono=null;
		domicilio=null;
		intereses=null;
		
	}


	public String getEdad() {
		return edad;
	}


	public void setEdad(String edad) {
		this.edad = edad;
	}


	public String getExperienciaLaboral() {
		return experienciaLaboral;
	}


	public void setExperienciaLaboral(String experienciaLaboral) {
		this.experienciaLaboral = experienciaLaboral;
	}


	public String getProfesion() {
		return profesion;
	}


	public void setProfesion(String profesion) {
		this.profesion = profesion;
	}


	public String getRama() {
		return rama;
	}


	public void setRama(String rama) {
		this.rama = rama;
	}


	public String getSituacionLaboral() {
		return situacionLaboral;
	}


	public void setSituacionLaboral(String situacionLaboral) {
		this.situacionLaboral = situacionLaboral;
	}


	public String getDescripcion() {
		return descripcion;
	}


	public void setDescripcion(String descripcion) {
		this.descripcion = descripcion;
	}


	public Image getImagen() {
		return imagen;
	}


	public void setImagen(Image imagen) {
		this.imagen = imagen;
	}


	public String getTipoCV() {
		return tipoCV;
	}


	public void setTipoCV(String tipoCV) {
		this.tipoCV = tipoCV;
	}


	public String getFechaNacimiento() {
		return fechaNacimiento;
	}


	public void setFechaNacimiento(String fechaNacimiento) {
		this.fechaNacimiento = fechaNacimiento;
	}


	public String getNacionalidad() {
		return nacionalidad;
	}


	public void setNacionalidad(String nacionalidad) {
		this.nacionalidad = nacionalidad;
	}


	public String getTelefono() {
		return telefono;
	}


	public void setTelefono(String telefono) {
		this.telefono = telefono;
	}


	public String getDomicilio() {
		return domicilio;
	}


	public void setDomicilio(String domicilio) {
		this.domicilio = domicilio;
	}


	public String getIntereses() {
		return intereses;
	}


	public void setIntereses(String intereses) {
		this.intereses = intereses;
	}


	public String getNombre() {
		return nombre;
	}
	public void setNombre(String nombre) {
		this.nombre = nombre;
	}
	public String getApellidos() {
		return apellidos;
	}
	public void setApellidos(String apellidos) {
		this.apellidos = apellidos;
	}
	public int getTipoUsuario() {
		return tipoUsuario;
	}
	public void setTipoUsuario(int tipoUsuario) {
		this.tipoUsuario = tipoUsuario;
	}
	public String getNombreEmpresa() {
		return nombreEmpresa;
	}
	public void setNombreEmpresa(String nombreEmpresa) {
		this.nombreEmpresa = nombreEmpresa;
	}
	public String getCorreo() {
		return correo;
	}
	public void setCorreo(String correo) {
		System.out.println(correo);
		this.correo = correo;
	}
	public String getPass() {
		return pass;
	}
	public void setPass(String pass) {
		this.pass = pass;
	}
	
}
