"use strict";
var express = require('express')
  , app     = express()
  , nconf   = require('nconf')
  , _        = require('underscore');

//Load configuration hierarch
nconf.env().argv().file(__dirname + '/config.json');

var model    = new require('./model')(nconf, _);
var settings = new require('./settings')(nconf, express, app);
var api      = new require('./api')(app, model, _);

// Start listening after everything is loaded
app.listen(nconf.get("port"));
