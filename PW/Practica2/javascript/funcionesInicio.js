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
    if(param=="invitado"){
		document.getElementById('invitado').style.display = 'none';
    // alert("HOLA");
	}
}
