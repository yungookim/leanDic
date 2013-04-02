import web
import sys
import xapian
import json

urls = (
    '/search/(.*)', 'search',
    '/docid/(.*)', 'doc'
)

database = xapian.Database('./index')
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
			category = m.document.get_value(0)
			title = m.document.get_value(1)
			text = m.document.get_value(2)
			data = { 'rank' : rank, 'percent' : percent, 'title' : title, 'category' : category, 'docid' : m.docid}
			out.append(data)
		return json.dumps(out)

class doc:
	def GET(self, docid):
		doc = database.get_document(int(docid))
		return doc.get_value(2)
		
if __name__ == "__main__":
	app.run()
