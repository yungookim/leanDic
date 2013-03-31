"use strict";
$(function(){


  window.loadTemplate(function(){
    $(window).load(function(){
      // Make sure all the external libraries are loaded
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
    window.searchCollection = new SearchCollection();
    (new SearchView({ collection : searchCollection }));
  },
  
  defaultAction : function(){

  }
});

window.loadTemplate = function(next){
  window.Templates = window.Templates || {};
  var templateList = ['searchResult'];
  _.each(templateList, function(name){
    $.get('templates/' + name + '.html', function(data) {
      window.Templates[name] = data;
    }, 'text');
  });
  next();
}
