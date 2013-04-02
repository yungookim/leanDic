"use strict";
var http = require('http');

module.exports = function(app, model, _){

	app.get('/search/:word', function(req, res){
		http.get('http://127.0.0.1:8081/search/' + req.params.word, function(_res){
			_res.on('data', function(d){ 
				res.write(d, 'UTF-8')
				res.end();
  			});
		}).on('error', function(e){
			console.log(e);
		});
	});
	
	app.get('/docid/:id', function(req, res){
		http.get('http://127.0.0.1:8081/docid/' + req.params.id, function(_res){
			_res.on('data', function(d){
				res.write(d, 'UTF-8');
				res.end();
			});
		}).on('error', function(e){
			console.log(e);
		});
	});

	return this;
}
