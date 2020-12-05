/*
 * Unit Test Bootstrap
 * Autor: Tomasz Jaworski, 2018-2020
 *
 * Test dla zadania Projekt: ścieżki bezwzględne, wielkości liter (4,0)
 * Autor testowanej odpowiedzi: Sebastian Derendarz
 * Test wygenerowano automatycznie o 2020-12-05 14:22:19.177530
 *
 * Debug: 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <signal.h>
#include <setjmp.h>
#include <assert.h>

#if !defined(__clang__) && !defined(__GNUC__)
// Zakomentuj poniższy błąd, jeżeli chcesz przetestować testy na swoim kompilatorze C.
#error System testow jednostkowych jest przeznaczony dla kompilatorów GCC/Clang.
#endif

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
// Zakomentuj poniższy błąd, jeżeli chcesz przetestować testy na platformie Windows.
#error System testow jednostkowych NIE jest przeznaczony dla testów uruchamianych na platformach Windows.
#endif

#define _RLDEBUG_API_
#include "unit_helper_v2.h"
#include "rdebug.h"

#include "tested_declarations.h"
#include "rdebug.h"

//
// Elementy globalne dla całego testu
//




//
//  Test 1: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST1(void)
{
    // informacje o teście
    test_start(1, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file("ENERGY.TXT");
            test_error(disk == NULL, "Funkcja disk_open_from_file() powinna zwrócić NULL przy próbie otwarcia nieistniejącego pliku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 2: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST2(void)
{
    // informacje o teście
    test_start(2, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file(NULL);
            test_error(disk == NULL, "Funkcja disk_open_from_file() powinna zwrócić NULL przy próbie otwarcia nieistniejącego pliku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 3: Sprawdzanie poprawności działania funkcji disk_close
//
void UTEST3(void)
{
    // informacje o teście
    test_start(3, "Sprawdzanie poprawności działania funkcji disk_close", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            disk_close(NULL);
      
            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 4: Sprawdzanie poprawności działania funkcji fat_open
//
void UTEST4(void)
{
    // informacje o teście
    test_start(4, "Sprawdzanie poprawności działania funkcji fat_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file("soon.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume == NULL, "Funkcja fat_open() powinna zwrócić NULL w przypadku przekazania błędnego obrazu dysku");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 5: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST5(void)
{
    // informacje o teście
    test_start(5, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct volume_t* volume = fat_open(NULL, 0);
            test_error(volume == NULL, "Funkcja fat_open() powinna zwrócić NULL w przypadku przekazania błędnego obrazu dysku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 6: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST6(void)
{
    // informacje o teście
    test_start(6, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(5344, 1);
                char expected_filecontent[5345] = "";
        
                strcat(expected_filecontent, " he chooses!\"  I to him in few:\n\"Bard!  by that God, whom thou didst not adore,\nI do beseech thee (that this ill and worse\nI may escape) to lead me, where thou saidst,\nThat I Saint Peter\'s gate may view, and those\nWho as thou tell\'st, are in such dismal plight.\"\n     Onward he mov\'d, I close his steps pursu\'d.\n\n\n\nCANTO II\n\nNOW was the day departing, and the air,\nImbrown\'d with shadows, from their toils releas\'d\nAll animals on earth; and I alone\nPrepar\'d myself the conflict to sustain,\nBoth of sad pity, and that perilous road,\nWhich my unerring memory shall retrace.\n     O Muses!  O high genius!  now vouchsafe\nYour aid!  O mind!  that all I saw hast kept\nSafe in a written record, here thy worth\nAnd eminent endowments come to proof.\n     I thus began:  \"Bard!  thou who art my guide,\nConsider well, if virtue be in me\nSufficient, ere to this high enterprise\nThou trust me.  Thou hast told that Silvius\' sire,\nYet cloth\'d in corruptible flesh, among\nTh\' immortal tribes had entrance, and was there\nSensible present.  Yet if heaven\'s great Lord,\nAlmighty foe to ill, such favour shew\'d,\nIn contemplation of the high effect,\nBoth what and who from him should issue forth,\nIt seems in reason\'s judgment well deserv\'d:\nSith he of Rome, and of Rome\'s empire wide,\nIn heaven\'s empyreal height was chosen sire:\nBoth which, if truth be spoken, were ordain\'d\nAnd \'stablish\'d for the holy place, where sits\nWho to great Peter\'s sacred chair succeeds.\nHe from this journey, in thy song renown\'d,\nLearn\'d things, that to his victory gave rise\nAnd to the papal robe.  In after-times\nThe chosen vessel also travel\'d there,\nTo bring us back assurance in that faith,\nWhich is the entrance to salvation\'s way.\nBut I, why should I there presume?  or who\nPermits it?  not, Aeneas I nor Paul.\nMyself I deem not worthy, and none else\nWill deem me.  I, if on this voyage then\nI venture, fear it will in folly end.\nThou, who art wise, better my meaning know\'st,\nThan I can speak.\"  As one, who unresolves\nWhat he hath late resolv\'d, and with new thoughts\nChanges his purpose, from his first intent\nRemov\'d; e\'en such was I on that dun coast,\nWasting in thought my enterprise, at first\nSo eagerly embrac\'d.  \"If right thy words\nI scan,\" replied that shade magnanimous,\n\"Thy soul is by vile fear assail\'d, which oft\nSo overcasts a man, that he recoils\nFrom noblest resolution, like a beast\nAt some false semblance in the twilight gloom.\nThat from this terror thou mayst free thyself,\nI will instruct thee why I came, and what\nI heard in that same instant, when for thee\nGrief touch\'d me first.  I was among the tribe,\nWho rest suspended, when a dame, so blest\nAnd lovely, I besought her to command,\nCall\'d me; her eyes were brighter than the star\nOf day; and she with gentle voice and soft\nAngelically tun\'d her speech address\'d:\n\"O courteous shade of Mantua!  thou whose fame\nYet lives, and shall live long as nature lasts!\nA friend, not of my fortune but myself,\nOn the wide desert in his road has met\nHindrance so great, that he through fear has turn\'d.\nNow much I dread lest he past help have stray\'d,\nAnd I be ris\'n too late for his relief,\nFrom what in heaven of him I heard.  Speed now,\nAnd by thy eloquent persuasive tongue,\nAnd by all means for his deliverance meet,\nAssist him.  So to me will comfort spring.\nI who now bid thee on this errand forth\nAm Beatrice; from a place I come\n\n(Note:  Beatrice.  I use this word, as it is\npronounced in the Italian, as consisting of four\nsyllables, of which the third is a long one.)\n\nRevisited with joy.  Love brought me thence,\nWho prompts my speech.  When in my Master\'s sight\nI stand, thy praise to him I oft will tell.\"\n     She then was silent, and I thus began:\n\"O Lady!  by whose influence alone,\nMankind excels whatever is contain\'d\nWithin that heaven which hath the smallest orb,\nSo thy command delights me, that to obey,\nIf it were done already, would seem late.\nNo need hast thou farther to speak thy will;\nYet tell the reason, why thou art not loth\nTo leave that ample space, where to return\nThou burnest, for this centre here beneath.\"\n     She then:");
    strcat(expected_filecontent, "  \"Since thou so deeply wouldst inquire,\nI will instruct thee briefly, why no dread\nHinders my entrance here.  Those things alone\nAre to be fear\'d, whence evil may proceed,\nNone else, for none are terrible beside.\nI am so fram\'d by God, thanks to his grace!\nThat any suff\'rance of your misery\nTouches me not, nor flame of that fierce fire\nAssails me.  In high heaven a blessed dame\nBesides, who mourns with such effectual grief\nThat hindrance, which I send thee to remove,\nThat God\'s stern judgment to her will inclines.\nTo Lucia calling, her she thus bespake:\n\"Now doth thy faithful servant need thy aid\nAnd I commend him to thee.\"  At her word\nSped Lucia, of all cruelty the foe,\nAnd coming to the place, where I abode\nSeated with Rachel, her of ancient days,\nShe thus address\'d me: \"Thou true praise of God!\nBeatrice!  why is not thy succour lent\nTo him, who so much lov\'d thee, as to leave\nFor thy sake all the multitude admires?\nDost thou not hear how pitiful his wail,\nNor mark the death, which in the torrent flood,\nSwoln mightier than a sea, him struggling holds?\"\nNe\'er among men did any with such speed\nHaste to their profit, flee from their annoy,\nAs when these words were spoken, I came here,\nDown from my blessed seat, trusting the forc");
                
        
                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "HaD.bIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 5344, file);
                test_error(size == 5344, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 5344 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 5344);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 5344);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 7: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST7(void)
{
    // informacje o teście
    test_start(7, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(727, 1);
                char expected_filecontent[728] = "";
        
                strcat(expected_filecontent, "ness he has transmitted to posterity. He  died in 1336, at\nthe age of 60.\n\nv. 96.  One Guido from the other.]  Guido Cavalcanti, the friend\nof our Poet, (see Hell, Canto X. 59.) had eclipsed the literary\nfame of Guido Guinicelli, of a noble family in Bologna, whom we\nshall meet with in the twenty-sixth Canto and of whom frequent\nmention is made by our Poet in his Treatise de Vulg. Eloq.\nGuinicelli died in 1276.  Many of Cavalcanti\'s writings, hitherto\nin MS. are now publishing at Florence\" Esprit des Journaux, Jan.\n1813.\n\nv. 97.  He perhaps is born.]  Some imagine, with much\nprobability, that Dante here augurs the greatness of his own\npoetical reputation.  Others have fancied that he prophesies the\nglory of Petrarch. ");
                
        
                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "OWN.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 727, file);
                test_error(size == 727, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 727 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 727);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 727);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 8: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST8(void)
{
    // informacje o teście
    test_start(8, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(6211, 1);
                char expected_filecontent[6212] = "";
        
                strcat(expected_filecontent, "father, or bishop,\nin whose presence he made a profession of poverty.\n\nv. 60.  Her first husband.]  Christ.\n\nv. 63.  Amyclas.]  Lucan makes Caesar exclaim, on witnessing the\nsecure poverty of the fisherman Amyclas:\n\n--O vite tuta facultas\nPauperis, angustique lares!  O munera nondum\nIntellecta deum!  quibus hoc contingere templis,\nAut potuit muris, nullo trepidare tumultu,\nCaesarea pulsante manu?\nLucan Phars. 1. v. 531.\n\nv. 72.  Bernard.]  One of the first followers of the saint.\n\nv. 76.  Egidius.]  The third of his disciples, who died in 1262.\nHis work, entitled Verba Aurea, was published in 1534, at Antwerp\nSee Lucas Waddingus, Annales Ordinis Minoris, p. 5.\n\nv. 76.  Sylvester.]  Another of his earliest associates.\n\nv. 83.  Pietro Bernardone.]  A man in an humble station of life\nat Assisi.\n\nv. 86.  Innocent.]  Pope Innocent III.\n\nv. 90.  Honorius.]  His successor Honorius III who granted\ncertain privileges to the Franciscans.\n\nv. 93.  On the hard rock.]  The mountain Alverna in the Apennine.\n\nv. 100.  The last signet.]  Alluding to the stigmata, or marks\nresembling the wounds of Christ, said to have been found on the\nsaint\'s body.\n\nv. 106.  His dearest lady.]  Poverty.\n\nv. 113.  Our Patriarch ]  Saint Dominic.\n\nv. 316.  His flock ] The Dominicans.\n\nv. 127.  The planet from whence they split.]  \"The rule of their\norder, which the Dominicans neglect to observe.\"\n\nCANTO XII\n\nv. 1.  The blessed flame.]  Thomas Aquinas\n\nv. 12.  That voice.]  The nymph Echo, transformed into the\nrepercussion of the voice.\n\nv. 25.  One.]  Saint Buonaventura, general of the Franciscan\norder, in which he effected some reformation, and one of the most\nprofound divines of his age.  \"He refused the archbishopric of\nYork, which was offered him by Clement IV, but afterwards was\nprevailed on to accept the bishopric of Albano and a cardinal\'s\nhat.  He was born at Bagnoregio or Bagnorea, in Tuscany, A.D.\n1221, and died in 1274.\"  Dict. Histor. par Chaudon et Delandine.\nEd.  Lyon.  1804.\n\nv. 28.  The love.]  By an act of mutual courtesy, Buonaventura,\na Franciscan, is made to proclaim the praises of St. Dominic,\nas Thomas Aquinas, a Dominican, has celebrated those of St.\nFrancis.\n\nv. 42.  In that clime.]  Spain.\n\nv. 48.  Callaroga.]  Between Osma and Aranda, in Old Castile,\ndesignated by the royal coat of arms.\n\nv. 51.  The loving minion of the Christian faith.]  Dominic was\nborn April 5, 1170, and died August 6, 1221.  His birthplace,\nCallaroga; his father and mother\'s names, Felix and Joanna, his\nmother\'s dream; his name of Dominic, given him in consequence of\na vision by a noble matron, who stood sponsor to him, are all\ntold in an anonymous life of the saint, said to be written in the\nthirteenth century, and published by Quetif and Echard,\nScriptores Ordinis Praedicatorum.  Par.  1719. fol. t 1.  p. 25.\nThese writers deny his having been an inquisitor, and indeed the\nestablishment of the inquisition itself before the fourth Lateran\ncouncil.  Ibid.  p. 88.\n\nv. 55.  In the mother\'s womb.]  His mother, when pregnant with\nhim, is said to have dreamt that she should bring forth a white\nand black dog, with a lighted torch in its mouth.\n\nv. 59.  The dame.]  His godmother\'s dream was, that he had one\nstar in his forehead, and another in the nape of his neck, from\nwhich he communicated light to the east and the west.\n\nv. 73.  Felix.]  Felix Gusman.\n\nv. 75.  As men interpret it.]  Grace or gift of the Lord.\n\nv. 77.  Ostiense.]  A cardinal, who explained the decretals.\n\nv. 77.  Taddeo.]  A physician, of Florence.\n\nv. 82.  The see.]  \"The apostolic see, which no longer continues\nits wonted liberality towards the indigent and deserving; not\nindeed  through its own fault, as its doctrines are still the\nsame, but through the fault of the pontiff, who is seated in it.\"\n\nv. 85.  No dispensation.]  Dominic did not ask license to\ncompound for the use of unjust acquisitions, by dedicating a part\nof them to pious purposes.\n\nv. 89.  In favour of that seed.]  \"For that seed of the divine\nword, from which have sprung up these four-and-twenty plants,\nthat now environ thee.\"");
    strcat(expected_filecontent, "\n\nv. 101.  But the track.]  \"But the rule of St. Francis is already\ndeserted and the lees of the wine are turned into mouldiness.\"\n\nv. 110.  Tares.]  He adverts to the parable of the taxes and the\nwheat.\n\nv. 111.  I question not.]  \"Some indeed might be found, who still\nobserve the rule of the order, but such would come neither from\nCasale nor Acquasparta:\" of the former of which places was\nUberto, one master general, by whom the discipline had been\nrelaxed; and of the latter, Matteo, another, who had enforced it\nwith unnecessary rigour.\n\nv. 121.  -Illuminato here,\nAnd Agostino.]\nTwo among the earliest followers of St. Francis.\n\nv. 125.  Hugues of St. Victor.]  A Saxon of the monastery of\nSaint  Victor at Paris, who fed ill 1142 at the age of\nforty-four.  \"A man distinguished by the fecundity of his genius,\nwho treated in his writings of all the branches of sacred and\nprofane erudition that were known in his time, and who composed\nseveral dissertations that are not destitute of merit.\"\nMaclaine\'s Mosheim, Eccl. Hist. v. iii . cent. xii. p. 2. 2. 23.\nI have looked into his writings, and found some reason for\nthis high eulogium.\n\nv. 125.  Piatro Mangiadore.]  \"Petrus Comestor, or the Eater,\nborn at Troyes, was canon and dean of that church, and afterwards\nchancellor of the church of Paris.  He relinquished these\nbenefices to become a regular canon of St. Victor at Paris, where\nhe died in 1198.  Chaudon et Delandine Dict. Hist. Ed. Lyon.\n1804. The work by which he is best known, is his Historia\nScolastica, which I shall have occasion to cite in the Notes to\nCanto XXVI.\n\nv. 126.  He of Spain.]  \"To Pope Adrian V succeeded John XXI a\nnative of Lisbon a man of great genius and extraordinary\nacquirements, especially in logic and in medicine, as his books,\nwritten in the name of Peter of Spain (by which he was known\nbefore he became Pope), may testify.  His life was not much\nlonger than that of his predecessors, for he was killed at\nViterbo, by the falling in of the roof of his chamber, after he\nhad been pontiff only eight months and as many days.\nA.D. 1277.  Mariana, Hist. de Esp. l. xi");
                
        
                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "bONE.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 6211, file);
                test_error(size == 6211, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6211 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6211);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 6211);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 9: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST9(void)
{
    // informacje o teście
    test_start(9, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(6144, 1);
                char expected_filecontent[6145] = "";
        
                strcat(expected_filecontent, "pric of Albano and a cardinal\'s\nhat.  He was born at Bagnoregio or Bagnorea, in Tuscany, A.D.\n1221, and died in 1274.\"  Dict. Histor. par Chaudon et Delandine.\nEd.  Lyon.  1804.\n\nv. 28.  The love.]  By an act of mutual courtesy, Buonaventura,\na Franciscan, is made to proclaim the praises of St. Dominic,\nas Thomas Aquinas, a Dominican, has celebrated those of St.\nFrancis.\n\nv. 42.  In that clime.]  Spain.\n\nv. 48.  Callaroga.]  Between Osma and Aranda, in Old Castile,\ndesignated by the royal coat of arms.\n\nv. 51.  The loving minion of the Christian faith.]  Dominic was\nborn April 5, 1170, and died August 6, 1221.  His birthplace,\nCallaroga; his father and mother\'s names, Felix and Joanna, his\nmother\'s dream; his name of Dominic, given him in consequence of\na vision by a noble matron, who stood sponsor to him, are all\ntold in an anonymous life of the saint, said to be written in the\nthirteenth century, and published by Quetif and Echard,\nScriptores Ordinis Praedicatorum.  Par.  1719. fol. t 1.  p. 25.\nThese writers deny his having been an inquisitor, and indeed the\nestablishment of the inquisition itself before the fourth Lateran\ncouncil.  Ibid.  p. 88.\n\nv. 55.  In the mother\'s womb.]  His mother, when pregnant with\nhim, is said to have dreamt that she should bring forth a white\nand black dog, with a lighted torch in its mouth.\n\nv. 59.  The dame.]  His godmother\'s dream was, that he had one\nstar in his forehead, and another in the nape of his neck, from\nwhich he communicated light to the east and the west.\n\nv. 73.  Felix.]  Felix Gusman.\n\nv. 75.  As men interpret it.]  Grace or gift of the Lord.\n\nv. 77.  Ostiense.]  A cardinal, who explained the decretals.\n\nv. 77.  Taddeo.]  A physician, of Florence.\n\nv. 82.  The see.]  \"The apostolic see, which no longer continues\nits wonted liberality towards the indigent and deserving; not\nindeed  through its own fault, as its doctrines are still the\nsame, but through the fault of the pontiff, who is seated in it.\"\n\nv. 85.  No dispensation.]  Dominic did not ask license to\ncompound for the use of unjust acquisitions, by dedicating a part\nof them to pious purposes.\n\nv. 89.  In favour of that seed.]  \"For that seed of the divine\nword, from which have sprung up these four-and-twenty plants,\nthat now environ thee.\"\n\nv. 101.  But the track.]  \"But the rule of St. Francis is already\ndeserted and the lees of the wine are turned into mouldiness.\"\n\nv. 110.  Tares.]  He adverts to the parable of the taxes and the\nwheat.\n\nv. 111.  I question not.]  \"Some indeed might be found, who still\nobserve the rule of the order, but such would come neither from\nCasale nor Acquasparta:\" of the former of which places was\nUberto, one master general, by whom the discipline had been\nrelaxed; and of the latter, Matteo, another, who had enforced it\nwith unnecessary rigour.\n\nv. 121.  -Illuminato here,\nAnd Agostino.]\nTwo among the earliest followers of St. Francis.\n\nv. 125.  Hugues of St. Victor.]  A Saxon of the monastery of\nSaint  Victor at Paris, who fed ill 1142 at the age of\nforty-four.  \"A man distinguished by the fecundity of his genius,\nwho treated in his writings of all the branches of sacred and\nprofane erudition that were known in his time, and who composed\nseveral dissertations that are not destitute of merit.\"\nMaclaine\'s Mosheim, Eccl. Hist. v. iii . cent. xii. p. 2. 2. 23.\nI have looked into his writings, and found some reason for\nthis high eulogium.\n\nv. 125.  Piatro Mangiadore.]  \"Petrus Comestor, or the Eater,\nborn at Troyes, was canon and dean of that church, and afterwards\nchancellor of the church of Paris.  He relinquished these\nbenefices to become a regular canon of St. Victor at Paris, where\nhe died in 1198.  Chaudon et Delandine Dict. Hist. Ed. Lyon.\n1804. The work by which he is best known, is his Historia\nScolastica, which I shall have occasion to cite in the Notes to\nCanto XXVI.\n\nv. 126.  He of Spain.]  \"To Pope Adrian V succeeded John XXI a\nnative of Lisbon a man of great genius and extraordinary\nacquirements, especially in logic and in medicine, as his books,\nwritten in the name of Peter of S");
    strcat(expected_filecontent, "pain (by which he was known\nbefore he became Pope), may testify.  His life was not much\nlonger than that of his predecessors, for he was killed at\nViterbo, by the falling in of the roof of his chamber, after he\nhad been pontiff only eight months and as many days.\nA.D. 1277.  Mariana, Hist. de Esp. l. xiv.  c. 2.\n\nv. 128.  Chrysostom.]  The eloquent patriarch of Constantinople.\n\nv. 128.  Anselmo.]  \"Anselm, Archbishop of Canterbury, was born\nat Aosta, about 1034, and studied under Lanfrane at the monastery\nof Bec, in Normandy, where he afterwards devoted himself to a\nreligious life, in his twenty-seventh year.  In three years he\nwas made prior, and then abbot of that monastery!  from whence he\nwas taken, in 1093, to succeed to the archbishopric, vacant by\nthe death of Lanfrane. He enjoyed this dignity till his death, in\n1109, though it was disturbed by many\ndissentions with William II and Henry I respecting the immunities\nand investitures.  There is much depth and precisian in his\ntheological  works.\" Tiraboschi, Stor.  della Lett. Ital. t. iii.\n\n1. iv. c. 2. Ibid.  c. v.  \"It is an observation made by many\nmodern writers, that the demonstration of the existence of God,\ntaken from the idea of a Supreme Being, of which Des Cartes is\nthought to be the author, was so many ages back discovered and\nbrought to light by Anselm.  Leibnitz himself makes\nthe remark, vol. v. Oper.  p. 570.  Edit.  Genev. 1768.\"\n\nv. 129.  Donatus.]  Aelius Donatus, the grammarian, in the fourth\ncentury, one of the preceptors of St. Jerome.\n\nv. 130.  Raban.]  \"Rabanus Maurus, Archbishop of Mentz, is\ndeservedly placed at the head of the Latin writers of this age.\"\nMosheim, v. ii. cent. ix. p.  2 c. 2.  14.\n\nv. 131.  Joachim.]  Abbot of Flora in Calabria; \"whom the\nmultitude revered as a person divinely inspired and equal to the\nmost illustrious prophets of ancient times.\"  Ibid.  v. iii.\ncent. xiii. p. 2. c. 2. 33.\n\nv. 134.  A peer.]  St. Dominic.\n\nCANTO XIII\n\nv. 1.  Let him.]  \"Whoever would conceive the sight that now\npresented itself to me, m");
                
        
                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "SUN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 6144, file);
                test_error(size == 6144, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6144 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6144);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 6144);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 10: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST10(void)
{
    // informacje o teście
    test_start(10, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(5130, 1);
                char expected_filecontent[5131] = "";
        
                strcat(expected_filecontent, " now I. now L. figur\'d I\' th\' air.\nFirst, singing, to their notes they mov\'d, then one\nBecoming of these signs, a little while\nDid rest them, and were mute.  O nymph divine\nOf Pegasean race!  whose souls, which thou\nInspir\'st, mak\'st glorious and long-liv\'d, as they\nCities and realms by thee!  thou with thyself\nInform me; that I may set forth the shapes,\nAs fancy doth present them.  Be thy power\nDisplay\'d in this brief song.  The characters,\nVocal and consonant, were five-fold seven.\nIn order each, as they appear\'d, I mark\'d.\nDiligite Justitiam, the first,\nBoth verb and noun all blazon\'d; and the extreme\nQui judicatis terram.  In the M.\nOf the fifth word they held their station,\nMaking the star seem silver streak\'d with gold.\nAnd on the summit of the M. I saw\nDescending other lights, that rested there,\nSinging, methinks, their bliss and primal good.\nThen, as at shaking of a lighted brand,\nSparkles innumerable on all sides\nRise scatter\'d, source of augury to th\' unwise;\nThus more than thousand twinkling lustres hence\nSeem\'d reascending, and a higher pitch\nSome mounting, and some less; e\'en as the sun,\nWhich kindleth them, decreed.  And when each one\nHad settled in his place, the head and neck\nThen saw I of an eagle, lively\nGrav\'d in that streaky fire.  Who painteth there,\nHath none to guide him; of himself he guides;\nAnd every line and texture of the nest\nDoth own from him the virtue, fashions it.\nThe other bright beatitude, that seem\'d\nErewhile, with lilied crowning, well content\nTo over-canopy the M. mov\'d forth,\nFollowing gently the impress of the bird.\n      Sweet star!  what glorious and thick-studded gems\nDeclar\'d to me our justice on the earth\nTo be the effluence of that heav\'n, which thou,\nThyself a costly jewel, dost inlay!\nTherefore I pray the Sovran Mind, from whom\nThy motion and thy virtue are begun,\nThat he would look from whence the fog doth rise,\nTo vitiate thy beam: so that once more\nHe may put forth his hand \'gainst such, as drive\nTheir traffic in that sanctuary, whose walls\nWith miracles and martyrdoms were built.\n     Ye host of heaven!  whose glory I survey l\nO beg ye grace for those, that are on earth\nAll after ill example gone astray.\nWar once had for its instrument the sword:\nBut now \'t is made, taking the bread away\nWhich the good Father locks from none.  --And thou,\nThat writes but to cancel, think, that they,\nWho for the vineyard, which thou wastest, died,\nPeter and Paul live yet, and mark thy doings.\nThou hast good cause to cry, \"My heart so cleaves\nTo him, that liv\'d in solitude remote,\nAnd from the wilds was dragg\'d to martyrdom,\nI wist not of the fisherman nor Paul.\"\n\n\n\nCANTO XIX\n\nBefore my sight appear\'d, with open wings,\nThe beauteous image, in fruition sweet\nGladdening the thronged spirits.  Each did seem\nA little ruby, whereon so intense\nThe sun-beam glow\'d that to mine eyes it came\nIn clear refraction.  And that, which next\nBefalls me to portray, voice hath not utter\'d,\nNor hath ink written, nor in fantasy\nWas e\'er conceiv\'d.  For I beheld and heard\nThe beak discourse; and, what intention form\'d\nOf many, singly as of one express,\nBeginning:  \"For that I was just and piteous,\nl am exalted to this height of glory,\nThe which no wish exceeds: and there on earth\nHave I my memory left, e\'en by the bad\nCommended, while they leave its course untrod.\"\n     Thus is one heat from many embers felt,\nAs in that image many were the loves,\nAnd one the voice, that issued from them all.\nWhence I address them:  \"O perennial flowers\nOf gladness everlasting!  that exhale\nIn single breath your odours manifold!\nBreathe now; and let the hunger be appeas\'d,\nThat with great craving long hath held my soul,\nFinding no food on earth.  This well I know,\nThat if there be in heav\'n a realm, that shows\nIn faithful mirror the celestial Justice,\nYours without veil reflects it.  Ye discern\nThe heed, wherewith I do prepare myself\nTo hearken; ye the doubt that urges me\nWith such inveterate craving.\"  Straight I saw,\nLike to a falcon issuing from the hood,\nThat rears his head, and claps him with his wings,\nHis beauty and his");
    strcat(expected_filecontent, " eagerness bewraying.\nSo saw I move that stately sign, with praise\nOf grace divine inwoven and high song\nOf inexpressive joy.  \"He,\" it began,\n\"Who turn\'d his compass on the world\'s extreme,\nAnd in that space so variously hath wrought,\nBoth openly, and in secret, in such wise\nCould not through all the universe display\nImpression of his glory, that the Word\nOf his omniscience should not still remain\nIn infinite excess.  In proof whereof,\nHe first through pride supplanted, who was sum\nOf each created being, waited not\nFor light celestial, and abortive fell.\nWhence needs each lesser nature is but scant\nReceptacle unto that Good, which knows\nNo limit, measur\'d by itself alone.\nTherefore your sight, of th\' omnipresent Mind\nA single beam, its origin must own\nSurpassing far its utmost potency.\nThe ken, your world is gifted with, descends\nIn th\' everlasting Justice as low down,\nAs eye doth in the sea; which though it mark\nThe bottom from the shore, in the wide main\nDiscerns it not; and ne\'ertheless it is,\nBut hidden through its");
                
        
                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "cOsT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 5130, file);
                test_error(size == 5130, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 5130 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 5130);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 5130);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 11: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST11(void)
{
    // informacje o teście
    test_start(11, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(537, 1);
                char expected_filecontent[538] = "";
        
                strcat(expected_filecontent, "disposes me not less\nFor weeping, when I see It thus transform\'d.\nSay then, by Heav\'n, what blasts ye thus?  The whilst\nI wonder, ask not Speech from me:  unapt\nIs he to speak, whom other will employs.\n     He thus:  \"The water and tee plant we pass\'d,\nVirtue possesses, by th\' eternal will\nInfus\'d, the which so pines me.  Every spirit,\nWhose song bewails his gluttony indulg\'d\nToo grossly, here in hunger and in thirst\nIs purified.  The odour, which the fruit,\nAnd spray, that showers upon the verdure, breathe,\nInflames us with desire");
                
        
                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "WArHAnDT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 537, file);
                test_error(size == 537, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 537 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 537);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 537);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 12: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST12(void)
{
    // informacje o teście
    test_start(12, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(5344, 1);
                char expected_filecontent[5345] = "";

                strcat(expected_filecontent, " he chooses!\"  I to him in few:\n\"Bard!  by that God, whom thou didst not adore,\nI do beseech thee (that this ill and worse\nI may escape) to lead me, where thou saidst,\nThat I Saint Peter\'s gate may view, and those\nWho as thou tell\'st, are in such dismal plight.\"\n     Onward he mov\'d, I close his steps pursu\'d.\n\n\n\nCANTO II\n\nNOW was the day departing, and the air,\nImbrown\'d with shadows, from their toils releas\'d\nAll animals on earth; and I alone\nPrepar\'d myself the conflict to sustain,\nBoth of sad pity, and that perilous road,\nWhich my unerring memory shall retrace.\n     O Muses!  O high genius!  now vouchsafe\nYour aid!  O mind!  that all I saw hast kept\nSafe in a written record, here thy worth\nAnd eminent endowments come to proof.\n     I thus began:  \"Bard!  thou who art my guide,\nConsider well, if virtue be in me\nSufficient, ere to this high enterprise\nThou trust me.  Thou hast told that Silvius\' sire,\nYet cloth\'d in corruptible flesh, among\nTh\' immortal tribes had entrance, and was there\nSensible present.  Yet if heaven\'s great Lord,\nAlmighty foe to ill, such favour shew\'d,\nIn contemplation of the high effect,\nBoth what and who from him should issue forth,\nIt seems in reason\'s judgment well deserv\'d:\nSith he of Rome, and of Rome\'s empire wide,\nIn heaven\'s empyreal height was chosen sire:\nBoth which, if truth be spoken, were ordain\'d\nAnd \'stablish\'d for the holy place, where sits\nWho to great Peter\'s sacred chair succeeds.\nHe from this journey, in thy song renown\'d,\nLearn\'d things, that to his victory gave rise\nAnd to the papal robe.  In after-times\nThe chosen vessel also travel\'d there,\nTo bring us back assurance in that faith,\nWhich is the entrance to salvation\'s way.\nBut I, why should I there presume?  or who\nPermits it?  not, Aeneas I nor Paul.\nMyself I deem not worthy, and none else\nWill deem me.  I, if on this voyage then\nI venture, fear it will in folly end.\nThou, who art wise, better my meaning know\'st,\nThan I can speak.\"  As one, who unresolves\nWhat he hath late resolv\'d, and with new thoughts\nChanges his purpose, from his first intent\nRemov\'d; e\'en such was I on that dun coast,\nWasting in thought my enterprise, at first\nSo eagerly embrac\'d.  \"If right thy words\nI scan,\" replied that shade magnanimous,\n\"Thy soul is by vile fear assail\'d, which oft\nSo overcasts a man, that he recoils\nFrom noblest resolution, like a beast\nAt some false semblance in the twilight gloom.\nThat from this terror thou mayst free thyself,\nI will instruct thee why I came, and what\nI heard in that same instant, when for thee\nGrief touch\'d me first.  I was among the tribe,\nWho rest suspended, when a dame, so blest\nAnd lovely, I besought her to command,\nCall\'d me; her eyes were brighter than the star\nOf day; and she with gentle voice and soft\nAngelically tun\'d her speech address\'d:\n\"O courteous shade of Mantua!  thou whose fame\nYet lives, and shall live long as nature lasts!\nA friend, not of my fortune but myself,\nOn the wide desert in his road has met\nHindrance so great, that he through fear has turn\'d.\nNow much I dread lest he past help have stray\'d,\nAnd I be ris\'n too late for his relief,\nFrom what in heaven of him I heard.  Speed now,\nAnd by thy eloquent persuasive tongue,\nAnd by all means for his deliverance meet,\nAssist him.  So to me will comfort spring.\nI who now bid thee on this errand forth\nAm Beatrice; from a place I come\n\n(Note:  Beatrice.  I use this word, as it is\npronounced in the Italian, as consisting of four\nsyllables, of which the third is a long one.)\n\nRevisited with joy.  Love brought me thence,\nWho prompts my speech.  When in my Master\'s sight\nI stand, thy praise to him I oft will tell.\"\n     She then was silent, and I thus began:\n\"O Lady!  by whose influence alone,\nMankind excels whatever is contain\'d\nWithin that heaven which hath the smallest orb,\nSo thy command delights me, that to obey,\nIf it were done already, would seem late.\nNo need hast thou farther to speak thy will;\nYet tell the reason, why thou art not loth\nTo leave that ample space, where to return\nThou burnest, for this centre here beneath.\"\n     She then:");
    strcat(expected_filecontent, "  \"Since thou so deeply wouldst inquire,\nI will instruct thee briefly, why no dread\nHinders my entrance here.  Those things alone\nAre to be fear\'d, whence evil may proceed,\nNone else, for none are terrible beside.\nI am so fram\'d by God, thanks to his grace!\nThat any suff\'rance of your misery\nTouches me not, nor flame of that fierce fire\nAssails me.  In high heaven a blessed dame\nBesides, who mourns with such effectual grief\nThat hindrance, which I send thee to remove,\nThat God\'s stern judgment to her will inclines.\nTo Lucia calling, her she thus bespake:\n\"Now doth thy faithful servant need thy aid\nAnd I commend him to thee.\"  At her word\nSped Lucia, of all cruelty the foe,\nAnd coming to the place, where I abode\nSeated with Rachel, her of ancient days,\nShe thus address\'d me: \"Thou true praise of God!\nBeatrice!  why is not thy succour lent\nTo him, who so much lov\'d thee, as to leave\nFor thy sake all the multitude admires?\nDost thou not hear how pitiful his wail,\nNor mark the death, which in the torrent flood,\nSwoln mightier than a sea, him struggling holds?\"\nNe\'er among men did any with such speed\nHaste to their profit, flee from their annoy,\nAs when these words were spoken, I came here,\nDown from my blessed seat, trusting the forc");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "HAD.bIn");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 5827, file);
                test_error(size == 5344, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 5344 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 5344);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 5344);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 13: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST13(void)
{
    // informacje o teście
    test_start(13, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(727, 1);
                char expected_filecontent[728] = "";

                strcat(expected_filecontent, "ness he has transmitted to posterity. He  died in 1336, at\nthe age of 60.\n\nv. 96.  One Guido from the other.]  Guido Cavalcanti, the friend\nof our Poet, (see Hell, Canto X. 59.) had eclipsed the literary\nfame of Guido Guinicelli, of a noble family in Bologna, whom we\nshall meet with in the twenty-sixth Canto and of whom frequent\nmention is made by our Poet in his Treatise de Vulg. Eloq.\nGuinicelli died in 1276.  Many of Cavalcanti\'s writings, hitherto\nin MS. are now publishing at Florence\" Esprit des Journaux, Jan.\n1813.\n\nv. 97.  He perhaps is born.]  Some imagine, with much\nprobability, that Dante here augurs the greatness of his own\npoetical reputation.  Others have fancied that he prophesies the\nglory of Petrarch. ");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "OwN.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 1015, file);
                test_error(size == 727, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 727 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 727);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 727);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 14: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST14(void)
{
    // informacje o teście
    test_start(14, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(6211, 1);
                char expected_filecontent[6212] = "";

                strcat(expected_filecontent, "father, or bishop,\nin whose presence he made a profession of poverty.\n\nv. 60.  Her first husband.]  Christ.\n\nv. 63.  Amyclas.]  Lucan makes Caesar exclaim, on witnessing the\nsecure poverty of the fisherman Amyclas:\n\n--O vite tuta facultas\nPauperis, angustique lares!  O munera nondum\nIntellecta deum!  quibus hoc contingere templis,\nAut potuit muris, nullo trepidare tumultu,\nCaesarea pulsante manu?\nLucan Phars. 1. v. 531.\n\nv. 72.  Bernard.]  One of the first followers of the saint.\n\nv. 76.  Egidius.]  The third of his disciples, who died in 1262.\nHis work, entitled Verba Aurea, was published in 1534, at Antwerp\nSee Lucas Waddingus, Annales Ordinis Minoris, p. 5.\n\nv. 76.  Sylvester.]  Another of his earliest associates.\n\nv. 83.  Pietro Bernardone.]  A man in an humble station of life\nat Assisi.\n\nv. 86.  Innocent.]  Pope Innocent III.\n\nv. 90.  Honorius.]  His successor Honorius III who granted\ncertain privileges to the Franciscans.\n\nv. 93.  On the hard rock.]  The mountain Alverna in the Apennine.\n\nv. 100.  The last signet.]  Alluding to the stigmata, or marks\nresembling the wounds of Christ, said to have been found on the\nsaint\'s body.\n\nv. 106.  His dearest lady.]  Poverty.\n\nv. 113.  Our Patriarch ]  Saint Dominic.\n\nv. 316.  His flock ] The Dominicans.\n\nv. 127.  The planet from whence they split.]  \"The rule of their\norder, which the Dominicans neglect to observe.\"\n\nCANTO XII\n\nv. 1.  The blessed flame.]  Thomas Aquinas\n\nv. 12.  That voice.]  The nymph Echo, transformed into the\nrepercussion of the voice.\n\nv. 25.  One.]  Saint Buonaventura, general of the Franciscan\norder, in which he effected some reformation, and one of the most\nprofound divines of his age.  \"He refused the archbishopric of\nYork, which was offered him by Clement IV, but afterwards was\nprevailed on to accept the bishopric of Albano and a cardinal\'s\nhat.  He was born at Bagnoregio or Bagnorea, in Tuscany, A.D.\n1221, and died in 1274.\"  Dict. Histor. par Chaudon et Delandine.\nEd.  Lyon.  1804.\n\nv. 28.  The love.]  By an act of mutual courtesy, Buonaventura,\na Franciscan, is made to proclaim the praises of St. Dominic,\nas Thomas Aquinas, a Dominican, has celebrated those of St.\nFrancis.\n\nv. 42.  In that clime.]  Spain.\n\nv. 48.  Callaroga.]  Between Osma and Aranda, in Old Castile,\ndesignated by the royal coat of arms.\n\nv. 51.  The loving minion of the Christian faith.]  Dominic was\nborn April 5, 1170, and died August 6, 1221.  His birthplace,\nCallaroga; his father and mother\'s names, Felix and Joanna, his\nmother\'s dream; his name of Dominic, given him in consequence of\na vision by a noble matron, who stood sponsor to him, are all\ntold in an anonymous life of the saint, said to be written in the\nthirteenth century, and published by Quetif and Echard,\nScriptores Ordinis Praedicatorum.  Par.  1719. fol. t 1.  p. 25.\nThese writers deny his having been an inquisitor, and indeed the\nestablishment of the inquisition itself before the fourth Lateran\ncouncil.  Ibid.  p. 88.\n\nv. 55.  In the mother\'s womb.]  His mother, when pregnant with\nhim, is said to have dreamt that she should bring forth a white\nand black dog, with a lighted torch in its mouth.\n\nv. 59.  The dame.]  His godmother\'s dream was, that he had one\nstar in his forehead, and another in the nape of his neck, from\nwhich he communicated light to the east and the west.\n\nv. 73.  Felix.]  Felix Gusman.\n\nv. 75.  As men interpret it.]  Grace or gift of the Lord.\n\nv. 77.  Ostiense.]  A cardinal, who explained the decretals.\n\nv. 77.  Taddeo.]  A physician, of Florence.\n\nv. 82.  The see.]  \"The apostolic see, which no longer continues\nits wonted liberality towards the indigent and deserving; not\nindeed  through its own fault, as its doctrines are still the\nsame, but through the fault of the pontiff, who is seated in it.\"\n\nv. 85.  No dispensation.]  Dominic did not ask license to\ncompound for the use of unjust acquisitions, by dedicating a part\nof them to pious purposes.\n\nv. 89.  In favour of that seed.]  \"For that seed of the divine\nword, from which have sprung up these four-and-twenty plants,\nthat now environ thee.\"");
    strcat(expected_filecontent, "\n\nv. 101.  But the track.]  \"But the rule of St. Francis is already\ndeserted and the lees of the wine are turned into mouldiness.\"\n\nv. 110.  Tares.]  He adverts to the parable of the taxes and the\nwheat.\n\nv. 111.  I question not.]  \"Some indeed might be found, who still\nobserve the rule of the order, but such would come neither from\nCasale nor Acquasparta:\" of the former of which places was\nUberto, one master general, by whom the discipline had been\nrelaxed; and of the latter, Matteo, another, who had enforced it\nwith unnecessary rigour.\n\nv. 121.  -Illuminato here,\nAnd Agostino.]\nTwo among the earliest followers of St. Francis.\n\nv. 125.  Hugues of St. Victor.]  A Saxon of the monastery of\nSaint  Victor at Paris, who fed ill 1142 at the age of\nforty-four.  \"A man distinguished by the fecundity of his genius,\nwho treated in his writings of all the branches of sacred and\nprofane erudition that were known in his time, and who composed\nseveral dissertations that are not destitute of merit.\"\nMaclaine\'s Mosheim, Eccl. Hist. v. iii . cent. xii. p. 2. 2. 23.\nI have looked into his writings, and found some reason for\nthis high eulogium.\n\nv. 125.  Piatro Mangiadore.]  \"Petrus Comestor, or the Eater,\nborn at Troyes, was canon and dean of that church, and afterwards\nchancellor of the church of Paris.  He relinquished these\nbenefices to become a regular canon of St. Victor at Paris, where\nhe died in 1198.  Chaudon et Delandine Dict. Hist. Ed. Lyon.\n1804. The work by which he is best known, is his Historia\nScolastica, which I shall have occasion to cite in the Notes to\nCanto XXVI.\n\nv. 126.  He of Spain.]  \"To Pope Adrian V succeeded John XXI a\nnative of Lisbon a man of great genius and extraordinary\nacquirements, especially in logic and in medicine, as his books,\nwritten in the name of Peter of Spain (by which he was known\nbefore he became Pope), may testify.  His life was not much\nlonger than that of his predecessors, for he was killed at\nViterbo, by the falling in of the roof of his chamber, after he\nhad been pontiff only eight months and as many days.\nA.D. 1277.  Mariana, Hist. de Esp. l. xi");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "BONE.BIn");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 6468, file);
                test_error(size == 6211, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6211 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6211);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 6211);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 15: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST15(void)
{
    // informacje o teście
    test_start(15, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(6144, 1);
                char expected_filecontent[6145] = "";

                strcat(expected_filecontent, "pric of Albano and a cardinal\'s\nhat.  He was born at Bagnoregio or Bagnorea, in Tuscany, A.D.\n1221, and died in 1274.\"  Dict. Histor. par Chaudon et Delandine.\nEd.  Lyon.  1804.\n\nv. 28.  The love.]  By an act of mutual courtesy, Buonaventura,\na Franciscan, is made to proclaim the praises of St. Dominic,\nas Thomas Aquinas, a Dominican, has celebrated those of St.\nFrancis.\n\nv. 42.  In that clime.]  Spain.\n\nv. 48.  Callaroga.]  Between Osma and Aranda, in Old Castile,\ndesignated by the royal coat of arms.\n\nv. 51.  The loving minion of the Christian faith.]  Dominic was\nborn April 5, 1170, and died August 6, 1221.  His birthplace,\nCallaroga; his father and mother\'s names, Felix and Joanna, his\nmother\'s dream; his name of Dominic, given him in consequence of\na vision by a noble matron, who stood sponsor to him, are all\ntold in an anonymous life of the saint, said to be written in the\nthirteenth century, and published by Quetif and Echard,\nScriptores Ordinis Praedicatorum.  Par.  1719. fol. t 1.  p. 25.\nThese writers deny his having been an inquisitor, and indeed the\nestablishment of the inquisition itself before the fourth Lateran\ncouncil.  Ibid.  p. 88.\n\nv. 55.  In the mother\'s womb.]  His mother, when pregnant with\nhim, is said to have dreamt that she should bring forth a white\nand black dog, with a lighted torch in its mouth.\n\nv. 59.  The dame.]  His godmother\'s dream was, that he had one\nstar in his forehead, and another in the nape of his neck, from\nwhich he communicated light to the east and the west.\n\nv. 73.  Felix.]  Felix Gusman.\n\nv. 75.  As men interpret it.]  Grace or gift of the Lord.\n\nv. 77.  Ostiense.]  A cardinal, who explained the decretals.\n\nv. 77.  Taddeo.]  A physician, of Florence.\n\nv. 82.  The see.]  \"The apostolic see, which no longer continues\nits wonted liberality towards the indigent and deserving; not\nindeed  through its own fault, as its doctrines are still the\nsame, but through the fault of the pontiff, who is seated in it.\"\n\nv. 85.  No dispensation.]  Dominic did not ask license to\ncompound for the use of unjust acquisitions, by dedicating a part\nof them to pious purposes.\n\nv. 89.  In favour of that seed.]  \"For that seed of the divine\nword, from which have sprung up these four-and-twenty plants,\nthat now environ thee.\"\n\nv. 101.  But the track.]  \"But the rule of St. Francis is already\ndeserted and the lees of the wine are turned into mouldiness.\"\n\nv. 110.  Tares.]  He adverts to the parable of the taxes and the\nwheat.\n\nv. 111.  I question not.]  \"Some indeed might be found, who still\nobserve the rule of the order, but such would come neither from\nCasale nor Acquasparta:\" of the former of which places was\nUberto, one master general, by whom the discipline had been\nrelaxed; and of the latter, Matteo, another, who had enforced it\nwith unnecessary rigour.\n\nv. 121.  -Illuminato here,\nAnd Agostino.]\nTwo among the earliest followers of St. Francis.\n\nv. 125.  Hugues of St. Victor.]  A Saxon of the monastery of\nSaint  Victor at Paris, who fed ill 1142 at the age of\nforty-four.  \"A man distinguished by the fecundity of his genius,\nwho treated in his writings of all the branches of sacred and\nprofane erudition that were known in his time, and who composed\nseveral dissertations that are not destitute of merit.\"\nMaclaine\'s Mosheim, Eccl. Hist. v. iii . cent. xii. p. 2. 2. 23.\nI have looked into his writings, and found some reason for\nthis high eulogium.\n\nv. 125.  Piatro Mangiadore.]  \"Petrus Comestor, or the Eater,\nborn at Troyes, was canon and dean of that church, and afterwards\nchancellor of the church of Paris.  He relinquished these\nbenefices to become a regular canon of St. Victor at Paris, where\nhe died in 1198.  Chaudon et Delandine Dict. Hist. Ed. Lyon.\n1804. The work by which he is best known, is his Historia\nScolastica, which I shall have occasion to cite in the Notes to\nCanto XXVI.\n\nv. 126.  He of Spain.]  \"To Pope Adrian V succeeded John XXI a\nnative of Lisbon a man of great genius and extraordinary\nacquirements, especially in logic and in medicine, as his books,\nwritten in the name of Peter of S");
    strcat(expected_filecontent, "pain (by which he was known\nbefore he became Pope), may testify.  His life was not much\nlonger than that of his predecessors, for he was killed at\nViterbo, by the falling in of the roof of his chamber, after he\nhad been pontiff only eight months and as many days.\nA.D. 1277.  Mariana, Hist. de Esp. l. xiv.  c. 2.\n\nv. 128.  Chrysostom.]  The eloquent patriarch of Constantinople.\n\nv. 128.  Anselmo.]  \"Anselm, Archbishop of Canterbury, was born\nat Aosta, about 1034, and studied under Lanfrane at the monastery\nof Bec, in Normandy, where he afterwards devoted himself to a\nreligious life, in his twenty-seventh year.  In three years he\nwas made prior, and then abbot of that monastery!  from whence he\nwas taken, in 1093, to succeed to the archbishopric, vacant by\nthe death of Lanfrane. He enjoyed this dignity till his death, in\n1109, though it was disturbed by many\ndissentions with William II and Henry I respecting the immunities\nand investitures.  There is much depth and precisian in his\ntheological  works.\" Tiraboschi, Stor.  della Lett. Ital. t. iii.\n\n1. iv. c. 2. Ibid.  c. v.  \"It is an observation made by many\nmodern writers, that the demonstration of the existence of God,\ntaken from the idea of a Supreme Being, of which Des Cartes is\nthought to be the author, was so many ages back discovered and\nbrought to light by Anselm.  Leibnitz himself makes\nthe remark, vol. v. Oper.  p. 570.  Edit.  Genev. 1768.\"\n\nv. 129.  Donatus.]  Aelius Donatus, the grammarian, in the fourth\ncentury, one of the preceptors of St. Jerome.\n\nv. 130.  Raban.]  \"Rabanus Maurus, Archbishop of Mentz, is\ndeservedly placed at the head of the Latin writers of this age.\"\nMosheim, v. ii. cent. ix. p.  2 c. 2.  14.\n\nv. 131.  Joachim.]  Abbot of Flora in Calabria; \"whom the\nmultitude revered as a person divinely inspired and equal to the\nmost illustrious prophets of ancient times.\"  Ibid.  v. iii.\ncent. xiii. p. 2. c. 2. 33.\n\nv. 134.  A peer.]  St. Dominic.\n\nCANTO XIII\n\nv. 1.  Let him.]  \"Whoever would conceive the sight that now\npresented itself to me, m");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "Sun");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 6453, file);
                test_error(size == 6144, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6144 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6144);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 6144);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 16: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST16(void)
{
    // informacje o teście
    test_start(16, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(5130, 1);
                char expected_filecontent[5131] = "";

                strcat(expected_filecontent, " now I. now L. figur\'d I\' th\' air.\nFirst, singing, to their notes they mov\'d, then one\nBecoming of these signs, a little while\nDid rest them, and were mute.  O nymph divine\nOf Pegasean race!  whose souls, which thou\nInspir\'st, mak\'st glorious and long-liv\'d, as they\nCities and realms by thee!  thou with thyself\nInform me; that I may set forth the shapes,\nAs fancy doth present them.  Be thy power\nDisplay\'d in this brief song.  The characters,\nVocal and consonant, were five-fold seven.\nIn order each, as they appear\'d, I mark\'d.\nDiligite Justitiam, the first,\nBoth verb and noun all blazon\'d; and the extreme\nQui judicatis terram.  In the M.\nOf the fifth word they held their station,\nMaking the star seem silver streak\'d with gold.\nAnd on the summit of the M. I saw\nDescending other lights, that rested there,\nSinging, methinks, their bliss and primal good.\nThen, as at shaking of a lighted brand,\nSparkles innumerable on all sides\nRise scatter\'d, source of augury to th\' unwise;\nThus more than thousand twinkling lustres hence\nSeem\'d reascending, and a higher pitch\nSome mounting, and some less; e\'en as the sun,\nWhich kindleth them, decreed.  And when each one\nHad settled in his place, the head and neck\nThen saw I of an eagle, lively\nGrav\'d in that streaky fire.  Who painteth there,\nHath none to guide him; of himself he guides;\nAnd every line and texture of the nest\nDoth own from him the virtue, fashions it.\nThe other bright beatitude, that seem\'d\nErewhile, with lilied crowning, well content\nTo over-canopy the M. mov\'d forth,\nFollowing gently the impress of the bird.\n      Sweet star!  what glorious and thick-studded gems\nDeclar\'d to me our justice on the earth\nTo be the effluence of that heav\'n, which thou,\nThyself a costly jewel, dost inlay!\nTherefore I pray the Sovran Mind, from whom\nThy motion and thy virtue are begun,\nThat he would look from whence the fog doth rise,\nTo vitiate thy beam: so that once more\nHe may put forth his hand \'gainst such, as drive\nTheir traffic in that sanctuary, whose walls\nWith miracles and martyrdoms were built.\n     Ye host of heaven!  whose glory I survey l\nO beg ye grace for those, that are on earth\nAll after ill example gone astray.\nWar once had for its instrument the sword:\nBut now \'t is made, taking the bread away\nWhich the good Father locks from none.  --And thou,\nThat writes but to cancel, think, that they,\nWho for the vineyard, which thou wastest, died,\nPeter and Paul live yet, and mark thy doings.\nThou hast good cause to cry, \"My heart so cleaves\nTo him, that liv\'d in solitude remote,\nAnd from the wilds was dragg\'d to martyrdom,\nI wist not of the fisherman nor Paul.\"\n\n\n\nCANTO XIX\n\nBefore my sight appear\'d, with open wings,\nThe beauteous image, in fruition sweet\nGladdening the thronged spirits.  Each did seem\nA little ruby, whereon so intense\nThe sun-beam glow\'d that to mine eyes it came\nIn clear refraction.  And that, which next\nBefalls me to portray, voice hath not utter\'d,\nNor hath ink written, nor in fantasy\nWas e\'er conceiv\'d.  For I beheld and heard\nThe beak discourse; and, what intention form\'d\nOf many, singly as of one express,\nBeginning:  \"For that I was just and piteous,\nl am exalted to this height of glory,\nThe which no wish exceeds: and there on earth\nHave I my memory left, e\'en by the bad\nCommended, while they leave its course untrod.\"\n     Thus is one heat from many embers felt,\nAs in that image many were the loves,\nAnd one the voice, that issued from them all.\nWhence I address them:  \"O perennial flowers\nOf gladness everlasting!  that exhale\nIn single breath your odours manifold!\nBreathe now; and let the hunger be appeas\'d,\nThat with great craving long hath held my soul,\nFinding no food on earth.  This well I know,\nThat if there be in heav\'n a realm, that shows\nIn faithful mirror the celestial Justice,\nYours without veil reflects it.  Ye discern\nThe heed, wherewith I do prepare myself\nTo hearken; ye the doubt that urges me\nWith such inveterate craving.\"  Straight I saw,\nLike to a falcon issuing from the hood,\nThat rears his head, and claps him with his wings,\nHis beauty and his");
    strcat(expected_filecontent, " eagerness bewraying.\nSo saw I move that stately sign, with praise\nOf grace divine inwoven and high song\nOf inexpressive joy.  \"He,\" it began,\n\"Who turn\'d his compass on the world\'s extreme,\nAnd in that space so variously hath wrought,\nBoth openly, and in secret, in such wise\nCould not through all the universe display\nImpression of his glory, that the Word\nOf his omniscience should not still remain\nIn infinite excess.  In proof whereof,\nHe first through pride supplanted, who was sum\nOf each created being, waited not\nFor light celestial, and abortive fell.\nWhence needs each lesser nature is but scant\nReceptacle unto that Good, which knows\nNo limit, measur\'d by itself alone.\nTherefore your sight, of th\' omnipresent Mind\nA single beam, its origin must own\nSurpassing far its utmost potency.\nThe ken, your world is gifted with, descends\nIn th\' everlasting Justice as low down,\nAs eye doth in the sea; which though it mark\nThe bottom from the shore, in the wide main\nDiscerns it not; and ne\'ertheless it is,\nBut hidden through its");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "COSt");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 5451, file);
                test_error(size == 5130, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 5130 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 5130);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 5130);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 17: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST17(void)
{
    // informacje o teście
    test_start(17, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(537, 1);
                char expected_filecontent[538] = "";

                strcat(expected_filecontent, "disposes me not less\nFor weeping, when I see It thus transform\'d.\nSay then, by Heav\'n, what blasts ye thus?  The whilst\nI wonder, ask not Speech from me:  unapt\nIs he to speak, whom other will employs.\n     He thus:  \"The water and tee plant we pass\'d,\nVirtue possesses, by th\' eternal will\nInfus\'d, the which so pines me.  Every spirit,\nWhose song bewails his gluttony indulg\'d\nToo grossly, here in hunger and in thirst\nIs purified.  The odour, which the fruit,\nAnd spray, that showers upon the verdure, breathe,\nInflames us with desire");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "WARHaNDT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 990, file);
                test_error(size == 537, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 537 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 537);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 537);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 18: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST18(void)
{
    // informacje o teście
    test_start(18, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(5344, 1);
                char expected_filecontent[5345] = "";

                strcat(expected_filecontent, " he chooses!\"  I to him in few:\n\"Bard!  by that God, whom thou didst not adore,\nI do beseech thee (that this ill and worse\nI may escape) to lead me, where thou saidst,\nThat I Saint Peter\'s gate may view, and those\nWho as thou tell\'st, are in such dismal plight.\"\n     Onward he mov\'d, I close his steps pursu\'d.\n\n\n\nCANTO II\n\nNOW was the day departing, and the air,\nImbrown\'d with shadows, from their toils releas\'d\nAll animals on earth; and I alone\nPrepar\'d myself the conflict to sustain,\nBoth of sad pity, and that perilous road,\nWhich my unerring memory shall retrace.\n     O Muses!  O high genius!  now vouchsafe\nYour aid!  O mind!  that all I saw hast kept\nSafe in a written record, here thy worth\nAnd eminent endowments come to proof.\n     I thus began:  \"Bard!  thou who art my guide,\nConsider well, if virtue be in me\nSufficient, ere to this high enterprise\nThou trust me.  Thou hast told that Silvius\' sire,\nYet cloth\'d in corruptible flesh, among\nTh\' immortal tribes had entrance, and was there\nSensible present.  Yet if heaven\'s great Lord,\nAlmighty foe to ill, such favour shew\'d,\nIn contemplation of the high effect,\nBoth what and who from him should issue forth,\nIt seems in reason\'s judgment well deserv\'d:\nSith he of Rome, and of Rome\'s empire wide,\nIn heaven\'s empyreal height was chosen sire:\nBoth which, if truth be spoken, were ordain\'d\nAnd \'stablish\'d for the holy place, where sits\nWho to great Peter\'s sacred chair succeeds.\nHe from this journey, in thy song renown\'d,\nLearn\'d things, that to his victory gave rise\nAnd to the papal robe.  In after-times\nThe chosen vessel also travel\'d there,\nTo bring us back assurance in that faith,\nWhich is the entrance to salvation\'s way.\nBut I, why should I there presume?  or who\nPermits it?  not, Aeneas I nor Paul.\nMyself I deem not worthy, and none else\nWill deem me.  I, if on this voyage then\nI venture, fear it will in folly end.\nThou, who art wise, better my meaning know\'st,\nThan I can speak.\"  As one, who unresolves\nWhat he hath late resolv\'d, and with new thoughts\nChanges his purpose, from his first intent\nRemov\'d; e\'en such was I on that dun coast,\nWasting in thought my enterprise, at first\nSo eagerly embrac\'d.  \"If right thy words\nI scan,\" replied that shade magnanimous,\n\"Thy soul is by vile fear assail\'d, which oft\nSo overcasts a man, that he recoils\nFrom noblest resolution, like a beast\nAt some false semblance in the twilight gloom.\nThat from this terror thou mayst free thyself,\nI will instruct thee why I came, and what\nI heard in that same instant, when for thee\nGrief touch\'d me first.  I was among the tribe,\nWho rest suspended, when a dame, so blest\nAnd lovely, I besought her to command,\nCall\'d me; her eyes were brighter than the star\nOf day; and she with gentle voice and soft\nAngelically tun\'d her speech address\'d:\n\"O courteous shade of Mantua!  thou whose fame\nYet lives, and shall live long as nature lasts!\nA friend, not of my fortune but myself,\nOn the wide desert in his road has met\nHindrance so great, that he through fear has turn\'d.\nNow much I dread lest he past help have stray\'d,\nAnd I be ris\'n too late for his relief,\nFrom what in heaven of him I heard.  Speed now,\nAnd by thy eloquent persuasive tongue,\nAnd by all means for his deliverance meet,\nAssist him.  So to me will comfort spring.\nI who now bid thee on this errand forth\nAm Beatrice; from a place I come\n\n(Note:  Beatrice.  I use this word, as it is\npronounced in the Italian, as consisting of four\nsyllables, of which the third is a long one.)\n\nRevisited with joy.  Love brought me thence,\nWho prompts my speech.  When in my Master\'s sight\nI stand, thy praise to him I oft will tell.\"\n     She then was silent, and I thus began:\n\"O Lady!  by whose influence alone,\nMankind excels whatever is contain\'d\nWithin that heaven which hath the smallest orb,\nSo thy command delights me, that to obey,\nIf it were done already, would seem late.\nNo need hast thou farther to speak thy will;\nYet tell the reason, why thou art not loth\nTo leave that ample space, where to return\nThou burnest, for this centre here beneath.\"\n     She then:");
    strcat(expected_filecontent, "  \"Since thou so deeply wouldst inquire,\nI will instruct thee briefly, why no dread\nHinders my entrance here.  Those things alone\nAre to be fear\'d, whence evil may proceed,\nNone else, for none are terrible beside.\nI am so fram\'d by God, thanks to his grace!\nThat any suff\'rance of your misery\nTouches me not, nor flame of that fierce fire\nAssails me.  In high heaven a blessed dame\nBesides, who mourns with such effectual grief\nThat hindrance, which I send thee to remove,\nThat God\'s stern judgment to her will inclines.\nTo Lucia calling, her she thus bespake:\n\"Now doth thy faithful servant need thy aid\nAnd I commend him to thee.\"  At her word\nSped Lucia, of all cruelty the foe,\nAnd coming to the place, where I abode\nSeated with Rachel, her of ancient days,\nShe thus address\'d me: \"Thou true praise of God!\nBeatrice!  why is not thy succour lent\nTo him, who so much lov\'d thee, as to leave\nFor thy sake all the multitude admires?\nDost thou not hear how pitiful his wail,\nNor mark the death, which in the torrent flood,\nSwoln mightier than a sea, him struggling holds?\"\nNe\'er among men did any with such speed\nHaste to their profit, flee from their annoy,\nAs when these words were spoken, I came here,\nDown from my blessed seat, trusting the forc");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "hAD.Bin");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 5629, file);
                test_error(size == 5344, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 5344 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 5344);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 5344);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 19: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST19(void)
{
    // informacje o teście
    test_start(19, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(727, 1);
                char expected_filecontent[728] = "";

                strcat(expected_filecontent, "ness he has transmitted to posterity. He  died in 1336, at\nthe age of 60.\n\nv. 96.  One Guido from the other.]  Guido Cavalcanti, the friend\nof our Poet, (see Hell, Canto X. 59.) had eclipsed the literary\nfame of Guido Guinicelli, of a noble family in Bologna, whom we\nshall meet with in the twenty-sixth Canto and of whom frequent\nmention is made by our Poet in his Treatise de Vulg. Eloq.\nGuinicelli died in 1276.  Many of Cavalcanti\'s writings, hitherto\nin MS. are now publishing at Florence\" Esprit des Journaux, Jan.\n1813.\n\nv. 97.  He perhaps is born.]  Some imagine, with much\nprobability, that Dante here augurs the greatness of his own\npoetical reputation.  Others have fancied that he prophesies the\nglory of Petrarch. ");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "OwN.TXt");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 1028, file);
                test_error(size == 727, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 727 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 727);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 727);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 20: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST20(void)
{
    // informacje o teście
    test_start(20, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(6211, 1);
                char expected_filecontent[6212] = "";

                strcat(expected_filecontent, "father, or bishop,\nin whose presence he made a profession of poverty.\n\nv. 60.  Her first husband.]  Christ.\n\nv. 63.  Amyclas.]  Lucan makes Caesar exclaim, on witnessing the\nsecure poverty of the fisherman Amyclas:\n\n--O vite tuta facultas\nPauperis, angustique lares!  O munera nondum\nIntellecta deum!  quibus hoc contingere templis,\nAut potuit muris, nullo trepidare tumultu,\nCaesarea pulsante manu?\nLucan Phars. 1. v. 531.\n\nv. 72.  Bernard.]  One of the first followers of the saint.\n\nv. 76.  Egidius.]  The third of his disciples, who died in 1262.\nHis work, entitled Verba Aurea, was published in 1534, at Antwerp\nSee Lucas Waddingus, Annales Ordinis Minoris, p. 5.\n\nv. 76.  Sylvester.]  Another of his earliest associates.\n\nv. 83.  Pietro Bernardone.]  A man in an humble station of life\nat Assisi.\n\nv. 86.  Innocent.]  Pope Innocent III.\n\nv. 90.  Honorius.]  His successor Honorius III who granted\ncertain privileges to the Franciscans.\n\nv. 93.  On the hard rock.]  The mountain Alverna in the Apennine.\n\nv. 100.  The last signet.]  Alluding to the stigmata, or marks\nresembling the wounds of Christ, said to have been found on the\nsaint\'s body.\n\nv. 106.  His dearest lady.]  Poverty.\n\nv. 113.  Our Patriarch ]  Saint Dominic.\n\nv. 316.  His flock ] The Dominicans.\n\nv. 127.  The planet from whence they split.]  \"The rule of their\norder, which the Dominicans neglect to observe.\"\n\nCANTO XII\n\nv. 1.  The blessed flame.]  Thomas Aquinas\n\nv. 12.  That voice.]  The nymph Echo, transformed into the\nrepercussion of the voice.\n\nv. 25.  One.]  Saint Buonaventura, general of the Franciscan\norder, in which he effected some reformation, and one of the most\nprofound divines of his age.  \"He refused the archbishopric of\nYork, which was offered him by Clement IV, but afterwards was\nprevailed on to accept the bishopric of Albano and a cardinal\'s\nhat.  He was born at Bagnoregio or Bagnorea, in Tuscany, A.D.\n1221, and died in 1274.\"  Dict. Histor. par Chaudon et Delandine.\nEd.  Lyon.  1804.\n\nv. 28.  The love.]  By an act of mutual courtesy, Buonaventura,\na Franciscan, is made to proclaim the praises of St. Dominic,\nas Thomas Aquinas, a Dominican, has celebrated those of St.\nFrancis.\n\nv. 42.  In that clime.]  Spain.\n\nv. 48.  Callaroga.]  Between Osma and Aranda, in Old Castile,\ndesignated by the royal coat of arms.\n\nv. 51.  The loving minion of the Christian faith.]  Dominic was\nborn April 5, 1170, and died August 6, 1221.  His birthplace,\nCallaroga; his father and mother\'s names, Felix and Joanna, his\nmother\'s dream; his name of Dominic, given him in consequence of\na vision by a noble matron, who stood sponsor to him, are all\ntold in an anonymous life of the saint, said to be written in the\nthirteenth century, and published by Quetif and Echard,\nScriptores Ordinis Praedicatorum.  Par.  1719. fol. t 1.  p. 25.\nThese writers deny his having been an inquisitor, and indeed the\nestablishment of the inquisition itself before the fourth Lateran\ncouncil.  Ibid.  p. 88.\n\nv. 55.  In the mother\'s womb.]  His mother, when pregnant with\nhim, is said to have dreamt that she should bring forth a white\nand black dog, with a lighted torch in its mouth.\n\nv. 59.  The dame.]  His godmother\'s dream was, that he had one\nstar in his forehead, and another in the nape of his neck, from\nwhich he communicated light to the east and the west.\n\nv. 73.  Felix.]  Felix Gusman.\n\nv. 75.  As men interpret it.]  Grace or gift of the Lord.\n\nv. 77.  Ostiense.]  A cardinal, who explained the decretals.\n\nv. 77.  Taddeo.]  A physician, of Florence.\n\nv. 82.  The see.]  \"The apostolic see, which no longer continues\nits wonted liberality towards the indigent and deserving; not\nindeed  through its own fault, as its doctrines are still the\nsame, but through the fault of the pontiff, who is seated in it.\"\n\nv. 85.  No dispensation.]  Dominic did not ask license to\ncompound for the use of unjust acquisitions, by dedicating a part\nof them to pious purposes.\n\nv. 89.  In favour of that seed.]  \"For that seed of the divine\nword, from which have sprung up these four-and-twenty plants,\nthat now environ thee.\"");
    strcat(expected_filecontent, "\n\nv. 101.  But the track.]  \"But the rule of St. Francis is already\ndeserted and the lees of the wine are turned into mouldiness.\"\n\nv. 110.  Tares.]  He adverts to the parable of the taxes and the\nwheat.\n\nv. 111.  I question not.]  \"Some indeed might be found, who still\nobserve the rule of the order, but such would come neither from\nCasale nor Acquasparta:\" of the former of which places was\nUberto, one master general, by whom the discipline had been\nrelaxed; and of the latter, Matteo, another, who had enforced it\nwith unnecessary rigour.\n\nv. 121.  -Illuminato here,\nAnd Agostino.]\nTwo among the earliest followers of St. Francis.\n\nv. 125.  Hugues of St. Victor.]  A Saxon of the monastery of\nSaint  Victor at Paris, who fed ill 1142 at the age of\nforty-four.  \"A man distinguished by the fecundity of his genius,\nwho treated in his writings of all the branches of sacred and\nprofane erudition that were known in his time, and who composed\nseveral dissertations that are not destitute of merit.\"\nMaclaine\'s Mosheim, Eccl. Hist. v. iii . cent. xii. p. 2. 2. 23.\nI have looked into his writings, and found some reason for\nthis high eulogium.\n\nv. 125.  Piatro Mangiadore.]  \"Petrus Comestor, or the Eater,\nborn at Troyes, was canon and dean of that church, and afterwards\nchancellor of the church of Paris.  He relinquished these\nbenefices to become a regular canon of St. Victor at Paris, where\nhe died in 1198.  Chaudon et Delandine Dict. Hist. Ed. Lyon.\n1804. The work by which he is best known, is his Historia\nScolastica, which I shall have occasion to cite in the Notes to\nCanto XXVI.\n\nv. 126.  He of Spain.]  \"To Pope Adrian V succeeded John XXI a\nnative of Lisbon a man of great genius and extraordinary\nacquirements, especially in logic and in medicine, as his books,\nwritten in the name of Peter of Spain (by which he was known\nbefore he became Pope), may testify.  His life was not much\nlonger than that of his predecessors, for he was killed at\nViterbo, by the falling in of the roof of his chamber, after he\nhad been pontiff only eight months and as many days.\nA.D. 1277.  Mariana, Hist. de Esp. l. xi");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "BONE.BiN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 6481, file);
                test_error(size == 6211, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6211 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6211);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 6211);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 21: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST21(void)
{
    // informacje o teście
    test_start(21, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(6144, 1);
                char expected_filecontent[6145] = "";

                strcat(expected_filecontent, "pric of Albano and a cardinal\'s\nhat.  He was born at Bagnoregio or Bagnorea, in Tuscany, A.D.\n1221, and died in 1274.\"  Dict. Histor. par Chaudon et Delandine.\nEd.  Lyon.  1804.\n\nv. 28.  The love.]  By an act of mutual courtesy, Buonaventura,\na Franciscan, is made to proclaim the praises of St. Dominic,\nas Thomas Aquinas, a Dominican, has celebrated those of St.\nFrancis.\n\nv. 42.  In that clime.]  Spain.\n\nv. 48.  Callaroga.]  Between Osma and Aranda, in Old Castile,\ndesignated by the royal coat of arms.\n\nv. 51.  The loving minion of the Christian faith.]  Dominic was\nborn April 5, 1170, and died August 6, 1221.  His birthplace,\nCallaroga; his father and mother\'s names, Felix and Joanna, his\nmother\'s dream; his name of Dominic, given him in consequence of\na vision by a noble matron, who stood sponsor to him, are all\ntold in an anonymous life of the saint, said to be written in the\nthirteenth century, and published by Quetif and Echard,\nScriptores Ordinis Praedicatorum.  Par.  1719. fol. t 1.  p. 25.\nThese writers deny his having been an inquisitor, and indeed the\nestablishment of the inquisition itself before the fourth Lateran\ncouncil.  Ibid.  p. 88.\n\nv. 55.  In the mother\'s womb.]  His mother, when pregnant with\nhim, is said to have dreamt that she should bring forth a white\nand black dog, with a lighted torch in its mouth.\n\nv. 59.  The dame.]  His godmother\'s dream was, that he had one\nstar in his forehead, and another in the nape of his neck, from\nwhich he communicated light to the east and the west.\n\nv. 73.  Felix.]  Felix Gusman.\n\nv. 75.  As men interpret it.]  Grace or gift of the Lord.\n\nv. 77.  Ostiense.]  A cardinal, who explained the decretals.\n\nv. 77.  Taddeo.]  A physician, of Florence.\n\nv. 82.  The see.]  \"The apostolic see, which no longer continues\nits wonted liberality towards the indigent and deserving; not\nindeed  through its own fault, as its doctrines are still the\nsame, but through the fault of the pontiff, who is seated in it.\"\n\nv. 85.  No dispensation.]  Dominic did not ask license to\ncompound for the use of unjust acquisitions, by dedicating a part\nof them to pious purposes.\n\nv. 89.  In favour of that seed.]  \"For that seed of the divine\nword, from which have sprung up these four-and-twenty plants,\nthat now environ thee.\"\n\nv. 101.  But the track.]  \"But the rule of St. Francis is already\ndeserted and the lees of the wine are turned into mouldiness.\"\n\nv. 110.  Tares.]  He adverts to the parable of the taxes and the\nwheat.\n\nv. 111.  I question not.]  \"Some indeed might be found, who still\nobserve the rule of the order, but such would come neither from\nCasale nor Acquasparta:\" of the former of which places was\nUberto, one master general, by whom the discipline had been\nrelaxed; and of the latter, Matteo, another, who had enforced it\nwith unnecessary rigour.\n\nv. 121.  -Illuminato here,\nAnd Agostino.]\nTwo among the earliest followers of St. Francis.\n\nv. 125.  Hugues of St. Victor.]  A Saxon of the monastery of\nSaint  Victor at Paris, who fed ill 1142 at the age of\nforty-four.  \"A man distinguished by the fecundity of his genius,\nwho treated in his writings of all the branches of sacred and\nprofane erudition that were known in his time, and who composed\nseveral dissertations that are not destitute of merit.\"\nMaclaine\'s Mosheim, Eccl. Hist. v. iii . cent. xii. p. 2. 2. 23.\nI have looked into his writings, and found some reason for\nthis high eulogium.\n\nv. 125.  Piatro Mangiadore.]  \"Petrus Comestor, or the Eater,\nborn at Troyes, was canon and dean of that church, and afterwards\nchancellor of the church of Paris.  He relinquished these\nbenefices to become a regular canon of St. Victor at Paris, where\nhe died in 1198.  Chaudon et Delandine Dict. Hist. Ed. Lyon.\n1804. The work by which he is best known, is his Historia\nScolastica, which I shall have occasion to cite in the Notes to\nCanto XXVI.\n\nv. 126.  He of Spain.]  \"To Pope Adrian V succeeded John XXI a\nnative of Lisbon a man of great genius and extraordinary\nacquirements, especially in logic and in medicine, as his books,\nwritten in the name of Peter of S");
    strcat(expected_filecontent, "pain (by which he was known\nbefore he became Pope), may testify.  His life was not much\nlonger than that of his predecessors, for he was killed at\nViterbo, by the falling in of the roof of his chamber, after he\nhad been pontiff only eight months and as many days.\nA.D. 1277.  Mariana, Hist. de Esp. l. xiv.  c. 2.\n\nv. 128.  Chrysostom.]  The eloquent patriarch of Constantinople.\n\nv. 128.  Anselmo.]  \"Anselm, Archbishop of Canterbury, was born\nat Aosta, about 1034, and studied under Lanfrane at the monastery\nof Bec, in Normandy, where he afterwards devoted himself to a\nreligious life, in his twenty-seventh year.  In three years he\nwas made prior, and then abbot of that monastery!  from whence he\nwas taken, in 1093, to succeed to the archbishopric, vacant by\nthe death of Lanfrane. He enjoyed this dignity till his death, in\n1109, though it was disturbed by many\ndissentions with William II and Henry I respecting the immunities\nand investitures.  There is much depth and precisian in his\ntheological  works.\" Tiraboschi, Stor.  della Lett. Ital. t. iii.\n\n1. iv. c. 2. Ibid.  c. v.  \"It is an observation made by many\nmodern writers, that the demonstration of the existence of God,\ntaken from the idea of a Supreme Being, of which Des Cartes is\nthought to be the author, was so many ages back discovered and\nbrought to light by Anselm.  Leibnitz himself makes\nthe remark, vol. v. Oper.  p. 570.  Edit.  Genev. 1768.\"\n\nv. 129.  Donatus.]  Aelius Donatus, the grammarian, in the fourth\ncentury, one of the preceptors of St. Jerome.\n\nv. 130.  Raban.]  \"Rabanus Maurus, Archbishop of Mentz, is\ndeservedly placed at the head of the Latin writers of this age.\"\nMosheim, v. ii. cent. ix. p.  2 c. 2.  14.\n\nv. 131.  Joachim.]  Abbot of Flora in Calabria; \"whom the\nmultitude revered as a person divinely inspired and equal to the\nmost illustrious prophets of ancient times.\"  Ibid.  v. iii.\ncent. xiii. p. 2. c. 2. 33.\n\nv. 134.  A peer.]  St. Dominic.\n\nCANTO XIII\n\nv. 1.  Let him.]  \"Whoever would conceive the sight that now\npresented itself to me, m");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "SUN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 6412, file);
                test_error(size == 6144, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6144 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6144);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 6144);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 22: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST22(void)
{
    // informacje o teście
    test_start(22, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(5130, 1);
                char expected_filecontent[5131] = "";

                strcat(expected_filecontent, " now I. now L. figur\'d I\' th\' air.\nFirst, singing, to their notes they mov\'d, then one\nBecoming of these signs, a little while\nDid rest them, and were mute.  O nymph divine\nOf Pegasean race!  whose souls, which thou\nInspir\'st, mak\'st glorious and long-liv\'d, as they\nCities and realms by thee!  thou with thyself\nInform me; that I may set forth the shapes,\nAs fancy doth present them.  Be thy power\nDisplay\'d in this brief song.  The characters,\nVocal and consonant, were five-fold seven.\nIn order each, as they appear\'d, I mark\'d.\nDiligite Justitiam, the first,\nBoth verb and noun all blazon\'d; and the extreme\nQui judicatis terram.  In the M.\nOf the fifth word they held their station,\nMaking the star seem silver streak\'d with gold.\nAnd on the summit of the M. I saw\nDescending other lights, that rested there,\nSinging, methinks, their bliss and primal good.\nThen, as at shaking of a lighted brand,\nSparkles innumerable on all sides\nRise scatter\'d, source of augury to th\' unwise;\nThus more than thousand twinkling lustres hence\nSeem\'d reascending, and a higher pitch\nSome mounting, and some less; e\'en as the sun,\nWhich kindleth them, decreed.  And when each one\nHad settled in his place, the head and neck\nThen saw I of an eagle, lively\nGrav\'d in that streaky fire.  Who painteth there,\nHath none to guide him; of himself he guides;\nAnd every line and texture of the nest\nDoth own from him the virtue, fashions it.\nThe other bright beatitude, that seem\'d\nErewhile, with lilied crowning, well content\nTo over-canopy the M. mov\'d forth,\nFollowing gently the impress of the bird.\n      Sweet star!  what glorious and thick-studded gems\nDeclar\'d to me our justice on the earth\nTo be the effluence of that heav\'n, which thou,\nThyself a costly jewel, dost inlay!\nTherefore I pray the Sovran Mind, from whom\nThy motion and thy virtue are begun,\nThat he would look from whence the fog doth rise,\nTo vitiate thy beam: so that once more\nHe may put forth his hand \'gainst such, as drive\nTheir traffic in that sanctuary, whose walls\nWith miracles and martyrdoms were built.\n     Ye host of heaven!  whose glory I survey l\nO beg ye grace for those, that are on earth\nAll after ill example gone astray.\nWar once had for its instrument the sword:\nBut now \'t is made, taking the bread away\nWhich the good Father locks from none.  --And thou,\nThat writes but to cancel, think, that they,\nWho for the vineyard, which thou wastest, died,\nPeter and Paul live yet, and mark thy doings.\nThou hast good cause to cry, \"My heart so cleaves\nTo him, that liv\'d in solitude remote,\nAnd from the wilds was dragg\'d to martyrdom,\nI wist not of the fisherman nor Paul.\"\n\n\n\nCANTO XIX\n\nBefore my sight appear\'d, with open wings,\nThe beauteous image, in fruition sweet\nGladdening the thronged spirits.  Each did seem\nA little ruby, whereon so intense\nThe sun-beam glow\'d that to mine eyes it came\nIn clear refraction.  And that, which next\nBefalls me to portray, voice hath not utter\'d,\nNor hath ink written, nor in fantasy\nWas e\'er conceiv\'d.  For I beheld and heard\nThe beak discourse; and, what intention form\'d\nOf many, singly as of one express,\nBeginning:  \"For that I was just and piteous,\nl am exalted to this height of glory,\nThe which no wish exceeds: and there on earth\nHave I my memory left, e\'en by the bad\nCommended, while they leave its course untrod.\"\n     Thus is one heat from many embers felt,\nAs in that image many were the loves,\nAnd one the voice, that issued from them all.\nWhence I address them:  \"O perennial flowers\nOf gladness everlasting!  that exhale\nIn single breath your odours manifold!\nBreathe now; and let the hunger be appeas\'d,\nThat with great craving long hath held my soul,\nFinding no food on earth.  This well I know,\nThat if there be in heav\'n a realm, that shows\nIn faithful mirror the celestial Justice,\nYours without veil reflects it.  Ye discern\nThe heed, wherewith I do prepare myself\nTo hearken; ye the doubt that urges me\nWith such inveterate craving.\"  Straight I saw,\nLike to a falcon issuing from the hood,\nThat rears his head, and claps him with his wings,\nHis beauty and his");
    strcat(expected_filecontent, " eagerness bewraying.\nSo saw I move that stately sign, with praise\nOf grace divine inwoven and high song\nOf inexpressive joy.  \"He,\" it began,\n\"Who turn\'d his compass on the world\'s extreme,\nAnd in that space so variously hath wrought,\nBoth openly, and in secret, in such wise\nCould not through all the universe display\nImpression of his glory, that the Word\nOf his omniscience should not still remain\nIn infinite excess.  In proof whereof,\nHe first through pride supplanted, who was sum\nOf each created being, waited not\nFor light celestial, and abortive fell.\nWhence needs each lesser nature is but scant\nReceptacle unto that Good, which knows\nNo limit, measur\'d by itself alone.\nTherefore your sight, of th\' omnipresent Mind\nA single beam, its origin must own\nSurpassing far its utmost potency.\nThe ken, your world is gifted with, descends\nIn th\' everlasting Justice as low down,\nAs eye doth in the sea; which though it mark\nThe bottom from the shore, in the wide main\nDiscerns it not; and ne\'ertheless it is,\nBut hidden through its");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "CosT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 5377, file);
                test_error(size == 5130, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 5130 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 5130);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 5130);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 23: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST23(void)
{
    // informacje o teście
    test_start(23, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(537, 1);
                char expected_filecontent[538] = "";

                strcat(expected_filecontent, "disposes me not less\nFor weeping, when I see It thus transform\'d.\nSay then, by Heav\'n, what blasts ye thus?  The whilst\nI wonder, ask not Speech from me:  unapt\nIs he to speak, whom other will employs.\n     He thus:  \"The water and tee plant we pass\'d,\nVirtue possesses, by th\' eternal will\nInfus\'d, the which so pines me.  Every spirit,\nWhose song bewails his gluttony indulg\'d\nToo grossly, here in hunger and in thirst\nIs purified.  The odour, which the fruit,\nAnd spray, that showers upon the verdure, breathe,\nInflames us with desire");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "WARHANdt");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 781, file);
                test_error(size == 537, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 537 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 537);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 537);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 24: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST24(void)
{
    // informacje o teście
    test_start(24, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char expected_filecontent[124] = "";

            strcat(expected_filecontent, "stra tenere,\nSic tenuit vivens:  nunc tenet astra poli.\n\nv. 95.  The cry is Giotto\'s.]  In Giotto we have a proof at how\nea");

            struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "\\DEPEND\\DRIVE\\DEVElOP\\SECoNd\\.\\..\\SECONd\\TEmPeRAt\\fReE.tXT");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            for (int i = 0; i < 123; ++i)
            {
                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
            }

            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 25: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST25(void)
{
    // informacje o teście
    test_start(25, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[7823] = "";

                strcat(expected_filecontent, " behold,\nAs would my speech discredit.\"  On all sides\nI heard sad plainings breathe, and none could see\nFrom whom they might have issu\'d.  In amaze\nFast bound I stood.  He, as it seem\'d, believ\'d,\nThat I had thought so many voices came\nFrom some amid those thickets close conceal\'d,\nAnd thus his speech resum\'d:  \"If thou lop off\nA single twig from one of those ill plants,\nThe thought thou hast conceiv\'d shall vanish quite.\"\n     Thereat a little stretching forth my hand,\nFrom a great wilding gather\'d I a branch,\nAnd straight the trunk exclaim\'d:  \"Why pluck\'st thou me?\"\nThen as the dark blood trickled down its side,\nThese words it added:  \"Wherefore tear\'st me thus?\nIs there no touch of mercy in thy breast?\nMen once were we, that now are rooted here.\nThy hand might well have spar\'d us, had we been\nThe souls of serpents.\"  As a brand yet green,\nThat burning at one end from the\' other sends\nA groaning sound, and hisses with the wind\nThat forces out its way, so burst at once,\nForth from the broken splinter words and blood.\n     I, letting fall the bough, remain\'d as one\nAssail\'d by terror, and the sage replied:\n\"If he, O injur\'d spirit! could have believ\'d\nWhat he hath seen but in my verse describ\'d,\nHe never against thee had stretch\'d his hand.\nBut I, because the thing surpass\'d belief,\nPrompted him to this deed, which even now\nMyself I rue.  But tell me, who thou wast;\nThat, for this wrong to do thee some amends,\nIn the upper world (for thither to return\nIs granted him) thy fame he may revive.\"\n     \"That pleasant word of thine,\" the trunk replied\n\"Hath so inveigled me, that I from speech\nCannot refrain, wherein if I indulge\nA little longer, in the snare detain\'d,\nCount it not grievous.  I it was, who held\nBoth keys to Frederick\'s heart, and turn\'d the wards,\nOpening and shutting, with a skill so sweet,\nThat besides me, into his inmost breast\nScarce any other could admittance find.\nThe faith I bore to my high charge was such,\nIt cost me the life-blood that warm\'d my veins.\nThe harlot, who ne\'er turn\'d her gloating eyes\nFrom Caesar\'s household, common vice and pest\nOf courts, \'gainst me inflam\'d the minds of all;\nAnd to Augustus they so spread the flame,\nThat my glad honours chang\'d to bitter woes.\nMy soul, disdainful and disgusted, sought\nRefuge in death from scorn, and I became,\nJust as I was, unjust toward myself.\nBy the new roots, which fix this stem, I swear,\nThat never faith I broke to my liege lord,\nWho merited such honour; and of you,\nIf any to the world indeed return,\nClear he from wrong my memory, that lies\nYet prostrate under envy\'s cruel blow.\"\n     First somewhat pausing, till the mournful words\nWere ended, then to me the bard began:\n\"Lose not the time; but speak and of him ask,\nIf more thou wish to learn.\"  Whence I replied:\n\"Question thou him again of whatsoe\'er\nWill, as thou think\'st, content me; for no power\nHave I to ask, such pity\' is at my heart.\"\n     He thus resum\'d;  \"So may he do for thee\nFreely what thou entreatest, as thou yet\nBe pleas\'d, imprison\'d Spirit! to declare,\nHow in these gnarled joints the soul is tied;\nAnd whether any ever from such frame\nBe loosen\'d, if thou canst, that also tell.\"\n     Thereat the trunk breath\'d hard, and the wind soon\nChang\'d into sounds articulate like these;\n     Briefly ye shall be answer\'d.  When departs\nThe fierce soul from the body, by itself\nThence torn asunder, to the seventh gulf\nBy Minos doom\'d, into the wood it falls,\nNo place assign\'d, but wheresoever chance\nHurls it, there sprouting, as a grain of spelt,\nIt rises to a sapling, growing thence\nA savage plant.  The Harpies, on its leaves\nThen feeding, cause both pain and for the pain\nA vent to grief.  We, as the rest, shall come\nFor our own spoils, yet not so that with them\nWe may again be clad; for what a man\nTakes from himself it is not just he have.\nHere we perforce shall drag them; and throughout\nThe dismal glade our bodies shall be hung,\nEach on the wild thorn of his wretched shade.\"\n     Attentive yet to listen to the trunk\nWe stood, expecting farther speech, when us\nA noise surpris\'d, as when a man ");
    strcat(expected_filecontent, "perceives\nThe wild boar and the hunt approach his place\nOf station\'d watch, who of the beasts and boughs\nLoud rustling round him hears.  And lo! there came\nTwo naked, torn with briers, in headlong flight,\nThat they before them broke each fan o\' th\' wood.\n\"Haste now,\" the foremost cried, \"now haste thee death!\"\nThe\' other, as seem\'d, impatient of delay\nExclaiming, \"Lano! not so bent for speed\nThy sinews, in the lists of Toppo\'s field.\"\nAnd then, for that perchance no longer breath\nSuffic\'d him, of himself and of a bush\nOne group he made.  Behind them was the wood\nFull of black female mastiffs, gaunt and fleet,\nAs greyhounds that have newly slipp\'d the leash.\nOn him, who squatted down, they stuck their fangs,\nAnd having rent him piecemeal bore away\nThe tortur\'d limbs.  My guide then seiz\'d my hand,\nAnd led me to the thicket, which in vain\nMourn\'d through its bleeding wounds:  \"O Giacomo\nOf Sant\' Andrea! what avails it thee,\"\nIt cried, \"that of me thou hast made thy screen?\nFor thy ill life what blame on me recoils?\"\n     When o\'er it he had paus\'d, my master spake:\n\"Say who wast thou, that at so many points\nBreath\'st out with blood thy lamentable speech?\"\n     He answer\'d: \"Oh, ye spirits:  arriv\'d in time\nTo spy the shameful havoc, that from me\nMy leaves hath sever\'d thus, gather them up,\nAnd at the foot of their sad parent-tree\nCarefully lay them.  In that city\' I dwelt,\nWho for the Baptist her first patron chang\'d,\nWhence he for this shall cease not with his art\nTo work her woe:  and if there still remain\'d not\nOn Arno\'s passage some faint glimpse of him,\nThose citizens, who rear\'d once more her walls\nUpon the ashes left by Attila,\nHad labour\'d without profit of their toil.\nI slung the fatal noose from my own roof.\"\n\n\n\nCANTO XIV\n\nSOON as the charity of native land\nWrought in my bosom, I the scatter\'d leaves\nCollected, and to him restor\'d, who now\nWas hoarse with utt\'rance.  To the limit thence\nWe came, which from the third the second round\nDivides, and where of justice is display\'d\nContrivance horrible.  Things then first seen\nClearlier to manifest, I tell how next\nA plain we reach\'d, that from its sterile bed\nEach plant repell\'d. The mournful wood waves round\nIts garland on all sides, as round the wood\nSpreads the sad foss.  There, on the very edge,\nOur steps we stay\'d.  It was an area wide\nOf arid sand and thick, resembling most\nThe soil that erst by Cato\'s foot was trod.\n     Vengeance of Heav\'n! Oh ! how shouldst thou be fear\'d\nBy all, who read what here my eyes beheld!\n     Of naked spirits many a flock I saw,\nAll weeping piteously, to different laws\nSubjected:  for on the\' earth some lay supine,\nSome crouching close were seated, others pac\'d\nIncessantly around; the latter tribe,\nMore numerous, those fewer who beneath\nThe torment lay, but louder in their grief.\n     O\'er all the sand fell slowly wafting down\nDilated flakes of fire, as flakes of snow\nOn Alpine summit, when the wind is hush\'d.\nAs in the torrid Indian clime, the son\nOf Ammon saw upon his warrior band\nDescending, solid flames, that to the ground\nCame down:  whence he bethought him with his troop\nTo trample on the soil; for easier thus\nThe vapour was extinguish\'d, while alone;\nSo fell the eternal fiery flood, wherewith\nThe marble glow\'d underneath, as under stove\nThe viands, doubly to augment the pain.\nUnceasing was the play of wretched hands,\nNow this, now that way glancing, to shake off\nThe heat, still falling fresh.  I thus began:\n\"Instructor! thou who all things overcom\'st,\nExcept the hardy demons, that rush\'d forth\nTo stop our entrance at the gate, say who\nIs yon huge spirit, that, as seems, heeds not\nThe burning, but lies writhen in proud scorn,\nAs by the sultry tempest immatur\'d?\"\n   ");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\dEPenD\\dRIVE\\DEVELOP\\guIDE\\EITHeR\\nAtURAL.tXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 7822; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 26: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST26(void)
{
    // informacje o teście
    test_start(26, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[851] = "";

                strcat(expected_filecontent, "re,\nI do beseech thee (that this ill and worse\nI may escape) to lead me, where thou saidst,\nThat I Saint Peter\'s gate may view, and those\nWho as thou tell\'st, are in such dismal plight.\"\n     Onward he mov\'d, I close his steps pursu\'d.\n\n\n\nCANTO II\n\nNOW was the day departing, and the air,\nImbrown\'d with shadows, from their toils releas\'d\nAll animals on earth; and I alone\nPrepar\'d myself the conflict to sustain,\nBoth of sad pity, and that perilous road,\nWhich my unerring memory shall retrace.\n     O Muses!  O high genius!  now vouchsafe\nYour aid!  O mind!  that all I saw hast kept\nSafe in a written record, here thy worth\nAnd eminent endowments come to proof.\n     I thus began:  \"Bard!  thou who art my guide,\nConsider well, if virtue be in me\nSufficient, ere to this high enterprise\nThou trust me.  Thou hast told that Silvius\' sire,\nYet cloth");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\DEPENd\\LeAVE\\FiVe\\EASt\\BeGIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 850; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 27: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST27(void)
{
    // informacje o teście
    test_start(27, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[4242] = "";

                strcat(expected_filecontent, " in heaven.\n     I understood that to this torment sad\nThe carnal sinners are condemn\'d, in whom\nReason by lust is sway\'d.  As in large troops\nAnd multitudinous, when winter reigns,\nThe starlings on their wings are borne abroad;\nSo bears the tyrannous gust those evil souls.\nOn this side and on that, above, below,\nIt drives them:  hope of rest to solace them\nIs none, nor e\'en of milder pang.  As cranes,\nChanting their dol\'rous notes, traverse the sky,\nStretch\'d out in long array:  so I beheld\nSpirits, who came loud wailing, hurried on\nBy their dire doom.  Then I:  \"Instructor!  who\nAre these, by the black air so scourg\'d?\"--\" The first\n\'Mong those, of whom thou question\'st,\" he replied,\n\"O\'er many tongues was empress.  She in vice\nOf luxury was so shameless, that she made\nLiking be lawful by promulg\'d decree,\nTo clear the blame she had herself incurr\'d.\nThis is Semiramis, of whom \'tis writ,\nThat she succeeded Ninus her espous\'d;\nAnd held the land, which now the Soldan rules.\nThe next in amorous fury slew herself,\nAnd to Sicheus\' ashes broke her faith:\nThen follows Cleopatra, lustful queen.\"\n     There mark\'d I Helen, for whose sake so long\nThe time was fraught with evil; there the great\nAchilles, who with love fought to the end.\nParis I saw, and Tristan; and beside\nA thousand more he show\'d me, and by name\nPointed them out, whom love bereav\'d of life.\n     When I had heard my sage instructor name\nThose dames and knights of antique days, o\'erpower\'d\nBy pity, well-nigh in amaze my mind\nWas lost; and I began:  \"Bard!  willingly\nI would address those two together coming,\nWhich seem so light before the wind.\"  He thus:\n\"Note thou, when nearer they to us approach.\nThen by that love which carries them along,\nEntreat; and they will come.\"  Soon as the wind\nSway\'d them toward us, I thus fram\'d my speech:\n\"O wearied spirits!  come, and hold discourse\nWith us, if by none else restrain\'d.\"  As doves\nBy fond desire invited, on wide wings\nAnd firm, to their sweet nest returning home,\nCleave the air, wafted by their will along;\nThus issu\'d from that troop, where Dido ranks,\nThey through the ill air speeding; with such force\nMy cry prevail\'d by strong affection urg\'d.\n     \"O gracious creature and benign!  who go\'st\nVisiting, through this element obscure,\nUs, who the world with bloody stain imbru\'d;\nIf for a friend the King of all we own\'d,\nOur pray\'r to him should for thy peace arise,\nSince thou hast pity on our evil plight.\n()f whatsoe\'er to hear or to discourse\nIt pleases thee, that will we hear, of that\nFreely with thee discourse, while e\'er the wind,\nAs now, is mute.  The land, that gave me birth,\nIs situate on the coast, where Po descends\nTo rest in ocean with his sequent streams.\n     \"Love, that in gentle heart is quickly learnt,\nEntangled him by that fair form, from me\nTa\'en in such cruel sort, as grieves me still:\nLove, that denial takes from none belov\'d,\nCaught me with pleasing him so passing well,\nThat, as thou see\'st, he yet deserts me not.\nLove brought us to one death:  Caina waits\nThe soul, who spilt our life.\"  Such were their words;\nAt hearing which downward I bent my looks,\nAnd held them there so long, that the bard cried:\n\"What art thou pond\'ring?\"  I in answer thus:\n\"Alas!  by what sweet thoughts, what fond desire\nMust they at length to that ill pass have reach\'d!\"\n     Then turning, I to them my speech address\'d.\nAnd thus began:  \"Francesca!  your sad fate\nEven to tears my grief and pity moves.\nBut tell me; in the time of your sweet sighs,\nBy what, and how love granted, that ye knew\nYour yet uncertain wishes?\"  She replied:\n\"No greater grief than to remember days\nOf joy, when mis\'ry is at hand!  That kens\nThy learn\'d instructor.  Yet so eagerly\nIf thou art bent to know the primal root,\nFrom whence our love gat being, I will do,\nAs one, who weeps and tells his tale.  One day\nFor our delight we read of Lancelot,\nHow him love thrall\'d.  Alone we were, and no\nSuspicion near us.  Ofttimes by that reading\nOur eyes were drawn together, and the hue\nFled from our alter\'d cheek.  But at one point\nAlone we fell.  When of that");
    strcat(expected_filecontent, " smile we read,\nThe wished smile, rapturously kiss\'d\nBy one so deep in love, then he, who ne\'er\nFrom me shall separate, at once my lips\nAll trembl");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\On\\pHRASE\\NATurE\\enERGy\\CONtINUE\\mOnEY.TXt");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 4241; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 28: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST28(void)
{
    // informacje o teście
    test_start(28, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[5338] = "";

                strcat(expected_filecontent, "e the fever of his pride\nThis man besought: my counsel to that end\nHe ask\'d:  and I was silent:  for his words\nSeem\'d drunken:  but forthwith he thus resum\'d:\n\"From thy heart banish fear:  of all offence\nI hitherto absolve thee.  In return,\nTeach me my purpose so to execute,\nThat Penestrino cumber earth no more.\nHeav\'n, as thou knowest, I have power to shut\nAnd open:  and the keys are therefore twain,\nThe which my predecessor meanly priz\'d.\"\n     Then, yielding to the forceful arguments,\nOf silence as more perilous I deem\'d,\nAnd answer\'d:  \"Father! since thou washest me\nClear of that guilt wherein I now must fall,\nLarge promise with performance scant, be sure,\nShall make thee triumph in thy lofty seat.\"\n     \"When I was number\'d with the dead, then came\nSaint Francis for me; but a cherub dark\nHe met, who cried: \"\'Wrong me not; he is mine,\nAnd must below to join the wretched crew,\nFor the deceitful counsel which he gave.\nE\'er since I watch\'d him, hov\'ring at his hair,\nNo power can the impenitent absolve;\nNor to repent and will at once consist,\nBy contradiction absolute forbid.\"\nOh mis\'ry! how I shook myself, when he\nSeiz\'d me, and cried, \"Thou haply thought\'st me not\nA disputant in logic so exact.\"\nTo Minos down he bore me, and the judge\nTwin\'d eight times round his callous back the tail,\nWhich biting with excess of rage, he spake:\n\"This is a guilty soul, that in the fire\nMust vanish.\'  Hence perdition-doom\'d I rove\nA prey to rankling sorrow in this garb.\"\n     When he had thus fulfill\'d his words, the flame\nIn dolour parted, beating to and fro,\nAnd writhing its sharp horn.  We onward went,\nI and my leader, up along the rock,\nFar as another arch, that overhangs\nThe foss, wherein the penalty is paid\nOf those, who load them with committed sin.\n\n\n\nCANTO XXVIII\n\nWHO, e\'en in words unfetter\'d, might at full\nTell of the wounds and blood that now I saw,\nThough he repeated oft the tale? No tongue\nSo vast a theme could equal, speech and thought\nBoth impotent alike.  If in one band\nCollected, stood the people all, who e\'er\nPour\'d on Apulia\'s happy soil their blood,\nSlain by the Trojans, and in that long war\nWhen of the rings the measur\'d booty made\nA pile so high, as Rome\'s historian writes\nWho errs not, with the multitude, that felt\nThe grinding force of Guiscard\'s Norman steel,\nAnd those the rest, whose bones are gather\'d yet\nAt Ceperano, there where treachery\nBranded th\' Apulian name, or where beyond\nThy walls, O Tagliacozzo, without arms\nThe old Alardo conquer\'d; and his limbs\nOne were to show transpierc\'d, another his\nClean lopt away; a spectacle like this\nWere but a thing of nought, to the\' hideous sight\nOf the ninth chasm.  A rundlet, that hath lost\nIts middle or side stave, gapes not so wide,\nAs one I mark\'d, torn from the chin throughout\nDown to the hinder passage: \'twixt the legs\nDangling his entrails hung, the midriff lay\nOpen to view, and wretched ventricle,\nThat turns th\' englutted aliment to dross.\n     Whilst eagerly I fix on him my gaze,\nHe ey\'d me, with his hands laid his breast bare,\nAnd cried;  \"Now mark how I do rip me!  lo!\nHow is Mohammed mangled!  before me\nWalks Ali weeping, from the chin his face\nCleft to the forelock; and the others all\nWhom here thou seest, while they liv\'d, did sow\nScandal and schism, and therefore thus are rent.\nA fiend is here behind, who with his sword\nHacks us thus cruelly, slivering again\nEach of this ream, when we have compast round\nThe dismal way, for first our gashes close\nEre we repass before him.  But say who\nArt thou, that standest musing on the rock,\nHaply so lingering to delay the pain\nSentenc\'d upon thy crimes?\"--\"Him death not yet,\"\nMy guide rejoin\'d, \"hath overta\'en, nor sin\nConducts to torment; but, that he may make\nFull trial of your state, I who am dead\nMust through the depths of hell, from orb to orb,\nConduct him.  Trust my words, for they are true.\"\n     More than a hundred spirits, when that they heard,\nStood in the foss to mark me, through amazed,\nForgetful of their pangs.  \"Thou, who perchance\nShalt shortly view the sun, this warning thou\nBear to Dolcino:  bid hi");
    strcat(expected_filecontent, "m, if he wish not\nHere soon to follow me, that with good store\nOf food he arm him, lest impris\'ning snows\nYield him a victim to Novara\'s power,\nNo easy conquest else.\"  With foot uprais\'d\nFor stepping, spake Mohammed, on the ground\nThen fix\'d it to depart.  Another shade,\nPierc\'d in the throat, his nostrils mutilate\nE\'en from beneath the eyebrows, and one ear\nLopt off, who with the rest through wonder stood\nGazing, before the rest advanc\'d, and bar\'d\nHis wind-pipe, that without was all o\'ersmear\'d\nWith crimson stain.  \"O thou!\" said \'he, \"whom sin\nCondemns not, and whom erst (unless too near\nResemblance do deceive me) I aloft\nHave seen on Latian ground, call thou to mind\nPiero of Medicina, if again\nReturning, thou behold\'st the pleasant land\nThat from Vercelli slopes to Mercabo;\nAnd there instruct the twain, whom Fano boasts\nHer worthiest sons, Guido and Angelo,\nThat if \'t is giv\'n us here to scan aright\nThe future, they out of life\'s tenement\nShall be cast forth, and whelm\'d under the waves\nNear to Cattolica, through perfidy\nOf a fell tyrant.  \'Twixt the Cyprian isle\nAnd Balearic, ne\'er hath Neptune seen\nAn injury so foul, by pirates done\nOr Argive crew of old.  That one-ey\'d traitor\n(Whose realm there is a spirit here we");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\MINe\\cArRY\\AS\\TIE\\STEAd.TXt");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 5337; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 29: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST29(void)
{
    // informacje o teście
    test_start(29, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[566] = "";

                strcat(expected_filecontent, "ards the height.\n     Reader!  thou markest how my theme doth rise,\nNor wonder therefore, if more artfully\nI prop the structure!  Nearer now we drew,\nArriv\'d\' whence in that part, where first a breach\nAs of a wall appear\'d, I could descry\nA portal, and three steps beneath, that led\nFor inlet there, of different colour each,\nAnd one who watch\'d, but spake not yet a word.\nAs more and more mine eye did stretch its view,\nI mark\'d him seated on the highest step,\nIn visage such, as past my power to bear.\nGrasp\'d in his hand a naked sword, glanc\'d back\nThe rays so t");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\DEPEND\\DRiVE\\BETWEEn\\LISTeN\\dreAM\\LoT.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 565; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 30: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST30(void)
{
    // informacje o teście
    test_start(30, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[303] = "";

                strcat(expected_filecontent, "\nBoth piers and water.  As the Flemings rear\nTheir mound, \'twixt Ghent and Bruges, to chase back\nThe ocean, fearing his tumultuous tide\nThat drives toward them, or the Paduans theirs\nAlong the Brenta, to defend their towns\nAnd castles, ere the genial warmth be felt\nOn Chiarentana\'s top; such were the ");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ON\\WaRM\\sTREAM\\YeS\\caRD.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 302; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 31: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST31(void)
{
    // informacje o teście
    test_start(31, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[177] = "";

                strcat(expected_filecontent, "not, but towards me\nHis mind directing and his face, wherein\nWas dismal shame depictur\'d, thus he spake:\n\"It grieves me more to have been caught by thee\nIn this sad plight, whi");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\RULESoUT\\laNd\\cLASS.tXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 176; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 32: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST32(void)
{
    // informacje o teście
    test_start(32, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[824] = "";

                strcat(expected_filecontent, " written, yet at least\nPainted thou take it in thee, for the cause,\nThat one brings home his staff inwreath\'d with palm.\n     \"I thus:  \"As wax by seal, that changeth not\nIts impress, now is stamp\'d my brain by thee.\nBut wherefore soars thy wish\'d-for speech so high\nBeyond my sight, that loses it the more,\nThe more it strains to reach it?\" --\"To the end\nThat thou mayst know,\" she answer\'d straight, \"the school,\nThat thou hast follow\'d; and how far behind,\nWhen following my discourse, its learning halts:\nAnd mayst behold your art, from the divine\nAs distant, as the disagreement is\n\'Twixt earth and heaven\'s most high and rapturous orb.\"\n     \"I not remember,\" I replied, \"that e\'er\nI was estrang\'d from thee, nor for such fault\nDoth conscience chide me.\"  Smiling she return\'d:\n\"If thou canst, not remember, call to m");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\oN\\WArM\\cONNECT\\SOiL.Tx");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 823; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 33: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST33(void)
{
    // informacje o teście
    test_start(33, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[592] = "";

                strcat(expected_filecontent, "ll\'d all the circuits of the sacred mount;\nAnd, as we journey\'d, on our shoulder smote\nThe early ray.  I follow\'d, stooping low\nMy forehead, as a man, o\'ercharg\'d with thought,\nWho bends him to the likeness of an arch,\nThat midway spans the flood; when thus I heard,\n\"Come, enter here,\" in tone so soft and mild,\nAs never met the ear on mortal strand.\n     With swan-like wings dispread and pointing up,\nWho thus had spoken marshal\'d us along,\nWhere each side of the solid masonry\nThe sloping, walls retir\'d; then mov\'d his plumes,\nAnd fanning us, affirm\'d that those, who mourn,\nAre blessed");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ON\\WON'T\\BOUGHt\\HAS\\HARD.tx");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 591; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 34: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST34(void)
{
    // informacje o teście
    test_start(34, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[6520] = "";

                strcat(expected_filecontent, "e, whom no event surpris\'d,\nTo comfort me thus spake:  \"Let not thy fear\nHarm thee, for power in him, be sure, is none\nTo hinder down this rock thy safe descent.\"\nThen to that sworn lip turning, \" Peace!\"  he cried,\n\"Curs\'d wolf!  thy fury inward on thyself\nPrey, and consume thee!  Through the dark profound\nNot without cause he passes.  So \'t is will\'d\nOn high, there where the great Archangel pour\'d\nHeav\'n\'s vengeance on the first adulterer proud.\"\n     As sails full spread and bellying with the wind\nDrop suddenly collaps\'d, if the mast split;\nSo to the ground down dropp\'d the cruel fiend.\n     Thus we, descending to the fourth steep ledge,\nGain\'d on the dismal shore, that all the woe\nHems in of all the universe.  Ah me!\nAlmighty Justice!  in what store thou heap\'st\nNew pains, new troubles, as I here beheld!\nWherefore doth fault of ours bring us to this?\n     E\'en as a billow, on Charybdis rising,\nAgainst encounter\'d billow dashing breaks;\nSuch is the dance this wretched race must lead,\nWhom more than elsewhere numerous here I found,\nFrom one side and the other, with loud voice,\nBoth roll\'d on weights by main forge of their breasts,\nThen smote together, and each one forthwith\nRoll\'d them back voluble, turning again,\nExclaiming these, \"Why holdest thou so fast?\"\nThose answering, \"And why castest thou away?\"\nSo still repeating their despiteful song,\nThey to the opposite point on either hand\nTravers\'d the horrid circle:  then arriv\'d,\nBoth turn\'d them round, and through the middle space\nConflicting met again.  At sight whereof\nI, stung with grief, thus spake:  \"O say, my guide!\nWhat race is this?  Were these, whose heads are shorn,\nOn our left hand, all sep\'rate to the church?\"\n     He straight replied:  \"In their first life these all\nIn mind were so distorted, that they made,\nAccording to due measure, of their wealth,\nNo use.  This clearly from their words collect,\nWhich they howl forth, at each extremity\nArriving of the circle, where their crime\nContrary\' in kind disparts them.  To the church\nWere separate those, that with no hairy cowls\nAre crown\'d, both Popes and Cardinals, o\'er whom\nAv\'rice dominion absolute maintains.\"\n     I then:  \"Mid such as these some needs must be,\nWhom I shall recognize, that with the blot\nOf these foul sins were stain\'d.\"  He answering thus:\n\"Vain thought conceiv\'st thou.  That ignoble life,\nWhich made them vile before, now makes them dark,\nAnd to all knowledge indiscernible.\nForever they shall meet in this rude shock:\nThese from the tomb with clenched grasp shall rise,\nThose with close-shaven locks.  That ill they gave,\nAnd ill they kept, hath of the beauteous world\nDepriv\'d, and set them at this strife, which needs\nNo labour\'d phrase of mine to set if off.\nNow may\'st thou see, my son!  how brief, how vain,\nThe goods committed into fortune\'s hands,\nFor which the human race keep such a coil!\nNot all the gold, that is beneath the moon,\nOr ever hath been, of these toil-worn souls\nMight purchase rest for one.\"  I thus rejoin\'d:\n     \"My guide! of thee this also would I learn;\nThis fortune, that thou speak\'st of, what it is,\nWhose talons grasp the blessings of the world?\"\n     He thus:  \"O beings blind!  what ignorance\nBesets you?  Now my judgment hear and mark.\nHe, whose transcendent wisdom passes all,\nThe heavens creating, gave them ruling powers\nTo guide them, so that each part shines to each,\nTheir light in equal distribution pour\'d.\nBy similar appointment he ordain\'d\nOver the world\'s bright images to rule.\nSuperintendence of a guiding hand\nAnd general minister, which at due time\nMay change the empty vantages of life\nFrom race to race, from one to other\'s blood,\nBeyond prevention of man\'s wisest care:\nWherefore one nation rises into sway,\nAnother languishes, e\'en as her will\nDecrees, from us conceal\'d, as in the grass\nThe serpent train.  Against her nought avails\nYour utmost wisdom.  She with foresight plans,\nJudges, and carries on her reign, as theirs\nThe other powers divine.  Her changes know\nNore intermission:  by necessity\nShe is made swift, so frequent come who claim\nSuccession in her fa");
    strcat(expected_filecontent, "vours.  This is she,\nSo execrated e\'en by those, whose debt\nTo her is rather praise; they wrongfully\nWith blame requite her, and with evil word;\nBut she is blessed, and for that recks not:\nAmidst the other primal beings glad\nRolls on her sphere, and in her bliss exults.\nNow on our way pass we, to heavier woe\nDescending:  for each star is falling now,\nThat mounted at our entrance, and forbids\nToo long our tarrying.\"  We the circle cross\'d\nTo the next steep, arriving at a well,\nThat boiling pours itself down to a foss\nSluic\'d from its source.  Far murkier was the wave\nThan sablest grain:  and we in company\nOf the\' inky waters, journeying by their side,\nEnter\'d, though by a different track, beneath.\nInto a lake, the Stygian nam\'d, expands\nThe dismal stream, when it hath reach\'d the foot\nOf the grey wither\'d cliffs.  Intent I stood\nTo gaze, and in the marish sunk descried\nA miry tribe, all naked, and with looks\nBetok\'ning rage.  They with their hands alone\nStruck not, but with the head, the breast, the feet,\nCutting each other piecemeal with their fangs.\n     The good instructor spake; \"Now seest thou, son!\nThe souls of those, whom anger overcame.\nThis too for certain know, that underneath\nThe water dwells a multitude, whose sighs\nInto these bubbles make the surface heave,\nAs thine eye tells thee wheresoe\'er it turn.\nFix\'d in the slime they say: \"Sad once were we\nIn the sweet air made gladsome by the sun,\nCarrying a foul and lazy mist within:\nNow in these murky settlings are we sad.\"\nSuch dolorous strain they gurgle in their throats.\nBut word distinct can utter none.\"  Our route\nThus compass\'d we, a segment widely stretch\'d\nBetween the dry embankment, and the core\nOf the loath\'d pool, turning meanwhile our eyes\nDownward on those who gulp\'d its muddy lees;\nNor stopp\'d, till to a tower\'s low base we came.\n\n\n\nCANTO VIII\n\nMY theme pursuing, I relate that ere\nWe reach\'d the lofty turret\'s base, our eyes\nIts height ascended, where two cressets hung\nWe mark\'d, and from afar another light\nReturn the signal, so remote, that scarce\nThe eye could catch its beam.  I turning round\nTo the deep source of knowledge, thus inquir\'d:\n\"Say what this means?  and what that other light\nIn answer set?  what agency doth this?\"\n     \"There on the filthy waters,\" he replied,\n\"E\'en now what next awaits us mayst thou see,\nIf the marsh-gender\'d fog conceal it not.\"\n     Never was arrow from the cord dismiss\'d,\nThat");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ON\\DEATH\\Lift\\EqUATE\\WHeeL");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 6519; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 35: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST35(void)
{
    // informacje o teście
    test_start(35, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[631] = "";

                strcat(expected_filecontent, "dar\'d on earth.\"  I then:\n\"If soul that to the verge of life delays\nRepentance, linger in that lower space,\nNor hither mount, unless good prayers befriend,\nHow chanc\'d admittance was vouchsaf\'d to him?\"\n     \"When at his glory\'s topmost height,\" said he,\n\"Respect of dignity all cast aside,\nFreely He fix\'d him on Sienna\'s plain,\nA suitor to  redeem his suff\'ring friend,\nWho languish\'d in the prison-house of Charles,\nNor for his sake refus\'d through every vein\nTo tremble.  More I will not say; and dark,\nI know, my words are, but thy neighbours soon\nShall help thee to a comment on the text.\nThis is the work, that from these l");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\MINE\\TYPE\\CHeCK");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 630; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 36: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST36(void)
{
    // informacje o teście
    test_start(36, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[5121] = "";

                strcat(expected_filecontent, "wail,\nAnd soon as they had reach\'d us, all the three\nWhirl\'d round together in one restless wheel.\nAs naked champions, smear\'d with slippery oil,\nAre wont intent to watch their place of hold\nAnd vantage, ere in closer strife they meet;\nThus each one, as he wheel\'d, his countenance\nAt me directed, so that opposite\nThe neck mov\'d ever to the twinkling feet.\n     \"If misery of this drear wilderness,\"\nThus one began, \"added to our sad cheer\nAnd destitute, do call forth scorn on us\nAnd our entreaties, let our great renown\nIncline thee to inform us who thou art,\nThat dost imprint with living feet unharm\'d\nThe soil of Hell.  He, in whose track thou see\'st\nMy steps pursuing, naked though he be\nAnd reft of all, was of more high estate\nThan thou believest; grandchild of the chaste\nGualdrada, him they Guidoguerra call\'d,\nWho in his lifetime many a noble act\nAchiev\'d, both by his wisdom and his sword.\nThe other, next to me that beats the sand,\nIs Aldobrandi, name deserving well,\nIn the\' upper world, of honour; and myself\nWho in this torment do partake with them,\nAm Rusticucci, whom, past doubt, my wife\nOf savage temper, more than aught beside\nHath to this evil brought.\"  If from the fire\nI had been shelter\'d, down amidst them straight\nI then had cast me, nor my guide, I deem,\nWould have restrain\'d my going; but that fear\nOf the dire burning vanquish\'d the desire,\nWhich made me eager of their wish\'d embrace.\n     I then began:  \"Not scorn, but grief much more,\nSuch as long time alone can cure, your doom\nFix\'d deep within me, soon as this my lord\nSpake words, whose tenour taught me to expect\nThat such a race, as ye are, was at hand.\nI am a countryman of yours, who still\nAffectionate have utter\'d, and have heard\nYour deeds and names renown\'d.  Leaving the gall\nFor the sweet fruit I go, that a sure guide\nHath promis\'d to me.  But behooves, that far\nAs to the centre first I downward tend.\"\n     \"So may long space thy spirit guide thy limbs,\"\nHe answer straight return\'d; \"and so thy fame\nShine bright, when thou art gone; as thou shalt tell,\nIf courtesy and valour, as they wont,\nDwell in our city, or have vanish\'d clean?\nFor one amidst us late condemn\'d to wail,\nBorsiere, yonder walking with his peers,\nGrieves us no little by the news he brings.\"\n     \"An upstart multitude and sudden gains,\nPride and excess, O Florence! have in thee\nEngender\'d, so that now in tears thou mourn\'st!\"\nThus cried I with my face uprais\'d, and they\nAll three, who for an answer took my words,\nLook\'d at each other, as men look when truth\nComes to their ear.  \"If thou at other times,\"\nThey all at once rejoin\'d, \"so easily\nSatisfy those, who question, happy thou,\nGifted with words, so apt to speak thy thought!\nWherefore if thou escape this darksome clime,\nReturning to behold the radiant stars,\nWhen thou with pleasure shalt retrace the past,\nSee that of us thou speak among mankind.\"\n     This said, they broke the circle, and so swift\nFled, that as pinions seem\'d their nimble feet.\n     Not in so short a time might one have said\n\"Amen,\" as they had vanish\'d. Straight my guide\nPursu\'d his track.  I follow\'d; and small space\nHad we pass\'d onward, when the water\'s sound\nWas now so near at hand, that we had scarce\nHeard one another\'s speech for the loud din.\n     E\'en as the river, that holds on its course\nUnmingled, from the mount of Vesulo,\nOn the left side of Apennine, toward\nThe east, which Acquacheta higher up\nThey call, ere it descend into the vale,\nAt Forli by that name no longer known,\nRebellows o\'er Saint Benedict, roll\'d on\nFrom the\' Alpine summit down a precipice,\nWhere space enough to lodge a thousand spreads;\nThus downward from a craggy steep we found,\nThat this dark wave resounded, roaring loud,\nSo that the ear its clamour soon had stunn\'d.\n     I had a cord that brac\'d my girdle round,\nWherewith I erst had thought fast bound to take\nThe painted leopard.  This when I had all\nUnloosen\'d from me (so my master bade)\nI gather\'d up, and stretch\'d it forth to him.\nThen to the right he turn\'d, and from the brink\nStanding few paces distant, cast it down\nInto the dee");
    strcat(expected_filecontent, "p abyss.  \"And somewhat strange,\"\nThus to myself I spake, \"signal so strange\nBetokens, which my guide with earnest eye\nThus follows.\"  Ah! what caution must men use\nWith those who look not at the deed alone,\nBut spy into the thoughts with subtle skill!\n     \"Quickly shall come,\" he said, \"what I expect,\nThine eye discover quickly, that whereof\nThy thought is dreaming.\"  Ever to that truth,\nWhich but the semblance of a falsehood wears,\nA man, if possible, should bar his lip;\nSince, although blameless, he incurs reproach.\nBut silence here were vain; and by these notes\nWhich now I sing, reader!  I swear to thee,\nSo may they favour find to latest times!\nThat through the gross and murky air I spied\nA shape come swimming up, that might have quell\'d\nThe stoutest heart with wonder, in such guise\nAs one returns, who hath been down to loose\nAn anchor grappled fast against some rock,\nOr to aught else that in the salt wave lies,\nWho upward springing close draws in his feet.\n\n\n\nCANTO XVII\n\n\"LO! the fell monster with the de");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ON\\BLaCK\\be\\FALL.tXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 5120; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 37: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST37(void)
{
    // informacje o teście
    test_start(37, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[564] = "";

                strcat(expected_filecontent, "re.]  Hence Milton:\n               Death\n        Grinn\'d horrible a ghastly smile.\n               P. L. b. ii. 845.\n\nv. 46.  As cranes.]  This simile is imitated by Lorenzo de\nMedici, in his Ambra, a poem, first published by Mr. Roscoe, in\nthe  Appendix to his Life of Lorenzo.\n        Marking the tracts of air, the clamorous cranes\n        Wheel their due flight in varied ranks descried:\n        And each with outstretch\'d neck his rank maintains\n        In marshal\'d order through th\' ethereal void.\n               Roscoe, v. i. c. v. p. 257.  4to edit.\nCompa");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ON\\KnEW.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 563; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 38: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST38(void)
{
    // informacje o teście
    test_start(38, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[8012] = "";

                strcat(expected_filecontent, "in his Essay on Wit and Humour, p. 4. s. 3.\n\nCANTO XI\n\nv. 1.  0 thou Mighty Father.] The first four lines are borrowed\nby Pulci, Morg. Magg.  c. vi.\nDante, in his \'Credo,\' has again versified the Lord\'s prayer.\n\nv. 58.  I was of Latinum.] Omberto, the son of Guglielino\nAldobrandeseo, Count of Santafiore, in the territory of Sienna\nHis arrogance provoked his countrymen to such a pitch of fury\nagainst him, that he was murdered by them at Campagnatico.\n\nv. 79.  Oderigi.]  The illuminator, or miniature painter, a\nfriend of Giotto and Dante\n\nv. 83.  Bolognian Franco.]  Franco of Bologna, who is said to\nhave been a pupil of Oderigi\'s.\n\nv. 93.  Cimabue.]  Giovanni Cimabue, the restorer of painting,\nwas born at Florence, of a noble family, in 1240, and died in\n1300. The passage in the text is an illusion to his epitaph:\n\nCredidit ut Cimabos picturae castra tenere,\nSic tenuit vivens:  nunc tenet astra poli.\n\nv. 95.  The cry is Giotto\'s.]  In Giotto we have a proof at how\nearly a period the fine arts were encouraged in Italy.  His\ntalents were discovered by Cimabue, while he was tending sheep\nfor his father in the neighbourhood of Florence, and he was\nafterwards patronized by Pope Benedict XI  and Robert King of\nNaples, and enjoyed the society and friendship of Dante, whose\nlikeness he has transmitted to posterity. He  died in 1336, at\nthe age of 60.\n\nv. 96.  One Guido from the other.]  Guido Cavalcanti, the friend\nof our Poet, (see Hell, Canto X. 59.) had eclipsed the literary\nfame of Guido Guinicelli, of a noble family in Bologna, whom we\nshall meet with in the twenty-sixth Canto and of whom frequent\nmention is made by our Poet in his Treatise de Vulg. Eloq.\nGuinicelli died in 1276.  Many of Cavalcanti\'s writings, hitherto\nin MS. are now publishing at Florence\" Esprit des Journaux, Jan.\n1813.\n\nv. 97.  He perhaps is born.]  Some imagine, with much\nprobability, that Dante here augurs the greatness of his own\npoetical reputation.  Others have fancied that he prophesies the\nglory of Petrarch.  But Petrarch was not yet born.\n\nv. 136.  suitor.]  Provenzano salvani humbled himself so far for\nthe  sake of one of his friends, who was detained in captivity by\nCharles I of Sicily, as personally to supplicate the people of\nSienna to contribute the sum required by the king for his ransom:\n\nand this act of self-abasement atoned for his general ambition\nand pride.\n\nv. 140.  Thy neighbours soon.]  \"Thou wilt know in the time of\nthy banishment, which is near at hand, what it is to solicit\nfavours of others and \'tremble through every vein,\' lest they\nshould be refused  thee.\"\n\nCANTO XII\n\nv. 26.  The Thymbraen god.]  Apollo\n\nSi modo, quem perhibes, pater est Thymbraeus Apollo. Virg. Georg.\niv. 323.\n\nv. 37.  Mars.]\n\nWith such a grace,\nThe giants that attempted to scale heaven\nWhen they lay dead on the Phlegren plain\nMars did appear to Jove.\nBeaumont and Fletcher, The Prophetess, a. 2. s. 3.\n\nv. 42.  O Rehoboam.]  1 Kings, c. xii.  18.\n\nv. 46.  A1cmaeon.] Virg. Aen. l. vi. 445, and Homer, Od. xi. 325.\n\nv. 48.  Sennacherib.]  2 Kings, c.  xix.  37.\n\nv. 58.  What master of the pencil or the style.]\n--inimitable on earth\nBy model, or by shading pencil drawn.\nMilton, P. L. b. iii.  509.\n\nv. 94.  The chapel stands.]  The church of San Miniato in\nFlorence situated on a height that overlooks the Arno, where it\nis crossed by the bridge Rubaconte, so called from Messer\nRubaconte da Mandelia, of Milan chief magistrate of Florence, by\nwhom the bridge was founded in 1237.  See G. Villani, 1. vi. c.\n27.\n\nv.  96.  The well-guided city] This is said ironically of\nFlorence.\n\nv. 99.  The registry.]  In allusion to certain instances of fraud\ncommitted with respect to the public accounts and measures See\nParadise Canto XVI. 103.\n\nCANTO XIII\n\nv. 26.  They have no wine.]  John, ii.  3. These words of the\nVirgin are referred to as an instance of charity.\n\nv. 29.  Orestes]  Alluding to his friendship with Pylades\n\nv. 32.  Love ye those have wrong\'d you.]  Matt. c. v. 44.\n\nv. 33.  The scourge.]  \"The chastisement of envy consists in\nhearing examples of the opposite virtue");
    strcat(expected_filecontent, ", charity.  As a curb and\nrestraint on this vice, you will presently hear very different\nsounds, those of threatening and punishment.\"\n\nv. 87.  Citizens Of one true city.]\n\"For here we have no continuing city, but we seek to come.\" Heb.\nC. xiii. 14.\n\nv. 101.  Sapia.]  A lady of Sienna, who, living in exile at\nColle, was so overjoyed at a defeat which her countrymen\nsustained near that place that she declared nothing more was\nwanting to make her die contented.\n\nv. 114.  The merlin.]  The story of the merlin is that having\nbeen induced by a gleam of fine weather in the winter to escape\nfrom his master, he was soon oppressed by the rigour of the\nseason.\n\nv. 119.  The hermit Piero.]  Piero Pettinagno, a holy hermit of\nFlorence.\n\nv. 141.  That vain multitude.]  The Siennese.  See Hell, Canto\nXXIX. 117. \"Their acquisition of Telamone, a seaport on the\nconfines of the Maremma, has led them to conceive hopes of\nbecoming a naval power: but this scheme will prove as chimerical\nas their former plan for the discovery of a subterraneous stream\nunder their city.\"  Why they gave the appellation of Diana to the\nimagined stream, Venturi says he leaves it to the antiquaries of\nSienna to conjecture.\n\nCANTO XIV\n\nv. 34.  Maim\'d of Pelorus.]  Virg. Aen. 1. iii. 414.\n\n--a hill\nTorn from Pelorus\nMilton P. L. b. i. 232\n\nv. 45.  \'Midst brute swine.]  The people of Casentino.\n\nv. 49.  Curs.]  The Arno leaves Arezzo about four miles to the\nleft.\n\nv. 53.  Wolves.]  The Florentines.\n\nv. 55.  Foxes.]  The Pisans\n\nv. 61.  Thy grandson.]  Fulcieri de\' Calboli, grandson of\nRinieri de\' Calboli, who is here spoken to.  The atrocities\npredicted came to pass in 1302.  See G. Villani, 1.  viii c. 59\n\nv. 95.  \'Twixt Po, the mount, the Reno, and the shore.]  The\nboundaries of Romagna.\n\nv. 99.  Lizio.]  Lizio da Valbona, introduced into Boccaccio\'s\nDecameron, G. v. N, 4.\n\nv. 100.  Manardi, Traversaro, and Carpigna.1 Arrigo Manardi of\nFaenza, or as some say, of Brettinoro, Pier Traversaro, lord of\nRavenna, and Guido di Carpigna of Montefeltro.\n\nv. 102.  In Bologna the low artisan.]  One who had been a\nmechanic named Lambertaccio, arrived at almost supreme power in\nBologna.\n\nv. 103.  Yon Bernardin.]  Bernardin di Fosco, a man of low\norigin but great talents, who governed at Faenza.\n\nv. 107.  Prata.]  A place between Faenza and Ravenna\n\nv. 107.  Of Azzo him.] Ugolino of the Ubaldini family in Tuscany\nHe is recounted among the poets by Crescimbeni and Tiraboschi.\n\nv. 108.  Tignoso.] Federigo Tignoso of Rimini.\n\nv. 109.  Traversaro\'s house and Anastagio\'s.]  Two noble families\nof Ravenna.  She to whom Dryden has given the name of Honoria, in\nthe fable so admirably paraphrased from Boccaccio, was of the\nformer: her lover and the specter were of the Anastagi family.\n\nv. 111.  The ladies, &c.]  These two lines express the true\nspirit of chivalry.  \"Agi\" is understood by the commentators whom\nI have consulted,to mean \"the ease procured for others by the\nexertions of knight-errantry.\"  But surely it signifies the\nalternation of ease with labour.\n\nv. 114.  O Brettinoro.]  A beautifully situated castle in\nRomagna, the hospitable residence of Guido del Duca, who is here\nspeaking.\n\nv. 118.  Baynacavallo.]  A castle between Imola and Ravenna\n\nv. 118.  Castracaro ill\nAnd Conio worse.]  Both in Romagna.\n\nv. 121.  Pagani.]  The Pagani were lords of Faenza and Imola. One\nof them Machinardo, was named the Demon, from his treachery.\nSee Hell, Canto XXVII. 47, and Note.\n\nv. 124.  Hugolin.]  Ugolino Ubaldini, a noble and virtuous person\nin Faenza, who, on account of his age probably, was not likely to\nleave any offspring behind him.  He is enumerated among the poets\nby Crescimbeni, and Tiraboschi.  Mr. Matthias\'s edit. vol. i. 143\n\nv. 136.  Whosoever finds Will slay me.] The words of Cain, Gen.\ne. iv. 14.\n\nv. 142.  Aglauros.]  Ovid, Met.  I, ii.  fate. 12.\n\nv. 145.  There was the galling bit.]  Referring to ");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\on\\pRODuCT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 8011; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 39: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST39(void)
{
    // informacje o teście
    test_start(39, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[802] = "";

                strcat(expected_filecontent, "Ariadne, and\nmoving round m opposite directions.\"\n\nv. 21.  The Chiava.]  See Hell, Canto XXIX. 45.\n\nv. 29.  That luminary.]  Thomas Aquinas.\n\nv. 31.  One ear.]  \"Having solved one of thy questions, I proceed\nto answer the other.  Thou thinkest, then, that Adam and Christ\nwere both endued with all the perfection of which the human\nnature is capable and therefore wonderest at what has been said\nconcerning Solomon\"\n\nv. 48.  That.]  \"Things corruptible and incorruptible, are only\nemanations from the archetypal idea residing in the Divine mind.\"\n\nv. 52.  His brightness.]  The Word: the Son of God.\n\nv. 53.  His love triune with them.]  The Holy Ghost.\n\nv. 55.  New existences.]  Angels and human souls.\n\nv. 57.  The lowest powers.]  Irrational life and brute matter.\n\nv. 62.  Their wax and that whic");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\oN\\SUCh.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 801; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 40: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST40(void)
{
    // informacje o teście
    test_start(40, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[6221] = "";

                strcat(expected_filecontent, "igaglia; and \'t will seem\nNo longer new or strange to thee to hear,\nThat families fail, when cities have their end.\nAll things, that appertain t\' ye, like yourselves,\nAre mortal: but mortality in some\nYe mark not, they endure so long, and you\nPass by so suddenly.  And as the moon\nDoth, by the rolling of her heav\'nly sphere,\nHide and reveal the strand unceasingly;\nSo fortune deals with Florence.  Hence admire not\nAt what of them I tell thee, whose renown\nTime covers, the first Florentines.  I saw\nThe Ughi, Catilini and Filippi,\nThe Alberichi, Greci and Ormanni,\nNow in their wane, illustrious citizens:\nAnd great as ancient, of Sannella him,\nWith him of Arca saw, and Soldanieri\nAnd Ardinghi, and Bostichi.  At the poop,\nThat now is laden with new felony,\nSo cumb\'rous it may speedily sink the bark,\nThe Ravignani sat, of whom is sprung\nThe County Guido, and whoso hath since\nHis title from the fam\'d Bellincione ta\'en.\nFair governance was yet an art well priz\'d\nBy him of Pressa:  Galigaio show\'d\nThe gilded hilt and pommel, in his house.\nThe column, cloth\'d with verrey, still was seen\nUnshaken:  the Sacchetti still were great,\nGiouchi, Sifanti, Galli and Barucci,\nWith them who blush to hear the bushel nam\'d.\nOf the Calfucci still the branchy trunk\nWas in its strength: and to the curule chairs\nSizii and Arigucci yet were drawn.\nHow mighty them I saw, whom since their pride\nHath undone!  and in all her goodly deeds\nFlorence was by the bullets of bright gold\nO\'erflourish\'d.  Such the sires of those, who now,\nAs surely as your church is vacant, flock\nInto her consistory, and at leisure\nThere stall them and grow fat.  The o\'erweening brood,\nThat plays the dragon after him that flees,\nBut unto such, as turn and show the tooth,\nAy or the purse, is gentle as a lamb,\nWas on its rise, but yet so slight esteem\'d,\nThat Ubertino of Donati grudg\'d\nHis father-in-law should yoke him to its tribe.\nAlready Caponsacco had descended\nInto the mart from Fesole:  and Giuda\nAnd Infangato were good citizens.\nA thing incredible I tell, tho\' true:\nThe gateway, named from those of Pera, led\nInto the narrow circuit of your walls.\nEach one, who bears the sightly quarterings\nOf the great Baron (he whose name and worth\nThe festival of Thomas still revives)\nHis knighthood and his privilege retain\'d;\nAlbeit one, who borders them With gold,\nThis day is mingled with the common herd.\nIn Borgo yet the Gualterotti dwelt,\nAnd Importuni: well for its repose\nHad it still lack\'d of newer neighbourhood.\nThe house, from whence your tears have had their spring,\nThrough the just anger that hath murder\'d ye\nAnd put a period to your gladsome days,\nWas honour\'d, it, and those consorted with it.\nO Buondelmonte!  what ill counseling\nPrevail\'d on thee to break the plighted bond\nMany, who now are weeping, would rejoice,\nHad God to Ema giv\'n thee, the first time\nThou near our city cam\'st.  But so was doom\'d:\nOn that maim\'d stone set up to guard the bridge,\nAt thy last peace, the victim, Florence!  fell.\nWith these and others like to them, I saw\nFlorence in such assur\'d tranquility,\nShe had no cause at which to grieve: with these\nSaw her so glorious and so just, that ne\'er\nThe lily from the lance had hung reverse,\nOr through division been with vermeil dyed.\"\n\n\n\nCANTO XVII\n\nSuch as the youth, who came to Clymene\nTo certify himself of that reproach,\nWhich had been fasten\'d on him, (he whose end\nStill makes the fathers chary to their sons,\nE\'en such was I; nor unobserv\'d was such\nOf Beatrice, and that saintly lamp,\nWho had erewhile for me his station mov\'d;\nWhen thus by lady:  \"Give thy wish free vent,\nThat it may issue, bearing true report\nOf the mind\'s impress; not that aught thy words\nMay to our knowledge add, but to the end,\nThat thou mayst use thyself to own thy thirst\nAnd men may mingle for thee when they hear.\"\n     \"O plant!  from whence I spring! rever\'d and lov\'d!\nWho soar\'st so high a pitch, thou seest as clear,\nAs earthly thought determines two obtuse\nIn one triangle not contain\'d, so clear\nDost see contingencies, ere in themselves\nExistent, looking at the point whereto\nAll ");
    strcat(expected_filecontent, "times are present, I, the whilst I scal\'d\nWith Virgil the soul purifying mount,\nAnd visited the nether world of woe,\nTouching my future destiny have heard\nWords grievous, though I feel me on all sides\nWell squar\'d to fortune\'s blows.  Therefore my will\nWere satisfied to know the lot awaits me,\nThe arrow, seen beforehand, slacks its flight.\"\n     So said I to the brightness, which erewhile\nTo me had spoken, and my will declar\'d,\nAs Beatrice will\'d, explicitly.\nNor with oracular response obscure,\nSuch, as or ere the Lamb of God was slain,\nBeguil\'d the credulous nations; but, in terms\nPrecise and unambiguous lore, replied\nThe spirit of paternal love, enshrin\'d,\nYet in his smile apparent; and thus spake:\n\"Contingency, unfolded not to view\nUpon the tablet of your mortal mold,\nIs all depictur\'d in the\' eternal sight;\nBut hence deriveth not necessity,\nMore then the tall ship, hurried down the flood,\nDoth from the vision, that reflects the scene.\nFrom thence, as to the ear sweet harmony\nFrom organ comes, so comes before mine eye\nThe time prepar\'d for thee.  Such as driv\'n out\nFrom Athens, by his cruel stepdame\'s wiles,\nHippolytus departed, such must thou\nDepart from Florence.  This they wish, and this\nContrive, and will ere long effectuate, there,\nWhere gainful merchandize is made of Christ,\nThroughout the livelong day.  The common cry,\nWill, as \'t is ever wont, affix the blame\nUnto the party injur\'d:  but the truth\nShall, in the vengeance it dispenseth, find\nA faithful witness.  Thou shall leave each thing\nBelov\'d most dearly:  this is the first shaft\nShot from the bow of exile.  Thou shalt prove\nHow salt the savour is of other\'s bread,\nHow hard the passage to descend and climb\nBy other\'s stairs, But that shall gall thee most\nWill he the worthless and vile company,\nWith whom thou must be thrown into these straits.\nFor all ungrateful, impious all and mad,\nShall turn \'gainst thee:  but in a little while\nTheirs and not thine shall be the crimson\'d brow\nTheir course shall so evince their brutishness\nT\' have ta\'en thy stand apart shall well become thee.\n     \"First refuge thou must find, first place ");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ON\\STUDy");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 6220; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 41: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST41(void)
{
    // informacje o teście
    test_start(41, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[6128] = "";

                strcat(expected_filecontent, "m all.  But if thou know\'st and canst,\nDirect us, how we soonest may arrive,\nWhere Purgatory its true beginning takes.\"\n     He answer\'d thus:  \"We have no certain place\nAssign\'d us: upwards I may go or round,\nFar as I can, I join thee for thy guide.\nBut thou beholdest now how day declines:\nAnd upwards to proceed by night, our power\nExcels: therefore it may be well to choose\nA place of pleasant sojourn.  To the right\nSome spirits sit apart retir\'d.  If thou\nConsentest, I to these will lead thy steps:\nAnd thou wilt know them, not without delight.\"\n     \"How chances this?\"  was answer\'d;  \"who so wish\'d\nTo ascend by night, would he be thence debarr\'d\nBy other, or through his own weakness fail?\"\n     The good Sordello then, along the ground\nTrailing his finger, spoke: \"Only this line\nThou shalt not overpass, soon as the sun\nHath disappear\'d; not that aught else impedes\nThy going upwards, save the shades of night.\nThese with the wont of power perplex the will.\nWith them thou haply mightst return beneath,\nOr to and fro around the mountain\'s side\nWander, while day is in the horizon shut.\"\n     My master straight, as wond\'ring at his speech,\nExclaim\'d:  \"Then lead us quickly, where thou sayst,\nThat, while we stay, we may enjoy delight.\"\n     A little space we were remov\'d from thence,\nWhen I perceiv\'d the mountain hollow\'d out.\nEv\'n as large valleys hollow\'d out on earth,\n     \"That way,\" the\' escorting spirit cried, \"we go,\nWhere in a bosom the high bank recedes:\nAnd thou await renewal of the day.\"\n     Betwixt the steep and plain a crooked path\nLed us traverse into the ridge\'s side,\nWhere more than half the sloping edge expires.\nRefulgent gold, and silver thrice refin\'d,\nAnd scarlet grain and ceruse, Indian wood\nOf lucid dye serene, fresh emeralds\nBut newly broken, by the herbs and flowers\nPlac\'d in that fair recess, in color all\nHad been surpass\'d, as great surpasses less.\nNor nature only there lavish\'d her hues,\nBut of the sweetness of a thousand smells\nA rare and undistinguish\'d fragrance made.\n     \"Salve Regina,\" on the grass and flowers\nHere chanting I beheld those spirits sit\nWho not beyond the valley could be seen.\n     \"Before the west\'ring sun sink to his bed,\"\nBegan the Mantuan, who our steps had turn\'d,\n     \"\'Mid those desires not that I lead ye on.\nFor from this eminence ye shall discern\nBetter the acts and visages of all,\nThan in the nether vale among them mix\'d.\nHe, who sits high above the rest, and seems\nTo have neglected that he should have done,\nAnd to the others\' song moves not his lip,\nThe Emperor Rodolph call, who might have heal\'d\nThe wounds whereof fair Italy hath died,\nSo that by others she revives but slowly,\nHe, who with kindly visage comforts him,\nSway\'d in that country, where the water springs,\nThat Moldaw\'s river to the Elbe, and Elbe\nRolls to the ocean: Ottocar his name:\nWho in his swaddling clothes was of more worth\nThan Winceslaus his son, a bearded man,\nPamper\'d with rank luxuriousness and ease.\nAnd that one with the nose depress, who close\nIn counsel seems with him of gentle look,\nFlying expir\'d, with\'ring the lily\'s flower.\nLook there how he doth knock against his breast!\nThe other ye behold, who for his cheek\nMakes of one hand a couch, with frequent sighs.\nThey are the father and the father-in-law\nOf Gallia\'s bane: his vicious life they know\nAnd foul; thence comes the grief that rends them thus.\n     \"He, so robust of limb, who measure keeps\nIn song, with him of feature prominent,\nWith ev\'ry virtue bore his girdle brac\'d.\nAnd if that stripling who behinds him sits,\nKing after him had liv\'d, his virtue then\nFrom vessel to like vessel had been pour\'d;\nWhich may not of the other heirs be said.\nBy James and Frederick his realms are held;\nNeither the better heritage obtains.\nRarely into the branches of the tree\nDoth human worth mount up; and so ordains\nHe who bestows it, that as his free gift\nIt may be call\'d.  To Charles my words apply\nNo less than to his brother in the song;\nWhich Pouille and Provence now with grief confess.\nSo much that plant degenerates from its seed,\nAs more than Beatrice");
    strcat(expected_filecontent, " and Margaret\nCostanza still boasts of her valorous spouse.\n     \"Behold the king of simple life and plain,\nHarry of England, sitting there alone:\nHe through his branches better issue spreads.\n     \"That one, who on the ground beneath the rest\nSits lowest, yet his gaze directs aloft,\nUs William, that brave Marquis, for whose cause\nThe deed of Alexandria and his war\nMakes Conferrat and Canavese weep.\"\n\n\n\nCANTO VIII\n\nNow was the hour that wakens fond desire\nIn men at sea, and melts their thoughtful heart,\nWho in the morn have bid sweet friends farewell,\nAnd pilgrim newly on his road with love\nThrills, if he hear the vesper bell from far,\nThat seems to mourn for the expiring day:\nWhen I, no longer taking heed to hear\nBegan, with wonder, from those spirits to mark\nOne risen from its seat, which with its hand\nAudience implor\'d. Both palms it join\'d and rais\'d,\nFixing its steadfast gaze towards the east,\nAs telling God, \"I care for naught beside.\"\n     \"Te Lucis Ante,\" so devoutly then\nCame from its lip, and in so soft a strain,\nThat all my sense in ravishment was lost.\nAnd the rest after, softly and devout,\nFollow\'d through all the hymn, with upward gaze\nDirected to the bright supernal wheels.\n     Here, reader!  for the truth makes thine eyes keen:\nFor of so subtle texture is this veil,\nThat thou with ease mayst pass it through unmark\'d.\n     I saw that gentle band silently next\nLook up, as if in expectation held,\nPale and in lowly guise; and from on high\nI saw forth issuing descend beneath\nTwo angels with two flame-illumin\'d swords,\nBroken and mutilated at their points.\nGreen as the tender leaves but newly born,\nTheir vesture was, the which by wings as green\nBeaten, they drew behind them, fann\'d in air.\nA little over us one took his stand,\nThe other lighted on the\' Opposing hill,\nSo that the troop were in the midst contain\'d.\n     Well I descried the whiteness on their heads;\nBut in their visages the dazzled eye\nWas lost, as faculty that by too much\nIs overpower\'d.  \"From Mary\'s bosom both\nAre come,\"");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ON\\DEaR.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 6127; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 42: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST42(void)
{
    // informacje o teście
    test_start(42, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[740] = "";

                strcat(expected_filecontent, "k to it well:\nTake heed thou cleanse thee of their ways.  For thee\nThy fortune hath such honour in reserve,\nThat thou by either party shalt be crav\'d\nWith hunger keen:  but be the fresh herb far\nFrom the goat\'s tooth.  The herd of Fesole\nMay of themselves make litter, not touch the plant,\nIf any such yet spring on their rank bed,\nIn which the holy seed revives, transmitted\nFrom those true Romans, who still there remain\'d,\nWhen it was made the nest of so much ill.\"\n     \"Were all my wish fulfill\'d,\" I straight replied,\n\"Thou from the confines of man\'s nature yet\nHadst not been driven forth; for in my mind\nIs fix\'d, and now strikes full upon my heart\nThe dear, benign, paternal image, such\nAs thine was, when so lately thou didst tea");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ON\\FRUiT.tX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 739; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 43: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST43(void)
{
    // informacje o teście
    test_start(43, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[6145] = "";

                strcat(expected_filecontent, "an of\ncourteous and elegant manners, and of great readiness in\nconversation.\"  Dec. Giorn. i. Nov. 8.\n\nv. 84.  When thou with pleasure shalt retrace the past.]\n        Quando ti giovera dicere io fui.\nSo Tasso, G. L. c. xv. st. 38.\n        Quando mi giovera narrar altrui\n        Le novita vedute, e dire; io fui.\n\nv. 121.  Ever to that truth.]  This memorable apophthegm is\nrepeated by Luigi Pulci and Trissino.\n\n        Sempre a quel ver, ch\' ha faccia di menzogna\n        E piu senno tacer la lingua cheta\n        Che spesso senza colpa fa vergogna.\n               Morgante. Magg.  c. xxiv.\n\n               La verita, che par mensogna\n        Si dovrebbe tacer dall\' uom ch\'e saggio.\n               Italia. Lib. C. xvi.\n\nCANTO XVII\n\nv. 1.  The fell monster.]  Fraud.\n\nv. 53.  A pouch.]  A purse, whereon the armorial bearings of each\nwere emblazoned.  According to Landino, our poet implies that the\nusurer can pretend to no other honour, than such as he derives\nfrom his purse and his family.\n\nv. 57.  A yellow purse.]  The arms of the Gianfigliazzi of\nFlorence.\n\nv. 60.  Another.]  Those of the Ubbriachi, another Florentine\nfamily of high distinction.\n\nv. 62.  A fat and azure swine.]  The arms of the Scrovigni a\nnoble family of Padua.\n\nv. 66.  Vitaliano.]  Vitaliano del Dente, a Paduan.\n\nv. 69.  That noble knight.]  Giovanni Bujamonti, a Florentine\nusurer, the most infamous of his time.\n\nCANTO XVIII\n\nv. 28.  With us beyond.]  Beyond the middle point they tended the\nsame way with us, but their pace was quicker than ours.\n\nv. 29.  E\'en thus the Romans.]  In the year 1300, Pope Boniface\nVIII., to remedy the inconvenience occasioned by the press of\npeople who were passing over the bridge of St. Angelo during the\ntime of the Jubilee, caused it to be divided length wise by a\npartition, and ordered, that all those who were going to St.\nPeter\'s should keep one side, and those returning the other.\n\nv. 50.  Venedico.]  Venedico Caccianimico, a Bolognese, who\nprevailed on his sister Ghisola to prostitute herself to Obizzo\nda  Este, Marquis of Ferrara, whom we have seen among the\ntyrants, Canto XII.\n\nv. 62.  To answer Sipa.]  He denotes Bologna by its situation\nbetween the rivers Savena to the east, and Reno to the west of\nthat city; and by a peculiarity of dialect, the use of the\naffirmative sipa instead of si.\n\nv. 90.  Hypsipyle.]  See Appolonius Rhodius, l. i. and Valerius\nFlaccus l.ii.  Hypsipyle deceived the other women by concealing\nher father Thoas, when they had agreed to put all their males to\ndeath.\n\nv. 120.  Alessio.]  Alessio, of an ancient and considerable\nfamily in Lucca, called the Interminei.\n\nv. 130.  Thais.]  He alludes to that passage in the Eunuchus of\nTerence where Thraso asks if Thais was obliged to him for the\npresent he had sent her, and Gnatho replies, that she had\nexpressed her obligation in the most forcible terms.\n        T.  Magnas vero agere gratias Thais mihi?\n        G.  Ingentes.\n               Eun. a. iii. s. i.\n\nCANTO XIX\n\nv. 18.  Saint John\'s fair dome.]  The apertures in the  rock were\nof the same dimensions as the fonts of St. John the Baptist at\nFlorence, one of which, Dante says he had broken, to rescue a\nchild  that was playing near and fell in. He intimates that the\nmotive of his  breaking the font had been maliciously represented\nby his enemies.\n\nv. 55.  O Boniface!]  The spirit mistakes Dante for  Boniface\nVIII. who was then alive, and who he did not expect would have\narrived so soon, in consequence, as it should seem, of a\nprophecy, which  predicted the death of that Pope at a later\nperiod. Boniface died in  1303.\n\nv. 58.  In guile.]  \"Thou didst presume to arrive by fraudulent\nmeans at the papal power, and afterwards to abuse it.\"\n\nv. 71.  In the mighty mantle I was rob\'d.]  Nicholas III, of the\nOrsini family, whom the poet therefore calls \"figliuol dell\'\norsa,\" \"son of the she-bear.\"  He died in 1281.\n\nv. 86.  From forth the west, a shepherd without law.]   Bertrand\nde Got Archbishop of Bordeaux, who succeeded to the pontificate\nin 1305, and assumed the title of Clement V. He transferred the\nholy ");
    strcat(expected_filecontent, " see to Avignon in 1308 (where it remained till 1376), and\ndied in 1314.\n\nv. 88.  A new Jason.]  See Maccabees, b. ii. c. iv. 7,8.\n\nv. 97.  Nor Peter.]  Acts of the Apostles, c.i. 26.\n\nv. 100.  The condemned soul.]  Judas.\n\nv. 103.  Against Charles.]  Nicholas III. was enraged against\nCharles I, King of Sicily, because he rejected with scorn a\nproposition made by that Pope for an alliance between their\nfamilies.  See G. Villani, Hist. l. vii. c. liv.\n\nv. 109.  Th\' Evangelist.]  Rev. c. xvii. 1, 2, 3.  Compare\nPetrarch.  Opera fol. ed. Basil. 1551. Epist. sine titulo liber.\nep. xvi. p. 729.\n\nv. 118.  Ah, Constantine.]  He alludes to the pretended gift of\nthe Lateran by Constantine to Silvester, of which Dante himself\nseems to imply a doubt, in his treatise \"De Monarchia.\" - \"Ergo\nscindere Imperium, Imperatori non licet.  Si ergo aliquae,\ndignitates per Constantinum essent alienatae, (ut dicunt) ab\nImperio,\" &c. l. iii.\nThe gift is by Ariosto very humorously placed in the moon, among\nthe things lost or abused on earth.\n        Di varj fiori, &c.\n               O. F. c. xxxiv. st. 80.\n\nMilton has translated both this passage and that in the text.\nProse works, vol. i. p. 11. ed. 1753.\n\nCANTO XX\n\nv. 11.  Revers\'d.]  Compare Spenser, F. Q. b. i. c. viii.  st. 31\n\nv. 30.  Before whose eyes.]  Amphiaraus, one of the seven kings\nwho besieged Thebes.  He is said to have been swallowed up by  an\nopening of the earth.  See Lidgate\'s Storie of Thebes, Part III\nwhere it is told how the \"Bishop Amphiaraus\" fell down to hell.\n        And thus the devill for his outrages,\n        Like his desert payed him his wages.\nA different reason for his being doomed thus to perish is\nassigned by Pindar.\n[GREEK HERE]\n               Nem ix.\n\n        For thee, Amphiaraus, earth,\n        By Jove\'s all-riving thunder cleft\n        Her mighty bosom open\'d wide,\n        Thee and thy plunging steeds to hide,\n        Or ever on thy back the spear\n        Of Periclymenus impress\'d\n        A wound to shame thy warlike breast\n        For struck with pan");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ON\\THIn.BIn");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 6144; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 44: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST44(void)
{
    // informacje o teście
    test_start(44, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3073] = "";

                strcat(expected_filecontent, "ng thence\nA savage plant.  The Harpies, on its leaves\nThen feeding, cause both pain and for the pain\nA vent to grief.  We, as the rest, shall come\nFor our own spoils, yet not so that with them\nWe may again be clad; for what a man\nTakes from himself it is not just he have.\nHere we perforce shall drag them; and throughout\nThe dismal glade our bodies shall be hung,\nEach on the wild thorn of his wretched shade.\"\n     Attentive yet to listen to the trunk\nWe stood, expecting farther speech, when us\nA noise surpris\'d, as when a man perceives\nThe wild boar and the hunt approach his place\nOf station\'d watch, who of the beasts and boughs\nLoud rustling round him hears.  And lo! there came\nTwo naked, torn with briers, in headlong flight,\nThat they before them broke each fan o\' th\' wood.\n\"Haste now,\" the foremost cried, \"now haste thee death!\"\nThe\' other, as seem\'d, impatient of delay\nExclaiming, \"Lano! not so bent for speed\nThy sinews, in the lists of Toppo\'s field.\"\nAnd then, for that perchance no longer breath\nSuffic\'d him, of himself and of a bush\nOne group he made.  Behind them was the wood\nFull of black female mastiffs, gaunt and fleet,\nAs greyhounds that have newly slipp\'d the leash.\nOn him, who squatted down, they stuck their fangs,\nAnd having rent him piecemeal bore away\nThe tortur\'d limbs.  My guide then seiz\'d my hand,\nAnd led me to the thicket, which in vain\nMourn\'d through its bleeding wounds:  \"O Giacomo\nOf Sant\' Andrea! what avails it thee,\"\nIt cried, \"that of me thou hast made thy screen?\nFor thy ill life what blame on me recoils?\"\n     When o\'er it he had paus\'d, my master spake:\n\"Say who wast thou, that at so many points\nBreath\'st out with blood thy lamentable speech?\"\n     He answer\'d: \"Oh, ye spirits:  arriv\'d in time\nTo spy the shameful havoc, that from me\nMy leaves hath sever\'d thus, gather them up,\nAnd at the foot of their sad parent-tree\nCarefully lay them.  In that city\' I dwelt,\nWho for the Baptist her first patron chang\'d,\nWhence he for this shall cease not with his art\nTo work her woe:  and if there still remain\'d not\nOn Arno\'s passage some faint glimpse of him,\nThose citizens, who rear\'d once more her walls\nUpon the ashes left by Attila,\nHad labour\'d without profit of their toil.\nI slung the fatal noose from my own roof.\"\n\n\n\nCANTO XIV\n\nSOON as the charity of native land\nWrought in my bosom, I the scatter\'d leaves\nCollected, and to him restor\'d, who now\nWas hoarse with utt\'rance.  To the limit thence\nWe came, which from the third the second round\nDivides, and where of justice is display\'d\nContrivance horrible.  Things then first seen\nClearlier to manifest, I tell how next\nA plain we reach\'d, that from its sterile bed\nEach plant repell\'d. The mournful wood waves round\nIts garland on all sides, as round the wood\nSpreads the sad foss.  There, on the very edge,\nOur steps we stay\'d.  It was an area wide\nOf arid sand and thick, resembling most\nThe soil that erst by Cato\'s foot was trod.\n     Vengeance of Heav\'n! Oh ! how shouldst thou be fear\'d\nBy all, who read what here my eyes beheld!\n     Of naked spirits");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ON\\AlLOW.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3072; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 45: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST45(void)
{
    // informacje o teście
    test_start(45, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[438] = "";

                strcat(expected_filecontent, "ing reach\'d,\nIt \'gins to work, coagulating first;\nThen vivifies what its own substance caus\'d\nTo bear.  With animation now indued,\nThe active virtue (differing from a plant\nNo further, than that this is on the way\nAnd at its limit that) continues yet\nTo operate, that now it moves, and feels,\nAs sea sponge clinging to the rock: and there\nAssumes th\' organic powers its seed convey\'d.\n\'This is the period, son!  at which the virtue,\nThat");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ON\\ThEsE.tX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 437; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 46: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST46(void)
{
    // informacje o teście
    test_start(46, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[5121] = "";

                strcat(expected_filecontent, " the Provencal.  According to Dante, (De Vulg. Eloq. 1. 1.\nc. 8.) the Provencal was one language with the Spanish.  What he\nsays on this subject is so curious, that the reader will perhaps\nnot be displeased it I give an abstract of it.\n\nHe first makes three great divisions of the European languages.\n\"One of these extends from the mouths of the Danube, or the lake\nof Maeotis, to the western limits of England, and is bounded by\nthe limits of the French and Italians, and by the ocean. One\nidiom obtained over the whole of this space: but was\nafterwards subdivided into, the Sclavonian, Hungarian, Teutonic,\nSaxon, English, and the vernacular tongues of several other\npeople, one sign remaining to all, that they use the affirmative\nio, (our English ay.)  The whole of Europe, beginning from the\nHungarian limits and stretching towards the east, has a second\nidiom which reaches still further than the end of Europe into\nAsia. This is the Greek.  In all that remains of Europe, there is\na third idiom subdivided into three dialects, which may be\nseverally distinguished by the use of the affirmatives, oc, oil,\nand si; the first spoken by the Spaniards, the next by the\nFrench, and the third by the Latins (or Italians).  The first\noccupy the western part of southern Europe, beginning from the\nlimits of the Genoese.  The third occupy the eastern part\nfrom the said limits, as far, that is, as the promontory of\nItaly, where the Adriatic sea begins, and to Sicily. The second\nare in a manner northern with respect to these for they have the\nGermans to the east and north, on the west they are bounded by\nthe English sea, and the mountains of Arragon, and on the\nsouth by the people of Provence and the declivity of the\nApennine.\" Ibid.  c. x. \"Each of these three,\" he observes, \"has\nits own claims to distinction The excellency of the French\nlanguage consists in its being best adapted, on account of its\nfacility and agreeableness, to prose narration, (quicquid\nredactum, sive inventum est ad vulgare prosaicum suum\nest); and he instances the books compiled on the gests of the\nTrojans and Romans and the delightful adventures of King Arthur,\nwith many other histories and works of instruction. The Spanish\n(or Provencal) may boast of its having produced such\nas first cultivated in this as in a more perfect and sweet\nlanguage, the vernacular poetry: among whom are Pierre\nd\'Auvergne, and others more ancient.\nThe privileges of the Latin, or Italian are two:  first that it\nmay reckon for its own those writers who have adopted a more\nsweet and subtle style of poetry, in the number of whom are Cino,\nda Pistoia and his friend, and the next, that its writers seem to\nadhere to, certain general rules of grammar, and in so doing give\nit, in the opinion of the intelligent, a very weighty pretension\nto preference.\"\n\nCANTO XXVII\n\nv. 1.  The sun.]  At Jerusalem it was dawn, in Spain midnight,\nand in India noonday, while it was sunset in Purgatory\n\nv. 10.  Blessed.]  Matt. c. v. 8.\n\nv. 57.  Come.]  Matt.  c. xxv. 34.\n\nv. 102.  I am Leah.]  By Leah is understood the active life, as\nRachel figures the contemplative. The divinity is the mirror in\nwhich the latter looks. Michel Angelo has made these allegorical\npersonages the subject of two statues on the monument of Julius\nII. in the church of S. Pietro in Vincolo. See Mr. Duppa\'s Life\nof Michel Angelo, Sculpture viii. And x. and p 247.\n\nv. 135.  Those bright eyes.]  The eyes of Beatrice.\n\nCANTO XXVIII\n\nv. 11.  To that part.]  The west.\n\nv. 14.  The feather\'d quiristers] Imitated by Boccaccio,\nFiammetta, 1. iv. \"Odi i queruli uccelli,\" &c. --\"Hear the\nquerulous birds plaining with sweet songs, and the boughs\ntrembling, and, moved by a gentle wind, as it were keeping tenor\nto their notes.\"\n\nv. 7.  A pleasant air.]  Compare Ariosto, O. F. c. xxxiv. st. 50.\n\nv. Chiassi.]  This is the wood where the scene of Boccaccio\'s\nsublimest story is laid. See Dec.  g. 5. n. 8. and Dryden\'s\nTheodore and Honoria Our Poet perhaps wandered in it daring his\nabode with Guido Novello da Polenta.\n\nv. 41.  A lady.]  Most of the commentators suppo");
    strcat(expected_filecontent, "se, that by this\nlady, who in the last Canto is called Matilda, is to be\nunderstood the Countess Matilda, who endowed the holy see with\nthe estates called the Patrimony of St. Peter,\nand died in 1115. See G. Villani, 1. iv. e. 20 But it seems more\nprobable that she should be intended for an allegorical\npersonage.\n\nv. 80.  Thou, Lord  hast made me glad.]  Psalm xcii. 4\n\nv. 146.  On the Parnassian mountain.]\nIn bicipiti somniasse Parnasso.\nPersius  Prol.\n\nCANTO XXIX\n\nv. 76.  Listed colours.]\nDi sette liste tutte in quel colori, &c.\n--a bow\nConspicuous with three listed colours gay.\nMilton, P. L. b. xi.  865.\n\nv. 79.  Ten paces.]  For an explanation of the allegorical\nmeaning of this mysterious procession, Venturi refers those \"who\nwould see in the dark\" to the commentaries of Landino,\nVellutello, and others: and adds that it is evident the Poet has\naccommodated to his own fancy many sacred images in the\nApocalypse.  In Vasari\'s Life of Giotto, we learn that Dante\nrecommended that book to his friend, as affording");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ON\\tRADe");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 5120; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 47: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST47(void)
{
    // informacje o teście
    test_start(47, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[128] = "";

                strcat(expected_filecontent, "o first had all the rest herself beguil\'d.\nImpregnated he left her there forlorn.\nSuch is the guilt condemns him to this pain.\n");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\On\\PApER.Bin");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 127; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 48: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST48(void)
{
    // informacje o teście
    test_start(48, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[1014] = "";

                strcat(expected_filecontent, "ou who discerneth all.\"\n\n\n\nCANTO XV\n\nAs much as \'twixt the third hour\'s close and dawn,\nAppeareth of heav\'n\'s sphere, that ever whirls\nAs restless as an infant in his play,\nSo much appear\'d remaining to the sun\nOf his slope journey towards the western goal.\n     Evening was there, and here the noon of night;\nand full upon our forehead smote the beams.\nFor  round the mountain, circling, so our path\nHad led us, that toward the sun-set now\nDirect we journey\'d: when I felt a weight\nOf more exceeding splendour, than before,\nPress on my front.  The cause unknown, amaze\nPossess\'d me, and both hands against my brow\nLifting, I interpos\'d them, as a screen,\nThat of its gorgeous superflux of light\nClipp\'d the diminish\'d orb. As when the ray,\nStriking On water or the surface clear\nOf mirror, leaps unto the opposite part,\nAscending at a glance, e\'en as it fell,\n(And so much differs from the stone, that falls\nThrough equal space, as practice skill hath shown;\nThus with refracted light before me seemed\nThe ground");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ON\\GLAD");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 1013; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 49: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST49(void)
{
    // informacje o teście
    test_start(49, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[7103] = "";

                strcat(expected_filecontent, "ts wing\'d with horrid fear,\nNor hope had they of crevice where to hide,\nOr heliotrope to charm them out of view.\nWith serpents were their hands behind them bound,\nWhich through their reins infix\'d the tail and head\nTwisted in folds before.  And lo!  on one\nNear to our side, darted an adder up,\nAnd, where the neck is on the shoulders tied,\nTranspierc\'d him.  Far more quickly than e\'er pen\nWrote O or I, he kindled, burn\'d, and chang\'d\nTo ashes, all pour\'d out upon the earth.\nWhen there dissolv\'d he lay, the dust again\nUproll\'d spontaneous, and the self-same form\nInstant resumed.  So mighty sages tell,\nThe\' Arabian Phoenix, when five hundred years\nHave well nigh circled, dies, and springs forthwith\nRenascent.  Blade nor herb throughout his life\nHe tastes, but tears of frankincense alone\nAnd odorous amomum:  swaths of nard\nAnd myrrh his funeral shroud.  As one that falls,\nHe knows not how, by force demoniac dragg\'d\nTo earth, or through obstruction fettering up\nIn chains invisible the powers of man,\nWho, risen from his trance, gazeth around,\nBewilder\'d with the monstrous agony\nHe hath endur\'d, and wildly staring sighs;\nSo stood aghast the sinner when he rose.\n     Oh!  how severe God\'s judgment, that deals out\nSuch blows in stormy vengeance!  Who he was\nMy teacher next inquir\'d, and thus in few\nHe answer\'d:  \"Vanni Fucci am I call\'d,\nNot long since rained down from Tuscany\nTo this dire gullet.  Me the beastial life\nAnd not the human pleas\'d, mule that I was,\nWho in Pistoia found my worthy den.\"\n     I then to Virgil:  \"Bid him stir not hence,\nAnd ask what crime did thrust him hither:  once\nA man I knew him choleric and bloody.\"\n     The sinner heard and feign\'d not, but towards me\nHis mind directing and his face, wherein\nWas dismal shame depictur\'d, thus he spake:\n\"It grieves me more to have been caught by thee\nIn this sad plight, which thou beholdest, than\nWhen I was taken from the other life.\nI have no power permitted to deny\nWhat thou inquirest.\"  I am doom\'d thus low\nTo dwell, for that the sacristy by me\nWas rifled of its goodly ornaments,\nAnd with the guilt another falsely charged.\nBut that thou mayst not joy to see me thus,\nSo as thou e\'er shalt \'scape this darksome realm\nOpen thine ears and hear what I forebode.\nReft of the Neri first Pistoia pines,\nThen Florence changeth citizens and laws.\nFrom Valdimagra, drawn by wrathful Mars,\nA vapour rises, wrapt in turbid mists,\nAnd sharp and eager driveth on the storm\nWith arrowy hurtling o\'er Piceno\'s field,\nWhence suddenly the cloud shall burst, and strike\nEach helpless Bianco prostrate to the ground.\nThis have I told, that grief may rend thy heart.\"\n\n\n\nCANTO XXV\n\nWHEN he had spoke, the sinner rais\'d his hands\nPointed in mockery, and cried:  \"Take them, God!\nI level them at thee!\"  From that day forth\nThe serpents were my friends; for round his neck\nOne of then rolling twisted, as it said,\n\"Be silent, tongue!\"  Another to his arms\nUpgliding, tied them, riveting itself\nSo close, it took from them the power to move.\n     Pistoia!  Ah Pistoia!  why dost doubt\nTo turn thee into ashes, cumb\'ring earth\nNo longer, since in evil act so far\nThou hast outdone thy seed?  I did not mark,\nThrough all the gloomy circles of the\' abyss,\nSpirit, that swell\'d so proudly \'gainst his God,\nNot him, who headlong fell from Thebes.  He fled,\nNor utter\'d more; and after him there came\nA centaur full of fury, shouting, \"Where\nWhere is the caitiff?\"  On Maremma\'s marsh\nSwarm not the serpent tribe, as on his haunch\nThey swarm\'d, to where the human face begins.\nBehind his head upon the shoulders lay,\nWith open wings, a dragon breathing fire\nOn whomsoe\'er he met.  To me my guide:\n\"Cacus is this, who underneath the rock\nOf Aventine spread oft a lake of blood.\nHe, from his brethren parted, here must tread\nA different journey, for his fraudful theft\nOf the great herd, that near him stall\'d; whence found\nHis felon deeds their end, beneath the mace\nOf stout Alcides, that perchance laid on\nA hundred blows, and not the tenth was felt.\"\n     While yet he spake, the centaur sped away:\nAnd under us three spirits c");
    strcat(expected_filecontent, "ame, of whom\nNor I nor he was ware, till they exclaim\'d;\n\"Say who are ye?\"  We then brake off discourse,\nIntent on these alone.  I knew them not;\nBut, as it chanceth oft, befell, that one\nHad need to name another.  \"Where,\" said he,\n\"Doth Cianfa lurk?\"  I, for a sign my guide\nShould stand attentive, plac\'d against my lips\nThe finger lifted.  If, O reader!  now\nThou be not apt to credit what I tell,\nNo marvel; for myself do scarce allow\nThe witness of mine eyes.  But as I looked\nToward them, lo!  a serpent with six feet\nSprings forth on one, and fastens full upon him:\nHis midmost grasp\'d the belly, a forefoot\nSeiz\'d on each arm (while deep in either cheek\nHe flesh\'d his fangs); the hinder on the thighs\nWere spread, \'twixt which the tail inserted curl\'d\nUpon the reins behind.  Ivy ne\'er clasp\'d\nA dodder\'d oak, as round the other\'s limbs\nThe hideous monster intertwin\'d his own.\nThen, as they both had been of burning wax,\nEach melted into other, mingling hues,\nThat which was either now was seen no more.\nThus up the shrinking paper, ere it burns,\nA brown tint glides, not turning yet to black,\nAnd the clean white expires.  The other two\nLook\'d on exclaiming:  \"Ah, how dost thou change,\nAgnello!  See!  Thou art nor double now,\nNor only one.\"  The two heads now became\nOne, and two figures blended in one form\nAppear\'d, where both were lost.  Of the four lengths\nTwo arms were made:  the belly and the chest\nThe thighs and legs into such members chang\'d,\nAs never eye hath seen.  Of former shape\nAll trace was vanish\'d.  Two yet neither seem\'d\nThat image miscreate, and so pass\'d on\nWith tardy steps.  As underneath the scourge\nOf the fierce dog-star, that lays bare the fields,\nShifting from brake to brake, the lizard seems\nA flash of lightning, if he thwart the road,\nSo toward th\' entrails of the other two\nApproaching seem\'d, an adder all on fire,\nAs the dark pepper-grain, livid and swart.\nIn that part, whence our life is nourish\'d first,\nOne he transpierc\'d; then down before him fell\nStretch\'d out.  The pierced spirit look\'d on him\nBut spake not; yea stood motionless and yawn\'d,\nAs if by sleep or fev\'rous fit assail\'d.\nHe ey\'d the serpent, and the serpent him.\nOne from the wound, the other from the mouth\nBreath\'d a thick smoke, whose vap\'ry columns join\'d.\n     Lucan in mute attention now may hear,\nNor thy disastrous fate, Sabellus!  tell,\nNor shine, Nasidius!  Ovid now be mute.\nWhat if in warbling fiction he record\nCadmus and Arethusa, to a snake\nHim chang\'d, and her into a fountain clear,\nI envy not; for never face to face\nTwo natures thus transmuted did he sing,\nWherein both shapes were ready to assume\nThe other\'s substance.  They in mutual guise\nSo answer\'d, that the serpent split his train\nDivided to a fork, and the pierc\'d spirit\nDrew close his steps together, legs and thighs\nCompacted, that no sign of juncture soon\nWas visible:  the tail disparted took\nThe figure which the spirit lost, its skin\nSoft\'ning, his indurated to a rind.\nThe shoulders next I mark\'d, t");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\oN\\PREPArE.BiN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 7102; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 50: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST50(void)
{
    // informacje o teście
    test_start(50, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[709] = "";

                strcat(expected_filecontent, "trike\nThe two entwining serpents, ere the plumes,\nThat mark\'d the better sex, might shoot again.\n     \"Aruns, with rere his belly facing, comes.\nOn Luni\'s mountains \'midst the marbles white,\nWhere delves Carrara\'s hind, who wons beneath,\nA cavern was his dwelling, whence the stars\nAnd main-sea wide in boundless view he held.\n     \"The next, whose loosen\'d tresses overspread\nHer bosom, which thou seest not (for each hair\nOn that side grows) was Manto, she who search\'d\nThrough many regions, and at length her seat\nFix\'d in my native land, whence a short space\nMy words detain thy audience.  When her sire\nFrom life departed, and in servitude\nThe city dedicate to Bacchus mourn\'d,\nLong time she went a wand");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\On\\oUT.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 708; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 51: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST51(void)
{
    // informacje o teście
    test_start(51, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3940] = "";

                strcat(expected_filecontent, "soul\nIs in Cocytus plung\'d, and yet doth seem\nIn body still alive upon the earth.\n\n\n\nCANTO XXXIV\n\n\"THE banners of Hell\'s Monarch do come forth\nTowards us; therefore look,\" so spake my guide,\n\"If thou discern him.\"  As, when breathes a cloud\nHeavy and dense, or when the shades of night\nFall on our hemisphere, seems view\'d from far\nA windmill, which the blast stirs briskly round,\nSuch was the fabric then methought I saw,\n     To shield me from the wind, forthwith I drew\nBehind my guide:  no covert else was there.\n     Now came I (and with fear I bid my strain\nRecord the marvel) where the souls were all\nWhelm\'d underneath, transparent, as through glass\nPellucid the frail stem.  Some prone were laid,\nOthers stood upright, this upon the soles,\nThat on his head, a third with face to feet\nArch\'d like a bow.  When to the point we came,\nWhereat my guide was pleas\'d that I should see\nThe creature eminent in beauty once,\nHe from before me stepp\'d and made me pause.\n     \"Lo!\"  he exclaim\'d, \"lo Dis! and lo the place,\nWhere thou hast need to arm thy heart with strength.\"\n     How frozen and how faint I then became,\nAsk me not, reader!  for I write it not,\nSince words would fail to tell thee of my state.\nI was not dead nor living.  Think thyself\nIf quick conception work in thee at all,\nHow I did feel.  That emperor, who sways\nThe realm of sorrow, at mid breast from th\' ice\nStood forth; and I in stature am more like\nA giant, than the giants are in his arms.\nMark now how great that whole must be, which suits\nWith such a part.  If he were beautiful\nAs he is hideous now, and yet did dare\nTo scowl upon his Maker, well from him\nMay all our mis\'ry flow.  Oh what a sight!\nHow passing strange it seem\'d, when I did spy\nUpon his head three faces: one in front\nOf hue vermilion, th\' other two with this\nMidway each shoulder join\'d and at the crest;\nThe right \'twixt wan and yellow seem\'d:  the left\nTo look on, such as come from whence old Nile\nStoops to the lowlands.  Under each shot forth\nTwo mighty wings, enormous as became\nA bird so vast.  Sails never such I saw\nOutstretch\'d on the wide sea.  No plumes had they,\nBut were in texture like a bat, and these\nHe flapp\'d i\' th\' air, that from him issued still\nThree winds, wherewith Cocytus to its depth\nWas frozen.  At six eyes he wept:  the tears\nAdown three chins distill\'d with bloody foam.\nAt every mouth his teeth a sinner champ\'d\nBruis\'d as with pond\'rous engine, so that three\nWere in this guise tormented.  But far more\nThan from that gnawing, was the foremost pang\'d\nBy the fierce rending, whence ofttimes the back\nWas stript of all its skin.  \"That upper spirit,\nWho hath worse punishment,\" so spake my guide,\n\"Is Judas, he that hath his head within\nAnd plies the feet without.  Of th\' other two,\nWhose heads are under, from the murky jaw\nWho hangs, is Brutus:  lo!  how he doth writhe\nAnd speaks not!  Th\' other Cassius, that appears\nSo large of limb.  But night now re-ascends,\nAnd it is time for parting.  All is seen.\"\n     I clipp\'d him round the neck, for so he bade;\nAnd noting time and place, he, when the wings\nEnough were op\'d, caught fast the shaggy sides,\nAnd down from pile to pile descending stepp\'d\nBetween the thick fell and the jagged ice.\n     Soon as he reach\'d the point, whereat the thigh\nUpon the swelling of the haunches turns,\nMy leader there with pain and struggling hard\nTurn\'d round his head, where his feet stood before,\nAnd grappled at the fell, as one who mounts,\nThat into hell methought we turn\'d again.\n     \"Expect that by such stairs as these,\" thus spake\nThe teacher, panting like a man forespent,\n\"We must depart from evil so extreme.\"\nThen at a rocky opening issued forth,\nAnd plac\'d me on a brink to sit, next join\'d\nWith wary step my side.  I rais\'d mine eyes,\nBelieving that I Lucifer should see\nWhere he was lately left, but saw him now\nWith legs held upward.  Let the grosser sort,\nWho see not what the point was I had pass\'d,\nB");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ON\\EXciTE.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3939; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 52: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST52(void)
{
    // informacje o teście
    test_start(52, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3073] = "";

                strcat(expected_filecontent, "t pass we on, nor waste\nOur words; for so each language is to him,\nAs his to others, understood by none.\"\n     Then to the leftward turning sped we forth,\nAnd at a sling\'s throw found another shade\nFar fiercer and more huge.  I cannot say\nWhat master hand had girt him; but he held\nBehind the right arm fetter\'d, and before\nThe other with a chain, that fasten\'d him\nFrom the neck down, and five times round his form\nApparent met the wreathed links.  \"This proud one\nWould of his strength against almighty Jove\nMake trial,\" said my guide; \"whence he is thus\nRequited: Ephialtes him they call.\nGreat was his prowess, when the giants brought\nFear on the gods:  those arms, which then he piled,\nNow moves he never.\"  Forthwith I return\'d:\n\"Fain would I, if \'t were possible, mine eyes\nOf Briareus immeasurable gain\'d\nExperience next.\"  He answer\'d: \"Thou shalt see\nNot far from hence Antaeus, who both speaks\nAnd is unfetter\'d, who shall place us there\nWhere guilt is at its depth.  Far onward stands\nWhom thou wouldst fain behold, in chains, and made\nLike to this spirit, save that in his looks\nMore fell he seems.\"  By violent earthquake rock\'d\nNe\'er shook a tow\'r, so reeling to its base,\nAs Ephialtes.  More than ever then\nI dreaded death, nor than the terror more\nHad needed, if I had not seen the cords\nThat held him fast.  We, straightway journeying on,\nCame to Antaeus, who five ells complete\nWithout the head, forth issued from the cave.\n     \"O thou, who in the fortunate vale, that made\nGreat Scipio heir of glory, when his sword\nDrove back the troop of Hannibal in flight,\nWho thence of old didst carry for thy spoil\nAn hundred lions; and if thou hadst fought\nIn the high conflict on thy brethren\'s side,\nSeems as men yet believ\'d, that through thine arm\nThe sons of earth had conquer\'d, now vouchsafe\nTo place us down beneath, where numbing cold\nLocks up Cocytus.  Force not that we crave\nOr Tityus\' help or Typhon\'s.  Here is one\nCan give what in this realm ye covet.  Stoop\nTherefore, nor scornfully distort thy lip.\nHe in the upper world can yet bestow\nRenown on thee, for he doth live, and looks\nFor life yet longer, if before the time\nGrace call him not unto herself.\"  Thus spake\nThe teacher.  He in haste forth stretch\'d his hands,\nAnd caught my guide.  Alcides whilom felt\nThat grapple straighten\'d score.  Soon as my guide\nHad felt it, he bespake me thus:  \"This way\nThat I may clasp thee;\" then so caught me up,\nThat we were both one burden.  As appears\nThe tower of Carisenda, from beneath\nWhere it doth lean, if chance a passing cloud\nSo sail across, that opposite it hangs,\nSuch then Antaeus seem\'d, as at mine ease\nI mark\'d him stooping.  I were fain at times\nT\' have pass\'d another way.  Yet in th\' abyss,\nThat Lucifer with Judas low ingulfs,\nI,ightly he plac\'d us; nor there leaning stay\'d,\nBut rose as in a bark the stately mast.\n\n\n\nCANTO XXXII\n\nCOULD I command rough rhimes and hoarse, to suit\nThat hole of sorrow, o\'er which ev\'ry rock\nHis firm abutment rears, then might the vein\nOf fancy rise full springing:  but not mine\nSuch measures, and ");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ON\\SaiD.Bin");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3072; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 53: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST53(void)
{
    // informacje o teście
    test_start(53, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[5775] = "";

                strcat(expected_filecontent, "By Jove\'s all-riving thunder cleft\n        Her mighty bosom open\'d wide,\n        Thee and thy plunging steeds to hide,\n        Or ever on thy back the spear\n        Of Periclymenus impress\'d\n        A wound to shame thy warlike breast\n        For struck with panic fear\n        The gods\' own children flee.\n\nv. 37.  Tiresias.]\n        Duo magnorum viridi coeuntia sylva\n        Corpora serpentum baculi violaverat ictu, &c.\n               Ovid. Met. iii.\n\nv. 43.  Aruns.]  Aruns is said to have dwelt in the  mountains of\nLuni (from whence that territory is still called Lunigiana),\nabove Carrara, celebrated for its marble.  Lucan. Phars. l. i.\n575.  So Boccaccio in the Fiammetta, l. iii.  \"Quale Arunte,\" &c.\n\n\"Like Aruns, who amidst the white marbles of Luni, contemplated\nthe celestial bodies and their motions.\"\n\nv. 50.  Manto.]  The daughter of Tiresias of Thebes, a city\ndedicated to Bacchus.  From Manto Mantua, the country of Virgil\nderives its name. The Poet proceeds to describe the situation of\nthat place.\n\nv. 61.  Between the vale.]  The lake Benacus, now called  the\nLago di Garda, though here said to lie between Garda, Val\nCamonica, and the Apennine, is, however, very distant from the\nlatter two\n\nv. 63.  There is a spot.]  Prato di Fame, where the dioceses of\nTrento, Verona, and Brescia met.\n\nv. 69.  Peschiera.]  A garrison situated to the south of the\nlake, where it empties itself and forms the Mincius.\n\nv. 94.  Casalodi\'s madness.]  Alberto da Casalodi, who had got\npossession of Mantua, was persuaded by Pinamonte Buonacossi, that\nhe might ingratiate himself with the people by banishing to their\n\nown castles the nobles, who were obnoxious to them.  No sooner\nwas this done, than Pinamonte put himself at the head of the\npopulace, drove out Casalodi and his adherents, and obtained the\nsovereignty for himself.\n\nv. 111.  So sings my tragic strain.]\n        Suspensi Eurypilum scitatum oracula Phoebi\n        Mittimus.\n               Virg. Aeneid. ii. 14.\n\nv. 115.  Michael Scot.]  Sir Michael Scott, of Balwearie,\nastrologer to the Emperor Frederick II. lived in the thirteenth\ncentury.  For further particulars relating to this singular man,\nsee Warton\'s History of English Poetry, vol. i. diss. ii. and\nsect. ix.  p 292, and the Notes to Mr. Scott\'s \"Lay of the Last\nMinstrel,\" a  poem in which a happy use is made of the traditions\nthat are still current in North Britain concerning him.  He is\nmentioned by G. Villani. Hist. l. x. c. cv. and cxli. and l. xii.\nc. xviii. and by Boccaccio, Dec. Giorn. viii. Nov. 9.\n\nv. 116.  Guido Bonatti.]  An astrologer of Forli, on whose  skill\nGuido da Montefeltro, lord of that place, so much relied, that he\nis reported never to have gone into battle, except in the hour\nrecommended to him as fortunate by Bonatti.\n\nLandino and Vellutello, speak of a book, which he composed on the\nsubject of his art.\n\nv. 116.  Asdente.]  A shoemaker at Parma, who deserted his\nbusiness to practice the arts of divination.\n\nv. 123.  Cain with fork of thorns.]  By Cain and the thorns, or\nwhat is still vulgarly called the Man in the Moon, the Poet\ndenotes that luminary.  The same superstition is alluded to in\nthe Paradise, Canto II. 52.  The curious reader may consult Brand\non Popular Antiquities, 4to.  1813. vol. ii. p. 476.\n\nCANTO XXI\n\nv. 7.  In the Venetians\' arsenal.]  Compare Ruccellai, Le  Api,\n165, and Dryden\'s Annus Mirabilis, st. 146, &c.\n\nv. 37.  One of Santa Zita\'s elders.]  The elders or chief\nmagistrates of Lucca, where Santa Zita was held in especial\nveneration.  The name of this sinner is supposed to have been\nMartino Botaio.\n\nv. 40.  Except Bonturo, barterers.]  This is said ironically of\nBonturo de\' Dati.  By barterers are meant peculators, of every\ndescription; all who traffic the interests of the public  for\ntheir own private advantage.\n\nv. 48.  Is other swimming than in Serchio\'s wave.]\n        Qui si nuota altrimenti che nel Serchio.\nSerchio is the river that flows by Lucca.  So Pulci, Morg. Mag.\nc. xxiv.\n        Qui si nuota nel sangue, e non nel Serchio.\n\nv. 92.  From Caprona.]  The surrender of th");
    strcat(expected_filecontent, "e castle of Caprona to\nthe combined forces of Florence and Lucca, on condition that the\ngarrison should march out in safety, to which event Dante was a\nwitness, took place in 1290.  See G. Villani, Hist. l. vii. c.\n136.\n\nv. 109.  Yesterday.]  This passage fixes the era of Dante\'s\ndescent at Good Friday, in the year 1300 (34 years from our\nblessed  Lord\'s incarnation being added to 1266), and at the\nthirty-fifth  year of our poet\'s age. See Canto I. v. 1.\n\nThe awful event alluded to, the Evangelists inform us, happened\n\"at the ninth hour,\" that is, our sixth, when \"the rocks  were\nrent,\" and the convulsion, according to Dante, was felt even in\nthe depths in Hell.  See Canto XII. 38.\n\nCANTO XXII\n\nv. 16.  In the church.]  This proverb is repeated by Pulci, Morg.\nMagg. c. xvii.\n\nv. 47.  Born in Navarre\'s domain.]  The name of this peculator is\nsaid to have been Ciampolo.\n\nv. 51.  The good king Thibault.]  \"Thibault I. king of Navarre,\ndied on the 8th of June, 1233, as much to be commended for the\ndesire he showed of aiding the war in the Holy Land, as\nreprehensible and faulty for his design of oppressing the rights\nand privileges of the church, on which account it is said that\nthe whole kingdom was under an interdict for the space of three\nentire years.  Thibault undoubtedly merits praise, as for his\nother endowments, so especially for his cultivation of the\nliberal arts, his exercise and knowledge of music and poetry in\nwhich he much excelled, that he was accustomed to compose verses\nand sing them to the viol, and to exhibit his poetical\ncompositions publicly in his palace, that they might be\ncriticized by all.\"  Mariana, History of Spain, b. xiii.  c. 9");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ON\\CAT.TxT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 5774; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 54: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST54(void)
{
    // informacje o teście
    test_start(54, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[471] = "";

                strcat(expected_filecontent, "nd a sweet melody\nRan through the luminous air.  Then did I chide\nWith warrantable zeal the hardihood\nOf our first parent, for that there were earth\nStood in obedience to the heav\'ns, she only,\nWoman, the creature of an hour, endur\'d not\nRestraint of any veil: which had she borne\nDevoutly, joys, ineffable as these,\nHad from the first, and long time since, been mine.\n     While through that wilderness of primy sweets\nThat never fade, suspense I walk\'d, and yet\nExpect");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ON\\HAnD.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 470; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 55: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST55(void)
{
    // informacje o teście
    test_start(55, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[920] = "";

                strcat(expected_filecontent, "ough I feel me on all sides\nWell squar\'d to fortune\'s blows.  Therefore my will\nWere satisfied to know the lot awaits me,\nThe arrow, seen beforehand, slacks its flight.\"\n     So said I to the brightness, which erewhile\nTo me had spoken, and my will declar\'d,\nAs Beatrice will\'d, explicitly.\nNor with oracular response obscure,\nSuch, as or ere the Lamb of God was slain,\nBeguil\'d the credulous nations; but, in terms\nPrecise and unambiguous lore, replied\nThe spirit of paternal love, enshrin\'d,\nYet in his smile apparent; and thus spake:\n\"Contingency, unfolded not to view\nUpon the tablet of your mortal mold,\nIs all depictur\'d in the\' eternal sight;\nBut hence deriveth not necessity,\nMore then the tall ship, hurried down the flood,\nDoth from the vision, that reflects the scene.\nFrom thence, as to the ear sweet harmony\nFrom organ comes, so comes before mine eye\nThe time prepar\'d for thee.  Such as driv\'n out\nFrom At");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ON\\SEttle.bIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 919; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 56: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST56(void)
{
    // informacje o teście
    test_start(56, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[5082] = "";

                strcat(expected_filecontent, "acy dies\nAgainst the holy church, though he repent,\nMust wander thirty-fold for all the time\nIn his presumption past; if such decree\nBe not by prayers of good men shorter made\nLook therefore if thou canst advance my bliss;\nRevealing to my good Costanza, how\nThou hast beheld me, and beside the terms\nLaid on me of that interdict; for here\nBy means of those below much profit comes.\"\n\n\nCANTO IV\n\nWhen by sensations of delight or pain,\nThat any of our faculties hath seiz\'d,\nEntire the soul collects herself, it seems\nShe is intent upon that power alone,\nAnd thus the error is disprov\'d which holds\nThe soul not singly lighted in the breast.\nAnd therefore when as aught is heard or seen,\nThat firmly keeps the soul toward it turn\'d,\nTime passes, and a man perceives it not.\nFor that, whereby he hearken, is one power,\nAnother that, which the whole spirit hash;\nThis is as it were bound, while that is free.\n     This found I true by proof, hearing that spirit\nAnd wond\'ring; for full fifty steps aloft\nThe sun had measur\'d unobserv\'d of me,\nWhen we arriv\'d where all with one accord\nThe spirits shouted, \"Here is what ye ask.\"\n     A larger aperture ofttimes is stopp\'d\nWith forked stake of thorn by villager,\nWhen the ripe grape imbrowns, than was the path,\nBy which my guide, and I behind him close,\nAscended solitary, when that troop\nDeparting left us.  On Sanleo\'s road\nWho journeys, or to Noli low descends,\nOr mounts Bismantua\'s height, must use his feet;\nBut here a man had need to fly, I mean\nWith the swift wing and plumes of high desire,\nConducted by his aid, who gave me hope,\nAnd with light furnish\'d to direct my way.\n     We through the broken rock ascended, close\nPent on each side, while underneath the ground\nAsk\'d help of hands and feet.  When we arriv\'d\nNear on the highest ridge of the steep bank,\nWhere the plain level open\'d I exclaim\'d,\n\"O master!  say which way can we proceed?\"\n     He answer\'d, \"Let no step of thine recede.\nBehind me gain the mountain, till to us\nSome practis\'d guide appear.\"  That eminence\nWas lofty that no eye might reach its point,\nAnd the side proudly rising, more than line\nFrom the mid quadrant to the centre drawn.\nI wearied thus began:  \"Parent belov\'d!\nTurn, and behold how I remain alone,\nIf thou stay not.\" --\" My son!\"  He straight reply\'d,\n\"Thus far put forth thy strength; \"and to a track\nPointed, that, on this side projecting, round\nCircles the hill.  His words so spurr\'d me on,\nThat I behind him clamb\'ring, forc\'d myself,\nTill my feet press\'d the circuit plain beneath.\nThere both together seated, turn\'d we round\nTo eastward, whence was our ascent: and oft\nMany beside have with delight look\'d back.\n     First on the nether shores I turn\'d my eyes,\nThen rais\'d them to the sun, and wond\'ring mark\'d\nThat from the left it smote us.  Soon perceiv\'d\nThat Poet sage how at the car of light\nAmaz\'d I stood, where \'twixt us and the north\nIts course it enter\'d.  Whence he thus to me:\n\"Were Leda\'s offspring now in company\nOf that broad mirror, that high up and low\nImparts his light beneath, thou might\'st behold\nThe ruddy zodiac nearer to the bears\nWheel, if its ancient course it not forsook.\nHow that may be if thou would\'st think; within\nPond\'ring, imagine Sion with this mount\nPlac\'d on the earth, so that to both be one\nHorizon, and two hemispheres apart,\nWhere lies the path that Phaeton ill knew\nTo guide his erring chariot: thou wilt see\nHow of necessity by this on one\nHe passes, while by that on the\' other side,\nIf with clear view shine intellect attend.\"\n     \"Of truth, kind teacher!\"  I exclaim\'d, \"so clear\nAught saw I never, as I now discern\nWhere seem\'d my ken to fail, that the mid orb\nOf the supernal motion (which in terms\nOf art is called the Equator, and remains\nEver between the sun and winter) for the cause\nThou hast assign\'d, from hence toward the north\nDeparts, when those who in the Hebrew land\nInhabit, see it tow\'rds the warmer part.\nBut if it please thee, I would gladly know,\nHow far we have to journey: for the hill\nMounts higher, than this sight of mine can mount.\"\n     He thus to me:  \"Such is this ");
    strcat(expected_filecontent, "steep ascent,\nThat it is ever difficult at first,\nBut, more a man proceeds, less evil grows.\nWhen pleasant it shall seem to thee, so much\nThat upward going shall be easy to thee.\nAs in a vessel to go down the tide,\nThen of this path thou wilt have reach\'d the end.\nThere hope to rest thee from thy toil.  No more\nI answer, and thus far for certain know.\"\nAs he his words had spoken, near to us\nA voice there sounded:  \"Yet ye first perchance\nMay to repose you by constraint be led.\"\nAt sound thereof each turn\'d, and on the left\nA huge stone we beheld, of which nor I\nNor he before was ware.  Thither we drew,\nfind there were some, who in the shady place\nBehind the rock were standing, as a man\nThru\' idleness might stand.  Among them one,\nWho seem\'d to me much wearied, sat him down,\nAnd with his arms did fold his knees about,\nHolding his face between them downward bent.\n     \"Sweet Sir!\"  I cry\'d, \"behold that man, who shows\nHimself more idle, than if laziness\nWere sister to him.\"");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ON\\TOwN.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 5081; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 57: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST57(void)
{
    // informacje o teście
    test_start(57, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[5121] = "";

                strcat(expected_filecontent, "e of man, our justice seems\nUnjust, is argument for faith, and not\nFor heretic declension.  To the end\nThis truth may stand more clearly in your view,\nI will content thee even to thy wish\n     \"If violence be, when that which suffers, nought\nConsents to that which forceth, not for this\nThese spirits stood exculpate.  For the will,\nThat will not, still survives unquench\'d, and doth\nAs nature doth in fire, tho\' violence\nWrest it a thousand times; for, if it yield\nOr more or less, so far it follows force.\nAnd thus did these, whom they had power to seek\nThe hallow\'d place again.  In them, had will\nBeen perfect, such as once upon the bars\nHeld Laurence firm, or wrought in Scaevola\nTo his own hand remorseless, to the path,\nWhence they were drawn, their steps had hasten\'d back,\nWhen liberty return\'d: but in too few\nResolve so steadfast dwells.  And by these words\nIf duly weigh\'d, that argument is void,\nWhich oft might have perplex\'d thee still.  But now\nAnother question thwarts thee, which to solve\nMight try thy patience without better aid.\nI have, no doubt, instill\'d into thy mind,\nThat blessed spirit may not lie; since near\nThe source of primal truth it dwells for aye:\nAnd thou might\'st after of Piccarda learn\nThat Constance held affection to the veil;\nSo that she seems to contradict me here.\nNot seldom, brother, it hath chanc\'d for men\nTo do what they had gladly left undone,\nYet to shun peril they have done amiss:\nE\'en as Alcmaeon, at his father\'s suit\nSlew his own mother, so made pitiless\nNot to lose pity.  On this point bethink thee,\nThat force and will are blended in such wise\nAs not to make the\' offence excusable.\nAbsolute will agrees not to the wrong,\nThat inasmuch as there is fear of woe\nFrom non-compliance, it agrees.  Of will\nThus absolute Piccarda spake, and I\nOf th\' other; so that both have truly said.\"\n     Such was the flow of that pure rill, that well\'d\nFrom forth the fountain of all truth; and such\nThe rest, that to my wond\'ring thoughts l found.\n      \"O thou of primal love the prime delight!\nGoddess!  \"I straight reply\'d, \"whose lively words\nStill shed new heat and vigour through my soul!\nAffection fails me to requite thy grace\nWith equal sum of gratitude: be his\nTo recompense, who sees and can reward thee.\nWell I discern, that by that truth alone\nEnlighten\'d, beyond which no truth may roam,\nOur mind can satisfy her thirst to know:\nTherein she resteth, e\'en as in his lair\nThe wild beast, soon as she hath reach\'d that bound,\nAnd she hath power to reach it; else desire\nWere given to no end.  And thence doth doubt\nSpring, like a shoot, around the stock of truth;\nAnd it is nature which from height to height\nOn to the summit prompts us.  This invites,\nThis doth assure me, lady, rev\'rently\nTo ask thee of other truth, that yet\nIs dark to me.  I fain would know, if man\nBy other works well done may so supply\nThe failure of his vows, that in your scale\nThey lack not weight.\"  I spake; and on me straight\nBeatrice look\'d with eyes that shot forth sparks\nOf love celestial in such copious stream,\nThat, virtue sinking in me overpower\'d,\nI turn\'d, and downward bent confus\'d my sight.\n\n\n\nCANTO V\n\n\"If beyond earthly wont, the flame of love\nIllume me, so that I o\'ercome thy power\nOf vision, marvel not: but learn the cause\nIn that perfection of the sight, which soon\nAs apprehending, hasteneth on to reach\nThe good it apprehends.  I well discern,\nHow in thine intellect already shines\nThe light eternal, which to view alone\nNe\'er fails to kindle love; and if aught else\nYour love seduces, \'t is but that it shows\nSome ill-mark\'d vestige of that primal beam.\n     \"This would\'st thou know, if failure of the vow\nBy other service may be so supplied,\nAs from self-question to assure the soul.\"\n     Thus she her words, not heedless of my wish,\nBegan; and thus, as one who breaks not off\nDiscourse, continued in her saintly strain.\n\"Supreme of gifts, which God creating gave\nOf his free bounty, sign most evident\nOf goodness, and in his account most priz\'d,\nWas liberty of will, the boon wherewith\nAll intellectual creatures, and them sole\nHe hath");
    strcat(expected_filecontent, " endow\'d.  Hence now thou mayst infer\nOf what high worth the vow, which so is fram\'d\nThat when man offers, God well-pleas\'d accepts;\nFor in the compact between God and him,\nThis treasure, such as I describe it to thee,\nHe makes the victim, and of his own act.\nWhat compensation therefore may he find?\nIf that, whereof thou hast oblation made,\nBy using well thou think\'st to consecrate,\nThou would\'st of theft do charitable deed.\nThus I resolve thee of the greater point.\n     \"But forasmuch as holy church, herein\nDispensing, seems to contradict the truth\nI have discover\'d to thee, yet behooves\nThou rest a little longer at the board,\nEre the crude aliment, which thou hast taken,\nDigested fitly to nutrition turn.\nOpen thy mind to what I now unfold,\nAnd give it inward keeping.  Knowledge comes\nOf learning well retain\'d, unfruitful else.\n     \"This sacrifice in essence of two things\nConsisteth; one is that, whereof \'t is made,\nThe covenant the other.  For the last,\nIt ne\'er is cancell\'d if not kept: and hence\nI spake e");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\on\\LEFt.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 5120; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 58: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST58(void)
{
    // informacje o teście
    test_start(58, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[7915] = "";

                strcat(expected_filecontent, "ke slew\nher own son Itylus, and for her punishment was transformed by\nJupiter into a nightingale.\"\nCowper\'s note on the passage.\nIn speaking of the nightingale, let me observe, that while some\nhave considered its song as a melancholy, and others as a\ncheerful one, Chiabrera appears to have come nearest the truth,\nwhen he says, in the Alcippo, a. l. s. 1,\nNon mal si stanca d\' iterar le note\nO gioconde o dogliose,\nAl sentir dilettose.\n\nUnwearied still reiterates her lays,\nJocund or sad, delightful to the ear.\n\nv. 26.  One crucified.]  Haman.  See the book of Esther, c. vii.\nv. 34.  A damsel.]  Lavinia, mourning for her mother Amata, who,\nimpelled by grief and indignation for the supposed death of\nTurnus, destroyed herself.  Aen. 1. xii. 595.\n\nv. 43.  The broken slumber quivering ere it dies.]  Venturi\nsuggests that this bold and unusual metaphor may have been formed\non that in Virgil.\n\nTempus erat quo prima quies mortalibus aegris\nIncipit, et dono divun gratissima serpit.\nAen. 1. ii. 268.\n\nv. 68.  The peace-makers.]  Matt. c. v. 9.\n\nv. 81.  The love.]  \"A defect in our love towards God, or\nlukewarmness in piety, is here removed.\"\n\nv. 94.  The primal blessings.]  Spiritual good.\n\nv. 95.  Th\' inferior.]  Temporal good.\n\nv. 102.  Now.]  \"It is impossible for any being, either to hate\nitself, or to hate the First Cause of all, by which it exists.\nWe can therefore only rejoice in the evil which befalls others.\"\n\nv. 111.  There is.]  The proud.\n\nv. 114.  There is.]  The envious.\n\nv. 117.  There is he.]  The resentful.\n\nv. 135.  Along Three circles.]  According to the allegorical\ncommentators, as Venturi has observed, Reason is represented\nunder the person of Virgil, and Sense under that of Dante.  The\nformer leaves to the latter to discover for itself the three\ncarnal sins, avarice, gluttony and libidinousness; having already\ndeclared the nature of the spiritual sins, pride, envy, anger,\nand indifference, or lukewarmness in piety, which the Italians\ncall accidia, from the Greek word.\n[GREEK HERE]\n\nCANTO XVIII\n\nv. 1.  The teacher ended.]  Compare Plato, Protagoras, v. iii.\np. 123.  Bip.  edit. [GREEK HERE]  Apoll. Rhod. 1. i. 513,\nand Milton, P. L. b. viii. 1.\nThe angel ended, &c.\n\nv. 23.  Your apprehension.]  It is literally, \"Your apprehensive\nfaculty derives intention from a thing really existing, and\ndisplays the intention within you, so that it makes the soul turn\nto it.\"  The commentators labour in explaining this; and whatever\nsense they have elicited may, I think, be resolved into the words\nof the translation in the text.\n\nv. 47.  Spirit.]  The human soul, which differs from that of\nbrutes, inasmuch as, though united with the body, it has a\nseparate existence of its own.\nv. 65.  Three men.]  The great moral philosophers among the\nheathens.\n\nv. 78.  A crag.]  I have preferred the reading of Landino,\nscheggion, \"crag,\" conceiving it to be more poetical than\nsecchion, \"bucket,\" which is the common reading.  The same cause,\nthe vapours, which the commentators say might give the appearance\nof increased magnitude to the moon, might also make her seem\nbroken at her rise.\n\nv. 78.  Up the vault.]  The moon passed with a motion opposite to\nthat of the heavens, through the constellation of the scorpion,\nin which the sun is, when to those who are in Rome he appears to\nset between the isles of Corsica and Sardinia.\n\nv. 84.  Andes.]  Andes, now Pietola, made more famous than Mantua\nnear which it is situated, by having been the birthplace of\nVirgil.\n\nv. 92.  Ismenus and Asopus.]  Rivers near Thebes\n\nv. 98.  Mary.]  Luke, c i. 39, 40\n\nv. 99.  Caesar.]  See Lucan, Phars. I. iii. and iv, and\nCaesar de Bello Civiii, I. i.  Caesar left Brutus to complete\nthe siege of Marseilles, and hastened on to the attack of\nAfranius and Petreius, the generals of Pompey, at Ilerda (Lerida)\nin Spain.\n\nv. 118.  abbot.]  Alberto, abbot of San Zeno in Verona, when\nFrederick I was emperor, by whom Milan was besieged and reduced\nto ashes.\n\nv. 121.  There is he.]  Alberto della Scala, lord of Verona, who\nhad made his natural son abbot of San Zeno.\n\nv. 133.  Fir");
    strcat(expected_filecontent, "st they died.]  The Israelites, who, on account of\ntheir disobedience, died before reaching the promised land.\n\nv. 135.  And they.]  Virg  Aen. 1. v.\n\nCANTO XIX\n\nv. 1.  The hour.]  Near the dawn.\n\nv. 4.  The geomancer.]  The geomancers, says Landino, when they\ndivined, drew a figure consisting of sixteen marks, named from so\nmany stars which constitute the end of Aquarius and the beginning\nof Pisces. One of these they called \"the greater fortune.\"\n\nv. 7.  A woman\'s shape.]  Worldly happiness.  This allegory\nreminds us of the \"Choice of Hercules.\"\n\nv. 14.  Love\'s own hue.]\nA smile that glow\'d\nCelestial rosy red, love\'s proper hue.\nMilton, P. L. b. viii.  619\n\n--facies pulcherrima tune est\nQuum porphyriaco variatur candida rubro\nQuid color hic roseus sibi vult?  designat amorem:\nQuippe amor est igni similis; flammasque rubentes\nIgnus habere solet.\nPalingenii Zodiacus Vitae, 1. xii.\n\nv. 26.  A dame.]  Philosophy.\n\nv. 49.  Who mourn.]  Matt.  c. v. 4.\n\nv. 72.  My soul.]  Psalm cxix.  5\n\nv. 97.  The successor of Peter Ottobuono, of the family of\nFieschi Counts of Lavagna, died thirty-nine days after he became\nPope, with the title of Adrian V, in 1276.\n\nv. 98.  That stream.]  The river Lavagna, in the Genoese\nterritory.\n\nv. 135.  nor shall be giv\'n in marriage.]  Matt. c. xxii. 30.\n\"Since in this state we neither marry nor are given in marriage,\nI am no longer the spouse of the church, and therefore no longer\nretain my former dignity.\n\nv. 140.  A kinswoman.]  Alagia is said to have been the wife of\nthe Marchese Marcello Malaspina, one of the poet\'s protectors\nduring his exile.  See Canto VIII.  133.\n\nCANTO XX\n\nv. 3.  I drew the sponge.]  \"I did not persevere in my inquiries\nfrom the spirit though still anxious to learn more.\"\nv. 11.  Wolf.]  Avarice.\n\nv. 16.  Of his appearing.]  He is thought to allude to\nCan Grande della Scala.  See Hell, Canto I. 98.\n\nv. 25.  Fabricius.]  Compare Petrarch, Tr. della Fama, c. 1.\n\nUn Curio ed un Fabricio, &c.\n\nv. 30.  Nicholas.]  The story of Nicholas is, that an angel\nhaving revealed to him that the father of a family was so\nimpoverished as to resolve on exposing the chastity of his three\ndaughters to sale, he threw in at the window of their house three\nbags of money, containing a sufficient portion for each of them.\nv. 42.  Root.]  Hugh Capet, ancestor of Philip IV.\nv. 46.  Had Ghent and Douay, Lille and Bruges power.]  These\ncities had lately been seized by Philip IV.  The spirit is made\nto imitate the approaching defeat of the French army by the\nFlemings, in the battle of Courtrai, which happened in 1302.\nv. 51.  The slaughter\'s trade.]  This reflection on the birth of\nhis ancestor induced Francis I  to forbid the reading of Dante in\nhis dominions Hugh Capet, who came to the throne of France in\n987, was however the grandson of Robert, who was the brother of\nEudes,  King of France in 888.\n\nv. 52.  All save one.]  The posterity of Charlemagne, the second\nrace of French monarchs, had failed, with the exception of\nCharles of Lorraine who is said, on account of the melancholy\ntemper of his mind, to have always clothed himself in black.\nVenturi suggest that Dante may have confounded him with Childeric\nIII  the last of the Merosvingian, or first, race, who was\ndeposed and made a monk in 751.\n\nv. 57.  My son.]  Hugh Capet caused his son Robert to be crowned\nat Orleans.\n\nv. 59.  The Great dower of Provence.]  Louis IX, and his brother\nCharles of Anjou, married two of the four daughters of Raymond\nBerenger Count of Provence. See Par. Canto VI.  135.\n\nv. 63.  For amends.]  This is ironical\n\nv. 64.  Poitou it seiz\'d, Navarre and Gascony.]  I venture to\nread-\nPotti e Navarra prese e Guascogna,\n\ninstead of\n\nPonti e Normandia prese e Guascogna\nSeiz\'d Ponthieu, Normandy and Gascogny.\n\nLandino has \"Potti,\" and he is probably right for");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\oN\\oBSErve");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 7914; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 59: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST59(void)
{
    // informacje o teście
    test_start(59, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[645] = "";

                strcat(expected_filecontent, "oughout this kingdom, pleases all,\nE\'en as our King, who in us plants his will;\nAnd in his will is our tranquillity;\nIt is the mighty ocean, whither tends\nWhatever it creates and nature makes.\"\n     Then saw I clearly how each spot in heav\'n\nIs Paradise, though with like gracious dew\nThe supreme virtue show\'r not over all.\n     But as it chances, if one sort of food\nHath satiated, and of another still\nThe appetite remains, that this is ask\'d,\nAnd thanks for that return\'d; e\'en so did I\nIn word and motion, bent from her to learn\nWhat web it was, through which she had not drawn\nThe shuttle to its point.  She thus began:\n\"Exalted worth and");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\On\\WAVE.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 644; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 60: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST60(void)
{
    // informacje o teście
    test_start(60, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3983] = "";

                strcat(expected_filecontent, "new miracles descry\'d,\nAnd toil\'d me with the change.  In that abyss\nOf radiance, clear and lofty, seem\'d methought,\nThree orbs of triple hue clipt in one bound:\nAnd, from another, one reflected seem\'d,\nAs rainbow is from rainbow: and the third\nSeem\'d fire, breath\'d equally from both.  Oh speech\nHow feeble and how faint art thou, to give\nConception birth!  Yet this to what I saw\nIs less than little.  Oh eternal light!\nSole in thyself that dwellst; and of thyself\nSole understood, past, present, or to come!\nThou smiledst; on that circling, which in thee\nSeem\'d as reflected splendour, while I mus\'d;\nFor I therein, methought, in its own hue\nBeheld our image painted: steadfastly\nI therefore por\'d upon the view.  As one\nWho vers\'d in geometric lore, would fain\nMeasure the circle; and, though pondering long\nAnd deeply, that beginning, which he needs,\nFinds not; e\'en such was I, intent to scan\nThe novel wonder, and trace out the form,\nHow to the circle fitted, and therein\nHow plac\'d: but the flight was not for my wing;\nHad not a flash darted athwart my mind,\nAnd in the spleen unfolded what it sought.\n     Here vigour fail\'d the tow\'ring fantasy:\nBut yet the will roll\'d onward, like a wheel\nIn even motion, by the Love impell\'d,\nThat moves the sun in heav\'n and all the stars.\n\n\nNOTES TO PARADISE\n\n\nCANTO 1\n\nVerse 12.  Benign Apollo.]  Chaucer has imitated this invention\nvery closely at the beginning of the Third Booke of Fame.\n\nIf, divine vertue, thou\nWilt helpe me to shewe  now\nThat in my head ymarked is,\n     * * * * *\nThou shalt see me go as blive\nUnto the next laurer I see,\nAnd kisse it for it is thy tree\nNow entre thou my breast anone.\n\nv. 15.  Thus for.]  He appears to mean nothing more than that\nthis part of his poem will require a greater exertion of his\npowers than the former.\n\nv. 19.  Marsyas.]  Ovid, Met. 1. vi. fab. 7.  Compare Boccaccio,\nII Filocopo, 1.  5. p. 25. v. ii. Ediz.  Fir.  1723.  \"Egli nel\nmio petto entri,\" &c. - \"May he enter my bosom, and let my voice\nsound like his own, when he made that daring mortal deserve to\ncome forth unsheathed from his limbs. \"\nv. 29.  Caesar, or bard.]  So Petrarch, Son.  Par. Prima.\n\nArbor vittoriosa e trionfale,\nOnor d\'imperadori e di poeti.\n\nAnd Spenser, F. Q. b. i. c. 1.  st. 9,\nThe laurel, meed of mighty conquerours\nAnd poets sage.\n\nv. 37.  Through that.]  \"Where the four circles, the horizon, the\nzodiac, the equator, and the equinoctial colure, join; the last\nthreeintersecting each other so as to form three crosses, as may\nbe seen in the armillary sphere.\"\n\nv. 39.  In happiest constellation.]  Aries.  Some understand the\nplanetVenus by the \"miglior stella \"\n\nv. 44.  To the left.]  Being in the opposite hemisphere to ours,\nBeatrice that she may behold the rising sun, turns herself to the\nleft.\n\nv. 47.  As from the first a second beam.]  \"Like a reflected\nsunbeam,\" which he compares to a pilgrim hastening homewards.\n\nNe simil tanto mal raggio secondo\nDal primo usci.\nFilicaja, canz. 15. st. 4.\n\nv. 58.  As iron that comes boiling from the fire.]  So Milton,\nP.  L.  b. iii.  594.\n--As glowing iron with fire.\n\nv. 69.  Upon the day appear\'d.\n\n--If the heaven had ywonne,\nAll new of God another sunne.\nChaucer, First Booke of Fame\n\nE par ch\' agginuga un altro sole al cielo.\nAriosto, O F.  c.  x.  st.  109.\n\nEd ecco un lustro lampeggiar d\' intorno\nChe sole a sole aggiunse e giorno a giorno.\nManno, Adone.  c. xi. st. 27.\n\nQuando a paro col sol ma piu lucente\nL\'angelo gli appari sull; oriente\nTasso, G. L. c. i.\n\n-Seems another morn\nRis\'n on mid-noon.\nMilton, P. L. b. v. 311.\n\nCompare Euripides, Ion. 1550.  [GREEK HERE]\n66.  as Glaucus. ] Ovid, Met. 1.  Xiii. Fab.  9\n\nv. 71.  If.]  \"Thou O divine Spirit, knowest  whether 1 had not\nrisen above my human nature, and were not merely such as thou\nhadst then, formed me.\"\n\nv.  125.  Through sluggishness.]\nPerch\' a risponder la materia e sorda.\n\nSo Filicaja, canz.  vi. st 9.\nPerche a risponder la discordia e sorda\n\n\"The workman hath i");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ON\\FIght.tX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3982; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 61: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST61(void)
{
    // informacje o teście
    test_start(61, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[5165] = "";

                strcat(expected_filecontent, "ns with William II and Henry I respecting the immunities\nand investitures.  There is much depth and precisian in his\ntheological  works.\" Tiraboschi, Stor.  della Lett. Ital. t. iii.\n\n1. iv. c. 2. Ibid.  c. v.  \"It is an observation made by many\nmodern writers, that the demonstration of the existence of God,\ntaken from the idea of a Supreme Being, of which Des Cartes is\nthought to be the author, was so many ages back discovered and\nbrought to light by Anselm.  Leibnitz himself makes\nthe remark, vol. v. Oper.  p. 570.  Edit.  Genev. 1768.\"\n\nv. 129.  Donatus.]  Aelius Donatus, the grammarian, in the fourth\ncentury, one of the preceptors of St. Jerome.\n\nv. 130.  Raban.]  \"Rabanus Maurus, Archbishop of Mentz, is\ndeservedly placed at the head of the Latin writers of this age.\"\nMosheim, v. ii. cent. ix. p.  2 c. 2.  14.\n\nv. 131.  Joachim.]  Abbot of Flora in Calabria; \"whom the\nmultitude revered as a person divinely inspired and equal to the\nmost illustrious prophets of ancient times.\"  Ibid.  v. iii.\ncent. xiii. p. 2. c. 2. 33.\n\nv. 134.  A peer.]  St. Dominic.\n\nCANTO XIII\n\nv. 1.  Let him.]  \"Whoever would conceive the sight that now\npresented itself to me, must imagine to himself fifteen of the\nbrightest stars in heaven, together with seven stars of Arcturus\nMajor and two of Arcturus Minor, ranged in two circles, one\nwithin the other, each resembling the crown of Ariadne, and\nmoving round m opposite directions.\"\n\nv. 21.  The Chiava.]  See Hell, Canto XXIX. 45.\n\nv. 29.  That luminary.]  Thomas Aquinas.\n\nv. 31.  One ear.]  \"Having solved one of thy questions, I proceed\nto answer the other.  Thou thinkest, then, that Adam and Christ\nwere both endued with all the perfection of which the human\nnature is capable and therefore wonderest at what has been said\nconcerning Solomon\"\n\nv. 48.  That.]  \"Things corruptible and incorruptible, are only\nemanations from the archetypal idea residing in the Divine mind.\"\n\nv. 52.  His brightness.]  The Word: the Son of God.\n\nv. 53.  His love triune with them.]  The Holy Ghost.\n\nv. 55.  New existences.]  Angels and human souls.\n\nv. 57.  The lowest powers.]  Irrational life and brute matter.\n\nv. 62.  Their wax and that which moulds it.]  Matter, and the\nvirtue or energy that acts on it.\n\nv. 68.  The heav\'n.]  The influence of the planetary bodies.\n\nv. 77.  The clay.]  Adam.\n\nv. 88.  Who ask\'d.]  \"He did not desire to know the number of the\nstars, or to pry into the subtleties of metaphysical and\nmathematical science: but asked for that wisdom which might fit\nhim for his kingly office.\"\n\nv. 120.  --Parmenides Melissus Bryso.]\nFor the singular opinions entertained by the two former of these\nheathen philosophers, see Diogenes Laertius, 1. ix. and Aristot.\nde Caelo, 1. iii. c. 1 and Phys. l. i. c. 2. The last is also\ntwice adduced by 2. Aristotle (Anal Post. 1. i. c. 9. and Rhet.\n1. iii. c. 2.) as 3. affording instances of false reasoning.\n\nv. 123.  Sabellius, Arius.]  Well-known heretics.\n\nv. 124.  Scymitars.] A passage in the travels of\nBertradon de la Brocquiere, translated by Mr. Johnes, will\nexplain this\nallusion, which has given some trouble to the commentators.  That\ntraveler, who wrote before Dante, informs us, p. 138, that the\nwandering Arabs used their scymitars as mirrors.\n\nv. 126.  Let not.]  \"Let not short-sighted mortals presume to\ndecide on the future doom of any man, from a consideration of his\npresent character and actions.\"\n\nCANTO XIV\n\nv. 5.  Such was the image.]  The voice of Thomas Aquinas\nproceeding, from the circle to the centre and that of Beatrice\nfrom the centre to the circle.\n\nv. 26.  Him.]  Literally translated by Chaucer, Troilus and\nCresseide.\n\nThou one two, and three eterne on live\nThat raignest aie in three, two and one\nUncircumscript, and all maist circonscrive,\n\nv. 81. The goodliest light.]  Solomon.\n\nv. 78.  To more lofty bliss.]  To the planet Mars.\n\nv. 94.  The venerable sign.]  The cross.\n\nv. 125.  He.]  \"He who considers that the eyes of Beatrice became\nmore radiant the higher we ascended, must not wonder that I do\nnot except even them as I had not yet beheld them s");
    strcat(expected_filecontent, "ince our\nentrance into this planet.\"\n\nCANTO XV\n\nv. 24.  Our greater Muse.]  Virgil Aen.  1. vi. 684.\nv. 84.  I am thy root.]  Cacciaguida, father to Alighieri, of\nwhom our Poet was the great-grandson.\n\nv. 89.  The mountain.]  Purgatory.\n\nv. 92.  Florence.]  See G. Villani, l. iii.  c. 2.\n\nv. 93.  Which calls her still.]  The public clock being still\nwithin the circuit of the ancient walls.\n\nv. 98.  When.]  When the women were not married at too early an\nage, and did not expect too large a portion.\n\nv. 101.  Void.]  Through the civil wars.\n\nv. 102 Sardanapalus.]  The luxurious monarch of Assyria Juvenal\nis here imitated, who uses his name for an instance of\neffeminacy.  Sat.\n\nv. 103.  Montemalo ] Either an elevated spot between Rome and\nViterbo, or Monte Mario, the site of the villa Mellini,\ncommanding a view of Rome.\n\nv. 101.  Our suburban turret.]  Uccellatojo, near Florence, from\nwhence that city was discovered.\n\nv. 103.  Bellincion Berti.]  Hell, Canto XVI. 38.  nd Notes.\nThere is a curious description of the simple manner in which the\nearlier Floren");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\on\\eaT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 5164; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 62: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST62(void)
{
    // informacje o teście
    test_start(62, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[4097] = "";

                strcat(expected_filecontent, " go they over through the umber\'d wave,\nAnd ever they on the opposing bank\nBe landed, on this side another throng\nStill gathers.  \"Son,\" thus spake the courteous guide,\n\"Those, who die subject to the wrath of God,\nAll here together come from every clime,\nAnd to o\'erpass the river are not loth:\nFor so heaven\'s justice goads them on, that fear\nIs turn\'d into desire.  Hence ne\'er hath past\nGood spirit.  If of thee Charon complain,\nNow mayst thou know the import of his words.\"\n     This said, the gloomy region trembling shook\nSo terribly, that yet with clammy dews\nFear chills my brow.  The sad earth gave a blast,\nThat, lightening, shot forth a vermilion flame,\nWhich all my senses conquer\'d quite, and I\nDown dropp\'d, as one with sudden slumber seiz\'d.\n\n\n\nCANTO IV\n\nBROKE the deep slumber in my brain a crash\nOf heavy thunder, that I shook myself,\nAs one by main force rous\'d.  Risen upright,\nMy rested eyes I mov\'d around, and search\'d\nWith fixed ken to know what place it was,\nWherein I stood.  For certain on the brink\nI found me of the lamentable vale,\nThe dread abyss, that joins a thund\'rous sound\nOf plaints innumerable.  Dark and deep,\nAnd thick with clouds o\'erspread, mine eye in vain\nExplor\'d its bottom, nor could aught discern.\n     \"Now let us to the blind world there beneath\nDescend;\" the bard began all pale of look:\n\"I go the first, and thou shalt follow next.\"\n     Then I his alter\'d hue perceiving, thus:\n\"How may I speed, if thou yieldest to dread,\nWho still art wont to comfort me in doubt?\"\n     He then:  \"The anguish of that race below\nWith pity stains my cheek, which thou for fear\nMistakest.  Let us on.  Our length of way\nUrges to haste.\"  Onward, this said, he mov\'d;\nAnd ent\'ring led me with him on the bounds\nOf the first circle, that surrounds th\' abyss.\nHere, as mine ear could note, no plaint was heard\nExcept of sighs, that made th\' eternal air\nTremble, not caus\'d by tortures, but from grief\nFelt by those multitudes, many and vast,\nOf men, women, and infants.  Then to me\nThe gentle guide:  \"Inquir\'st thou not what spirits\nAre these, which thou beholdest?  Ere thou pass\nFarther, I would thou know, that these of sin\nWere blameless; and if aught they merited,\nIt profits not, since baptism was not theirs,\nThe portal to thy faith.  If they before\nThe Gospel liv\'d, they serv\'d not God aright;\nAnd among such am I. For these defects,\nAnd for no other evil, we are lost;\nOnly so far afflicted, that we live\nDesiring without hope.\"  So grief assail\'d\nMy heart at hearing this, for well I knew\nSuspended in that Limbo many a soul\nOf mighty worth.  \"O tell me, sire rever\'d!\nTell me, my master!\"  I began through wish\nOf full assurance in that holy faith,\nWhich vanquishes all error; \"say, did e\'er\nAny, or through his own or other\'s merit,\nCome forth from thence, whom afterward was blest?\"\n     Piercing the secret purport of my speech,\nHe answer\'d: \"I was new to that estate,\nWhen I beheld a puissant one arrive\nAmongst us, with victorious trophy crown\'d.\nHe forth the shade of our first parent drew,\nAbel his child, and Noah righteous man,\nOf Moses lawgiver for faith approv\'d,\nOf patriarch Abraham, and David king,\nIsrael with his sire and with his sons,\nNor without Rachel whom so hard he won,\nAnd others many more, whom he to bliss\nExalted.  Before these, be thou assur\'d,\nNo spirit of human kind was ever sav\'d.\"\n     We, while he spake, ceas\'d not our onward road,\nStill passing through the wood; for so I name\nThose spirits thick beset.  We were not far\nOn this side from the summit, when I kenn\'d\nA flame, that o\'er the darken\'d hemisphere\nPrevailing shin\'d.  Yet we a little space\nWere distant, not so far but I in part\nDiscover\'d, that a tribe in honour high\nThat place possess\'d.  \"O thou, who every art\nAnd science valu\'st!  who are these, that boast\nSuch honour, separate from all the rest?\"\n     He answer\'d: \"The renown of their great names\nThat echoes through your world above, acquires\nFavour in heaven, which holds them thus advanc\'d.\"\nMeantime a voice I heard: \"Honour the bard\nSublime!  his shade returns that left us late!\"\nNo sooner");
    strcat(expected_filecontent, " ");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ON\\pRovIDe.Txt");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 4096; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 63: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST63(void)
{
    // informacje o teście
    test_start(63, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[84] = "";

                strcat(expected_filecontent, "y was sinking, when the\' angel of God\nAppear\'d before us.  Joy was in his mien.\nFor");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ON\\THICK.bin");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 83; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 64: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST64(void)
{
    // informacje o teście
    test_start(64, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[7822] = "";

                strcat(expected_filecontent, "nto X.  This event happened in 1260.\n\nv. 113.  Him of Duera.]  Buoso of Cremona, of the family of\nDuera, who was bribed by Guy de Montfort, to leave a pass between\nPiedmont and Parma, with the defence of which he had been\nentrusted by the Ghibellines, open to the army of Charles of\nAnjou, A.D. 1265, at which the people of Cremona were so enraged,\nthat they extirpated the whole family.  G. Villani, l. vii. c. 4.\n\nv. 118.  Beccaria.]  Abbot of Vallombrosa, who was the Pope\'s\nLegate at Florence, where his intrigues in favour of the\nGhibellines being discovered, he was beheaded. I do not find the\noccurrence in Vallini, nor do the commentators say to what pope\nhe was legate. By Landino he is reported to have been from Parma,\nby Vellutello from Pavia.\n\nv. 118.  Soldanieri.]  \"Gianni Soldanieri,\"  says Villani, Hist.\nl. vii. c14, \"put himself at the head of the people, in the hopes\nof rising into power, not aware that the result would be mischief\nto the Ghibelline party, and his own ruin; an event which seems\never to have befallen him, who has headed the populace in\nFlorence.\" A.D. 1266.\n\nv. 119.  Ganellon.]  The betrayer of Charlemain, mentioned by\nArchbishop Turpin.  He is a common instance of treachery with the\npoets of the middle ages.\n        Trop son fol e mal pensant,\n        Pis valent que Guenelon.\n               Thibaut, roi de Navarre\n        O new Scariot, and new Ganilion,\n        O false dissembler, &c.\n               Chaucer, Nonne\'s Prieste\'s Tale\nAnd in the Monke\'s Tale, Peter of Spaine.\nv. 119.  Tribaldello.]  Tribaldello de\'Manfredi, who was bribed\nto betray the city of Faonza, A. D. 1282. G. Villani, l. vii. c.\n80\n\nv. 128.  Tydeus.] See Statius, Theb. l. viii. ad finem.\n\nCANTO XXXIII.\n\nv. 14.  Count Ugolino.]  \"In the year 1288, in the month of July,\nPisa was much divided by competitors for the sovereignty; one\nparty, composed of certain of the Guelphi, being headed by the\nJudge Nino di Gallura de\'Visconti; another, consisting of others\nof the same faction, by the Count Ugolino de\' Gherardeschi; and\nthe third by the Archbishop Ruggieri degli Ubaldini, with the\nLanfranchi, Sismondi, Gualandi, and other Ghibelline houses.  The\nCount Ugolino,to effect his purpose, united with the Archbishop\nand his party, and having betrayed Nino, his sister\'s son, they\ncontrived that he and his followers should either be driven out\nof Pisa, or their persons seized.  Nino hearing this, and not\nseeing any means of defending himself, retired to Calci, his\ncastle, and formed an alliance with the Florentines and people of\nLucca, against the Pisans.  The Count, before Nino was gone, in\norder to cover his treachery, when everything was settled for his\nexpulsion, quitted Pisa, and repaired to a manor of his called\nSettimo; whence, as soon as he was informed of Nino\'s departure,\nhe returned to Pisa with great rejoicing and festivity, and was\nelevated to the supreme power with every demonstration of triumph\nand honour.  But his greatness was not of long continuauce.  It\npleased the Almighty that a total reverse of fortune should\nensue, as a punishment for his acts of treachery and guilt:  for\nhe was said to have poisoned the Count Anselmo da Capraia, his\nsister\'s son, on account of the envy and fear excited in his mind\nby the high esteem in which the gracious manners of Anselmo were\nheld by the Pisans.  The power of the Guelphi being so much\ndiminished, the Archbishop devised means to betray the Count\nUglino and caused him to be suddenly attacked in his palace by\nthe fury of the people, whom he had exasperated, by telling them\nthat Ugolino had betrayed Pisa, and given up their castles to the\ncitizens of Florence and of Lucca. He was immediately compelled\nto surrender; his bastard son and his grandson fell in the\nassault; and two of his sons, with their two sons also, were\nconveyed to prison.\"  G. Villani l. vii. c. 120.\n\n\"In the following march, the Pisans, who had imprisoned the Count\nUglino, with two of his sons and two of his grandchildren, the\noffspring of his son the Count Guelfo, in a tower on the Piazza\nof the Anzania, caused th");
    strcat(expected_filecontent, "e tower to be locked, the key thrown\ninto the Arno, and all food to be withheld from them.  In a few\ndays they died of hunger; but the Count first with loud cries\ndeclared his penitence, and yet neither priest nor friar was\nallowed to shrive him.  All the five, when dead, were dragged out\nof the prison, and meanly interred; and from thence forward the\ntower was called the tower of famine, and so shall ever be.\"\nIbid. c. 127.\n\nChancer has briefly told Ugolino\'s story. See Monke\'s Tale,\nHugeline of Pise.\n\nv. 29.  Unto the mountain.]  The mountain S. Giuliano, between\nPisa and Lucca.\n\nv. 59. Thou gav\'st.]\n               Tu ne vestisti\n        Queste misere carni, e tu le spoglia.\nImitated by Filicaja, Canz. iii.\n        Di questa imperial caduca spoglia\n        Tu, Signor, me vestisti e tu mi spoglia:\n        Ben puoi\'l Regno me tor tu che me\'l desti.\nAnd by Maffei, in the Merope:\n               Tu disciogleste\n        Queste misere membra e tu le annodi.\n\nv. 79. In that fair region.]\n        Del bel paese la, dove\'l si suona.\nItaly as explained by Dante himself, in his treatise De Vulg.\nEloq. l. i. c. 8. \"Qui autem Si dicunt a praedictis finibus.\n(Januensiem) Oreintalem (Meridionalis Europae partem) tenent;\nvidelicet usque ad promontorium illud Italiae, qua sinus\nAdriatici maris incipit et Siciliam.\"\n\nv. 82.  Capraia and Gorgona.]  Small islands near the mouth of\nthe Arno.\n\nv. 94.  There very weeping suffers not to weep,]\n        Lo pianto stesso li pianger non lascia.\nSo Giusto de\'Conti, Bella Mano. Son. \"Quanto il ciel.\"\n        Che il troppo pianto a me pianger non lassa.\nv. 116.  The friar Albigero.]  Alberigo de\'Manfredi, of Faenza,\none of the Frati Godenti, Joyons Friars who having quarrelled\nwith some of his brotherhood, under pretence of wishing to be\nreconciled, invited them to a banquet, at the conclusion of which\nhe called for the fruit, a signal for the assassins to rush in\nand dispatch those whom he had marked for destruction.  Hence,\nadds Landino, it is said proverbially of one who has been\nstabbed, that he has had some of the friar Alberigo\'s fruit.\nThus Pulci, Morg. Magg. c. xxv.\n        Le frutte amare di frate Alberico.\n\nv. 123.  Ptolomea.]  This circle is named Ptolomea from Ptolemy,\nthe son of Abubus, by whom Simon and his sons were murdered, at a\ngreat banquet he had made for them. See Maccabees, ch xvi.\n\nv. 126.  The glazed tear-drops.]\n\n        -sorrow\'s eye, glazed with blinding tears.\n               Shakspeare, Rich. II. a. 2. s. 2.\n\nv. 136.  Branca Doria.]  The family of Doria was possessed of\ngreat influence in Genoa.  Branca is said to have murdered his\nfather-in-law, Michel Zanche, introduced in Canto XXII.\n\nv. 162  Romagna\'s darkest spirit.]  The friar Alberigo.\n\n\n\nCanto XXXIV.\n\nv. 6.  A wind-mill.]  The author of the Caliph Vathek, in the\nnotes to that tale, justly observes, that it is more than\nprobable that Don Quixote\'s mistake of the wind-mills for giants\nwas suggested to Cervantes by this simile.\n\nv. 37. Three faces.]  It can scarcely be doubted but that Milton\nderived his description of Satan in those lines,\n\n               Each passion dimm\'d his face\n        Thrice chang\'d with pale, ire, envy, and despair.\n               P. L. b. iv. 114.\nfrom this passage, coupled with the remark of Vellutello upon it:\n\n\"The first of these sins is anger which he signifies by the red\nface; the second, represented by that between pale and yellow is\nenvy and not, as others have said, avarice; and the third,\ndenoted by the black, is a melancholy humour that causes a man\'s\nthoughts to be dark and evil, and averse from all joy and\ntranquillity.\"\n\nv. 44. Sails.]\n               --His sail-broad vans\n        He spreads for flight.\n              ");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ON\\CRoSs.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 7821; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 65: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST65(void)
{
    // informacje o teście
    test_start(65, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[933] = "";

                strcat(expected_filecontent, "at Paris.  When the race\nOf ancient kings had vanish\'d (all save one\nWrapt up in sable weeds) within my gripe\nI found the reins of empire, and such powers\nOf new acquirement, with full store of friends,\nThat soon the widow\'d circlet of the crown\nWas girt upon the temples of my son,\nHe, from whose bones th\' anointed race begins.\nTill the great dower of Provence had remov\'d\nThe stains, that yet obscur\'d our lowly blood,\nIts sway indeed was narrow, but howe\'er\nIt wrought no evil: there, with force and lies,\nBegan its rapine; after, for amends,\nPoitou it seiz\'d, Navarre and Gascony.\nTo Italy came Charles, and for amends\nYoung Conradine an innocent victim slew,\nAnd sent th\' angelic teacher back to heav\'n,\nStill for amends.  I see the time at hand,\nThat forth from France invites another Charles\nTo make himself and kindred better known.\nUnarm\'d he issues, saving with that lance,\nWhich the arch-traitor tilted with; and that\nHe");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\On\\HeR");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 932; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 66: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST66(void)
{
    // informacje o teście
    test_start(66, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[4097] = "";

                strcat(expected_filecontent, "n the furnace, every cirque\nEbullient shot forth scintillating fires:\nAnd every sparkle shivering to new blaze,\nIn number did outmillion the account\nReduplicate upon the chequer\'d board.\nThen heard I echoing on from choir to choir,\n\"Hosanna,\" to the fixed point, that holds,\nAnd shall for ever hold them to their place,\nFrom everlasting, irremovable.\n     Musing awhile I stood: and she, who saw\nby inward meditations, thus began:\n\"In the first circles, they, whom thou beheldst,\nAre seraphim and cherubim.  Thus swift\nFollow their hoops, in likeness to the point,\nNear as they can, approaching; and they can\nThe more, the loftier their vision.  Those,\nThat round them fleet, gazing the Godhead next,\nAre thrones; in whom the first trine ends.  And all\nAre blessed, even as their sight descends\nDeeper into the truth, wherein rest is\nFor every mind.  Thus happiness hath root\nIn seeing, not in  loving, which of sight\nIs aftergrowth.  And of the seeing such\nThe meed, as unto each in due degree\nGrace and good-will their measure have assign\'d.\nThe other trine, that with still opening buds\nIn this eternal springtide blossom fair,\nFearless of bruising from the nightly ram,\nBreathe up in warbled melodies threefold\nHosannas blending ever, from the three\nTransmitted. hierarchy of gods, for aye\nRejoicing, dominations first, next then\nVirtues, and powers the third.  The next to whom\nAre princedoms and archangels, with glad round\nTo tread their festal ring; and last the band\nAngelical, disporting in their sphere.\nAll, as they circle in their orders, look\nAloft, and downward with such sway prevail,\nThat all with mutual impulse tend to God.\nThese once a mortal view beheld.  Desire\nIn Dionysius so intently wrought,\nThat he, as I have done rang\'d them; and nam\'d\nTheir orders, marshal\'d in his thought.  From him\nDissentient, one refus\'d his sacred read.\nBut soon as in this heav\'n his doubting eyes\nWere open\'d, Gregory at his error smil\'d\nNor marvel, that a denizen of earth\nShould scan such secret truth; for he had learnt\nBoth this and much beside of these our orbs,\nFrom an eye-witness to heav\'n\'s mysteries.\"\n\n\n\nCANTO XXIX\n\nNo longer than what time Latona\'s twins\nCover\'d of Libra and the fleecy star,\nTogether both, girding the\' horizon hang,\nIn even balance from the zenith pois\'d,\nTill from that verge, each, changing hemisphere,\nPart the nice level; e\'en so brief a space\nDid Beatrice\'s silence hold.  A smile\nBat painted on her cheek; and her fix\'d gaze\nBent on the point, at which my vision fail\'d:\nWhen thus her words resuming she began:\n\"I speak, nor what thou wouldst inquire demand;\nFor I have mark\'d it, where all time and place\nAre present.  Not for increase to himself\nOf good, which may not be increas\'d, but forth\nTo manifest his glory by its beams,\nInhabiting his own eternity,\nBeyond time\'s limit or what bound soe\'er\nTo circumscribe his being, as he will\'d,\nInto new natures, like unto himself,\nEternal Love unfolded.  Nor before,\nAs if in dull inaction torpid lay.\nFor not in process of before or aft\nUpon these waters mov\'d the Spirit of God.\nSimple and mix\'d, both form and substance, forth\nTo perfect being started, like three darts\nShot from a bow three-corded.  And as ray\nIn crystal, glass, and amber, shines entire,\nE\'en at the moment of its issuing; thus\nDid, from th\' eternal Sovran, beam entire\nHis threefold operation, at one act\nProduc\'d coeval.  Yet in order each\nCreated his due station knew: those highest,\nWho pure intelligence were made: mere power\nThe lowest: in the midst, bound with strict league,\nIntelligence and power, unsever\'d bond.\nLong tract of ages by the angels past,\nEre the creating of another world,\nDescrib\'d on Jerome\'s pages thou hast seen.\nBut that what I disclose to thee is true,\nThose penmen, whom the Holy Spirit mov\'d\nIn many a passage of their sacred book\nAttest; as thou by diligent search shalt find\nAnd reason in some sort discerns the same,\nWho scarce would grant the heav\'nly ministers\nOf their perfection void, so long a space.\nThus when and where these spirits of love were made,\nThou know\'st, and how: and knowing hast");
    strcat(expected_filecontent, " ");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ON\\cLOUD");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 4096; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 67: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST67(void)
{
    // informacje o teście
    test_start(67, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[424] = "";

                strcat(expected_filecontent, "at these people.]  That the inhabitants of the above-\nmentioned places had not been mixed with the citizens: nor the\nlimits of Florence extended beyond Galluzzo and Trespiano.\"\n\nv. 54.  Aguglione\'s hind and Signa\'s.]  Baldo of Aguglione, and\nBonifazio of Signa.\n\nv. 56.  Had not the people.]  If Rome had continued in her\nallegiance to the emperor, and the Guelph and Ghibelline factions\nhad thus been prevented, Florence w");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\oN\\mUsT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 423; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 68: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST68(void)
{
    // informacje o teście
    test_start(68, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[613] = "";

                strcat(expected_filecontent, " its hand\nAudience implor\'d. Both palms it join\'d and rais\'d,\nFixing its steadfast gaze towards the east,\nAs telling God, \"I care for naught beside.\"\n     \"Te Lucis Ante,\" so devoutly then\nCame from its lip, and in so soft a strain,\nThat all my sense in ravishment was lost.\nAnd the rest after, softly and devout,\nFollow\'d through all the hymn, with upward gaze\nDirected to the bright supernal wheels.\n     Here, reader!  for the truth makes thine eyes keen:\nFor of so subtle texture is this veil,\nThat thou with ease mayst pass it through unmark\'d.\n     I saw that gentle band silently next\nLook up, as if in ex");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\On\\BeliEVE");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 612; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 69: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST69(void)
{
    // informacje o teście
    test_start(69, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[5121] = "";

                strcat(expected_filecontent, "reat\nmilitary talents.\"  Hist. of Flor. b. ii.\n\nv. 52.  A shade.]  The spirit of Cavalcante Cavalcanti, a noble\nFlorentine, of the Guelph party.\n\nv. 59.  My son.]  Guido, the son of Cavalcante Cavalcanti; \"he\nwhom I call the first of my friends,\" says Dante in his Vita\nNuova, where the commencement of their friendship is related.\n>From the character given of him by contemporary writers his\ntemper was well formed to assimilate with that of our poet. \"He\nwas,\" according to G. Villani, l. viii. c. 41. \"of a\nphilosophical and elegant mind, if he had not been too delicate\nand fastidious.\" And Dino Compagni terms him \"a young and noble\nknight, brave and courteous, but of a lofty scornful spirit, much\naddicted to solitude and study.\" Muratori. Rer. Ital. Script t. 9\nl. 1. p. 481.  He died, either in exile at Serrazana, or soon\nafter his return to Florence, December 1300, during the spring of\nwhich year the action of this poem is supposed to be passing.\nv. 62.         Guido thy son\n        Had in contempt.]\nGuido Cavalcanti, being more given to philosophy than poetry, was\nperhaps no great admirer of Virgil. Some poetical compositions by\nGuido are, however, still extant; and his reputation for skill in\nthe art was such as to eclipse that of his predecessor and\nnamesake Guido Guinicelli, as we shall see in the Purgatory,\nCanto XI.  His \"Canzone sopra il Terreno Amore\" was thought\nworthy of being illustrated by numerous and ample commentaries.\nCrescimbeni Ist. della Volg. Poes. l. v.\nFor a playful sonnet which Dante addressed to him, and a spirited\ntranslation of it, see Hayley\'s Essay on Epic Poetry, Notes to\nEp. iii.\n\nv. 66.  Saidst thou he had?]  In Aeschylus, the shade of Darius\nis represented as inquiring with similar anxiety after the fate\nof his son Xerxes.\n\n[GREEK HERE]\n\nAtossa:  Xerxes astonish\'d, desolate, alone--\nGhost of Dar:  How will this end?  Nay, pause not.  Is he safe?\n               The Persians.  Potter\'s Translation.\n\nv. 77.  Not yet fifty times.]  \"Not fifty months shall be passed,\nbefore thou shalt learn, by woeful experience, the difficulty of\nreturning from banishment to thy native city\"\n\nv.83.  The slaughter.]  \"By means of Farinata degli Uberti, the\nGuelfi were conquered by the army of King Manfredi, near the\nriver Arbia, with so great a slaughter, that those who escaped\nfrom that defeat took refuge not in Florence, which city they\nconsidered as lost to them, but in Lucca.\"  Macchiavelli. Hist.\nof Flor. b 2.\n\nv. 86.  Such orisons.]  This appears to allude to certain prayers\nwhich were offered up in the churches of Florence, for\ndeliverance from the hostile attempts of the Uberti.\n\nv. 90.  Singly there I stood.]  Guido Novello assembled a council\nof the Ghibellini at Empoli where it was agreed by all, that, in\norder to maintain the ascendancy of the Ghibelline party in\nTuscany, it was necessary to destroy Florence, which could serve\nonly (the people of that city beingvGuelfi) to enable the party\nattached to the church to recover its strength.  This cruel\nsentence, passed upon so noble a city, met with no opposition\nfrom any of its citizens or friends, except Farinata degli\nUberti, who openly and without reserve forbade the measure,\naffirming that he had endured so many hardships, and encountered\nso many dangers, with no other view than that of being able to\npass his days in his own country. Macchiavelli. Hist. of Flor. b.\n2.\n\nv. 103.  My fault.]  Dante felt remorse for not having returned\nan immediate answer to the inquiry of Cavalcante, from which\ndelay he was led to believe that his son Guido was no longer\nliving.\n\nv. 120.  Frederick.]  The Emperor Frederick the Second, who died\nin 1250. See Notes to Canto XIII.\n\nv. 121.  The Lord Cardinal.]  Ottaviano Ubaldini, a Florentine,\nmade Cardinal in 1245, and deceased about 1273.  On account of\nhis great influence, he was generally known by the appellation of\n\"the Cardinal.\"  It is reported of him that he declared, if there\nwere any such thing as a human soul, he had lost his for the\nGhibellini.\n\nv. 132.  Her gracious beam.]  Beatrice.\n\nCANTO XI\n\nv. 9.  Pope A");
    strcat(expected_filecontent, "nastasius.]  The commentators are not agreed\nconcerning the identity of the person, who is here mentioned as a\nfollower of the heretical Photinus.  By some he is supposed to\nhave been Anastasius the Second, by others, the Fourth of that\nname; while a third set, jealous of the integrity of the papal\nfaith, contend that our poet has confounded him with Anastasius\n1. Emperor of the East.\n\nv. 17.  My son.]  The remainder of the present Canto may be\nconsidered as a syllabus of the whole of this part of the poem.\n\nv. 48.  And sorrows.]  This fine moral, that not to enjoy our\nbeing is to be ungrateful to the Author of it, is well expressed\nin Spenser, F. Q. b. iv. c. viii. st. 15.\n        For he whose daies in wilful woe are worne\n        The grace of his Creator doth despise,\n        That will not use his gifts for thankless\nnigardise.\n\nv. 53.  Cahors.]  A city in Guienne, much frequented by usurers\n\nv. 83.  Thy ethic page.]  He refers to Aristotle\'s Ethics.\n\n[GREEK HERE]\n\n\"In the next place, entering, on another di");

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\On\\FiNgER");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 5120; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 70: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST70(void)
{
    // informacje o teście
    test_start(70, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(6144, 1);
            char expected_filecontent[6145] = "";

            strcat(expected_filecontent, "pric of Albano and a cardinal\'s\nhat.  He was born at Bagnoregio or Bagnorea, in Tuscany, A.D.\n1221, and died in 1274.\"  Dict. Histor. par Chaudon et Delandine.\nEd.  Lyon.  1804.\n\nv. 28.  The love.]  By an act of mutual courtesy, Buonaventura,\na Franciscan, is made to proclaim the praises of St. Dominic,\nas Thomas Aquinas, a Dominican, has celebrated those of St.\nFrancis.\n\nv. 42.  In that clime.]  Spain.\n\nv. 48.  Callaroga.]  Between Osma and Aranda, in Old Castile,\ndesignated by the royal coat of arms.\n\nv. 51.  The loving minion of the Christian faith.]  Dominic was\nborn April 5, 1170, and died August 6, 1221.  His birthplace,\nCallaroga; his father and mother\'s names, Felix and Joanna, his\nmother\'s dream; his name of Dominic, given him in consequence of\na vision by a noble matron, who stood sponsor to him, are all\ntold in an anonymous life of the saint, said to be written in the\nthirteenth century, and published by Quetif and Echard,\nScriptores Ordinis Praedicatorum.  Par.  1719. fol. t 1.  p. 25.\nThese writers deny his having been an inquisitor, and indeed the\nestablishment of the inquisition itself before the fourth Lateran\ncouncil.  Ibid.  p. 88.\n\nv. 55.  In the mother\'s womb.]  His mother, when pregnant with\nhim, is said to have dreamt that she should bring forth a white\nand black dog, with a lighted torch in its mouth.\n\nv. 59.  The dame.]  His godmother\'s dream was, that he had one\nstar in his forehead, and another in the nape of his neck, from\nwhich he communicated light to the east and the west.\n\nv. 73.  Felix.]  Felix Gusman.\n\nv. 75.  As men interpret it.]  Grace or gift of the Lord.\n\nv. 77.  Ostiense.]  A cardinal, who explained the decretals.\n\nv. 77.  Taddeo.]  A physician, of Florence.\n\nv. 82.  The see.]  \"The apostolic see, which no longer continues\nits wonted liberality towards the indigent and deserving; not\nindeed  through its own fault, as its doctrines are still the\nsame, but through the fault of the pontiff, who is seated in it.\"\n\nv. 85.  No dispensation.]  Dominic did not ask license to\ncompound for the use of unjust acquisitions, by dedicating a part\nof them to pious purposes.\n\nv. 89.  In favour of that seed.]  \"For that seed of the divine\nword, from which have sprung up these four-and-twenty plants,\nthat now environ thee.\"\n\nv. 101.  But the track.]  \"But the rule of St. Francis is already\ndeserted and the lees of the wine are turned into mouldiness.\"\n\nv. 110.  Tares.]  He adverts to the parable of the taxes and the\nwheat.\n\nv. 111.  I question not.]  \"Some indeed might be found, who still\nobserve the rule of the order, but such would come neither from\nCasale nor Acquasparta:\" of the former of which places was\nUberto, one master general, by whom the discipline had been\nrelaxed; and of the latter, Matteo, another, who had enforced it\nwith unnecessary rigour.\n\nv. 121.  -Illuminato here,\nAnd Agostino.]\nTwo among the earliest followers of St. Francis.\n\nv. 125.  Hugues of St. Victor.]  A Saxon of the monastery of\nSaint  Victor at Paris, who fed ill 1142 at the age of\nforty-four.  \"A man distinguished by the fecundity of his genius,\nwho treated in his writings of all the branches of sacred and\nprofane erudition that were known in his time, and who composed\nseveral dissertations that are not destitute of merit.\"\nMaclaine\'s Mosheim, Eccl. Hist. v. iii . cent. xii. p. 2. 2. 23.\nI have looked into his writings, and found some reason for\nthis high eulogium.\n\nv. 125.  Piatro Mangiadore.]  \"Petrus Comestor, or the Eater,\nborn at Troyes, was canon and dean of that church, and afterwards\nchancellor of the church of Paris.  He relinquished these\nbenefices to become a regular canon of St. Victor at Paris, where\nhe died in 1198.  Chaudon et Delandine Dict. Hist. Ed. Lyon.\n1804. The work by which he is best known, is his Historia\nScolastica, which I shall have occasion to cite in the Notes to\nCanto XXVI.\n\nv. 126.  He of Spain.]  \"To Pope Adrian V succeeded John XXI a\nnative of Lisbon a man of great genius and extraordinary\nacquirements, especially in logic and in medicine, as his books,\nwritten in the name of Peter of S");
    strcat(expected_filecontent, "pain (by which he was known\nbefore he became Pope), may testify.  His life was not much\nlonger than that of his predecessors, for he was killed at\nViterbo, by the falling in of the roof of his chamber, after he\nhad been pontiff only eight months and as many days.\nA.D. 1277.  Mariana, Hist. de Esp. l. xiv.  c. 2.\n\nv. 128.  Chrysostom.]  The eloquent patriarch of Constantinople.\n\nv. 128.  Anselmo.]  \"Anselm, Archbishop of Canterbury, was born\nat Aosta, about 1034, and studied under Lanfrane at the monastery\nof Bec, in Normandy, where he afterwards devoted himself to a\nreligious life, in his twenty-seventh year.  In three years he\nwas made prior, and then abbot of that monastery!  from whence he\nwas taken, in 1093, to succeed to the archbishopric, vacant by\nthe death of Lanfrane. He enjoyed this dignity till his death, in\n1109, though it was disturbed by many\ndissentions with William II and Henry I respecting the immunities\nand investitures.  There is much depth and precisian in his\ntheological  works.\" Tiraboschi, Stor.  della Lett. Ital. t. iii.\n\n1. iv. c. 2. Ibid.  c. v.  \"It is an observation made by many\nmodern writers, that the demonstration of the existence of God,\ntaken from the idea of a Supreme Being, of which Des Cartes is\nthought to be the author, was so many ages back discovered and\nbrought to light by Anselm.  Leibnitz himself makes\nthe remark, vol. v. Oper.  p. 570.  Edit.  Genev. 1768.\"\n\nv. 129.  Donatus.]  Aelius Donatus, the grammarian, in the fourth\ncentury, one of the preceptors of St. Jerome.\n\nv. 130.  Raban.]  \"Rabanus Maurus, Archbishop of Mentz, is\ndeservedly placed at the head of the Latin writers of this age.\"\nMosheim, v. ii. cent. ix. p.  2 c. 2.  14.\n\nv. 131.  Joachim.]  Abbot of Flora in Calabria; \"whom the\nmultitude revered as a person divinely inspired and equal to the\nmost illustrious prophets of ancient times.\"  Ibid.  v. iii.\ncent. xiii. p. 2. c. 2. 33.\n\nv. 134.  A peer.]  St. Dominic.\n\nCANTO XIII\n\nv. 1.  Let him.]  \"Whoever would conceive the sight that now\npresented itself to me, m");

            struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "SuN");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int i;
            for (i = 0; i < 323; ++i)
            {
                int res = file_read(filecontent + 19 * i, 19, 1, file);
                test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            }

            int res = file_read(filecontent + 19 * i, 19, 1, file);
            test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6144);

            // jeśli jest, to raportuj błąd
            test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

            onerror_compare_memory(expected_filecontent, filecontent, 6144);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 71: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST71(void)
{
    // informacje o teście
    test_start(71, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char *filecontent0 = (char *)calloc(5344, 1);
    char *filecontent1 = (char *)calloc(727, 1);
    char *filecontent2 = (char *)calloc(6211, 1);
    char *filecontent3 = (char *)calloc(6144, 1);
    char *filecontent4 = (char *)calloc(5130, 1);
    char *filecontent5 = (char *)calloc(537, 1);

            char expected_filecontent0[5345] = "";
    char expected_filecontent1[728] = "";
    char expected_filecontent2[6212] = "";
    char expected_filecontent3[6145] = "";
    char expected_filecontent4[5131] = "";
    char expected_filecontent5[538] = "";

            strcat(expected_filecontent0, " he chooses!\"  I to him in few:\n\"Bard!  by that God, whom thou didst not adore,\nI do beseech thee (that this ill and worse\nI may escape) to lead me, where thou saidst,\nThat I Saint Peter\'s gate may view, and those\nWho as thou tell\'st, are in such dismal plight.\"\n     Onward he mov\'d, I close his steps pursu\'d.\n\n\n\nCANTO II\n\nNOW was the day departing, and the air,\nImbrown\'d with shadows, from their toils releas\'d\nAll animals on earth; and I alone\nPrepar\'d myself the conflict to sustain,\nBoth of sad pity, and that perilous road,\nWhich my unerring memory shall retrace.\n     O Muses!  O high genius!  now vouchsafe\nYour aid!  O mind!  that all I saw hast kept\nSafe in a written record, here thy worth\nAnd eminent endowments come to proof.\n     I thus began:  \"Bard!  thou who art my guide,\nConsider well, if virtue be in me\nSufficient, ere to this high enterprise\nThou trust me.  Thou hast told that Silvius\' sire,\nYet cloth\'d in corruptible flesh, among\nTh\' immortal tribes had entrance, and was there\nSensible present.  Yet if heaven\'s great Lord,\nAlmighty foe to ill, such favour shew\'d,\nIn contemplation of the high effect,\nBoth what and who from him should issue forth,\nIt seems in reason\'s judgment well deserv\'d:\nSith he of Rome, and of Rome\'s empire wide,\nIn heaven\'s empyreal height was chosen sire:\nBoth which, if truth be spoken, were ordain\'d\nAnd \'stablish\'d for the holy place, where sits\nWho to great Peter\'s sacred chair succeeds.\nHe from this journey, in thy song renown\'d,\nLearn\'d things, that to his victory gave rise\nAnd to the papal robe.  In after-times\nThe chosen vessel also travel\'d there,\nTo bring us back assurance in that faith,\nWhich is the entrance to salvation\'s way.\nBut I, why should I there presume?  or who\nPermits it?  not, Aeneas I nor Paul.\nMyself I deem not worthy, and none else\nWill deem me.  I, if on this voyage then\nI venture, fear it will in folly end.\nThou, who art wise, better my meaning know\'st,\nThan I can speak.\"  As one, who unresolves\nWhat he hath late resolv\'d, and with new thoughts\nChanges his purpose, from his first intent\nRemov\'d; e\'en such was I on that dun coast,\nWasting in thought my enterprise, at first\nSo eagerly embrac\'d.  \"If right thy words\nI scan,\" replied that shade magnanimous,\n\"Thy soul is by vile fear assail\'d, which oft\nSo overcasts a man, that he recoils\nFrom noblest resolution, like a beast\nAt some false semblance in the twilight gloom.\nThat from this terror thou mayst free thyself,\nI will instruct thee why I came, and what\nI heard in that same instant, when for thee\nGrief touch\'d me first.  I was among the tribe,\nWho rest suspended, when a dame, so blest\nAnd lovely, I besought her to command,\nCall\'d me; her eyes were brighter than the star\nOf day; and she with gentle voice and soft\nAngelically tun\'d her speech address\'d:\n\"O courteous shade of Mantua!  thou whose fame\nYet lives, and shall live long as nature lasts!\nA friend, not of my fortune but myself,\nOn the wide desert in his road has met\nHindrance so great, that he through fear has turn\'d.\nNow much I dread lest he past help have stray\'d,\nAnd I be ris\'n too late for his relief,\nFrom what in heaven of him I heard.  Speed now,\nAnd by thy eloquent persuasive tongue,\nAnd by all means for his deliverance meet,\nAssist him.  So to me will comfort spring.\nI who now bid thee on this errand forth\nAm Beatrice; from a place I come\n\n(Note:  Beatrice.  I use this word, as it is\npronounced in the Italian, as consisting of four\nsyllables, of which the third is a long one.)\n\nRevisited with joy.  Love brought me thence,\nWho prompts my speech.  When in my Master\'s sight\nI stand, thy praise to him I oft will tell.\"\n     She then was silent, and I thus began:\n\"O Lady!  by whose influence alone,\nMankind excels whatever is contain\'d\nWithin that heaven which hath the smallest orb,\nSo thy command delights me, that to obey,\nIf it were done already, would seem late.\nNo need hast thou farther to speak thy will;\nYet tell the reason, why thou art not loth\nTo leave that ample space, where to return\nThou burnest, for this centre here beneath.\"\n     She then:");
    strcat(expected_filecontent0, "  \"Since thou so deeply wouldst inquire,\nI will instruct thee briefly, why no dread\nHinders my entrance here.  Those things alone\nAre to be fear\'d, whence evil may proceed,\nNone else, for none are terrible beside.\nI am so fram\'d by God, thanks to his grace!\nThat any suff\'rance of your misery\nTouches me not, nor flame of that fierce fire\nAssails me.  In high heaven a blessed dame\nBesides, who mourns with such effectual grief\nThat hindrance, which I send thee to remove,\nThat God\'s stern judgment to her will inclines.\nTo Lucia calling, her she thus bespake:\n\"Now doth thy faithful servant need thy aid\nAnd I commend him to thee.\"  At her word\nSped Lucia, of all cruelty the foe,\nAnd coming to the place, where I abode\nSeated with Rachel, her of ancient days,\nShe thus address\'d me: \"Thou true praise of God!\nBeatrice!  why is not thy succour lent\nTo him, who so much lov\'d thee, as to leave\nFor thy sake all the multitude admires?\nDost thou not hear how pitiful his wail,\nNor mark the death, which in the torrent flood,\nSwoln mightier than a sea, him struggling holds?\"\nNe\'er among men did any with such speed\nHaste to their profit, flee from their annoy,\nAs when these words were spoken, I came here,\nDown from my blessed seat, trusting the forc");strcat(expected_filecontent1, "ness he has transmitted to posterity. He  died in 1336, at\nthe age of 60.\n\nv. 96.  One Guido from the other.]  Guido Cavalcanti, the friend\nof our Poet, (see Hell, Canto X. 59.) had eclipsed the literary\nfame of Guido Guinicelli, of a noble family in Bologna, whom we\nshall meet with in the twenty-sixth Canto and of whom frequent\nmention is made by our Poet in his Treatise de Vulg. Eloq.\nGuinicelli died in 1276.  Many of Cavalcanti\'s writings, hitherto\nin MS. are now publishing at Florence\" Esprit des Journaux, Jan.\n1813.\n\nv. 97.  He perhaps is born.]  Some imagine, with much\nprobability, that Dante here augurs the greatness of his own\npoetical reputation.  Others have fancied that he prophesies the\nglory of Petrarch. ");strcat(expected_filecontent2, "father, or bishop,\nin whose presence he made a profession of poverty.\n\nv. 60.  Her first husband.]  Christ.\n\nv. 63.  Amyclas.]  Lucan makes Caesar exclaim, on witnessing the\nsecure poverty of the fisherman Amyclas:\n\n--O vite tuta facultas\nPauperis, angustique lares!  O munera nondum\nIntellecta deum!  quibus hoc contingere templis,\nAut potuit muris, nullo trepidare tumultu,\nCaesarea pulsante manu?\nLucan Phars. 1. v. 531.\n\nv. 72.  Bernard.]  One of the first followers of the saint.\n\nv. 76.  Egidius.]  The third of his disciples, who died in 1262.\nHis work, entitled Verba Aurea, was published in 1534, at Antwerp\nSee Lucas Waddingus, Annales Ordinis Minoris, p. 5.\n\nv. 76.  Sylvester.]  Another of his earliest associates.\n\nv. 83.  Pietro Bernardone.]  A man in an humble station of life\nat Assisi.\n\nv. 86.  Innocent.]  Pope Innocent III.\n\nv. 90.  Honorius.]  His successor Honorius III who granted\ncertain privileges to the Franciscans.\n\nv. 93.  On the hard rock.]  The mountain Alverna in the Apennine.\n\nv. 100.  The last signet.]  Alluding to the stigmata, or marks\nresembling the wounds of Christ, said to have been found on the\nsaint\'s body.\n\nv. 106.  His dearest lady.]  Poverty.\n\nv. 113.  Our Patriarch ]  Saint Dominic.\n\nv. 316.  His flock ] The Dominicans.\n\nv. 127.  The planet from whence they split.]  \"The rule of their\norder, which the Dominicans neglect to observe.\"\n\nCANTO XII\n\nv. 1.  The blessed flame.]  Thomas Aquinas\n\nv. 12.  That voice.]  The nymph Echo, transformed into the\nrepercussion of the voice.\n\nv. 25.  One.]  Saint Buonaventura, general of the Franciscan\norder, in which he effected some reformation, and one of the most\nprofound divines of his age.  \"He refused the archbishopric of\nYork, which was offered him by Clement IV, but afterwards was\nprevailed on to accept the bishopric of Albano and a cardinal\'s\nhat.  He was born at Bagnoregio or Bagnorea, in Tuscany, A.D.\n1221, and died in 1274.\"  Dict. Histor. par Chaudon et Delandine.\nEd.  Lyon.  1804.\n\nv. 28.  The love.]  By an act of mutual courtesy, Buonaventura,\na Franciscan, is made to proclaim the praises of St. Dominic,\nas Thomas Aquinas, a Dominican, has celebrated those of St.\nFrancis.\n\nv. 42.  In that clime.]  Spain.\n\nv. 48.  Callaroga.]  Between Osma and Aranda, in Old Castile,\ndesignated by the royal coat of arms.\n\nv. 51.  The loving minion of the Christian faith.]  Dominic was\nborn April 5, 1170, and died August 6, 1221.  His birthplace,\nCallaroga; his father and mother\'s names, Felix and Joanna, his\nmother\'s dream; his name of Dominic, given him in consequence of\na vision by a noble matron, who stood sponsor to him, are all\ntold in an anonymous life of the saint, said to be written in the\nthirteenth century, and published by Quetif and Echard,\nScriptores Ordinis Praedicatorum.  Par.  1719. fol. t 1.  p. 25.\nThese writers deny his having been an inquisitor, and indeed the\nestablishment of the inquisition itself before the fourth Lateran\ncouncil.  Ibid.  p. 88.\n\nv. 55.  In the mother\'s womb.]  His mother, when pregnant with\nhim, is said to have dreamt that she should bring forth a white\nand black dog, with a lighted torch in its mouth.\n\nv. 59.  The dame.]  His godmother\'s dream was, that he had one\nstar in his forehead, and another in the nape of his neck, from\nwhich he communicated light to the east and the west.\n\nv. 73.  Felix.]  Felix Gusman.\n\nv. 75.  As men interpret it.]  Grace or gift of the Lord.\n\nv. 77.  Ostiense.]  A cardinal, who explained the decretals.\n\nv. 77.  Taddeo.]  A physician, of Florence.\n\nv. 82.  The see.]  \"The apostolic see, which no longer continues\nits wonted liberality towards the indigent and deserving; not\nindeed  through its own fault, as its doctrines are still the\nsame, but through the fault of the pontiff, who is seated in it.\"\n\nv. 85.  No dispensation.]  Dominic did not ask license to\ncompound for the use of unjust acquisitions, by dedicating a part\nof them to pious purposes.\n\nv. 89.  In favour of that seed.]  \"For that seed of the divine\nword, from which have sprung up these four-and-twenty plants,\nthat now environ thee.\"");
    strcat(expected_filecontent2, "\n\nv. 101.  But the track.]  \"But the rule of St. Francis is already\ndeserted and the lees of the wine are turned into mouldiness.\"\n\nv. 110.  Tares.]  He adverts to the parable of the taxes and the\nwheat.\n\nv. 111.  I question not.]  \"Some indeed might be found, who still\nobserve the rule of the order, but such would come neither from\nCasale nor Acquasparta:\" of the former of which places was\nUberto, one master general, by whom the discipline had been\nrelaxed; and of the latter, Matteo, another, who had enforced it\nwith unnecessary rigour.\n\nv. 121.  -Illuminato here,\nAnd Agostino.]\nTwo among the earliest followers of St. Francis.\n\nv. 125.  Hugues of St. Victor.]  A Saxon of the monastery of\nSaint  Victor at Paris, who fed ill 1142 at the age of\nforty-four.  \"A man distinguished by the fecundity of his genius,\nwho treated in his writings of all the branches of sacred and\nprofane erudition that were known in his time, and who composed\nseveral dissertations that are not destitute of merit.\"\nMaclaine\'s Mosheim, Eccl. Hist. v. iii . cent. xii. p. 2. 2. 23.\nI have looked into his writings, and found some reason for\nthis high eulogium.\n\nv. 125.  Piatro Mangiadore.]  \"Petrus Comestor, or the Eater,\nborn at Troyes, was canon and dean of that church, and afterwards\nchancellor of the church of Paris.  He relinquished these\nbenefices to become a regular canon of St. Victor at Paris, where\nhe died in 1198.  Chaudon et Delandine Dict. Hist. Ed. Lyon.\n1804. The work by which he is best known, is his Historia\nScolastica, which I shall have occasion to cite in the Notes to\nCanto XXVI.\n\nv. 126.  He of Spain.]  \"To Pope Adrian V succeeded John XXI a\nnative of Lisbon a man of great genius and extraordinary\nacquirements, especially in logic and in medicine, as his books,\nwritten in the name of Peter of Spain (by which he was known\nbefore he became Pope), may testify.  His life was not much\nlonger than that of his predecessors, for he was killed at\nViterbo, by the falling in of the roof of his chamber, after he\nhad been pontiff only eight months and as many days.\nA.D. 1277.  Mariana, Hist. de Esp. l. xi");strcat(expected_filecontent3, "pric of Albano and a cardinal\'s\nhat.  He was born at Bagnoregio or Bagnorea, in Tuscany, A.D.\n1221, and died in 1274.\"  Dict. Histor. par Chaudon et Delandine.\nEd.  Lyon.  1804.\n\nv. 28.  The love.]  By an act of mutual courtesy, Buonaventura,\na Franciscan, is made to proclaim the praises of St. Dominic,\nas Thomas Aquinas, a Dominican, has celebrated those of St.\nFrancis.\n\nv. 42.  In that clime.]  Spain.\n\nv. 48.  Callaroga.]  Between Osma and Aranda, in Old Castile,\ndesignated by the royal coat of arms.\n\nv. 51.  The loving minion of the Christian faith.]  Dominic was\nborn April 5, 1170, and died August 6, 1221.  His birthplace,\nCallaroga; his father and mother\'s names, Felix and Joanna, his\nmother\'s dream; his name of Dominic, given him in consequence of\na vision by a noble matron, who stood sponsor to him, are all\ntold in an anonymous life of the saint, said to be written in the\nthirteenth century, and published by Quetif and Echard,\nScriptores Ordinis Praedicatorum.  Par.  1719. fol. t 1.  p. 25.\nThese writers deny his having been an inquisitor, and indeed the\nestablishment of the inquisition itself before the fourth Lateran\ncouncil.  Ibid.  p. 88.\n\nv. 55.  In the mother\'s womb.]  His mother, when pregnant with\nhim, is said to have dreamt that she should bring forth a white\nand black dog, with a lighted torch in its mouth.\n\nv. 59.  The dame.]  His godmother\'s dream was, that he had one\nstar in his forehead, and another in the nape of his neck, from\nwhich he communicated light to the east and the west.\n\nv. 73.  Felix.]  Felix Gusman.\n\nv. 75.  As men interpret it.]  Grace or gift of the Lord.\n\nv. 77.  Ostiense.]  A cardinal, who explained the decretals.\n\nv. 77.  Taddeo.]  A physician, of Florence.\n\nv. 82.  The see.]  \"The apostolic see, which no longer continues\nits wonted liberality towards the indigent and deserving; not\nindeed  through its own fault, as its doctrines are still the\nsame, but through the fault of the pontiff, who is seated in it.\"\n\nv. 85.  No dispensation.]  Dominic did not ask license to\ncompound for the use of unjust acquisitions, by dedicating a part\nof them to pious purposes.\n\nv. 89.  In favour of that seed.]  \"For that seed of the divine\nword, from which have sprung up these four-and-twenty plants,\nthat now environ thee.\"\n\nv. 101.  But the track.]  \"But the rule of St. Francis is already\ndeserted and the lees of the wine are turned into mouldiness.\"\n\nv. 110.  Tares.]  He adverts to the parable of the taxes and the\nwheat.\n\nv. 111.  I question not.]  \"Some indeed might be found, who still\nobserve the rule of the order, but such would come neither from\nCasale nor Acquasparta:\" of the former of which places was\nUberto, one master general, by whom the discipline had been\nrelaxed; and of the latter, Matteo, another, who had enforced it\nwith unnecessary rigour.\n\nv. 121.  -Illuminato here,\nAnd Agostino.]\nTwo among the earliest followers of St. Francis.\n\nv. 125.  Hugues of St. Victor.]  A Saxon of the monastery of\nSaint  Victor at Paris, who fed ill 1142 at the age of\nforty-four.  \"A man distinguished by the fecundity of his genius,\nwho treated in his writings of all the branches of sacred and\nprofane erudition that were known in his time, and who composed\nseveral dissertations that are not destitute of merit.\"\nMaclaine\'s Mosheim, Eccl. Hist. v. iii . cent. xii. p. 2. 2. 23.\nI have looked into his writings, and found some reason for\nthis high eulogium.\n\nv. 125.  Piatro Mangiadore.]  \"Petrus Comestor, or the Eater,\nborn at Troyes, was canon and dean of that church, and afterwards\nchancellor of the church of Paris.  He relinquished these\nbenefices to become a regular canon of St. Victor at Paris, where\nhe died in 1198.  Chaudon et Delandine Dict. Hist. Ed. Lyon.\n1804. The work by which he is best known, is his Historia\nScolastica, which I shall have occasion to cite in the Notes to\nCanto XXVI.\n\nv. 126.  He of Spain.]  \"To Pope Adrian V succeeded John XXI a\nnative of Lisbon a man of great genius and extraordinary\nacquirements, especially in logic and in medicine, as his books,\nwritten in the name of Peter of S");
    strcat(expected_filecontent3, "pain (by which he was known\nbefore he became Pope), may testify.  His life was not much\nlonger than that of his predecessors, for he was killed at\nViterbo, by the falling in of the roof of his chamber, after he\nhad been pontiff only eight months and as many days.\nA.D. 1277.  Mariana, Hist. de Esp. l. xiv.  c. 2.\n\nv. 128.  Chrysostom.]  The eloquent patriarch of Constantinople.\n\nv. 128.  Anselmo.]  \"Anselm, Archbishop of Canterbury, was born\nat Aosta, about 1034, and studied under Lanfrane at the monastery\nof Bec, in Normandy, where he afterwards devoted himself to a\nreligious life, in his twenty-seventh year.  In three years he\nwas made prior, and then abbot of that monastery!  from whence he\nwas taken, in 1093, to succeed to the archbishopric, vacant by\nthe death of Lanfrane. He enjoyed this dignity till his death, in\n1109, though it was disturbed by many\ndissentions with William II and Henry I respecting the immunities\nand investitures.  There is much depth and precisian in his\ntheological  works.\" Tiraboschi, Stor.  della Lett. Ital. t. iii.\n\n1. iv. c. 2. Ibid.  c. v.  \"It is an observation made by many\nmodern writers, that the demonstration of the existence of God,\ntaken from the idea of a Supreme Being, of which Des Cartes is\nthought to be the author, was so many ages back discovered and\nbrought to light by Anselm.  Leibnitz himself makes\nthe remark, vol. v. Oper.  p. 570.  Edit.  Genev. 1768.\"\n\nv. 129.  Donatus.]  Aelius Donatus, the grammarian, in the fourth\ncentury, one of the preceptors of St. Jerome.\n\nv. 130.  Raban.]  \"Rabanus Maurus, Archbishop of Mentz, is\ndeservedly placed at the head of the Latin writers of this age.\"\nMosheim, v. ii. cent. ix. p.  2 c. 2.  14.\n\nv. 131.  Joachim.]  Abbot of Flora in Calabria; \"whom the\nmultitude revered as a person divinely inspired and equal to the\nmost illustrious prophets of ancient times.\"  Ibid.  v. iii.\ncent. xiii. p. 2. c. 2. 33.\n\nv. 134.  A peer.]  St. Dominic.\n\nCANTO XIII\n\nv. 1.  Let him.]  \"Whoever would conceive the sight that now\npresented itself to me, m");strcat(expected_filecontent4, " now I. now L. figur\'d I\' th\' air.\nFirst, singing, to their notes they mov\'d, then one\nBecoming of these signs, a little while\nDid rest them, and were mute.  O nymph divine\nOf Pegasean race!  whose souls, which thou\nInspir\'st, mak\'st glorious and long-liv\'d, as they\nCities and realms by thee!  thou with thyself\nInform me; that I may set forth the shapes,\nAs fancy doth present them.  Be thy power\nDisplay\'d in this brief song.  The characters,\nVocal and consonant, were five-fold seven.\nIn order each, as they appear\'d, I mark\'d.\nDiligite Justitiam, the first,\nBoth verb and noun all blazon\'d; and the extreme\nQui judicatis terram.  In the M.\nOf the fifth word they held their station,\nMaking the star seem silver streak\'d with gold.\nAnd on the summit of the M. I saw\nDescending other lights, that rested there,\nSinging, methinks, their bliss and primal good.\nThen, as at shaking of a lighted brand,\nSparkles innumerable on all sides\nRise scatter\'d, source of augury to th\' unwise;\nThus more than thousand twinkling lustres hence\nSeem\'d reascending, and a higher pitch\nSome mounting, and some less; e\'en as the sun,\nWhich kindleth them, decreed.  And when each one\nHad settled in his place, the head and neck\nThen saw I of an eagle, lively\nGrav\'d in that streaky fire.  Who painteth there,\nHath none to guide him; of himself he guides;\nAnd every line and texture of the nest\nDoth own from him the virtue, fashions it.\nThe other bright beatitude, that seem\'d\nErewhile, with lilied crowning, well content\nTo over-canopy the M. mov\'d forth,\nFollowing gently the impress of the bird.\n      Sweet star!  what glorious and thick-studded gems\nDeclar\'d to me our justice on the earth\nTo be the effluence of that heav\'n, which thou,\nThyself a costly jewel, dost inlay!\nTherefore I pray the Sovran Mind, from whom\nThy motion and thy virtue are begun,\nThat he would look from whence the fog doth rise,\nTo vitiate thy beam: so that once more\nHe may put forth his hand \'gainst such, as drive\nTheir traffic in that sanctuary, whose walls\nWith miracles and martyrdoms were built.\n     Ye host of heaven!  whose glory I survey l\nO beg ye grace for those, that are on earth\nAll after ill example gone astray.\nWar once had for its instrument the sword:\nBut now \'t is made, taking the bread away\nWhich the good Father locks from none.  --And thou,\nThat writes but to cancel, think, that they,\nWho for the vineyard, which thou wastest, died,\nPeter and Paul live yet, and mark thy doings.\nThou hast good cause to cry, \"My heart so cleaves\nTo him, that liv\'d in solitude remote,\nAnd from the wilds was dragg\'d to martyrdom,\nI wist not of the fisherman nor Paul.\"\n\n\n\nCANTO XIX\n\nBefore my sight appear\'d, with open wings,\nThe beauteous image, in fruition sweet\nGladdening the thronged spirits.  Each did seem\nA little ruby, whereon so intense\nThe sun-beam glow\'d that to mine eyes it came\nIn clear refraction.  And that, which next\nBefalls me to portray, voice hath not utter\'d,\nNor hath ink written, nor in fantasy\nWas e\'er conceiv\'d.  For I beheld and heard\nThe beak discourse; and, what intention form\'d\nOf many, singly as of one express,\nBeginning:  \"For that I was just and piteous,\nl am exalted to this height of glory,\nThe which no wish exceeds: and there on earth\nHave I my memory left, e\'en by the bad\nCommended, while they leave its course untrod.\"\n     Thus is one heat from many embers felt,\nAs in that image many were the loves,\nAnd one the voice, that issued from them all.\nWhence I address them:  \"O perennial flowers\nOf gladness everlasting!  that exhale\nIn single breath your odours manifold!\nBreathe now; and let the hunger be appeas\'d,\nThat with great craving long hath held my soul,\nFinding no food on earth.  This well I know,\nThat if there be in heav\'n a realm, that shows\nIn faithful mirror the celestial Justice,\nYours without veil reflects it.  Ye discern\nThe heed, wherewith I do prepare myself\nTo hearken; ye the doubt that urges me\nWith such inveterate craving.\"  Straight I saw,\nLike to a falcon issuing from the hood,\nThat rears his head, and claps him with his wings,\nHis beauty and his");
    strcat(expected_filecontent4, " eagerness bewraying.\nSo saw I move that stately sign, with praise\nOf grace divine inwoven and high song\nOf inexpressive joy.  \"He,\" it began,\n\"Who turn\'d his compass on the world\'s extreme,\nAnd in that space so variously hath wrought,\nBoth openly, and in secret, in such wise\nCould not through all the universe display\nImpression of his glory, that the Word\nOf his omniscience should not still remain\nIn infinite excess.  In proof whereof,\nHe first through pride supplanted, who was sum\nOf each created being, waited not\nFor light celestial, and abortive fell.\nWhence needs each lesser nature is but scant\nReceptacle unto that Good, which knows\nNo limit, measur\'d by itself alone.\nTherefore your sight, of th\' omnipresent Mind\nA single beam, its origin must own\nSurpassing far its utmost potency.\nThe ken, your world is gifted with, descends\nIn th\' everlasting Justice as low down,\nAs eye doth in the sea; which though it mark\nThe bottom from the shore, in the wide main\nDiscerns it not; and ne\'ertheless it is,\nBut hidden through its");strcat(expected_filecontent5, "disposes me not less\nFor weeping, when I see It thus transform\'d.\nSay then, by Heav\'n, what blasts ye thus?  The whilst\nI wonder, ask not Speech from me:  unapt\nIs he to speak, whom other will employs.\n     He thus:  \"The water and tee plant we pass\'d,\nVirtue possesses, by th\' eternal will\nInfus\'d, the which so pines me.  Every spirit,\nWhose song bewails his gluttony indulg\'d\nToo grossly, here in hunger and in thirst\nIs purified.  The odour, which the fruit,\nAnd spray, that showers upon the verdure, breathe,\nInflames us with desire");


            struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            
                    struct file_t* file0 = file_open(volume, "hAD.biN");
                    test_error(file0 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file1 = file_open(volume, "OWN.TXt");
                    test_error(file1 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file2 = file_open(volume, "BoNE.BIN");
                    test_error(file2 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file3 = file_open(volume, "SuN");
                    test_error(file3 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file4 = file_open(volume, "CoST");
                    test_error(file4 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file5 = file_open(volume, "WARHaNDt");
                    test_error(file5 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
            
                size_t size0 = file_read(filecontent0, 1, 5344, file0);
                test_error(size0 == 5344, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 5344 bajtów, a wczytała %lu", size0);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos0 = mem_find_first_difference(filecontent0, expected_filecontent0, 5344);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos0 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos0, mem_get_byte(filecontent0, diff_pos0), mem_get_byte(expected_filecontent0, diff_pos0));
        
                onerror_compare_memory(expected_filecontent0, filecontent0, 5344);
            
                size_t size1 = file_read(filecontent1, 1, 727, file1);
                test_error(size1 == 727, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 727 bajtów, a wczytała %lu", size1);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos1 = mem_find_first_difference(filecontent1, expected_filecontent1, 727);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos1 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos1, mem_get_byte(filecontent1, diff_pos1), mem_get_byte(expected_filecontent1, diff_pos1));
        
                onerror_compare_memory(expected_filecontent1, filecontent1, 727);
            
                size_t size2 = file_read(filecontent2, 1, 6211, file2);
                test_error(size2 == 6211, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6211 bajtów, a wczytała %lu", size2);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos2 = mem_find_first_difference(filecontent2, expected_filecontent2, 6211);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos2 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos2, mem_get_byte(filecontent2, diff_pos2), mem_get_byte(expected_filecontent2, diff_pos2));
        
                onerror_compare_memory(expected_filecontent2, filecontent2, 6211);
            
                size_t size3 = file_read(filecontent3, 1, 6144, file3);
                test_error(size3 == 6144, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6144 bajtów, a wczytała %lu", size3);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos3 = mem_find_first_difference(filecontent3, expected_filecontent3, 6144);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos3 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos3, mem_get_byte(filecontent3, diff_pos3), mem_get_byte(expected_filecontent3, diff_pos3));
        
                onerror_compare_memory(expected_filecontent3, filecontent3, 6144);
            
                size_t size4 = file_read(filecontent4, 1, 5130, file4);
                test_error(size4 == 5130, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 5130 bajtów, a wczytała %lu", size4);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos4 = mem_find_first_difference(filecontent4, expected_filecontent4, 5130);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos4 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos4, mem_get_byte(filecontent4, diff_pos4), mem_get_byte(expected_filecontent4, diff_pos4));
        
                onerror_compare_memory(expected_filecontent4, filecontent4, 5130);
            
                size_t size5 = file_read(filecontent5, 1, 537, file5);
                test_error(size5 == 537, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 537 bajtów, a wczytała %lu", size5);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos5 = mem_find_first_difference(filecontent5, expected_filecontent5, 537);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos5 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos5, mem_get_byte(filecontent5, diff_pos5), mem_get_byte(expected_filecontent5, diff_pos5));
        
                onerror_compare_memory(expected_filecontent5, filecontent5, 537);
            

            free(filecontent0);
    free(filecontent1);
    free(filecontent2);
    free(filecontent3);
    free(filecontent4);
    free(filecontent5);

            file_close(file0);
    file_close(file1);
    file_close(file2);
    file_close(file3);
    file_close(file4);
    file_close(file5);


            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 72: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST72(void)
{
    // informacje o teście
    test_start(72, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(6211, 1);
            char expected_filecontent[6212] = "";

            strcat(expected_filecontent, "father, or bishop,\nin whose presence he made a profession of poverty.\n\nv. 60.  Her first husband.]  Christ.\n\nv. 63.  Amyclas.]  Lucan makes Caesar exclaim, on witnessing the\nsecure poverty of the fisherman Amyclas:\n\n--O vite tuta facultas\nPauperis, angustique lares!  O munera nondum\nIntellecta deum!  quibus hoc contingere templis,\nAut potuit muris, nullo trepidare tumultu,\nCaesarea pulsante manu?\nLucan Phars. 1. v. 531.\n\nv. 72.  Bernard.]  One of the first followers of the saint.\n\nv. 76.  Egidius.]  The third of his disciples, who died in 1262.\nHis work, entitled Verba Aurea, was published in 1534, at Antwerp\nSee Lucas Waddingus, Annales Ordinis Minoris, p. 5.\n\nv. 76.  Sylvester.]  Another of his earliest associates.\n\nv. 83.  Pietro Bernardone.]  A man in an humble station of life\nat Assisi.\n\nv. 86.  Innocent.]  Pope Innocent III.\n\nv. 90.  Honorius.]  His successor Honorius III who granted\ncertain privileges to the Franciscans.\n\nv. 93.  On the hard rock.]  The mountain Alverna in the Apennine.\n\nv. 100.  The last signet.]  Alluding to the stigmata, or marks\nresembling the wounds of Christ, said to have been found on the\nsaint\'s body.\n\nv. 106.  His dearest lady.]  Poverty.\n\nv. 113.  Our Patriarch ]  Saint Dominic.\n\nv. 316.  His flock ] The Dominicans.\n\nv. 127.  The planet from whence they split.]  \"The rule of their\norder, which the Dominicans neglect to observe.\"\n\nCANTO XII\n\nv. 1.  The blessed flame.]  Thomas Aquinas\n\nv. 12.  That voice.]  The nymph Echo, transformed into the\nrepercussion of the voice.\n\nv. 25.  One.]  Saint Buonaventura, general of the Franciscan\norder, in which he effected some reformation, and one of the most\nprofound divines of his age.  \"He refused the archbishopric of\nYork, which was offered him by Clement IV, but afterwards was\nprevailed on to accept the bishopric of Albano and a cardinal\'s\nhat.  He was born at Bagnoregio or Bagnorea, in Tuscany, A.D.\n1221, and died in 1274.\"  Dict. Histor. par Chaudon et Delandine.\nEd.  Lyon.  1804.\n\nv. 28.  The love.]  By an act of mutual courtesy, Buonaventura,\na Franciscan, is made to proclaim the praises of St. Dominic,\nas Thomas Aquinas, a Dominican, has celebrated those of St.\nFrancis.\n\nv. 42.  In that clime.]  Spain.\n\nv. 48.  Callaroga.]  Between Osma and Aranda, in Old Castile,\ndesignated by the royal coat of arms.\n\nv. 51.  The loving minion of the Christian faith.]  Dominic was\nborn April 5, 1170, and died August 6, 1221.  His birthplace,\nCallaroga; his father and mother\'s names, Felix and Joanna, his\nmother\'s dream; his name of Dominic, given him in consequence of\na vision by a noble matron, who stood sponsor to him, are all\ntold in an anonymous life of the saint, said to be written in the\nthirteenth century, and published by Quetif and Echard,\nScriptores Ordinis Praedicatorum.  Par.  1719. fol. t 1.  p. 25.\nThese writers deny his having been an inquisitor, and indeed the\nestablishment of the inquisition itself before the fourth Lateran\ncouncil.  Ibid.  p. 88.\n\nv. 55.  In the mother\'s womb.]  His mother, when pregnant with\nhim, is said to have dreamt that she should bring forth a white\nand black dog, with a lighted torch in its mouth.\n\nv. 59.  The dame.]  His godmother\'s dream was, that he had one\nstar in his forehead, and another in the nape of his neck, from\nwhich he communicated light to the east and the west.\n\nv. 73.  Felix.]  Felix Gusman.\n\nv. 75.  As men interpret it.]  Grace or gift of the Lord.\n\nv. 77.  Ostiense.]  A cardinal, who explained the decretals.\n\nv. 77.  Taddeo.]  A physician, of Florence.\n\nv. 82.  The see.]  \"The apostolic see, which no longer continues\nits wonted liberality towards the indigent and deserving; not\nindeed  through its own fault, as its doctrines are still the\nsame, but through the fault of the pontiff, who is seated in it.\"\n\nv. 85.  No dispensation.]  Dominic did not ask license to\ncompound for the use of unjust acquisitions, by dedicating a part\nof them to pious purposes.\n\nv. 89.  In favour of that seed.]  \"For that seed of the divine\nword, from which have sprung up these four-and-twenty plants,\nthat now environ thee.\"");
    strcat(expected_filecontent, "\n\nv. 101.  But the track.]  \"But the rule of St. Francis is already\ndeserted and the lees of the wine are turned into mouldiness.\"\n\nv. 110.  Tares.]  He adverts to the parable of the taxes and the\nwheat.\n\nv. 111.  I question not.]  \"Some indeed might be found, who still\nobserve the rule of the order, but such would come neither from\nCasale nor Acquasparta:\" of the former of which places was\nUberto, one master general, by whom the discipline had been\nrelaxed; and of the latter, Matteo, another, who had enforced it\nwith unnecessary rigour.\n\nv. 121.  -Illuminato here,\nAnd Agostino.]\nTwo among the earliest followers of St. Francis.\n\nv. 125.  Hugues of St. Victor.]  A Saxon of the monastery of\nSaint  Victor at Paris, who fed ill 1142 at the age of\nforty-four.  \"A man distinguished by the fecundity of his genius,\nwho treated in his writings of all the branches of sacred and\nprofane erudition that were known in his time, and who composed\nseveral dissertations that are not destitute of merit.\"\nMaclaine\'s Mosheim, Eccl. Hist. v. iii . cent. xii. p. 2. 2. 23.\nI have looked into his writings, and found some reason for\nthis high eulogium.\n\nv. 125.  Piatro Mangiadore.]  \"Petrus Comestor, or the Eater,\nborn at Troyes, was canon and dean of that church, and afterwards\nchancellor of the church of Paris.  He relinquished these\nbenefices to become a regular canon of St. Victor at Paris, where\nhe died in 1198.  Chaudon et Delandine Dict. Hist. Ed. Lyon.\n1804. The work by which he is best known, is his Historia\nScolastica, which I shall have occasion to cite in the Notes to\nCanto XXVI.\n\nv. 126.  He of Spain.]  \"To Pope Adrian V succeeded John XXI a\nnative of Lisbon a man of great genius and extraordinary\nacquirements, especially in logic and in medicine, as his books,\nwritten in the name of Peter of Spain (by which he was known\nbefore he became Pope), may testify.  His life was not much\nlonger than that of his predecessors, for he was killed at\nViterbo, by the falling in of the roof of his chamber, after he\nhad been pontiff only eight months and as many days.\nA.D. 1277.  Mariana, Hist. de Esp. l. xi");

            struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "bONE.biN");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 2821, SEEK_SET);
        
            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[2821] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[2821], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 73: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST73(void)
{
    // informacje o teście
    test_start(73, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(537, 1);
            char expected_filecontent[538] = "";

            strcat(expected_filecontent, "disposes me not less\nFor weeping, when I see It thus transform\'d.\nSay then, by Heav\'n, what blasts ye thus?  The whilst\nI wonder, ask not Speech from me:  unapt\nIs he to speak, whom other will employs.\n     He thus:  \"The water and tee plant we pass\'d,\nVirtue possesses, by th\' eternal will\nInfus\'d, the which so pines me.  Every spirit,\nWhose song bewails his gluttony indulg\'d\nToo grossly, here in hunger and in thirst\nIs purified.  The odour, which the fruit,\nAnd spray, that showers upon the verdure, breathe,\nInflames us with desire");

            struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "wArHANdT");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, -241, SEEK_END);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[296] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[296], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 74: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST74(void)
{
    // informacje o teście
    test_start(74, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(5344, 1);
            char expected_filecontent[5345] = "";

            strcat(expected_filecontent, " he chooses!\"  I to him in few:\n\"Bard!  by that God, whom thou didst not adore,\nI do beseech thee (that this ill and worse\nI may escape) to lead me, where thou saidst,\nThat I Saint Peter\'s gate may view, and those\nWho as thou tell\'st, are in such dismal plight.\"\n     Onward he mov\'d, I close his steps pursu\'d.\n\n\n\nCANTO II\n\nNOW was the day departing, and the air,\nImbrown\'d with shadows, from their toils releas\'d\nAll animals on earth; and I alone\nPrepar\'d myself the conflict to sustain,\nBoth of sad pity, and that perilous road,\nWhich my unerring memory shall retrace.\n     O Muses!  O high genius!  now vouchsafe\nYour aid!  O mind!  that all I saw hast kept\nSafe in a written record, here thy worth\nAnd eminent endowments come to proof.\n     I thus began:  \"Bard!  thou who art my guide,\nConsider well, if virtue be in me\nSufficient, ere to this high enterprise\nThou trust me.  Thou hast told that Silvius\' sire,\nYet cloth\'d in corruptible flesh, among\nTh\' immortal tribes had entrance, and was there\nSensible present.  Yet if heaven\'s great Lord,\nAlmighty foe to ill, such favour shew\'d,\nIn contemplation of the high effect,\nBoth what and who from him should issue forth,\nIt seems in reason\'s judgment well deserv\'d:\nSith he of Rome, and of Rome\'s empire wide,\nIn heaven\'s empyreal height was chosen sire:\nBoth which, if truth be spoken, were ordain\'d\nAnd \'stablish\'d for the holy place, where sits\nWho to great Peter\'s sacred chair succeeds.\nHe from this journey, in thy song renown\'d,\nLearn\'d things, that to his victory gave rise\nAnd to the papal robe.  In after-times\nThe chosen vessel also travel\'d there,\nTo bring us back assurance in that faith,\nWhich is the entrance to salvation\'s way.\nBut I, why should I there presume?  or who\nPermits it?  not, Aeneas I nor Paul.\nMyself I deem not worthy, and none else\nWill deem me.  I, if on this voyage then\nI venture, fear it will in folly end.\nThou, who art wise, better my meaning know\'st,\nThan I can speak.\"  As one, who unresolves\nWhat he hath late resolv\'d, and with new thoughts\nChanges his purpose, from his first intent\nRemov\'d; e\'en such was I on that dun coast,\nWasting in thought my enterprise, at first\nSo eagerly embrac\'d.  \"If right thy words\nI scan,\" replied that shade magnanimous,\n\"Thy soul is by vile fear assail\'d, which oft\nSo overcasts a man, that he recoils\nFrom noblest resolution, like a beast\nAt some false semblance in the twilight gloom.\nThat from this terror thou mayst free thyself,\nI will instruct thee why I came, and what\nI heard in that same instant, when for thee\nGrief touch\'d me first.  I was among the tribe,\nWho rest suspended, when a dame, so blest\nAnd lovely, I besought her to command,\nCall\'d me; her eyes were brighter than the star\nOf day; and she with gentle voice and soft\nAngelically tun\'d her speech address\'d:\n\"O courteous shade of Mantua!  thou whose fame\nYet lives, and shall live long as nature lasts!\nA friend, not of my fortune but myself,\nOn the wide desert in his road has met\nHindrance so great, that he through fear has turn\'d.\nNow much I dread lest he past help have stray\'d,\nAnd I be ris\'n too late for his relief,\nFrom what in heaven of him I heard.  Speed now,\nAnd by thy eloquent persuasive tongue,\nAnd by all means for his deliverance meet,\nAssist him.  So to me will comfort spring.\nI who now bid thee on this errand forth\nAm Beatrice; from a place I come\n\n(Note:  Beatrice.  I use this word, as it is\npronounced in the Italian, as consisting of four\nsyllables, of which the third is a long one.)\n\nRevisited with joy.  Love brought me thence,\nWho prompts my speech.  When in my Master\'s sight\nI stand, thy praise to him I oft will tell.\"\n     She then was silent, and I thus began:\n\"O Lady!  by whose influence alone,\nMankind excels whatever is contain\'d\nWithin that heaven which hath the smallest orb,\nSo thy command delights me, that to obey,\nIf it were done already, would seem late.\nNo need hast thou farther to speak thy will;\nYet tell the reason, why thou art not loth\nTo leave that ample space, where to return\nThou burnest, for this centre here beneath.\"\n     She then:");
    strcat(expected_filecontent, "  \"Since thou so deeply wouldst inquire,\nI will instruct thee briefly, why no dread\nHinders my entrance here.  Those things alone\nAre to be fear\'d, whence evil may proceed,\nNone else, for none are terrible beside.\nI am so fram\'d by God, thanks to his grace!\nThat any suff\'rance of your misery\nTouches me not, nor flame of that fierce fire\nAssails me.  In high heaven a blessed dame\nBesides, who mourns with such effectual grief\nThat hindrance, which I send thee to remove,\nThat God\'s stern judgment to her will inclines.\nTo Lucia calling, her she thus bespake:\n\"Now doth thy faithful servant need thy aid\nAnd I commend him to thee.\"  At her word\nSped Lucia, of all cruelty the foe,\nAnd coming to the place, where I abode\nSeated with Rachel, her of ancient days,\nShe thus address\'d me: \"Thou true praise of God!\nBeatrice!  why is not thy succour lent\nTo him, who so much lov\'d thee, as to leave\nFor thy sake all the multitude admires?\nDost thou not hear how pitiful his wail,\nNor mark the death, which in the torrent flood,\nSwoln mightier than a sea, him struggling holds?\"\nNe\'er among men did any with such speed\nHaste to their profit, flee from their annoy,\nAs when these words were spoken, I came here,\nDown from my blessed seat, trusting the forc");

            struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "HAD.BIN");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 1511, SEEK_SET);
            file_seek(file, 3704, SEEK_CUR);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[5215] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[5215], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 75: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST75(void)
{
    // informacje o teście
    test_start(75, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\ON\\WARM\\STREam\\yES");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\On\\WaRM\\sTREAm\\YEs) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 76: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST76(void)
{
    // informacje o teście
    test_start(76, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\ON\\PhRASE\\NATure");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\ON\\PHRaSe\\NATuRE) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 77: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST77(void)
{
    // informacje o teście
    test_start(77, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\On\\OPPoSITE\\wRITTEN\\fOur\\COUNT");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\On\\OPPOsITe\\wRITTEN\\FOUR\\COUnT) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 78: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST78(void)
{
    // informacje o teście
    test_start(78, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\ON\\PHRASE\\nATURE\\boRN\\qUOtIENT");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\ON\\PHrASe\\nATURE\\BoRn\\QUOTiEnt) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 79: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST79(void)
{
    // informacje o teście
    test_start(79, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\MINE\\TYpE\\mUlTIPLY");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\MINE\\TYPE\\MULTIPlY) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 80: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST80(void)
{
    // informacje o teście
    test_start(80, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\ON\\wARM\\EYE");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\oN\\WArM\\EYe) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 81: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST81(void)
{
    // informacje o teście
    test_start(81, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\TerM\\ONe\\ORIGinAL\\WINTER\\aFTeR");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\TERM\\ONe\\ORiGINAl\\wINtER\\AFTer) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 82: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST82(void)
{
    // informacje o teście
    test_start(82, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\MINE\\CArry\\As\\tIE");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\MiNE\\cArry\\AS\\TIE) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 83: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST83(void)
{
    // informacje o teście
    test_start(83, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\MINE\\TYPE\\MULtiPly");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\MInE\\TYPE\\MULTiPLY) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 84: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST84(void)
{
    // informacje o teście
    test_start(84, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "TRACK");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (TrACK) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 85: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST85(void)
{
    // informacje o teście
    test_start(85, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "DePenD");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (DEPENd) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 86: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST86(void)
{
    // informacje o teście
    test_start(86, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "TERM");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (tErM) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 87: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST87(void)
{
    // informacje o teście
    test_start(87, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "ON");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (ON) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 88: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST88(void)
{
    // informacje o teście
    test_start(88, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "MINe");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (MINE) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 89: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST89(void)
{
    // informacje o teście
    test_start(89, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "RUlEsOuT");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (rULESOUt) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 90: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST90(void)
{
    // informacje o teście
    test_start(90, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "eNERgy.TXT");
            test_error(file == NULL, "Funkcja file_open() nie powinna otworzyć pliku o nazwie ENERGY.TXT, ponieważ nie istnieje on w katalogu głównym");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 91: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST91(void)
{
    // informacje o teście
    test_start(91, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(NULL, "ENErgY.TXt");
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 92: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST92(void)
{
    // informacje o teście
    test_start(92, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, NULL);
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 93: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST93(void)
{
    // informacje o teście
    test_start(93, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(NULL, NULL);
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 94: Sprawdzanie poprawności działania funkcji file_close
//
void UTEST94(void)
{
    // informacje o teście
    test_start(94, "Sprawdzanie poprawności działania funkcji file_close", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            file_close(NULL);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 95: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST95(void)
{
    // informacje o teście
    test_start(95, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "HAD.BIN");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int res = file_read(NULL, 1, 1, file);
            test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 96: Sprawdzanie poprawności działania funkcji dir_read
//
void UTEST96(void)
{
    // informacje o teście
    test_start(96, "Sprawdzanie poprawności działania funkcji dir_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char* expected_names[12] = { "HAD.BIN", "OWN.TXT", "BONE.BIN", "SUN", "COST", "WARHANDT", "TRACK", "DEPEND", "TERM", "ON", "MINE", "RULESOUT" };
            int found_names[12] = { 0 };

            struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t* pdir = dir_open(volume, "\\");
            test_error(pdir != NULL, "Funkcja dir_open() niepoprawnie otworzyła katalog");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            for (int i = 0; i < 12; ++i)
            {
                struct dir_entry_t entry;
                int res = dir_read(pdir, &entry);
                test_error(res == 0, "Funkcja dir_read() niepoprawnie odczytała wpis z katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int name_found = 0;

                for (int j = 0; j < 12; ++j)
                {
                    if (strcmp(entry.name, expected_names[j]) == 0)
                    {
                        test_error(found_names[j] == 0, "Funkcja dir_read() ponownie zwróciła informację o wpisie %s", expected_names[j]);
                        found_names[j] = 1;
                        name_found = 1;
                        break;
                    }
                }

                test_error(name_found == 1, "Funkcja dir_read() zwróciła informację o wpisie %s, który nie znajduje się w katalogu", entry.name);
            }

            struct dir_entry_t entry;
            int res = dir_read(pdir, &entry);
            test_error(res == 1, "Funkcja dir_read() zwróciła niepoprawną wartość, po odczytaniu wszystkich wpisów z katalogu powinna zwrócić %d, a zwróciła %d", 1, res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            dir_close(pdir);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 97: Sprawdzanie poprawności działania funkcji dir_read
//
void UTEST97(void)
{
    // informacje o teście
    test_start(97, "Sprawdzanie poprawności działania funkcji dir_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char* expected_names[44] = { "KNEW.BIN", "PRODUCT", "SUCH.TXT", "STUDY", "DEAR.BIN", "FRUIT.TX", "THIN.BIN", "ALLOW.BIN", "THESE.TX", "TRADE", "PAPER.BIN", "GLAD", "PREPARE.BIN", "OUT.BIN", "EXCITE.TXT", "SAID.BIN", "CAT.TXT", "HAND.TX", "SETTLE.BIN", "TOWN.TX", "LEFT.TX", "OBSERVE", "WAVE.TX", "FIGHT.TX", "EAT", "PROVIDE.TXT", "THICK.BIN", "CROSS.BIN", "HER", "CLOUD", "MUST", "BELIEVE", "FINGER", "PHRASE", "OPPOSITE", "BLACK", "SPOT", "VOWEL", "WON'T", "WARM", "VERB", "DEATH", ".", ".." };
            int found_names[44] = { 0 };

            struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t* pdir = dir_open(volume, "\\On");
            test_error(pdir != NULL, "Funkcja dir_open() niepoprawnie otworzyła katalog");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            for (int i = 0; i < 44; ++i)
            {
                struct dir_entry_t entry;
                int res = dir_read(pdir, &entry);
                test_error(res == 0, "Funkcja dir_read() niepoprawnie odczytała wpis z katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int name_found = 0;

                for (int j = 0; j < 44; ++j)
                {
                    if (strcmp(entry.name, expected_names[j]) == 0)
                    {
                        test_error(found_names[j] == 0, "Funkcja dir_read() ponownie zwróciła informację o wpisie %s", expected_names[j]);
                        found_names[j] = 1;
                        name_found = 1;
                        break;
                    }
                }

                test_error(name_found == 1, "Funkcja dir_read() zwróciła informację o wpisie %s, który nie znajduje się w katalogu", entry.name);
            }

            struct dir_entry_t entry;
            int res = dir_read(pdir, &entry);
            test_error(res == 1, "Funkcja dir_read() zwróciła niepoprawną wartość, po odczytaniu wszystkich wpisów z katalogu powinna zwrócić %d, a zwróciła %d", 1, res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            dir_close(pdir);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 98: Sprawdzanie poprawności działania funkcji dir_read
//
void UTEST98(void)
{
    // informacje o teście
    test_start(98, "Sprawdzanie poprawności działania funkcji dir_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char* expected_names[11] = { "SYLLABLE.TX", "RED.TXT", "FREE.TXT", "MIX.BIN", "PAY", "HORSE", "WAS", "TROUBLE", "DIVISION", ".", ".." };
            int found_names[11] = { 0 };

            struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t* pdir = dir_open(volume, "\\dEPend\\DRIvE\\DeVELOP\\..\\DEVELOP\\SECOND\\.\\TEmPERAt");
            test_error(pdir != NULL, "Funkcja dir_open() niepoprawnie otworzyła katalog");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            for (int i = 0; i < 11; ++i)
            {
                struct dir_entry_t entry;
                int res = dir_read(pdir, &entry);
                test_error(res == 0, "Funkcja dir_read() niepoprawnie odczytała wpis z katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int name_found = 0;

                for (int j = 0; j < 11; ++j)
                {
                    if (strcmp(entry.name, expected_names[j]) == 0)
                    {
                        test_error(found_names[j] == 0, "Funkcja dir_read() ponownie zwróciła informację o wpisie %s", expected_names[j]);
                        found_names[j] = 1;
                        name_found = 1;
                        break;
                    }
                }

                test_error(name_found == 1, "Funkcja dir_read() zwróciła informację o wpisie %s, który nie znajduje się w katalogu", entry.name);
            }

            struct dir_entry_t entry;
            int res = dir_read(pdir, &entry);
            test_error(res == 1, "Funkcja dir_read() zwróciła niepoprawną wartość, po odczytaniu wszystkich wpisów z katalogu powinna zwrócić %d, a zwróciła %d", 1, res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            dir_close(pdir);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 99: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST99(void)
{
    // informacje o teście
    test_start(99, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\dEpEnD\\lEAvE\\FIvE\\EasT\\mORnING\\MARK.tX");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 100: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST100(void)
{
    // informacje o teście
    test_start(100, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\minE\\TYPE\\WiN\\MEEt.tx");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 101: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST101(void)
{
    // informacje o teście
    test_start(101, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\ON\\OPpoSITE\\sEcTION\\aREa\\seNSe\\SYStEM.TXT");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 102: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST102(void)
{
    // informacje o teście
    test_start(102, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\ON\\opPOSITe\\sEcTiON\\AREA\\LIST\\INStAnt.BiN");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 103: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST103(void)
{
    // informacje o teście
    test_start(103, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\oN\\oPPOsITE\\ShOE\\LIKe\\LIsTEn\\rePLY.BIN");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 104: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST104(void)
{
    // informacje o teście
    test_start(104, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\MiNe\\TYPE\\pAIR\\RIse\\PAsS");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 105: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST105(void)
{
    // informacje o teście
    test_start(105, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\DEPend\\LEAvE\\fIVE\\eaSt\\HAIR\\STAte.bIN");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 106: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST106(void)
{
    // informacje o teście
    test_start(106, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\MInE\\CARRy\\AS\\TIe\\THRow.TXT");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 107: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST107(void)
{
    // informacje o teście
    test_start(107, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\ON\\VERB\\ProTECt\\SURe\\deaL.BIN");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 108: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST108(void)
{
    // informacje o teście
    test_start(108, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\mINE\\tYPE\\KNoW\\MeaSURE");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 109: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST109(void)
{
    // informacje o teście
    test_start(109, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\ON\\WoN't\\dOG\\CHANGE.BIN");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 110: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST110(void)
{
    // informacje o teście
    test_start(110, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\ON\\bLACk\\BE\\GReEn.Tx");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 111: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST111(void)
{
    // informacje o teście
    test_start(111, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "HAD.BIN");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 112: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST112(void)
{
    // informacje o teście
    test_start(112, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "OWn.tXT");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 113: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST113(void)
{
    // informacje o teście
    test_start(113, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "BONE.BIn");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 114: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST114(void)
{
    // informacje o teście
    test_start(114, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "SUN");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 115: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST115(void)
{
    // informacje o teście
    test_start(115, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "COST");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 116: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST116(void)
{
    // informacje o teście
    test_start(116, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "WARHANDT");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 117: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST117(void)
{
    // informacje o teście
    test_start(117, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("body_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t*  dir = dir_open(volume, "gather");
            test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}




enum run_mode_t { rm_normal_with_rld = 0, rm_unit_test = 1, rm_main_test = 2 };

int __wrap_main(volatile int _argc, char** _argv, char** _envp)
{
    int volatile vargc = _argc;
    char ** volatile vargv = _argv, ** volatile venvp = _envp;
	volatile enum run_mode_t run_mode = rm_unit_test; // -1
	volatile int selected_test = -1;

    if (vargc > 1)
	{
	    char* smode = strtok(vargv[1], ",");
	    char* stest = strtok(NULL, "");
		char *errptr = NULL;
		run_mode = (enum run_mode_t)strtol(smode, &errptr, 10);
		if (*errptr == '\x0')
		{
			memmove(vargv + 1, vargv + 2, sizeof(char*) * (vargc - 1));
			vargc--;

			if (stest != NULL)
			{
			    int val = (int)strtol(stest, &errptr, 10);
			    if (*errptr == '\x0')
			        selected_test = val;
			}
		}
	}

    // printf("runmode=%d; selected_test=%d\n", run_mode, selected_test);

    // inicjuj testy jednostkowe
    unit_test_init(run_mode, "unit_test_v2.c");
    test_limit_init();
    rldebug_set_reported_severity_level(MSL_FAILURE);

    if (run_mode == rm_normal_with_rld)
    {
        // konfiguracja ograniczników
        rldebug_reset_limits();
        

        // uruchom funkcję main Studenta a potem wyświetl podsumowanie sterty i zasobów
        volatile int ret_code = rdebug_call_main(tested_main, vargc, vargv, venvp);

        rldebug_reset_limits();
        

        int leaks_detected = rldebug_show_leaked_resources(0);
        if (leaks_detected)
            raise(SIGHEAP);

        return ret_code;
    }

    
    if (run_mode == rm_unit_test)
    {
        test_title("Testy jednostkowe");

        void (*pfcn[])(void) =
        { 
            UTEST1, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST2, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST3, // Sprawdzanie poprawności działania funkcji disk_close
            UTEST4, // Sprawdzanie poprawności działania funkcji fat_open
            UTEST5, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST6, // Sprawdzanie poprawności działania funkcji file_read
            UTEST7, // Sprawdzanie poprawności działania funkcji file_read
            UTEST8, // Sprawdzanie poprawności działania funkcji file_read
            UTEST9, // Sprawdzanie poprawności działania funkcji file_read
            UTEST10, // Sprawdzanie poprawności działania funkcji file_read
            UTEST11, // Sprawdzanie poprawności działania funkcji file_read
            UTEST12, // Sprawdzanie poprawności działania funkcji file_read
            UTEST13, // Sprawdzanie poprawności działania funkcji file_read
            UTEST14, // Sprawdzanie poprawności działania funkcji file_read
            UTEST15, // Sprawdzanie poprawności działania funkcji file_read
            UTEST16, // Sprawdzanie poprawności działania funkcji file_read
            UTEST17, // Sprawdzanie poprawności działania funkcji file_read
            UTEST18, // Sprawdzanie poprawności działania funkcji file_read
            UTEST19, // Sprawdzanie poprawności działania funkcji file_read
            UTEST20, // Sprawdzanie poprawności działania funkcji file_read
            UTEST21, // Sprawdzanie poprawności działania funkcji file_read
            UTEST22, // Sprawdzanie poprawności działania funkcji file_read
            UTEST23, // Sprawdzanie poprawności działania funkcji file_read
            UTEST24, // Sprawdzanie poprawności działania funkcji file_read
            UTEST25, // Sprawdzanie poprawności działania funkcji file_read
            UTEST26, // Sprawdzanie poprawności działania funkcji file_read
            UTEST27, // Sprawdzanie poprawności działania funkcji file_read
            UTEST28, // Sprawdzanie poprawności działania funkcji file_read
            UTEST29, // Sprawdzanie poprawności działania funkcji file_read
            UTEST30, // Sprawdzanie poprawności działania funkcji file_read
            UTEST31, // Sprawdzanie poprawności działania funkcji file_read
            UTEST32, // Sprawdzanie poprawności działania funkcji file_read
            UTEST33, // Sprawdzanie poprawności działania funkcji file_read
            UTEST34, // Sprawdzanie poprawności działania funkcji file_read
            UTEST35, // Sprawdzanie poprawności działania funkcji file_read
            UTEST36, // Sprawdzanie poprawności działania funkcji file_read
            UTEST37, // Sprawdzanie poprawności działania funkcji file_read
            UTEST38, // Sprawdzanie poprawności działania funkcji file_read
            UTEST39, // Sprawdzanie poprawności działania funkcji file_read
            UTEST40, // Sprawdzanie poprawności działania funkcji file_read
            UTEST41, // Sprawdzanie poprawności działania funkcji file_read
            UTEST42, // Sprawdzanie poprawności działania funkcji file_read
            UTEST43, // Sprawdzanie poprawności działania funkcji file_read
            UTEST44, // Sprawdzanie poprawności działania funkcji file_read
            UTEST45, // Sprawdzanie poprawności działania funkcji file_read
            UTEST46, // Sprawdzanie poprawności działania funkcji file_read
            UTEST47, // Sprawdzanie poprawności działania funkcji file_read
            UTEST48, // Sprawdzanie poprawności działania funkcji file_read
            UTEST49, // Sprawdzanie poprawności działania funkcji file_read
            UTEST50, // Sprawdzanie poprawności działania funkcji file_read
            UTEST51, // Sprawdzanie poprawności działania funkcji file_read
            UTEST52, // Sprawdzanie poprawności działania funkcji file_read
            UTEST53, // Sprawdzanie poprawności działania funkcji file_read
            UTEST54, // Sprawdzanie poprawności działania funkcji file_read
            UTEST55, // Sprawdzanie poprawności działania funkcji file_read
            UTEST56, // Sprawdzanie poprawności działania funkcji file_read
            UTEST57, // Sprawdzanie poprawności działania funkcji file_read
            UTEST58, // Sprawdzanie poprawności działania funkcji file_read
            UTEST59, // Sprawdzanie poprawności działania funkcji file_read
            UTEST60, // Sprawdzanie poprawności działania funkcji file_read
            UTEST61, // Sprawdzanie poprawności działania funkcji file_read
            UTEST62, // Sprawdzanie poprawności działania funkcji file_read
            UTEST63, // Sprawdzanie poprawności działania funkcji file_read
            UTEST64, // Sprawdzanie poprawności działania funkcji file_read
            UTEST65, // Sprawdzanie poprawności działania funkcji file_read
            UTEST66, // Sprawdzanie poprawności działania funkcji file_read
            UTEST67, // Sprawdzanie poprawności działania funkcji file_read
            UTEST68, // Sprawdzanie poprawności działania funkcji file_read
            UTEST69, // Sprawdzanie poprawności działania funkcji file_read
            UTEST70, // Sprawdzanie poprawności działania funkcji file_read
            UTEST71, // Sprawdzanie poprawności działania funkcji file_read
            UTEST72, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST73, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST74, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST75, // Sprawdzanie poprawności działania funkcji file_open
            UTEST76, // Sprawdzanie poprawności działania funkcji file_open
            UTEST77, // Sprawdzanie poprawności działania funkcji file_open
            UTEST78, // Sprawdzanie poprawności działania funkcji file_open
            UTEST79, // Sprawdzanie poprawności działania funkcji file_open
            UTEST80, // Sprawdzanie poprawności działania funkcji file_open
            UTEST81, // Sprawdzanie poprawności działania funkcji file_open
            UTEST82, // Sprawdzanie poprawności działania funkcji file_open
            UTEST83, // Sprawdzanie poprawności działania funkcji file_open
            UTEST84, // Sprawdzanie poprawności działania funkcji file_open
            UTEST85, // Sprawdzanie poprawności działania funkcji file_open
            UTEST86, // Sprawdzanie poprawności działania funkcji file_open
            UTEST87, // Sprawdzanie poprawności działania funkcji file_open
            UTEST88, // Sprawdzanie poprawności działania funkcji file_open
            UTEST89, // Sprawdzanie poprawności działania funkcji file_open
            UTEST90, // Sprawdzanie poprawności działania funkcji file_open
            UTEST91, // Sprawdzanie poprawności działania funkcji file_read
            UTEST92, // Sprawdzanie poprawności działania funkcji file_read
            UTEST93, // Sprawdzanie poprawności działania funkcji file_read
            UTEST94, // Sprawdzanie poprawności działania funkcji file_close
            UTEST95, // Sprawdzanie poprawności działania funkcji file_read
            UTEST96, // Sprawdzanie poprawności działania funkcji dir_read
            UTEST97, // Sprawdzanie poprawności działania funkcji dir_read
            UTEST98, // Sprawdzanie poprawności działania funkcji dir_read
            UTEST99, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST100, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST101, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST102, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST103, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST104, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST105, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST106, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST107, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST108, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST109, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST110, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST111, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST112, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST113, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST114, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST115, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST116, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST117, // Sprawdzanie poprawności działania funkcji dir_open
            NULL
        };

        for (int idx = 0; pfcn[idx] != NULL && !test_get_session_termination_flag(); idx++)
        {
            if (selected_test == -1 || selected_test == idx + 1)
                pfcn[idx]();

            // limit niezaliczonych testów, po jakim testy jednostkowe zostaną przerwane
            if (test_session_get_fail_count() >= 1000)
                test_terminate_session();
        }


        test_title("RLDebug :: Analiza wycieku zasobów");
        // sprawdź wycieki pamięci
        int leaks_detected = rldebug_show_leaked_resources(1);
        test_set_session_leaks(leaks_detected);

        // poinformuj serwer Mrówka o wyniku testu - podsumowanie
        test_title("Podsumowanie");
        if (selected_test == -1)
            test_summary(117); // wszystkie testy muszą zakończyć się sukcesem
        else
            test_summary(1); // tylko jeden (selected_test) test musi zakończyć się  sukcesem
        return EXIT_SUCCESS;
    }
    

    if (run_mode == rm_main_test)
    {
        test_title("Testy funkcji main()");

        void (*pfcn[])(int, char**, char**) =
        { 
            NULL
        };

        for (volatile int idx = 0; pfcn[idx] != NULL && !test_get_session_termination_flag(); idx++)
        {
            if (selected_test == -1 || selected_test == idx + 1)
                pfcn[idx](vargc, vargv, venvp);

            // limit niezaliczonych testów, po jakim testy jednostkowe zostaną przerwane
            if (test_session_get_fail_count() >= 1000)
                test_terminate_session();
        }


        test_title("RLDebug :: Analiza wycieku zasobów");
        // sprawdź wycieki pamięci
        int leaks_detected = rldebug_show_leaked_resources(1);
        test_set_session_leaks(leaks_detected);

        // poinformuj serwer Mrówka o wyniku testu - podsumowanie
        test_title("Podsumowanie");
        if (selected_test == -1)
            test_summary(0); // wszystkie testy muszą zakończyć się sukcesem
        else
            test_summary(1); // tylko jeden (selected_test) test musi zakończyć się  sukcesem

        return EXIT_SUCCESS;
    }

    printf("*** Nieznana wartość RunMode: %d", (int)run_mode);
    abort();
}