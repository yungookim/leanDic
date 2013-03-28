#!/usr/bin/python
import sys
from wiktionary_parser.xml_parser import XMLPageParser
from wiktionary_parser.languages.simple.page import simplePage

if (len(sys.argv) != 2):
	print "Input data dump file"
	sys.exit()


xml_file = open(sys.argv[1])
xml_parser = XMLPageParser(xml_file, simplePage)
from itertools import islice

# 3575190
pages = list(islice(xml_parser, 3575190))

f = open('dump','w+')

for pg in pages:
	title = pg.title.encode('ascii', 'ignore')
	text = pg.text.encode('ascii', 'ignore')
	f.write("\n<=Title=>" + title)
	f.write("\n<=Text=>" + text) 
	# print pg.discriminator
	# print pg.language
	# print pg.revision_id
	# pg.parse()
		
