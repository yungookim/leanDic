/* Warning: This file is generated by /data/home/olly/tmp/xapian-svn-snapshot/tags/1.2.14/xapian/xapian-core/tests/collate-test - do not modify directly! */

    if (writable&&!remote&&!inmemory) {
	static const test_desc tests[] = {
	    { "queries1", test_queries1 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
