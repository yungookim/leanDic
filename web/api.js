"use strict";

module.exports = function(app, model, _){

	// Example
	app.post('/*', function(req, res){
		res.end();
	});

	return this;
}