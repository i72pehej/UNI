function getParams(){
    var idx= document.URL.indexOf('?');
    var param;
    
    if(idx != -1){
        var pairs = document.URL.substring(idx+1, document.URL.length).split('&');
    }
    for (var i=0; i<pairs.length; i++){
        nameVal = pairs[i].split('=');
        param= nameVal[1];
    }
    if(param=="inicio"){
		document.getElementById('botones').style.display = 'block';
	}else if(param=="persona"){
		document.getElementById('botones').style.display = 'none';			
	}
}

function habilitarCampo(){
    document.getElementById("nombreUsuario").disabled=false;
    document.getElementById("edadUsuario").disabled=false;
    document.getElementById("experienciaUsuario").disabled=false;
    document.getElementById("elaboral").disabled=false;
    document.getElementById("resumen").disabled=false;    
}

function deshabilitarCampo(){
    document.getElementById("nombreUsuario").disabled=true;
    document.getElementById("edadUsuario").disabled=true;
    document.getElementById("experienciaUsuario").disabled=true;
    document.getElementById("elaboral").disabled=true;
    document.getElementById("resumen").disabled=true;    
}