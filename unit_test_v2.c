/*
 * Unit Test Bootstrap
 * Autor: Tomasz Jaworski, 2018-2020
 *
 * Test dla zadania Projekt: czytnik dysku, woluminu, katalogu głównego i plików (3,0)
 * Autor testowanej odpowiedzi: Sebastian Derendarz
 * Test wygenerowano automatycznie o 2020-11-30 09:35:22.237776
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
    


            struct disk_t* disk = disk_open_from_file("FOREST.TX");
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
    


            struct disk_t* disk = disk_open_from_file("the.img");
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
    
        
                char *filecontent = (char *)calloc(31, 1);
                char expected_filecontent[32] = "";
        
                strcat(expected_filecontent, "hose lively clearness far\nSurpa");
                
        
                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "SUN.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 31, file);
                test_error(size == 31, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 31 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 31);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 31);


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
    
        
                char *filecontent = (char *)calloc(1788, 1);
                char expected_filecontent[1789] = "";
        
                strcat(expected_filecontent, "Thaumantian.]  Figlia di Taumante\n[GREEK HERE]\n\nCompare Plato, Theaet.  v. ii.  p. 76.  Bip.  edit., Virg; Aen.\nix. 5, and Spenser, Faery Queen, b. v. c. 3.  st. 25.\n\nv. 85.  The name.]  The name of Poet.\n\nv. 89.  From Tolosa.]  Dante, as many others have done, confounds\nStatius the poet, who was a Neapolitan, with a rhetorician of the\nsame name, who was of Tolosa, or Thoulouse.  Thus Chaucer, Temple\nof Fame, b. iii. The Tholason, that height Stace.\n\nv. 94.  Fell.]  Statius lived to write only a small part of the\nAchilleid.\n\nCANTO XXII\n\nv. 5.  Blessed.]  Matt.  v. 6.\n\nv. 14.  Aquinum\'s bard.]  Juvenal had celebrated his contemporary\nStatius, Sat. vii.  82; though some critics imagine that there is\na secret derision couched under his praise.\n\nv. 28.  Why.]  Quid non mortalia pecaora cogis\nAnri sacra fames?\nVirg. Aen. 1. iii. 57\n\nVenturi supposes that Dante might have mistaken the meaning of\nthe word sacra, and construed it \"holy,\" instead of \"cursed.\"\nBut I see no necessity for having recourse to so improbable a\nconjecture.\n\nv. 41.  The fierce encounter.]  See Hell, Canto VII.  26.\n\nv. 46.  With shorn locks.]  Ibid.  58.\n\nv. 57.  The twin sorrow of Jocasta\'s womb.]  Eteocles and\nPolynices\n\nv. 71.  A renovated world.]  Virg.  Ecl.  iv. 5\n\nv. 100.  That Greek.]  Homer\n\nv. 107.  Of thy train. ]  Of those celebrated in thy Poem.\"\n\nv. 112.  Tiresias\' daughter.]  Dante appears to have forgotten\nthat he had placed Manto, the daughter of Tiresias, among the\nsorcerers. See Hell Canto XX.  Vellutello endeavours, rather\nawkwardly, to reconcile the inconsistency, by observing, that\nalthough she was placed there as a sinner, yet, as one of famous\nmemory, she had also a place among the worthies in Limbo.\n\nLombardi excuses our author better, by observing that Tiresias\nhad a");
                
        
                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "USUAL.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 1788, file);
                test_error(size == 1788, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1788 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 1788);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 1788);


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
    
        
                char *filecontent = (char *)calloc(2985, 1);
                char expected_filecontent[2986] = "";
        
                strcat(expected_filecontent, "ndro and Napoleone, sons of\nAlberto Alberti, who murdered each other.  They were proprietors\nof the valley of Falterona, where the Bisenzio has its source, a\nriver that falls into the Arno about six miles from Florence.\n\nv. 59.  Not him,]  Mordrec, son of King Arthur.\n\nv. 60. Foccaccia.]  Focaccia of Cancellieri, (the Pistoian\nfamily) whose atrocious act of revenge against his uncle is said\nto have given rise to the parties of the Bianchi and Neri, in the\nyear 1300. See G. Villani, Hist. l, viii. c. 37. and\nMacchiavelli, Hist. l. ii. The account of the latter writer\ndiffers much from that given by Landino in his Commentary.\n\nv. 63.  Mascheroni.]  Sassol Mascheroni, a Florentiue, who also\nmurdered his uncle.\n\nv. 66.  Camiccione.]  Camiccione de\' Pazzi of Valdarno, by whom\nhis kinsman Ubertino was treacherously pnt to death.\n\nv. 67.  Carlino.]  One of the same family.  He betrayed the\nCastel di Piano Travigne, in Valdarno, to the Florentines, after\nthe refugees of the Bianca and Ghibelline party had defended it\nagainst a siege for twenty-nine days, in the summer of 1302.  See\nG. Villani, l. viii. c. 52 and Dino Compagni, l. ii.\n\nv. 81. Montaperto.] The defeat of the Guelfi at Montaperto,\noccasioned by the treachery of Bocca degli Abbati, who, during\nthe engagement, cut off the hand of Giacopo del Vacca de\'Pazzi,\nbearer of the Florentine standard.  G. Villani, l. vi. c. 80, and\nNotes to Canto X.  This event happened in 1260.\n\nv. 113.  Him of Duera.]  Buoso of Cremona, of the family of\nDuera, who was bribed by Guy de Montfort, to leave a pass between\nPiedmont and Parma, with the defence of which he had been\nentrusted by the Ghibellines, open to the army of Charles of\nAnjou, A.D. 1265, at which the people of Cremona were so enraged,\nthat they extirpated the whole family.  G. Villani, l. vii. c. 4.\n\nv. 118.  Beccaria.]  Abbot of Vallombrosa, who was the Pope\'s\nLegate at Florence, where his intrigues in favour of the\nGhibellines being discovered, he was beheaded. I do not find the\noccurrence in Vallini, nor do the commentators say to what pope\nhe was legate. By Landino he is reported to have been from Parma,\nby Vellutello from Pavia.\n\nv. 118.  Soldanieri.]  \"Gianni Soldanieri,\"  says Villani, Hist.\nl. vii. c14, \"put himself at the head of the people, in the hopes\nof rising into power, not aware that the result would be mischief\nto the Ghibelline party, and his own ruin; an event which seems\never to have befallen him, who has headed the populace in\nFlorence.\" A.D. 1266.\n\nv. 119.  Ganellon.]  The betrayer of Charlemain, mentioned by\nArchbishop Turpin.  He is a common instance of treachery with the\npoets of the middle ages.\n        Trop son fol e mal pensant,\n        Pis valent que Guenelon.\n               Thibaut, roi de Navarre\n        O new Scariot, and new Ganilion,\n        O false dissembler, &c.\n               Chaucer, Nonne\'s Prieste\'s Tale\nAnd in the Monke\'s Tale, Peter of Spaine.\nv. 119.  Tribaldello.]  Tribaldello de\'Manfredi, who ");
                
        
                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "THEIR.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 2985, file);
                test_error(size == 2985, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2985 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2985);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 2985);


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
    
        
                char *filecontent = (char *)calloc(3072, 1);
                char expected_filecontent[3073] = "";
        
                strcat(expected_filecontent, "was the second emperor of the house of Saab; and his\nson Frederick II \"the third and last.\"\n\nCANTO IV\n\nv. 6.  Between two deer]\n\nTigris ut auditis, diversa valle duorum\nExtimulata fame, mugitibus armentorum\nNeseit utro potius ruat, et ruere ardet utroque.\nOvid, Metam. 1. v. 166\n\nv. 13.  Daniel.]  See Daniel, c. ii.\n\nv. 24.  Plato.]  [GREEK HERE]  Plato Timaeus v. ix.  p. 326.\nEdit. Bip.  \"The Creator, when he had framed the universe,\ndistributed to the stars an equal number of souls, appointing to\neach soul its several star.\"\n\nv. 27.  Of that.]  Plato\'s opinion.\n\nv. 34.  The first circle.]  The empyrean.\n\nv. 48.  Him who made Tobias whole.]\n\nRaphael, the sociable spirit, that deign\'d\nTo travel with Tobias, and secur\'d\nHis marriage with the sev\'n times wedded maid,\nMilton, P. L. b. v. 223.\n\nv. 67.  That to the eye of man.]  \"That the ways of divine\njustice are often inscrutable to man, ought rather to be a motive\nto faith than an inducement to heresy.\" Such appears to me the\nmost satisfactory explanation of the passage.\n\nv. 82.  Laurence.]  Who suffered martyrdom in the third century.\n\nv. 82.  Scaevola.]  See Liv.  Hist. D. 1.  1. ii. 12.\n\nv. 100.  Alcmaeon.] Ovid, Met.  1. ix. f. 10.\n\n--Ultusque parente parentem\nNatus, erit facto pius et sceleratus eodem.\n\nv. 107.  Of will.]  \"What Piccarda asserts of Constance, that she\nretained her affection to the monastic life, is said absolutely\nand without relation to circumstances; and that which I affirm is\nspoken of the will conditionally and respectively: so that our\napparent difference is without any disagreement.\"\nv. 119.  That truth.]  The light of divine truth.\n\nCANTO V\n\nv. 43.  Two things.]  The one, the substance of the vow; the\nother, the compact, or form of it.\n\nv. 48.  It was enjoin\'d the Israelites.]  See Lev. e. xii, and\nxxvii.\n\nv. 56.  Either key.]  Purgatory, Canto IX.  108.\n\nv. 86.  That region.]  As some explain it, the east, according to\nothers the equinoctial line.\n\nv. 124.  This sphere.]  The planet Mercury, which, being nearest\nto the sun, is oftenest hidden by that luminary\n\nCANTO VI\n\nv. 1.  After that Constantine the eagle turn\'d.]  Constantine,\nin transferring the seat of empire from Rome to Byzantium,\ncarried the eagle, the Imperial ensign, from the west to the\neast. Aeneas, on the contrary had moved along with the sun\'s\ncourse, when he passed from Troy to Italy.\n\nv. 5.  A hundred years twice told and more.]  The Emperor\nConstantine entered Byzantium in 324, and Justinian began his\nreign in 527.\n\nv. 6.  At Europe\'s extreme point.]  Constantinople being situated\nat the extreme of Europe, and on the borders of Asia, near those\nmountains\nin the neighbourhood of Troy, from whence the first founders of\nRome had emigrated.\n\nv. 13.  To clear th\' incumber\'d laws.]  The code of laws was\nabridged and reformed by Justinian.\n\nv. 15.  Christ\'s nature merely human.]  Justinian is said to have\nbeen a follower of the heretical Opinions held by Eutyches,\" who\ntaught that in Christ there was but one nature, viz. that of the\nincarnate word.\"\nMaclaine\'s Mosheim, t. ii.  ");
                
        
                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "WATCH.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 3072, file);
                test_error(size == 3072, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3072 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3072);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 3072);


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
    
        
                char *filecontent = (char *)calloc(2525, 1);
                char expected_filecontent[2526] = "";
        
                strcat(expected_filecontent, "     To which I thus: \" In mourning and in woe,\nCurs\'d spirit!  tarry thou. I know thee well,\nE\'en thus in filth disguis\'d.\"  Then stretch\'d he forth\nHands to the bark; whereof my teacher sage\nAware, thrusting him back: \"Away!  down there\nTo the\' other dogs!\"  then, with his arms my neck\nEncircling, kiss\'d my cheek, and spake: \"O soul\nJustly disdainful!  blest was she in whom\nThou was conceiv\'d!  He in the world was one\nFor arrogance noted; to his memory\nNo virtue lends its lustre; even so\nHere is his shadow furious.  There above\nHow many now hold themselves mighty kings\nWho here like swine shall wallow in the mire,\nLeaving behind them horrible dispraise!\"\n     I then: \"Master!  him fain would I behold\nWhelm\'d in these dregs, before we quit the lake.\"\n     He thus: \"Or ever to thy view the shore\nBe offer\'d, satisfied shall be that wish,\nWhich well deserves completion.\"  Scarce his words\nWere ended, when I saw the miry tribes\nSet on him with such violence, that yet\nFor that render I thanks to God and praise\n\"To Filippo Argenti:\" cried they all:\nAnd on himself the moody Florentine\nTurn\'d his avenging fangs.  Him here we left,\nNor speak I of him more.  But on mine ear\nSudden a sound of lamentation smote,\nWhereat mine eye unbarr\'d I sent abroad.\n     And thus the good instructor: \"Now, my son!\nDraws near the city, that of Dis is nam\'d,\nWith its grave denizens, a mighty throng.\"\n     I thus: \"The minarets already, Sir!\nThere certes in the valley I descry,\nGleaming vermilion, as if they from fire\nHad issu\'d.\"  He replied: \"Eternal fire,\nThat inward burns, shows them with ruddy flame\nIllum\'d; as in this nether hell thou seest.\"\n     We came within the fosses deep, that moat\nThis region comfortless.  The walls appear\'d\nAs they were fram\'d of iron.  We had made\nWide circuit, ere a place we reach\'d, where loud\nThe mariner cried vehement: \"Go forth!\nThe\' entrance is here!\"  Upon the gates I spied\nMore than a thousand, who of old from heaven\nWere hurl\'d.  With ireful gestures, \"Who is this,\"\nThey cried, \"that without death first felt, goes through\nThe regions of the dead?\"  My sapient guide\nMade sign that he for secret parley wish\'d;\nWhereat their angry scorn abating, thus\nThey spake: \"Come thou alone; and let him go\nWho hath so hardily enter\'d this realm.\nAlone return he by his witless way;\nIf well he know it, let him prove.  For thee,\nHere shalt thou tarry, who through clime so dark\nHast been his escort.\" Now bethink thee, reader!\nWhat cheer was mine at sound of those curs\'d words.\nI did be");
                
        
                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "BAD.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 2525, file);
                test_error(size == 2525, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2525 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2525);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 2525);


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
    
        
                char *filecontent = (char *)calloc(2409, 1);
                char expected_filecontent[2410] = "";
        
                strcat(expected_filecontent, "s birthplace,\nCallaroga; his father and mother\'s names, Felix and Joanna, his\nmother\'s dream; his name of Dominic, given him in consequence of\na vision by a noble matron, who stood sponsor to him, are all\ntold in an anonymous life of the saint, said to be written in the\nthirteenth century, and published by Quetif and Echard,\nScriptores Ordinis Praedicatorum.  Par.  1719. fol. t 1.  p. 25.\nThese writers deny his having been an inquisitor, and indeed the\nestablishment of the inquisition itself before the fourth Lateran\ncouncil.  Ibid.  p. 88.\n\nv. 55.  In the mother\'s womb.]  His mother, when pregnant with\nhim, is said to have dreamt that she should bring forth a white\nand black dog, with a lighted torch in its mouth.\n\nv. 59.  The dame.]  His godmother\'s dream was, that he had one\nstar in his forehead, and another in the nape of his neck, from\nwhich he communicated light to the east and the west.\n\nv. 73.  Felix.]  Felix Gusman.\n\nv. 75.  As men interpret it.]  Grace or gift of the Lord.\n\nv. 77.  Ostiense.]  A cardinal, who explained the decretals.\n\nv. 77.  Taddeo.]  A physician, of Florence.\n\nv. 82.  The see.]  \"The apostolic see, which no longer continues\nits wonted liberality towards the indigent and deserving; not\nindeed  through its own fault, as its doctrines are still the\nsame, but through the fault of the pontiff, who is seated in it.\"\n\nv. 85.  No dispensation.]  Dominic did not ask license to\ncompound for the use of unjust acquisitions, by dedicating a part\nof them to pious purposes.\n\nv. 89.  In favour of that seed.]  \"For that seed of the divine\nword, from which have sprung up these four-and-twenty plants,\nthat now environ thee.\"\n\nv. 101.  But the track.]  \"But the rule of St. Francis is already\ndeserted and the lees of the wine are turned into mouldiness.\"\n\nv. 110.  Tares.]  He adverts to the parable of the taxes and the\nwheat.\n\nv. 111.  I question not.]  \"Some indeed might be found, who still\nobserve the rule of the order, but such would come neither from\nCasale nor Acquasparta:\" of the former of which places was\nUberto, one master general, by whom the discipline had been\nrelaxed; and of the latter, Matteo, another, who had enforced it\nwith unnecessary rigour.\n\nv. 121.  -Illuminato here,\nAnd Agostino.]\nTwo among the earliest followers of St. Francis.\n\nv. 125.  Hugues of St. Victor.]  A Saxon of the monastery of\nSaint  Victor at Paris, who fed ill 1142 at the a");
                
        
                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "LONE.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 2409, file);
                test_error(size == 2409, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2409 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2409);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 2409);


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
    
        
                char *filecontent = (char *)calloc(3212, 1);
                char expected_filecontent[3213] = "";
        
                strcat(expected_filecontent, "thus spake:\n\"Contingency, unfolded not to view\nUpon the tablet of your mortal mold,\nIs all depictur\'d in the\' eternal sight;\nBut hence deriveth not necessity,\nMore then the tall ship, hurried down the flood,\nDoth from the vision, that reflects the scene.\nFrom thence, as to the ear sweet harmony\nFrom organ comes, so comes before mine eye\nThe time prepar\'d for thee.  Such as driv\'n out\nFrom Athens, by his cruel stepdame\'s wiles,\nHippolytus departed, such must thou\nDepart from Florence.  This they wish, and this\nContrive, and will ere long effectuate, there,\nWhere gainful merchandize is made of Christ,\nThroughout the livelong day.  The common cry,\nWill, as \'t is ever wont, affix the blame\nUnto the party injur\'d:  but the truth\nShall, in the vengeance it dispenseth, find\nA faithful witness.  Thou shall leave each thing\nBelov\'d most dearly:  this is the first shaft\nShot from the bow of exile.  Thou shalt prove\nHow salt the savour is of other\'s bread,\nHow hard the passage to descend and climb\nBy other\'s stairs, But that shall gall thee most\nWill he the worthless and vile company,\nWith whom thou must be thrown into these straits.\nFor all ungrateful, impious all and mad,\nShall turn \'gainst thee:  but in a little while\nTheirs and not thine shall be the crimson\'d brow\nTheir course shall so evince their brutishness\nT\' have ta\'en thy stand apart shall well become thee.\n     \"First refuge thou must find, first place of rest,\nIn the great Lombard\'s courtesy, who bears\nUpon the ladder perch\'d the sacred bird.\nHe shall behold thee with such kind regard,\nThat \'twixt ye two, the contrary to that\nWhich falls \'twixt other men, the granting shall\nForerun the asking.  With him shalt thou see\nThat mortal, who was at his birth impress\nSo strongly from this star, that of his deeds\nThe nations shall take note.  His unripe age\nYet holds him from observance; for these wheels\nOnly nine years have compass him about.\nBut, ere the Gascon practice on great Harry,\nSparkles of virtue shall shoot forth in him,\nIn equal scorn of labours and of gold.\nHis bounty shall be spread abroad so widely,\nAs not to let the tongues e\'en of his foes\nBe idle in its praise.  Look thou to him\nAnd his beneficence:  for he shall cause\nReversal of their lot to many people,\nRich men and beggars interchanging fortunes.\nAnd thou shalt bear this written in thy soul\nOf him, but tell it not; \"and things he told\nIncredible to those who witness them;\nThen added:  \"So interpret thou, my son,\nWhat hath been told thee.--Lo!  the ambushment\nThat a few circling seasons hide for thee!\nYet envy not thy neighbours: time extends\nThy span beyond their treason\'s chastisement.\"\n     Soon, as the saintly spirit, by his silence,\nHad shown the web, which I had streteh\'d for him\nUpon the warp, was woven, I began,\nAs one, who in perplexity desires\nCounsel of other, wise, benign and friendly:\n\"My father!  well I mark how time spurs on\nToward me, ready to inflict the blow,\nWhich falls most heavily on him, who most\nAbandoned himself.  Therefore \'t is good\nI should forecast, that driven from the place\nMost dear to me, I may not lose myself\nAll others by my song.  Down through the world\nOf infinite mourning, and along the mount\nFrom whose ");
                
        
                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "EDGE.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 3212, file);
                test_error(size == 3212, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3212 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3212);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 3212);


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
    
        
                char *filecontent = (char *)calloc(337, 1);
                char expected_filecontent[338] = "";
        
                strcat(expected_filecontent, " fly, yet ventures not to quit\nThe nest, and drops it; so in me desire\nOf questioning my guide arose, and fell,\nArriving even to the act, that marks\nA man prepar\'d for speech.  Him all our haste\nRestrain\'d not, but thus spake the sire belov\'d:\nFear not to speed the shaft, that on thy lip\nStands trembling for its flight.\"  Encourag\'d th");
                
        
                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "SMALLSPE");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 337, file);
                test_error(size == 337, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 337 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 337);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 337);


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
    

                char *filecontent = (char *)calloc(31, 1);
                char expected_filecontent[32] = "";

                strcat(expected_filecontent, "hose lively clearness far\nSurpa");

                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "SUN.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 191, file);
                test_error(size == 31, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 31 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 31);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 31);


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
    

                char *filecontent = (char *)calloc(1788, 1);
                char expected_filecontent[1789] = "";

                strcat(expected_filecontent, "Thaumantian.]  Figlia di Taumante\n[GREEK HERE]\n\nCompare Plato, Theaet.  v. ii.  p. 76.  Bip.  edit., Virg; Aen.\nix. 5, and Spenser, Faery Queen, b. v. c. 3.  st. 25.\n\nv. 85.  The name.]  The name of Poet.\n\nv. 89.  From Tolosa.]  Dante, as many others have done, confounds\nStatius the poet, who was a Neapolitan, with a rhetorician of the\nsame name, who was of Tolosa, or Thoulouse.  Thus Chaucer, Temple\nof Fame, b. iii. The Tholason, that height Stace.\n\nv. 94.  Fell.]  Statius lived to write only a small part of the\nAchilleid.\n\nCANTO XXII\n\nv. 5.  Blessed.]  Matt.  v. 6.\n\nv. 14.  Aquinum\'s bard.]  Juvenal had celebrated his contemporary\nStatius, Sat. vii.  82; though some critics imagine that there is\na secret derision couched under his praise.\n\nv. 28.  Why.]  Quid non mortalia pecaora cogis\nAnri sacra fames?\nVirg. Aen. 1. iii. 57\n\nVenturi supposes that Dante might have mistaken the meaning of\nthe word sacra, and construed it \"holy,\" instead of \"cursed.\"\nBut I see no necessity for having recourse to so improbable a\nconjecture.\n\nv. 41.  The fierce encounter.]  See Hell, Canto VII.  26.\n\nv. 46.  With shorn locks.]  Ibid.  58.\n\nv. 57.  The twin sorrow of Jocasta\'s womb.]  Eteocles and\nPolynices\n\nv. 71.  A renovated world.]  Virg.  Ecl.  iv. 5\n\nv. 100.  That Greek.]  Homer\n\nv. 107.  Of thy train. ]  Of those celebrated in thy Poem.\"\n\nv. 112.  Tiresias\' daughter.]  Dante appears to have forgotten\nthat he had placed Manto, the daughter of Tiresias, among the\nsorcerers. See Hell Canto XX.  Vellutello endeavours, rather\nawkwardly, to reconcile the inconsistency, by observing, that\nalthough she was placed there as a sinner, yet, as one of famous\nmemory, she had also a place among the worthies in Limbo.\n\nLombardi excuses our author better, by observing that Tiresias\nhad a");

                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "USUAL.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 1987, file);
                test_error(size == 1788, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1788 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 1788);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 1788);


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
    

                char *filecontent = (char *)calloc(2985, 1);
                char expected_filecontent[2986] = "";

                strcat(expected_filecontent, "ndro and Napoleone, sons of\nAlberto Alberti, who murdered each other.  They were proprietors\nof the valley of Falterona, where the Bisenzio has its source, a\nriver that falls into the Arno about six miles from Florence.\n\nv. 59.  Not him,]  Mordrec, son of King Arthur.\n\nv. 60. Foccaccia.]  Focaccia of Cancellieri, (the Pistoian\nfamily) whose atrocious act of revenge against his uncle is said\nto have given rise to the parties of the Bianchi and Neri, in the\nyear 1300. See G. Villani, Hist. l, viii. c. 37. and\nMacchiavelli, Hist. l. ii. The account of the latter writer\ndiffers much from that given by Landino in his Commentary.\n\nv. 63.  Mascheroni.]  Sassol Mascheroni, a Florentiue, who also\nmurdered his uncle.\n\nv. 66.  Camiccione.]  Camiccione de\' Pazzi of Valdarno, by whom\nhis kinsman Ubertino was treacherously pnt to death.\n\nv. 67.  Carlino.]  One of the same family.  He betrayed the\nCastel di Piano Travigne, in Valdarno, to the Florentines, after\nthe refugees of the Bianca and Ghibelline party had defended it\nagainst a siege for twenty-nine days, in the summer of 1302.  See\nG. Villani, l. viii. c. 52 and Dino Compagni, l. ii.\n\nv. 81. Montaperto.] The defeat of the Guelfi at Montaperto,\noccasioned by the treachery of Bocca degli Abbati, who, during\nthe engagement, cut off the hand of Giacopo del Vacca de\'Pazzi,\nbearer of the Florentine standard.  G. Villani, l. vi. c. 80, and\nNotes to Canto X.  This event happened in 1260.\n\nv. 113.  Him of Duera.]  Buoso of Cremona, of the family of\nDuera, who was bribed by Guy de Montfort, to leave a pass between\nPiedmont and Parma, with the defence of which he had been\nentrusted by the Ghibellines, open to the army of Charles of\nAnjou, A.D. 1265, at which the people of Cremona were so enraged,\nthat they extirpated the whole family.  G. Villani, l. vii. c. 4.\n\nv. 118.  Beccaria.]  Abbot of Vallombrosa, who was the Pope\'s\nLegate at Florence, where his intrigues in favour of the\nGhibellines being discovered, he was beheaded. I do not find the\noccurrence in Vallini, nor do the commentators say to what pope\nhe was legate. By Landino he is reported to have been from Parma,\nby Vellutello from Pavia.\n\nv. 118.  Soldanieri.]  \"Gianni Soldanieri,\"  says Villani, Hist.\nl. vii. c14, \"put himself at the head of the people, in the hopes\nof rising into power, not aware that the result would be mischief\nto the Ghibelline party, and his own ruin; an event which seems\never to have befallen him, who has headed the populace in\nFlorence.\" A.D. 1266.\n\nv. 119.  Ganellon.]  The betrayer of Charlemain, mentioned by\nArchbishop Turpin.  He is a common instance of treachery with the\npoets of the middle ages.\n        Trop son fol e mal pensant,\n        Pis valent que Guenelon.\n               Thibaut, roi de Navarre\n        O new Scariot, and new Ganilion,\n        O false dissembler, &c.\n               Chaucer, Nonne\'s Prieste\'s Tale\nAnd in the Monke\'s Tale, Peter of Spaine.\nv. 119.  Tribaldello.]  Tribaldello de\'Manfredi, who ");

                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "THEIR.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 3224, file);
                test_error(size == 2985, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2985 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2985);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 2985);


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
    

                char *filecontent = (char *)calloc(3072, 1);
                char expected_filecontent[3073] = "";

                strcat(expected_filecontent, "was the second emperor of the house of Saab; and his\nson Frederick II \"the third and last.\"\n\nCANTO IV\n\nv. 6.  Between two deer]\n\nTigris ut auditis, diversa valle duorum\nExtimulata fame, mugitibus armentorum\nNeseit utro potius ruat, et ruere ardet utroque.\nOvid, Metam. 1. v. 166\n\nv. 13.  Daniel.]  See Daniel, c. ii.\n\nv. 24.  Plato.]  [GREEK HERE]  Plato Timaeus v. ix.  p. 326.\nEdit. Bip.  \"The Creator, when he had framed the universe,\ndistributed to the stars an equal number of souls, appointing to\neach soul its several star.\"\n\nv. 27.  Of that.]  Plato\'s opinion.\n\nv. 34.  The first circle.]  The empyrean.\n\nv. 48.  Him who made Tobias whole.]\n\nRaphael, the sociable spirit, that deign\'d\nTo travel with Tobias, and secur\'d\nHis marriage with the sev\'n times wedded maid,\nMilton, P. L. b. v. 223.\n\nv. 67.  That to the eye of man.]  \"That the ways of divine\njustice are often inscrutable to man, ought rather to be a motive\nto faith than an inducement to heresy.\" Such appears to me the\nmost satisfactory explanation of the passage.\n\nv. 82.  Laurence.]  Who suffered martyrdom in the third century.\n\nv. 82.  Scaevola.]  See Liv.  Hist. D. 1.  1. ii. 12.\n\nv. 100.  Alcmaeon.] Ovid, Met.  1. ix. f. 10.\n\n--Ultusque parente parentem\nNatus, erit facto pius et sceleratus eodem.\n\nv. 107.  Of will.]  \"What Piccarda asserts of Constance, that she\nretained her affection to the monastic life, is said absolutely\nand without relation to circumstances; and that which I affirm is\nspoken of the will conditionally and respectively: so that our\napparent difference is without any disagreement.\"\nv. 119.  That truth.]  The light of divine truth.\n\nCANTO V\n\nv. 43.  Two things.]  The one, the substance of the vow; the\nother, the compact, or form of it.\n\nv. 48.  It was enjoin\'d the Israelites.]  See Lev. e. xii, and\nxxvii.\n\nv. 56.  Either key.]  Purgatory, Canto IX.  108.\n\nv. 86.  That region.]  As some explain it, the east, according to\nothers the equinoctial line.\n\nv. 124.  This sphere.]  The planet Mercury, which, being nearest\nto the sun, is oftenest hidden by that luminary\n\nCANTO VI\n\nv. 1.  After that Constantine the eagle turn\'d.]  Constantine,\nin transferring the seat of empire from Rome to Byzantium,\ncarried the eagle, the Imperial ensign, from the west to the\neast. Aeneas, on the contrary had moved along with the sun\'s\ncourse, when he passed from Troy to Italy.\n\nv. 5.  A hundred years twice told and more.]  The Emperor\nConstantine entered Byzantium in 324, and Justinian began his\nreign in 527.\n\nv. 6.  At Europe\'s extreme point.]  Constantinople being situated\nat the extreme of Europe, and on the borders of Asia, near those\nmountains\nin the neighbourhood of Troy, from whence the first founders of\nRome had emigrated.\n\nv. 13.  To clear th\' incumber\'d laws.]  The code of laws was\nabridged and reformed by Justinian.\n\nv. 15.  Christ\'s nature merely human.]  Justinian is said to have\nbeen a follower of the heretical Opinions held by Eutyches,\" who\ntaught that in Christ there was but one nature, viz. that of the\nincarnate word.\"\nMaclaine\'s Mosheim, t. ii.  ");

                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "WATCH.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 3440, file);
                test_error(size == 3072, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3072 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3072);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 3072);


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
    

                char *filecontent = (char *)calloc(2525, 1);
                char expected_filecontent[2526] = "";

                strcat(expected_filecontent, "     To which I thus: \" In mourning and in woe,\nCurs\'d spirit!  tarry thou. I know thee well,\nE\'en thus in filth disguis\'d.\"  Then stretch\'d he forth\nHands to the bark; whereof my teacher sage\nAware, thrusting him back: \"Away!  down there\nTo the\' other dogs!\"  then, with his arms my neck\nEncircling, kiss\'d my cheek, and spake: \"O soul\nJustly disdainful!  blest was she in whom\nThou was conceiv\'d!  He in the world was one\nFor arrogance noted; to his memory\nNo virtue lends its lustre; even so\nHere is his shadow furious.  There above\nHow many now hold themselves mighty kings\nWho here like swine shall wallow in the mire,\nLeaving behind them horrible dispraise!\"\n     I then: \"Master!  him fain would I behold\nWhelm\'d in these dregs, before we quit the lake.\"\n     He thus: \"Or ever to thy view the shore\nBe offer\'d, satisfied shall be that wish,\nWhich well deserves completion.\"  Scarce his words\nWere ended, when I saw the miry tribes\nSet on him with such violence, that yet\nFor that render I thanks to God and praise\n\"To Filippo Argenti:\" cried they all:\nAnd on himself the moody Florentine\nTurn\'d his avenging fangs.  Him here we left,\nNor speak I of him more.  But on mine ear\nSudden a sound of lamentation smote,\nWhereat mine eye unbarr\'d I sent abroad.\n     And thus the good instructor: \"Now, my son!\nDraws near the city, that of Dis is nam\'d,\nWith its grave denizens, a mighty throng.\"\n     I thus: \"The minarets already, Sir!\nThere certes in the valley I descry,\nGleaming vermilion, as if they from fire\nHad issu\'d.\"  He replied: \"Eternal fire,\nThat inward burns, shows them with ruddy flame\nIllum\'d; as in this nether hell thou seest.\"\n     We came within the fosses deep, that moat\nThis region comfortless.  The walls appear\'d\nAs they were fram\'d of iron.  We had made\nWide circuit, ere a place we reach\'d, where loud\nThe mariner cried vehement: \"Go forth!\nThe\' entrance is here!\"  Upon the gates I spied\nMore than a thousand, who of old from heaven\nWere hurl\'d.  With ireful gestures, \"Who is this,\"\nThey cried, \"that without death first felt, goes through\nThe regions of the dead?\"  My sapient guide\nMade sign that he for secret parley wish\'d;\nWhereat their angry scorn abating, thus\nThey spake: \"Come thou alone; and let him go\nWho hath so hardily enter\'d this realm.\nAlone return he by his witless way;\nIf well he know it, let him prove.  For thee,\nHere shalt thou tarry, who through clime so dark\nHast been his escort.\" Now bethink thee, reader!\nWhat cheer was mine at sound of those curs\'d words.\nI did be");

                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "BAD.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 2911, file);
                test_error(size == 2525, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2525 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2525);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 2525);


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
    

                char *filecontent = (char *)calloc(2409, 1);
                char expected_filecontent[2410] = "";

                strcat(expected_filecontent, "s birthplace,\nCallaroga; his father and mother\'s names, Felix and Joanna, his\nmother\'s dream; his name of Dominic, given him in consequence of\na vision by a noble matron, who stood sponsor to him, are all\ntold in an anonymous life of the saint, said to be written in the\nthirteenth century, and published by Quetif and Echard,\nScriptores Ordinis Praedicatorum.  Par.  1719. fol. t 1.  p. 25.\nThese writers deny his having been an inquisitor, and indeed the\nestablishment of the inquisition itself before the fourth Lateran\ncouncil.  Ibid.  p. 88.\n\nv. 55.  In the mother\'s womb.]  His mother, when pregnant with\nhim, is said to have dreamt that she should bring forth a white\nand black dog, with a lighted torch in its mouth.\n\nv. 59.  The dame.]  His godmother\'s dream was, that he had one\nstar in his forehead, and another in the nape of his neck, from\nwhich he communicated light to the east and the west.\n\nv. 73.  Felix.]  Felix Gusman.\n\nv. 75.  As men interpret it.]  Grace or gift of the Lord.\n\nv. 77.  Ostiense.]  A cardinal, who explained the decretals.\n\nv. 77.  Taddeo.]  A physician, of Florence.\n\nv. 82.  The see.]  \"The apostolic see, which no longer continues\nits wonted liberality towards the indigent and deserving; not\nindeed  through its own fault, as its doctrines are still the\nsame, but through the fault of the pontiff, who is seated in it.\"\n\nv. 85.  No dispensation.]  Dominic did not ask license to\ncompound for the use of unjust acquisitions, by dedicating a part\nof them to pious purposes.\n\nv. 89.  In favour of that seed.]  \"For that seed of the divine\nword, from which have sprung up these four-and-twenty plants,\nthat now environ thee.\"\n\nv. 101.  But the track.]  \"But the rule of St. Francis is already\ndeserted and the lees of the wine are turned into mouldiness.\"\n\nv. 110.  Tares.]  He adverts to the parable of the taxes and the\nwheat.\n\nv. 111.  I question not.]  \"Some indeed might be found, who still\nobserve the rule of the order, but such would come neither from\nCasale nor Acquasparta:\" of the former of which places was\nUberto, one master general, by whom the discipline had been\nrelaxed; and of the latter, Matteo, another, who had enforced it\nwith unnecessary rigour.\n\nv. 121.  -Illuminato here,\nAnd Agostino.]\nTwo among the earliest followers of St. Francis.\n\nv. 125.  Hugues of St. Victor.]  A Saxon of the monastery of\nSaint  Victor at Paris, who fed ill 1142 at the a");

                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "LONE.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 2511, file);
                test_error(size == 2409, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2409 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2409);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 2409);


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
    

                char *filecontent = (char *)calloc(3212, 1);
                char expected_filecontent[3213] = "";

                strcat(expected_filecontent, "thus spake:\n\"Contingency, unfolded not to view\nUpon the tablet of your mortal mold,\nIs all depictur\'d in the\' eternal sight;\nBut hence deriveth not necessity,\nMore then the tall ship, hurried down the flood,\nDoth from the vision, that reflects the scene.\nFrom thence, as to the ear sweet harmony\nFrom organ comes, so comes before mine eye\nThe time prepar\'d for thee.  Such as driv\'n out\nFrom Athens, by his cruel stepdame\'s wiles,\nHippolytus departed, such must thou\nDepart from Florence.  This they wish, and this\nContrive, and will ere long effectuate, there,\nWhere gainful merchandize is made of Christ,\nThroughout the livelong day.  The common cry,\nWill, as \'t is ever wont, affix the blame\nUnto the party injur\'d:  but the truth\nShall, in the vengeance it dispenseth, find\nA faithful witness.  Thou shall leave each thing\nBelov\'d most dearly:  this is the first shaft\nShot from the bow of exile.  Thou shalt prove\nHow salt the savour is of other\'s bread,\nHow hard the passage to descend and climb\nBy other\'s stairs, But that shall gall thee most\nWill he the worthless and vile company,\nWith whom thou must be thrown into these straits.\nFor all ungrateful, impious all and mad,\nShall turn \'gainst thee:  but in a little while\nTheirs and not thine shall be the crimson\'d brow\nTheir course shall so evince their brutishness\nT\' have ta\'en thy stand apart shall well become thee.\n     \"First refuge thou must find, first place of rest,\nIn the great Lombard\'s courtesy, who bears\nUpon the ladder perch\'d the sacred bird.\nHe shall behold thee with such kind regard,\nThat \'twixt ye two, the contrary to that\nWhich falls \'twixt other men, the granting shall\nForerun the asking.  With him shalt thou see\nThat mortal, who was at his birth impress\nSo strongly from this star, that of his deeds\nThe nations shall take note.  His unripe age\nYet holds him from observance; for these wheels\nOnly nine years have compass him about.\nBut, ere the Gascon practice on great Harry,\nSparkles of virtue shall shoot forth in him,\nIn equal scorn of labours and of gold.\nHis bounty shall be spread abroad so widely,\nAs not to let the tongues e\'en of his foes\nBe idle in its praise.  Look thou to him\nAnd his beneficence:  for he shall cause\nReversal of their lot to many people,\nRich men and beggars interchanging fortunes.\nAnd thou shalt bear this written in thy soul\nOf him, but tell it not; \"and things he told\nIncredible to those who witness them;\nThen added:  \"So interpret thou, my son,\nWhat hath been told thee.--Lo!  the ambushment\nThat a few circling seasons hide for thee!\nYet envy not thy neighbours: time extends\nThy span beyond their treason\'s chastisement.\"\n     Soon, as the saintly spirit, by his silence,\nHad shown the web, which I had streteh\'d for him\nUpon the warp, was woven, I began,\nAs one, who in perplexity desires\nCounsel of other, wise, benign and friendly:\n\"My father!  well I mark how time spurs on\nToward me, ready to inflict the blow,\nWhich falls most heavily on him, who most\nAbandoned himself.  Therefore \'t is good\nI should forecast, that driven from the place\nMost dear to me, I may not lose myself\nAll others by my song.  Down through the world\nOf infinite mourning, and along the mount\nFrom whose ");

                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "EDGE.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 3511, file);
                test_error(size == 3212, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3212 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3212);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 3212);


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
    

                char *filecontent = (char *)calloc(337, 1);
                char expected_filecontent[338] = "";

                strcat(expected_filecontent, " fly, yet ventures not to quit\nThe nest, and drops it; so in me desire\nOf questioning my guide arose, and fell,\nArriving even to the act, that marks\nA man prepar\'d for speech.  Him all our haste\nRestrain\'d not, but thus spake the sire belov\'d:\nFear not to speed the shaft, that on thy lip\nStands trembling for its flight.\"  Encourag\'d th");

                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "SMALLSPE");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 688, file);
                test_error(size == 337, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 337 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 337);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 337);


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
    

                char expected_filecontent[32] = "";

                strcat(expected_filecontent, "hose lively clearness far\nSurpa");

                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "SUN.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 31; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

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
    

                char expected_filecontent[1789] = "";

                strcat(expected_filecontent, "Thaumantian.]  Figlia di Taumante\n[GREEK HERE]\n\nCompare Plato, Theaet.  v. ii.  p. 76.  Bip.  edit., Virg; Aen.\nix. 5, and Spenser, Faery Queen, b. v. c. 3.  st. 25.\n\nv. 85.  The name.]  The name of Poet.\n\nv. 89.  From Tolosa.]  Dante, as many others have done, confounds\nStatius the poet, who was a Neapolitan, with a rhetorician of the\nsame name, who was of Tolosa, or Thoulouse.  Thus Chaucer, Temple\nof Fame, b. iii. The Tholason, that height Stace.\n\nv. 94.  Fell.]  Statius lived to write only a small part of the\nAchilleid.\n\nCANTO XXII\n\nv. 5.  Blessed.]  Matt.  v. 6.\n\nv. 14.  Aquinum\'s bard.]  Juvenal had celebrated his contemporary\nStatius, Sat. vii.  82; though some critics imagine that there is\na secret derision couched under his praise.\n\nv. 28.  Why.]  Quid non mortalia pecaora cogis\nAnri sacra fames?\nVirg. Aen. 1. iii. 57\n\nVenturi supposes that Dante might have mistaken the meaning of\nthe word sacra, and construed it \"holy,\" instead of \"cursed.\"\nBut I see no necessity for having recourse to so improbable a\nconjecture.\n\nv. 41.  The fierce encounter.]  See Hell, Canto VII.  26.\n\nv. 46.  With shorn locks.]  Ibid.  58.\n\nv. 57.  The twin sorrow of Jocasta\'s womb.]  Eteocles and\nPolynices\n\nv. 71.  A renovated world.]  Virg.  Ecl.  iv. 5\n\nv. 100.  That Greek.]  Homer\n\nv. 107.  Of thy train. ]  Of those celebrated in thy Poem.\"\n\nv. 112.  Tiresias\' daughter.]  Dante appears to have forgotten\nthat he had placed Manto, the daughter of Tiresias, among the\nsorcerers. See Hell Canto XX.  Vellutello endeavours, rather\nawkwardly, to reconcile the inconsistency, by observing, that\nalthough she was placed there as a sinner, yet, as one of famous\nmemory, she had also a place among the worthies in Limbo.\n\nLombardi excuses our author better, by observing that Tiresias\nhad a");

                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "USUAL.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 1788; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

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
    

                char expected_filecontent[2986] = "";

                strcat(expected_filecontent, "ndro and Napoleone, sons of\nAlberto Alberti, who murdered each other.  They were proprietors\nof the valley of Falterona, where the Bisenzio has its source, a\nriver that falls into the Arno about six miles from Florence.\n\nv. 59.  Not him,]  Mordrec, son of King Arthur.\n\nv. 60. Foccaccia.]  Focaccia of Cancellieri, (the Pistoian\nfamily) whose atrocious act of revenge against his uncle is said\nto have given rise to the parties of the Bianchi and Neri, in the\nyear 1300. See G. Villani, Hist. l, viii. c. 37. and\nMacchiavelli, Hist. l. ii. The account of the latter writer\ndiffers much from that given by Landino in his Commentary.\n\nv. 63.  Mascheroni.]  Sassol Mascheroni, a Florentiue, who also\nmurdered his uncle.\n\nv. 66.  Camiccione.]  Camiccione de\' Pazzi of Valdarno, by whom\nhis kinsman Ubertino was treacherously pnt to death.\n\nv. 67.  Carlino.]  One of the same family.  He betrayed the\nCastel di Piano Travigne, in Valdarno, to the Florentines, after\nthe refugees of the Bianca and Ghibelline party had defended it\nagainst a siege for twenty-nine days, in the summer of 1302.  See\nG. Villani, l. viii. c. 52 and Dino Compagni, l. ii.\n\nv. 81. Montaperto.] The defeat of the Guelfi at Montaperto,\noccasioned by the treachery of Bocca degli Abbati, who, during\nthe engagement, cut off the hand of Giacopo del Vacca de\'Pazzi,\nbearer of the Florentine standard.  G. Villani, l. vi. c. 80, and\nNotes to Canto X.  This event happened in 1260.\n\nv. 113.  Him of Duera.]  Buoso of Cremona, of the family of\nDuera, who was bribed by Guy de Montfort, to leave a pass between\nPiedmont and Parma, with the defence of which he had been\nentrusted by the Ghibellines, open to the army of Charles of\nAnjou, A.D. 1265, at which the people of Cremona were so enraged,\nthat they extirpated the whole family.  G. Villani, l. vii. c. 4.\n\nv. 118.  Beccaria.]  Abbot of Vallombrosa, who was the Pope\'s\nLegate at Florence, where his intrigues in favour of the\nGhibellines being discovered, he was beheaded. I do not find the\noccurrence in Vallini, nor do the commentators say to what pope\nhe was legate. By Landino he is reported to have been from Parma,\nby Vellutello from Pavia.\n\nv. 118.  Soldanieri.]  \"Gianni Soldanieri,\"  says Villani, Hist.\nl. vii. c14, \"put himself at the head of the people, in the hopes\nof rising into power, not aware that the result would be mischief\nto the Ghibelline party, and his own ruin; an event which seems\never to have befallen him, who has headed the populace in\nFlorence.\" A.D. 1266.\n\nv. 119.  Ganellon.]  The betrayer of Charlemain, mentioned by\nArchbishop Turpin.  He is a common instance of treachery with the\npoets of the middle ages.\n        Trop son fol e mal pensant,\n        Pis valent que Guenelon.\n               Thibaut, roi de Navarre\n        O new Scariot, and new Ganilion,\n        O false dissembler, &c.\n               Chaucer, Nonne\'s Prieste\'s Tale\nAnd in the Monke\'s Tale, Peter of Spaine.\nv. 119.  Tribaldello.]  Tribaldello de\'Manfredi, who ");

                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "THEIR.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2985; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

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
    

                char expected_filecontent[3073] = "";

                strcat(expected_filecontent, "was the second emperor of the house of Saab; and his\nson Frederick II \"the third and last.\"\n\nCANTO IV\n\nv. 6.  Between two deer]\n\nTigris ut auditis, diversa valle duorum\nExtimulata fame, mugitibus armentorum\nNeseit utro potius ruat, et ruere ardet utroque.\nOvid, Metam. 1. v. 166\n\nv. 13.  Daniel.]  See Daniel, c. ii.\n\nv. 24.  Plato.]  [GREEK HERE]  Plato Timaeus v. ix.  p. 326.\nEdit. Bip.  \"The Creator, when he had framed the universe,\ndistributed to the stars an equal number of souls, appointing to\neach soul its several star.\"\n\nv. 27.  Of that.]  Plato\'s opinion.\n\nv. 34.  The first circle.]  The empyrean.\n\nv. 48.  Him who made Tobias whole.]\n\nRaphael, the sociable spirit, that deign\'d\nTo travel with Tobias, and secur\'d\nHis marriage with the sev\'n times wedded maid,\nMilton, P. L. b. v. 223.\n\nv. 67.  That to the eye of man.]  \"That the ways of divine\njustice are often inscrutable to man, ought rather to be a motive\nto faith than an inducement to heresy.\" Such appears to me the\nmost satisfactory explanation of the passage.\n\nv. 82.  Laurence.]  Who suffered martyrdom in the third century.\n\nv. 82.  Scaevola.]  See Liv.  Hist. D. 1.  1. ii. 12.\n\nv. 100.  Alcmaeon.] Ovid, Met.  1. ix. f. 10.\n\n--Ultusque parente parentem\nNatus, erit facto pius et sceleratus eodem.\n\nv. 107.  Of will.]  \"What Piccarda asserts of Constance, that she\nretained her affection to the monastic life, is said absolutely\nand without relation to circumstances; and that which I affirm is\nspoken of the will conditionally and respectively: so that our\napparent difference is without any disagreement.\"\nv. 119.  That truth.]  The light of divine truth.\n\nCANTO V\n\nv. 43.  Two things.]  The one, the substance of the vow; the\nother, the compact, or form of it.\n\nv. 48.  It was enjoin\'d the Israelites.]  See Lev. e. xii, and\nxxvii.\n\nv. 56.  Either key.]  Purgatory, Canto IX.  108.\n\nv. 86.  That region.]  As some explain it, the east, according to\nothers the equinoctial line.\n\nv. 124.  This sphere.]  The planet Mercury, which, being nearest\nto the sun, is oftenest hidden by that luminary\n\nCANTO VI\n\nv. 1.  After that Constantine the eagle turn\'d.]  Constantine,\nin transferring the seat of empire from Rome to Byzantium,\ncarried the eagle, the Imperial ensign, from the west to the\neast. Aeneas, on the contrary had moved along with the sun\'s\ncourse, when he passed from Troy to Italy.\n\nv. 5.  A hundred years twice told and more.]  The Emperor\nConstantine entered Byzantium in 324, and Justinian began his\nreign in 527.\n\nv. 6.  At Europe\'s extreme point.]  Constantinople being situated\nat the extreme of Europe, and on the borders of Asia, near those\nmountains\nin the neighbourhood of Troy, from whence the first founders of\nRome had emigrated.\n\nv. 13.  To clear th\' incumber\'d laws.]  The code of laws was\nabridged and reformed by Justinian.\n\nv. 15.  Christ\'s nature merely human.]  Justinian is said to have\nbeen a follower of the heretical Opinions held by Eutyches,\" who\ntaught that in Christ there was but one nature, viz. that of the\nincarnate word.\"\nMaclaine\'s Mosheim, t. ii.  ");

                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "WATCH.BIN");
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

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

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
    

                char expected_filecontent[2526] = "";

                strcat(expected_filecontent, "     To which I thus: \" In mourning and in woe,\nCurs\'d spirit!  tarry thou. I know thee well,\nE\'en thus in filth disguis\'d.\"  Then stretch\'d he forth\nHands to the bark; whereof my teacher sage\nAware, thrusting him back: \"Away!  down there\nTo the\' other dogs!\"  then, with his arms my neck\nEncircling, kiss\'d my cheek, and spake: \"O soul\nJustly disdainful!  blest was she in whom\nThou was conceiv\'d!  He in the world was one\nFor arrogance noted; to his memory\nNo virtue lends its lustre; even so\nHere is his shadow furious.  There above\nHow many now hold themselves mighty kings\nWho here like swine shall wallow in the mire,\nLeaving behind them horrible dispraise!\"\n     I then: \"Master!  him fain would I behold\nWhelm\'d in these dregs, before we quit the lake.\"\n     He thus: \"Or ever to thy view the shore\nBe offer\'d, satisfied shall be that wish,\nWhich well deserves completion.\"  Scarce his words\nWere ended, when I saw the miry tribes\nSet on him with such violence, that yet\nFor that render I thanks to God and praise\n\"To Filippo Argenti:\" cried they all:\nAnd on himself the moody Florentine\nTurn\'d his avenging fangs.  Him here we left,\nNor speak I of him more.  But on mine ear\nSudden a sound of lamentation smote,\nWhereat mine eye unbarr\'d I sent abroad.\n     And thus the good instructor: \"Now, my son!\nDraws near the city, that of Dis is nam\'d,\nWith its grave denizens, a mighty throng.\"\n     I thus: \"The minarets already, Sir!\nThere certes in the valley I descry,\nGleaming vermilion, as if they from fire\nHad issu\'d.\"  He replied: \"Eternal fire,\nThat inward burns, shows them with ruddy flame\nIllum\'d; as in this nether hell thou seest.\"\n     We came within the fosses deep, that moat\nThis region comfortless.  The walls appear\'d\nAs they were fram\'d of iron.  We had made\nWide circuit, ere a place we reach\'d, where loud\nThe mariner cried vehement: \"Go forth!\nThe\' entrance is here!\"  Upon the gates I spied\nMore than a thousand, who of old from heaven\nWere hurl\'d.  With ireful gestures, \"Who is this,\"\nThey cried, \"that without death first felt, goes through\nThe regions of the dead?\"  My sapient guide\nMade sign that he for secret parley wish\'d;\nWhereat their angry scorn abating, thus\nThey spake: \"Come thou alone; and let him go\nWho hath so hardily enter\'d this realm.\nAlone return he by his witless way;\nIf well he know it, let him prove.  For thee,\nHere shalt thou tarry, who through clime so dark\nHast been his escort.\" Now bethink thee, reader!\nWhat cheer was mine at sound of those curs\'d words.\nI did be");

                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "BAD.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2525; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

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
    

                char expected_filecontent[2410] = "";

                strcat(expected_filecontent, "s birthplace,\nCallaroga; his father and mother\'s names, Felix and Joanna, his\nmother\'s dream; his name of Dominic, given him in consequence of\na vision by a noble matron, who stood sponsor to him, are all\ntold in an anonymous life of the saint, said to be written in the\nthirteenth century, and published by Quetif and Echard,\nScriptores Ordinis Praedicatorum.  Par.  1719. fol. t 1.  p. 25.\nThese writers deny his having been an inquisitor, and indeed the\nestablishment of the inquisition itself before the fourth Lateran\ncouncil.  Ibid.  p. 88.\n\nv. 55.  In the mother\'s womb.]  His mother, when pregnant with\nhim, is said to have dreamt that she should bring forth a white\nand black dog, with a lighted torch in its mouth.\n\nv. 59.  The dame.]  His godmother\'s dream was, that he had one\nstar in his forehead, and another in the nape of his neck, from\nwhich he communicated light to the east and the west.\n\nv. 73.  Felix.]  Felix Gusman.\n\nv. 75.  As men interpret it.]  Grace or gift of the Lord.\n\nv. 77.  Ostiense.]  A cardinal, who explained the decretals.\n\nv. 77.  Taddeo.]  A physician, of Florence.\n\nv. 82.  The see.]  \"The apostolic see, which no longer continues\nits wonted liberality towards the indigent and deserving; not\nindeed  through its own fault, as its doctrines are still the\nsame, but through the fault of the pontiff, who is seated in it.\"\n\nv. 85.  No dispensation.]  Dominic did not ask license to\ncompound for the use of unjust acquisitions, by dedicating a part\nof them to pious purposes.\n\nv. 89.  In favour of that seed.]  \"For that seed of the divine\nword, from which have sprung up these four-and-twenty plants,\nthat now environ thee.\"\n\nv. 101.  But the track.]  \"But the rule of St. Francis is already\ndeserted and the lees of the wine are turned into mouldiness.\"\n\nv. 110.  Tares.]  He adverts to the parable of the taxes and the\nwheat.\n\nv. 111.  I question not.]  \"Some indeed might be found, who still\nobserve the rule of the order, but such would come neither from\nCasale nor Acquasparta:\" of the former of which places was\nUberto, one master general, by whom the discipline had been\nrelaxed; and of the latter, Matteo, another, who had enforced it\nwith unnecessary rigour.\n\nv. 121.  -Illuminato here,\nAnd Agostino.]\nTwo among the earliest followers of St. Francis.\n\nv. 125.  Hugues of St. Victor.]  A Saxon of the monastery of\nSaint  Victor at Paris, who fed ill 1142 at the a");

                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "LONE.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2409; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

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
    

                char expected_filecontent[3213] = "";

                strcat(expected_filecontent, "thus spake:\n\"Contingency, unfolded not to view\nUpon the tablet of your mortal mold,\nIs all depictur\'d in the\' eternal sight;\nBut hence deriveth not necessity,\nMore then the tall ship, hurried down the flood,\nDoth from the vision, that reflects the scene.\nFrom thence, as to the ear sweet harmony\nFrom organ comes, so comes before mine eye\nThe time prepar\'d for thee.  Such as driv\'n out\nFrom Athens, by his cruel stepdame\'s wiles,\nHippolytus departed, such must thou\nDepart from Florence.  This they wish, and this\nContrive, and will ere long effectuate, there,\nWhere gainful merchandize is made of Christ,\nThroughout the livelong day.  The common cry,\nWill, as \'t is ever wont, affix the blame\nUnto the party injur\'d:  but the truth\nShall, in the vengeance it dispenseth, find\nA faithful witness.  Thou shall leave each thing\nBelov\'d most dearly:  this is the first shaft\nShot from the bow of exile.  Thou shalt prove\nHow salt the savour is of other\'s bread,\nHow hard the passage to descend and climb\nBy other\'s stairs, But that shall gall thee most\nWill he the worthless and vile company,\nWith whom thou must be thrown into these straits.\nFor all ungrateful, impious all and mad,\nShall turn \'gainst thee:  but in a little while\nTheirs and not thine shall be the crimson\'d brow\nTheir course shall so evince their brutishness\nT\' have ta\'en thy stand apart shall well become thee.\n     \"First refuge thou must find, first place of rest,\nIn the great Lombard\'s courtesy, who bears\nUpon the ladder perch\'d the sacred bird.\nHe shall behold thee with such kind regard,\nThat \'twixt ye two, the contrary to that\nWhich falls \'twixt other men, the granting shall\nForerun the asking.  With him shalt thou see\nThat mortal, who was at his birth impress\nSo strongly from this star, that of his deeds\nThe nations shall take note.  His unripe age\nYet holds him from observance; for these wheels\nOnly nine years have compass him about.\nBut, ere the Gascon practice on great Harry,\nSparkles of virtue shall shoot forth in him,\nIn equal scorn of labours and of gold.\nHis bounty shall be spread abroad so widely,\nAs not to let the tongues e\'en of his foes\nBe idle in its praise.  Look thou to him\nAnd his beneficence:  for he shall cause\nReversal of their lot to many people,\nRich men and beggars interchanging fortunes.\nAnd thou shalt bear this written in thy soul\nOf him, but tell it not; \"and things he told\nIncredible to those who witness them;\nThen added:  \"So interpret thou, my son,\nWhat hath been told thee.--Lo!  the ambushment\nThat a few circling seasons hide for thee!\nYet envy not thy neighbours: time extends\nThy span beyond their treason\'s chastisement.\"\n     Soon, as the saintly spirit, by his silence,\nHad shown the web, which I had streteh\'d for him\nUpon the warp, was woven, I began,\nAs one, who in perplexity desires\nCounsel of other, wise, benign and friendly:\n\"My father!  well I mark how time spurs on\nToward me, ready to inflict the blow,\nWhich falls most heavily on him, who most\nAbandoned himself.  Therefore \'t is good\nI should forecast, that driven from the place\nMost dear to me, I may not lose myself\nAll others by my song.  Down through the world\nOf infinite mourning, and along the mount\nFrom whose ");

                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "EDGE.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3212; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

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
    

                char expected_filecontent[338] = "";

                strcat(expected_filecontent, " fly, yet ventures not to quit\nThe nest, and drops it; so in me desire\nOf questioning my guide arose, and fell,\nArriving even to the act, that marks\nA man prepar\'d for speech.  Him all our haste\nRestrain\'d not, but thus spake the sire belov\'d:\nFear not to speed the shaft, that on thy lip\nStands trembling for its flight.\"  Encourag\'d th");

                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "SMALLSPE");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 337; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

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
    
            char *filecontent = (char *)calloc(2409, 1);
            char expected_filecontent[2410] = "";

            strcat(expected_filecontent, "s birthplace,\nCallaroga; his father and mother\'s names, Felix and Joanna, his\nmother\'s dream; his name of Dominic, given him in consequence of\na vision by a noble matron, who stood sponsor to him, are all\ntold in an anonymous life of the saint, said to be written in the\nthirteenth century, and published by Quetif and Echard,\nScriptores Ordinis Praedicatorum.  Par.  1719. fol. t 1.  p. 25.\nThese writers deny his having been an inquisitor, and indeed the\nestablishment of the inquisition itself before the fourth Lateran\ncouncil.  Ibid.  p. 88.\n\nv. 55.  In the mother\'s womb.]  His mother, when pregnant with\nhim, is said to have dreamt that she should bring forth a white\nand black dog, with a lighted torch in its mouth.\n\nv. 59.  The dame.]  His godmother\'s dream was, that he had one\nstar in his forehead, and another in the nape of his neck, from\nwhich he communicated light to the east and the west.\n\nv. 73.  Felix.]  Felix Gusman.\n\nv. 75.  As men interpret it.]  Grace or gift of the Lord.\n\nv. 77.  Ostiense.]  A cardinal, who explained the decretals.\n\nv. 77.  Taddeo.]  A physician, of Florence.\n\nv. 82.  The see.]  \"The apostolic see, which no longer continues\nits wonted liberality towards the indigent and deserving; not\nindeed  through its own fault, as its doctrines are still the\nsame, but through the fault of the pontiff, who is seated in it.\"\n\nv. 85.  No dispensation.]  Dominic did not ask license to\ncompound for the use of unjust acquisitions, by dedicating a part\nof them to pious purposes.\n\nv. 89.  In favour of that seed.]  \"For that seed of the divine\nword, from which have sprung up these four-and-twenty plants,\nthat now environ thee.\"\n\nv. 101.  But the track.]  \"But the rule of St. Francis is already\ndeserted and the lees of the wine are turned into mouldiness.\"\n\nv. 110.  Tares.]  He adverts to the parable of the taxes and the\nwheat.\n\nv. 111.  I question not.]  \"Some indeed might be found, who still\nobserve the rule of the order, but such would come neither from\nCasale nor Acquasparta:\" of the former of which places was\nUberto, one master general, by whom the discipline had been\nrelaxed; and of the latter, Matteo, another, who had enforced it\nwith unnecessary rigour.\n\nv. 121.  -Illuminato here,\nAnd Agostino.]\nTwo among the earliest followers of St. Francis.\n\nv. 125.  Hugues of St. Victor.]  A Saxon of the monastery of\nSaint  Victor at Paris, who fed ill 1142 at the a");

            struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "LONE.BIN");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int i;
            for (i = 0; i < 344; ++i)
            {
                int res = file_read(filecontent + 7 * i, 7, 1, file);
                test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            }

            int res = file_read(filecontent + 7 * i, 7, 1, file);
            test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2409);

            // jeśli jest, to raportuj błąd
            test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

            onerror_compare_memory(expected_filecontent, filecontent, 2409);

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
    

            char *filecontent0 = (char *)calloc(31, 1);
    char *filecontent1 = (char *)calloc(1788, 1);
    char *filecontent2 = (char *)calloc(2985, 1);
    char *filecontent3 = (char *)calloc(3072, 1);
    char *filecontent4 = (char *)calloc(2525, 1);
    char *filecontent5 = (char *)calloc(2409, 1);
    char *filecontent6 = (char *)calloc(3212, 1);
    char *filecontent7 = (char *)calloc(337, 1);

            char expected_filecontent0[32] = "";
    char expected_filecontent1[1789] = "";
    char expected_filecontent2[2986] = "";
    char expected_filecontent3[3073] = "";
    char expected_filecontent4[2526] = "";
    char expected_filecontent5[2410] = "";
    char expected_filecontent6[3213] = "";
    char expected_filecontent7[338] = "";

            strcat(expected_filecontent0, "hose lively clearness far\nSurpa");strcat(expected_filecontent1, "Thaumantian.]  Figlia di Taumante\n[GREEK HERE]\n\nCompare Plato, Theaet.  v. ii.  p. 76.  Bip.  edit., Virg; Aen.\nix. 5, and Spenser, Faery Queen, b. v. c. 3.  st. 25.\n\nv. 85.  The name.]  The name of Poet.\n\nv. 89.  From Tolosa.]  Dante, as many others have done, confounds\nStatius the poet, who was a Neapolitan, with a rhetorician of the\nsame name, who was of Tolosa, or Thoulouse.  Thus Chaucer, Temple\nof Fame, b. iii. The Tholason, that height Stace.\n\nv. 94.  Fell.]  Statius lived to write only a small part of the\nAchilleid.\n\nCANTO XXII\n\nv. 5.  Blessed.]  Matt.  v. 6.\n\nv. 14.  Aquinum\'s bard.]  Juvenal had celebrated his contemporary\nStatius, Sat. vii.  82; though some critics imagine that there is\na secret derision couched under his praise.\n\nv. 28.  Why.]  Quid non mortalia pecaora cogis\nAnri sacra fames?\nVirg. Aen. 1. iii. 57\n\nVenturi supposes that Dante might have mistaken the meaning of\nthe word sacra, and construed it \"holy,\" instead of \"cursed.\"\nBut I see no necessity for having recourse to so improbable a\nconjecture.\n\nv. 41.  The fierce encounter.]  See Hell, Canto VII.  26.\n\nv. 46.  With shorn locks.]  Ibid.  58.\n\nv. 57.  The twin sorrow of Jocasta\'s womb.]  Eteocles and\nPolynices\n\nv. 71.  A renovated world.]  Virg.  Ecl.  iv. 5\n\nv. 100.  That Greek.]  Homer\n\nv. 107.  Of thy train. ]  Of those celebrated in thy Poem.\"\n\nv. 112.  Tiresias\' daughter.]  Dante appears to have forgotten\nthat he had placed Manto, the daughter of Tiresias, among the\nsorcerers. See Hell Canto XX.  Vellutello endeavours, rather\nawkwardly, to reconcile the inconsistency, by observing, that\nalthough she was placed there as a sinner, yet, as one of famous\nmemory, she had also a place among the worthies in Limbo.\n\nLombardi excuses our author better, by observing that Tiresias\nhad a");strcat(expected_filecontent2, "ndro and Napoleone, sons of\nAlberto Alberti, who murdered each other.  They were proprietors\nof the valley of Falterona, where the Bisenzio has its source, a\nriver that falls into the Arno about six miles from Florence.\n\nv. 59.  Not him,]  Mordrec, son of King Arthur.\n\nv. 60. Foccaccia.]  Focaccia of Cancellieri, (the Pistoian\nfamily) whose atrocious act of revenge against his uncle is said\nto have given rise to the parties of the Bianchi and Neri, in the\nyear 1300. See G. Villani, Hist. l, viii. c. 37. and\nMacchiavelli, Hist. l. ii. The account of the latter writer\ndiffers much from that given by Landino in his Commentary.\n\nv. 63.  Mascheroni.]  Sassol Mascheroni, a Florentiue, who also\nmurdered his uncle.\n\nv. 66.  Camiccione.]  Camiccione de\' Pazzi of Valdarno, by whom\nhis kinsman Ubertino was treacherously pnt to death.\n\nv. 67.  Carlino.]  One of the same family.  He betrayed the\nCastel di Piano Travigne, in Valdarno, to the Florentines, after\nthe refugees of the Bianca and Ghibelline party had defended it\nagainst a siege for twenty-nine days, in the summer of 1302.  See\nG. Villani, l. viii. c. 52 and Dino Compagni, l. ii.\n\nv. 81. Montaperto.] The defeat of the Guelfi at Montaperto,\noccasioned by the treachery of Bocca degli Abbati, who, during\nthe engagement, cut off the hand of Giacopo del Vacca de\'Pazzi,\nbearer of the Florentine standard.  G. Villani, l. vi. c. 80, and\nNotes to Canto X.  This event happened in 1260.\n\nv. 113.  Him of Duera.]  Buoso of Cremona, of the family of\nDuera, who was bribed by Guy de Montfort, to leave a pass between\nPiedmont and Parma, with the defence of which he had been\nentrusted by the Ghibellines, open to the army of Charles of\nAnjou, A.D. 1265, at which the people of Cremona were so enraged,\nthat they extirpated the whole family.  G. Villani, l. vii. c. 4.\n\nv. 118.  Beccaria.]  Abbot of Vallombrosa, who was the Pope\'s\nLegate at Florence, where his intrigues in favour of the\nGhibellines being discovered, he was beheaded. I do not find the\noccurrence in Vallini, nor do the commentators say to what pope\nhe was legate. By Landino he is reported to have been from Parma,\nby Vellutello from Pavia.\n\nv. 118.  Soldanieri.]  \"Gianni Soldanieri,\"  says Villani, Hist.\nl. vii. c14, \"put himself at the head of the people, in the hopes\nof rising into power, not aware that the result would be mischief\nto the Ghibelline party, and his own ruin; an event which seems\never to have befallen him, who has headed the populace in\nFlorence.\" A.D. 1266.\n\nv. 119.  Ganellon.]  The betrayer of Charlemain, mentioned by\nArchbishop Turpin.  He is a common instance of treachery with the\npoets of the middle ages.\n        Trop son fol e mal pensant,\n        Pis valent que Guenelon.\n               Thibaut, roi de Navarre\n        O new Scariot, and new Ganilion,\n        O false dissembler, &c.\n               Chaucer, Nonne\'s Prieste\'s Tale\nAnd in the Monke\'s Tale, Peter of Spaine.\nv. 119.  Tribaldello.]  Tribaldello de\'Manfredi, who ");strcat(expected_filecontent3, "was the second emperor of the house of Saab; and his\nson Frederick II \"the third and last.\"\n\nCANTO IV\n\nv. 6.  Between two deer]\n\nTigris ut auditis, diversa valle duorum\nExtimulata fame, mugitibus armentorum\nNeseit utro potius ruat, et ruere ardet utroque.\nOvid, Metam. 1. v. 166\n\nv. 13.  Daniel.]  See Daniel, c. ii.\n\nv. 24.  Plato.]  [GREEK HERE]  Plato Timaeus v. ix.  p. 326.\nEdit. Bip.  \"The Creator, when he had framed the universe,\ndistributed to the stars an equal number of souls, appointing to\neach soul its several star.\"\n\nv. 27.  Of that.]  Plato\'s opinion.\n\nv. 34.  The first circle.]  The empyrean.\n\nv. 48.  Him who made Tobias whole.]\n\nRaphael, the sociable spirit, that deign\'d\nTo travel with Tobias, and secur\'d\nHis marriage with the sev\'n times wedded maid,\nMilton, P. L. b. v. 223.\n\nv. 67.  That to the eye of man.]  \"That the ways of divine\njustice are often inscrutable to man, ought rather to be a motive\nto faith than an inducement to heresy.\" Such appears to me the\nmost satisfactory explanation of the passage.\n\nv. 82.  Laurence.]  Who suffered martyrdom in the third century.\n\nv. 82.  Scaevola.]  See Liv.  Hist. D. 1.  1. ii. 12.\n\nv. 100.  Alcmaeon.] Ovid, Met.  1. ix. f. 10.\n\n--Ultusque parente parentem\nNatus, erit facto pius et sceleratus eodem.\n\nv. 107.  Of will.]  \"What Piccarda asserts of Constance, that she\nretained her affection to the monastic life, is said absolutely\nand without relation to circumstances; and that which I affirm is\nspoken of the will conditionally and respectively: so that our\napparent difference is without any disagreement.\"\nv. 119.  That truth.]  The light of divine truth.\n\nCANTO V\n\nv. 43.  Two things.]  The one, the substance of the vow; the\nother, the compact, or form of it.\n\nv. 48.  It was enjoin\'d the Israelites.]  See Lev. e. xii, and\nxxvii.\n\nv. 56.  Either key.]  Purgatory, Canto IX.  108.\n\nv. 86.  That region.]  As some explain it, the east, according to\nothers the equinoctial line.\n\nv. 124.  This sphere.]  The planet Mercury, which, being nearest\nto the sun, is oftenest hidden by that luminary\n\nCANTO VI\n\nv. 1.  After that Constantine the eagle turn\'d.]  Constantine,\nin transferring the seat of empire from Rome to Byzantium,\ncarried the eagle, the Imperial ensign, from the west to the\neast. Aeneas, on the contrary had moved along with the sun\'s\ncourse, when he passed from Troy to Italy.\n\nv. 5.  A hundred years twice told and more.]  The Emperor\nConstantine entered Byzantium in 324, and Justinian began his\nreign in 527.\n\nv. 6.  At Europe\'s extreme point.]  Constantinople being situated\nat the extreme of Europe, and on the borders of Asia, near those\nmountains\nin the neighbourhood of Troy, from whence the first founders of\nRome had emigrated.\n\nv. 13.  To clear th\' incumber\'d laws.]  The code of laws was\nabridged and reformed by Justinian.\n\nv. 15.  Christ\'s nature merely human.]  Justinian is said to have\nbeen a follower of the heretical Opinions held by Eutyches,\" who\ntaught that in Christ there was but one nature, viz. that of the\nincarnate word.\"\nMaclaine\'s Mosheim, t. ii.  ");strcat(expected_filecontent4, "     To which I thus: \" In mourning and in woe,\nCurs\'d spirit!  tarry thou. I know thee well,\nE\'en thus in filth disguis\'d.\"  Then stretch\'d he forth\nHands to the bark; whereof my teacher sage\nAware, thrusting him back: \"Away!  down there\nTo the\' other dogs!\"  then, with his arms my neck\nEncircling, kiss\'d my cheek, and spake: \"O soul\nJustly disdainful!  blest was she in whom\nThou was conceiv\'d!  He in the world was one\nFor arrogance noted; to his memory\nNo virtue lends its lustre; even so\nHere is his shadow furious.  There above\nHow many now hold themselves mighty kings\nWho here like swine shall wallow in the mire,\nLeaving behind them horrible dispraise!\"\n     I then: \"Master!  him fain would I behold\nWhelm\'d in these dregs, before we quit the lake.\"\n     He thus: \"Or ever to thy view the shore\nBe offer\'d, satisfied shall be that wish,\nWhich well deserves completion.\"  Scarce his words\nWere ended, when I saw the miry tribes\nSet on him with such violence, that yet\nFor that render I thanks to God and praise\n\"To Filippo Argenti:\" cried they all:\nAnd on himself the moody Florentine\nTurn\'d his avenging fangs.  Him here we left,\nNor speak I of him more.  But on mine ear\nSudden a sound of lamentation smote,\nWhereat mine eye unbarr\'d I sent abroad.\n     And thus the good instructor: \"Now, my son!\nDraws near the city, that of Dis is nam\'d,\nWith its grave denizens, a mighty throng.\"\n     I thus: \"The minarets already, Sir!\nThere certes in the valley I descry,\nGleaming vermilion, as if they from fire\nHad issu\'d.\"  He replied: \"Eternal fire,\nThat inward burns, shows them with ruddy flame\nIllum\'d; as in this nether hell thou seest.\"\n     We came within the fosses deep, that moat\nThis region comfortless.  The walls appear\'d\nAs they were fram\'d of iron.  We had made\nWide circuit, ere a place we reach\'d, where loud\nThe mariner cried vehement: \"Go forth!\nThe\' entrance is here!\"  Upon the gates I spied\nMore than a thousand, who of old from heaven\nWere hurl\'d.  With ireful gestures, \"Who is this,\"\nThey cried, \"that without death first felt, goes through\nThe regions of the dead?\"  My sapient guide\nMade sign that he for secret parley wish\'d;\nWhereat their angry scorn abating, thus\nThey spake: \"Come thou alone; and let him go\nWho hath so hardily enter\'d this realm.\nAlone return he by his witless way;\nIf well he know it, let him prove.  For thee,\nHere shalt thou tarry, who through clime so dark\nHast been his escort.\" Now bethink thee, reader!\nWhat cheer was mine at sound of those curs\'d words.\nI did be");strcat(expected_filecontent5, "s birthplace,\nCallaroga; his father and mother\'s names, Felix and Joanna, his\nmother\'s dream; his name of Dominic, given him in consequence of\na vision by a noble matron, who stood sponsor to him, are all\ntold in an anonymous life of the saint, said to be written in the\nthirteenth century, and published by Quetif and Echard,\nScriptores Ordinis Praedicatorum.  Par.  1719. fol. t 1.  p. 25.\nThese writers deny his having been an inquisitor, and indeed the\nestablishment of the inquisition itself before the fourth Lateran\ncouncil.  Ibid.  p. 88.\n\nv. 55.  In the mother\'s womb.]  His mother, when pregnant with\nhim, is said to have dreamt that she should bring forth a white\nand black dog, with a lighted torch in its mouth.\n\nv. 59.  The dame.]  His godmother\'s dream was, that he had one\nstar in his forehead, and another in the nape of his neck, from\nwhich he communicated light to the east and the west.\n\nv. 73.  Felix.]  Felix Gusman.\n\nv. 75.  As men interpret it.]  Grace or gift of the Lord.\n\nv. 77.  Ostiense.]  A cardinal, who explained the decretals.\n\nv. 77.  Taddeo.]  A physician, of Florence.\n\nv. 82.  The see.]  \"The apostolic see, which no longer continues\nits wonted liberality towards the indigent and deserving; not\nindeed  through its own fault, as its doctrines are still the\nsame, but through the fault of the pontiff, who is seated in it.\"\n\nv. 85.  No dispensation.]  Dominic did not ask license to\ncompound for the use of unjust acquisitions, by dedicating a part\nof them to pious purposes.\n\nv. 89.  In favour of that seed.]  \"For that seed of the divine\nword, from which have sprung up these four-and-twenty plants,\nthat now environ thee.\"\n\nv. 101.  But the track.]  \"But the rule of St. Francis is already\ndeserted and the lees of the wine are turned into mouldiness.\"\n\nv. 110.  Tares.]  He adverts to the parable of the taxes and the\nwheat.\n\nv. 111.  I question not.]  \"Some indeed might be found, who still\nobserve the rule of the order, but such would come neither from\nCasale nor Acquasparta:\" of the former of which places was\nUberto, one master general, by whom the discipline had been\nrelaxed; and of the latter, Matteo, another, who had enforced it\nwith unnecessary rigour.\n\nv. 121.  -Illuminato here,\nAnd Agostino.]\nTwo among the earliest followers of St. Francis.\n\nv. 125.  Hugues of St. Victor.]  A Saxon of the monastery of\nSaint  Victor at Paris, who fed ill 1142 at the a");strcat(expected_filecontent6, "thus spake:\n\"Contingency, unfolded not to view\nUpon the tablet of your mortal mold,\nIs all depictur\'d in the\' eternal sight;\nBut hence deriveth not necessity,\nMore then the tall ship, hurried down the flood,\nDoth from the vision, that reflects the scene.\nFrom thence, as to the ear sweet harmony\nFrom organ comes, so comes before mine eye\nThe time prepar\'d for thee.  Such as driv\'n out\nFrom Athens, by his cruel stepdame\'s wiles,\nHippolytus departed, such must thou\nDepart from Florence.  This they wish, and this\nContrive, and will ere long effectuate, there,\nWhere gainful merchandize is made of Christ,\nThroughout the livelong day.  The common cry,\nWill, as \'t is ever wont, affix the blame\nUnto the party injur\'d:  but the truth\nShall, in the vengeance it dispenseth, find\nA faithful witness.  Thou shall leave each thing\nBelov\'d most dearly:  this is the first shaft\nShot from the bow of exile.  Thou shalt prove\nHow salt the savour is of other\'s bread,\nHow hard the passage to descend and climb\nBy other\'s stairs, But that shall gall thee most\nWill he the worthless and vile company,\nWith whom thou must be thrown into these straits.\nFor all ungrateful, impious all and mad,\nShall turn \'gainst thee:  but in a little while\nTheirs and not thine shall be the crimson\'d brow\nTheir course shall so evince their brutishness\nT\' have ta\'en thy stand apart shall well become thee.\n     \"First refuge thou must find, first place of rest,\nIn the great Lombard\'s courtesy, who bears\nUpon the ladder perch\'d the sacred bird.\nHe shall behold thee with such kind regard,\nThat \'twixt ye two, the contrary to that\nWhich falls \'twixt other men, the granting shall\nForerun the asking.  With him shalt thou see\nThat mortal, who was at his birth impress\nSo strongly from this star, that of his deeds\nThe nations shall take note.  His unripe age\nYet holds him from observance; for these wheels\nOnly nine years have compass him about.\nBut, ere the Gascon practice on great Harry,\nSparkles of virtue shall shoot forth in him,\nIn equal scorn of labours and of gold.\nHis bounty shall be spread abroad so widely,\nAs not to let the tongues e\'en of his foes\nBe idle in its praise.  Look thou to him\nAnd his beneficence:  for he shall cause\nReversal of their lot to many people,\nRich men and beggars interchanging fortunes.\nAnd thou shalt bear this written in thy soul\nOf him, but tell it not; \"and things he told\nIncredible to those who witness them;\nThen added:  \"So interpret thou, my son,\nWhat hath been told thee.--Lo!  the ambushment\nThat a few circling seasons hide for thee!\nYet envy not thy neighbours: time extends\nThy span beyond their treason\'s chastisement.\"\n     Soon, as the saintly spirit, by his silence,\nHad shown the web, which I had streteh\'d for him\nUpon the warp, was woven, I began,\nAs one, who in perplexity desires\nCounsel of other, wise, benign and friendly:\n\"My father!  well I mark how time spurs on\nToward me, ready to inflict the blow,\nWhich falls most heavily on him, who most\nAbandoned himself.  Therefore \'t is good\nI should forecast, that driven from the place\nMost dear to me, I may not lose myself\nAll others by my song.  Down through the world\nOf infinite mourning, and along the mount\nFrom whose ");strcat(expected_filecontent7, " fly, yet ventures not to quit\nThe nest, and drops it; so in me desire\nOf questioning my guide arose, and fell,\nArriving even to the act, that marks\nA man prepar\'d for speech.  Him all our haste\nRestrain\'d not, but thus spake the sire belov\'d:\nFear not to speed the shaft, that on thy lip\nStands trembling for its flight.\"  Encourag\'d th");


            struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            
                    struct file_t* file0 = file_open(volume, "SUN.TXT");
                    test_error(file0 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file1 = file_open(volume, "USUAL.TXT");
                    test_error(file1 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file2 = file_open(volume, "THEIR.TX");
                    test_error(file2 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file3 = file_open(volume, "WATCH.BIN");
                    test_error(file3 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file4 = file_open(volume, "BAD.BIN");
                    test_error(file4 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file5 = file_open(volume, "LONE.BIN");
                    test_error(file5 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file6 = file_open(volume, "EDGE.TXT");
                    test_error(file6 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file7 = file_open(volume, "SMALLSPE");
                    test_error(file7 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
            
                size_t size0 = file_read(filecontent0, 1, 31, file0);
                test_error(size0 == 31, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 31 bajtów, a wczytała %lu", size0);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos0 = mem_find_first_difference(filecontent0, expected_filecontent0, 31);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos0 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos0, mem_get_byte(filecontent0, diff_pos0), mem_get_byte(expected_filecontent0, diff_pos0));
        
                onerror_compare_memory(expected_filecontent0, filecontent0, 31);
            
                size_t size1 = file_read(filecontent1, 1, 1788, file1);
                test_error(size1 == 1788, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1788 bajtów, a wczytała %lu", size1);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos1 = mem_find_first_difference(filecontent1, expected_filecontent1, 1788);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos1 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos1, mem_get_byte(filecontent1, diff_pos1), mem_get_byte(expected_filecontent1, diff_pos1));
        
                onerror_compare_memory(expected_filecontent1, filecontent1, 1788);
            
                size_t size2 = file_read(filecontent2, 1, 2985, file2);
                test_error(size2 == 2985, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2985 bajtów, a wczytała %lu", size2);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos2 = mem_find_first_difference(filecontent2, expected_filecontent2, 2985);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos2 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos2, mem_get_byte(filecontent2, diff_pos2), mem_get_byte(expected_filecontent2, diff_pos2));
        
                onerror_compare_memory(expected_filecontent2, filecontent2, 2985);
            
                size_t size3 = file_read(filecontent3, 1, 3072, file3);
                test_error(size3 == 3072, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3072 bajtów, a wczytała %lu", size3);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos3 = mem_find_first_difference(filecontent3, expected_filecontent3, 3072);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos3 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos3, mem_get_byte(filecontent3, diff_pos3), mem_get_byte(expected_filecontent3, diff_pos3));
        
                onerror_compare_memory(expected_filecontent3, filecontent3, 3072);
            
                size_t size4 = file_read(filecontent4, 1, 2525, file4);
                test_error(size4 == 2525, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2525 bajtów, a wczytała %lu", size4);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos4 = mem_find_first_difference(filecontent4, expected_filecontent4, 2525);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos4 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos4, mem_get_byte(filecontent4, diff_pos4), mem_get_byte(expected_filecontent4, diff_pos4));
        
                onerror_compare_memory(expected_filecontent4, filecontent4, 2525);
            
                size_t size5 = file_read(filecontent5, 1, 2409, file5);
                test_error(size5 == 2409, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2409 bajtów, a wczytała %lu", size5);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos5 = mem_find_first_difference(filecontent5, expected_filecontent5, 2409);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos5 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos5, mem_get_byte(filecontent5, diff_pos5), mem_get_byte(expected_filecontent5, diff_pos5));
        
                onerror_compare_memory(expected_filecontent5, filecontent5, 2409);
            
                size_t size6 = file_read(filecontent6, 1, 3212, file6);
                test_error(size6 == 3212, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3212 bajtów, a wczytała %lu", size6);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos6 = mem_find_first_difference(filecontent6, expected_filecontent6, 3212);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos6 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos6, mem_get_byte(filecontent6, diff_pos6), mem_get_byte(expected_filecontent6, diff_pos6));
        
                onerror_compare_memory(expected_filecontent6, filecontent6, 3212);
            
                size_t size7 = file_read(filecontent7, 1, 337, file7);
                test_error(size7 == 337, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 337 bajtów, a wczytała %lu", size7);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos7 = mem_find_first_difference(filecontent7, expected_filecontent7, 337);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos7 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos7, mem_get_byte(filecontent7, diff_pos7), mem_get_byte(expected_filecontent7, diff_pos7));
        
                onerror_compare_memory(expected_filecontent7, filecontent7, 337);
            

            free(filecontent0);
    free(filecontent1);
    free(filecontent2);
    free(filecontent3);
    free(filecontent4);
    free(filecontent5);
    free(filecontent6);
    free(filecontent7);

            file_close(file0);
    file_close(file1);
    file_close(file2);
    file_close(file3);
    file_close(file4);
    file_close(file5);
    file_close(file6);
    file_close(file7);


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
//  Test 32: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST32(void)
{
    // informacje o teście
    test_start(32, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(31, 1);
            char expected_filecontent[32] = "";

            strcat(expected_filecontent, "hose lively clearness far\nSurpa");

            struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "SUN.TXT");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 14, SEEK_SET);
        
            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[14] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[14], c);

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
//  Test 33: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST33(void)
{
    // informacje o teście
    test_start(33, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(2409, 1);
            char expected_filecontent[2410] = "";

            strcat(expected_filecontent, "s birthplace,\nCallaroga; his father and mother\'s names, Felix and Joanna, his\nmother\'s dream; his name of Dominic, given him in consequence of\na vision by a noble matron, who stood sponsor to him, are all\ntold in an anonymous life of the saint, said to be written in the\nthirteenth century, and published by Quetif and Echard,\nScriptores Ordinis Praedicatorum.  Par.  1719. fol. t 1.  p. 25.\nThese writers deny his having been an inquisitor, and indeed the\nestablishment of the inquisition itself before the fourth Lateran\ncouncil.  Ibid.  p. 88.\n\nv. 55.  In the mother\'s womb.]  His mother, when pregnant with\nhim, is said to have dreamt that she should bring forth a white\nand black dog, with a lighted torch in its mouth.\n\nv. 59.  The dame.]  His godmother\'s dream was, that he had one\nstar in his forehead, and another in the nape of his neck, from\nwhich he communicated light to the east and the west.\n\nv. 73.  Felix.]  Felix Gusman.\n\nv. 75.  As men interpret it.]  Grace or gift of the Lord.\n\nv. 77.  Ostiense.]  A cardinal, who explained the decretals.\n\nv. 77.  Taddeo.]  A physician, of Florence.\n\nv. 82.  The see.]  \"The apostolic see, which no longer continues\nits wonted liberality towards the indigent and deserving; not\nindeed  through its own fault, as its doctrines are still the\nsame, but through the fault of the pontiff, who is seated in it.\"\n\nv. 85.  No dispensation.]  Dominic did not ask license to\ncompound for the use of unjust acquisitions, by dedicating a part\nof them to pious purposes.\n\nv. 89.  In favour of that seed.]  \"For that seed of the divine\nword, from which have sprung up these four-and-twenty plants,\nthat now environ thee.\"\n\nv. 101.  But the track.]  \"But the rule of St. Francis is already\ndeserted and the lees of the wine are turned into mouldiness.\"\n\nv. 110.  Tares.]  He adverts to the parable of the taxes and the\nwheat.\n\nv. 111.  I question not.]  \"Some indeed might be found, who still\nobserve the rule of the order, but such would come neither from\nCasale nor Acquasparta:\" of the former of which places was\nUberto, one master general, by whom the discipline had been\nrelaxed; and of the latter, Matteo, another, who had enforced it\nwith unnecessary rigour.\n\nv. 121.  -Illuminato here,\nAnd Agostino.]\nTwo among the earliest followers of St. Francis.\n\nv. 125.  Hugues of St. Victor.]  A Saxon of the monastery of\nSaint  Victor at Paris, who fed ill 1142 at the a");

            struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "LONE.BIN");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, -2043, SEEK_END);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[366] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[366], c);

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
//  Test 34: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST34(void)
{
    // informacje o teście
    test_start(34, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(2409, 1);
            char expected_filecontent[2410] = "";

            strcat(expected_filecontent, "s birthplace,\nCallaroga; his father and mother\'s names, Felix and Joanna, his\nmother\'s dream; his name of Dominic, given him in consequence of\na vision by a noble matron, who stood sponsor to him, are all\ntold in an anonymous life of the saint, said to be written in the\nthirteenth century, and published by Quetif and Echard,\nScriptores Ordinis Praedicatorum.  Par.  1719. fol. t 1.  p. 25.\nThese writers deny his having been an inquisitor, and indeed the\nestablishment of the inquisition itself before the fourth Lateran\ncouncil.  Ibid.  p. 88.\n\nv. 55.  In the mother\'s womb.]  His mother, when pregnant with\nhim, is said to have dreamt that she should bring forth a white\nand black dog, with a lighted torch in its mouth.\n\nv. 59.  The dame.]  His godmother\'s dream was, that he had one\nstar in his forehead, and another in the nape of his neck, from\nwhich he communicated light to the east and the west.\n\nv. 73.  Felix.]  Felix Gusman.\n\nv. 75.  As men interpret it.]  Grace or gift of the Lord.\n\nv. 77.  Ostiense.]  A cardinal, who explained the decretals.\n\nv. 77.  Taddeo.]  A physician, of Florence.\n\nv. 82.  The see.]  \"The apostolic see, which no longer continues\nits wonted liberality towards the indigent and deserving; not\nindeed  through its own fault, as its doctrines are still the\nsame, but through the fault of the pontiff, who is seated in it.\"\n\nv. 85.  No dispensation.]  Dominic did not ask license to\ncompound for the use of unjust acquisitions, by dedicating a part\nof them to pious purposes.\n\nv. 89.  In favour of that seed.]  \"For that seed of the divine\nword, from which have sprung up these four-and-twenty plants,\nthat now environ thee.\"\n\nv. 101.  But the track.]  \"But the rule of St. Francis is already\ndeserted and the lees of the wine are turned into mouldiness.\"\n\nv. 110.  Tares.]  He adverts to the parable of the taxes and the\nwheat.\n\nv. 111.  I question not.]  \"Some indeed might be found, who still\nobserve the rule of the order, but such would come neither from\nCasale nor Acquasparta:\" of the former of which places was\nUberto, one master general, by whom the discipline had been\nrelaxed; and of the latter, Matteo, another, who had enforced it\nwith unnecessary rigour.\n\nv. 121.  -Illuminato here,\nAnd Agostino.]\nTwo among the earliest followers of St. Francis.\n\nv. 125.  Hugues of St. Victor.]  A Saxon of the monastery of\nSaint  Victor at Paris, who fed ill 1142 at the a");

            struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "LONE.BIN");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 359, SEEK_SET);
            file_seek(file, 993, SEEK_CUR);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[1352] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[1352], c);

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
//  Test 35: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST35(void)
{
    // informacje o teście
    test_start(35, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "PRODUCE");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (PRODUCE) jest nazwą katalogu, a nie pliku");
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
//  Test 36: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST36(void)
{
    // informacje o teście
    test_start(36, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "VERB");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (VERB) jest nazwą katalogu, a nie pliku");
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
//  Test 37: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST37(void)
{
    // informacje o teście
    test_start(37, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "BALL");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (BALL) jest nazwą katalogu, a nie pliku");
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
//  Test 38: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST38(void)
{
    // informacje o teście
    test_start(38, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "CURRENT");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (CURRENT) jest nazwą katalogu, a nie pliku");
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
//  Test 39: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST39(void)
{
    // informacje o teście
    test_start(39, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "SYSTEM");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (SYSTEM) jest nazwą katalogu, a nie pliku");
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
//  Test 40: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST40(void)
{
    // informacje o teście
    test_start(40, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "WINDOW");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (WINDOW) jest nazwą katalogu, a nie pliku");
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
//  Test 41: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST41(void)
{
    // informacje o teście
    test_start(41, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "CUT");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (CUT) jest nazwą katalogu, a nie pliku");
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
//  Test 42: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST42(void)
{
    // informacje o teście
    test_start(42, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "LOVECLOC");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (LOVECLOC) jest nazwą katalogu, a nie pliku");
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
//  Test 43: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST43(void)
{
    // informacje o teście
    test_start(43, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "FOREST.TX");
            test_error(file == NULL, "Funkcja file_open() nie powinna otworzyć pliku o nazwie FOREST.TX, ponieważ nie istnieje on w katalogu głównym");
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
    

            struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(NULL, "FOREST.TX");
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
    

            struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
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
    

            struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
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
//  Test 47: Sprawdzanie poprawności działania funkcji file_close
//
void UTEST47(void)
{
    // informacje o teście
    test_start(47, "Sprawdzanie poprawności działania funkcji file_close", __LINE__);

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
    

            struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "SUN.TXT");
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
//  Test 49: Sprawdzanie poprawności działania funkcji dir_read
//
void UTEST49(void)
{
    // informacje o teście
    test_start(49, "Sprawdzanie poprawności działania funkcji dir_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char* expected_names[16] = { "SUN.TXT", "USUAL.TXT", "THEIR.TX", "WATCH.BIN", "BAD.BIN", "LONE.BIN", "EDGE.TXT", "SMALLSPE", "PRODUCE", "VERB", "BALL", "CURRENT", "SYSTEM", "WINDOW", "CUT", "LOVECLOC" };
            int found_names[16] = { 0 };

            struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t* pdir = dir_open(volume, "\\");
            test_error(pdir != NULL, "Funkcja dir_open() niepoprawnie otworzyła katalog");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            for (int i = 0; i < 16; ++i)
            {
                struct dir_entry_t entry;
                int res = dir_read(pdir, &entry);
                test_error(res == 0, "Funkcja dir_read() niepoprawnie odczytała wpis z katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int name_found = 0;

                for (int j = 0; j < 16; ++j)
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
//  Test 50: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST50(void)
{
    // informacje o teście
    test_start(50, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "SUN.TXT");
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
//  Test 51: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST51(void)
{
    // informacje o teście
    test_start(51, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "USUAL.TXT");
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
//  Test 52: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST52(void)
{
    // informacje o teście
    test_start(52, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "THEIR.TX");
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
//  Test 53: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST53(void)
{
    // informacje o teście
    test_start(53, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "WATCH.BIN");
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
//  Test 54: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST54(void)
{
    // informacje o teście
    test_start(54, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "BAD.BIN");
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
//  Test 55: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST55(void)
{
    // informacje o teście
    test_start(55, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "LONE.BIN");
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
//  Test 56: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST56(void)
{
    // informacje o teście
    test_start(56, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "EDGE.TXT");
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
//  Test 57: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST57(void)
{
    // informacje o teście
    test_start(57, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "SMALLSPE");
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
//  Test 58: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST58(void)
{
    // informacje o teście
    test_start(58, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("score_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t*  dir = dir_open(volume, "son");
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
            UTEST32, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST33, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST34, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST35, // Sprawdzanie poprawności działania funkcji file_open
            UTEST36, // Sprawdzanie poprawności działania funkcji file_open
            UTEST37, // Sprawdzanie poprawności działania funkcji file_open
            UTEST38, // Sprawdzanie poprawności działania funkcji file_open
            UTEST39, // Sprawdzanie poprawności działania funkcji file_open
            UTEST40, // Sprawdzanie poprawności działania funkcji file_open
            UTEST41, // Sprawdzanie poprawności działania funkcji file_open
            UTEST42, // Sprawdzanie poprawności działania funkcji file_open
            UTEST43, // Sprawdzanie poprawności działania funkcji file_open
            UTEST44, // Sprawdzanie poprawności działania funkcji file_read
            UTEST45, // Sprawdzanie poprawności działania funkcji file_read
            UTEST46, // Sprawdzanie poprawności działania funkcji file_read
            UTEST47, // Sprawdzanie poprawności działania funkcji file_close
            UTEST48, // Sprawdzanie poprawności działania funkcji file_read
            UTEST49, // Sprawdzanie poprawności działania funkcji dir_read
            UTEST50, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST51, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST52, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST53, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST54, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST55, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST56, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST57, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST58, // Sprawdzanie poprawności działania funkcji dir_open
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
            test_summary(58); // wszystkie testy muszą zakończyć się sukcesem
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