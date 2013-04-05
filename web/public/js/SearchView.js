"use strict";
window.SearchView = Backbone.View.extend({
  el : $(".core"),
  tokens : "",
  events : {
    "click #search_btn" : "search",
    "click #highlight_btn" : "highlight",
    "click #highlight_ngram_btn" : "highlight_ngram",
    "click #highlight_ngram_reduced_btn" : "highlight_reduced_ngram",
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
    self.render();
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

  highlight_reduced_ngram : function(){
    this.highlight_ngram(true);
  },

  highlight_ngram : function(evnt, reduce){
    var self = this;
    self.render();
    var query_tokens = self.tokens.split(' ');
    var ngram_dic;
    var final_dic = [];
    //Get list of the words associated with the ngrams of the querying token
    _.each(query_tokens, function(query_token){
      var ngrams = ngram(query_token);
      var results = [];
      _.each(ngrams, function(gram){
        results = results.concat(self.collection.dictionary[gram]);
      });
      ngram_dic = flatten(results);
      //Ignore tokens with less than 2 occurance from the overall texts
      for (var k in ngram_dic){
        // TODO : This can be improved for more precise highlighting
        if (reduce){
          if (ngram_dic[k] > 1 || _.size(ngram_dic) == 1){
            final_dic.push(k);
          }
        } else {
          final_dic.push(k);
        }
      }
    }); 
    console.log(final_dic);
    console.log(final_dic.length);
    //Start highlighting
    var txt_elements = $('.text');
    var mark_s = " <span class=\"label label-warning n_match\">";
    var mark_e = "</span> ";
    _.each(txt_elements, function(ele){
    	_.each(final_dic, function(token){
          var text = $(ele).html();
          $(ele).html(text.replace(' ' +  token + ' ', mark_s + token + mark_e));
        });
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

//Given the list of all the words from ngram dictionary, 
//return the list of words with with high occurance from the query string
var flatten = function(list){
  var _obj = {};
  _.each(list, function(each){
    if(_obj[each]){ _obj[each]++;}
    else{_obj[each] = 1;}
  });
  _.sortBy(_obj, function(val){
    return val;
  });
  return _obj;
}
