/**
 * Fichero funcionesPerfil.js que contendrá todas las funciones usadas en miPerfil.html
 * @author Isabel María Ariza Velasco
*/

/**Función que recibirá un paramatro desde otra funcion externa. Según dicho parámetro, se ejecutará un trozo de código u otro 
   @function
   @param {cadena}
*/
function getPerfil(param){
    if(param=="inicio"){
		document.getElementById('botones').style.display = 'block';
	}else if(param=="verPerfil"){
		document.getElementById('botones').style.display = 'none';	
        document.getElementById('verCV').style.display = 'block';	
        document.getElementById('verMiCV').style.display = 'none';        
	}
}

/**
 * Función que habilitará los campos en caso de que el usuario quiera editar su perfil
 * @function
*/
function habilitarCampo(){
    document.getElementById("nombreUsuario").disabled=false;
    document.getElementById("edadUsuario").disabled=false;
    document.getElementById("experienciaUsuario").disabled=false;
    document.getElementById("elaboral").disabled=false;
    document.getElementById("resumen").disabled=false;
    document.getElementById("profesion").disabled=false;        
}

/**
 * Función que deshabilitará los campos una vez el usuario haya editado su perfil y pulse guardar
 * @function
*/
function deshabilitarCampo(){
    document.getElementById("nombreUsuario").disabled=true;
    document.getElementById("edadUsuario").disabled=true;
    document.getElementById("experienciaUsuario").disabled=true;
    document.getElementById("elaboral").disabled=true;
    document.getElementById("resumen").disabled=true;    
    document.getElementById("profesion").disabled=true;  
    document.getElementById("rama").disabled=true;      
}

function activarRama(){
    var profesion = document.getElementById('profesion');
			profesion.addEventListener("change", function(){
				if (profesion.value== '2') {
					document.getElementById('rama').disabled = false;
				}else {
					document.getElementById('rama').disabled = true;
				}
			});
}