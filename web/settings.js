"use strict";

module.exports = function(nconf, express, app){

var fs = require('fs');
var logFile = fs.createWriteStream('./express.log', {flags: 'w'}); 

	app.configure(function(){
	 	app.use(express.static(__dirname + '/public'));	
		// app.use(express.bodyParser());
		// app.use(express.bodyParser({ uploadDir :__dirname + '/uploads' }));
		app.use(express.methodOverride());
		app.use(express.logger());
		app.use(express.compress());
		app.use(express.logger({stream: logFile}));
		app.use(function(err, req, res, next){
		  console.error(err.stack);
		  res.send(500, 'Something broke!');
		});
	});

	return this;
}
