import re
import xapian
import sys
import glob
import os
import fnmatch

pattern = re.compile('([^\s\w]|_)+')

def ngrams(tokens):
	n_tokens = len(tokens)
	_list = []
	for i in xrange(n_tokens):
		for j in xrange(i+3, min(n_tokens, i+3)+1):
			_list.append(tokens[i:j])
	return _list

def index_files(file_list):
	global LINENO
	for _file in file_list:
		f = open(_file, 'r')
		category = os.path.basename(os.path.dirname(_file))
		title = os.path.splitext(os.path.basename(_file))[0]
		text = f.read().lower()
		
		doc.add_value(0, category)
		doc.add_value(1, title)
		doc.add_value(2, text)
		doc.add_value(3, _file)

		#add terms to index
		doc.add_term(title)
		_text = pattern.sub('', text)
		terms = _text.split(' ')
		for term in terms:
			t = term.lower()
			if len(t) > 0 and len(t) < 50 :
				doc.add_term(t)

		title_ngrams = ngrams(title)
		txt_ngrams = ngrams(text)
		#add ngram terms index
		for title_ngram in title_ngrams:
			doc.add_term(title_ngram)

		for txt_ngram in txt_ngrams:
			doc.add_term(txt_ngram)

		db.add_document(doc)
		doc.clear_terms()
		doc.clear_values()

		LINENO += 1
		if (LINENO % 1000 == 0):
			print "commit", LINENO
			db.commit()

if len(sys.argv) != 2:
	print >> sys.stderr, "Usage: %s PATH_TO_DATABASE" % sys.argv[0]
	sys.exit(1)

# Open the database for update, creating a new database if necessary.
db = xapian.WritableDatabase(sys.argv[1], xapian.DB_CREATE_OR_OPEN)
doc = xapian.Document()
LINENO = 0

file_list = []
for root, dirnames, filenames in os.walk('/home/kimy/OANC/data/'):
	for filename in fnmatch.filter(filenames, '*.txt'):
		file_list.append(os.path.join(root, filename))
index_files(file_list)
#commit any remaining documents
db.commit()

#file_list = glob.glob('/home/kimy/OANC/data/written_2/technical/911report/*.txt')
