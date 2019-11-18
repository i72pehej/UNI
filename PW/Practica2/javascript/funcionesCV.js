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
    if(param=="verCV"){
        deshabilitarCampos();
        ocultarCampos();
    }
}

function ocultarCampos(){
    document.getElementById('fotoPerfil').style.display = 'none';
    document.getElementById('perfilImg').style.display = 'none';
    document.getElementById('guardarCV').style.display='none';
}          
          
function deshabilitarCampos(){
    document.getElementById("tipo").disabled=true;
    document.getElementById("datosPersonales").disabled=true;
    document.getElementById("contacto").disabled=true;
    document.getElementById("intereses").disabled=true;
    document.getElementById("articulos").disabled=true;
    document.getElementById("datosProfesionales").disabled=true;
    document.getElementById("educacion").disabled=true;
    document.getElementById("experienciaLaboral").disabled=true;
    document.getElementById("idiomas").disabled=true;
    document.getElementById("proyectos").disabled=true;
    document.getElementById("eventos").disabled=true;
    document.getElementById("tesisDoctorales").disabled=true;
    document.getElementById("produccionCientifica").disabled=true;
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