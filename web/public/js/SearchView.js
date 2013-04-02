"use strict";
window.SearchView = Backbone.View.extend({
  el : $(".core"),
  events : {
    "click #search_btn" : "search"
  },

  initialize: function() {
  },

  render: function(eventName) {
    var self = this;
    $("#search_result").empty();
    _.each(self.collection.models, function(model){
      $("#search_result").append(Mustache.render(window.Templates.searchResult, model.toJSON()));
    });
  },

  search : function(){
    console.log("Searching");
    var token = $("#search_token").val();
    var self = this;
    this.collection.search(token, function(ret){
      self.render();
    });
  }
  
});
