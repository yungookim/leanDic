"use strict";
window.SearchView = Backbone.View.extend({
  el : $(".core"),
  tokens : "",
  events : {
    "click #search_btn" : "search",
    "click #highlight_btn" : "highlight",
    "click #highlight_ngram_btn" : "highlight_ngram",
    "click #make_dictionary_btn" : "show_dictionary"
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
    var mark_s = " <span class=\"label label-success match\">";
    var mark_e = "</span> ";
    _.each(txt_elements, function(ele){
    	_.each(tokens, function(token){
          var text = $(ele).html();
          $(ele).html(text.replace(' ' +  token + ' ', mark_s + token + mark_e));
        });
    });
    $("#numb_matching").html($('.match').length);
  },

  search : function(){
    var self = this;
    var token = $("#search_token").val();
    self.tokens = token;
    this.collection.search(token, function(ret){
      self.render();
    });
  },

  highlight_ngram : function(){
    var self = this;
    var txt_elements = $('.text');
    var query_tokens = self.tokens.split(' ');
    var mark_s = " <span class=\"label label-warning n_match\">";
    var mark_e = "</span> ";

    //Get list of the words associated with the ngrams of the querying token
    _.each(query_tokens, function(query_token){
      var ngrams = ngram(query_token);
      var results = [];
      _.each(ngrams, function(gram){
        results = results.concat(self.collection.dictionary[gram]);
      });
      ngram_dic = flatten(results);
    }); 
  },

  show_dictionary : function(){
    var self = this;
    this.collection.build_dictionary(function(){
      $('#dictionary_size').html(self.collection.numb_words);
      $('#ngram_size').html(_.size(self.collection.dictionary));
      window.dic = self.collection.dictionary;
      console.log(self.collection.dictionary);
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

var ngram_dic = function(list){

}
