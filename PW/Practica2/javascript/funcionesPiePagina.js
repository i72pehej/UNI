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
    if(param=="Nosotros"){
		document.getElementById('nosotros').style.display = 'block';
	}else if(param=="seguridad"){
		document.getElementById('seguridad').style.display = 'block';
	}else if(param=="ayuda"){
        document.getElementById('ayuda').style.display = 'block';
    }
}

function mostrarProteccion(){
    document.getElementById("card").style.display='block';
    document.getElementById("condicionesLegales").style.display='none';
    document.getElementById("proteccionDatos").style.display='block';
}

function mostrarCondiciones(){
    document.getElementById("card").style.display='block';
    document.getElementById("proteccionDatos").style.display='none';
    document.getElementById("condicionesLegales").style.display='block';
}
