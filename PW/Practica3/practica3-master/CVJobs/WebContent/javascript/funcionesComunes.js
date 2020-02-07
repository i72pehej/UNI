/**
 * Fichero funcionesComunes.js que contendrá todas las funciones que sean comunes en todos los archivos
 * @author Isabel María Ariza Velasco
*/

/**
 * Función que recuperará de la URL de donde viene la petición.
 * Según el parametro recuperado, llamará a una de las funciones declaradas en los demás fichero .js
 * @function
*/
function getParams(){
	console.log("Entra");
    var idx= document.URL.indexOf('?');
    var param;
    var pairs;
    
    if(idx != -1){
        pairs = document.URL.substring(idx+1, document.URL.length).split('&');
    }
    for (var i=0; i<pairs.length; i++){
        nameVal = pairs[i].split('=');
        param= nameVal[1];
    }
    
    console.log("Despues del for: "+param);
    
    if(param=="invitado"){
    	
        getInicio(param);
    }
    
    if(param=="verCV" || param=="verMiCV"){
        getCV(param);
    }
    
    if(param=="inicio" || param=="verPerfil"){
        getPerfil(param);
    }
    
    if(param=="cientificos" || param=="IpD"){
        getPersona(param);
    }  
    
    if(param=="Nosotros" || param=="seguridad" || param=="ayuda"){
        getPiePagina(param);
    }
}