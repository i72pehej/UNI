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
    if(param=="cientificos"){
		document.getElementById('cientificos').style.display = 'block';
	}else if(param=="IpD"){
		document.getElementById('IpD').style.display = 'block';			
	}
}