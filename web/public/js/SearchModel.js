"use strict";
window.SearchModel = Backbone.Model.extend({
  defaults: {
  },
  initialize : function(){
    var self = this;
    $.get('/docid/' + this.get('docid'), function(ret){
      //TODO check for status code
      ret = ret.replace(/(\s)+/g, ' ');
      ret = ret.replace(/\n/g, "<br>");
      self.set('text', ret);
    });
  }
});

window.SearchCollection = Backbone.Collection.extend({
  model : SearchModel,
  initialize : function(){
    this.comparator = function(m){
      m.get('rank');
    }
  },
  search : function(token, next){
    var self = this;
    self.reset();
    $.get('/search/' + token , function(ret){
      ret = JSON.parse(ret);
      _.each(ret, function(ele){
        self.push(ele);
      });
      
      next();
    });
  }
});
