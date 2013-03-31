"use strict";
window.SearchModel = Backbone.Model.extend({
  defaults: {
  },
  initialize : function(){
  }
});

window.SearchCollection = Backbone.Collection.extend({
  model : SearchModel,

  search : function(token, next){
    var self = this;
    self.reset();
    $.get('/' + token , function(ret){
      ret = JSON.parse(ret);
      _.each(ret, function(ele){
        self.push(ele);
      });
      next();
    });
  }
});
