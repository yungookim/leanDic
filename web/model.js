var pg      = require('pg');

pg.on('error', function(err, client){
  console.err(err);
});

module.exports = function(nconf, _){

  var pg_address = nconf.get('pg_address');

  pg.defaults.user     = nconf.get('pg_user');
  pg.defaults.password = nconf.get('pg_pw');
  pg.defaults.database = nconf.get('pg_db');
  pg.defaults.host     = nconf.get('pg_host');

  var functions = {
    // Functions go here
  }

  return functions;
}
