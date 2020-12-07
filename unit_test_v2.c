/*
 * Unit Test Bootstrap
 * Autor: Tomasz Jaworski, 2018-2020
 *
 * Test dla zadania Projekt: ścieżki bezwzględne, wielkości liter (4,0)
 * Autor testowanej odpowiedzi: Sebastian Derendarz
 * Test wygenerowano automatycznie o 2020-12-07 11:46:32.828898
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
    


            struct disk_t* disk = disk_open_from_file("KNOW");
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
    


            struct disk_t* disk = disk_open_from_file("south.img");
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
    
        
                char *filecontent = (char *)calloc(490, 1);
                char expected_filecontent[491] = "";
        
                strcat(expected_filecontent, "thy voice.\"\n     There stood I like the friar, that doth shrive\nA wretch for murder doom\'d, who e\'en when fix\'d,\nCalleth him back, whence death awhile delays.\n     He shouted:  \"Ha! already standest there?\nAlready standest there, O Boniface!\nBy many a year the writing play\'d me false.\nSo early dost thou surfeit with the wealth,\nFor which thou fearedst not in guile to take\nThe lovely lady, and then mangle her?\"\n     I felt as those who, piercing not the drift\nOf answer made them, stand ");
                
        
                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "YarD");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 490, file);
                test_error(size == 490, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 490 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 490);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 490);


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
    
        
                char *filecontent = (char *)calloc(2474, 1);
                char expected_filecontent[2475] = "";
        
                strcat(expected_filecontent, "\'d not\nBut I remember\'d him; and towards his face\nMy hand inclining, answer\'d:  \"Sir! Brunetto!\nAnd art thou here?\"  He thus to me:  \"My son!\nOh let it not displease thee, if Brunetto\nLatini but a little space with thee\nTurn back, and leave his fellows to proceed.\"\n     I thus to him replied:  \"Much as I can,\nI thereto pray thee; and if thou be willing,\nThat I here seat me with thee, I consent;\nHis leave, with whom I journey, first obtain\'d.\"\n     \"O son!\" said he, \" whoever of this throng\nOne instant stops, lies then a hundred years,\nNo fan to ventilate him, when the fire\nSmites sorest.  Pass thou therefore on.  I close\nWill at thy garments walk, and then rejoin\nMy troop, who go mourning their endless doom.\"\n     I dar\'d not from the path descend to tread\nOn equal ground with him, but held my head\nBent down, as one who walks in reverent guise.\n     \"What chance or destiny,\" thus be began,\n\"Ere the last day conducts thee here below?\nAnd who is this, that shows to thee the way?\"\n     \"There up aloft,\" I answer\'d, \"in the life\nSerene, I wander\'d in a valley lost,\nBefore mine age had to its fullness reach\'d.\nBut yester-morn I left it:  then once more\nInto that vale returning, him I met;\nAnd by this path homeward he leads me back.\"\n     \"If thou,\" he answer\'d, \"follow but thy star,\nThou canst not miss at last a glorious haven:\nUnless in fairer days my judgment err\'d.\nAnd if my fate so early had not chanc\'d,\nSeeing the heav\'ns thus bounteous to thee, I\nHad gladly giv\'n thee comfort in thy work.\nBut that ungrateful and malignant race,\nWho in old times came down from Fesole,\nAy and still smack of their rough mountain-flint,\nWill for thy good deeds shew thee enmity.\nNor wonder; for amongst ill-savour\'d crabs\nIt suits not the sweet fig-tree lay her fruit.\nOld fame reports them in the world for blind,\nCovetous, envious, proud.  Look to it well:\nTake heed thou cleanse thee of their ways.  For thee\nThy fortune hath such honour in reserve,\nThat thou by either party shalt be crav\'d\nWith hunger keen:  but be the fresh herb far\nFrom the goat\'s tooth.  The herd of Fesole\nMay of themselves make litter, not touch the plant,\nIf any such yet spring on their rank bed,\nIn which the holy seed revives, transmitted\nFrom those true Romans, who still there remain\'d,\nWhen it was made the nest of so much ill.\"\n     \"Were all my wish fulfill\'d,\" I straight replied,\n\"Thou from the confines of man\'s nature yet\nHadst not been driven forth; for in my mind\nIs fix\'d,");
                
        
                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "CLaIm.Tx");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 2474, file);
                test_error(size == 2474, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2474 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2474);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 2474);


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
    
        
                char *filecontent = (char *)calloc(3376, 1);
                char expected_filecontent[3377] = "";
        
                strcat(expected_filecontent, "g\n        Torment, and loud lament, and furious rage.\n\nv. 50.  a puissant one.]  Our Saviour.\n\nv. 75.                 Honour the bard\n        Sublime.]\n\n        Onorate l\'altissimo poeta.\nSo Chiabrera, Canz. Eroiche. 32.\n        Onorando l\'altissimo poeta.\n\nv. 79.  Of semblance neither sorrowful nor glad.]\n        She nas to sober ne to glad.\n               Chaucer\'s Dream.\n\nv. 90.  The Monarch of sublimest song.]  Homer.\n\nv. 100.  Fitter left untold.]\n        Che\'l tacere e bello,\nSo our Poet, in Canzone 14.\n        La vide in parte che\'l tacere e bello,\nRuccellai, Le Api, 789.\n        Ch\'a dire e brutto ed a tacerlo e bello\nAnd Bembo,\n        \"Vie pui bello e il tacerle, che il favellarne.\"\n               Gli. Asol. lib. 1.\n\nv. 117.  Electra.]  The daughter of Atlas, and mother of Dardanus\nthe founder of Troy.  See Virg. Aen. b. viii. 134. as referred to\nby Dante in treatise \"De Monarchia,\" lib. ii. \"Electra, scilicet,\nnata magni nombris regis Atlantis, ut de ambobus testimonium\nreddit poeta noster in octavo ubi Aeneas ad Avandrum sic ait\n        \"Dardanus Iliacae,\" &c.\n\nv. 125.  Julia.]  The daughter of Julius Caesar, and wife of\nPompey.\n\nv. 126.  The Soldan fierce.]  Saladin or Salaheddin, the  rival\nof  Richard coeur de lion.  See D\'Herbelot, Bibl. Orient. and\nKnolles\'s Hist. of the Turks p. 57 to 73 and the Life of Saladin,\nby Bohao\'edin Ebn Shedad, published by Albert Schultens, with a\nLatin translation. He is introduced by Petrarch in the Triumph of\nFame, c. ii\n\nv. 128.  The master of the sapient throng.]\n        Maestro di color che sanno.\nAristotle--Petrarch assigns the first place to Plato. See Triumph\nof Fame, c. iii.\nPulci, in his Morgante Maggiore, c. xviii. says,\n        Tu se\'il maestro di color che sanno.\n\nv. 132.               Democritus\n        Who sets the world at chance.]\nDemocritus,who maintained the world to have been formed by the\nfortuitous concourse of atoms.\n\nv. 140.  Avicen.]  See D\'Herbelot Bibl. Orient. article  Sina. He\ndied in 1050.  Pulci here again imitates our poet:\n\n        Avicenna quel che il sentimento\n        Intese di Aristotile e i segreti,\n        Averrois che fece il gran comento.\n               Morg. Mag. c. xxv.\n\nv. 140.               Him who made\n        That commentary vast, Averroes.]\nAverroes, called by the Arabians Roschd, translated and commented\nthe works of Aristotle. According to Tiraboschi (storia della\nLett. Ital. t. v. 1. ii. c. ii. sect. 4.) he was the source of\nmodern philosophical impiety. The critic quotes some passages\nfrom Petrarch (Senil. 1. v. ep. iii. et. Oper. v. ii. p. 1143) to\nshow how strongly such sentiments prevailed in the time of that\npoet, by whom they were held in horror and detestation He adds,\nthat this fanatic admirer of Aristotle translated his writings\nwith that felicity, which might be expected from one who did not\nknow a syllable of Greek, and who was therefore compelled to\navail himself of the unfaithful Arabic versions. D\'Herbelot, on\nthe other hand, informs us, that \"Averroes was the first who\ntranslated Aristotle from Greek into Arabic, before the Jews had\nmade their translation:  and that we had for a long time no other\ntext of Aristotle, except that of the Latin translation, which\nwas made from this Arabic version of this great philosopher\n(Averroes), who afterwards added to it a very ample commentary,\nof which Thomas Aquinas");
                
        
                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "CRoP.Tx");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 3376, file);
                test_error(size == 3376, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3376 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3376);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 3376);


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
    
        
                char *filecontent = (char *)calloc(1593, 1);
                char expected_filecontent[1594] = "";
        
                strcat(expected_filecontent, "n idle play.\"\n     Such were the words that Beatrice spake:\nThese ended, to that region, where the world\nIs liveliest, full of fond desire she turn\'d.\n     Though mainly prompt new question to propose,\nHer silence and chang\'d look did keep me dumb.\nAnd as the arrow, ere the cord is still,\nLeapeth unto its mark; so on we sped\nInto the second realm.  There I beheld\nThe dame, so joyous enter, that the orb\nGrew brighter at her smiles; and, if the star\nWere mov\'d to gladness, what then was my cheer,\nWhom nature hath made apt for every change!\n     As in a quiet and clear lake the fish,\nIf aught approach them from without, do draw\nTowards it, deeming it their food; so drew\nFull more than thousand splendours towards us,\nAnd in each one was heard:  \"Lo!  one arriv\'d\nTo multiply our loves!\" and as each came\nThe shadow, streaming forth effulgence new,\nWitness\'d augmented joy.  Here, reader!  think,\nIf thou didst miss the sequel of my tale,\nTo know the rest how sorely thou wouldst crave;\nAnd thou shalt see what vehement desire\nPossess\'d me, as soon as these had met my view,\nTo know their state.  \"O born in happy hour!\nThou to whom grace vouchsafes, or ere thy close\nOf fleshly warfare, to behold the thrones\nOf that eternal triumph, know to us\nThe light communicated, which through heaven\nExpatiates without bound.  Therefore, if aught\nThou of our beams wouldst borrow for thine aid,\nSpare not; and of our radiance take thy fill.\"\n     Thus of those piteous spirits one bespake me;\nAnd Beatrice next:  \"Say on; and trust\nAs unto gods!\" --\"How in the light supreme\nThou harbour\'st, and f");
                
        
                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "STuDY.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 1593, file);
                test_error(size == 1593, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1593 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 1593);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 1593);


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
    
        
                char *filecontent = (char *)calloc(3584, 1);
                char expected_filecontent[3585] = "";
        
                strcat(expected_filecontent, "with the change.  In that abyss\nOf radiance, clear and lofty, seem\'d methought,\nThree orbs of triple hue clipt in one bound:\nAnd, from another, one reflected seem\'d,\nAs rainbow is from rainbow: and the third\nSeem\'d fire, breath\'d equally from both.  Oh speech\nHow feeble and how faint art thou, to give\nConception birth!  Yet this to what I saw\nIs less than little.  Oh eternal light!\nSole in thyself that dwellst; and of thyself\nSole understood, past, present, or to come!\nThou smiledst; on that circling, which in thee\nSeem\'d as reflected splendour, while I mus\'d;\nFor I therein, methought, in its own hue\nBeheld our image painted: steadfastly\nI therefore por\'d upon the view.  As one\nWho vers\'d in geometric lore, would fain\nMeasure the circle; and, though pondering long\nAnd deeply, that beginning, which he needs,\nFinds not; e\'en such was I, intent to scan\nThe novel wonder, and trace out the form,\nHow to the circle fitted, and therein\nHow plac\'d: but the flight was not for my wing;\nHad not a flash darted athwart my mind,\nAnd in the spleen unfolded what it sought.\n     Here vigour fail\'d the tow\'ring fantasy:\nBut yet the will roll\'d onward, like a wheel\nIn even motion, by the Love impell\'d,\nThat moves the sun in heav\'n and all the stars.\n\n\nNOTES TO PARADISE\n\n\nCANTO 1\n\nVerse 12.  Benign Apollo.]  Chaucer has imitated this invention\nvery closely at the beginning of the Third Booke of Fame.\n\nIf, divine vertue, thou\nWilt helpe me to shewe  now\nThat in my head ymarked is,\n     * * * * *\nThou shalt see me go as blive\nUnto the next laurer I see,\nAnd kisse it for it is thy tree\nNow entre thou my breast anone.\n\nv. 15.  Thus for.]  He appears to mean nothing more than that\nthis part of his poem will require a greater exertion of his\npowers than the former.\n\nv. 19.  Marsyas.]  Ovid, Met. 1. vi. fab. 7.  Compare Boccaccio,\nII Filocopo, 1.  5. p. 25. v. ii. Ediz.  Fir.  1723.  \"Egli nel\nmio petto entri,\" &c. - \"May he enter my bosom, and let my voice\nsound like his own, when he made that daring mortal deserve to\ncome forth unsheathed from his limbs. \"\nv. 29.  Caesar, or bard.]  So Petrarch, Son.  Par. Prima.\n\nArbor vittoriosa e trionfale,\nOnor d\'imperadori e di poeti.\n\nAnd Spenser, F. Q. b. i. c. 1.  st. 9,\nThe laurel, meed of mighty conquerours\nAnd poets sage.\n\nv. 37.  Through that.]  \"Where the four circles, the horizon, the\nzodiac, the equator, and the equinoctial colure, join; the last\nthreeintersecting each other so as to form three crosses, as may\nbe seen in the armillary sphere.\"\n\nv. 39.  In happiest constellation.]  Aries.  Some understand the\nplanetVenus by the \"miglior stella \"\n\nv. 44.  To the left.]  Being in the opposite hemisphere to ours,\nBeatrice that she may behold the rising sun, turns herself to the\nleft.\n\nv. 47.  As from the first a second beam.]  \"Like a reflected\nsunbeam,\" which he compares to a pilgrim hastening homewards.\n\nNe simil tanto mal raggio secondo\nDal primo usci.\nFilicaja, canz. 15. st. 4.\n\nv. 58.  As iron that comes boiling from the fire.]  So Milton,\nP.  L.  b. iii.  594.\n--As glowing iron with fire.\n\nv. 69.  Upon the day appear\'d.\n\n--If the heaven had ywonne,\nAll new of God another sunne.\nChaucer, First Booke of Fame\n\nE par ch\' agginuga un altro sole al cielo.\nAriosto, O F.  c.  x.  st.  109.\n\nEd ecco un lustro lampeggiar d\' intorno\nChe sole a sole aggiunse e giorno a giorno.\nManno, Adone.  c. xi. st. 27.\n\nQuando a paro col sol ma piu lucente\nL\'angelo gli appari sull; oriente\nTasso, G. L. c. i.\n\n-Seems another morn\nRis\'n on mid-noon.\nMilton, P. L. b. v. 311.\n\nCompare Euripides, Ion. 1550.  [GREEK HERE]\n66");
                
        
                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "whETHEr.Tx");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 3584, file);
                test_error(size == 3584, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3584 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3584);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 3584);


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
    
        
                char *filecontent = (char *)calloc(186, 1);
                char expected_filecontent[187] = "";
        
                strcat(expected_filecontent, "light,\nLight intellectual replete with love,\nLove of true happiness replete with joy,\nJoy, that transcends all sweetness of delight.\nHere shalt thou look on either mighty host\nOf Paradis");
                
        
                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "STreAMBA.bIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 186, file);
                test_error(size == 186, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 186 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 186);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 186);


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
    

                char *filecontent = (char *)calloc(490, 1);
                char expected_filecontent[491] = "";

                strcat(expected_filecontent, "thy voice.\"\n     There stood I like the friar, that doth shrive\nA wretch for murder doom\'d, who e\'en when fix\'d,\nCalleth him back, whence death awhile delays.\n     He shouted:  \"Ha! already standest there?\nAlready standest there, O Boniface!\nBy many a year the writing play\'d me false.\nSo early dost thou surfeit with the wealth,\nFor which thou fearedst not in guile to take\nThe lovely lady, and then mangle her?\"\n     I felt as those who, piercing not the drift\nOf answer made them, stand ");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "YARD");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 857, file);
                test_error(size == 490, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 490 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 490);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 490);


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
    

                char *filecontent = (char *)calloc(2474, 1);
                char expected_filecontent[2475] = "";

                strcat(expected_filecontent, "\'d not\nBut I remember\'d him; and towards his face\nMy hand inclining, answer\'d:  \"Sir! Brunetto!\nAnd art thou here?\"  He thus to me:  \"My son!\nOh let it not displease thee, if Brunetto\nLatini but a little space with thee\nTurn back, and leave his fellows to proceed.\"\n     I thus to him replied:  \"Much as I can,\nI thereto pray thee; and if thou be willing,\nThat I here seat me with thee, I consent;\nHis leave, with whom I journey, first obtain\'d.\"\n     \"O son!\" said he, \" whoever of this throng\nOne instant stops, lies then a hundred years,\nNo fan to ventilate him, when the fire\nSmites sorest.  Pass thou therefore on.  I close\nWill at thy garments walk, and then rejoin\nMy troop, who go mourning their endless doom.\"\n     I dar\'d not from the path descend to tread\nOn equal ground with him, but held my head\nBent down, as one who walks in reverent guise.\n     \"What chance or destiny,\" thus be began,\n\"Ere the last day conducts thee here below?\nAnd who is this, that shows to thee the way?\"\n     \"There up aloft,\" I answer\'d, \"in the life\nSerene, I wander\'d in a valley lost,\nBefore mine age had to its fullness reach\'d.\nBut yester-morn I left it:  then once more\nInto that vale returning, him I met;\nAnd by this path homeward he leads me back.\"\n     \"If thou,\" he answer\'d, \"follow but thy star,\nThou canst not miss at last a glorious haven:\nUnless in fairer days my judgment err\'d.\nAnd if my fate so early had not chanc\'d,\nSeeing the heav\'ns thus bounteous to thee, I\nHad gladly giv\'n thee comfort in thy work.\nBut that ungrateful and malignant race,\nWho in old times came down from Fesole,\nAy and still smack of their rough mountain-flint,\nWill for thy good deeds shew thee enmity.\nNor wonder; for amongst ill-savour\'d crabs\nIt suits not the sweet fig-tree lay her fruit.\nOld fame reports them in the world for blind,\nCovetous, envious, proud.  Look to it well:\nTake heed thou cleanse thee of their ways.  For thee\nThy fortune hath such honour in reserve,\nThat thou by either party shalt be crav\'d\nWith hunger keen:  but be the fresh herb far\nFrom the goat\'s tooth.  The herd of Fesole\nMay of themselves make litter, not touch the plant,\nIf any such yet spring on their rank bed,\nIn which the holy seed revives, transmitted\nFrom those true Romans, who still there remain\'d,\nWhen it was made the nest of so much ill.\"\n     \"Were all my wish fulfill\'d,\" I straight replied,\n\"Thou from the confines of man\'s nature yet\nHadst not been driven forth; for in my mind\nIs fix\'d,");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "cLAiM.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 2909, file);
                test_error(size == 2474, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2474 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2474);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 2474);


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
    

                char *filecontent = (char *)calloc(3376, 1);
                char expected_filecontent[3377] = "";

                strcat(expected_filecontent, "g\n        Torment, and loud lament, and furious rage.\n\nv. 50.  a puissant one.]  Our Saviour.\n\nv. 75.                 Honour the bard\n        Sublime.]\n\n        Onorate l\'altissimo poeta.\nSo Chiabrera, Canz. Eroiche. 32.\n        Onorando l\'altissimo poeta.\n\nv. 79.  Of semblance neither sorrowful nor glad.]\n        She nas to sober ne to glad.\n               Chaucer\'s Dream.\n\nv. 90.  The Monarch of sublimest song.]  Homer.\n\nv. 100.  Fitter left untold.]\n        Che\'l tacere e bello,\nSo our Poet, in Canzone 14.\n        La vide in parte che\'l tacere e bello,\nRuccellai, Le Api, 789.\n        Ch\'a dire e brutto ed a tacerlo e bello\nAnd Bembo,\n        \"Vie pui bello e il tacerle, che il favellarne.\"\n               Gli. Asol. lib. 1.\n\nv. 117.  Electra.]  The daughter of Atlas, and mother of Dardanus\nthe founder of Troy.  See Virg. Aen. b. viii. 134. as referred to\nby Dante in treatise \"De Monarchia,\" lib. ii. \"Electra, scilicet,\nnata magni nombris regis Atlantis, ut de ambobus testimonium\nreddit poeta noster in octavo ubi Aeneas ad Avandrum sic ait\n        \"Dardanus Iliacae,\" &c.\n\nv. 125.  Julia.]  The daughter of Julius Caesar, and wife of\nPompey.\n\nv. 126.  The Soldan fierce.]  Saladin or Salaheddin, the  rival\nof  Richard coeur de lion.  See D\'Herbelot, Bibl. Orient. and\nKnolles\'s Hist. of the Turks p. 57 to 73 and the Life of Saladin,\nby Bohao\'edin Ebn Shedad, published by Albert Schultens, with a\nLatin translation. He is introduced by Petrarch in the Triumph of\nFame, c. ii\n\nv. 128.  The master of the sapient throng.]\n        Maestro di color che sanno.\nAristotle--Petrarch assigns the first place to Plato. See Triumph\nof Fame, c. iii.\nPulci, in his Morgante Maggiore, c. xviii. says,\n        Tu se\'il maestro di color che sanno.\n\nv. 132.               Democritus\n        Who sets the world at chance.]\nDemocritus,who maintained the world to have been formed by the\nfortuitous concourse of atoms.\n\nv. 140.  Avicen.]  See D\'Herbelot Bibl. Orient. article  Sina. He\ndied in 1050.  Pulci here again imitates our poet:\n\n        Avicenna quel che il sentimento\n        Intese di Aristotile e i segreti,\n        Averrois che fece il gran comento.\n               Morg. Mag. c. xxv.\n\nv. 140.               Him who made\n        That commentary vast, Averroes.]\nAverroes, called by the Arabians Roschd, translated and commented\nthe works of Aristotle. According to Tiraboschi (storia della\nLett. Ital. t. v. 1. ii. c. ii. sect. 4.) he was the source of\nmodern philosophical impiety. The critic quotes some passages\nfrom Petrarch (Senil. 1. v. ep. iii. et. Oper. v. ii. p. 1143) to\nshow how strongly such sentiments prevailed in the time of that\npoet, by whom they were held in horror and detestation He adds,\nthat this fanatic admirer of Aristotle translated his writings\nwith that felicity, which might be expected from one who did not\nknow a syllable of Greek, and who was therefore compelled to\navail himself of the unfaithful Arabic versions. D\'Herbelot, on\nthe other hand, informs us, that \"Averroes was the first who\ntranslated Aristotle from Greek into Arabic, before the Jews had\nmade their translation:  and that we had for a long time no other\ntext of Aristotle, except that of the Latin translation, which\nwas made from this Arabic version of this great philosopher\n(Averroes), who afterwards added to it a very ample commentary,\nof which Thomas Aquinas");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "crOp.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 3534, file);
                test_error(size == 3376, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3376 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3376);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 3376);


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
    

                char *filecontent = (char *)calloc(1593, 1);
                char expected_filecontent[1594] = "";

                strcat(expected_filecontent, "n idle play.\"\n     Such were the words that Beatrice spake:\nThese ended, to that region, where the world\nIs liveliest, full of fond desire she turn\'d.\n     Though mainly prompt new question to propose,\nHer silence and chang\'d look did keep me dumb.\nAnd as the arrow, ere the cord is still,\nLeapeth unto its mark; so on we sped\nInto the second realm.  There I beheld\nThe dame, so joyous enter, that the orb\nGrew brighter at her smiles; and, if the star\nWere mov\'d to gladness, what then was my cheer,\nWhom nature hath made apt for every change!\n     As in a quiet and clear lake the fish,\nIf aught approach them from without, do draw\nTowards it, deeming it their food; so drew\nFull more than thousand splendours towards us,\nAnd in each one was heard:  \"Lo!  one arriv\'d\nTo multiply our loves!\" and as each came\nThe shadow, streaming forth effulgence new,\nWitness\'d augmented joy.  Here, reader!  think,\nIf thou didst miss the sequel of my tale,\nTo know the rest how sorely thou wouldst crave;\nAnd thou shalt see what vehement desire\nPossess\'d me, as soon as these had met my view,\nTo know their state.  \"O born in happy hour!\nThou to whom grace vouchsafes, or ere thy close\nOf fleshly warfare, to behold the thrones\nOf that eternal triumph, know to us\nThe light communicated, which through heaven\nExpatiates without bound.  Therefore, if aught\nThou of our beams wouldst borrow for thine aid,\nSpare not; and of our radiance take thy fill.\"\n     Thus of those piteous spirits one bespake me;\nAnd Beatrice next:  \"Say on; and trust\nAs unto gods!\" --\"How in the light supreme\nThou harbour\'st, and f");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "STuDy.TXt");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 1731, file);
                test_error(size == 1593, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1593 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 1593);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 1593);


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
    

                char *filecontent = (char *)calloc(3584, 1);
                char expected_filecontent[3585] = "";

                strcat(expected_filecontent, "with the change.  In that abyss\nOf radiance, clear and lofty, seem\'d methought,\nThree orbs of triple hue clipt in one bound:\nAnd, from another, one reflected seem\'d,\nAs rainbow is from rainbow: and the third\nSeem\'d fire, breath\'d equally from both.  Oh speech\nHow feeble and how faint art thou, to give\nConception birth!  Yet this to what I saw\nIs less than little.  Oh eternal light!\nSole in thyself that dwellst; and of thyself\nSole understood, past, present, or to come!\nThou smiledst; on that circling, which in thee\nSeem\'d as reflected splendour, while I mus\'d;\nFor I therein, methought, in its own hue\nBeheld our image painted: steadfastly\nI therefore por\'d upon the view.  As one\nWho vers\'d in geometric lore, would fain\nMeasure the circle; and, though pondering long\nAnd deeply, that beginning, which he needs,\nFinds not; e\'en such was I, intent to scan\nThe novel wonder, and trace out the form,\nHow to the circle fitted, and therein\nHow plac\'d: but the flight was not for my wing;\nHad not a flash darted athwart my mind,\nAnd in the spleen unfolded what it sought.\n     Here vigour fail\'d the tow\'ring fantasy:\nBut yet the will roll\'d onward, like a wheel\nIn even motion, by the Love impell\'d,\nThat moves the sun in heav\'n and all the stars.\n\n\nNOTES TO PARADISE\n\n\nCANTO 1\n\nVerse 12.  Benign Apollo.]  Chaucer has imitated this invention\nvery closely at the beginning of the Third Booke of Fame.\n\nIf, divine vertue, thou\nWilt helpe me to shewe  now\nThat in my head ymarked is,\n     * * * * *\nThou shalt see me go as blive\nUnto the next laurer I see,\nAnd kisse it for it is thy tree\nNow entre thou my breast anone.\n\nv. 15.  Thus for.]  He appears to mean nothing more than that\nthis part of his poem will require a greater exertion of his\npowers than the former.\n\nv. 19.  Marsyas.]  Ovid, Met. 1. vi. fab. 7.  Compare Boccaccio,\nII Filocopo, 1.  5. p. 25. v. ii. Ediz.  Fir.  1723.  \"Egli nel\nmio petto entri,\" &c. - \"May he enter my bosom, and let my voice\nsound like his own, when he made that daring mortal deserve to\ncome forth unsheathed from his limbs. \"\nv. 29.  Caesar, or bard.]  So Petrarch, Son.  Par. Prima.\n\nArbor vittoriosa e trionfale,\nOnor d\'imperadori e di poeti.\n\nAnd Spenser, F. Q. b. i. c. 1.  st. 9,\nThe laurel, meed of mighty conquerours\nAnd poets sage.\n\nv. 37.  Through that.]  \"Where the four circles, the horizon, the\nzodiac, the equator, and the equinoctial colure, join; the last\nthreeintersecting each other so as to form three crosses, as may\nbe seen in the armillary sphere.\"\n\nv. 39.  In happiest constellation.]  Aries.  Some understand the\nplanetVenus by the \"miglior stella \"\n\nv. 44.  To the left.]  Being in the opposite hemisphere to ours,\nBeatrice that she may behold the rising sun, turns herself to the\nleft.\n\nv. 47.  As from the first a second beam.]  \"Like a reflected\nsunbeam,\" which he compares to a pilgrim hastening homewards.\n\nNe simil tanto mal raggio secondo\nDal primo usci.\nFilicaja, canz. 15. st. 4.\n\nv. 58.  As iron that comes boiling from the fire.]  So Milton,\nP.  L.  b. iii.  594.\n--As glowing iron with fire.\n\nv. 69.  Upon the day appear\'d.\n\n--If the heaven had ywonne,\nAll new of God another sunne.\nChaucer, First Booke of Fame\n\nE par ch\' agginuga un altro sole al cielo.\nAriosto, O F.  c.  x.  st.  109.\n\nEd ecco un lustro lampeggiar d\' intorno\nChe sole a sole aggiunse e giorno a giorno.\nManno, Adone.  c. xi. st. 27.\n\nQuando a paro col sol ma piu lucente\nL\'angelo gli appari sull; oriente\nTasso, G. L. c. i.\n\n-Seems another morn\nRis\'n on mid-noon.\nMilton, P. L. b. v. 311.\n\nCompare Euripides, Ion. 1550.  [GREEK HERE]\n66");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "wHETHeR.Tx");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 3695, file);
                test_error(size == 3584, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3584 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3584);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 3584);


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
    

                char *filecontent = (char *)calloc(186, 1);
                char expected_filecontent[187] = "";

                strcat(expected_filecontent, "light,\nLight intellectual replete with love,\nLove of true happiness replete with joy,\nJoy, that transcends all sweetness of delight.\nHere shalt thou look on either mighty host\nOf Paradis");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "stREAMBA.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 458, file);
                test_error(size == 186, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 186 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 186);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 186);


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
    

                char *filecontent = (char *)calloc(490, 1);
                char expected_filecontent[491] = "";

                strcat(expected_filecontent, "thy voice.\"\n     There stood I like the friar, that doth shrive\nA wretch for murder doom\'d, who e\'en when fix\'d,\nCalleth him back, whence death awhile delays.\n     He shouted:  \"Ha! already standest there?\nAlready standest there, O Boniface!\nBy many a year the writing play\'d me false.\nSo early dost thou surfeit with the wealth,\nFor which thou fearedst not in guile to take\nThe lovely lady, and then mangle her?\"\n     I felt as those who, piercing not the drift\nOf answer made them, stand ");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "YARD");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 767, file);
                test_error(size == 490, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 490 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 490);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 490);


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
    

                char *filecontent = (char *)calloc(2474, 1);
                char expected_filecontent[2475] = "";

                strcat(expected_filecontent, "\'d not\nBut I remember\'d him; and towards his face\nMy hand inclining, answer\'d:  \"Sir! Brunetto!\nAnd art thou here?\"  He thus to me:  \"My son!\nOh let it not displease thee, if Brunetto\nLatini but a little space with thee\nTurn back, and leave his fellows to proceed.\"\n     I thus to him replied:  \"Much as I can,\nI thereto pray thee; and if thou be willing,\nThat I here seat me with thee, I consent;\nHis leave, with whom I journey, first obtain\'d.\"\n     \"O son!\" said he, \" whoever of this throng\nOne instant stops, lies then a hundred years,\nNo fan to ventilate him, when the fire\nSmites sorest.  Pass thou therefore on.  I close\nWill at thy garments walk, and then rejoin\nMy troop, who go mourning their endless doom.\"\n     I dar\'d not from the path descend to tread\nOn equal ground with him, but held my head\nBent down, as one who walks in reverent guise.\n     \"What chance or destiny,\" thus be began,\n\"Ere the last day conducts thee here below?\nAnd who is this, that shows to thee the way?\"\n     \"There up aloft,\" I answer\'d, \"in the life\nSerene, I wander\'d in a valley lost,\nBefore mine age had to its fullness reach\'d.\nBut yester-morn I left it:  then once more\nInto that vale returning, him I met;\nAnd by this path homeward he leads me back.\"\n     \"If thou,\" he answer\'d, \"follow but thy star,\nThou canst not miss at last a glorious haven:\nUnless in fairer days my judgment err\'d.\nAnd if my fate so early had not chanc\'d,\nSeeing the heav\'ns thus bounteous to thee, I\nHad gladly giv\'n thee comfort in thy work.\nBut that ungrateful and malignant race,\nWho in old times came down from Fesole,\nAy and still smack of their rough mountain-flint,\nWill for thy good deeds shew thee enmity.\nNor wonder; for amongst ill-savour\'d crabs\nIt suits not the sweet fig-tree lay her fruit.\nOld fame reports them in the world for blind,\nCovetous, envious, proud.  Look to it well:\nTake heed thou cleanse thee of their ways.  For thee\nThy fortune hath such honour in reserve,\nThat thou by either party shalt be crav\'d\nWith hunger keen:  but be the fresh herb far\nFrom the goat\'s tooth.  The herd of Fesole\nMay of themselves make litter, not touch the plant,\nIf any such yet spring on their rank bed,\nIn which the holy seed revives, transmitted\nFrom those true Romans, who still there remain\'d,\nWhen it was made the nest of so much ill.\"\n     \"Were all my wish fulfill\'d,\" I straight replied,\n\"Thou from the confines of man\'s nature yet\nHadst not been driven forth; for in my mind\nIs fix\'d,");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "CLaIm.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 2862, file);
                test_error(size == 2474, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2474 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2474);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 2474);


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
    

                char *filecontent = (char *)calloc(3376, 1);
                char expected_filecontent[3377] = "";

                strcat(expected_filecontent, "g\n        Torment, and loud lament, and furious rage.\n\nv. 50.  a puissant one.]  Our Saviour.\n\nv. 75.                 Honour the bard\n        Sublime.]\n\n        Onorate l\'altissimo poeta.\nSo Chiabrera, Canz. Eroiche. 32.\n        Onorando l\'altissimo poeta.\n\nv. 79.  Of semblance neither sorrowful nor glad.]\n        She nas to sober ne to glad.\n               Chaucer\'s Dream.\n\nv. 90.  The Monarch of sublimest song.]  Homer.\n\nv. 100.  Fitter left untold.]\n        Che\'l tacere e bello,\nSo our Poet, in Canzone 14.\n        La vide in parte che\'l tacere e bello,\nRuccellai, Le Api, 789.\n        Ch\'a dire e brutto ed a tacerlo e bello\nAnd Bembo,\n        \"Vie pui bello e il tacerle, che il favellarne.\"\n               Gli. Asol. lib. 1.\n\nv. 117.  Electra.]  The daughter of Atlas, and mother of Dardanus\nthe founder of Troy.  See Virg. Aen. b. viii. 134. as referred to\nby Dante in treatise \"De Monarchia,\" lib. ii. \"Electra, scilicet,\nnata magni nombris regis Atlantis, ut de ambobus testimonium\nreddit poeta noster in octavo ubi Aeneas ad Avandrum sic ait\n        \"Dardanus Iliacae,\" &c.\n\nv. 125.  Julia.]  The daughter of Julius Caesar, and wife of\nPompey.\n\nv. 126.  The Soldan fierce.]  Saladin or Salaheddin, the  rival\nof  Richard coeur de lion.  See D\'Herbelot, Bibl. Orient. and\nKnolles\'s Hist. of the Turks p. 57 to 73 and the Life of Saladin,\nby Bohao\'edin Ebn Shedad, published by Albert Schultens, with a\nLatin translation. He is introduced by Petrarch in the Triumph of\nFame, c. ii\n\nv. 128.  The master of the sapient throng.]\n        Maestro di color che sanno.\nAristotle--Petrarch assigns the first place to Plato. See Triumph\nof Fame, c. iii.\nPulci, in his Morgante Maggiore, c. xviii. says,\n        Tu se\'il maestro di color che sanno.\n\nv. 132.               Democritus\n        Who sets the world at chance.]\nDemocritus,who maintained the world to have been formed by the\nfortuitous concourse of atoms.\n\nv. 140.  Avicen.]  See D\'Herbelot Bibl. Orient. article  Sina. He\ndied in 1050.  Pulci here again imitates our poet:\n\n        Avicenna quel che il sentimento\n        Intese di Aristotile e i segreti,\n        Averrois che fece il gran comento.\n               Morg. Mag. c. xxv.\n\nv. 140.               Him who made\n        That commentary vast, Averroes.]\nAverroes, called by the Arabians Roschd, translated and commented\nthe works of Aristotle. According to Tiraboschi (storia della\nLett. Ital. t. v. 1. ii. c. ii. sect. 4.) he was the source of\nmodern philosophical impiety. The critic quotes some passages\nfrom Petrarch (Senil. 1. v. ep. iii. et. Oper. v. ii. p. 1143) to\nshow how strongly such sentiments prevailed in the time of that\npoet, by whom they were held in horror and detestation He adds,\nthat this fanatic admirer of Aristotle translated his writings\nwith that felicity, which might be expected from one who did not\nknow a syllable of Greek, and who was therefore compelled to\navail himself of the unfaithful Arabic versions. D\'Herbelot, on\nthe other hand, informs us, that \"Averroes was the first who\ntranslated Aristotle from Greek into Arabic, before the Jews had\nmade their translation:  and that we had for a long time no other\ntext of Aristotle, except that of the Latin translation, which\nwas made from this Arabic version of this great philosopher\n(Averroes), who afterwards added to it a very ample commentary,\nof which Thomas Aquinas");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "CRop.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 3484, file);
                test_error(size == 3376, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3376 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3376);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 3376);


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
    

                char *filecontent = (char *)calloc(1593, 1);
                char expected_filecontent[1594] = "";

                strcat(expected_filecontent, "n idle play.\"\n     Such were the words that Beatrice spake:\nThese ended, to that region, where the world\nIs liveliest, full of fond desire she turn\'d.\n     Though mainly prompt new question to propose,\nHer silence and chang\'d look did keep me dumb.\nAnd as the arrow, ere the cord is still,\nLeapeth unto its mark; so on we sped\nInto the second realm.  There I beheld\nThe dame, so joyous enter, that the orb\nGrew brighter at her smiles; and, if the star\nWere mov\'d to gladness, what then was my cheer,\nWhom nature hath made apt for every change!\n     As in a quiet and clear lake the fish,\nIf aught approach them from without, do draw\nTowards it, deeming it their food; so drew\nFull more than thousand splendours towards us,\nAnd in each one was heard:  \"Lo!  one arriv\'d\nTo multiply our loves!\" and as each came\nThe shadow, streaming forth effulgence new,\nWitness\'d augmented joy.  Here, reader!  think,\nIf thou didst miss the sequel of my tale,\nTo know the rest how sorely thou wouldst crave;\nAnd thou shalt see what vehement desire\nPossess\'d me, as soon as these had met my view,\nTo know their state.  \"O born in happy hour!\nThou to whom grace vouchsafes, or ere thy close\nOf fleshly warfare, to behold the thrones\nOf that eternal triumph, know to us\nThe light communicated, which through heaven\nExpatiates without bound.  Therefore, if aught\nThou of our beams wouldst borrow for thine aid,\nSpare not; and of our radiance take thy fill.\"\n     Thus of those piteous spirits one bespake me;\nAnd Beatrice next:  \"Say on; and trust\nAs unto gods!\" --\"How in the light supreme\nThou harbour\'st, and f");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "STuDY.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 1717, file);
                test_error(size == 1593, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1593 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 1593);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 1593);


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
    

                char *filecontent = (char *)calloc(3584, 1);
                char expected_filecontent[3585] = "";

                strcat(expected_filecontent, "with the change.  In that abyss\nOf radiance, clear and lofty, seem\'d methought,\nThree orbs of triple hue clipt in one bound:\nAnd, from another, one reflected seem\'d,\nAs rainbow is from rainbow: and the third\nSeem\'d fire, breath\'d equally from both.  Oh speech\nHow feeble and how faint art thou, to give\nConception birth!  Yet this to what I saw\nIs less than little.  Oh eternal light!\nSole in thyself that dwellst; and of thyself\nSole understood, past, present, or to come!\nThou smiledst; on that circling, which in thee\nSeem\'d as reflected splendour, while I mus\'d;\nFor I therein, methought, in its own hue\nBeheld our image painted: steadfastly\nI therefore por\'d upon the view.  As one\nWho vers\'d in geometric lore, would fain\nMeasure the circle; and, though pondering long\nAnd deeply, that beginning, which he needs,\nFinds not; e\'en such was I, intent to scan\nThe novel wonder, and trace out the form,\nHow to the circle fitted, and therein\nHow plac\'d: but the flight was not for my wing;\nHad not a flash darted athwart my mind,\nAnd in the spleen unfolded what it sought.\n     Here vigour fail\'d the tow\'ring fantasy:\nBut yet the will roll\'d onward, like a wheel\nIn even motion, by the Love impell\'d,\nThat moves the sun in heav\'n and all the stars.\n\n\nNOTES TO PARADISE\n\n\nCANTO 1\n\nVerse 12.  Benign Apollo.]  Chaucer has imitated this invention\nvery closely at the beginning of the Third Booke of Fame.\n\nIf, divine vertue, thou\nWilt helpe me to shewe  now\nThat in my head ymarked is,\n     * * * * *\nThou shalt see me go as blive\nUnto the next laurer I see,\nAnd kisse it for it is thy tree\nNow entre thou my breast anone.\n\nv. 15.  Thus for.]  He appears to mean nothing more than that\nthis part of his poem will require a greater exertion of his\npowers than the former.\n\nv. 19.  Marsyas.]  Ovid, Met. 1. vi. fab. 7.  Compare Boccaccio,\nII Filocopo, 1.  5. p. 25. v. ii. Ediz.  Fir.  1723.  \"Egli nel\nmio petto entri,\" &c. - \"May he enter my bosom, and let my voice\nsound like his own, when he made that daring mortal deserve to\ncome forth unsheathed from his limbs. \"\nv. 29.  Caesar, or bard.]  So Petrarch, Son.  Par. Prima.\n\nArbor vittoriosa e trionfale,\nOnor d\'imperadori e di poeti.\n\nAnd Spenser, F. Q. b. i. c. 1.  st. 9,\nThe laurel, meed of mighty conquerours\nAnd poets sage.\n\nv. 37.  Through that.]  \"Where the four circles, the horizon, the\nzodiac, the equator, and the equinoctial colure, join; the last\nthreeintersecting each other so as to form three crosses, as may\nbe seen in the armillary sphere.\"\n\nv. 39.  In happiest constellation.]  Aries.  Some understand the\nplanetVenus by the \"miglior stella \"\n\nv. 44.  To the left.]  Being in the opposite hemisphere to ours,\nBeatrice that she may behold the rising sun, turns herself to the\nleft.\n\nv. 47.  As from the first a second beam.]  \"Like a reflected\nsunbeam,\" which he compares to a pilgrim hastening homewards.\n\nNe simil tanto mal raggio secondo\nDal primo usci.\nFilicaja, canz. 15. st. 4.\n\nv. 58.  As iron that comes boiling from the fire.]  So Milton,\nP.  L.  b. iii.  594.\n--As glowing iron with fire.\n\nv. 69.  Upon the day appear\'d.\n\n--If the heaven had ywonne,\nAll new of God another sunne.\nChaucer, First Booke of Fame\n\nE par ch\' agginuga un altro sole al cielo.\nAriosto, O F.  c.  x.  st.  109.\n\nEd ecco un lustro lampeggiar d\' intorno\nChe sole a sole aggiunse e giorno a giorno.\nManno, Adone.  c. xi. st. 27.\n\nQuando a paro col sol ma piu lucente\nL\'angelo gli appari sull; oriente\nTasso, G. L. c. i.\n\n-Seems another morn\nRis\'n on mid-noon.\nMilton, P. L. b. v. 311.\n\nCompare Euripides, Ion. 1550.  [GREEK HERE]\n66");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "WHEtHER.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 3805, file);
                test_error(size == 3584, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3584 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3584);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 3584);


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
    

                char *filecontent = (char *)calloc(186, 1);
                char expected_filecontent[187] = "";

                strcat(expected_filecontent, "light,\nLight intellectual replete with love,\nLove of true happiness replete with joy,\nJoy, that transcends all sweetness of delight.\nHere shalt thou look on either mighty host\nOf Paradis");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "STREAMBa.BiN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 411, file);
                test_error(size == 186, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 186 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 186);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 186);


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
    

            char expected_filecontent[294] = "";

            strcat(expected_filecontent, "nd turn red.\nIn shepherd\'s clothing greedy wolves below\nRange wide o\'er all the pastures.  Arm of God!\nWhy longer sleepst thou?  Caorsines and Gascona\nPrepare to quaff our blood.  O good beginning\nTo what a vile conclusion must thou stoop!\nBut the high providence, which did defend\nThrough Sci");

            struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "\\tHEIR\\..\\THEIr\\ToGEtHEr\\.\\gENERAL\\MULTIPlY\\THIcK.TxT");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            for (int i = 0; i < 293; ++i)
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
    

                char expected_filecontent[3730] = "";

                strcat(expected_filecontent, "s?\"  After that I saw\nA multitude, in fury burning, slay\nWith stones a stripling youth, and shout amain\n\"Destroy, destroy: \"and him I saw, who bow\'d\nHeavy with death unto the ground, yet made\nHis eyes, unfolded upward, gates to heav\'n,\nPraying forgiveness of th\' Almighty Sire,\nAmidst that cruel conflict, on his foes,\nWith looks, that With compassion to their aim.\n     Soon as my spirit, from her airy flight\nReturning, sought again the things, whose truth\nDepends not on her shaping, I observ\'d\nHow she had rov\'d to no unreal scenes\n     Meanwhile the leader, who might see I mov\'d,\nAs one, who struggles to shake off his sleep,\nExclaim\'d:  \"What ails thee, that thou canst not hold\nThy footing firm, but more than half a league\nHast travel\'d with clos\'d eyes and tott\'ring gait,\nLike to a man by wine or sleep o\'ercharg\'d?\"\n     \"Beloved father!  so thou deign,\" said I,\n\"To listen, I will tell thee what appear\'d\nBefore me, when so fail\'d my sinking steps.\"\n     He thus: \"Not if thy Countenance were mask\'d\nWith hundred vizards, could a thought of thine\nHow small soe\'er, elude me.  What thou saw\'st\nWas shown, that freely thou mightst ope thy heart\nTo the waters of peace, that flow diffus\'d\nFrom their eternal fountain.  I not ask\'d,\nWhat ails thee?  for such cause as he doth, who\nLooks only with that eye which sees no more,\nWhen spiritless the body lies; but ask\'d,\nTo give fresh vigour to thy foot.  Such goads\nThe slow and loit\'ring need; that they be found\nNot wanting, when their hour of watch returns.\"\n     So on we journey\'d through the evening sky\nGazing intent, far onward, as our eyes\nWith level view could stretch against the bright\nVespertine ray: and lo!  by slow degrees\nGath\'ring, a fog made tow\'rds us, dark as night.\nThere was no room for \'scaping; and that mist\nBereft us, both of sight and the pure air.\n\n\n\nCANTO XVI\n\nHell\'s dunnest gloom, or night unlustrous, dark,\nOf every planes \'reft, and pall\'d in clouds,\nDid never spread before the sight a veil\nIn thickness like that fog, nor to the sense\nSo palpable and gross.  Ent\'ring its shade,\nMine eye endured not with unclosed lids;\nWhich marking, near me drew the faithful guide,\nOffering me his shoulder for a stay.\n     As the blind man behind his leader walks,\nLest he should err, or stumble unawares\nOn what might harm him, or perhaps destroy,\nI journey\'d through that bitter air and foul,\nStill list\'ning to my escort\'s warning voice,\n\"Look that from me thou part not.\"  Straight I heard\nVoices, and each one seem\'d to pray for peace,\nAnd for compassion, to the Lamb of God\nThat taketh sins away.  Their prelude still\nWas \"Agnus Dei,\" and through all the choir,\nOne voice, one measure ran, that perfect seem\'d\nThe concord of their song.  \"Are these I hear\nSpirits, O master?\"  I exclaim\'d; and he:\n\"Thou aim\'st aright: these loose the bonds of wrath.\"\n     \"Now who art thou, that through our smoke dost cleave?\nAnd speak\'st of us, as thou thyself e\'en yet\nDividest time by calends?\"  So one voice\nBespake me; whence my master said: \"Reply;\nAnd ask, if upward hence the passage lead.\"\n     \"O being!  who dost make thee pure, to stand\nBeautiful once more in thy Maker\'s sight!\nAlong with me: and thou shalt hear and wonder.\"\nThus I, whereto the spirit answering spake:\n\"Long as \'t is lawful for me, shall my steps\nFollow on thine; and since the cloudy smoke\nForbids the seeing, hearing in its stead\nShall keep us join\'d.\"  I then forthwith began\n\"Yet in my mortal swathing, I ascend\nTo higher regions, and am hither come\nThrough the fearful agony of hell.\nAnd, if so largely God hath doled his grace,\nThat, clean beside all modern precedent,\nHe wills me to behold his kingly state,\nFrom me conceal not who thou wast, ere death\nHad loos\'d thee;");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\MUCHeITh\\StEP\\POSItIOn\\NOiSe");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3729; ++i)
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
    

                char expected_filecontent[152] = "";

                strcat(expected_filecontent, "t.  When we had run\nO\'er all the ladder to its topmost round,\nAs there we stood, on me the Mantuan fix\'d\nHis eyes, and thus he spake:  \"Both fires, my ");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\rUB\\CAmP\\EVeN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 151; ++i)
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
    

                char expected_filecontent[2049] = "";

                strcat(expected_filecontent, " old man.]  As some say, St. John, under his\ncharacter of the author of the Apocalypse.  But in the poem\nattributed to Giacopo, the son of our Poet, which in some MSS,\naccompanies the original of this work, and is descriptive of its\nplan, this old man is said to be Moses.\n\nE\'l vecchio, ch\' era dietro a tutti loro\nFu Moyse.\n\nAnd the old man, who was behind them all,\nWas Moses.\nSee No. 3459 of the Harl.  MSS. in the British Museum.\n\nCANTO XXX\n\nv. 1.  The polar light.]  The seven candlesticks.\n\nv. 12.  Come.]  Song of Solomon, c. iv. 8.\n\nv. 19.  Blessed.]  Matt.  c. xxi. 9.\n\nv. 20.  From full hands.] Virg.  Aen 1. vi. 884.\n\nv. 97.  The old flame.]\nAgnosco veteris vestigia flammae\nVirg.  Aen. I. I. 23.\n\nConosco i segni dell\' antico fuoco.\nGiusto de\' Conti, La Bella Mano.\n\nv. 61.  Nor.]  \"Not all the beauties of the terrestrial Paradise;\nin which I was, were sufficient to allay my grief.\"\n\nv. 85.  But.]  They sang the thirty-first Psalm, to the end of\nthe eighth verse.\n\nv. 87.  The living rafters.]  The leafless woods on the Apennine.\n\nv. 90.  The land whereon no shadow falls.]  \"When the wind blows,\nfrom off Africa, where, at the time of the equinox, bodies being\nunder the equator cast little or no shadow; or, in other words,\nwhen the wind is south.\"\n\nv. 98.  The ice.]  Milton has transferred this conceit, though\nscarcely worth the pains of removing, into one of his Italian\npoems, son.\n\nCANTO XXXI\n\nv. 3.  With lateral edge.]  The words of Beatrice, when not\naddressed directly to himself, but speaking to the angel of hell,\nDante had thought sufficiently harsh.\n\nv. 39.  Counter to the edge.]  \"The weapons of divine justice are\nblunted by the confession and sorrow of the offender.\"\n\nv. 58.  Bird.]  Prov. c. i. 17\n\nv. 69.  From Iarbas\' land.]  The south.\n\nv. 71.  The beard.]  \"I perceived, that when she desired me to\nraise my beard, instead of telling me to lift up my head, a\nsevere reflection was implied on my want of that wisdom which\nshould accompany the age of manhood.\"\n\nv. 98.  Tu asperges me.]  A prayer repeated by");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\THeir\\ToGEThER\\GENErAL\\MULTIPLY\\grEW.TXt");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2048; ++i)
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
    

                char expected_filecontent[2366] = "";

                strcat(expected_filecontent, "now discern\nWhere seem\'d my ken to fail, that the mid orb\nOf the supernal motion (which in terms\nOf art is called the Equator, and remains\nEver between the sun and winter) for the cause\nThou hast assign\'d, from hence toward the north\nDeparts, when those who in the Hebrew land\nInhabit, see it tow\'rds the warmer part.\nBut if it please thee, I would gladly know,\nHow far we have to journey: for the hill\nMounts higher, than this sight of mine can mount.\"\n     He thus to me:  \"Such is this steep ascent,\nThat it is ever difficult at first,\nBut, more a man proceeds, less evil grows.\nWhen pleasant it shall seem to thee, so much\nThat upward going shall be easy to thee.\nAs in a vessel to go down the tide,\nThen of this path thou wilt have reach\'d the end.\nThere hope to rest thee from thy toil.  No more\nI answer, and thus far for certain know.\"\nAs he his words had spoken, near to us\nA voice there sounded:  \"Yet ye first perchance\nMay to repose you by constraint be led.\"\nAt sound thereof each turn\'d, and on the left\nA huge stone we beheld, of which nor I\nNor he before was ware.  Thither we drew,\nfind there were some, who in the shady place\nBehind the rock were standing, as a man\nThru\' idleness might stand.  Among them one,\nWho seem\'d to me much wearied, sat him down,\nAnd with his arms did fold his knees about,\nHolding his face between them downward bent.\n     \"Sweet Sir!\"  I cry\'d, \"behold that man, who shows\nHimself more idle, than if laziness\nWere sister to him.\"  Straight he turn\'d to us,\nAnd, o\'er the thigh lifting his face, observ\'d,\nThen in these accents spake:  \"Up then, proceed\nThou valiant one.\"  Straight who it was I knew;\nNor could the pain I felt (for want of breath\nStill somewhat urg\'d me) hinder my approach.\nAnd when I came to him, he scarce his head\nUplifted, saying \"Well hast thou discern\'d,\nHow from the left the sun his chariot leads.\"\n     His lazy acts and broken words my lips\nTo laughter somewhat mov\'d; when I began:\n\"Belacqua, now for thee I grieve no more.\nBut tell, why thou art seated upright there?\nWaitest thou escort to conduct thee hence?\nOr blame I only shine accustom\'d ways?\"\nThen he:  \"My brother, of what use to mount,\nWhen to my suffering would not let me pass\nThe bird of God, who at the portal sits?\nBehooves so long that heav\'n first bear me round\nWithout its limits, as in life it bore,\nBecause I to the end");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\theiR\\TogeTHEr\\Even\\ARE\\REaD.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2365; ++i)
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
    

                char expected_filecontent[114] = "";

                strcat(expected_filecontent, "wash out mine.\"  A thousand visages\nThen mark\'d I, which the keen and eager cold\nHad shap\'d into a doggish grin; ");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\RUB\\paY\\COLOnY");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 113; ++i)
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
    

                char expected_filecontent[258] = "";

                strcat(expected_filecontent, "en mistaken.  It is in the French spoken in the\nreign of St. Louis,under the title of Tresor, and contains a\nspecies of philosophical course of lectures divided into theory\nand practice, or, as he expresses it, \"un enchaussement des\nchoses divines et humain");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\THeIR\\ToGeTHER\\EVEN\\heaRt");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 257; ++i)
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
    

                char expected_filecontent[232] = "";

                strcat(expected_filecontent, "o,\nin Italian, signifying a pig. The real name of this glutton has\nnot been transmitted to us. He is introduced in Boccaccio\'s\nDecameron, Giorn. ix. Nov. 8.\n\nv. 61.  The divided city.]  The city of Florence, divided into\nthe Bianch");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\SImPLE\\SEGMENT\\JumP\\SIX.tXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 231; ++i)
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
    

                char expected_filecontent[3722] = "";

                strcat(expected_filecontent, "where the rock impends\nDirectly o\'er the centre of the foss.\n     Wisdom Supreme! how wonderful the art,\nWhich thou dost manifest in heaven, in earth,\nAnd in the evil world, how just a meed\nAllotting by thy virtue unto all!\n     I saw the livid stone, throughout the sides\nAnd in its bottom full of apertures,\nAll equal in their width, and circular each,\nNor ample less nor larger they appear\'d\nThan in Saint John\'s fair dome of me belov\'d\nThose fram\'d to hold the pure baptismal streams,\nOne of the which I brake, some few years past,\nTo save a whelming infant; and be this\nA seal to undeceive whoever doubts\nThe motive of my deed.  From out the mouth\nOf every one, emerg\'d a sinner\'s feet\nAnd of the legs high upward as the calf\nThe rest beneath was hid.  On either foot\nThe soles were burning, whence the flexile joints\nGlanc\'d with such violent motion, as had snapt\nAsunder cords or twisted withs.  As flame,\nFeeding on unctuous matter, glides along\nThe surface, scarcely touching where it moves;\nSo here, from heel to point, glided the flames.\n     \"Master! say who is he, than all the rest\nGlancing in fiercer agony, on whom\nA ruddier flame doth prey?\"  I thus inquir\'d.\n     \"If thou be willing,\" he replied, \"that I\nCarry thee down, where least the slope bank falls,\nHe of himself shall tell thee and his wrongs.\"\n     I then:  \"As pleases thee to me is best.\nThou art my lord; and know\'st that ne\'er I quit\nThy will:  what silence hides that knowest thou.\"\nThereat on the fourth pier we came, we turn\'d,\nAnd on our left descended to the depth,\nA narrow strait and perforated close.\nNor from his side my leader set me down,\nTill to his orifice he brought, whose limb\nQuiv\'ring express\'d his pang.  \"Whoe\'er thou art,\nSad spirit! thus revers\'d, and as a stake\nDriv\'n in the soil!\"  I in these words began,\n\"If thou be able, utter forth thy voice.\"\n     There stood I like the friar, that doth shrive\nA wretch for murder doom\'d, who e\'en when fix\'d,\nCalleth him back, whence death awhile delays.\n     He shouted:  \"Ha! already standest there?\nAlready standest there, O Boniface!\nBy many a year the writing play\'d me false.\nSo early dost thou surfeit with the wealth,\nFor which thou fearedst not in guile to take\nThe lovely lady, and then mangle her?\"\n     I felt as those who, piercing not the drift\nOf answer made them, stand as if expos\'d\nIn mockery, nor know what to reply,\nWhen Virgil thus admonish\'d:  \"Tell him quick,\nI am not he, not he, whom thou believ\'st.\"\n     And I, as was enjoin\'d me, straight replied.\n     That heard, the spirit all did wrench his feet,\nAnd sighing next in woeful accent spake:\n\"What then of me requirest?\"  If to know\nSo much imports thee, who I am, that thou\nHast therefore down the bank descended, learn\nThat in the mighty mantle I was rob\'d,\nAnd of a she-bear was indeed the son,\nSo eager to advance my whelps, that there\nMy having in my purse above I stow\'d,\nAnd here myself.  Under my head are dragg\'d\nThe rest, my predecessors in the guilt\nOf simony.  Stretch\'d at their length they lie\nAlong an opening in the rock.  \'Midst them\nI also low shall fall, soon as he comes,\nFor whom I took thee, when so hastily\nI question\'d.  But already longer time\nHath pass\'d, since my souls kindled, and I thus\nUpturn\'d have stood, than is his doom to stand\nPlanted with fiery feet.  For after him,\nOne yet of deeds more ugly shall arrive,\nFrom forth the west, a shepherd without law,\nFated to cover both his form and mine.\nHe a new Jason shall be call\'d, of whom\nIn Maccabees we read; and favour such\nAs to that priest his king indulgent show\'d,\nShall be of France\'s monarch shown to him.\"\n     I know not if I here too far presum\'d,\nBut in this strain I answer\'d:  \"Tell me now,\nWhat trea");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\MUcHEITH\\STEP\\sOLVE\\SpEAK\\bABY.txT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3721; ++i)
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
    

                char expected_filecontent[172] = "";

                strcat(expected_filecontent, "the sky element\nOne ray obstructs not other.  To endure\nTorments of heat and cold extreme, like frames\nThat virtue hath dispos\'d, which how it works\nWills not to us should");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\aLL\\EACH\\SIlVER\\IN\\MANY.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 171; ++i)
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
    

                char expected_filecontent[3675] = "";

                strcat(expected_filecontent, "anders into a desert; but at length proceeds on his way,\nunder the protection of a banner, with which Nature had furnished\nhim, till on the third day he finds himself in a large pleasant\nchampaign, where are assembled many emperors, kings, and sages.\nIt is the habitation of Virtue and her daughters, the four\nCardinal Virtues.  Here Brunetto sees also Courtesy, Bounty,\nLoyalty, and Prowess, and hears the instructions they give to a\nknight, which occupy about a fourth part of the poem.  Leaving\nthis territory, he passes over valleys, mountains, woods,\nforests, and bridges, till he arrives in a beautiful valley\ncovered with flowers on all sides, and the richest in the world;\nbut which was continually  shifting its appearance from a round\nfigure to a square, from obscurity to light, and from\npopulousness to solitude.  This is the region of Pleasure, or\nCupid, who is accompanied by four ladies, Love, Hope, Fear, and\nDesire.  In one part of it he meets with Ovid, and is instructed\nby him how to conquer the passion of love, and to escape from\nthat place.  After his escape he makes his confession to a friar,\nand then returns to the forest of visions:  and ascending a\nmountain, he meets with Ptolemy, a venerable old man.  Here the\nnarrative breaks off. The  poem ends, as it began, with an\naddress to Rustico di Filippo, on whom he lavishes every sort of\npraise.\n\nIt has been observed, that Dante derived the idea of opening his\npoem by describing himself as lost in a wood, from the Tesoretto\nof his master.  I know not whether it has been remarked, that the\ncrime of usury is branded by both these poets as offensive to God\nand Nature:  or that the sin for which Brunetto is condemned by\nhis pupil, is mentioned in the Tesoretto with great horror.\nDante\'s twenty-fifth sonnet is a jocose one, addressed to\nBrunetto.  He died in 1295.\n\nv. 62.  Who in old times came down from Fesole.]  See G. Villani\nHist. l. iv. c. 5. and Macchiavelli Hist. of Flor. b. ii.\n\nv. 89.  With another text.]  He refers to the prediction of\nFarinata, in Canto X.\n\nv. 110.  Priscian.]  There is no reason to believe, as the\ncommentators observe that the grammarian of this name was stained\nwith the vice imputed to him; and we must therefore suppose that\nDante puts the individual for the species, and implies the\nfrequency of the crime among those who abused the opportunities\nwhich the education of youth afforded them, to so abominable a\npurpose.\n\nv. 111.  Francesco.]  Son of Accorso, a Florentine, celebrated\nfor his skill in jurisprudence, and commonly known by the name of\nAccursius.\n\nv. 113.  Him.]  Andrea de\' Mozzi, who, that his scandalous life\nmight be less exposed to observation, was translated either by\nNicholas III, or Boniface VIII from the see of Florence to that\nof Vicenza, through which passes the river Baccchiglione.  At the\nlatter of these places he died.\n\nv. 114.  The servants\' servant.]  Servo de\' servi.  So Ariosto,\nSat. 3.\n               Degli servi\n        Io sia il gran servo.\n\nv. 124.  I commend my Treasure to thee.]  Brunetto\'s great work,\nthe Tresor.\nSieti raccomandato \'l mio Tesoro.\nSo Giusto de\' Conti, in his Bella Mano, Son.  \"Occhi:\"\n        Siavi raccommandato il mio Tesoro.\n\nCANTO XVI\n\nv. 38.  Gualdrada.]  Gualdrada was the daughter of Bellincione\nBerti, of whom mention is made in the Paradise, Canto XV, and\nXVI.  He was of the family of Ravignani, a branch of the Adimari.\n\nThe Emperor Otho IV. being at a festival in Florence, where\nGualdrada was present, was struck with her beauty; and inquiring\nwho she was, was answered by Bellincione, that she was the\ndaughter of one who, if it was his Majesty\'s pleasure, would make\nher admit");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\VIew\\HArD\\RESUlT\\FeLt\\HEAd.TXt");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3674; ++i)
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
    

                char expected_filecontent[360] = "";

                strcat(expected_filecontent, "ch our wills with his\nAre one.  So that as we from step to step\nAre plac\'d throughout this kingdom, pleases all,\nE\'en as our King, who in us plants his will;\nAnd in his will is our tranquillity;\nIt is the mighty ocean, whither tends\nWhatever it creates and nature makes.\"\n     Then saw I clearly how each spot in heav\'n\nIs Paradise, though with like gracious ");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\RUB\\DIFfER\\INSTANT\\WIN\\NOTE.Tx");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 359; ++i)
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
    

                char expected_filecontent[2469] = "";

                strcat(expected_filecontent, "o speak no more, and now pass\'d on with leave\nFrom the mild poet gain\'d, when following came\nAnother, from whose top a sound confus\'d,\nForth issuing, drew our eyes that way to look.\n     As the Sicilian bull, that rightfully\nHis cries first echoed, who had shap\'d its mould,\nDid so rebellow, with the voice of him\nTormented, that the brazen monster seem\'d\nPierc\'d through with pain; thus while no way they found\nNor avenue immediate through the flame,\nInto its language turn\'d the dismal words:\nBut soon as they had won their passage forth,\nUp from the point, which vibrating obey\'d\nTheir motion at the tongue, these sounds we heard:\n\"O thou!  to whom I now direct my voice!\nThat lately didst exclaim in Lombard phrase,\n     Depart thou, I solicit thee no more,\'\nThough somewhat tardy I perchance arrive\nLet it not irk thee here to pause awhile,\nAnd with me parley:  lo! it irks not me\nAnd yet I burn.  If but e\'en now thou fall\ninto this blind world, from that pleasant land\nOf Latium, whence I draw my sum of guilt,\nTell me if those, who in Romagna dwell,\nHave peace or war.  For of the mountains there\nWas I, betwixt Urbino and the height,\nWhence Tyber first unlocks his mighty flood.\"\n     Leaning I listen\'d yet with heedful ear,\nWhen, as he touch\'d my side, the leader thus:\n\"Speak thou: he is a Latian.\"  My reply\nWas ready, and I spake without delay:\n     \"O spirit!  who art hidden here below!\nNever was thy Romagna without war\nIn her proud tyrants\' bosoms, nor is now:\nBut open war there left I none.  The state,\nRavenna hath maintain\'d this many a year,\nIs steadfast.  There Polenta\'s eagle broods,\nAnd in his broad circumference of plume\nO\'ershadows Cervia. The green talons grasp\nThe land, that stood erewhile the proof so long,\nAnd pil\'d in bloody heap the host of France.\n     \"The\' old mastiff of Verruchio and the young,\nThat tore Montagna in their wrath, still make,\nWhere they are wont, an augre of their fangs.\n     \"Lamone\'s city and Santerno\'s range\nUnder the lion of the snowy lair.\nInconstant partisan! that changeth sides,\nOr ever summer yields to winter\'s frost.\nAnd she, whose flank is wash\'d of Savio\'s wave,\nAs \'twixt the level and the steep she lies,\nLives so \'twixt tyrant power and liberty.\n     \"Now tell us, I entreat thee, who art thou?\nBe not more hard than others.  In the world,\nSo may thy name still rear its forehead high.\"\n     Then roar\'d awhile the fire, its sharpen\'d point\nOn either side wav\'d, and thus breath\'d at last:\n\"");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\viEW\\SEED\\GAVE\\iN\\A.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2468; ++i)
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
    

                char expected_filecontent[99] = "";

                strcat(expected_filecontent, "e world\'s lowest gap unto this height.\nSuppliant to thee he kneels, imploring grace\nFor virtue, ye");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\RUB\\FOrWARD\\uP");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 98; ++i)
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
    

                char expected_filecontent[238] = "";

                strcat(expected_filecontent, "b\'d he cried:  \"Mark now, my son,\nFrom Beatrice thou art by this wall\nDivided.\"  As at Thisbe\'s name the eye\nOf Pyramus was open\'d (when life ebb\'d\nFast from his veins), and took one parting glance,\nWhile vermeil dyed the mulberry; thus ");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\VIEW\\SEEd\\lEAST\\DROP.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 237; ++i)
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
    

                char expected_filecontent[274] = "";

                strcat(expected_filecontent, ",\" with that he cried,\n\"And Calcabrina, and Cagnazzo thou!\nThe troop of ten let Barbariccia lead.\nWith Libicocco Draghinazzo haste,\nFang\'d Ciriatto, Grafflacane fierce,\nAnd Farfarello, and mad Rubicant.\nSearch ye around the bubbling tar.  For these,\nIn safety lead them, wh");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ThEIR\\TogETHER\\oFF\\FiVE\\SuPplY.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 273; ++i)
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
    

                char expected_filecontent[250] = "";

                strcat(expected_filecontent, "nscious to the pang;\nIts native shores Antandros, and the streams\nOf Simois revisited, and there\nWhere Hector lies; then ill for Ptolemy\nHis pennons shook again; lightning thence fell\nOn Juba; and the next upon your west,\nAt sound of the Pompeian tr");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\RuB\\SAY.TXt");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 249; ++i)
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
    

                char expected_filecontent[394] = "";

                strcat(expected_filecontent, "f aught alarm them, suddenly desert\nTheir meal, assail\'d by more important care;\nSo I that new-come troop beheld, the song\nDeserting, hasten to the mountain\'s side,\nAs one who goes yet where he tends knows not.\n     Nor with less hurried step did we depart.\n\n\n\nCANTO III\n\nThem sudden flight had scatter\'d over the plain,\nTurn\'d tow\'rds the mountain, whither reason\'s voice\nDrives us; I to my f");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\rUb\\dAY");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 393; ++i)
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
    

                char expected_filecontent[257] = "";

                strcat(expected_filecontent, " since hath quench\'d the other; and the sword\nIs grafted on the crook; and so conjoin\'d\nEach must perforce decline to worse, unaw\'d\nBy fear of other.  If thou doubt me, mark\nThe blade: each herb is judg\'d of by its seed.\nThat land, through which Adice and ");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\RUB\\caPiTAL.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 256; ++i)
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
    

                char expected_filecontent[437] = "";

                strcat(expected_filecontent, "ght\'ning beam!\nO glory of our kind!  beseech thee say\nWhat water this, which from one source deriv\'d\nItself removes to distance from itself?\"\n     To such entreaty answer thus was made:\n\"Entreat Matilda, that she teach thee this.\"\n     And here, as one, who clears himself of blame\nImputed, the fair dame return\'d:  \"Of me\nHe this and more hath learnt; and I am safe\nThat Lethe\'s water hath not hid it from him.\"\n     And Beatrice:  \"So");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\RUB\\LAst");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 436; ++i)
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
    

                char expected_filecontent[76] = "";

                strcat(expected_filecontent, "ten demons on our way we went;\nAh fearful company!  but in the church\nWith ");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\RUB\\SUbsTANc.bIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 75; ++i)
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
    

                char expected_filecontent[2561] = "";

                strcat(expected_filecontent, "well translated by\nChaucer--\n        But right as floures through the cold of night\n        Iclosed, stoupen in her stalkes lowe,\n        Redressen hem agen the sunne bright,\n        And speden in her kinde course by rowe, &c.\n               Troilus and Creseide, b.ii.\nIt has been imitated by many others, among whom see Berni,\nOrl.Inn. Iib. 1. c. xii. st. 86.  Marino, Adone, c. xvii. st. 63.\nand Sor. \"Donna vestita di nero.\" and Spenser\'s Faery Queen, b.4.\nc. xii. st. 34. and b. 6 c. ii. st. 35.\n\nCANTO III\n\nv. 5.          Power divine\n        Supremest wisdom, and primeval love.]  The three\npersons of the blessed Trinity.\nv. 9.  all hope abandoned.] Lasciate ogni speranza voi\nch\'entrate.\nSo Berni, Orl. Inn. lib. i. c. 8. st. 53.\n        Lascia pur della vita ogni speranza.\n\nv. 29.  Like to the sand.]\n               Unnumber\'d as the sands\n        Of Barca or Cyrene\'s torrid soil\n        Levied to side with warring winds, and poise\n        Their lighter wings.\n               Milton, P. L. ii. 908.\n\nv. 40.  Lest th\' accursed tribe.]  Lest the rebellious angels\nshould exult at seeing those who were neutral and therefore less\nguilty, condemned to the same punishment with themselves.\n\nv. 50.  A flag.]\n               All the grisly legions that troop\n        Under the sooty flag of Acheron\n               Milton. Comus.\n\nv. 56.         Who to base fear\n        Yielding, abjur\'d his high estate.] This is\ncommonly understood of Celestine the Fifth, who abdicated the\npapal power in 1294. Venturi mentions a work written by\nInnocenzio Barcellini, of the Celestine order, and printed in\nMilan in 1701, In which an attempt is made to put a different\ninterpretation on this passage.\n\nv. 70.  through the blear light.]\n        Lo fioco lume\nSo Filicaja, canz. vi. st. 12.\n        Qual fioco lume.\n\nv. 77.  An old man.]\n        Portitor has horrendus aquas et flumina servat\n        Terribili squalore Charon, cui plurima mento\n        Canities inculta jacet; stant lumina flamma.\n               Virg. 7.  Aen. Iib. vi. 2.\n\nv. 82.  In fierce heat and in ice.]\n               The delighted spirit\n        To bathe in fiery floods or to reside\n        In thrilling regions of thick ribbed ice.\n               Shakesp. Measure for Measure, a. iii.s.1.\nCompare Milton, P. L. b. ii. 600.\n\nv. 92.  The livid lake.] Vada livida.\n               Virg. Aen. Iib. vi. 320\n               Totius ut Lacus putidaeque paludis\n        Lividissima, maximeque est profunda vorago.\n               Catullus. xviii. 10.\n\nv. 102.  With eyes of burning coal.]\n        His lo");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\rUb\\VALLEY.BIn");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2560; ++i)
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
    

                char expected_filecontent[3073] = "";

                strcat(expected_filecontent, "nd dense, or when the shades of night\nFall on our hemisphere, seems view\'d from far\nA windmill, which the blast stirs briskly round,\nSuch was the fabric then methought I saw,\n     To shield me from the wind, forthwith I drew\nBehind my guide:  no covert else was there.\n     Now came I (and with fear I bid my strain\nRecord the marvel) where the souls were all\nWhelm\'d underneath, transparent, as through glass\nPellucid the frail stem.  Some prone were laid,\nOthers stood upright, this upon the soles,\nThat on his head, a third with face to feet\nArch\'d like a bow.  When to the point we came,\nWhereat my guide was pleas\'d that I should see\nThe creature eminent in beauty once,\nHe from before me stepp\'d and made me pause.\n     \"Lo!\"  he exclaim\'d, \"lo Dis! and lo the place,\nWhere thou hast need to arm thy heart with strength.\"\n     How frozen and how faint I then became,\nAsk me not, reader!  for I write it not,\nSince words would fail to tell thee of my state.\nI was not dead nor living.  Think thyself\nIf quick conception work in thee at all,\nHow I did feel.  That emperor, who sways\nThe realm of sorrow, at mid breast from th\' ice\nStood forth; and I in stature am more like\nA giant, than the giants are in his arms.\nMark now how great that whole must be, which suits\nWith such a part.  If he were beautiful\nAs he is hideous now, and yet did dare\nTo scowl upon his Maker, well from him\nMay all our mis\'ry flow.  Oh what a sight!\nHow passing strange it seem\'d, when I did spy\nUpon his head three faces: one in front\nOf hue vermilion, th\' other two with this\nMidway each shoulder join\'d and at the crest;\nThe right \'twixt wan and yellow seem\'d:  the left\nTo look on, such as come from whence old Nile\nStoops to the lowlands.  Under each shot forth\nTwo mighty wings, enormous as became\nA bird so vast.  Sails never such I saw\nOutstretch\'d on the wide sea.  No plumes had they,\nBut were in texture like a bat, and these\nHe flapp\'d i\' th\' air, that from him issued still\nThree winds, wherewith Cocytus to its depth\nWas frozen.  At six eyes he wept:  the tears\nAdown three chins distill\'d with bloody foam.\nAt every mouth his teeth a sinner champ\'d\nBruis\'d as with pond\'rous engine, so that three\nWere in this guise tormented.  But far more\nThan from that gnawing, was the foremost pang\'d\nBy the fierce rending, whence ofttimes the back\nWas stript of all its skin.  \"That upper spirit,\nWho hath worse punishment,\" so spake my guide,\n\"Is Judas, he that hath his head within\nAnd plies the feet without.  Of th\' other two,\nWhose heads are under, from the murky jaw\nWho hangs, is Brutus:  lo!  how he doth writhe\nAnd speaks not!  Th\' other Cassius, that appears\nSo large of limb.  But night now re-ascends,\nAnd it is time for parting.  All is seen.\"\n     I clipp\'d him round the neck, for so he bade;\nAnd noting time and place, he, when the wings\nEnough were op\'d, caught fast the shaggy sides,\nAnd down from pile to pile descending stepp\'d\nBetween the thick fell and the jagged ice.\n     Soon as he reach\'d the point, whereat the thigh\nUpon the swelling of the haunches turns,\nM");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\RUB\\hOT.tX");
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
    

                char expected_filecontent[139] = "";

                strcat(expected_filecontent, " Paradise, Canto Vl. 135.  Dante therefore considers Peter as\nthe most illustrious of the three monarchs.\n\nv. 129.  Harry of England.]  He");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\rUB\\CLeAr");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 138; ++i)
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
    

                char expected_filecontent[2730] = "";

                strcat(expected_filecontent, "\'Father, we should grieve\nFar less, if thou wouldst eat of us: thou gav\'st\nThese weeds of miserable flesh we wear,\nAnd do thou strip them off from us again.\'\nThen, not to make them sadder, I kept down\nMy spirit in stillness.  That day and the next\nWe all were silent.  Ah, obdurate earth!\nWhy open\'dst not upon us?  When we came\nTo the fourth day, then Geddo at my feet\nOutstretch\'d did fling him, crying, \'Hast no help\nFor me, my father!\'  \"There he died, and e\'en\nPlainly as thou seest me, saw I the three\nFall one by one \'twixt the fifth day and sixth:\nWhence I betook me now grown blind to grope\nOver them all, and for three days aloud\nCall\'d on them who were dead.  Then fasting got\nThe mastery of grief.\"  Thus having spoke,\nOnce more upon the wretched skull his teeth\nHe fasten\'d, like a mastiff\'s \'gainst the bone\nFirm and unyielding.  Oh thou Pisa!  shame\nOf all the people, who their dwelling make\nIn that fair region, where th\' Italian voice\nIs heard, since that thy neighbours are so slack\nTo punish, from their deep foundations rise\nCapraia and Gorgona, and dam up\nThe mouth of Arno, that each soul in thee\nMay perish in the waters!  What if fame\nReported that thy castles were betray\'d\nBy Ugolino, yet no right hadst thou\nTo stretch his children on the rack.  For them,\nBrigata, Ugaccione, and the pair\nOf gentle ones, of whom my song hath told,\nTheir tender years, thou modern Thebes!  did make\nUncapable of guilt.  Onward we pass\'d,\nWhere others skarf\'d in rugged folds of ice\nNot on their feet were turn\'d, but each revers\'d\n     There very weeping suffers not to weep;\nFor at their eyes grief seeking passage finds\nImpediment, and rolling inward turns\nFor increase of sharp anguish:  the first tears\nHang cluster\'d, and like crystal vizors show,\nUnder the socket brimming all the cup.\n     Now though the cold had from my face dislodg\'d\nEach feeling, as \'t were callous, yet me seem\'d\nSome breath of wind I felt.  \"Whence cometh this,\"\nSaid I, \"my master?  Is not here below\nAll vapour quench\'d?\"--\"\'Thou shalt be speedily,\"\nHe answer\'d, \"where thine eye shall tell thee whence\nThe cause descrying of this airy shower.\"\n     Then cried out one in the chill crust who mourn\'d:\n\"O souls so cruel!  that the farthest post\nHath been assign\'d you, from this face remove\nThe harden\'d veil, that I may vent the grief\nImpregnate at my heart, some little space\nEre it congeal again!\"  I thus replied:\n\"Say who thou wast, if thou wouldst have mine aid;\nAnd if I extricate thee not, far down\nAs to the lowest ice may I descend!\"\n     \"The friar Alberigo,\" answered he,\n\"Am I, who from the evil garden pluck\'d\nIts fruitage, and am here repaid, the date\nMore luscious for my fig.\"--\"Hah!\"  I exclaim\'d,\n\"Art thou too dead!\"-");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\RUB\\FoUND");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2729; ++i)
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
    

                char expected_filecontent[3024] = "";

                strcat(expected_filecontent, " comfort drew me on to climb,\nAnd climbing wind along this mountain-steep,\nWhich rectifies in you whate\'er the world\nMade crooked and deprav\'d I have his word,\nThat he will bear me company as far\nAs till I come where Beatrice dwells:\nBut there must leave me.  Virgil is that spirit,\nWho thus hath promis\'d,\"  and I pointed to him;\n\"The other is that shade, for whom so late\nYour realm, as he arose, exulting shook\nThrough every pendent cliff and rocky bound.\"\n\n\n\nCANTO XXIV\n\nOur journey was not slacken\'d by our talk,\nNor yet our talk by journeying.  Still we spake,\nAnd urg\'d our travel stoutly, like a ship\nWhen the wind sits astern.  The shadowy forms,\nThat seem\'d things dead and dead again, drew in\nAt their deep-delved orbs rare wonder of me,\nPerceiving I had life; and I my words\nContinued, and thus spake; \"He journeys up\nPerhaps more tardily then else he would,\nFor others\' sake.  But tell me, if thou know\'st,\nWhere is Piccarda?  Tell me, if I see\nAny of mark, among this multitude,\nWho eye me thus.\"--\"My sister (she for whom,\n\'Twixt beautiful and good I cannot say\nWhich name was fitter ) wears e\'en now her crown,\nAnd triumphs in Olympus.\"  Saying this,\nHe added: \"Since spare diet hath so worn\nOur semblance out, \'t is lawful here to name\nEach one .   This,\" and his finger then he rais\'d,\n\"Is Buonaggiuna,--Buonaggiuna, he\nOf Lucca: and that face beyond him, pierc\'d\nUnto a leaner fineness than the rest,\nHad keeping of the church: he was of Tours,\nAnd purges by wan abstinence away\nBolsena\'s eels and cups of muscadel.\"\n     He show\'d me many others, one by one,\nAnd all, as they were nam\'d, seem\'d well content;\nFor no dark gesture I discern\'d in any.\nI saw through hunger Ubaldino grind\nHis teeth on emptiness; and Boniface,\nThat wav\'d the crozier o\'er a num\'rous flock.\nI saw the Marquis, who tad time erewhile\nTo swill at Forli with less drought, yet so\nWas one ne\'er sated.  I howe\'er, like him,\nThat gazing \'midst a crowd, singles out one,\nSo singled him of Lucca; for methought\nWas none amongst them took such note of me.\nSomewhat I heard him whisper of Gentucca:\nThe sound was indistinct, and murmur\'d there,\nWhere justice, that so strips them, fix\'d her sting.\n     \"Spirit!\" said I, \"it seems as thou wouldst fain\nSpeak with me.  Let me hear thee.  Mutual wish\nTo converse prompts, which let us both indulge.\"\n     He, answ\'ring, straight began: \"Woman is born,\nWhose brow no wimple shades yet, that shall make\nMy city please thee, blame it as they may.\nGo then with this forewarning.  If aught false\nMy whisper too implied, th\' event shall tell\nBut say, if of a  truth I see the man\nOf that new lay th\' inventor, which begins\nWith \'Ladies, ye that con the lore of love\'.\"\n     To whom I thus:  \"Count of me but as one\nWho am the scribe of love; that, when he breathes,\nTake up my pen, and, as he dictates, write.\"\n     \"Brother!\" said he, \"the hind\'rance which once held\nThe notary with Guittone and myself,\nShort of that new and sweeter style I hear,\nIs now disclos\'d.  I see how ye your plumes\n");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ruB\\QUESTION.Bin");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3023; ++i)
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
    

                char expected_filecontent[2887] = "";

                strcat(expected_filecontent, "e green leaf mine eyes were fix\'d, like his\nWho throws away his days in idle chase\nOf the diminutive, when thus I heard\nThe more than father warn me: \"Son!  our time\nAsks thriftier using.  Linger not: away.\"\n     Thereat my face and steps at once I turn\'d\nToward the sages, by whose converse cheer\'d\nI journey\'d on, and felt no toil: and lo!\nA sound of weeping and a song: \"My lips,\nO Lord!\" and these so mingled, it gave birth\nTo pleasure and to pain.  \"O Sire, belov\'d!\nSay what is this I hear?\"  Thus I inquir\'d.\n     \"Spirits,\" said he, \"who as they go, perchance,\nTheir debt of duty pay.\"  As on their road\nThe thoughtful pilgrims, overtaking some\nNot known unto them, turn to them, and look,\nBut stay not; thus, approaching from behind\nWith speedier motion, eyed us, as they pass\'d,\nA crowd of spirits, silent and devout.\nThe eyes of each were dark and hollow: pale\nTheir visage, and so lean withal, the bones\nStood staring thro\' the skin.  I do not think\nThus dry and meagre Erisicthon show\'d,\nWhen pinc\'ed by sharp-set famine to the quick.\n     \"Lo!\" to myself I mus\'d, \"the race, who lost\nJerusalem, when Mary with dire beak\nPrey\'d on her child.\"  The sockets seem\'d as rings,\nFrom which the gems were drops.  Who reads the name\nOf man upon his forehead, there the M\nHad trac\'d most plainly.  Who would deem, that scent\nOf water and an apple, could have prov\'d\nPowerful to generate such pining want,\nNot knowing how it wrought?  While now I stood\nWond\'ring what thus could waste them (for the cause\nOf their gaunt hollowness and scaly rind\nAppear\'d not) lo!  a spirit turn\'d his eyes\nIn their deep-sunken cell, and fasten\'d then\nOn me, then cried with vehemence aloud:\n\"What grace is this vouchsaf\'d me?\"  By his looks\nI ne\'er had recogniz\'d him: but the voice\nBrought to my knowledge what his cheer conceal\'d.\nRemembrance of his alter\'d lineaments\nWas kindled from that spark; and I agniz\'d\nThe visage of Forese.  \"Ah! respect\nThis wan and leprous wither\'d skin,\" thus he\nSuppliant implor\'d, \"this macerated flesh.\nSpeak to me truly of thyself.  And who\nAre those twain spirits, that escort thee there?\nBe it not said thou Scorn\'st to talk with me.\"\n     \"That face of thine,\" I answer\'d him, \"which dead\nI once bewail\'d, disposes me not less\nFor weeping, when I see It thus transform\'d.\nSay then, by Heav\'n, what blasts ye thus?  The whilst\nI wonder, ask not Speech from me:  unapt\nIs he to speak, whom other will employs.\n     He thus:  \"The water and tee plant we pass\'d,\nVirtue possesses, by th\' eternal will\nInfus\'d, the which so pines me.  Every spirit,\nWhose song bewails his gluttony indulg\'d\nToo grossly, here in hunger and in thirst\nIs purified.  The odour, which the fruit,\nAnd spray, that showers upon the verdure, breathe,\nInflames us with desire to feed and drink.\nNor once alone encompassing our route\nWe come to add fresh fuel to the pain:\nPain, said I?  solac");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\rUb\\hoT.TxT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2886; ++i)
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
    

                char expected_filecontent[2561] = "";

                strcat(expected_filecontent, " an holocaust I made\nTo God, befitting the new grace vouchsaf\'d.\nAnd from my bosom had not yet upsteam\'d\nThe fuming of that incense, when I knew\nThe rite accepted.  With such mighty sheen\nAnd mantling crimson, in two listed rays\nThe splendours shot before me, that I cried,\n\"God of Sabaoth!  that does prank them thus!\"\n     As leads the galaxy from pole to pole,\nDistinguish\'d into greater lights and less,\nIts pathway, which the wisest fail to spell;\nSo thickly studded, in the depth of Mars,\nThose rays describ\'d the venerable sign,\nThat quadrants in the round conjoining frame.\nHere memory mocks the toil of genius.  Christ\nBeam\'d on that cross; and pattern fails me now.\nBut whoso takes his cross, and follows Christ\nWill pardon me for that I leave untold,\nWhen in the flecker\'d dawning he shall spy\nThe glitterance of Christ.  From horn to horn,\nAnd \'tween the summit and the base did move\nLights, scintillating, as they met and pass\'d.\nThus oft are seen, with ever-changeful glance,\nStraight or athwart, now rapid and now slow,\nThe atomies of bodies, long or short,\nTo move along the sunbeam, whose slant line\nCheckers the shadow, interpos\'d by art\nAgainst the noontide heat.  And as the chime\nOf minstrel music, dulcimer, and help\nWith many strings, a pleasant dining makes\nTo him, who heareth not distinct the note;\nSo from the lights, which there appear\'d to me,\nGather\'d along the cross a melody,\nThat, indistinctly heard, with ravishment\nPossess\'d me.  Yet I mark\'d it was a hymn\nOf lofty praises; for there came to me\n\"Arise and conquer,\" as to one who hears\nAnd comprehends not.  Me such ecstasy\nO\'ercame, that never till that hour was thing\nThat held me in so sweet imprisonment.\n     Perhaps my saying over bold appears,\nAccounting less the pleasure of those eyes,\nWhereon to look fulfilleth all desire.\nBut he, who is aware those living seals\nOf every beauty work with quicker force,\nThe higher they are ris\'n; and that there\nI had not turn\'d me to them; he may well\nExcuse me that, whereof in my excuse\nI do accuse me, and may own my truth;\nThat holy pleasure here not yet reveal\'d,\nWhich grows in transport as we mount aloof.\n\n\n\nCANTO XV\n\nTrue love, that ever shows itself as clear\nIn kindness, as loose appetite in wrong,\nSilenced that lyre harmonious, and still\'d\nThe sacred chords, that are by heav\'n\'s right hand\nUnwound and tighten\'d, flow to righteous prayers\nShould they not hearken, who, to give me will\nFor praying, in accordance thus were mute?\nHe hath in sooth good cause for endless grief,\nWho, for the love of thing that lasteth");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\RUB\\EVENING.tX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2560; ++i)
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
    

                char expected_filecontent[417] = "";

                strcat(expected_filecontent, " his arms my neck\nEncircling, kiss\'d my cheek, and spake: \"O soul\nJustly disdainful!  blest was she in whom\nThou was conceiv\'d!  He in the world was one\nFor arrogance noted; to his memory\nNo virtue lends its lustre; even so\nHere is his shadow furious.  There above\nHow many now hold themselves mighty kings\nWho here like swine shall wallow in the mire,\nLeaving behind them horrible dispraise!\"\n     I then: \"Master! ");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\RUB\\FAsT.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 416; ++i)
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
    

                char expected_filecontent[3073] = "";

                strcat(expected_filecontent, "heeds not\nThe burning, but lies writhen in proud scorn,\nAs by the sultry tempest immatur\'d?\"\n     Straight he himself, who was aware I ask\'d\nMy guide of him, exclaim\'d:  \"Such as I was\nWhen living, dead such now I am.  If Jove\nWeary his workman out, from whom in ire\nHe snatch\'d the lightnings, that at my last day\nTransfix\'d me, if the rest be weary out\nAt their black smithy labouring by turns\nIn Mongibello, while he cries aloud;\n\"Help, help, good Mulciber!\" as erst he cried\nIn the Phlegraean warfare, and the bolts\nLaunch he full aim\'d at me with all his might,\nHe never should enjoy a sweet revenge.\"\n     Then thus my guide, in accent higher rais\'d\nThan I before had heard him:  \"Capaneus!\nThou art more punish\'d, in that this thy pride\nLives yet unquench\'d:  no torrent, save thy rage,\nWere to thy fury pain proportion\'d full.\"\n     Next turning round to me with milder lip\nHe spake:  \"This of the seven kings was one,\nWho girt the Theban walls with siege, and held,\nAs still he seems to hold, God in disdain,\nAnd sets his high omnipotence at nought.\nBut, as I told him, his despiteful mood\nIs ornament well suits the breast that wears it.\nFollow me now; and look thou set not yet\nThy foot in the hot sand, but to the wood\nKeep ever close.\"  Silently on we pass\'d\nTo where there gushes from the forest\'s bound\nA little brook, whose crimson\'d wave yet lifts\nMy hair with horror.  As the rill, that runs\nFrom Bulicame, to be portion\'d out\nAmong the sinful women; so ran this\nDown through the sand, its bottom and each bank\nStone-built, and either margin at its side,\nWhereon I straight perceiv\'d our passage lay.\n     \"Of all that I have shown thee, since that gate\nWe enter\'d first, whose threshold is to none\nDenied, nought else so worthy of regard,\nAs is this river, has thine eye discern\'d,\nO\'er which the flaming volley all is quench\'d.\"\n     So spake my guide; and I him thence besought,\nThat having giv\'n me appetite to know,\nThe food he too would give, that hunger crav\'d.\n     \"In midst of ocean,\" forthwith he began,\n\"A desolate country lies, which Crete is nam\'d,\nUnder whose monarch in old times the world\nLiv\'d pure and chaste.  A mountain rises there,\nCall\'d Ida, joyous once with leaves and streams,\nDeserted now like a forbidden thing.\nIt was the spot which Rhea, Saturn\'s spouse,\nChose for the secret cradle of her son;\nAnd better to conceal him, drown\'d in shouts\nHis infant cries.  Within the mount, upright\nAn ancient form there stands and huge, that turns\nHis shoulders towards Damiata, and at Rome\nAs in his mirror looks.  Of finest gold\nHis head is shap\'d, pure silver are the breast\nAnd arms; thence to the middle is of brass.\nAnd downward all beneath well-temper\'d steel,\nSave the right foot of potter\'s clay, on which\nThan on the other more erect he stands,\nEach part except the gold, is rent throughout;\nAnd from the fissure tears distil, which join\'d\nPenetrate to that cave.  They in their course\nThus far precipitated down the rock\nForm Acheron, and Styx, and Phlegethon;\nThen by this straiten\'d channel passing hence\nBeneath, e\'en to th");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\RUB\\HOMe");
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
    

                char expected_filecontent[2561] = "";

                strcat(expected_filecontent, "\"See her,\" she replied,\n\"Beneath the fresh leaf seated on its root.\nBehold th\' associate choir that circles her.\nThe others, with a melody more sweet\nAnd more profound, journeying to higher realms,\nUpon the Gryphon tend.\"  If there her words\nWere clos\'d, I know not; but mine eyes had now\nTa\'en view of her, by whom all other thoughts\nWere barr\'d admittance.  On the very ground\nAlone she sat, as she had there been left\nA guard upon the wain, which I beheld\nBound to the twyform beast.  The seven nymphs\nDid make themselves a cloister round about her,\nAnd in their hands upheld those lights secure\nFrom blast septentrion and the gusty south.\n     \"A little while thou shalt be forester here:\nAnd citizen shalt be forever with me,\nOf that true Rome, wherein Christ dwells a Roman\nTo profit the misguided world, keep now\nThine eyes upon the car; and what thou seest,\nTake heed thou write, returning to that place.\"\n     Thus Beatrice: at whose feet inclin\'d\nDevout, at her behest, my thought and eyes,\nI, as she bade, directed.  Never fire,\nWith so swift motion, forth a stormy cloud\nLeap\'d downward from the welkin\'s farthest bound,\nAs I beheld the bird of Jove descending\nPounce on the tree, and, as he rush\'d, the rind,\nDisparting crush beneath him, buds much more\nAnd leaflets.  On the car with all his might\nHe struck, whence, staggering like a ship, it reel\'d,\nAt random driv\'n, to starboard now, o\'ercome,\nAnd now to larboard, by the vaulting waves.\n     Next springing up into the chariot\'s womb\nA fox I saw, with hunger seeming pin\'d\nOf all good food.  But, for his ugly sins\nThe saintly maid rebuking him, away\nScamp\'ring he turn\'d, fast as his hide-bound corpse\nWould bear him.  Next, from whence before he came,\nI saw the eagle dart into the hull\nO\' th\' car, and leave it with his feathers lin\'d;\nAnd then a voice, like that which issues forth\nFrom heart with sorrow riv\'d, did issue forth\nFrom heav\'n, and, \"O poor bark of mine!\" it cried,\n\"How badly art thou freighted!\"  Then, it seem\'d,\nThat the earth open\'d between either wheel,\nAnd I beheld a dragon issue thence,\nThat through the chariot fix\'d his forked train;\nAnd like a wasp that draggeth back the sting,\nSo drawing forth his baleful train, he dragg\'d\nPart of the bottom forth, and went his way\nExulting.  What remain\'d, as lively turf\nWith green herb, so did clothe itself with plumes,\nWhich haply had with purpose chaste and kind\nBeen offer\'d; and therewith were cloth\'d the wheels,\nBoth one and other, and the beam, so quickly\nA sigh were not breath\'d sooner.  Thus transform\'d,\nThe ho");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\RUB\\WALK.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2560; ++i)
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
    

                char expected_filecontent[3690] = "";

                strcat(expected_filecontent, "are bounded by\nthe English sea, and the mountains of Arragon, and on the\nsouth by the people of Provence and the declivity of the\nApennine.\" Ibid.  c. x. \"Each of these three,\" he observes, \"has\nits own claims to distinction The excellency of the French\nlanguage consists in its being best adapted, on account of its\nfacility and agreeableness, to prose narration, (quicquid\nredactum, sive inventum est ad vulgare prosaicum suum\nest); and he instances the books compiled on the gests of the\nTrojans and Romans and the delightful adventures of King Arthur,\nwith many other histories and works of instruction. The Spanish\n(or Provencal) may boast of its having produced such\nas first cultivated in this as in a more perfect and sweet\nlanguage, the vernacular poetry: among whom are Pierre\nd\'Auvergne, and others more ancient.\nThe privileges of the Latin, or Italian are two:  first that it\nmay reckon for its own those writers who have adopted a more\nsweet and subtle style of poetry, in the number of whom are Cino,\nda Pistoia and his friend, and the next, that its writers seem to\nadhere to, certain general rules of grammar, and in so doing give\nit, in the opinion of the intelligent, a very weighty pretension\nto preference.\"\n\nCANTO XXVII\n\nv. 1.  The sun.]  At Jerusalem it was dawn, in Spain midnight,\nand in India noonday, while it was sunset in Purgatory\n\nv. 10.  Blessed.]  Matt. c. v. 8.\n\nv. 57.  Come.]  Matt.  c. xxv. 34.\n\nv. 102.  I am Leah.]  By Leah is understood the active life, as\nRachel figures the contemplative. The divinity is the mirror in\nwhich the latter looks. Michel Angelo has made these allegorical\npersonages the subject of two statues on the monument of Julius\nII. in the church of S. Pietro in Vincolo. See Mr. Duppa\'s Life\nof Michel Angelo, Sculpture viii. And x. and p 247.\n\nv. 135.  Those bright eyes.]  The eyes of Beatrice.\n\nCANTO XXVIII\n\nv. 11.  To that part.]  The west.\n\nv. 14.  The feather\'d quiristers] Imitated by Boccaccio,\nFiammetta, 1. iv. \"Odi i queruli uccelli,\" &c. --\"Hear the\nquerulous birds plaining with sweet songs, and the boughs\ntrembling, and, moved by a gentle wind, as it were keeping tenor\nto their notes.\"\n\nv. 7.  A pleasant air.]  Compare Ariosto, O. F. c. xxxiv. st. 50.\n\nv. Chiassi.]  This is the wood where the scene of Boccaccio\'s\nsublimest story is laid. See Dec.  g. 5. n. 8. and Dryden\'s\nTheodore and Honoria Our Poet perhaps wandered in it daring his\nabode with Guido Novello da Polenta.\n\nv. 41.  A lady.]  Most of the commentators suppose, that by this\nlady, who in the last Canto is called Matilda, is to be\nunderstood the Countess Matilda, who endowed the holy see with\nthe estates called the Patrimony of St. Peter,\nand died in 1115. See G. Villani, 1. iv. e. 20 But it seems more\nprobable that she should be intended for an allegorical\npersonage.\n\nv. 80.  Thou, Lord  hast made me glad.]  Psalm xcii. 4\n\nv. 146.  On the Parnassian mountain.]\nIn bicipiti somniasse Parnasso.\nPersius  Prol.\n\nCANTO XXIX\n\nv. 76.  Listed colours.]\nDi sette liste tutte in quel colori, &c.\n--a bow\nConspicuous with three listed colours gay.\nMilton, P. L. b. xi.  865.\n\nv. 79.  Ten paces.]  For an explanation of the allegorical\nmeaning of this mysterious procession, Venturi refers those \"who\nwould see in the dark\" to the commentaries of Landino,\nVellutello, and others: and adds that it is evident the Poet has\naccommodated to his own fancy many sacred images in the\nApocalypse.  In Vasari\'s Life of Giotto, we learn that Dante\nrecommended that book to his friend, as affording fit\nsubjects for his pencil.\n\nv. 89.  Four.]  The four evangelists.\n\nv. 96.  Ezekiel.]  Chap. 1.  4.\n\nv. 101.  John.]  Rev. c. iv.  8.\n\nv. 104.  Gryphon.]  Und");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ruB\\eASE.tXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3689; ++i)
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
    

                char expected_filecontent[355] = "";

                strcat(expected_filecontent, "ompare Origen in Genesim, Patrum Graecorum, vol. xi. p. 14.\nWirer burgi,\n1783.  8vo.\n\nv. 79.  To mightier force.]  \"Though ye are subject to a higher\npower than that of the heavenly constellations, e`en to the power\nof the great Creator himself, yet ye are still left in the\npossession of liberty.\"\n\nv. 88.  Like a babe that wantons sportively.]  This re");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\RUB\\PITCH.BiN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 354; ++i)
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
    

                char expected_filecontent[1962] = "";

                strcat(expected_filecontent, "h art conducted, that the sound\nReach\'d the world\'s limit.  Soon as to that part\nOf life I found me come, when each behoves\nTo lower sails and gather in the lines;\nThat which before had pleased me then I rued,\nAnd to repentance and confession turn\'d;\nWretch that I was! and well it had bested me!\nThe chief of the new Pharisees meantime,\nWaging his warfare near the Lateran,\nNot with the Saracens or Jews (his foes\nAll Christians were, nor against Acre one\nHad fought, nor traffic\'d in the Soldan\'s land),\nHe his great charge nor sacred ministry\nIn himself, rev\'renc\'d, nor in me that cord,\nWhich us\'d to mark with leanness whom it girded.\nAs in Socrate, Constantine besought\nTo cure his leprosy Sylvester\'s aid,\nSo me to cure the fever of his pride\nThis man besought: my counsel to that end\nHe ask\'d:  and I was silent:  for his words\nSeem\'d drunken:  but forthwith he thus resum\'d:\n\"From thy heart banish fear:  of all offence\nI hitherto absolve thee.  In return,\nTeach me my purpose so to execute,\nThat Penestrino cumber earth no more.\nHeav\'n, as thou knowest, I have power to shut\nAnd open:  and the keys are therefore twain,\nThe which my predecessor meanly priz\'d.\"\n     Then, yielding to the forceful arguments,\nOf silence as more perilous I deem\'d,\nAnd answer\'d:  \"Father! since thou washest me\nClear of that guilt wherein I now must fall,\nLarge promise with performance scant, be sure,\nShall make thee triumph in thy lofty seat.\"\n     \"When I was number\'d with the dead, then came\nSaint Francis for me; but a cherub dark\nHe met, who cried: \"\'Wrong me not; he is mine,\nAnd must below to join the wretched crew,\nFor the deceitful counsel which he gave.\nE\'er since I watch\'d him, hov\'ring at his hair,\nNo power can the impenitent absolve;\nNor to repent and will at once consist,\nBy contradiction absolute forbid.\"\nOh mis\'ry! how I shook myself, when he\nSeiz\'d me, and cried, \"Thou haply thought\'st me not\nA disputant in logic so exact.\"\nTo Minos down he bo");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\RUB\\faIR");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 1961; ++i)
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
    

                char expected_filecontent[2811] = "";

                strcat(expected_filecontent, "am\'d and ever-new delight.\nThat vapours none, exhal\'d from earth beneath,\nOr from the waters (which, wherever heat\nAttracts them, follow), might ascend thus far\nTo vex man\'s peaceful state, this mountain rose\nSo high toward the heav\'n, nor fears the rage\n0f elements contending, from that part\nExempted, where the gate his limit bars.\nBecause the circumambient air throughout\nWith its first impulse circles still, unless\nAught interpose to cheek or thwart its course;\nUpon the summit, which on every side\nTo visitation of th\' impassive air\nIs open, doth that motion strike, and makes\nBeneath its sway th\' umbrageous wood resound:\nAnd in the shaken plant such power resides,\nThat it impregnates with its efficacy\nThe voyaging breeze, upon whose subtle plume\nThat wafted flies abroad; and th\' other land\nReceiving (as \'t is worthy in itself,\nOr in the clime, that warms it), doth conceive,\nAnd from its womb produces many a tree\nOf various virtue.  This when thou hast heard,\nThe marvel ceases, if in yonder earth\nSome plant without apparent seed be found\nTo fix its fibrous stem.  And further learn,\nThat with prolific foison of all seeds,\nThis holy plain is fill\'d, and in itself\nBears fruit that ne\'er was pluck\'d on other soil.\n \"The water, thou behold\'st, springs not from vein,\nAs stream, that intermittently repairs\nAnd spends his pulse of life, but issues forth\nFrom fountain, solid, undecaying, sure;\nAnd by the will omnific, full supply\nFeeds whatsoe\'er On either side it pours;\nOn this devolv\'d with power to take away\nRemembrance of offence, on that to bring\nRemembrance back of every good deed done.\nFrom whence its name of Lethe on this part;\nOn th\' other Eunoe: both of which must first\nBe tasted ere it work; the last exceeding\nAll flavours else.  Albeit thy thirst may now\nBe well contented, if I here break off,\nNo more revealing: yet a corollary\nI freely give beside: nor deem my words\nLess grateful to thee, if they somewhat pass\nThe stretch of promise.  They, whose verse of yore\nThe golden age recorded and its bliss,\nOn the Parnassian mountain, of this place\nPerhaps had dream\'d.  Here was man guiltless, here\nPerpetual spring and every fruit, and this\nThe far-fam\'d nectar.\"  Turning to the bards,\nWhen she had ceas\'d, I noted in their looks\nA smile at her conclusion; then my face\nAgain directed to the lovely dame.\n\n\n\nCANTO XXIX\n\nSinging, as if enamour\'d, she resum\'d\nAnd clos\'d the song, with \"Blessed they whose sins\nAre cover\'d.\"  Like the wood-nymphs then, that tripp\'d\nSingly across the sylvan shadows, one\nEager to view and one to \'scape the sun,\nSo mov\'d she on, against the current, up\nThe verdant rivage.  I, her mincing step\nObserving, with as tardy step pursued.\n     Between us not an hundred paces trod,\nThe bank, on each side bending equally,\nGave me to face the orient.  ");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\rUB\\RANGE.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2810; ++i)
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
    

                char expected_filecontent[255] = "";

                strcat(expected_filecontent, "k,\nThe Sun of angels, him, who by his grace\nTo this perceptible hath lifted thee.\"\n     Never was heart in such devotion bound,\nAnd with complacency so absolute\nDispos\'d to render up itself to God,\nAs mine was at those words: and so entire\nThe love for H");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\rUb\\KepT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 254; ++i)
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
    

                char expected_filecontent[2875] = "";

                strcat(expected_filecontent, " fled\nTo Scyros, with him sleeping in her arms;\nE\'en thus I shook me, soon as from my face\nThe slumber parted, turning deadly pale,\nLike one ice-struck with dread.  Solo at my side\nMy comfort stood: and the bright sun was now\nMore than two hours aloft: and to the sea\nMy looks were turn\'d.  \"Fear not,\" my master cried,\n\"Assur\'d we are at happy point.  Thy strength\nShrink not, but rise dilated.  Thou art come\nTo Purgatory now.  Lo! there the cliff\nThat circling bounds it!  Lo!  the entrance there,\nWhere it doth seem disparted!  Ere the dawn\nUsher\'d the daylight, when thy wearied soul\nSlept in thee, o\'er the flowery vale beneath\nA lady came, and thus bespake me: \"I\nAm Lucia.  Suffer me to take this man,\nWho slumbers.  Easier so his way shall speed.\"\nSordello and the other gentle shapes\nTarrying, she bare thee up: and, as day shone,\nThis summit reach\'d: and I pursued her steps.\nHere did she place thee.  First her lovely eyes\nThat open entrance show\'d me; then at once\nShe vanish\'d with thy sleep.\"  Like one, whose doubts\nAre chas\'d by certainty, and terror turn\'d\nTo comfort on discovery of the truth,\nSuch was the change in me: and as my guide\nBeheld me fearless, up along the cliff\nHe mov\'d, and I behind him, towards the height.\n     Reader!  thou markest how my theme doth rise,\nNor wonder therefore, if more artfully\nI prop the structure!  Nearer now we drew,\nArriv\'d\' whence in that part, where first a breach\nAs of a wall appear\'d, I could descry\nA portal, and three steps beneath, that led\nFor inlet there, of different colour each,\nAnd one who watch\'d, but spake not yet a word.\nAs more and more mine eye did stretch its view,\nI mark\'d him seated on the highest step,\nIn visage such, as past my power to bear.\nGrasp\'d in his hand a naked sword, glanc\'d back\nThe rays so toward me, that I oft in vain\nMy sight directed.  \"Speak from whence ye stand:\"\nHe cried:  \"What would ye?  Where is your escort?\nTake heed your coming upward harm ye not.\"\n     \"A heavenly dame, not skilless of these things,\"\nReplied the\' instructor, \"told us, even now,\n\'Pass that way: here the gate is.\" --\"And may she\nBefriending prosper your ascent,\" resum\'d\nThe courteous keeper of the gate:  \"Come then\nBefore our steps.\"  We straightway thither came.\n     The lowest stair was marble white so smooth\nAnd polish\'d, that therein my mirror\'d form\nDistinct I saw.  The next of hue more dark\nThan sablest grain, a rough and singed block,\nCrack\'d lengthwise and across.  The third, that lay\nMassy above, seem\'d porphyry, that flam\'d\nRed as the life-blood spouting from a vein.\nOn this God\'s angel either foot sustain\'d,\nUpon the threshold seated, which appear\'d\nA rock of diamond.  Up the trinal steps\nMy leader cheerily drew me.  \"Ask,\" said he,\n     \"With humble heart, that he unbar the bolt.\"\n     Piously at his holy feet devolv\'d\nI cast me, praying him for pity\'s sake\nThat he");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\rUB\\sOLUTION");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2874; ++i)
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
    

                char expected_filecontent[160] = "";

                strcat(expected_filecontent, "coda!\"  Whereat one advanc\'d,\nThe others standing firm, and as he came,\n\"What may this turn avail him?\" he exclaim\'d.\n     \"Believ\'st thou, Malacoda!  I had co");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\rUb\\rUN.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 159; ++i)
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
    

                char expected_filecontent[183] = "";

                strcat(expected_filecontent, "ight\nKindled afresh, with vigour to sustain\nExcess of light, however pure.  I look\'d;\nAnd in the likeness of a river saw\nLight flowing, from whose amber-seeming waves\nFlash\'d up effu");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\RuB\\FeLl");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 182; ++i)
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
    

                char expected_filecontent[2480] = "";

                strcat(expected_filecontent, "  designat amorem:\nQuippe amor est igni similis; flammasque rubentes\nIgnus habere solet.\nPalingenii Zodiacus Vitae, 1. xii.\n\nv. 26.  A dame.]  Philosophy.\n\nv. 49.  Who mourn.]  Matt.  c. v. 4.\n\nv. 72.  My soul.]  Psalm cxix.  5\n\nv. 97.  The successor of Peter Ottobuono, of the family of\nFieschi Counts of Lavagna, died thirty-nine days after he became\nPope, with the title of Adrian V, in 1276.\n\nv. 98.  That stream.]  The river Lavagna, in the Genoese\nterritory.\n\nv. 135.  nor shall be giv\'n in marriage.]  Matt. c. xxii. 30.\n\"Since in this state we neither marry nor are given in marriage,\nI am no longer the spouse of the church, and therefore no longer\nretain my former dignity.\n\nv. 140.  A kinswoman.]  Alagia is said to have been the wife of\nthe Marchese Marcello Malaspina, one of the poet\'s protectors\nduring his exile.  See Canto VIII.  133.\n\nCANTO XX\n\nv. 3.  I drew the sponge.]  \"I did not persevere in my inquiries\nfrom the spirit though still anxious to learn more.\"\nv. 11.  Wolf.]  Avarice.\n\nv. 16.  Of his appearing.]  He is thought to allude to\nCan Grande della Scala.  See Hell, Canto I. 98.\n\nv. 25.  Fabricius.]  Compare Petrarch, Tr. della Fama, c. 1.\n\nUn Curio ed un Fabricio, &c.\n\nv. 30.  Nicholas.]  The story of Nicholas is, that an angel\nhaving revealed to him that the father of a family was so\nimpoverished as to resolve on exposing the chastity of his three\ndaughters to sale, he threw in at the window of their house three\nbags of money, containing a sufficient portion for each of them.\nv. 42.  Root.]  Hugh Capet, ancestor of Philip IV.\nv. 46.  Had Ghent and Douay, Lille and Bruges power.]  These\ncities had lately been seized by Philip IV.  The spirit is made\nto imitate the approaching defeat of the French army by the\nFlemings, in the battle of Courtrai, which happened in 1302.\nv. 51.  The slaughter\'s trade.]  This reflection on the birth of\nhis ancestor induced Francis I  to forbid the reading of Dante in\nhis dominions Hugh Capet, who came to the throne of France in\n987, was however the grandson of Robert, who was the brother of\nEudes,  King of France in 888.\n\nv. 52.  All save one.]  The posterity of Charlemagne, the second\nrace of French monarchs, had failed, with the exception of\nCharles of Lorraine who is said, on account of the melancholy\ntemper of his mind, to have always clothed himself in black.\nVenturi suggest that Dante may have confounded him with Childeric\nIII  the last of the Merosvingian, or first, race, who was\ndepo");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\rUB\\FEAr.Bin");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2479; ++i)
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
    

                char expected_filecontent[3073] = "";

                strcat(expected_filecontent, "no track\nOf steps had worn a way.  Not verdant there\nThe foliage, but of dusky hue; not light\nThe boughs and tapering, but with knares deform\'d\nAnd matted thick:  fruits there were none, but thorns\nInstead, with venom fill\'d. Less sharp than these,\nLess intricate the brakes, wherein abide\nThose animals, that hate the cultur\'d fields,\nBetwixt Corneto and Cecina\'s stream.\n     Here the brute Harpies make their nest, the same\nWho from the Strophades the Trojan band\nDrove with dire boding of their future woe.\nBroad are their pennons, of the human form\nTheir neck and count\'nance, arm\'d with talons keen\nThe feet, and the huge belly fledge with wings\nThese sit and wail on the drear mystic wood.\n     The kind instructor in these words began:\n\"Ere farther thou proceed, know thou art now\nI\' th\' second round, and shalt be, till thou come\nUpon the horrid sand:  look therefore well\nAround thee, and such things thou shalt behold,\nAs would my speech discredit.\"  On all sides\nI heard sad plainings breathe, and none could see\nFrom whom they might have issu\'d.  In amaze\nFast bound I stood.  He, as it seem\'d, believ\'d,\nThat I had thought so many voices came\nFrom some amid those thickets close conceal\'d,\nAnd thus his speech resum\'d:  \"If thou lop off\nA single twig from one of those ill plants,\nThe thought thou hast conceiv\'d shall vanish quite.\"\n     Thereat a little stretching forth my hand,\nFrom a great wilding gather\'d I a branch,\nAnd straight the trunk exclaim\'d:  \"Why pluck\'st thou me?\"\nThen as the dark blood trickled down its side,\nThese words it added:  \"Wherefore tear\'st me thus?\nIs there no touch of mercy in thy breast?\nMen once were we, that now are rooted here.\nThy hand might well have spar\'d us, had we been\nThe souls of serpents.\"  As a brand yet green,\nThat burning at one end from the\' other sends\nA groaning sound, and hisses with the wind\nThat forces out its way, so burst at once,\nForth from the broken splinter words and blood.\n     I, letting fall the bough, remain\'d as one\nAssail\'d by terror, and the sage replied:\n\"If he, O injur\'d spirit! could have believ\'d\nWhat he hath seen but in my verse describ\'d,\nHe never against thee had stretch\'d his hand.\nBut I, because the thing surpass\'d belief,\nPrompted him to this deed, which even now\nMyself I rue.  But tell me, who thou wast;\nThat, for this wrong to do thee some amends,\nIn the upper world (for thither to return\nIs granted him) thy fame he may revive.\"\n     \"That pleasant word of thine,\" the trunk replied\n\"Hath so inveigled me, that I from speech\nCannot refrain, wherein if I indulge\nA little longer, in the snare detain\'d,\nCount it not grievous.  I it was, who held\nBoth keys to Frederick\'s heart, and turn\'d the wards,\nOpening and shutting, with a skill so sweet,\nThat besides me, into his inmost breast\nScarce any other could admittance find.\nThe faith I bore to my high charge was such,\nIt cost me the life-blood that warm\'d my veins.\nThe harlot, who ne\'er turn\'d her gloating eyes\nFrom Caesar\'s household, common vice and pest\nOf courts, \'gainst me inflam\'d the minds of all;\nAnd");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\RUB\\reD.TX");
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
    

                char expected_filecontent[426] = "";

                strcat(expected_filecontent, "blaze\nOf comet splendour; and as wheels, that wind\nTheir circles in the horologe, so work\nThe stated rounds, that to th\' observant eye\nThe first seems still, and, as it flew, the last;\nE\'en thus their carols weaving variously,\nThey by the measure pac\'d, or swift, or slow,\nMade me to rate the riches of their joy.\n     From that, which I did note in beauty most\nExcelling, saw I issue forth a flame\nSo bright, as none was lef");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\rUB\\TRoubLE.BIn");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 425; ++i)
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
    

                char expected_filecontent[324] = "";

                strcat(expected_filecontent, "For one of these may rise, the other fall.\"\n\n\n\nCANTO XIV\n\nFrom centre to the circle, and so back\nFrom circle to the centre, water moves\nIn the round chalice, even as the blow\nImpels it, inwardly, or from without.\nSuch was the image glanc\'d into my mind,\nAs the great spirit of Aquinum ceas\'d;\nAnd Beatrice after him her wor");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\RUB\\LIST");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 323; ++i)
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
    

                char expected_filecontent[3147] = "";

                strcat(expected_filecontent, "er my speech I fram\'d:\n\"Ah!  please thee hither towards the streamlet bend\nThy steps so near, that I may list thy song.\nBeholding thee and this fair place, methinks,\nI call to mind where wander\'d and how look\'d\nProserpine, in that season, when her child\nThe mother lost, and she the bloomy spring.\"\n     As when a lady, turning in the dance,\nDoth foot it featly, and advances scarce\nOne step before the other to the ground;\nOver the yellow and vermilion flowers\nThus turn\'d she at my suit, most maiden-like,\nValing her sober eyes, and came so near,\nThat I distinctly caught the dulcet sound.\nArriving where the limped waters now\nLav\'d the green sward, her eyes she deign\'d to raise,\nThat shot such splendour on me, as I ween\nNe\'er glanced from Cytherea\'s, when her son\nHad sped his keenest weapon to her heart.\nUpon the opposite bank she stood and smil\'d\nthrough her graceful fingers shifted still\nThe intermingling dyes, which without seed\nThat lofty land unbosoms.  By the stream\nThree paces only were we sunder\'d: yet\nThe Hellespont, where Xerxes pass\'d it o\'er,\n(A curb for ever to the pride of man)\nWas by Leander not more hateful held\nFor floating, with inhospitable wave\n\'Twixt Sestus and Abydos, than by me\nThat flood, because it gave no passage thence.\n     \"Strangers ye come, and haply in this place,\nThat cradled human nature in its birth,\nWond\'ring, ye not without suspicion view\nMy smiles: but that sweet strain of psalmody,\n\'Thou, Lord!  hast made me glad,\' will give ye light,\nWhich may uncloud your minds.  And thou, who stand\'st\nThe foremost, and didst make thy suit to me,\nSay if aught else thou wish to hear: for I\nCame prompt to answer every doubt of thine.\"\n     She spake; and I replied:  \"l know not how\nTo reconcile this wave and rustling sound\nOf forest leaves, with what I late have heard\nOf opposite report.\"  She answering thus:\n\"I will unfold the cause, whence that proceeds,\nWhich makes thee wonder; and so purge the cloud\nThat hath enwraps thee.  The First Good, whose joy\nIs only in himself, created man\nFor happiness, and gave this goodly place,\nHis pledge and earnest of eternal peace.\nFavour\'d thus highly, through his own defect\nHe fell, and here made short sojourn; he fell,\nAnd, for the bitterness of sorrow, chang\'d\nLaughter unblam\'d and ever-new delight.\nThat vapours none, exhal\'d from earth beneath,\nOr from the waters (which, wherever heat\nAttracts them, follow), might ascend thus far\nTo vex man\'s peaceful state, this mountain rose\nSo high toward the heav\'n, nor fears the rage\n0f elements contending, from that part\nExempted, where the gate his limit bars.\nBecause the circumambient air throughout\nWith its first impulse circles still, unless\nAught interpose to cheek or thwart its course;\nUpon the summit, which on every side\nTo visitation of th\' impassive air\nIs open, doth that motion strike, and makes\nBeneath its sway th\' umbrageous wood resound:\nAnd in the shaken plant such power resides,\nThat it impregnates with its efficacy\nThe voyaging breeze, upon whose subtle plume\nThat wafted flies abroad; and th\' other land\nReceiving (as \'t is worthy in itself,\nOr in the clime, that warms it), doth");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\RuB\\rOUND.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3146; ++i)
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
    

                char expected_filecontent[1990] = "";

                strcat(expected_filecontent, "ue, not the seeming, breadth\nOf substance, measure, thou shalt see the heav\'ns,\nEach to the\' intelligence that ruleth it,\nGreater to more, and smaller unto less,\nSuited in strict and wondrous harmony.\"\n     As when the sturdy north blows from his cheek\nA blast, that scours the sky, forthwith our air,\nClear\'d of the rack, that hung on it before,\nGlitters; and, With his beauties all unveil\'d,\nThe firmament looks forth serene, and smiles;\nSuch was my cheer, when Beatrice drove\nWith clear reply the shadows back, and truth\nWas manifested, as a star in heaven.\nAnd when the words were ended, not unlike\nTo iron in the furnace, every cirque\nEbullient shot forth scintillating fires:\nAnd every sparkle shivering to new blaze,\nIn number did outmillion the account\nReduplicate upon the chequer\'d board.\nThen heard I echoing on from choir to choir,\n\"Hosanna,\" to the fixed point, that holds,\nAnd shall for ever hold them to their place,\nFrom everlasting, irremovable.\n     Musing awhile I stood: and she, who saw\nby inward meditations, thus began:\n\"In the first circles, they, whom thou beheldst,\nAre seraphim and cherubim.  Thus swift\nFollow their hoops, in likeness to the point,\nNear as they can, approaching; and they can\nThe more, the loftier their vision.  Those,\nThat round them fleet, gazing the Godhead next,\nAre thrones; in whom the first trine ends.  And all\nAre blessed, even as their sight descends\nDeeper into the truth, wherein rest is\nFor every mind.  Thus happiness hath root\nIn seeing, not in  loving, which of sight\nIs aftergrowth.  And of the seeing such\nThe meed, as unto each in due degree\nGrace and good-will their measure have assign\'d.\nThe other trine, that with still opening buds\nIn this eternal springtide blossom fair,\nFearless of bruising from the nightly ram,\nBreathe up in warbled melodies threefold\nHosannas blending ever, from the three\nTransmitted. hierarchy of gods, for aye\nRejoicing, dominations first, next then\nVirtues, and powers the third.  The next to");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\RUB\\SECtIoN.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 1989; ++i)
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
    

                char expected_filecontent[3073] = "";

                strcat(expected_filecontent, "t of country, abounding in deer, goats, and wild boars.\nCecina is a river not far to the south of Leghorn, Corneto, a\nsmall city on the same coast in the patrimony of the church.\n\nv. 12.  The Strophades.]  See Virg. Aen. l. iii. 210.\n\nv. 14.  Broad are their pennons.]  From Virg. Aen. l. iii. 216.\n\nv. 48.  In my verse described.]  The commentators explain this,\n\"If he could have believed, in consequence of my assurances\nalone, that of which he hath now had ocular proof, he would not\nhave stretched forth his hand against thee.\"  But I am of opinion\nthat Dante makes Virgil allude to his own story of Polydorus in\nthe third book of the Aeneid.\n\nv. 56.  That pleasant word of thine.]  \"Since you have inveigled\nme to speak my holding forth so gratifying an expectation, let it\nnot displease you if I am as it were detained in the snare you\nhave spread for me, so as to be somewhat prolix in my answer.\"\n\nv. 60. I it was.]  Pietro delle Vigne, a native of Capua, who,\nfrom a low condition, raised himself by his eloquence and legal\nknowledge to the office of Chancellor to the Emperor Frederick\nII. whose confidence in him was such, that his influence in the\nempire became unbounded.  The courtiers, envious of his exalted\nsituation, contrived, by means of forged letters, to make\nFrederick believe that he held a secret and traitorous\nintercourse with the Pope, who was then at enmity with the\nEmperor.  In consequence of this supposed crime he was cruelly\ncondemned by his too credulous sovereign to lose his eyes, and,\nbeing driven to despair by his unmerited calamity and disgrace,\nhe put an end to his life by dashing out his brains against the\nwalls of a church, in the year 1245.  Both Frederick and Pietro\ndelle Vigne composed verses in the Sicilian dialect which are yet\nextant.\n\nv. 67.  The harlot.]  Envy.  Chaucer alludes to this in the\nPrologue to the Legende of Good women.\n        Envie is lavender to the court alway,\n        For she ne parteth neither night ne day\n        Out of the house of Cesar; thus saith Dant.\n\nv. 119.  Each fan o\' th\' wood.]  Hence perhaps Milton:\n        Leaves and fuming rills, Aurora\'s fan.\n               P. L. b. v. 6.\n\nv. 122.  Lano.]  Lano, a Siennese, who, being reduced by\nprodigality to a state of extreme want, found his existence no\nlonger supportable; and, having been sent by his countrymen on a\nmilitary expedition, to assist the Florentine against the\nAretini, took that opportunity of exposing himself to certain\ndeath, in the engagement which took place at Toppo near Arezzo.\nSee G. Villani, Hist. l. 7. c. cxix.\n\nv. 133.               O Giocomo\n        Of Sant\' Andrea!]\nJacopo da Sant\' Andrea, a Paduan, who, having wasted his property\nin the most wanton acts of profusion, killed himself in despair.\nv. 144.  In that City.]  \"I was an inhabitant of Florence, that\ncity which changed her first patron Mars for St. John the\nBaptist, for which reason the vengeance of the deity thus\nslighted will never be appeased:  and, if some remains of his\nstatus were not still visible on the bridge over the Arno, she\nw");

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\RuB\\BRING.Tx");
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
    
            char *filecontent = (char *)calloc(490, 1);
            char expected_filecontent[491] = "";

            strcat(expected_filecontent, "thy voice.\"\n     There stood I like the friar, that doth shrive\nA wretch for murder doom\'d, who e\'en when fix\'d,\nCalleth him back, whence death awhile delays.\n     He shouted:  \"Ha! already standest there?\nAlready standest there, O Boniface!\nBy many a year the writing play\'d me false.\nSo early dost thou surfeit with the wealth,\nFor which thou fearedst not in guile to take\nThe lovely lady, and then mangle her?\"\n     I felt as those who, piercing not the drift\nOf answer made them, stand ");

            struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "yarD");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int i;
            for (i = 0; i < 49; ++i)
            {
                int res = file_read(filecontent + 10 * i, 10, 1, file);
                test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            }

            int res = file_read(filecontent + 10 * i, 10, 1, file);
            test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 490);

            // jeśli jest, to raportuj błąd
            test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

            onerror_compare_memory(expected_filecontent, filecontent, 490);

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
    

            char *filecontent0 = (char *)calloc(490, 1);
    char *filecontent1 = (char *)calloc(2474, 1);
    char *filecontent2 = (char *)calloc(3376, 1);
    char *filecontent3 = (char *)calloc(1593, 1);
    char *filecontent4 = (char *)calloc(3584, 1);
    char *filecontent5 = (char *)calloc(186, 1);

            char expected_filecontent0[491] = "";
    char expected_filecontent1[2475] = "";
    char expected_filecontent2[3377] = "";
    char expected_filecontent3[1594] = "";
    char expected_filecontent4[3585] = "";
    char expected_filecontent5[187] = "";

            strcat(expected_filecontent0, "thy voice.\"\n     There stood I like the friar, that doth shrive\nA wretch for murder doom\'d, who e\'en when fix\'d,\nCalleth him back, whence death awhile delays.\n     He shouted:  \"Ha! already standest there?\nAlready standest there, O Boniface!\nBy many a year the writing play\'d me false.\nSo early dost thou surfeit with the wealth,\nFor which thou fearedst not in guile to take\nThe lovely lady, and then mangle her?\"\n     I felt as those who, piercing not the drift\nOf answer made them, stand ");strcat(expected_filecontent1, "\'d not\nBut I remember\'d him; and towards his face\nMy hand inclining, answer\'d:  \"Sir! Brunetto!\nAnd art thou here?\"  He thus to me:  \"My son!\nOh let it not displease thee, if Brunetto\nLatini but a little space with thee\nTurn back, and leave his fellows to proceed.\"\n     I thus to him replied:  \"Much as I can,\nI thereto pray thee; and if thou be willing,\nThat I here seat me with thee, I consent;\nHis leave, with whom I journey, first obtain\'d.\"\n     \"O son!\" said he, \" whoever of this throng\nOne instant stops, lies then a hundred years,\nNo fan to ventilate him, when the fire\nSmites sorest.  Pass thou therefore on.  I close\nWill at thy garments walk, and then rejoin\nMy troop, who go mourning their endless doom.\"\n     I dar\'d not from the path descend to tread\nOn equal ground with him, but held my head\nBent down, as one who walks in reverent guise.\n     \"What chance or destiny,\" thus be began,\n\"Ere the last day conducts thee here below?\nAnd who is this, that shows to thee the way?\"\n     \"There up aloft,\" I answer\'d, \"in the life\nSerene, I wander\'d in a valley lost,\nBefore mine age had to its fullness reach\'d.\nBut yester-morn I left it:  then once more\nInto that vale returning, him I met;\nAnd by this path homeward he leads me back.\"\n     \"If thou,\" he answer\'d, \"follow but thy star,\nThou canst not miss at last a glorious haven:\nUnless in fairer days my judgment err\'d.\nAnd if my fate so early had not chanc\'d,\nSeeing the heav\'ns thus bounteous to thee, I\nHad gladly giv\'n thee comfort in thy work.\nBut that ungrateful and malignant race,\nWho in old times came down from Fesole,\nAy and still smack of their rough mountain-flint,\nWill for thy good deeds shew thee enmity.\nNor wonder; for amongst ill-savour\'d crabs\nIt suits not the sweet fig-tree lay her fruit.\nOld fame reports them in the world for blind,\nCovetous, envious, proud.  Look to it well:\nTake heed thou cleanse thee of their ways.  For thee\nThy fortune hath such honour in reserve,\nThat thou by either party shalt be crav\'d\nWith hunger keen:  but be the fresh herb far\nFrom the goat\'s tooth.  The herd of Fesole\nMay of themselves make litter, not touch the plant,\nIf any such yet spring on their rank bed,\nIn which the holy seed revives, transmitted\nFrom those true Romans, who still there remain\'d,\nWhen it was made the nest of so much ill.\"\n     \"Were all my wish fulfill\'d,\" I straight replied,\n\"Thou from the confines of man\'s nature yet\nHadst not been driven forth; for in my mind\nIs fix\'d,");strcat(expected_filecontent2, "g\n        Torment, and loud lament, and furious rage.\n\nv. 50.  a puissant one.]  Our Saviour.\n\nv. 75.                 Honour the bard\n        Sublime.]\n\n        Onorate l\'altissimo poeta.\nSo Chiabrera, Canz. Eroiche. 32.\n        Onorando l\'altissimo poeta.\n\nv. 79.  Of semblance neither sorrowful nor glad.]\n        She nas to sober ne to glad.\n               Chaucer\'s Dream.\n\nv. 90.  The Monarch of sublimest song.]  Homer.\n\nv. 100.  Fitter left untold.]\n        Che\'l tacere e bello,\nSo our Poet, in Canzone 14.\n        La vide in parte che\'l tacere e bello,\nRuccellai, Le Api, 789.\n        Ch\'a dire e brutto ed a tacerlo e bello\nAnd Bembo,\n        \"Vie pui bello e il tacerle, che il favellarne.\"\n               Gli. Asol. lib. 1.\n\nv. 117.  Electra.]  The daughter of Atlas, and mother of Dardanus\nthe founder of Troy.  See Virg. Aen. b. viii. 134. as referred to\nby Dante in treatise \"De Monarchia,\" lib. ii. \"Electra, scilicet,\nnata magni nombris regis Atlantis, ut de ambobus testimonium\nreddit poeta noster in octavo ubi Aeneas ad Avandrum sic ait\n        \"Dardanus Iliacae,\" &c.\n\nv. 125.  Julia.]  The daughter of Julius Caesar, and wife of\nPompey.\n\nv. 126.  The Soldan fierce.]  Saladin or Salaheddin, the  rival\nof  Richard coeur de lion.  See D\'Herbelot, Bibl. Orient. and\nKnolles\'s Hist. of the Turks p. 57 to 73 and the Life of Saladin,\nby Bohao\'edin Ebn Shedad, published by Albert Schultens, with a\nLatin translation. He is introduced by Petrarch in the Triumph of\nFame, c. ii\n\nv. 128.  The master of the sapient throng.]\n        Maestro di color che sanno.\nAristotle--Petrarch assigns the first place to Plato. See Triumph\nof Fame, c. iii.\nPulci, in his Morgante Maggiore, c. xviii. says,\n        Tu se\'il maestro di color che sanno.\n\nv. 132.               Democritus\n        Who sets the world at chance.]\nDemocritus,who maintained the world to have been formed by the\nfortuitous concourse of atoms.\n\nv. 140.  Avicen.]  See D\'Herbelot Bibl. Orient. article  Sina. He\ndied in 1050.  Pulci here again imitates our poet:\n\n        Avicenna quel che il sentimento\n        Intese di Aristotile e i segreti,\n        Averrois che fece il gran comento.\n               Morg. Mag. c. xxv.\n\nv. 140.               Him who made\n        That commentary vast, Averroes.]\nAverroes, called by the Arabians Roschd, translated and commented\nthe works of Aristotle. According to Tiraboschi (storia della\nLett. Ital. t. v. 1. ii. c. ii. sect. 4.) he was the source of\nmodern philosophical impiety. The critic quotes some passages\nfrom Petrarch (Senil. 1. v. ep. iii. et. Oper. v. ii. p. 1143) to\nshow how strongly such sentiments prevailed in the time of that\npoet, by whom they were held in horror and detestation He adds,\nthat this fanatic admirer of Aristotle translated his writings\nwith that felicity, which might be expected from one who did not\nknow a syllable of Greek, and who was therefore compelled to\navail himself of the unfaithful Arabic versions. D\'Herbelot, on\nthe other hand, informs us, that \"Averroes was the first who\ntranslated Aristotle from Greek into Arabic, before the Jews had\nmade their translation:  and that we had for a long time no other\ntext of Aristotle, except that of the Latin translation, which\nwas made from this Arabic version of this great philosopher\n(Averroes), who afterwards added to it a very ample commentary,\nof which Thomas Aquinas");strcat(expected_filecontent3, "n idle play.\"\n     Such were the words that Beatrice spake:\nThese ended, to that region, where the world\nIs liveliest, full of fond desire she turn\'d.\n     Though mainly prompt new question to propose,\nHer silence and chang\'d look did keep me dumb.\nAnd as the arrow, ere the cord is still,\nLeapeth unto its mark; so on we sped\nInto the second realm.  There I beheld\nThe dame, so joyous enter, that the orb\nGrew brighter at her smiles; and, if the star\nWere mov\'d to gladness, what then was my cheer,\nWhom nature hath made apt for every change!\n     As in a quiet and clear lake the fish,\nIf aught approach them from without, do draw\nTowards it, deeming it their food; so drew\nFull more than thousand splendours towards us,\nAnd in each one was heard:  \"Lo!  one arriv\'d\nTo multiply our loves!\" and as each came\nThe shadow, streaming forth effulgence new,\nWitness\'d augmented joy.  Here, reader!  think,\nIf thou didst miss the sequel of my tale,\nTo know the rest how sorely thou wouldst crave;\nAnd thou shalt see what vehement desire\nPossess\'d me, as soon as these had met my view,\nTo know their state.  \"O born in happy hour!\nThou to whom grace vouchsafes, or ere thy close\nOf fleshly warfare, to behold the thrones\nOf that eternal triumph, know to us\nThe light communicated, which through heaven\nExpatiates without bound.  Therefore, if aught\nThou of our beams wouldst borrow for thine aid,\nSpare not; and of our radiance take thy fill.\"\n     Thus of those piteous spirits one bespake me;\nAnd Beatrice next:  \"Say on; and trust\nAs unto gods!\" --\"How in the light supreme\nThou harbour\'st, and f");strcat(expected_filecontent4, "with the change.  In that abyss\nOf radiance, clear and lofty, seem\'d methought,\nThree orbs of triple hue clipt in one bound:\nAnd, from another, one reflected seem\'d,\nAs rainbow is from rainbow: and the third\nSeem\'d fire, breath\'d equally from both.  Oh speech\nHow feeble and how faint art thou, to give\nConception birth!  Yet this to what I saw\nIs less than little.  Oh eternal light!\nSole in thyself that dwellst; and of thyself\nSole understood, past, present, or to come!\nThou smiledst; on that circling, which in thee\nSeem\'d as reflected splendour, while I mus\'d;\nFor I therein, methought, in its own hue\nBeheld our image painted: steadfastly\nI therefore por\'d upon the view.  As one\nWho vers\'d in geometric lore, would fain\nMeasure the circle; and, though pondering long\nAnd deeply, that beginning, which he needs,\nFinds not; e\'en such was I, intent to scan\nThe novel wonder, and trace out the form,\nHow to the circle fitted, and therein\nHow plac\'d: but the flight was not for my wing;\nHad not a flash darted athwart my mind,\nAnd in the spleen unfolded what it sought.\n     Here vigour fail\'d the tow\'ring fantasy:\nBut yet the will roll\'d onward, like a wheel\nIn even motion, by the Love impell\'d,\nThat moves the sun in heav\'n and all the stars.\n\n\nNOTES TO PARADISE\n\n\nCANTO 1\n\nVerse 12.  Benign Apollo.]  Chaucer has imitated this invention\nvery closely at the beginning of the Third Booke of Fame.\n\nIf, divine vertue, thou\nWilt helpe me to shewe  now\nThat in my head ymarked is,\n     * * * * *\nThou shalt see me go as blive\nUnto the next laurer I see,\nAnd kisse it for it is thy tree\nNow entre thou my breast anone.\n\nv. 15.  Thus for.]  He appears to mean nothing more than that\nthis part of his poem will require a greater exertion of his\npowers than the former.\n\nv. 19.  Marsyas.]  Ovid, Met. 1. vi. fab. 7.  Compare Boccaccio,\nII Filocopo, 1.  5. p. 25. v. ii. Ediz.  Fir.  1723.  \"Egli nel\nmio petto entri,\" &c. - \"May he enter my bosom, and let my voice\nsound like his own, when he made that daring mortal deserve to\ncome forth unsheathed from his limbs. \"\nv. 29.  Caesar, or bard.]  So Petrarch, Son.  Par. Prima.\n\nArbor vittoriosa e trionfale,\nOnor d\'imperadori e di poeti.\n\nAnd Spenser, F. Q. b. i. c. 1.  st. 9,\nThe laurel, meed of mighty conquerours\nAnd poets sage.\n\nv. 37.  Through that.]  \"Where the four circles, the horizon, the\nzodiac, the equator, and the equinoctial colure, join; the last\nthreeintersecting each other so as to form three crosses, as may\nbe seen in the armillary sphere.\"\n\nv. 39.  In happiest constellation.]  Aries.  Some understand the\nplanetVenus by the \"miglior stella \"\n\nv. 44.  To the left.]  Being in the opposite hemisphere to ours,\nBeatrice that she may behold the rising sun, turns herself to the\nleft.\n\nv. 47.  As from the first a second beam.]  \"Like a reflected\nsunbeam,\" which he compares to a pilgrim hastening homewards.\n\nNe simil tanto mal raggio secondo\nDal primo usci.\nFilicaja, canz. 15. st. 4.\n\nv. 58.  As iron that comes boiling from the fire.]  So Milton,\nP.  L.  b. iii.  594.\n--As glowing iron with fire.\n\nv. 69.  Upon the day appear\'d.\n\n--If the heaven had ywonne,\nAll new of God another sunne.\nChaucer, First Booke of Fame\n\nE par ch\' agginuga un altro sole al cielo.\nAriosto, O F.  c.  x.  st.  109.\n\nEd ecco un lustro lampeggiar d\' intorno\nChe sole a sole aggiunse e giorno a giorno.\nManno, Adone.  c. xi. st. 27.\n\nQuando a paro col sol ma piu lucente\nL\'angelo gli appari sull; oriente\nTasso, G. L. c. i.\n\n-Seems another morn\nRis\'n on mid-noon.\nMilton, P. L. b. v. 311.\n\nCompare Euripides, Ion. 1550.  [GREEK HERE]\n66");strcat(expected_filecontent5, "light,\nLight intellectual replete with love,\nLove of true happiness replete with joy,\nJoy, that transcends all sweetness of delight.\nHere shalt thou look on either mighty host\nOf Paradis");


            struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            
                    struct file_t* file0 = file_open(volume, "YARd");
                    test_error(file0 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file1 = file_open(volume, "CLAIM.TX");
                    test_error(file1 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file2 = file_open(volume, "CROp.tX");
                    test_error(file2 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file3 = file_open(volume, "STUDy.tXt");
                    test_error(file3 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file4 = file_open(volume, "WHeTHER.tx");
                    test_error(file4 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file5 = file_open(volume, "STREAMba.BIN");
                    test_error(file5 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
            
                size_t size0 = file_read(filecontent0, 1, 490, file0);
                test_error(size0 == 490, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 490 bajtów, a wczytała %lu", size0);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos0 = mem_find_first_difference(filecontent0, expected_filecontent0, 490);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos0 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos0, mem_get_byte(filecontent0, diff_pos0), mem_get_byte(expected_filecontent0, diff_pos0));
        
                onerror_compare_memory(expected_filecontent0, filecontent0, 490);
            
                size_t size1 = file_read(filecontent1, 1, 2474, file1);
                test_error(size1 == 2474, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2474 bajtów, a wczytała %lu", size1);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos1 = mem_find_first_difference(filecontent1, expected_filecontent1, 2474);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos1 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos1, mem_get_byte(filecontent1, diff_pos1), mem_get_byte(expected_filecontent1, diff_pos1));
        
                onerror_compare_memory(expected_filecontent1, filecontent1, 2474);
            
                size_t size2 = file_read(filecontent2, 1, 3376, file2);
                test_error(size2 == 3376, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3376 bajtów, a wczytała %lu", size2);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos2 = mem_find_first_difference(filecontent2, expected_filecontent2, 3376);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos2 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos2, mem_get_byte(filecontent2, diff_pos2), mem_get_byte(expected_filecontent2, diff_pos2));
        
                onerror_compare_memory(expected_filecontent2, filecontent2, 3376);
            
                size_t size3 = file_read(filecontent3, 1, 1593, file3);
                test_error(size3 == 1593, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1593 bajtów, a wczytała %lu", size3);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos3 = mem_find_first_difference(filecontent3, expected_filecontent3, 1593);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos3 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos3, mem_get_byte(filecontent3, diff_pos3), mem_get_byte(expected_filecontent3, diff_pos3));
        
                onerror_compare_memory(expected_filecontent3, filecontent3, 1593);
            
                size_t size4 = file_read(filecontent4, 1, 3584, file4);
                test_error(size4 == 3584, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3584 bajtów, a wczytała %lu", size4);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos4 = mem_find_first_difference(filecontent4, expected_filecontent4, 3584);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos4 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos4, mem_get_byte(filecontent4, diff_pos4), mem_get_byte(expected_filecontent4, diff_pos4));
        
                onerror_compare_memory(expected_filecontent4, filecontent4, 3584);
            
                size_t size5 = file_read(filecontent5, 1, 186, file5);
                test_error(size5 == 186, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 186 bajtów, a wczytała %lu", size5);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos5 = mem_find_first_difference(filecontent5, expected_filecontent5, 186);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos5 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos5, mem_get_byte(filecontent5, diff_pos5), mem_get_byte(expected_filecontent5, diff_pos5));
        
                onerror_compare_memory(expected_filecontent5, filecontent5, 186);
            

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
    
            char *filecontent = (char *)calloc(490, 1);
            char expected_filecontent[491] = "";

            strcat(expected_filecontent, "thy voice.\"\n     There stood I like the friar, that doth shrive\nA wretch for murder doom\'d, who e\'en when fix\'d,\nCalleth him back, whence death awhile delays.\n     He shouted:  \"Ha! already standest there?\nAlready standest there, O Boniface!\nBy many a year the writing play\'d me false.\nSo early dost thou surfeit with the wealth,\nFor which thou fearedst not in guile to take\nThe lovely lady, and then mangle her?\"\n     I felt as those who, piercing not the drift\nOf answer made them, stand ");

            struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "yaRD");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 111, SEEK_SET);
        
            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[111] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[111], c);

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
    
            char *filecontent = (char *)calloc(3584, 1);
            char expected_filecontent[3585] = "";

            strcat(expected_filecontent, "with the change.  In that abyss\nOf radiance, clear and lofty, seem\'d methought,\nThree orbs of triple hue clipt in one bound:\nAnd, from another, one reflected seem\'d,\nAs rainbow is from rainbow: and the third\nSeem\'d fire, breath\'d equally from both.  Oh speech\nHow feeble and how faint art thou, to give\nConception birth!  Yet this to what I saw\nIs less than little.  Oh eternal light!\nSole in thyself that dwellst; and of thyself\nSole understood, past, present, or to come!\nThou smiledst; on that circling, which in thee\nSeem\'d as reflected splendour, while I mus\'d;\nFor I therein, methought, in its own hue\nBeheld our image painted: steadfastly\nI therefore por\'d upon the view.  As one\nWho vers\'d in geometric lore, would fain\nMeasure the circle; and, though pondering long\nAnd deeply, that beginning, which he needs,\nFinds not; e\'en such was I, intent to scan\nThe novel wonder, and trace out the form,\nHow to the circle fitted, and therein\nHow plac\'d: but the flight was not for my wing;\nHad not a flash darted athwart my mind,\nAnd in the spleen unfolded what it sought.\n     Here vigour fail\'d the tow\'ring fantasy:\nBut yet the will roll\'d onward, like a wheel\nIn even motion, by the Love impell\'d,\nThat moves the sun in heav\'n and all the stars.\n\n\nNOTES TO PARADISE\n\n\nCANTO 1\n\nVerse 12.  Benign Apollo.]  Chaucer has imitated this invention\nvery closely at the beginning of the Third Booke of Fame.\n\nIf, divine vertue, thou\nWilt helpe me to shewe  now\nThat in my head ymarked is,\n     * * * * *\nThou shalt see me go as blive\nUnto the next laurer I see,\nAnd kisse it for it is thy tree\nNow entre thou my breast anone.\n\nv. 15.  Thus for.]  He appears to mean nothing more than that\nthis part of his poem will require a greater exertion of his\npowers than the former.\n\nv. 19.  Marsyas.]  Ovid, Met. 1. vi. fab. 7.  Compare Boccaccio,\nII Filocopo, 1.  5. p. 25. v. ii. Ediz.  Fir.  1723.  \"Egli nel\nmio petto entri,\" &c. - \"May he enter my bosom, and let my voice\nsound like his own, when he made that daring mortal deserve to\ncome forth unsheathed from his limbs. \"\nv. 29.  Caesar, or bard.]  So Petrarch, Son.  Par. Prima.\n\nArbor vittoriosa e trionfale,\nOnor d\'imperadori e di poeti.\n\nAnd Spenser, F. Q. b. i. c. 1.  st. 9,\nThe laurel, meed of mighty conquerours\nAnd poets sage.\n\nv. 37.  Through that.]  \"Where the four circles, the horizon, the\nzodiac, the equator, and the equinoctial colure, join; the last\nthreeintersecting each other so as to form three crosses, as may\nbe seen in the armillary sphere.\"\n\nv. 39.  In happiest constellation.]  Aries.  Some understand the\nplanetVenus by the \"miglior stella \"\n\nv. 44.  To the left.]  Being in the opposite hemisphere to ours,\nBeatrice that she may behold the rising sun, turns herself to the\nleft.\n\nv. 47.  As from the first a second beam.]  \"Like a reflected\nsunbeam,\" which he compares to a pilgrim hastening homewards.\n\nNe simil tanto mal raggio secondo\nDal primo usci.\nFilicaja, canz. 15. st. 4.\n\nv. 58.  As iron that comes boiling from the fire.]  So Milton,\nP.  L.  b. iii.  594.\n--As glowing iron with fire.\n\nv. 69.  Upon the day appear\'d.\n\n--If the heaven had ywonne,\nAll new of God another sunne.\nChaucer, First Booke of Fame\n\nE par ch\' agginuga un altro sole al cielo.\nAriosto, O F.  c.  x.  st.  109.\n\nEd ecco un lustro lampeggiar d\' intorno\nChe sole a sole aggiunse e giorno a giorno.\nManno, Adone.  c. xi. st. 27.\n\nQuando a paro col sol ma piu lucente\nL\'angelo gli appari sull; oriente\nTasso, G. L. c. i.\n\n-Seems another morn\nRis\'n on mid-noon.\nMilton, P. L. b. v. 311.\n\nCompare Euripides, Ion. 1550.  [GREEK HERE]\n66");

            struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "WHETHER.TX");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, -1148, SEEK_END);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[2436] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[2436], c);

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
    
            char *filecontent = (char *)calloc(1593, 1);
            char expected_filecontent[1594] = "";

            strcat(expected_filecontent, "n idle play.\"\n     Such were the words that Beatrice spake:\nThese ended, to that region, where the world\nIs liveliest, full of fond desire she turn\'d.\n     Though mainly prompt new question to propose,\nHer silence and chang\'d look did keep me dumb.\nAnd as the arrow, ere the cord is still,\nLeapeth unto its mark; so on we sped\nInto the second realm.  There I beheld\nThe dame, so joyous enter, that the orb\nGrew brighter at her smiles; and, if the star\nWere mov\'d to gladness, what then was my cheer,\nWhom nature hath made apt for every change!\n     As in a quiet and clear lake the fish,\nIf aught approach them from without, do draw\nTowards it, deeming it their food; so drew\nFull more than thousand splendours towards us,\nAnd in each one was heard:  \"Lo!  one arriv\'d\nTo multiply our loves!\" and as each came\nThe shadow, streaming forth effulgence new,\nWitness\'d augmented joy.  Here, reader!  think,\nIf thou didst miss the sequel of my tale,\nTo know the rest how sorely thou wouldst crave;\nAnd thou shalt see what vehement desire\nPossess\'d me, as soon as these had met my view,\nTo know their state.  \"O born in happy hour!\nThou to whom grace vouchsafes, or ere thy close\nOf fleshly warfare, to behold the thrones\nOf that eternal triumph, know to us\nThe light communicated, which through heaven\nExpatiates without bound.  Therefore, if aught\nThou of our beams wouldst borrow for thine aid,\nSpare not; and of our radiance take thy fill.\"\n     Thus of those piteous spirits one bespake me;\nAnd Beatrice next:  \"Say on; and trust\nAs unto gods!\" --\"How in the light supreme\nThou harbour\'st, and f");

            struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "sTUDY.TxT");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 353, SEEK_SET);
            file_seek(file, 913, SEEK_CUR);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[1266] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[1266], c);

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
    

                 struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\THEir\\mATTer\\SpREaD");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\ThEIr\\MATTER\\SPREaD) jest nazwą katalogu, a nie pliku");
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
    

                 struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\VIeW\\hARd\\resULT\\cOOK");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\vIeW\\HARD\\RESulT\\COok) jest nazwą katalogu, a nie pliku");
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
    

                 struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\THEIR\\ToGETHER\\SCHOOL\\wHy");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\tHEIR\\TOGETheR\\sCHOOl\\WHY) jest nazwą katalogu, a nie pliku");
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
    

                 struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\VIEW\\HARD\\BELIEVE");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\ViEW\\HArD\\bEliEVE) jest nazwą katalogu, a nie pliku");
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
    

                 struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\MUCHEiTH\\STEP");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\muCHeItH\\STEp) jest nazwą katalogu, a nie pliku");
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
    

                 struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\tHEiR\\TogETHER\\STORe");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\THEIR\\TOgETheR\\SToRe) jest nazwą katalogu, a nie pliku");
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
    

                 struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\DO\\MARK");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\do\\mArk) jest nazwą katalogu, a nie pliku");
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
    

                 struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\MUCHEITH\\STep");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\MUCHEITH\\stEP) jest nazwą katalogu, a nie pliku");
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
    

                 struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\THEir\\SUbJECT\\DRiVE");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\ThEIR\\SUBJeCt\\DRIVE) jest nazwą katalogu, a nie pliku");
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
    

                 struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\tHEiR\\tOGETHER\\EVEN\\Add");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\THEIr\\toGEtHER\\EvEN\\ADD) jest nazwą katalogu, a nie pliku");
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
    

                 struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\mUcHeITH\\STep\\PoSITION");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\MUCheITH\\StEP\\PosiTIoN) jest nazwą katalogu, a nie pliku");
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
    

                 struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "ALL");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (aLl) jest nazwą katalogu, a nie pliku");
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
    

                 struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "VIEW");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (VieW) jest nazwą katalogu, a nie pliku");
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
    

                 struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "Do");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (DO) jest nazwą katalogu, a nie pliku");
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
    

                 struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "SIMPLE");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (SIMPLE) jest nazwą katalogu, a nie pliku");
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
    

                 struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "RUB");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (RUb) jest nazwą katalogu, a nie pliku");
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
//  Test 91: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST91(void)
{
    // informacje o teście
    test_start(91, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "THEIR");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (THeiR) jest nazwą katalogu, a nie pliku");
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
//  Test 92: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST92(void)
{
    // informacje o teście
    test_start(92, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "MUCHEITH");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (MUCHEITh) jest nazwą katalogu, a nie pliku");
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
//  Test 93: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST93(void)
{
    // informacje o teście
    test_start(93, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "KNOW");
            test_error(file == NULL, "Funkcja file_open() nie powinna otworzyć pliku o nazwie KNOW, ponieważ nie istnieje on w katalogu głównym");
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
//  Test 94: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST94(void)
{
    // informacje o teście
    test_start(94, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(NULL, "kNow");
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
    

            struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
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
//  Test 96: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST96(void)
{
    // informacje o teście
    test_start(96, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
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
//  Test 97: Sprawdzanie poprawności działania funkcji file_close
//
void UTEST97(void)
{
    // informacje o teście
    test_start(97, "Sprawdzanie poprawności działania funkcji file_close", __LINE__);

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
//  Test 98: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST98(void)
{
    // informacje o teście
    test_start(98, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "YARD");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int res = file_read(NULL, 1, 1, file);
            test_error(res == -1, "Funkcja file_read() powinna zwrócić wartość -1, a zwróciła %d", res);
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
//  Test 99: Sprawdzanie poprawności działania funkcji dir_read
//
void UTEST99(void)
{
    // informacje o teście
    test_start(99, "Sprawdzanie poprawności działania funkcji dir_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char* expected_names[13] = { "YARD", "CLAIM.TX", "CROP.TX", "STUDY.TXT", "WHETHER.TX", "STREAMBA.BIN", "ALL", "VIEW", "DO", "SIMPLE", "RUB", "THEIR", "MUCHEITH" };
            int found_names[13] = { 0 };

            struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t* pdir = dir_open(volume, "\\");
            test_error(pdir != NULL, "Funkcja dir_open() niepoprawnie otworzyła katalog");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            for (int i = 0; i < 13; ++i)
            {
                struct dir_entry_t entry;
                int res = dir_read(pdir, &entry);
                test_error(res == 0, "Funkcja dir_read() niepoprawnie odczytała wpis z katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int name_found = 0;

                for (int j = 0; j < 13; ++j)
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
//  Test 100: Sprawdzanie poprawności działania funkcji dir_read
//
void UTEST100(void)
{
    // informacje o teście
    test_start(100, "Sprawdzanie poprawności działania funkcji dir_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char* expected_names[44] = { "SAY.TXT", "DAY", "CAPITAL.TX", "LAST", "SUBSTANC.BIN", "VALLEY.BIN", "HOT.TX", "CLEAR", "FOUND", "QUESTION.BIN", "HOT.TXT", "EVENING.TX", "FAST.BIN", "HOME", "WALK.TXT", "EASE.TXT", "PITCH.BIN", "FAIR", "RANGE.BIN", "KEPT", "SOLUTION", "RUN.TX", "FELL", "FEAR.BIN", "RED.TX", "TROUBLE.BIN", "LIST", "ROUND.TXT", "SECTION.TX", "BRING.TX", "DEEP", "ARRANGE", "ONLY", "FORWARD", "CAMP", "MONEY", "NO", "MISS", "GOLD", "LOT", "PAY", "DIFFER", ".", ".." };
            int found_names[44] = { 0 };

            struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t* pdir = dir_open(volume, "\\RUB");
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
//  Test 101: Sprawdzanie poprawności działania funkcji dir_read
//
void UTEST101(void)
{
    // informacje o teście
    test_start(101, "Sprawdzanie poprawności działania funkcji dir_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char* expected_names[7] = { "GREW.TXT", "LENGTH.BIN", "THICK.TXT", "ICE.TXT", "BRANCH", ".", ".." };
            int found_names[7] = { 0 };

            struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t* pdir = dir_open(volume, "\\thEIR\\TOGEtHER\\.\\GeNEraL\\..\\GENERAl\\MULTIPLY");
            test_error(pdir != NULL, "Funkcja dir_open() niepoprawnie otworzyła katalog");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            for (int i = 0; i < 7; ++i)
            {
                struct dir_entry_t entry;
                int res = dir_read(pdir, &entry);
                test_error(res == 0, "Funkcja dir_read() niepoprawnie odczytała wpis z katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int name_found = 0;

                for (int j = 0; j < 7; ++j)
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
    

                        struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\aLL\\eACh\\BOUghT\\HUNDrED\\MILK\\OF");
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
    

                        struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\tHEIr\\TOgEtHeR\\NEIGhBOr\\gAS.BiN");
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
    

                        struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\viEW\\SeED\\hAs\\REQUIRE\\PLant\\mAN.TXT");
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
    

                        struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\All\\EACH\\BOuGHT\\HUNDRED\\PLANEt\\CHICK.BIN");
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
    

                        struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\ruB\\mONEY\\RoSE\\feET\\BranCh");
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
    

                        struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\ViEw\\SEED\\gaVE\\IN\\LeNgTH\\AS.BiN");
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
    

                        struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\RUB\\CaMP\\OR\\heR\\BEaT");
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
    

                        struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\RUB\\MONeY\\ROSe\\TEST\\feW.TxT");
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
    

                        struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\RUB\\cAmp\\OR\\HER\\STrAIghT");
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
    

                        struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\DO\\mArK\\rAIL\\fINd");
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
    

                        struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\THEIr\\TOGEtHER\\OFf\\FiVE\\SMAlL");
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
    

                        struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\ThEIR\\OwN\\fRIEND.TX");
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
    

                        struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\ALL\\eACH\\SILVEr\\COOK");
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
    

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "YARD");
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
    

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "ClAIM.TX");
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
    

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "CROP.tx");
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
//  Test 118: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST118(void)
{
    // informacje o teście
    test_start(118, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "StUDY.tXT");
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
//  Test 119: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST119(void)
{
    // informacje o teście
    test_start(119, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "whETHeR.tx");
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
//  Test 120: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST120(void)
{
    // informacje o teście
    test_start(120, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "STREAMbA.bIN");
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
//  Test 121: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST121(void)
{
    // informacje o teście
    test_start(121, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("phrase_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t*  dir = dir_open(volume, "posiTioN");
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
            UTEST91, // Sprawdzanie poprawności działania funkcji file_open
            UTEST92, // Sprawdzanie poprawności działania funkcji file_open
            UTEST93, // Sprawdzanie poprawności działania funkcji file_open
            UTEST94, // Sprawdzanie poprawności działania funkcji file_read
            UTEST95, // Sprawdzanie poprawności działania funkcji file_read
            UTEST96, // Sprawdzanie poprawności działania funkcji file_read
            UTEST97, // Sprawdzanie poprawności działania funkcji file_close
            UTEST98, // Sprawdzanie poprawności działania funkcji file_read
            UTEST99, // Sprawdzanie poprawności działania funkcji dir_read
            UTEST100, // Sprawdzanie poprawności działania funkcji dir_read
            UTEST101, // Sprawdzanie poprawności działania funkcji dir_read
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
            UTEST118, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST119, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST120, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST121, // Sprawdzanie poprawności działania funkcji dir_open
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
            test_summary(121); // wszystkie testy muszą zakończyć się sukcesem
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