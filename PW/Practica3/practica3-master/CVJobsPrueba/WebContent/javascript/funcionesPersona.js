/**
 * Fichero funcionesPersona.js que contendrá todas las funciones usadas en persona.html
 * @author Isabel María Ariza Velasco
 * @author Francisco Javier Castillo Rivillas
*/

/**Función que recibirá un paramatro desde otra funcion externa. Según dicho parámetro, se ejecutará un trozo de código u otro 
   @function
   @param {cadena}
*/

function getPersona(param){
   if(param=="cientificos"){
		
	}else if(param=="IpD"){
		document.getElementById('ramaDiv').style.display = 'none';			
	} 
}
/**
 * Función que ordena el contenido de la tabla por experiencia laboral de forma ascendente y descendente
 * @function
 *@param {number} numero de celda por la que va a ordenar
*/

function ordenar(n) {
  //Creamos la variables necesarias
  var table, rows, switching, i, x, y, shouldSwitch;
  var ordenar = document.getElementById('ordenar'); //Guarda informacion al seleccionar el orden de ordenacion
  table = document.getElementById("tablaPersonas"); //Guarda informacion de la tabla
  switching = true;
  ordenar.addEventListener("change", function(){  //Registra un evento change a la funcion function
    while (switching) {  /*Creamos un bucle que se recorrera hasta haber algun cambio*/

      //Comienza diciendo que no realizara ningun cambio
      switching = false;
      rows = table.rows;
      /*Este bucle recorre todas las filas de la tabla menos la primera ya que es el encabezado*/
      for (i = 1; i < (rows.length - 1); i++) {
        //Comienza sin haber cambio
        shouldSwitch = false;
        /*Guarda en x un elemento de la fila actual y en y de la siguente,
         en este caso el numero de años de experiencia*/
        x = rows[i].getElementsByTagName("TD")[n];
        y = rows[i + 1].getElementsByTagName("TD")[n];
        //Comprobamos si las dos filas deberian de cambiar de lugar
        if(ordenar.value=='asc'){ //Comenzamos con la ordenacion de la tabla en caso de querer que sea orden ascendente
          if (Number(x.innerHTML) > Number(y.innerHTML)) {
            shouldSwitch = true;
            break;  //Si se cumple, shouldSwitch=true Es decir, hay que cambiar las filas y se rompe el bucle
          }
        }else if(ordenar.value=='des'){ //Comenzamos con la ordenacion de la tabla en caso de querer que sea orden descendente
          if (Number(x.innerHTML) < Number(y.innerHTML)) {
            shouldSwitch = true;
            break;  //Si se cumple, shouldSwitch=true y se rompe el bucle
          }
        }
      }
      if (shouldSwitch){  //Si shouldSwitch es true porque se desea una ordenacion realiza el cambio de filas de la tabla, y marca que se ha realizado el cambio
        rows[i].parentNode.insertBefore(rows[i + 1], rows[i]);
        switching = true;
      }
    }
  });
}

/**
 * Función que rellena el contenido de la tabla segun su situacion laboral
 * @function
 *@param {number} numero de celda por la que va a ordenar
*/
function situacionLaboral(n) {
  var table = document.getElementById('tablaPersonas');	//Guarda informacion de la tabla
  var situacion= document.getElementById('situacionLaboral'); //Guarda informacion al seleccionar el orden de ordenacion
  situacion.addEventListener("change", function(){  //Registra un evento change a la funcion function
	
	for(var i=1; i< table.rows.length; i++){	//Bucle para recorrer las filas de la tabla
		if (table.rows[i].classList.contains("noSearch")) {	//Si td tiene clase noSearch no se busca en su contenido
            continue;
        }
		
        var x = table.rows[i].getElementsByTagName("TD")[n];	//Guarda en x un elemento de la fila actual
		if(x.innerHTML.toLowerCase() != situacion.value.toLowerCase()){	// Si no coincide el dato guardado en la variable x y el valor dado a la ordenacion elegida entonces no imprime la fila  
			table.rows[i].style.display = 'none';
		}else{		//En caso contrario muestra la fila
			table.rows[i].style.display = '';
		}
	}
  });
}

/**
 * Función que rellena el contenido de la tabla segun la rama laboral a la que se dedica
 * @function
 *@param {number} numero de celda por la que va a ordenar
*/
function rama(n) {
  var table = document.getElementById('tablaPersonas');		//Guarda informacion de la tabla
  var situacion= document.getElementById('rama');	//Guarda informacion al seleccionar el orden de ordenacion
  situacion.addEventListener("change", function(){  //Registra un evento change a la funcion function
	
	for(var i=1; i< table.rows.length; i++){//Bucle para recorrer las filas de la tabla
		if (table.rows[i].classList.contains("noSearch")) {	//Si td tiene clase noSearch no se busca en su contenido
            continue;
        }
		
        var x = table.rows[i].getElementsByTagName("TD")[n];	//Guarda en x un elemento de la fila actual
		if(x.innerHTML.toLowerCase() != situacion.value.toLowerCase()){	// Si no coincide el dato guardado en la variable x y el valor dado a la ordenacion elegida entonces no imprime la fila  
			table.rows[i].style.display = 'none';
		}else{	//En caso contrario muestra la fila
			table.rows[i].style.display = '';
		}
	}
  });
}

/**
 * Función que buscar en el contenido de la tabla el nombre del empleado indicado
 * @function
*/
function buscar(){
	var table = document.getElementById('tablaPersonas');	//Guarda informacion de la tabla
	var textoBuscado = document.getElementById('buscardor').value.toLowerCase();	//Guarda El texto introducido para buscar en la variable 
	let total = 0;

	// Recorremos todas las filas con contenido de la tabla
	for (var i = 1; i < table.rows.length; i++) {
		// Si el td tiene la clase "noSearch" no se busca en su contenido
		if (table.rows[i].classList.contains("noSearch")) {
			continue;
		}
		let found = false;
		var cellsOfRow = table.rows[i].getElementsByTagName('td');
		// Recorremos todas las celdas
		for (var j = 0; j < cellsOfRow.length && !found; j++) {
			var compareWith = cellsOfRow[j].innerHTML.toLowerCase();
			// Buscamos el texto en el contenido de la celda
			if (textoBuscado.length == 0 || compareWith.indexOf(textoBuscado) > -1) {
				found = true;
				total++;
			}
		}
		if (found) {
			table.rows[i].style.display = '';
		} else {
			// si no ha encontrado ninguna coincidencia, esconde la fila de la tabla
			table.rows[i].style.display = 'none';
		}
	}

	
	var ultimaTR=table.rows[table.rows.length-1];
	var td=ultimaTR.querySelector("td");
	ultimaTR.classList.remove("hide", "red");
	if (textoBuscado == "") {	//Si no busca nada no muestra nada acerca de coincidencias encontradas 
		ultimaTR.classList.add("hide");
	} else if (total) {	// mostramos una nueva fila en la que se informe del numero de coincidencias obtenidas en caso de encontrarlas 
		td.innerHTML="Se ha encontrado "+total+" coincidencia"+((total>1)?"s":"");
	} else {	//En caso contrario mostraremos un mensaje de que no se han encontrado coincidencias 
		ultimaTR.classList.add("red");
		td.innerHTML="No se han encontrado coincidencias";
	}
}