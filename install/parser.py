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
def split(str, num):
  return [ str[start:start+num] for start in range(0, len(str), num) ]

def yourCallback(pg):
  global LINENO
  title = pg.title.encode('ascii', 'ignore')
  text = pg.text.encode('ascii', 'ignore')
  if(REG.match(title)):
#    f.write("\n<=Title=>\n" + title + "\n<=/Title=>")
#    f.write("\n<=Text=>\n" + text + "\n<=/Text=>")
    doc.add_value(0, title);
    doc.add_value(1, text);

    # add ngram terms
    terms = split(title, 3)
    for term in terms:
      doc.add_term(term);

    text = re.sub(r'\W+', '', text)
    terms = split(text, 3)
    for term in terms:      
      doc.add_term(term)

    doc.add_term(title)
    db.add_document(doc)
    doc.clear_terms()
    doc.clear_values()

    LINENO = LINENO + 1
    if(LINENO % 1000 == 0):
     db.commit();

  else:
    print "NOWRITE"
  print pg




if len(sys.argv) != 2:
    print >> sys.stderr, "Usage: %s PATH_TO_DATABASE" % sys.argv[0]
    sys.exit(1)

page_parser.parseWithCallback("enwiktionary-20120606-pages-articles.xml", yourCallback)
