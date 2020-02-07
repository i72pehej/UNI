/**
 * Fichero funcionesPerfil.js que contendrá todas las funciones usadas en miPerfil.html
 * @author Isabel María Ariza Velasco
*/

/**Función que recibirá un paramatro desde otra funcion externa. Según dicho parámetro, se ejecutará un trozo de código u otro 
   @function
   @param {cadena}
*/
function getPerfil(param){
	console.log(param);
    if(param=="inicio"){
		document.getElementById('guardar').style.display = 'block';
		document.getElementById('editar').style.display = 'block';
		document.getElementById('crearCV').style.display = 'block';
	}else if(param=="verPerfil"){
		document.getElementById('guardar').style.display = 'none';	
		document.getElementById('editar').style.display= 'none';
		document.getElementById('crearCV').style.display = 'none';
        document.getElementById('verCV').style.display = 'block';	
        document.getElementById('verMiCV').style.display = 'none';        
	}
}

/**
 * Función que habilitará los campos en caso de que el usuario quiera editar su perfil
 * @function
*/
function habilitarCampo(){
	document.getElementById("guardar").disabled=false;
    document.getElementById("nombreUsuario").disabled=false;
    document.getElementById("apellidosUsuario").disabled=false;
    document.getElementById("edadUsuario").disabled=false;
    document.getElementById("experienciaUsuario").disabled=false;
    document.getElementById("elaboral").disabled=false;
    document.getElementById("resumen").disabled=false;
    document.getElementById("profesion").disabled=false;
    document.getElementById('profesionOption').style.display = 'block';	
    document.getElementById('profesionDIV').style.display = 'none';
    document.getElementById('elaboralOption').style.display = 'block';	
    document.getElementById('elaboralDIV').style.display = 'none';
}

/**
 * Función que deshabilitará los campos una vez el usuario haya editado su perfil y pulse guardar
 * @function
*/
function deshabilitarCampo(){
    document.getElementById("nombreUsuario").disabled=true;
    document.getElementById("apellidosUsuario").disabled=true;
    document.getElementById("edadUsuario").disabled=true;
    document.getElementById("experienciaUsuario").disabled=true;
    document.getElementById("elaboral").disabled=true;
    document.getElementById("resumen").disabled=true;    
    document.getElementById("profesion").disabled=true;  
    document.getElementById("rama").disabled=true; 
    document.getElementById('profesionOption').style.display = 'none';	
    document.getElementById('profesionDIV').style.display = 'block';
    document.getElementById('elaboralOption').style.display = 'none';	
    document.getElementById('elaboralDIV').style.display = 'block';
    	
}

function activarRama(){
    var profesion = document.getElementById('profesion');
			profesion.addEventListener("change", function(){
				
				if (profesion.value== 'Cientifico') {
					document.getElementById('rama').disabled = false;
				}else {
					document.getElementById('rama').disabled = true;
				}
			});
}