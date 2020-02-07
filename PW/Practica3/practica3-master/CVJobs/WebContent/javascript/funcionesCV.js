/**
 * Fichero funcionesCV.js que contendrá todas las funciones usadas en CV.html
 * @author Isabel María Ariza Velasco
*/

/**Función que recibirá un paramatro desde otra funcion externa. Según dicho parámetro, se ejecutará un trozo de código u otro 
   @function
   @param {cadena}
*/

function getCV(param){
        ocultarCampos();
        deshabilitarCampos();
    if(param=="verMiCV"){
		document.getElementById('editarCV').style.display = 'block';			
	} 
}

/**
 * Función que oculta los elemenos que permiten la edición del CV
 * @function
*/
function ocultarCampos(){
    document.getElementById('fotoPerfil').style.display = 'none';
    document.getElementById('perfilImg').style.display = 'none';
    document.getElementById('guardarCV').style.display='none';
}          
  
/**
 * Función que deshabilita todos los elemenos para que el CV no se pueda editar
 * @function
*/  
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

/**
 * Función que habilita todos los elemenos para que el CV se pueda editar
 * @function
*/  
function habilitarCampos(){
    document.getElementById("tipo").disabled=false;
    document.getElementById("datosPersonales").disabled=false;
    document.getElementById("contacto").disabled=false;
    document.getElementById("intereses").disabled=false;
    document.getElementById("articulos").disabled=false;
    document.getElementById("datosProfesionales").disabled=false;
    document.getElementById("educacion").disabled=false;
    document.getElementById("experienciaLaboral").disabled=false;
    document.getElementById("idiomas").disabled=false;
    document.getElementById("proyectos").disabled=false;
    document.getElementById("eventos").disabled=false;
    document.getElementById("tesisDoctorales").disabled=false;
    document.getElementById("produccionCientifica").disabled=false;
}

/**
 * Función que permite seleccionar una rama cientifica en el caso de que el usuario haya marcado esta profesión
 * @function
*/

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

function agregarEducacion(){
	  var fieldset=document.getElementById("educacion");
	  var inputs=document.getElementsByName("edu");
      
	  var br=document.createElement("br");
	  var newInput=document.createElement("input");
      var newInputE=document.createElement("input");
      var newInputD=document.createElement("input");
      var newInputH=document.createElement("input");
	  var grp=document.createElement("span");


	  newInput.name="edu";
      newInput.style.width="100%";
      newInput.type="text";
      newInput.placeholder="Titulo";
	  newInput.id="titulo"+(inputs.length+1);


      newInputE.name="edu";
      newInputE.style.width="100%";
      newInputE.type="text";
      newInputE.placeholder="Escuela, Instituto, Universidad...";
	  newInputE.id="escuela"+(inputs.length+1);
      
      newInputD.name="edu";
      newInputD.type="text";
      newInputD.placeholder="Desde";
	  newInputD.id="desde"+(inputs.length+1);
      
      newInputH.name="edu";
      newInputH.type="text";
      newInputH.placeholder="Hasta";
	  newInputH.id="hasta"+(inputs.length+1);
      


	  var btnRemove=document.createElement("input");
	  btnRemove.type="button";
	  btnRemove.value="-";
      btnRemove.className="boton";
      btnRemove.style.width="10%";

	  grp.appendChild(br);
	  grp.appendChild(newInput); 
      grp.appendChild(br);      
      grp.appendChild(newInputE); 
      grp.appendChild(br);
      grp.appendChild(newInputD);
      grp.appendChild(newInputH);
	  grp.appendChild(btnRemove);  
	  fieldset.appendChild(grp);
	  btnRemove.onclick=function(){var elem=this.parentNode;elem.parentNode.removeChild(elem);};

	}