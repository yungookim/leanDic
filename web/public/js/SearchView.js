"use strict";
window.SearchView = Backbone.View.extend({
  el : $(".core"),
  events : {
    "click #search_btn" : "search"
  },

  initialize: function() {
    var self = this;    
  },

  render: function(eventName) {
    var self = this;
    $("#search_result").empty();
    _.each(self.collection.models, function(model){
      $("#search_result").append(Mustache.render(window.Templates.searchResult, model.toJSON()));
    });
  },

  search : function(){
    var token = $("#search_token").val();
    var self = this;
    this.collection.search(token, function(ret){
//      console.log(ret);
//	console.log(txtwiki.parseWikitext(ret[0].text))
      self.render();
    });
  }
  
});
