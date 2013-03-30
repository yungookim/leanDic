import sys
import xapian
import string

if len(sys.argv) != 2:
    print >> sys.stderr, "Usage: %s PATH_TO_DATABASE" % sys.argv[0]
    sys.exit(1)


# Open the database for update, creating a new database if necessary.
database = xapian.WritableDatabase(sys.argv[1], xapian.DB_CREATE_OR_OPEN)

#indexer = xapian.TermGenerator()
#stemmer = xapian.Stem("english")
#indexer.set_stemmer(stemmer)

try:
  title = ""
  title_flag = False
  text = ""
  text_flag = False

  for line in sys.stdin:
    line = string.strip(line)

    if(line=="<=Title=>" && !title_flag):
      title_flag = True
      assert !text_flag
    else if (title_flag):
      title += line
      assert !text_flag
    else if (line == "<=/Title=>"):
      title_flag = False
    else if (line == "<=Text=>"):
      text_flag = True
      assert !title_flag
    else if (line == "<=/Text=>"):
      assert text_flag
      text_flag = False
      assert !title_flag
    else if (text_flag):
      assert !title_flag
      

except StopIteration:
  pass
