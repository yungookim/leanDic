import page_parser
import re
import xapian
import sys

# Open the database for update, creating a new database if necessary.
db = xapian.WritableDatabase(sys.argv[1], xapian.DB_CREATE_OR_OPEN)
doc = xapian.Document()
LINENO = 0
#stemmer = xapian.Stem("english")
#indexer.set_stemmer(stemmer)

REG=re.compile('^[a-zA-Z0-9 \.]+$')
#f = open('dump','w+')
def ngrams(tokens):
  n_tokens = len(tokens)
  _list = []
  for i in xrange(n_tokens):
    for j in xrange(i+3, min(n_tokens, i+3)+1):
      _list.append(tokens[i:j])
  return _list

def yourCallback(pg):
  global LINENO
  title = pg.title.encode('ascii', 'ignore')
  text = pg.text.encode('ascii', 'ignore')
  if(REG.match(title)):
    doc.add_value(0, title);
    doc.add_value(1, text);

    # add ngram terms
    terms = ngrams(title)
    for term in terms:
      doc.add_term(term);

    text = re.sub(r'\W+', '', text)
    terms = ngrams(text)
    for term in terms:      
      doc.add_term(term)

    doc.add_term(title)
    db.add_document(doc)
    doc.clear_terms()
    doc.clear_values()

    LINENO = LINENO + 1
    if(LINENO % 1000 == 0):
     print "commit", LINENO
     db.commit();

  else:
    pass
#    print "NOWRITE"
#  print pg


if len(sys.argv) != 2:
    print >> sys.stderr, "Usage: %s PATH_TO_DATABASE" % sys.argv[0]
    sys.exit(1)

page_parser.parseWithCallback("enwiktionary-20120606-pages-articles.xml", yourCallback)
