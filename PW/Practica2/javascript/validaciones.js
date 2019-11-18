//Fichero validaciones.js donde se realizaran todas las validaciones de campos de texto necesarias

/**
 * Función que indica al usuario que todos los campos de texto son obligatorios
 * @function
*/

function camposRequeridos(){
	var nombre= document.getElementById("nombre").required;
	var apellidos= document.getElementById("apellidos").required;
	var correo = document.getElementById("correoID").required;
	var pass = document.getElementById("passID").required;
	var pass = document.getElementById("passIDRep").required;
	var fechaDia= document.getElementById("fecha_dia").required;
	var fechaAnio= document.getElementById("fecha_anio").required;
	var nacionalidad= document.getElementById("nacionalidad").required;
	var domicilio= document.getElementById("domicilio").required;
	var telefono= document.getElementById("telefono").required;
	var correo= document.getElementById("correo").required;
	var nombreCV= document.getElementById("nombreText").required;
	
}

/**
 * Función valida que el correo tenga el formato correcto
 * @function
*/
function validarCorreo(){
	var x = document.inicio.Correo.value;
	var atposition=x.indexOf("@");  
	var dotposition=x.lastIndexOf(".");  
	if (atposition<1 || dotposition<atposition+2 || dotposition+2>=x.length){   
		alert("El correo introducido no tiene un formato válido");
		return false;  
	}
	return true;
}

/**
 * Función valida que la contraseña tenga el formato correcto
 * @function
*/
function validarContrasena(){
	var x = document.inicio.Contrasena.value;
	if(x.length<1){
		alert("La contraseña debe tener mas de 6 digitos");
		return false;
	}
	return true;
}

function activainput() {
	document.getElementById("js_si").disabled = false; //HABILITA el input (id="js_si")
}
function desactivainput() {
	document.getElementById("js_si").disabled = true; //DESHABILITA el input
}

function comprobarClave(){
    clave1 = document.inicio.passID.value
    clave2 = document.inicio.passIDRep.value

    if (clave1 == clave2){
	   return true;
	}
    else{
		alert("Las contraseñas no coinciden");
		return false;
	}
}














