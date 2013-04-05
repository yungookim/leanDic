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
  dictionary : {},
  numb_words : 0,
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
  },

  build_dictionary : function(next){
    var self = this;
    _.each(self.models, function(model){
      var tokens = model.get('text').replace(/[^a-zA-Z ]/g,'').split(' ');
      _.each(tokens, function(token){
        if (token.length < 3) {return;}
        var trigrams = ngram(token);
        _.each(trigrams, function(gram){
          if (_.has(self.dictionary, gram)){
            if (_.indexOf(self.dictionary[gram], token) == -1){
              self.dictionary[gram].push(token);
              self.numb_words++;
            }
          } else {
            self.dictionary[gram] = [token];
            self.numb_words++;
          }
        });
      });
    });
    next();
  }
});
