"use strict";
var http = require('http');

module.exports = function(app, model, _){

	app.get('/:word', function(req, res){
		http.get('http://127.0.0.1:8081/' + req.params.word, function(_res){
			_res.on('data', function(d) {
				res.send(d);
  			});
		}).on('error', function(e){
			console.log(e);
		});
	});

	return this;
}
