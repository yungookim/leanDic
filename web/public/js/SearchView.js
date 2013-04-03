"use strict";
window.SearchView = Backbone.View.extend({
  el : $(".core"),
  tokens : "",
  events : {
    "click #search_btn" : "search",
    "click #highlight_btn" : "highlight"
  },

  initialize: function() {
	this.collection.bind('change', _.bind(this.render, this));
  },

  render: function(eventName) {
    var self = this;
    $("#search_result").empty();
    _.each(self.collection.models, function(model){
      $("#search_result").append(Mustache.render(window.Templates.searchResult, model.toJSON()));
    });
  },

  highlight : function(){
    var self = this;
    var txt_elements = $('.text');
    var tokens = self.tokens.split(' ');
    var mark_s = " <span class=\"text-error\">";
    var mark_e = "</span> ";
    _.each(txt_elements, function(ele){
    	_.each(tokens, function(token){
          $(ele).html($(ele).html().replace(' ' +  token + ' ', mark_s + token + mark_e));
          ngram(token);
        });
    });
  },

  search : function(){
    var self = this;
    var token = $("#search_token").val();
    self.tokens = token;
    this.collection.search(token, function(ret){
      self.render();
    });
  }
});

var ngram = function(token){
  var n_tokens = token.length
  var list = []
  
  for(var i = 0; i < n_tokens; i++){
    for(var j = i+3; j < Math.min(n_tokens, i+3) + 1; j++){
      var _token = token.substring(i, j).replace(/[^a-zA-Z0-9]/g,'');
      if (_token.length == 3){
        list.push(_token);
      }
    } 
  }
  return list;
}
