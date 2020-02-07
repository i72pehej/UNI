/**
 * Fichero funcionesPiePagina.js que contendrá todas las funciones usadas en piePagina.html
 * @author Isabel María Ariza Velasco
 * @author Alberto Perez Peña
*/


/**Función que recibirá un paramatro desde otra funcion externa. Según dicho parámetro, se ejecutará un trozo de código u otro 
   @function
   @param {cadena}
*/
function getPiePagina(param){
    if(param=="Nosotros"){
		document.getElementById('nosotros').style.display = 'block';
	}else if(param=="seguridad"){
		document.getElementById('seguridad').style.display = 'block';
	}else if(param=="ayuda"){
        document.getElementById('ayuda').style.display = 'block';
    }
}

/**
 * Función que mostrara la parte de Proteccion de Datos 
 * @function
*/
function mostrarProteccion(){
    document.getElementById("card").style.display='block';
    document.getElementById("condicionesLegales").style.display='none';
    document.getElementById("proteccionDatos").style.display='block';
}

/**
 * Función que mostrara la parte de Condiciones Legales
 * @function
*/
function mostrarCondiciones(){
    document.getElementById("card").style.display='block';
    document.getElementById("proteccionDatos").style.display='none';
    document.getElementById("condicionesLegales").style.display='block';
}
