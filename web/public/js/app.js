"use strict";
$(function(){


  window.loadTemplate(function(){
    $(window).load(function(){
      // Make sure all the external libraries are loaded
      // And finally, load up the youtube api lib
      window.app = new AppRouter;
      Backbone.history.start();
    });
  });
})

var AppRouter = Backbone.Router.extend({
  routes : {
    "" : "landing",
    "*actions": 'defaultAction'
  },

  landing : function(){
    
  },
  
  defaultAction : function(){

  }
});

window.loadTemplate = function(next){
  window.Templates = window.Templates || {};
  var templateList = ['example'];
  _.each(templateList, function(name){
    $.get('templates/' + name + '.html', function(data) {
      window.Templates[name] = data;
    }, 'text');
  });
  next();
}