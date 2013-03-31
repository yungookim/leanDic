import web
import sys
import xapian
import json

urls = (
    '/(.*)', 'search'
)

database = xapian.Database('./index_new')
app = web.application(urls, globals())

def ngrams(tokens):
	n_tokens = len(tokens)
	_list = []
	for i in xrange(n_tokens):
		for j in xrange(i+3, min(n_tokens, i+3)+1):
			_list.append(tokens[i:j])
	return _list

class search: 
	def GET(self, token):
		enquire = xapian.Enquire(database)
		ngram = ngrams(token)
		query_string = token + " " + " ".join(ngram)
		print ngram, token
		
		# Parse the query string to produce a Xapian::Query object.
		qp = xapian.QueryParser()
		qp.set_database(database)
		query = qp.parse_query(query_string)
		enquire.set_query(query)
		matches = enquire.get_mset(0, 10)
		
		out = []
		for m in matches:
			rank = m.rank
			percent = m.percent
			title = m.document.get_value(0)
			text = m.document.get_value(1)
			data = { 'rank' : rank, 'percent' : percent, 'title' : title, 'text' : text}
			out.append(data)
		return json.dumps(out)

if __name__ == "__main__":
	app.run()
