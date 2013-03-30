/* Warning: This file is generated by /data/home/olly/tmp/xapian-svn-snapshot/tags/1.2.14/xapian/xapian-core/tests/collate-test - do not modify directly! */

    if (!backend) {
	static const test_desc tests[] = {
	    { "stubdb7", test_stubdb7 },
	    { "defaultctor1", test_defaultctor1 },
	    { "copyassign1", test_copyassign1 },
	    { "matchspy6", test_matchspy6 },
	    { "trivial1", test_trivial1 },
	    { "getqterms1", test_getqterms1 },
	    { "getqterms2", test_getqterms2 },
	    { "emptyquery2", test_emptyquery2 },
	    { "emptyquery3", test_emptyquery3 },
	    { "querylen1", test_querylen1 },
	    { "querylen2", test_querylen2 },
	    { "queryvalid1", test_queryvalid1 },
	    { "subqcollapse1", test_subqcollapse1 },
	    { "emptyquerypart1", test_emptyquerypart1 },
	    { "singlesubq1", test_singlesubq1 },
	    { "stemlangs1", test_stemlangs1 },
	    { "weight1", test_weight1 },
	    { "nosuchdb1", test_nosuchdb1 },
	    { "addvalue1", test_addvalue1 },
	    { "poscollapse2", test_poscollapse2 },
	    { "uninitdb1", test_uninitdb1 },
	    { "scaleweight3", test_scaleweight3 },
	    { "scaleweight4", test_scaleweight4 },
	    { "rset3", test_rset3 },
	    { "rset4", test_rset4 },
	    { "valuesetmatchdecider1", test_valuesetmatchdecider1 },
	    { "emptymset1", test_emptymset1 },
	    { "nosubdatabases1", test_nosubdatabases1 },
	    { "document1", test_document1 },
	    { "document2", test_document2 },
	    { "valuege3", test_valuege3 },
	    { "queryterms1", test_queryterms1 },
	    { "matchnothing1", test_matchnothing1 },
	    { "nearsubqueries1", test_nearsubqueries1 },
	    { "serialise_document1", test_serialise_document1 },
	    { "serialise_query1", test_serialise_query1 },
	    { "serialise_query2", test_serialise_query2 },
	    { "serialise_query3", test_serialise_query3 },
	    { "serialise_query4", test_serialise_query4 },
	    { "double_register_leak", test_double_register_leak },
	    { "registry1", test_registry1 },
	    { "registry2", test_registry2 },
	    { "registry3", test_registry3 },
	    { "multivaluekeymaker1", test_multivaluekeymaker1 },
	    { "stem1", test_stem1 },
	    { "stem2", test_stem2 },
	    { "stemlangs2", test_stemlangs2 },
	    { "utf8iterator1", test_utf8iterator1 },
	    { "utf8iterator2", test_utf8iterator2 },
	    { "unicode1", test_unicode1 },
	    { "caseconvert1", test_caseconvert1 },
	    { "caseconvert2", test_caseconvert2 },
	    { "utf8convert1", test_utf8convert1 },
	    { "unicodepredicates1", test_unicodepredicates1 },
	    { "valuestats5", test_valuestats5 },
	    { "fixedweightsource2", test_fixedweightsource2 },
	    { "tradweight3", test_tradweight3 },
	    { "bm25weight3", test_bm25weight3 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (backend) {
	static const test_desc tests[] = {
	    { "zerodocid1", test_zerodocid1 },
	    { "emptyquery1", test_emptyquery1 },
	    { "simplequery1", test_simplequery1 },
	    { "simplequery2", test_simplequery2 },
	    { "simplequery3", test_simplequery3 },
	    { "wildquery1", test_wildquery1 },
	    { "msetmaxitems1", test_msetmaxitems1 },
	    { "expandweights1", test_expandweights1 },
	    { "expandweights2", test_expandweights2 },
	    { "expandweights3", test_expandweights3 },
	    { "expandweights4", test_expandweights4 },
	    { "expandmaxitems1", test_expandmaxitems1 },
	    { "boolquery1", test_boolquery1 },
	    { "msetfirst1", test_msetfirst1 },
	    { "topercent1", test_topercent1 },
	    { "topercent2", test_topercent2 },
	    { "expandfunctor1", test_expandfunctor1 },
	    { "pctcutoff1", test_pctcutoff1 },
	    { "pctcutoff2", test_pctcutoff2 },
	    { "pctcutoff3", test_pctcutoff3 },
	    { "cutoff1", test_cutoff1 },
	    { "allowqterms1", test_allowqterms1 },
	    { "maxattain1", test_maxattain1 },
	    { "reversebool1", test_reversebool1 },
	    { "reversebool2", test_reversebool2 },
	    { "getmterms1", test_getmterms1 },
	    { "getmterms2", test_getmterms2 },
	    { "poscollapse1", test_poscollapse1 },
	    { "repeatquery1", test_repeatquery1 },
	    { "fetchdocs1", test_fetchdocs1 },
	    { "absentterm1", test_absentterm1 },
	    { "absentterm2", test_absentterm2 },
	    { "rset1", test_rset1 },
	    { "rset2", test_rset2 },
	    { "eliteset1", test_eliteset1 },
	    { "eliteset2", test_eliteset2 },
	    { "eliteset3", test_eliteset3 },
	    { "eliteset4", test_eliteset4 },
	    { "eliteset5", test_eliteset5 },
	    { "termlisttermfreq1", test_termlisttermfreq1 },
	    { "qterminfo1", test_qterminfo1 },
	    { "qterminfo2", test_qterminfo2 },
	    { "msetzeroitems1", test_msetzeroitems1 },
	    { "matches1", test_matches1 },
	    { "wqf1", test_wqf1 },
	    { "qlen1", test_qlen1 },
	    { "termlist1", test_termlist1 },
	    { "termlist2", test_termlist2 },
	    { "termlist3", test_termlist3 },
	    { "termlist4", test_termlist4 },
	    { "puncterms1", test_puncterms1 },
	    { "spaceterms1", test_spaceterms1 },
	    { "xor1", test_xor1 },
	    { "xor2", test_xor2 },
	    { "getdoc1", test_getdoc1 },
	    { "emptyop1", test_emptyop1 },
	    { "checkatleast1", test_checkatleast1 },
	    { "checkatleast2", test_checkatleast2 },
	    { "checkatleast3", test_checkatleast3 },
	    { "allpostlist1", test_allpostlist1 },
	    { "emptyterm1", test_emptyterm1 },
	    { "scaleweight1", test_scaleweight1 },
	    { "scaleweight2", test_scaleweight2 },
	    { "bm25weight1", test_bm25weight1 },
	    { "tradweight1", test_tradweight1 },
	    { "tradweight4", test_tradweight4 },
	    { "dbstats1", test_dbstats1 },
	    { "alldocspl3", test_alldocspl3 },
	    { "msetfirst2", test_msetfirst2 },
	    { "bm25weight2", test_bm25weight2 },
	    { "tradweight2", test_tradweight2 },
	    { "emptydb1", test_emptydb1 },
	    { "msetweights1", test_msetweights1 },
	    { "closedb1", test_closedb1 },
	    { "closedb3", test_closedb3 },
	    { "collapsekey5", test_collapsekey5 },
	    { "termstats", test_termstats },
	    { "msetiterator1", test_msetiterator1 },
	    { "msetiterator2", test_msetiterator2 },
	    { "msetiterator3", test_msetiterator3 },
	    { "esetiterator1", test_esetiterator1 },
	    { "esetiterator2", test_esetiterator2 },
	    { "collapsekey1", test_collapsekey1 },
	    { "collapsekey2", test_collapsekey2 },
	    { "collapsekey3", test_collapsekey3 },
	    { "collapsekey4", test_collapsekey4 },
	    { "allterms1", test_allterms1 },
	    { "allterms2", test_allterms2 },
	    { "allterms3", test_allterms3 },
	    { "allterms4", test_allterms4 },
	    { "allterms5", test_allterms5 },
	    { "allterms6", test_allterms6 },
	    { "specialterms1", test_specialterms1 },
	    { "specialterms2", test_specialterms2 },
	    { "postlist1", test_postlist1 },
	    { "postlist2", test_postlist2 },
	    { "postlist3", test_postlist3 },
	    { "postlist4", test_postlist4 },
	    { "postlist5", test_postlist5 },
	    { "postlist6", test_postlist6 },
	    { "collfreq1", test_collfreq1 },
	    { "sortvalue1", test_sortvalue1 },
	    { "sortrel1", test_sortrel1 },
	    { "matchall1", test_matchall1 },
	    { "matchspy5", test_matchspy5 },
	    { "synonym1", test_synonym1 },
	    { "synonym2", test_synonym2 },
	    { "synonym3", test_synonym3 },
	    { "synonym4", test_synonym4 },
	    { "valuerange1", test_valuerange1 },
	    { "valuege1", test_valuege1 },
	    { "valuege2", test_valuege2 },
	    { "valuele1", test_valuele1 },
	    { "valuege4", test_valuege4 },
	    { "valuerange3", test_valuerange3 },
	    { "valuerange4", test_valuerange4 },
	    { "consistency3", test_consistency3 },
	    { "pctcutoff5", test_pctcutoff5 },
	    { "topercent4", test_topercent4 },
	    { "topercent5", test_topercent5 },
	    { "topercent6", test_topercent6 },
	    { "valueweightsource1", test_valueweightsource1 },
	    { "fixedweightsource1", test_fixedweightsource1 },
	    { "xor3", test_xor3 },
	    { "valuestream2", test_valuestream2 },
	    { "valuestream3", test_valuestream3 },
	    { "valuemapsource1", test_valuemapsource1 },
	    { "bm25weight4", test_bm25weight4 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (backend&&!inmemory&&!remote) {
	static const test_desc tests[] = {
	    { "stubdb1", test_stubdb1 },
	    { "stubdb2", test_stubdb2 },
	    { "stubdb3", test_stubdb3 },
	    { "stubdb4", test_stubdb4 },
	    { "stubdb5", test_stubdb5 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (backend&&!multi) {
	static const test_desc tests[] = {
	    { "multidb3", test_multidb3 },
	    { "multidb4", test_multidb4 },
	    { "multidb5", test_multidb5 },
	    { "rsetmultidb1", test_rsetmultidb1 },
	    { "rsetmultidb3", test_rsetmultidb3 },
	    { "uuid1", test_uuid1 },
	    { "rsetmultidb2", test_rsetmultidb2 },
	    { "multiexpand1", test_multiexpand1 },
	    { "valuestream1", test_valuestream1 },
	    { "valuemapsource2", test_valuemapsource2 },
	    { "decvalwtsource4", test_decvalwtsource4 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (backend&&!multi&&!remote) {
	static const test_desc tests[] = {
	    { "checkinitweight1", test_checkinitweight1 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (backend&&!remote) {
	static const test_desc tests[] = {
	    { "matchdecider1", test_matchdecider1 },
	    { "matchdecider2", test_matchdecider2 },
	    { "matchdecider3", test_matchdecider3 },
	    { "consistency1", test_consistency1 },
	    { "userweight1", test_userweight1 },
	    { "valuesetmatchdecider2", test_valuesetmatchdecider2 },
	    { "matchspy1", test_matchspy1 },
	    { "externalsource4", test_externalsource4 },
	    { "sortfunctor1", test_sortfunctor1 },
	    { "changesorter1", test_changesorter1 },
	    { "sortfunctorempty1", test_sortfunctorempty1 },
	    { "oldsortfunctor1", test_oldsortfunctor1 },
	    { "oldchangesorter1", test_oldchangesorter1 },
	    { "oldsortfunctorempty1", test_oldsortfunctorempty1 },
	    { "checkstatsweight1", test_checkstatsweight1 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (backend&&!remote&&!multi) {
	static const test_desc tests[] = {
	    { "pctcutoff4", test_pctcutoff4 },
	    { "externalsource1", test_externalsource1 },
	    { "externalsource3", test_externalsource3 },
	    { "changemaxweightsource1", test_changemaxweightsource1 },
	    { "emptyvalwtsource1", test_emptyvalwtsource1 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (brass||chert) {
	static const test_desc tests[] = {
	    { "lockfilealreadyopen1", test_lockfilealreadyopen1 },
	    { "compactempty1", test_compactempty1 },
	    { "compactmultipass1", test_compactmultipass1 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (brass||chert||flint) {
	static const test_desc tests[] = {
	    { "lockfileumask1", test_lockfileumask1 },
	    { "lockfilefd0or1", test_lockfilefd0or1 },
	    { "failedreplace1", test_failedreplace1 },
	    { "failedreplace2", test_failedreplace2 },
	    { "compactmerge1", test_compactmerge1 },
	    { "compactstub1", test_compactstub1 },
	    { "compactstub2", test_compactstub2 },
	    { "compactstub3", test_compactstub3 },
	    { "compactstub4", test_compactstub4 },
	    { "crashrecovery1", test_crashrecovery1 },
	    { "lazytablebug1", test_lazytablebug1 },
	    { "cursordelbug1", test_cursordelbug1 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (flint) {
	static const test_desc tests[] = {
	    { "flintdatabaseopeningerror1", test_flintdatabaseopeningerror1 },
	    { "flintdatabaseformaterror1", test_flintdatabaseformaterror1 },
	    { "flintdatabaseformaterror2", test_flintdatabaseformaterror2 },
	    { "flintdatabaseformaterror3", test_flintdatabaseformaterror3 },
	    { "flintbackwardcompat1", test_flintbackwardcompat1 },
	    { "flintbackwardcompat2", test_flintbackwardcompat2 },
	    { "flintdatabaseopen1", test_flintdatabaseopen1 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (generated) {
	static const test_desc tests[] = {
	    { "msize1", test_msize1 },
	    { "msize2", test_msize2 },
	    { "xordecay1", test_xordecay1 },
	    { "ordecay1", test_ordecay1 },
	    { "ordecay2", test_ordecay2 },
	    { "orcheck1", test_orcheck1 },
	    { "compactnorenumber1", test_compactnorenumber1 },
	    { "compactmultichunks1", test_compactmultichunks1 },
	    { "compactmissingtables1", test_compactmissingtables1 },
	    { "compactmergesynonym1", test_compactmergesynonym1 },
	    { "matchspy2", test_matchspy2 },
	    { "matchspy4", test_matchspy4 },
	    { "valuerange5", test_valuerange5 },
	    { "topercent7", test_topercent7 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (inmemory) {
	static const test_desc tests[] = {
	    { "stubdb6", test_stubdb6 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (metadata) {
	static const test_desc tests[] = {
	    { "metadata3", test_metadata3 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (metadata&&!inmemory) {
	static const test_desc tests[] = {
	    { "metadata2", test_metadata2 },
	    { "metadata4", test_metadata4 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (positional) {
	static const test_desc tests[] = {
	    { "phrase3", test_phrase3 },
	    { "near1", test_near1 },
	    { "near2", test_near2 },
	    { "phrase1", test_phrase1 },
	    { "phrase2", test_phrase2 },
	    { "poslist1", test_poslist1 },
	    { "positfromtermit1", test_positfromtermit1 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (positional&&writable) {
	static const test_desc tests[] = {
	    { "poslist2", test_poslist2 },
	    { "poslist3", test_poslist3 },
	    { "poslistupdate1", test_poslistupdate1 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (remote) {
	static const test_desc tests[] = {
	    { "matchdecider4", test_matchdecider4 },
	    { "closedb6", test_closedb6 },
	    { "keepalive1", test_keepalive1 },
	    { "netstats1", test_netstats1 },
	    { "topercent3", test_topercent3 },
	    { "externalsource2", test_externalsource2 },
	    { "sortfunctorremote1", test_sortfunctorremote1 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (replicas) {
	static const test_desc tests[] = {
	    { "replicate1", test_replicate1 },
	    { "replicate2", test_replicate2 },
	    { "replicate3", test_replicate3 },
	    { "replicate4", test_replicate4 },
	    { "replicate5", test_replicate5 },
	    { "replicate6", test_replicate6 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (spelling) {
	static const test_desc tests[] = {
	    { "spell1", test_spell1 },
	    { "spell2", test_spell2 },
	    { "spell3", test_spell3 },
	    { "spell4", test_spell4 },
	    { "spell5", test_spell5 },
	    { "spell6", test_spell6 },
	    { "spell7", test_spell7 },
	    { "spell8", test_spell8 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (spelling||remote) {
	static const test_desc tests[] = {
	    { "spell0", test_spell0 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (synonyms) {
	static const test_desc tests[] = {
	    { "qpsynonympartial1", test_qpsynonympartial1 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (transactions) {
	static const test_desc tests[] = {
	    { "badtransaction1", test_badtransaction1 },
	    { "committransaction1", test_committransaction1 },
	    { "canceltransaction1", test_canceltransaction1 },
	    { "canceltransaction2", test_canceltransaction2 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (transactions&&!remote) {
	static const test_desc tests[] = {
	    { "closedb5", test_closedb5 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (transactions&&valuestats) {
	static const test_desc tests[] = {
	    { "valuestats2", test_valuestats2 },
	    { "valuestats4", test_valuestats4 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (valuestats) {
	static const test_desc tests[] = {
	    { "valueweightsource2", test_valueweightsource2 },
	    { "valuestats3", test_valuestats3 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (valuestats&&!multi) {
	static const test_desc tests[] = {
	    { "valueweightsource3", test_valueweightsource3 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (writable) {
	static const test_desc tests[] = {
	    { "alldocspl1", test_alldocspl1 },
	    { "alldocspl2", test_alldocspl2 },
	    { "totaldoclen1", test_totaldoclen1 },
	    { "modifiedpostlist1", test_modifiedpostlist1 },
	    { "doclenaftercommit1", test_doclenaftercommit1 },
	    { "valuesaftercommit1", test_valuesaftercommit1 },
	    { "replacedoc8", test_replacedoc8 },
	    { "closedb7", test_closedb7 },
	    { "metadata1", test_metadata1 },
	    { "metadata5", test_metadata5 },
	    { "valuerange2", test_valuerange2 },
	    { "modtermwdf1", test_modtermwdf1 },
	    { "bigoaddvalue1", test_bigoaddvalue1 },
	    { "serialise_document2", test_serialise_document2 },
	    { "decvalwtsource1", test_decvalwtsource1 },
	    { "decvalwtsource2", test_decvalwtsource2 },
	    { "decvalwtsource3", test_decvalwtsource3 },
	    { "decvalwtsource5", test_decvalwtsource5 },
	    { "adddoc1", test_adddoc1 },
	    { "adddoc2", test_adddoc2 },
	    { "adddoc3", test_adddoc3 },
	    { "adddoc4", test_adddoc4 },
	    { "adddoc5", test_adddoc5 },
	    { "adddoc6", test_adddoc6 },
	    { "implicitendsession1", test_implicitendsession1 },
	    { "databaseassign1", test_databaseassign1 },
	    { "deldoc1", test_deldoc1 },
	    { "deldoc2", test_deldoc2 },
	    { "deldoc3", test_deldoc3 },
	    { "deldoc4", test_deldoc4 },
	    { "deldoc5", test_deldoc5 },
	    { "deldoc6", test_deldoc6 },
	    { "replacedoc1", test_replacedoc1 },
	    { "replacedoc2", test_replacedoc2 },
	    { "replacedoc3", test_replacedoc3 },
	    { "replacedoc4", test_replacedoc4 },
	    { "replacedoc5", test_replacedoc5 },
	    { "replacedoc6", test_replacedoc6 },
	    { "uniqueterm1", test_uniqueterm1 },
	    { "allpostlist2", test_allpostlist2 },
	    { "emptyterm2", test_emptyterm2 },
	    { "phraseorneartoand1", test_phraseorneartoand1 },
	    { "longpositionlist1", test_longpositionlist1 },
	    { "consistency2", test_consistency2 },
	    { "nomoredocids1", test_nomoredocids1 },
	    { "termtoolong1", test_termtoolong1 },
	    { "postlist7", test_postlist7 },
	    { "modifyvalues1", test_modifyvalues1 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (writable&&!inmemory) {
	static const test_desc tests[] = {
	    { "qpmemoryleak1", test_qpmemoryleak1 },
	    { "closedb4", test_closedb4 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (writable&&!inmemory&&!remote) {
	static const test_desc tests[] = {
	    { "replacedoc7", test_replacedoc7 },
	    { "databasemodified1", test_databasemodified1 },
	    { "closedb2", test_closedb2 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (writable&&!remote) {
	static const test_desc tests[] = {
	    { "sortfunctor2", test_sortfunctor2 },
	    { "oldsortfunctor2", test_oldsortfunctor2 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (writable&&metadata) {
	static const test_desc tests[] = {
	    { "closedb10", test_closedb10 },
	    { "writeread1", test_writeread1 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (writable&&spelling) {
	static const test_desc tests[] = {
	    { "closedb8", test_closedb8 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (writable&&synonyms) {
	static const test_desc tests[] = {
	    { "closedb9", test_closedb9 },
	    { "synonymitor1", test_synonymitor1 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
    if (writable&&valuestats) {
	static const test_desc tests[] = {
	    { "valuestats1", test_valuestats1 },
	    { "valueweightsource5", test_valueweightsource5 },
	    { 0, 0 }
	};
	result = max(result, test_driver::run(tests));
    }
