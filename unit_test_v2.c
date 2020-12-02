/*
 * Unit Test Bootstrap
 * Autor: Tomasz Jaworski, 2018-2020
 *
 * Test dla zadania Projekt: czytnik dysku, woluminu, katalogu głównego i plików (3,0)
 * Autor testowanej odpowiedzi: Sebastian Derendarz
 * Test wygenerowano automatycznie o 2020-12-02 11:34:12.774076
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
    


            struct disk_t* disk = disk_open_from_file("GARDEN.TXT");
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
    


            struct disk_t* disk = disk_open_from_file("occur.img");
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
    
        
                char *filecontent = (char *)calloc(620, 1);
                char expected_filecontent[621] = "";
        
                strcat(expected_filecontent, "pass\'d me speechless by; and doing so\nHath made me more compassionate his fate.\"\n     So we discours\'d to where the rock first show\'d\nThe other valley, had more light been there,\nE\'en to the lowest depth.  Soon as we came\nO\'er the last cloister in the dismal rounds\nOf Malebolge, and the brotherhood\nWere to our view expos\'d, then many a dart\nOf sore lament assail\'d me, headed all\nWith points of thrilling pity, that I clos\'d\nBoth ears against the volley with mine hands.\n     As were the torment, if each lazar-house\nOf Valdichiana, in the sultry time\n\'Twixt July and September, with the isle\nSardinia and Maremma\'s pe");
                
        
                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "WANT.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 620, file);
                test_error(size == 620, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 620 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 620);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 620);


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
    
        
                char *filecontent = (char *)calloc(14273, 1);
                char expected_filecontent[14274] = "";
        
                strcat(expected_filecontent, "t.  Sails never such I saw\nOutstretch\'d on the wide sea.  No plumes had they,\nBut were in texture like a bat, and these\nHe flapp\'d i\' th\' air, that from him issued still\nThree winds, wherewith Cocytus to its depth\nWas frozen.  At six eyes he wept:  the tears\nAdown three chins distill\'d with bloody foam.\nAt every mouth his teeth a sinner champ\'d\nBruis\'d as with pond\'rous engine, so that three\nWere in this guise tormented.  But far more\nThan from that gnawing, was the foremost pang\'d\nBy the fierce rending, whence ofttimes the back\nWas stript of all its skin.  \"That upper spirit,\nWho hath worse punishment,\" so spake my guide,\n\"Is Judas, he that hath his head within\nAnd plies the feet without.  Of th\' other two,\nWhose heads are under, from the murky jaw\nWho hangs, is Brutus:  lo!  how he doth writhe\nAnd speaks not!  Th\' other Cassius, that appears\nSo large of limb.  But night now re-ascends,\nAnd it is time for parting.  All is seen.\"\n     I clipp\'d him round the neck, for so he bade;\nAnd noting time and place, he, when the wings\nEnough were op\'d, caught fast the shaggy sides,\nAnd down from pile to pile descending stepp\'d\nBetween the thick fell and the jagged ice.\n     Soon as he reach\'d the point, whereat the thigh\nUpon the swelling of the haunches turns,\nMy leader there with pain and struggling hard\nTurn\'d round his head, where his feet stood before,\nAnd grappled at the fell, as one who mounts,\nThat into hell methought we turn\'d again.\n     \"Expect that by such stairs as these,\" thus spake\nThe teacher, panting like a man forespent,\n\"We must depart from evil so extreme.\"\nThen at a rocky opening issued forth,\nAnd plac\'d me on a brink to sit, next join\'d\nWith wary step my side.  I rais\'d mine eyes,\nBelieving that I Lucifer should see\nWhere he was lately left, but saw him now\nWith legs held upward.  Let the grosser sort,\nWho see not what the point was I had pass\'d,\nBethink them if sore toil oppress\'d me then.\n     \"Arise,\" my master cried, \"upon thy feet.\n\"The way is long, and much uncouth the road;\nAnd now within one hour and half of noon\nThe sun returns.\"  It was no palace-hall\nLofty and luminous wherein we stood,\nBut natural dungeon where ill footing was\nAnd scant supply of light.  \"Ere from th\' abyss\nI sep\'rate,\" thus when risen I began,\n\"My guide!  vouchsafe few words to set me free\nFrom error\'s thralldom.  Where is now the ice?\nHow standeth he in posture thus revers\'d?\nAnd how from eve to morn in space so brief\nHath the sun made his transit?\"  He in few\nThus answering spake:  \"Thou deemest thou art still\nOn th\' other side the centre, where I grasp\'d\nTh\' abhorred worm, that boreth through the world.\nThou wast on th\' other side, so long as I\nDescended; when I turn\'d, thou didst o\'erpass\nThat point, to which from ev\'ry part is dragg\'d\nAll heavy substance.  Thou art now arriv\'d\nUnder the hemisphere opposed to that,\nWhich the great continent doth overspread,\nAnd underneath whose canopy expir\'d\nThe Man, that was born sinless, and so liv\'d.\nThy feet are planted on the smallest sphere,\nWhose other aspect is Judecca.  Morn\nHere rises, when there evening sets:  and he,\nWhose shaggy pile was scal\'d, yet standeth fix\'d,\nAs at the first.  On this part he fell down\nFrom heav\'n; and th\' earth, here prominent before,\nThrough fear of him did veil her with the sea,\nAnd to our hemisphere retir\'d.  Perchance\nTo shun him was the vacant space left here\nBy what of firm land on this side appears,\nThat sprang aloof.\"  There is a place beneath,\nFrom Belzebub as distant, as extends\nThe vaulted tomb, discover\'d not by sight,\nBut by the sound of brooklet, that descends\nThis way along the hollow of a rock,\nWhich, as it winds with no precipitous course,\nThe wave hath eaten.  By that hidden way\nMy guide and I did enter, to return\nTo the fair world:  and heedless of repose\nWe climbed, he first, I following his steps,\nTill on our view the beautiful lights of heav\'n\nDawn, through a circular opening in the cave:\nThus issuing we again beheld the stars.\n\n\n\nNOTES TO HELL\n\nCANTO I\n\nVerse 1.  In the midway.]  That the era of the Poem is intended\nby these words ");
    strcat(expected_filecontent, "to be fixed to the thirty fifth year of the poet\'s\nage, A.D. 1300, will appear more plainly in Canto XXI. where that\ndate is explicitly marked.\n\nv. 16.  That planet\'s beam.]  The sun.\n\nv. 29.  The hinder foot.]  It is to be remembered, that in\nascending a hill the weight of the body rests on the hinder foot.\n\nv. 30.  A panther.]  Pleasure or luxury.\n\nv. 36.  With those stars.]  The sun was in Aries, in which sign\nhe supposes it to have begun its course at the creation.\n\nv. 43.  A lion.]  Pride or ambition.\n\nv. 45.  A she wolf.]  Avarice.\n\nv. 56.  Where the sun in silence rests.]  Hence Milton appears to\nhave taken his idea in the Samson Agonistes:\n\n        The sun to me is dark\n               And silent as the moon, &c\nThe same metaphor will recur, Canto V. v. 29.\n        Into a place I came\n       Where light was silent all.\n\nv. 65.  When the power of Julius.] This is explained by the\ncommentators to mean \"Although it was rather late with respect to\nmy birth before Julius Caesar assumed the supreme authority, and\nmade himself perpetual dictator.\"\n\nv. 98.  That greyhound.]  This passage is intended as an eulogium\non the liberal spirit of his Veronese patron Can Grande della\nScala.\n\nv. 102.  \'Twizt either Feltro.]  Verona, the country of Can della\nScala, is situated between Feltro, a city in the Marca\nTrivigiana, and Monte Feltro, a city in the territory of Urbino.\n\nv. 103.  Italia\'s plains.]  \"Umile Italia,\" from Virgil, Aen lib.\niii. 522.\n        Humilemque videmus\n       Italiam.\n\nv. 115.  Content in fire.]  The spirits in Purgatory.\n\nv. 118.  A spirit worthier.]  Beatrice, who conducts the Poet\nthrough Paradise.\n\nv. 130.  Saint Peter\'s gate.]  The gate of Purgatory, which the\nPoet feigns to be guarded by an angel placed on that station by\nSt. Peter.\n\nCANTO II\n\nv. 1.  Now was the day.]  A compendium of Virgil\'s description\nAen. lib. iv 522.  Nox erat, &c. Compare Apollonius Rhodius, lib\niii. 744, and lib. iv. 1058\n\nv. 8.  O mind.]\n        O thought that write all that I met,\n        And in the tresorie it set\n        Of my braine, now shall men see\n        If any virtue in thee be.\n               Chaucer.  Temple of Fame, b. ii. v.18\n\nv. 14.  Silvius\'sire.] Aeneas.\n\nv. 30.  The chosen vessel.]  St.Paul, Acts, c. ix. v. 15.  \"But\nthe Lord said unto him, Go thy way; for he is a chosen vessel\nunto me.\"\n\nv. 46.  Thy soul.] L\'anima tua e da viltate offesa. So in Berni,\nOrl Inn.lib. iii. c. i. st. 53.\n        Se l\'alma avete offesa da viltate.\n\nv. 64.  Who rest suspended.]  The spirits in Limbo, neither\nadmitted to a state of glory nor doomed to punishment.\n\nv. 61.  A friend not of my fortune, but myself.]  Se non fortunae\nsed hominibus solere esse amicum.  Cornelii Nepotis Attici Vitae,\nc. ix.\n\nv. 78.  Whatever is contain\'d.]  Every other thing comprised\nwithin the lunar heaven, which, being the lowest of all, has the\nsmallest circle.\n\nv. 93.  A blessed dame.]  The divine mercy.\n\nv. 97.  Lucia.]  The enlightening grace of heaven.\n\nv. 124.  Three maids.]  The divine mercy, Lucia, and Beatrice.\n\nv. 127.  As florets.]  This simile is well translated by\nChaucer--\n        But right as floures through the cold of night\n        Iclosed, stoupen in her stalkes lowe,\n        Redressen hem agen the sunne bright,\n        And speden in her kinde course by rowe, &c.\n               Troilus and Creseide, b.ii.\nIt has been imitated by many others, among whom see Berni,\nOrl.Inn. Iib. 1. c. xii. st. 86.  Marino, Adone, c. xvii. st. 63.\nand Sor. \"Donna vestita di nero.\" and Spenser\'s Faery Queen, b.4.\nc. xii. st. 34. and b. 6 c. ii. st. 35.\n\nCANTO III\n\nv. 5.          Power divine\n        Supremest wisdom, and primeval love.]  The three\npersons of the blessed Trinity.\nv. 9.  all hope abandoned.] Lasciate ogni speranza voi\nch\'entrate.\nSo Berni, Orl. Inn. lib. i. c. 8. st. 53.\n        Lascia pur della vita ogni speranza.\n\nv. 29.  Like to the sand.]\n               Unnumber\'d as the sands\n        Of Barca or Cyrene\'s torrid soil\n        Levied to side with warring winds, and poise\n        Their lighter wings.\n               Milton, P. L. ii. 908.");
    strcat(expected_filecontent, "\n\nv. 40.  Lest th\' accursed tribe.]  Lest the rebellious angels\nshould exult at seeing those who were neutral and therefore less\nguilty, condemned to the same punishment with themselves.\n\nv. 50.  A flag.]\n               All the grisly legions that troop\n        Under the sooty flag of Acheron\n               Milton. Comus.\n\nv. 56.         Who to base fear\n        Yielding, abjur\'d his high estate.] This is\ncommonly understood of Celestine the Fifth, who abdicated the\npapal power in 1294. Venturi mentions a work written by\nInnocenzio Barcellini, of the Celestine order, and printed in\nMilan in 1701, In which an attempt is made to put a different\ninterpretation on this passage.\n\nv. 70.  through the blear light.]\n        Lo fioco lume\nSo Filicaja, canz. vi. st. 12.\n        Qual fioco lume.\n\nv. 77.  An old man.]\n        Portitor has horrendus aquas et flumina servat\n        Terribili squalore Charon, cui plurima mento\n        Canities inculta jacet; stant lumina flamma.\n               Virg. 7.  Aen. Iib. vi. 2.\n\nv. 82.  In fierce heat and in ice.]\n               The delighted spirit\n        To bathe in fiery floods or to reside\n        In thrilling regions of thick ribbed ice.\n               Shakesp. Measure for Measure, a. iii.s.1.\nCompare Milton, P. L. b. ii. 600.\n\nv. 92.  The livid lake.] Vada livida.\n               Virg. Aen. Iib. vi. 320\n               Totius ut Lacus putidaeque paludis\n        Lividissima, maximeque est profunda vorago.\n               Catullus. xviii. 10.\n\nv. 102.  With eyes of burning coal.]\n        His looks were dreadful, and his fiery eyes\n        Like two great beacons glared bright and wide.\n               Spenser. F.Q. b. vi. c. vii.st. 42\n\nv. 104.  As fall off the light of autumnal leaves.]\n        Quam multa in silvis autumul frigore primo\n        Lapsa cadunt folia.\n               Virg. Aen. lib. vi. 309\nCompare Apoll.  Rhod. lib. iv. 214.\n\nCANTO IV\n\nv. 8.  A thund\'rous sound.]  Imitated, as Mr. Thyer has remarked,\nby Milton, P. L. b. viii. 242.\n               But long ere our approaching heard\n        Noise, other, than the sound of dance or song\n        Torment, and loud lament, and furious rage.\n\nv. 50.  a puissant one.]  Our Saviour.\n\nv. 75.                 Honour the bard\n        Sublime.]\n\n        Onorate l\'altissimo poeta.\nSo Chiabrera, Canz. Eroiche. 32.\n        Onorando l\'altissimo poeta.\n\nv. 79.  Of semblance neither sorrowful nor glad.]\n        She nas to sober ne to glad.\n               Chaucer\'s Dream.\n\nv. 90.  The Monarch of sublimest song.]  Homer.\n\nv. 100.  Fitter left untold.]\n        Che\'l tacere e bello,\nSo our Poet, in Canzone 14.\n        La vide in parte che\'l tacere e bello,\nRuccellai, Le Api, 789.\n        Ch\'a dire e brutto ed a tacerlo e bello\nAnd Bembo,\n        \"Vie pui bello e il tacerle, che il favellarne.\"\n               Gli. Asol. lib. 1.\n\nv. 117.  Electra.]  The daughter of Atlas, and mother of Dardanus\nthe founder of Troy.  See Virg. Aen. b. viii. 134. as referred to\nby Dante in treatise \"De Monarchia,\" lib. ii. \"Electra, scilicet,\nnata magni nombris regis Atlantis, ut de ambobus testimonium\nreddit poeta noster in octavo ubi Aeneas ad Avandrum sic ait\n        \"Dardanus Iliacae,\" &c.\n\nv. 125.  Julia.]  The daughter of Julius Caesar, and wife of\nPompey.\n\nv. 126.  The Soldan fierce.]  Saladin or Salaheddin, the  rival\nof  Richard coeur de lion.  See D\'Herbelot, Bibl. Orient. and\nKnolles\'s Hist. of the Turks p. 57 to 73 and the Life of Saladin,\nby Bohao\'edin Ebn Shedad, published by Albert Schultens, with a\nLatin translation. He is introduced by Petrarch in the Triumph of\nFame, c. ii\n\nv. 128.  The master of the sapient throng.]\n        Maestro di color che sanno.\nAristotle--Petrarch assigns the first place to Plato. See Triumph\nof Fame, c. iii.\nPulci, in his Morgante Maggiore, c. xviii. says,\n        Tu se\'il maestro di color che sanno.\n\nv. 132.               Democritus\n        Who sets the world at chance.]\nDemocritus,who maintained the world to have been formed by the\nfortuitous concourse of atoms.\n\nv. 140.  Avicen.]  See D\'Herbelot Bibl. Orient. article  Sina. He\n");
    strcat(expected_filecontent, "died in 1050.  Pulci here again imitates our poet:\n\n        Avicenna quel che il sentimento\n        Intese di Aristotile e i segreti,\n        Averrois che fece il gran comento.\n               Morg. Mag. c. xxv.\n\nv. 140.               Him who made\n        That commentary vast, Averroes.]\nAverroes, called by the Arabians Roschd, translated and commented\nthe works of Aristotle. According to Tiraboschi (storia della\nLett. Ital. t. v. 1. ii. c. ii. sect. 4.) he was the source of\nmodern philosophical impiety. The critic quotes some passages\nfrom Petrarch (Senil. 1. v. ep. iii. et. Oper. v. ii. p. 1143) to\nshow how strongly such sentiments prevailed in the time of that\npoet, by whom they were held in horror and detestation He adds,\nthat this fanatic admirer of Aristotle translated his writings\nwith that felicity, which might be expected from one who did not\nknow a syllable of Greek, and who was therefore compelled to\navail himself of the unfaithful Arabic versions. D\'Herbelot, on\nthe other hand, informs us, that \"Averroes was the first who\ntranslated Aristotle from Greek into Arabic, before the Jews had\nmade their translation:  and that we had for a long time no other\ntext of Aristotle, except that of the Latin translation, which\nwas made from this Arabic version of this great philosopher\n(Averroes), who afterwards added to it a very ample commentary,\nof which Thomas Aquinas, and the other scholastic writers,\navailed themselves, before the Greek originals of Aristotle and\nhis commentators were known to us in Europe.\" According to\nD\'Herbelot, he died in 1198: but Tiraboschi places that event\nabout 1206.\n\nCANTO V\n\nv. 5.  Grinning with ghastly feature.]  Hence Milton:\n               Death\n        Grinn\'d horrible a ghastly smile.\n               P. L. b. ii. 845.\n\nv. 46.  As cranes.]  This simile is imitated by Lorenzo de\nMedici, in his Ambra, a poem, first published by Mr. Roscoe, in\nthe  Appendix to his Life of Lorenzo.\n        Marking the tracts of air, the clam");
                
        
                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "COMMON.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 14273, file);
                test_error(size == 14273, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 14273 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 14273);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 14273);


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
    
        
                char *filecontent = (char *)calloc(14336, 1);
                char expected_filecontent[14337] = "";
        
                strcat(expected_filecontent, "y leader\'s feet still equaling pace\nFrom forth that cloud I came, when now expir\'d\nThe parting beams from off the nether shores.\n     O quick and forgetive power!  that sometimes dost\nSo rob us of ourselves, we take no mark\nThough round about us thousand trumpets clang!\nWhat moves thee, if the senses stir not?  Light\nKindled in heav\'n, spontaneous, self-inform\'d,\nOr likelier gliding down with swift illapse\nBy will divine.  Portray\'d before me came\nThe traces of her dire impiety,\nWhose form was chang\'d into the bird, that most\nDelights itself in song: and here my mind\nWas inwardly so wrapt, it gave no place\nTo aught that ask\'d admittance from without.\n     Next shower\'d into my fantasy a shape\nAs of one crucified, whose visage spake\nFell rancour, malice deep, wherein he died;\nAnd round him Ahasuerus the great king,\nEsther his bride, and Mordecai the just,\nBlameless in word and deed.  As of itself\nThat unsubstantial coinage of the brain\nBurst, like a bubble, Which the water fails\nThat fed it; in my vision straight uprose\nA damsel weeping loud, and cried, \"O queen!\nO mother!  wherefore has intemperate ire\nDriv\'n thee to loath thy being?  Not to lose\nLavinia, desp\'rate thou hast slain thyself.\nNow hast thou lost me.  I am she, whose tears\nMourn, ere I fall, a mother\'s timeless end.\"\n     E\'en as a sleep breaks off, if suddenly\nNew radiance strike upon the closed lids,\nThe broken slumber quivering ere it dies;\nThus from before me sunk that imagery\nVanishing, soon as on my face there struck\nThe light, outshining far our earthly beam.\nAs round I turn\'d me to survey what place\nI had arriv\'d at, \"Here ye mount,\" exclaim\'d\nA voice, that other purpose left me none,\nSave will so eager to behold who spake,\nI could not choose but gaze.  As \'fore the sun,\nThat weighs our vision down, and veils his form\nIn light transcendent, thus my virtue fail\'d\nUnequal.  \"This is Spirit from above,\nWho marshals us our upward way, unsought;\nAnd in his own light shrouds him;. As a man\nDoth for himself, so now is done for us.\nFor whoso waits imploring, yet sees need\nOf his prompt aidance, sets himself prepar\'d\nFor blunt denial, ere the suit be made.\nRefuse we not to lend a ready foot\nAt such inviting: haste we to ascend,\nBefore it darken: for we may not then,\nTill morn again return.\"  So spake my guide;\nAnd to one ladder both address\'d our steps;\nAnd the first stair approaching, I perceiv\'d\nNear me as \'twere the waving of a wing,\nThat fann\'d my face and whisper\'d: \"Blessed they\nThe peacemakers: they know not evil wrath.\"\n     Now to such height above our heads were rais\'d\nThe last beams, follow\'d close by hooded night,\nThat many a star on all sides through the gloom\nShone out.  \"Why partest from me, O my strength?\"\nSo with myself I commun\'d; for I felt\nMy o\'ertoil\'d sinews slacken.  We had reach\'d\nThe summit, and were fix\'d like to a bark\nArriv\'d at land.  And waiting a short space,\nIf aught should meet mine ear in that new round,\nThen to my guide I turn\'d, and said: \"Lov\'d sire!\nDeclare what guilt is on this circle purg\'d.\nIf our feet rest, no need thy speech should pause.\"\n     He thus to me:  \"The love of good, whate\'er\nWanted of just proportion, here fulfils.\nHere plies afresh the oar, that loiter\'d ill.\nBut that thou mayst yet clearlier understand,\nGive ear unto my words, and thou shalt cull\nSome fruit may please thee well, from this delay.\n     \"Creator, nor created being, ne\'er,\nMy son,\" he thus began, \"was without love,\nOr natural, or the free spirit\'s growth.\nThou hast not that to learn.  The natural still\nIs without error; but the other swerves,\nIf on ill object bent, or through excess\nOf vigour, or defect.  While e\'er it seeks\nThe primal blessings, or with measure due\nTh\' inferior, no delight, that flows from it,\nPartakes of ill.  But let it warp to evil,\nOr with more ardour than behooves, or less.\nPursue the good, the thing created then\nWorks \'gainst its Maker.  Hence thou must infer\nThat love is germin of each virtue in ye,\nAnd of each act no less, that merits pain.\nNow since it may not be, but love intend\nThe welfare mainly of the thing i");
    strcat(expected_filecontent, "t loves,\nAll from self-hatred are secure; and since\nNo being can be thought t\' exist apart\nAnd independent of the first, a bar\nOf equal force restrains from hating that.\n     \"Grant the distinction just; and it remains\nThe\' evil must be another\'s, which is lov\'d.\nThree ways such love is gender\'d in your clay.\nThere is who hopes (his neighbour\'s worth deprest,)\nPreeminence himself, and coverts hence\nFor his own greatness that another fall.\nThere is who so much fears the loss of power,\nFame, favour, glory (should his fellow mount\nAbove him), and so sickens at the thought,\nHe loves their opposite: and there is he,\nWhom wrong or insult seems to gall and shame\nThat he doth thirst for vengeance, and such needs\nMust doat on other\'s evil.  Here beneath\nThis threefold love is mourn\'d.  Of th\' other sort\nBe now instructed, that which follows good\nBut with disorder\'d and irregular course.\n     \"All indistinctly apprehend a bliss\nOn which the soul may rest, the hearts of all\nYearn after it, and to that wished bourn\nAll therefore strive to tend.  If ye behold\nOr seek it with a love remiss and lax,\nThis cornice after just repenting lays\nIts penal torment on ye.  Other good\nThere is, where man finds not his happiness:\nIt is not true fruition, not that blest\nEssence, of every good the branch and root.\nThe love too lavishly bestow\'d on this,\nAlong three circles over us, is mourn\'d.\nAccount of that division tripartite\nExpect not, fitter for thine own research.\n\n\n\nCANTO XVIII\n\nThe teacher ended, and his high discourse\nConcluding, earnest in my looks inquir\'d\nIf I appear\'d content; and I, whom still\nUnsated thirst to hear him urg\'d, was mute,\nMute outwardly, yet inwardly I said:\n\"Perchance my too much questioning offends\nBut he, true father, mark\'d the secret wish\nBy diffidence restrain\'d, and speaking, gave\nMe boldness thus to speak: \"Master, my Sight\nGathers so lively virtue from thy beams,\nThat all, thy words convey, distinct is seen.\nWherefore I pray thee, father, whom this heart\nHolds dearest!  thou wouldst deign by proof t\' unfold\nThat love, from which as from their source thou bring\'st\nAll good deeds and their opposite.\"  He then:\n\"To what I now disclose be thy clear ken\nDirected, and thou plainly shalt behold\nHow much those blind have err\'d, who make themselves\nThe guides of men.  The soul, created apt\nTo love, moves versatile which way soe\'er\nAught pleasing prompts her, soon as she is wak\'d\nBy pleasure into act.  Of substance true\nYour apprehension forms its counterfeit,\nAnd in you the ideal shape presenting\nAttracts the soul\'s regard.  If she, thus drawn,\nincline toward it, love is that inclining,\nAnd a new nature knit by pleasure in ye.\nThen as the fire points up, and mounting seeks\nHis birth-place and his lasting seat, e\'en thus\nEnters the captive soul into desire,\nWhich is a spiritual motion, that ne\'er rests\nBefore enjoyment of the thing it loves.\nEnough to show thee, how the truth from those\nIs hidden, who aver all love a thing\nPraise-worthy in itself: although perhaps\nIts substance seem still good.  Yet if the wax\nBe good, it follows not th\' impression must.\"\n\"What love is,\" I return\'d, \"thy words, O guide!\nAnd my own docile mind, reveal.  Yet thence\nNew doubts have sprung.  For from without if love\nBe offer\'d to us, and the spirit knows\nNo other footing, tend she right or wrong,\nIs no desert of hers.\"  He answering thus:\n\"What reason here discovers I have power\nTo show thee: that which lies beyond, expect\nFrom Beatrice, faith not reason\'s task.\nSpirit, substantial form, with matter join\'d\nNot in confusion mix\'d, hath in itself\nSpecific virtue of that union born,\nWhich is not felt except it work, nor prov\'d\nBut through effect, as vegetable life\nBy the green leaf.  From whence his intellect\nDeduced its primal notices of things,\nMan therefore knows not, or his appetites\nTheir first affections; such in you, as zeal\nIn bees to gather honey; at the first,\nVolition, meriting nor blame nor praise.\nBut o\'er each lower faculty supreme,\nThat as she list are summon\'d to her bar,\nYe have that virtue in you, whose just voice\nUttereth co");
    strcat(expected_filecontent, "unsel, and whose word should keep\nThe threshold of assent.  Here is the source,\nWhence cause of merit in you is deriv\'d,\nE\'en as the affections good or ill she takes,\nOr severs, winnow\'d as the chaff.  Those men\nWho reas\'ning went to depth profoundest, mark\'d\nThat innate freedom, and were thence induc\'d\nTo leave their moral teaching to the world.\nGrant then, that from necessity arise\nAll love that glows within you; to dismiss\nOr harbour it, the pow\'r is in yourselves.\nRemember, Beatrice, in her style,\nDenominates free choice by eminence\nThe noble virtue, if in talk with thee\nShe touch upon that theme.\"  The moon, well nigh\nTo midnight hour belated, made the stars\nAppear to wink and fade; and her broad disk\nSeem\'d like a crag on fire, as up the vault\nThat course she journey\'d, which the sun then warms,\nWhen they of Rome behold him at his set.\nBetwixt Sardinia and the Corsic isle.\nAnd now the weight, that hung upon my thought,\nWas lighten\'d by the aid of that clear spirit,\nWho raiseth Andes above Mantua\'s name.\nI therefore, when my questions had obtain\'d\nSolution plain and ample, stood as one\nMusing in dreary slumber; but not long\nSlumber\'d; for suddenly a multitude,\nThe steep already turning, from behind,\nRush\'d on.  With fury and like random rout,\nAs echoing on their shores at midnight heard\nIsmenus and Asopus, for his Thebes\nIf Bacchus\' help were needed; so came these\nTumultuous, curving each his rapid step,\nBy eagerness impell\'d of holy love.\n     Soon they o\'ertook us; with such swiftness mov\'d\nThe mighty crowd.  Two spirits at their head\nCried weeping; \"Blessed Mary sought with haste\nThe hilly region.  Caesar to subdue\nIlerda, darted in Marseilles his sting,\nAnd flew to Spain.\"--\"Oh tarry not: away;\"\nThe others shouted; \"let not time be lost\nThrough slackness of affection.  Hearty zeal\nTo serve reanimates celestial grace.\"\n     \"O ye, in whom intenser fervency\nHaply supplies, where lukewarm erst ye fail\'d,\nSlow or neglectful, to absolve your part\nOf good and virtuous, this man, who yet lives,\n(Credit my tale, though strange) desires t\' ascend,\nSo morning rise to light us.  Therefore say\nWhich hand leads nearest to the rifted rock?\"\n     So spake my guide, to whom a shade return\'d:\n\"Come after us, and thou shalt find the cleft.\nWe may not linger: such resistless will\nSpeeds our unwearied course.  Vouchsafe us then\nThy pardon, if our duty seem to thee\nDiscourteous rudeness.  In Verona I\nWas abbot of San Zeno, when the hand\nOf Barbarossa grasp\'d Imperial sway,\nThat name, ne\'er utter\'d without tears in Milan.\nAnd there is he, hath one foot in his grave,\nWho for that monastery ere long shall weep,\nRuing his power misus\'d: for that his son,\nOf body ill compact, and worse in mind,\nAnd born in evil, he hath set in place\nOf its true pastor.\"  Whether more he spake,\nOr here was mute, I know not: he had sped\nE\'en now so far beyond us.  Yet thus much\nI heard, and in rememb\'rance treasur\'d it.\n     He then, who never fail\'d me at my need,\nCried, \"Hither turn.  Lo!  two with sharp remorse\nChiding their sin!\"  In rear of all the troop\nThese shouted:  \"First they died, to whom the sea\nOpen\'d, or ever Jordan saw his heirs:\nAnd they, who with Aeneas to the end\nEndur\'d not suffering, for their portion chose\nLife without glory.\"  Soon as they had fled\nPast reach of sight, new thought within me rose\nBy others follow\'d fast, and each unlike\nIts fellow: till led on from thought to thought,\nAnd pleasur\'d with the fleeting train, mine eye\nWas clos\'d, and meditation chang\'d to dream.\n\n\nCANTO XIX\n\nIt was the hour, when of diurnal heat\nNo reliques chafe the cold beams of the moon,\nO\'erpower\'d by earth, or planetary sway\nOf Saturn; and the geomancer sees\nHis Greater Fortune up the east ascend,\nWhere gray dawn checkers first the shadowy cone;\nWhen \'fore me in my dream a woman\'s shape\nThere came, with lips that stammer\'d, eyes aslant,\nDistorted feet, hands maim\'d, and colour pale.\n     I look\'d upon her; and as sunshine cheers\nLimbs numb\'d by nightly cold, e\'en thus my look\nUnloos\'d her tongue, next in brief space her form\nDecrepit rais\'d erect, ");
    strcat(expected_filecontent, "and faded face\nWith love\'s own hue illum\'d. Recov\'ring speech\nShe forthwith warbling such a strain began,\nThat I, how loth soe\'er, could scarce have held\nAttention from the song.  \"I,\" thus she sang,\n\"I am the Siren, she, whom mariners\nOn the wide sea are wilder\'d when they hear:\nSuch fulness of delight the list\'ner feels.\nI from his course Ulysses by my lay\nEnchanted drew.  Whoe\'er frequents me once\nParts seldom; so I charm him, and his heart\nContented knows no void.\"  Or ere her mouth\nWas clos\'d, to shame her at her side appear\'d\nA dame of semblance holy.  With stern voice\nShe utter\'d; \"Say, O Virgil, who is this?\"\nWhich hearing, he approach\'d, with eyes still bent\nToward that goodly presence: th\' other seiz\'d her,\nAnd, her robes tearing, open\'d her before,\nAnd show\'d the belly to me, whence a smell,\nExhaling loathsome, wak\'d me.  Round I turn\'d\nMine eyes, and thus the teacher:  \"At the least\nThree times my voice hath call\'d thee.  Rise, begone.\nLet us the opening find where thou mayst pass.\"\n     I straightway rose.  Now day, pour\'d down from high,\nFill\'d all the circuits of the sacred mount;\nAnd, as we journey\'d, on our shoulder smote\nThe early ray.  I follow\'d, stooping low\nMy forehead, as a man, o\'ercharg\'d with thought,\nWho bends him to the likeness of an arch,\nThat midway spans the flood; when thus I heard,\n\"Come, enter here,\" in tone so soft and mild,\nAs never met the ear on mortal strand.\n     With swan-like wings dispread and pointing up,\nWho thus had spoken marshal\'d us along,\nWhere each side of the solid masonry\nThe sloping, walls retir\'d; then mov\'d his plumes,\nAnd fanning us, affirm\'d that those, who mourn,\nAre blessed, for that comfort shall be theirs.\n     \"What aileth thee, that still thou look\'st to earth?\"\nBegan my leader; while th\' angelic shape\nA little over us his station took.\n     \"New vision,\" I replied, \"hath rais\'d in me\n8urmisings strange and anxious doubts, whereon\nMy soul intent allows no other thought\nOr room or entrance.--\"Hast thou seen,\" said he,\n\"That old enchantress, her, whose w");
                
        
                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "SOME.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 14336, file);
                test_error(size == 14336, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 14336 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 14336);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 14336);


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
    
        
                char *filecontent = (char *)calloc(14150, 1);
                char expected_filecontent[14151] = "";
        
                strcat(expected_filecontent, "ed in 1312, at\nthe age of twenty four, in consequence, as it was supposed, of\nhis extreme intemperance.\nSee Mariana, Hist I. xv.  c. 11.\n\nv. 123.  The Bohemian.]  Winceslaus II.  Purgatory, Canto VII. v.\n\nv. 125.  The halter of Jerusalem.]  Charles II of Naples and\nJerusalem who was lame.  See note to Purgatory, Canto VII.  v.\n122, and XX. v. 78.\n\nv. 127.  He.]  Frederick of Sicily son of Peter III of Arragon.\nPurgatory, Canto VII.  v. 117.  The isle of fire is Sicily, where\nwas the tomb of Anchises.\n\nv. 133.  His uncle.]  James, king of Majorca and Minorca, brother\nto Peter III.\n\nv. 133.  His brother.]  James II of Arragon, who died in 1327.\nSee Purgatory, Canto VII.  v. 117.\n\nv. 135.  Of Portugal.]  In the time of Dante, Dionysius was king\nof Portugal.  He died in 1328, after a reign of near forty-six\nyears, and does not seem to have deserved the stigma here\nfastened on him. See Mariana. and 1. xv. c. 18.  Perhaps the\nrebellious son of Dionysius may be alluded to.\n\nv. 136.  Norway.]  Haquin, king of Norway, is probably meant;\nwho, having given refuge to the murderers of Eric VII king of\nDenmark, A D. 1288, commenced a war against his successor, Erie\nVIII, \"which continued for nine years, almost to the utter ruin\nand destruction of both kingdoms.\"  Modern Univ. Hist. v. xxxii\np. 215.\n\nv. 136.  -Him\nOf Ratza.]\nOne of the dynasty of the house of Nemagna, which ruled the\nkingdom of Rassia, or Ratza, in Sclavonia, from 1161 to 1371, and\nwhose history may be found in Mauro Orbino, Regno degli Slavi,\nEdiz. Pesaro. 1601. Uladislaus appears to have been the sovereign\nin Dante\'s time, but the disgraceful forgery adverted to in the\ntext, is not recorded by the historian v. 138.  Hungary.]  The\nkingdom of Hungary was about this time disputed by Carobert, son\nof Charles Martel, and Winceslaus, prince of Bohemia, son of\nWinceslaus II.  See Coxe\'s House of Austria, vol. i. p. 1. p. 86.\n\n4to edit.\n\nv. 140.  Navarre.]  Navarre was now under the yoke of France.\n It soon after (in 1328) followed the advice of Dante and had a\nmonarch of its own.  Mariana, 1.  xv. c. 19.\n\nv. 141.  Mountainous girdle.]  The Pyrenees.\n\nv. 143.  -Famagosta\'s streets\nAnd Nicosia\'s.]\n\nCities in the kingdom of Cyprus, at that time ruled by Henry II a\npusillanimous prince. Vertot.  Hist. des Chev.  de Malte, 1. iii.\niv. The meaning appears to be, that the complaints made by those\ncities of their weak and worthless governor, may be regarded as\nan earnest of his condemnation at the last doom.\n\nCANTO XX\n\nv. 6.  Wherein one shines.]  The light of the sun, whence he\nsupposes the other celestial bodies to derive their light\n\nv. 8.  The great sign.]  The eagle, the Imperial ensign.\n\nv. 34.  Who.]  David.\n\nv. 39.  He.]  Trajan.  See Purgatory, Canto X. 68.\n\nv. 44.  He next.]  Hezekiah.\n\nv. 50.  \'The other following.]  Constantine.  There is no passage\nin which Dante\'s opinion of the evil; that had arisen from the\nmixture of the civil with the ecclesiastical power, is more\nunequivocally  declared.\n\nv. 57.  William.]  William II, king of Sicily, at the latter part\nof  the twelfth century He was of the Norman line of sovereigns,\nand obtained the appellation of \"the Good\" and, as the poet says\nhis loss was as much the subject of regret in his dominions, as\nthe presence of Charles I of Anjou and Frederick of Arragon, was\nof sorrow and complaint.\n\nv. 62.  Trojan Ripheus.]\nRipheus, justissimus unus\nQui fuit in Teneris, et servantissimus aequi.\nVirg.  Aen.  1. ii. 4--.\n\nv. 97.  This.]  Ripheus.\n\nv. 98.  That.]  Trajan.\n\nv. 103.  The prayers,] The prayers of St. Gregory\n\nv. 119.  The three nymphs.]  Faith, Hope, and Charity. Purgatory,\nCanto XXIX.  116.\nv. 138.  The pair.]  Ripheus and Trajan.\n\nCANTO XXI\n\nv. 12.  The seventh splendour.]  The planet Saturn\n\nv. 13.  The burning lion\'s breast.]  The constellation Leo.\n\nv. 21.  In equal balance.]  \"My pleasure was as great in\ncomplying\nwith her will as in beholding her countenance.\"\n\nv. 24.  Of that lov\'d monarch.]  Saturn.  Compare Hell, Canto\nXIV.  91.\n\nv. 56.  What forbade the smile.]  \"Because it would have overcome\nthee.\"\n\nv. 6");
    strcat(expected_filecontent, "1.  There aloft.]  Where the other souls were.\n\nv. 97.  A stony ridge.]  The Apennine.\n\nv. 112.  Pietro Damiano.]  \"S. Pietro Damiano obtained a great\nand well-merited reputation, by the pains he took to correct the\nabuses among the clergy.  Ravenna is supposed to have been the\nplace of his birth, about 1007.  He was employed in several\nimportant missions, and rewarded by Stephen IX with the dignity\nof cardinal, and the bishopric of Ostia, to which, however, he\npreferred his former retreat in the monastery of Fonte Aveliana,\nand prevailed on Alexander II to permit him to retire thither.\nYet he did not long continue in this seclusion, before he was\nsent on other embassies.  He died at Faenza in 1072.  His\nletters throw much light on the obscure history of these times.\nBesides them, he has left several treatises on sacred and\necclesiastical subjects. His eloquence is worthy of a better\nage.\"  Tiraboschi, Storia della Lett Ital. t. iii.  1. iv. c. 2.\n\nv. 114.  Beside the Adriatic.]  At Ravenna.  Some editions have\nFU instead of FUI, according to which reading, Pietro\ndistinguishes  himself from another Pietro, who was termed\n\"Peccator,\" the sinner.\n\nv. 117.  The hat.]  The cardinal\'s hat.\n\nv. 118.  Cephas.]  St. Peter.\n\nv. 119 The Holy Spirit\'s vessel.]  St. Paul. See Hell, Canto II.\n30.\n\nv. 130.  Round this.]  Round the spirit of Pietro Damiano.\n\nCANTO XXII\n\nv. 14.  The vengeance.]  Beatrice, it is supposed, intimates the\napproaching fate of Boniface VIII.  See Purgatory, Canto XX.  86.\n\nv. 36.  Cassino.]  A castle in the Terra di Lavoro.\n\nv. 38.  I it was.]  \"A new order of monks, which in a manner\nabsorbed all the others that were established in the west, was\ninstituted, A.D.  529, by Benedict of Nursis, a man of piety and\nreputation for the age he  lived in.\"  Maclaine\'s Mosheim,\nEccles. Hist. v. ii.  cent. vi. p. 2. ch.  2 - 6.\n\nv. 48.  Macarius.]  There are two of this name enumerated by\nMosheim among the Greek theologians of the fourth century, v. i.\ncent. iv p. 11 ch. 2 - 9.  In the following chapter, 10, it is\nsaid, \"Macarius, an Egyptian monk, undoubtedly deserves the first\nrank among the practical matters of this time, as his works\ndisplayed, some few things excepted, the brightest and most\nlovely portraiture of sanctity and virtue.\"\n\nv. 48.  Romoaldo.]  S. Romoaldo, a native of Ravenna, and the\nfounder of the order of Camaldoli, died in 1027.  He was the\nauthor of a commentary on the Psalms.\n\nv. 70.  The patriarch Jacob.]  So Milton, P. L. b. iii. 510:\nThe stairs were such, as whereon Jacob saw\nAngels ascending and descending, bands\nOf guardians bright.\n\nv. 107.  The sign.]  The constellation of Gemini.\n\nv. 130. This globe.]  So Chaucer, Troilus and Cresseide, b. v,\n\nAnd down from thence fast he gan avise\nThis little spot of earth, that with the sea\nEmbraced is, and fully gan despite\nThis wretched world.\n\nCompare Cicero, Somn. Scip.  \"Jam ipsa terra ita mihi parva visa\nest.\" &c.  Lucan, Phar 1.  ix. 11;  and Tasso, G.  L.  c.  xiv.\nst, 9, 10, 11.\n\nv. 140.  Maia and Dione.]  The planets Mercury and Venus.\n\nCANTO XXIII\n\nv. 11.  That region.]  Towards the south, where the course of the\nsun appears less rapid, than, when he is in the east or the west.\n\nv. 26.  Trivia.]  A name of Diana.\n\nv. 26.  Th\' eternal nymphs.]  The stars.\n\nv. 36.  The Might.]  Our Saviour\n\nv. 71.  The rose.]  The Virgin Mary.\n\nv. 73.  The lilies.]  The apostles.\n\nv. 84.  Thou didst exalt thy glory.]  The diving light retired\nupwards, to render the eyes of Dante more capable of enduring the\nspectacle  which now presented itself.\n\nv. 86.  The name of that fair flower.]  The name of the Virgin.\n\nv. 92.  A cresset.]  The angel Gabriel.\n\nv. 98.  That lyre.]  By synecdoche, the lyre is put for the angel\n\nv. 99.  The goodliest sapphire.]  The Virgin\n\nv. 126.  Those rich-laden coffers.]  Those spirits who, having\nsown the seed of good works on earth, now contain the fruit of\ntheir pious endeavours.\n\nv. 129.  In the Babylonian exile.]  During their abode in this\nworld.\n\nv. 133.  He.]  St. Peter, with the other holy men of the Old and\nNew testament.\n\nC");
    strcat(expected_filecontent, "ANTO XXIV\n\nv. 28.  Such folds.]  Pindar has the same bold image:\n[GREEK HERE?]\nOn which Hayne strangely remarks:  Ad ambitus stropharum vldetur\n\nv. 65.  Faith.]  Hebrews, c.  xi.  1.  So Marino, in one of his\nsonnets, which calls Divozioni:\n\nFede e sustanza di sperate cose,\nE delle non visioili argomento.\n\nv. 82.  Current.]  \"The answer thou hast made is right; but let\nme know if thy inward persuasion is conformable to thy\nprofession.\"\n\nv. 91.  The ancient bond and new.]  The Old and New Testament.\n\nv. 114.  That Worthy.]  Quel Baron.\nIn the next Canto, St. James is called \"Barone.\"  So in\nBoccaccio, G. vi. N. 10, we find \"Baron Messer Santo Antonio.\"\nv. 124.  As to outstrip.]  Venturi insists that the Poet has\nhere, \"made a slip;\" for that John came first to the sepulchre,\nthough Peter was the first to enter it.  But let Dante have leave\nto explain his own meaning, in a passage from his third book De\nMonarchia:  \"Dicit etiam Johannes ipsum (scilicet Petrum)\nintroiisse SUBITO, cum venit in monumentum, videns allum\ndiscipulum cunctantem ad ostium.\" Opere de Dante, Ven. 1793. T.\nii. P. 146.\n\nCANTO XXV\n\nv. 6.  The fair sheep-fold.]  Florence, whence he was banished.\n\nv. 13.  For its sake.]  For the sake of that faith.\n\nv. 20.  Galicia throng\'d with visitants.] See Mariana, Hist. 1.\nxi.\n\nv. 13.  \"En el tiempo,\" &c.  \"At the time that the sepulchre of\nthe apostle St. James was discovered, the devotion for that place\nextended itself not only over all Spain, but even round about to\nforeign nations. Multitudes from all parts of the world came to\nvisit it.  Many others were deterred by the difficulty for the\njourney, by the roughness and barrenness of those parts, and by\nthe incursions of the Moors, who made captives many of the\npilgrims.  The canons of St. Eloy afterwards (the precise time is\nnot known), with a desire of remedying these evils, built, in\nmany places, along the whole read, which reached as far as to\nFrance, hospitals for the reception of the pilgrims.\"\n\nv. 31.  Who.]  The Epistle of St. James is here attributed to the\nelder apostle of that name, whose shrine was at Compostella, in\nGalicia.  Which of the two was the author of it is yet doubtful.\nThe learned and candid Michaelis contends very forcibly for its\nhaving been written by James the Elder.  Lardner rejects that\nopinion as absurd; while Benson argues against it, but is well\nanswered by Michaelis, who after all, is obliged to leave the\nquestion undecided.  See his Introduction to the New Testament,\ntranslated by Dr. Marsh, ed.  Cambridge, 1793.  V. iv. c.  26.  -\n1, 2, 3.\n\nv. 35.  As Jesus.]  In the transfiguration on Mount Tabor.\n\nv. 39.  The second flame.]  St. James.\n\nv. 40.  I lifted up.]  \"I will lift up mine eyes unto the hills,\nfrom whence cometh my help.\"  Ps.  Cxxi.  1.\n\nv. 59.  From Egypt to Jerusalem.]  From the lower world to\nheaven.\n\nv. 67.  Hope.]  This is from the Sentences of Petrus Lombardus.\n\"Est autem spes virtus, qua spiritualia et aeterna bona speratam,\nid  est, beatitudinem aeternam.  Sine meritis enim aliquid\nsperare non spes, sed praesumptio, dici potest.\"  Pet. Lomb.\nSent.  1.  Iii.  Dist.  26.   Ed. Bas.  1486.  Fol.\n\nv. 74.  His anthem.]  Psalm ix.  10.\n\nv. 90.  Isaias ]  Chap. lxi. 10.\n\nv. 94.  Thy brother.]  St. John in the Revelation, c. vii.  9.\n\nv. 101.  Winter\'s month.]  \"If a luminary, like that which now\nappeared, were to shine throughout the month following the winter\nsolstice during which the constellation Cancer appears in the\neast at the setting of the sun, there would be no interruption to\nthe light, but the whole month would be as a single day.\"\n\nv. 112.  This.]  St. John, who reclined on the bosom of our\nSaviour, and to whose charge Jesus recommended his mother.\n\nv. 121.  So I.]  He looked so earnestly, to descry whether St.\nJohn were present there in body, or in spirit only, having had\nhis doubts raised  by that saying of our Saviour\'s:  \"If I will,\nthat he tarry till I come  what is that to thee.\"\n\nv. 127.  The two.]  Christ and Mary, whom he has described, in\nthe last Canto but one, as rising above his sight\n\nCANT");
    strcat(expected_filecontent, "O XXVI\n\nv. 2.  The beamy flame.]  St. John.\n\nv. 13.  Ananias\' hand.]  Who, by putting his hand on St. Paul,\nrestored his sight.  Acts, c. ix.  17.\n\nv. 36.  From him.]  Some suppose that Plato is here meant, who,\nin his Banquet, makes Phaedrus say:  \"Love is confessedly amongst\nthe eldest of beings, and, being the eldest, is the cause to us\nof the greatest goods \" Plat. Op. t. x. p. 177.  Bip.  ed. Others\nhave understood it of Aristotle, and others, of the writer who\ngoes by the name of Dionysius the Areopagite, referred to in the\ntwenty-eighth Canto.\n\nv. 40.  I will make.]  Exodus, c. xxxiii. 19.\n\nv. 42.  At the outset.]  John, c. i. 1.  &c.\n\nv. 51.  The eagle of our Lord.]  St. John\n\nv. 62.  The leaves.]  Created beings.\n\nv. 82.  The first living soul.]  Adam.\n\nv. 107.  Parhelion.]  Who enlightens and comprehends all things;\nbut is himself enlightened and comprehended by none.\n\nv. 117.  Whence.]  That is, from Limbo.  See Hell, Canto II.  53.\nAdam says that 5232 years elapsed from his creation to the time\nof his deliverance, which followed the death of Christ.\n\nv. 133.  EL]  Some read UN, \"One,\" instead of EL:  but the latter\nof these readings is confirmed by a passage from Dante\'s Treatise\nDe Vulg. Eloq. 1. i. cap. 4. \"Quod prius vox primi loquentis\nsonaverit, viro sanae mentis in promptu esse non dubito ipsum\nfuisse quod Deus est, videlicet El.\"  St. Isidore in the\nOrigines, 1.  vii. c. 1. had said, \"Primum apud Hebraeos Dei\nnomen El dicitur.\"\n\nv. 135.  Use.]  From Horace, Ars. Poet. 62.\n\nv. 138.  All my life.]  \"I remained in the terrestrial Paradise\nonly tothe seventh hour.\"  In the Historia Scolastica of Petrus\nComestor, it is said of our first parents:  Quidam tradunt eos\nfuisse in Paradiso septem horae.\"  I. 9. ed. Par. 1513. 4to.\n\nCANTO XXVII\n\nv.  1.  Four torches.]  St. Peter, St. James, St. John, and Adam.\n\nv. 11.  That.] ");
                
        
                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "HAPPEN.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 14150, file);
                test_error(size == 14150, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 14150 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 14150);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 14150);


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
    
        
                char *filecontent = (char *)calloc(6913, 1);
                char expected_filecontent[6914] = "";
        
                strcat(expected_filecontent, "st gives\nIts temper and impression.  Morning there,\nHere eve was by almost such passage made;\nAnd whiteness had o\'erspread that hemisphere,\nBlackness the other part; when to the left\nI saw Beatrice turn\'d, and on the sun\nGazing, as never eagle fix\'d his ken.\nAs from the first a second beam is wont\nTo issue, and reflected upwards rise,\nE\'en as a pilgrim bent on his return,\nSo of her act, that through the eyesight pass\'d\nInto my fancy, mine was form\'d; and straight,\nBeyond our mortal wont, I fix\'d mine eyes\nUpon the sun.  Much is allowed us there,\nThat here exceeds our pow\'r; thanks to the place\nMade for the dwelling of the human kind\n     I suffer\'d it not long, and yet so long\nThat I beheld it bick\'ring sparks around,\nAs iron that comes boiling from the fire.\nAnd suddenly upon the day appear\'d\nA day new-ris\'n, as he, who hath the power,\nHad with another sun bedeck\'d the sky.\n     Her eyes fast fix\'d on the eternal wheels,\nBeatrice stood unmov\'d; and I with ken\nFix\'d upon her, from upward gaze remov\'d\nAt her aspect, such inwardly became\nAs Glaucus, when he tasted of the herb,\nThat made him peer among the ocean gods;\nWords may not tell of that transhuman change:\nAnd therefore let the example serve, though weak,\nFor those whom grace hath better proof in store\n     If I were only what thou didst create,\nThen newly, Love!  by whom the heav\'n is rul\'d,\nThou know\'st, who by thy light didst bear me up.\nWhenas the wheel which thou dost ever guide,\nDesired Spirit!  with its harmony\nTemper\'d of thee and measur\'d, charm\'d mine ear,\nThen seem\'d to me so much of heav\'n to blaze\nWith the sun\'s flame, that rain or flood ne\'er made\nA lake so broad.  The newness of the sound,\nAnd that great light, inflam\'d me with desire,\nKeener than e\'er was felt, to know their cause.\n     Whence she who saw me, clearly as myself,\nTo calm my troubled mind, before I ask\'d,\nOpen\'d her lips, and gracious thus began:\n\"With false imagination thou thyself\nMak\'st dull, so that thou seest not the thing,\nWhich thou hadst seen, had that been shaken off.\nThou art not on the earth as thou believ\'st;\nFor light\'ning scap\'d from its own proper place\nNe\'er ran, as thou hast hither now return\'d.\"\n     Although divested of my first-rais\'d doubt,\nBy those brief words, accompanied with smiles,\nYet in new doubt was I entangled more,\nAnd said:  \"Already satisfied, I rest\nFrom admiration deep, but now admire\nHow I above those lighter bodies rise.\"\n     Whence, after utt\'rance of a piteous sigh,\nShe tow\'rds me bent her eyes, with such a look,\nAs on her frenzied child a mother casts;\nThen thus began:  \"Among themselves all things\nHave order; and from hence the form, which makes\nThe universe resemble God.  In this\nThe higher creatures see the printed steps\nOf that eternal worth, which is the end\nWhither the line is drawn.  All natures lean,\nIn this their order, diversely, some more,\nSome less approaching to their primal source.\nThus they to different havens are mov\'d on\nThrough the vast sea of being, and each one\nWith instinct giv\'n, that bears it in its course;\nThis to the lunar sphere directs the fire,\nThis prompts the hearts of mortal animals,\nThis the brute earth together knits, and binds.\nNor only creatures, void of intellect,\nAre aim\'d at by this bow; hut even those,\nThat have intelligence and love, are pierc\'d.\nThat Providence, who so well orders all,\nWith her own light makes ever calm the heaven,\nIn which the substance, that hath greatest speed,\nIs turn\'d: and thither now, as to our seat\nPredestin\'d, we are carried by the force\nOf that strong cord, that never looses dart,\nBut at fair aim and glad.  Yet is it true,\nThat as ofttimes but ill accords the form\nTo the design of art, through sluggishness\nOf unreplying matter, so this course\nIs sometimes quitted by the creature, who\nHath power, directed thus, to bend elsewhere;\nAs from a cloud the fire is seen to fall,\nFrom its original impulse warp\'d, to earth,\nBy vicious fondness.  Thou no more admire\nThy soaring, (if I rightly deem,) than lapse\nOf torrent downwards from a mountain\'s height.\nThere would in thee for wonder be m");
    strcat(expected_filecontent, "ore cause,\nIf, free of hind\'rance, thou hadst fix\'d thyself\nBelow, like fire unmoving on the earth.\"\n     So said, she turn\'d toward the heav\'n her face.\n\n\n\nCANTO II\n\nAll ye, who in small bark have following sail\'d,\nEager to listen, on the advent\'rous track\nOf my proud keel, that singing cuts its way,\nBackward return with speed, and your own shores\nRevisit, nor put out to open sea,\nWhere losing me, perchance ye may remain\nBewilder\'d in deep maze.  The way I pass\nNe\'er yet was run: Minerva breathes the gale,\nApollo guides me, and another Nine\nTo my rapt sight the arctic beams reveal.\nYe other few, who have outstretch\'d the neck.\nTimely for food of angels, on which here\nThey live, yet never know satiety,\nThrough the deep brine ye fearless may put out\nYour vessel, marking, well the furrow broad\nBefore you in the wave, that on both sides\nEqual returns.  Those, glorious, who pass\'d o\'er\nTo Colchos, wonder\'d not as ye will do,\nWhen they saw Jason following the plough.\n     The increate perpetual thirst, that draws\nToward the realm of God\'s own form, bore us\nSwift almost as the heaven ye behold.\n     Beatrice upward gaz\'d, and I on her,\nAnd in such space as on the notch a dart\nIs plac\'d, then loosen\'d flies, I saw myself\nArriv\'d, where wond\'rous thing engag\'d my sight.\nWhence she, to whom no work of mine was hid,\nTurning to me, with aspect glad as fair,\nBespake me: \"Gratefully direct thy mind\nTo God, through whom to this first star we come.\"\n     Me seem\'d as if a cloud had cover\'d us,\nTranslucent, solid, firm, and polish\'d bright,\nLike adamant, which the sun\'s beam had smit\nWithin itself the ever-during pearl\nReceiv\'d us, as the wave a ray of light\nReceives, and rests unbroken.  If I then\nWas of corporeal frame, and it transcend\nOur weaker thought, how one dimension thus\nAnother could endure, which needs must be\nIf body enter body, how much more\nMust the desire inflame us to behold\nThat essence, which discovers by what means\nGod and our nature join\'d!  There will be seen\nThat which we hold through faith, not shown by proof,\nBut in itself intelligibly plain,\nE\'en as the truth that man at first believes.\n     I answered:  \"Lady!  I with thoughts devout,\nSuch as I best can frame, give thanks to Him,\nWho hath remov\'d me from the mortal world.\nBut tell, I pray thee, whence the gloomy spots\nUpon this body, which below on earth\nGive rise to talk of Cain in fabling quaint?\"\n     She somewhat smil\'d, then spake:  \"If mortals err\nIn their opinion, when the key of sense\nUnlocks not, surely wonder\'s weapon keen\nOught not to pierce thee; since thou find\'st, the wings\nOf reason to pursue the senses\' flight\nAre short.  But what thy own thought is, declare.\"\n     Then I:  \"What various here above appears,\nIs caus\'d, I deem, by bodies dense or rare.\"\n     She then resum\'d:  \"Thou certainly ");
                
        
                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "SOUND.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 6913, file);
                test_error(size == 6913, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6913 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6913);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 6913);


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
    
        
                char *filecontent = (char *)calloc(15015, 1);
                char expected_filecontent[15016] = "";
        
                strcat(expected_filecontent, "ges, till he arrives in a beautiful valley\ncovered with flowers on all sides, and the richest in the world;\nbut which was continually  shifting its appearance from a round\nfigure to a square, from obscurity to light, and from\npopulousness to solitude.  This is the region of Pleasure, or\nCupid, who is accompanied by four ladies, Love, Hope, Fear, and\nDesire.  In one part of it he meets with Ovid, and is instructed\nby him how to conquer the passion of love, and to escape from\nthat place.  After his escape he makes his confession to a friar,\nand then returns to the forest of visions:  and ascending a\nmountain, he meets with Ptolemy, a venerable old man.  Here the\nnarrative breaks off. The  poem ends, as it began, with an\naddress to Rustico di Filippo, on whom he lavishes every sort of\npraise.\n\nIt has been observed, that Dante derived the idea of opening his\npoem by describing himself as lost in a wood, from the Tesoretto\nof his master.  I know not whether it has been remarked, that the\ncrime of usury is branded by both these poets as offensive to God\nand Nature:  or that the sin for which Brunetto is condemned by\nhis pupil, is mentioned in the Tesoretto with great horror.\nDante\'s twenty-fifth sonnet is a jocose one, addressed to\nBrunetto.  He died in 1295.\n\nv. 62.  Who in old times came down from Fesole.]  See G. Villani\nHist. l. iv. c. 5. and Macchiavelli Hist. of Flor. b. ii.\n\nv. 89.  With another text.]  He refers to the prediction of\nFarinata, in Canto X.\n\nv. 110.  Priscian.]  There is no reason to believe, as the\ncommentators observe that the grammarian of this name was stained\nwith the vice imputed to him; and we must therefore suppose that\nDante puts the individual for the species, and implies the\nfrequency of the crime among those who abused the opportunities\nwhich the education of youth afforded them, to so abominable a\npurpose.\n\nv. 111.  Francesco.]  Son of Accorso, a Florentine, celebrated\nfor his skill in jurisprudence, and commonly known by the name of\nAccursius.\n\nv. 113.  Him.]  Andrea de\' Mozzi, who, that his scandalous life\nmight be less exposed to observation, was translated either by\nNicholas III, or Boniface VIII from the see of Florence to that\nof Vicenza, through which passes the river Baccchiglione.  At the\nlatter of these places he died.\n\nv. 114.  The servants\' servant.]  Servo de\' servi.  So Ariosto,\nSat. 3.\n               Degli servi\n        Io sia il gran servo.\n\nv. 124.  I commend my Treasure to thee.]  Brunetto\'s great work,\nthe Tresor.\nSieti raccomandato \'l mio Tesoro.\nSo Giusto de\' Conti, in his Bella Mano, Son.  \"Occhi:\"\n        Siavi raccommandato il mio Tesoro.\n\nCANTO XVI\n\nv. 38.  Gualdrada.]  Gualdrada was the daughter of Bellincione\nBerti, of whom mention is made in the Paradise, Canto XV, and\nXVI.  He was of the family of Ravignani, a branch of the Adimari.\n\nThe Emperor Otho IV. being at a festival in Florence, where\nGualdrada was present, was struck with her beauty; and inquiring\nwho she was, was answered by Bellincione, that she was the\ndaughter of one who, if it was his Majesty\'s pleasure, would make\nher admit the honour of his salute.  On overhearing this, she\narose from her seat, and blushing, in an animated tone of voice,\ndesired her father that he would not be so liberal in his offers,\nfor that no man should ever be allowed that freedom, except him\nwho should be her lawful husband.  The Emperor was not less\ndelighted by her resolute modesty than he had before been by the\nloveliness of her person, and calling to him Guido, one of his\nbarons, gave her to him in marriage, at the same time raising him\n\nto the rank of a count, and bestowing on her the whole of\nCasentino, and a part of the territory of Romagna, as her\nportion.  Two sons were the offspring of this union, Guglielmo\nand Ruggieri, the latter of whom was father of Guidoguerra, a man\nof great military skill and prowess who, at the head of four\nhundred Florentines of the Guelph party, was signally\ninstrumental to the victory obtained at Benevento by Charles of\nAnjou, over Manfredi, King of Naples, in 1265.   One of the\nconsequ");
    strcat(expected_filecontent, "ences of this victory was the expulsion of the Ghibellini,\nand the re-establishment of the Guelfi at Florence.\n\nv. 39.  Many a noble act.]  Compare Tasso, G. L. c. i. st. 1.\n\nv. 42.  Aldobrandiu]  Tegghiaio Aldobrandi was of the noble\nfamily of Adimari, and much esteemed for his military talents.\nHe endeavored to dissuade the Florentines from the attack, which\nthey meditated against the Siennese, and the rejection of his\ncounsel occasioned the memorable defeat, which the former\nsustained at Montaperto, and the consequent banishment of the\nGuelfi from Florence.\n\nv. 45.  Rusticucci.]  Giacopo Rusticucci, a Florentine,\nremarkable for his opulence and the generosity of his spirit.\n\nv. 70.  Borsiere.]  Guglielmo Borsiere, another Florentine, whom\nBoccaccio, in a story which he relates of him, terms \"a man of\ncourteous and elegant manners, and of great readiness in\nconversation.\"  Dec. Giorn. i. Nov. 8.\n\nv. 84.  When thou with pleasure shalt retrace the past.]\n        Quando ti giovera dicere io fui.\nSo Tasso, G. L. c. xv. st. 38.\n        Quando mi giovera narrar altrui\n        Le novita vedute, e dire; io fui.\n\nv. 121.  Ever to that truth.]  This memorable apophthegm is\nrepeated by Luigi Pulci and Trissino.\n\n        Sempre a quel ver, ch\' ha faccia di menzogna\n        E piu senno tacer la lingua cheta\n        Che spesso senza colpa fa vergogna.\n               Morgante. Magg.  c. xxiv.\n\n               La verita, che par mensogna\n        Si dovrebbe tacer dall\' uom ch\'e saggio.\n               Italia. Lib. C. xvi.\n\nCANTO XVII\n\nv. 1.  The fell monster.]  Fraud.\n\nv. 53.  A pouch.]  A purse, whereon the armorial bearings of each\nwere emblazoned.  According to Landino, our poet implies that the\nusurer can pretend to no other honour, than such as he derives\nfrom his purse and his family.\n\nv. 57.  A yellow purse.]  The arms of the Gianfigliazzi of\nFlorence.\n\nv. 60.  Another.]  Those of the Ubbriachi, another Florentine\nfamily of high distinction.\n\nv. 62.  A fat and azure swine.]  The arms of the Scrovigni a\nnoble family of Padua.\n\nv. 66.  Vitaliano.]  Vitaliano del Dente, a Paduan.\n\nv. 69.  That noble knight.]  Giovanni Bujamonti, a Florentine\nusurer, the most infamous of his time.\n\nCANTO XVIII\n\nv. 28.  With us beyond.]  Beyond the middle point they tended the\nsame way with us, but their pace was quicker than ours.\n\nv. 29.  E\'en thus the Romans.]  In the year 1300, Pope Boniface\nVIII., to remedy the inconvenience occasioned by the press of\npeople who were passing over the bridge of St. Angelo during the\ntime of the Jubilee, caused it to be divided length wise by a\npartition, and ordered, that all those who were going to St.\nPeter\'s should keep one side, and those returning the other.\n\nv. 50.  Venedico.]  Venedico Caccianimico, a Bolognese, who\nprevailed on his sister Ghisola to prostitute herself to Obizzo\nda  Este, Marquis of Ferrara, whom we have seen among the\ntyrants, Canto XII.\n\nv. 62.  To answer Sipa.]  He denotes Bologna by its situation\nbetween the rivers Savena to the east, and Reno to the west of\nthat city; and by a peculiarity of dialect, the use of the\naffirmative sipa instead of si.\n\nv. 90.  Hypsipyle.]  See Appolonius Rhodius, l. i. and Valerius\nFlaccus l.ii.  Hypsipyle deceived the other women by concealing\nher father Thoas, when they had agreed to put all their males to\ndeath.\n\nv. 120.  Alessio.]  Alessio, of an ancient and considerable\nfamily in Lucca, called the Interminei.\n\nv. 130.  Thais.]  He alludes to that passage in the Eunuchus of\nTerence where Thraso asks if Thais was obliged to him for the\npresent he had sent her, and Gnatho replies, that she had\nexpressed her obligation in the most forcible terms.\n        T.  Magnas vero agere gratias Thais mihi?\n        G.  Ingentes.\n               Eun. a. iii. s. i.\n\nCANTO XIX\n\nv. 18.  Saint John\'s fair dome.]  The apertures in the  rock were\nof the same dimensions as the fonts of St. John the Baptist at\nFlorence, one of which, Dante says he had broken, to rescue a\nchild  that was playing near and fell in. He intimates that the\nmotive of his  breaking the font had been m");
    strcat(expected_filecontent, "aliciously represented\nby his enemies.\n\nv. 55.  O Boniface!]  The spirit mistakes Dante for  Boniface\nVIII. who was then alive, and who he did not expect would have\narrived so soon, in consequence, as it should seem, of a\nprophecy, which  predicted the death of that Pope at a later\nperiod. Boniface died in  1303.\n\nv. 58.  In guile.]  \"Thou didst presume to arrive by fraudulent\nmeans at the papal power, and afterwards to abuse it.\"\n\nv. 71.  In the mighty mantle I was rob\'d.]  Nicholas III, of the\nOrsini family, whom the poet therefore calls \"figliuol dell\'\norsa,\" \"son of the she-bear.\"  He died in 1281.\n\nv. 86.  From forth the west, a shepherd without law.]   Bertrand\nde Got Archbishop of Bordeaux, who succeeded to the pontificate\nin 1305, and assumed the title of Clement V. He transferred the\nholy  see to Avignon in 1308 (where it remained till 1376), and\ndied in 1314.\n\nv. 88.  A new Jason.]  See Maccabees, b. ii. c. iv. 7,8.\n\nv. 97.  Nor Peter.]  Acts of the Apostles, c.i. 26.\n\nv. 100.  The condemned soul.]  Judas.\n\nv. 103.  Against Charles.]  Nicholas III. was enraged against\nCharles I, King of Sicily, because he rejected with scorn a\nproposition made by that Pope for an alliance between their\nfamilies.  See G. Villani, Hist. l. vii. c. liv.\n\nv. 109.  Th\' Evangelist.]  Rev. c. xvii. 1, 2, 3.  Compare\nPetrarch.  Opera fol. ed. Basil. 1551. Epist. sine titulo liber.\nep. xvi. p. 729.\n\nv. 118.  Ah, Constantine.]  He alludes to the pretended gift of\nthe Lateran by Constantine to Silvester, of which Dante himself\nseems to imply a doubt, in his treatise \"De Monarchia.\" - \"Ergo\nscindere Imperium, Imperatori non licet.  Si ergo aliquae,\ndignitates per Constantinum essent alienatae, (ut dicunt) ab\nImperio,\" &c. l. iii.\nThe gift is by Ariosto very humorously placed in the moon, among\nthe things lost or abused on earth.\n        Di varj fiori, &c.\n               O. F. c. xxxiv. st. 80.\n\nMilton has translated both this passage and that in the text.\nProse works, vol. i. p. 11. ed. 1753.\n\nCANTO XX\n\nv. 11.  Revers\'d.]  Compare Spenser, F. Q. b. i. c. viii.  st. 31\n\nv. 30.  Before whose eyes.]  Amphiaraus, one of the seven kings\nwho besieged Thebes.  He is said to have been swallowed up by  an\nopening of the earth.  See Lidgate\'s Storie of Thebes, Part III\nwhere it is told how the \"Bishop Amphiaraus\" fell down to hell.\n        And thus the devill for his outrages,\n        Like his desert payed him his wages.\nA different reason for his being doomed thus to perish is\nassigned by Pindar.\n[GREEK HERE]\n               Nem ix.\n\n        For thee, Amphiaraus, earth,\n        By Jove\'s all-riving thunder cleft\n        Her mighty bosom open\'d wide,\n        Thee and thy plunging steeds to hide,\n        Or ever on thy back the spear\n        Of Periclymenus impress\'d\n        A wound to shame thy warlike breast\n        For struck with panic fear\n        The gods\' own children flee.\n\nv. 37.  Tiresias.]\n        Duo magnorum viridi coeuntia sylva\n        Corpora serpentum baculi violaverat ictu, &c.\n               Ovid. Met. iii.\n\nv. 43.  Aruns.]  Aruns is said to have dwelt in the  mountains of\nLuni (from whence that territory is still called Lunigiana),\nabove Carrara, celebrated for its marble.  Lucan. Phars. l. i.\n575.  So Boccaccio in the Fiammetta, l. iii.  \"Quale Arunte,\" &c.\n\n\"Like Aruns, who amidst the white marbles of Luni, contemplated\nthe celestial bodies and their motions.\"\n\nv. 50.  Manto.]  The daughter of Tiresias of Thebes, a city\ndedicated to Bacchus.  From Manto Mantua, the country of Virgil\nderives its name. The Poet proceeds to describe the situation of\nthat place.\n\nv. 61.  Between the vale.]  The lake Benacus, now called  the\nLago di Garda, though here said to lie between Garda, Val\nCamonica, and the Apennine, is, however, very distant from the\nlatter two\n\nv. 63.  There is a spot.]  Prato di Fame, where the dioceses of\nTrento, Verona, and Brescia met.\n\nv. 69.  Peschiera.]  A garrison situated to the south of the\nlake, where it empties itself and forms the Mincius.\n\nv. 94.  Casalodi\'s madness.]  Alberto da Casalodi, who had got\npossess");
    strcat(expected_filecontent, "ion of Mantua, was persuaded by Pinamonte Buonacossi, that\nhe might ingratiate himself with the people by banishing to their\n\nown castles the nobles, who were obnoxious to them.  No sooner\nwas this done, than Pinamonte put himself at the head of the\npopulace, drove out Casalodi and his adherents, and obtained the\nsovereignty for himself.\n\nv. 111.  So sings my tragic strain.]\n        Suspensi Eurypilum scitatum oracula Phoebi\n        Mittimus.\n               Virg. Aeneid. ii. 14.\n\nv. 115.  Michael Scot.]  Sir Michael Scott, of Balwearie,\nastrologer to the Emperor Frederick II. lived in the thirteenth\ncentury.  For further particulars relating to this singular man,\nsee Warton\'s History of English Poetry, vol. i. diss. ii. and\nsect. ix.  p 292, and the Notes to Mr. Scott\'s \"Lay of the Last\nMinstrel,\" a  poem in which a happy use is made of the traditions\nthat are still current in North Britain concerning him.  He is\nmentioned by G. Villani. Hist. l. x. c. cv. and cxli. and l. xii.\nc. xviii. and by Boccaccio, Dec. Giorn. viii. Nov. 9.\n\nv. 116.  Guido Bonatti.]  An astrologer of Forli, on whose  skill\nGuido da Montefeltro, lord of that place, so much relied, that he\nis reported never to have gone into battle, except in the hour\nrecommended to him as fortunate by Bonatti.\n\nLandino and Vellutello, speak of a book, which he composed on the\nsubject of his art.\n\nv. 116.  Asdente.]  A shoemaker at Parma, who deserted his\nbusiness to practice the arts of divination.\n\nv. 123.  Cain with fork of thorns.]  By Cain and the thorns, or\nwhat is still vulgarly called the Man in the Moon, the Poet\ndenotes that luminary.  The same superstition is alluded to in\nthe Paradise, Canto II. 52.  The curious reader may consult Brand\non Popular Antiquities, 4to.  1813. vol. ii. p. 476.\n\nCANTO XXI\n\nv. 7.  In the Venetians\' arsenal.]  Compare Ruccellai, Le  Api,\n165, and Dryden\'s Annus Mirabilis, st. 146, &c.\n\nv. 37.  One of Santa Zita\'s elders.]  The elders or chief\nmagistrates of Lucca, where Santa Zita was held in especial\nveneration.  The name of this sinner is supposed to have been\nMartino Botaio.\n\nv. 40.  Except Bonturo, barterers.]  This is said ironically of\nBonturo de\' Dati.  By barterers are meant peculators, of every\ndescription; all who traffic the interests of the public  for\ntheir own private advantage.\n\nv. 48.  Is other swimming than in Serchio\'s wave.]\n        Qui si nuota altrimenti che nel Serchio.\nSerchio is the river that flows by Lucca.  So Pulci, Morg. Mag.\nc. xxiv.\n        Qui si nuota nel sangue, e non nel Serchio.\n\nv. 92.  From Caprona.]  The surrender of the castle of Caprona to\nthe combined forces of Florence and Lucca, on condition that the\ngarrison should march out in safety, to which ");
                
        
                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "MANY");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 15015, file);
                test_error(size == 15015, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 15015 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 15015);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 15015);


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
    
        
                char *filecontent = (char *)calloc(393, 1);
                char expected_filecontent[394] = "";
        
                strcat(expected_filecontent, " came; nor was it ever known whence\nhe was or wither he went.\" G. Villani, 1.  vi.  c. 92.\n\nv. 135.  Four daughters.]  Of the four daughters of Raymond\nBerenger, Margaret, the eldest, was married to Louis IX of\nFrance; Eleanor; the next, to Henry III, of England; Sancha, the\nthird, to Richard, Henry\'s brother, and King of the Romans; and\nthe youngest, Beatrice, to Charles I, King of Naples ");
                
        
                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "DIVIDETE.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 393, file);
                test_error(size == 393, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 393 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 393);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 393);


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
    

                char *filecontent = (char *)calloc(620, 1);
                char expected_filecontent[621] = "";

                strcat(expected_filecontent, "pass\'d me speechless by; and doing so\nHath made me more compassionate his fate.\"\n     So we discours\'d to where the rock first show\'d\nThe other valley, had more light been there,\nE\'en to the lowest depth.  Soon as we came\nO\'er the last cloister in the dismal rounds\nOf Malebolge, and the brotherhood\nWere to our view expos\'d, then many a dart\nOf sore lament assail\'d me, headed all\nWith points of thrilling pity, that I clos\'d\nBoth ears against the volley with mine hands.\n     As were the torment, if each lazar-house\nOf Valdichiana, in the sultry time\n\'Twixt July and September, with the isle\nSardinia and Maremma\'s pe");

                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "WANT.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 1032, file);
                test_error(size == 620, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 620 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 620);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 620);


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
    

                char *filecontent = (char *)calloc(14273, 1);
                char expected_filecontent[14274] = "";

                strcat(expected_filecontent, "t.  Sails never such I saw\nOutstretch\'d on the wide sea.  No plumes had they,\nBut were in texture like a bat, and these\nHe flapp\'d i\' th\' air, that from him issued still\nThree winds, wherewith Cocytus to its depth\nWas frozen.  At six eyes he wept:  the tears\nAdown three chins distill\'d with bloody foam.\nAt every mouth his teeth a sinner champ\'d\nBruis\'d as with pond\'rous engine, so that three\nWere in this guise tormented.  But far more\nThan from that gnawing, was the foremost pang\'d\nBy the fierce rending, whence ofttimes the back\nWas stript of all its skin.  \"That upper spirit,\nWho hath worse punishment,\" so spake my guide,\n\"Is Judas, he that hath his head within\nAnd plies the feet without.  Of th\' other two,\nWhose heads are under, from the murky jaw\nWho hangs, is Brutus:  lo!  how he doth writhe\nAnd speaks not!  Th\' other Cassius, that appears\nSo large of limb.  But night now re-ascends,\nAnd it is time for parting.  All is seen.\"\n     I clipp\'d him round the neck, for so he bade;\nAnd noting time and place, he, when the wings\nEnough were op\'d, caught fast the shaggy sides,\nAnd down from pile to pile descending stepp\'d\nBetween the thick fell and the jagged ice.\n     Soon as he reach\'d the point, whereat the thigh\nUpon the swelling of the haunches turns,\nMy leader there with pain and struggling hard\nTurn\'d round his head, where his feet stood before,\nAnd grappled at the fell, as one who mounts,\nThat into hell methought we turn\'d again.\n     \"Expect that by such stairs as these,\" thus spake\nThe teacher, panting like a man forespent,\n\"We must depart from evil so extreme.\"\nThen at a rocky opening issued forth,\nAnd plac\'d me on a brink to sit, next join\'d\nWith wary step my side.  I rais\'d mine eyes,\nBelieving that I Lucifer should see\nWhere he was lately left, but saw him now\nWith legs held upward.  Let the grosser sort,\nWho see not what the point was I had pass\'d,\nBethink them if sore toil oppress\'d me then.\n     \"Arise,\" my master cried, \"upon thy feet.\n\"The way is long, and much uncouth the road;\nAnd now within one hour and half of noon\nThe sun returns.\"  It was no palace-hall\nLofty and luminous wherein we stood,\nBut natural dungeon where ill footing was\nAnd scant supply of light.  \"Ere from th\' abyss\nI sep\'rate,\" thus when risen I began,\n\"My guide!  vouchsafe few words to set me free\nFrom error\'s thralldom.  Where is now the ice?\nHow standeth he in posture thus revers\'d?\nAnd how from eve to morn in space so brief\nHath the sun made his transit?\"  He in few\nThus answering spake:  \"Thou deemest thou art still\nOn th\' other side the centre, where I grasp\'d\nTh\' abhorred worm, that boreth through the world.\nThou wast on th\' other side, so long as I\nDescended; when I turn\'d, thou didst o\'erpass\nThat point, to which from ev\'ry part is dragg\'d\nAll heavy substance.  Thou art now arriv\'d\nUnder the hemisphere opposed to that,\nWhich the great continent doth overspread,\nAnd underneath whose canopy expir\'d\nThe Man, that was born sinless, and so liv\'d.\nThy feet are planted on the smallest sphere,\nWhose other aspect is Judecca.  Morn\nHere rises, when there evening sets:  and he,\nWhose shaggy pile was scal\'d, yet standeth fix\'d,\nAs at the first.  On this part he fell down\nFrom heav\'n; and th\' earth, here prominent before,\nThrough fear of him did veil her with the sea,\nAnd to our hemisphere retir\'d.  Perchance\nTo shun him was the vacant space left here\nBy what of firm land on this side appears,\nThat sprang aloof.\"  There is a place beneath,\nFrom Belzebub as distant, as extends\nThe vaulted tomb, discover\'d not by sight,\nBut by the sound of brooklet, that descends\nThis way along the hollow of a rock,\nWhich, as it winds with no precipitous course,\nThe wave hath eaten.  By that hidden way\nMy guide and I did enter, to return\nTo the fair world:  and heedless of repose\nWe climbed, he first, I following his steps,\nTill on our view the beautiful lights of heav\'n\nDawn, through a circular opening in the cave:\nThus issuing we again beheld the stars.\n\n\n\nNOTES TO HELL\n\nCANTO I\n\nVerse 1.  In the midway.]  That the era of the Poem is intended\nby these words ");
    strcat(expected_filecontent, "to be fixed to the thirty fifth year of the poet\'s\nage, A.D. 1300, will appear more plainly in Canto XXI. where that\ndate is explicitly marked.\n\nv. 16.  That planet\'s beam.]  The sun.\n\nv. 29.  The hinder foot.]  It is to be remembered, that in\nascending a hill the weight of the body rests on the hinder foot.\n\nv. 30.  A panther.]  Pleasure or luxury.\n\nv. 36.  With those stars.]  The sun was in Aries, in which sign\nhe supposes it to have begun its course at the creation.\n\nv. 43.  A lion.]  Pride or ambition.\n\nv. 45.  A she wolf.]  Avarice.\n\nv. 56.  Where the sun in silence rests.]  Hence Milton appears to\nhave taken his idea in the Samson Agonistes:\n\n        The sun to me is dark\n               And silent as the moon, &c\nThe same metaphor will recur, Canto V. v. 29.\n        Into a place I came\n       Where light was silent all.\n\nv. 65.  When the power of Julius.] This is explained by the\ncommentators to mean \"Although it was rather late with respect to\nmy birth before Julius Caesar assumed the supreme authority, and\nmade himself perpetual dictator.\"\n\nv. 98.  That greyhound.]  This passage is intended as an eulogium\non the liberal spirit of his Veronese patron Can Grande della\nScala.\n\nv. 102.  \'Twizt either Feltro.]  Verona, the country of Can della\nScala, is situated between Feltro, a city in the Marca\nTrivigiana, and Monte Feltro, a city in the territory of Urbino.\n\nv. 103.  Italia\'s plains.]  \"Umile Italia,\" from Virgil, Aen lib.\niii. 522.\n        Humilemque videmus\n       Italiam.\n\nv. 115.  Content in fire.]  The spirits in Purgatory.\n\nv. 118.  A spirit worthier.]  Beatrice, who conducts the Poet\nthrough Paradise.\n\nv. 130.  Saint Peter\'s gate.]  The gate of Purgatory, which the\nPoet feigns to be guarded by an angel placed on that station by\nSt. Peter.\n\nCANTO II\n\nv. 1.  Now was the day.]  A compendium of Virgil\'s description\nAen. lib. iv 522.  Nox erat, &c. Compare Apollonius Rhodius, lib\niii. 744, and lib. iv. 1058\n\nv. 8.  O mind.]\n        O thought that write all that I met,\n        And in the tresorie it set\n        Of my braine, now shall men see\n        If any virtue in thee be.\n               Chaucer.  Temple of Fame, b. ii. v.18\n\nv. 14.  Silvius\'sire.] Aeneas.\n\nv. 30.  The chosen vessel.]  St.Paul, Acts, c. ix. v. 15.  \"But\nthe Lord said unto him, Go thy way; for he is a chosen vessel\nunto me.\"\n\nv. 46.  Thy soul.] L\'anima tua e da viltate offesa. So in Berni,\nOrl Inn.lib. iii. c. i. st. 53.\n        Se l\'alma avete offesa da viltate.\n\nv. 64.  Who rest suspended.]  The spirits in Limbo, neither\nadmitted to a state of glory nor doomed to punishment.\n\nv. 61.  A friend not of my fortune, but myself.]  Se non fortunae\nsed hominibus solere esse amicum.  Cornelii Nepotis Attici Vitae,\nc. ix.\n\nv. 78.  Whatever is contain\'d.]  Every other thing comprised\nwithin the lunar heaven, which, being the lowest of all, has the\nsmallest circle.\n\nv. 93.  A blessed dame.]  The divine mercy.\n\nv. 97.  Lucia.]  The enlightening grace of heaven.\n\nv. 124.  Three maids.]  The divine mercy, Lucia, and Beatrice.\n\nv. 127.  As florets.]  This simile is well translated by\nChaucer--\n        But right as floures through the cold of night\n        Iclosed, stoupen in her stalkes lowe,\n        Redressen hem agen the sunne bright,\n        And speden in her kinde course by rowe, &c.\n               Troilus and Creseide, b.ii.\nIt has been imitated by many others, among whom see Berni,\nOrl.Inn. Iib. 1. c. xii. st. 86.  Marino, Adone, c. xvii. st. 63.\nand Sor. \"Donna vestita di nero.\" and Spenser\'s Faery Queen, b.4.\nc. xii. st. 34. and b. 6 c. ii. st. 35.\n\nCANTO III\n\nv. 5.          Power divine\n        Supremest wisdom, and primeval love.]  The three\npersons of the blessed Trinity.\nv. 9.  all hope abandoned.] Lasciate ogni speranza voi\nch\'entrate.\nSo Berni, Orl. Inn. lib. i. c. 8. st. 53.\n        Lascia pur della vita ogni speranza.\n\nv. 29.  Like to the sand.]\n               Unnumber\'d as the sands\n        Of Barca or Cyrene\'s torrid soil\n        Levied to side with warring winds, and poise\n        Their lighter wings.\n               Milton, P. L. ii. 908.");
    strcat(expected_filecontent, "\n\nv. 40.  Lest th\' accursed tribe.]  Lest the rebellious angels\nshould exult at seeing those who were neutral and therefore less\nguilty, condemned to the same punishment with themselves.\n\nv. 50.  A flag.]\n               All the grisly legions that troop\n        Under the sooty flag of Acheron\n               Milton. Comus.\n\nv. 56.         Who to base fear\n        Yielding, abjur\'d his high estate.] This is\ncommonly understood of Celestine the Fifth, who abdicated the\npapal power in 1294. Venturi mentions a work written by\nInnocenzio Barcellini, of the Celestine order, and printed in\nMilan in 1701, In which an attempt is made to put a different\ninterpretation on this passage.\n\nv. 70.  through the blear light.]\n        Lo fioco lume\nSo Filicaja, canz. vi. st. 12.\n        Qual fioco lume.\n\nv. 77.  An old man.]\n        Portitor has horrendus aquas et flumina servat\n        Terribili squalore Charon, cui plurima mento\n        Canities inculta jacet; stant lumina flamma.\n               Virg. 7.  Aen. Iib. vi. 2.\n\nv. 82.  In fierce heat and in ice.]\n               The delighted spirit\n        To bathe in fiery floods or to reside\n        In thrilling regions of thick ribbed ice.\n               Shakesp. Measure for Measure, a. iii.s.1.\nCompare Milton, P. L. b. ii. 600.\n\nv. 92.  The livid lake.] Vada livida.\n               Virg. Aen. Iib. vi. 320\n               Totius ut Lacus putidaeque paludis\n        Lividissima, maximeque est profunda vorago.\n               Catullus. xviii. 10.\n\nv. 102.  With eyes of burning coal.]\n        His looks were dreadful, and his fiery eyes\n        Like two great beacons glared bright and wide.\n               Spenser. F.Q. b. vi. c. vii.st. 42\n\nv. 104.  As fall off the light of autumnal leaves.]\n        Quam multa in silvis autumul frigore primo\n        Lapsa cadunt folia.\n               Virg. Aen. lib. vi. 309\nCompare Apoll.  Rhod. lib. iv. 214.\n\nCANTO IV\n\nv. 8.  A thund\'rous sound.]  Imitated, as Mr. Thyer has remarked,\nby Milton, P. L. b. viii. 242.\n               But long ere our approaching heard\n        Noise, other, than the sound of dance or song\n        Torment, and loud lament, and furious rage.\n\nv. 50.  a puissant one.]  Our Saviour.\n\nv. 75.                 Honour the bard\n        Sublime.]\n\n        Onorate l\'altissimo poeta.\nSo Chiabrera, Canz. Eroiche. 32.\n        Onorando l\'altissimo poeta.\n\nv. 79.  Of semblance neither sorrowful nor glad.]\n        She nas to sober ne to glad.\n               Chaucer\'s Dream.\n\nv. 90.  The Monarch of sublimest song.]  Homer.\n\nv. 100.  Fitter left untold.]\n        Che\'l tacere e bello,\nSo our Poet, in Canzone 14.\n        La vide in parte che\'l tacere e bello,\nRuccellai, Le Api, 789.\n        Ch\'a dire e brutto ed a tacerlo e bello\nAnd Bembo,\n        \"Vie pui bello e il tacerle, che il favellarne.\"\n               Gli. Asol. lib. 1.\n\nv. 117.  Electra.]  The daughter of Atlas, and mother of Dardanus\nthe founder of Troy.  See Virg. Aen. b. viii. 134. as referred to\nby Dante in treatise \"De Monarchia,\" lib. ii. \"Electra, scilicet,\nnata magni nombris regis Atlantis, ut de ambobus testimonium\nreddit poeta noster in octavo ubi Aeneas ad Avandrum sic ait\n        \"Dardanus Iliacae,\" &c.\n\nv. 125.  Julia.]  The daughter of Julius Caesar, and wife of\nPompey.\n\nv. 126.  The Soldan fierce.]  Saladin or Salaheddin, the  rival\nof  Richard coeur de lion.  See D\'Herbelot, Bibl. Orient. and\nKnolles\'s Hist. of the Turks p. 57 to 73 and the Life of Saladin,\nby Bohao\'edin Ebn Shedad, published by Albert Schultens, with a\nLatin translation. He is introduced by Petrarch in the Triumph of\nFame, c. ii\n\nv. 128.  The master of the sapient throng.]\n        Maestro di color che sanno.\nAristotle--Petrarch assigns the first place to Plato. See Triumph\nof Fame, c. iii.\nPulci, in his Morgante Maggiore, c. xviii. says,\n        Tu se\'il maestro di color che sanno.\n\nv. 132.               Democritus\n        Who sets the world at chance.]\nDemocritus,who maintained the world to have been formed by the\nfortuitous concourse of atoms.\n\nv. 140.  Avicen.]  See D\'Herbelot Bibl. Orient. article  Sina. He\n");
    strcat(expected_filecontent, "died in 1050.  Pulci here again imitates our poet:\n\n        Avicenna quel che il sentimento\n        Intese di Aristotile e i segreti,\n        Averrois che fece il gran comento.\n               Morg. Mag. c. xxv.\n\nv. 140.               Him who made\n        That commentary vast, Averroes.]\nAverroes, called by the Arabians Roschd, translated and commented\nthe works of Aristotle. According to Tiraboschi (storia della\nLett. Ital. t. v. 1. ii. c. ii. sect. 4.) he was the source of\nmodern philosophical impiety. The critic quotes some passages\nfrom Petrarch (Senil. 1. v. ep. iii. et. Oper. v. ii. p. 1143) to\nshow how strongly such sentiments prevailed in the time of that\npoet, by whom they were held in horror and detestation He adds,\nthat this fanatic admirer of Aristotle translated his writings\nwith that felicity, which might be expected from one who did not\nknow a syllable of Greek, and who was therefore compelled to\navail himself of the unfaithful Arabic versions. D\'Herbelot, on\nthe other hand, informs us, that \"Averroes was the first who\ntranslated Aristotle from Greek into Arabic, before the Jews had\nmade their translation:  and that we had for a long time no other\ntext of Aristotle, except that of the Latin translation, which\nwas made from this Arabic version of this great philosopher\n(Averroes), who afterwards added to it a very ample commentary,\nof which Thomas Aquinas, and the other scholastic writers,\navailed themselves, before the Greek originals of Aristotle and\nhis commentators were known to us in Europe.\" According to\nD\'Herbelot, he died in 1198: but Tiraboschi places that event\nabout 1206.\n\nCANTO V\n\nv. 5.  Grinning with ghastly feature.]  Hence Milton:\n               Death\n        Grinn\'d horrible a ghastly smile.\n               P. L. b. ii. 845.\n\nv. 46.  As cranes.]  This simile is imitated by Lorenzo de\nMedici, in his Ambra, a poem, first published by Mr. Roscoe, in\nthe  Appendix to his Life of Lorenzo.\n        Marking the tracts of air, the clam");

                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "COMMON.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 14623, file);
                test_error(size == 14273, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 14273 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 14273);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 14273);


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
    

                char *filecontent = (char *)calloc(14336, 1);
                char expected_filecontent[14337] = "";

                strcat(expected_filecontent, "y leader\'s feet still equaling pace\nFrom forth that cloud I came, when now expir\'d\nThe parting beams from off the nether shores.\n     O quick and forgetive power!  that sometimes dost\nSo rob us of ourselves, we take no mark\nThough round about us thousand trumpets clang!\nWhat moves thee, if the senses stir not?  Light\nKindled in heav\'n, spontaneous, self-inform\'d,\nOr likelier gliding down with swift illapse\nBy will divine.  Portray\'d before me came\nThe traces of her dire impiety,\nWhose form was chang\'d into the bird, that most\nDelights itself in song: and here my mind\nWas inwardly so wrapt, it gave no place\nTo aught that ask\'d admittance from without.\n     Next shower\'d into my fantasy a shape\nAs of one crucified, whose visage spake\nFell rancour, malice deep, wherein he died;\nAnd round him Ahasuerus the great king,\nEsther his bride, and Mordecai the just,\nBlameless in word and deed.  As of itself\nThat unsubstantial coinage of the brain\nBurst, like a bubble, Which the water fails\nThat fed it; in my vision straight uprose\nA damsel weeping loud, and cried, \"O queen!\nO mother!  wherefore has intemperate ire\nDriv\'n thee to loath thy being?  Not to lose\nLavinia, desp\'rate thou hast slain thyself.\nNow hast thou lost me.  I am she, whose tears\nMourn, ere I fall, a mother\'s timeless end.\"\n     E\'en as a sleep breaks off, if suddenly\nNew radiance strike upon the closed lids,\nThe broken slumber quivering ere it dies;\nThus from before me sunk that imagery\nVanishing, soon as on my face there struck\nThe light, outshining far our earthly beam.\nAs round I turn\'d me to survey what place\nI had arriv\'d at, \"Here ye mount,\" exclaim\'d\nA voice, that other purpose left me none,\nSave will so eager to behold who spake,\nI could not choose but gaze.  As \'fore the sun,\nThat weighs our vision down, and veils his form\nIn light transcendent, thus my virtue fail\'d\nUnequal.  \"This is Spirit from above,\nWho marshals us our upward way, unsought;\nAnd in his own light shrouds him;. As a man\nDoth for himself, so now is done for us.\nFor whoso waits imploring, yet sees need\nOf his prompt aidance, sets himself prepar\'d\nFor blunt denial, ere the suit be made.\nRefuse we not to lend a ready foot\nAt such inviting: haste we to ascend,\nBefore it darken: for we may not then,\nTill morn again return.\"  So spake my guide;\nAnd to one ladder both address\'d our steps;\nAnd the first stair approaching, I perceiv\'d\nNear me as \'twere the waving of a wing,\nThat fann\'d my face and whisper\'d: \"Blessed they\nThe peacemakers: they know not evil wrath.\"\n     Now to such height above our heads were rais\'d\nThe last beams, follow\'d close by hooded night,\nThat many a star on all sides through the gloom\nShone out.  \"Why partest from me, O my strength?\"\nSo with myself I commun\'d; for I felt\nMy o\'ertoil\'d sinews slacken.  We had reach\'d\nThe summit, and were fix\'d like to a bark\nArriv\'d at land.  And waiting a short space,\nIf aught should meet mine ear in that new round,\nThen to my guide I turn\'d, and said: \"Lov\'d sire!\nDeclare what guilt is on this circle purg\'d.\nIf our feet rest, no need thy speech should pause.\"\n     He thus to me:  \"The love of good, whate\'er\nWanted of just proportion, here fulfils.\nHere plies afresh the oar, that loiter\'d ill.\nBut that thou mayst yet clearlier understand,\nGive ear unto my words, and thou shalt cull\nSome fruit may please thee well, from this delay.\n     \"Creator, nor created being, ne\'er,\nMy son,\" he thus began, \"was without love,\nOr natural, or the free spirit\'s growth.\nThou hast not that to learn.  The natural still\nIs without error; but the other swerves,\nIf on ill object bent, or through excess\nOf vigour, or defect.  While e\'er it seeks\nThe primal blessings, or with measure due\nTh\' inferior, no delight, that flows from it,\nPartakes of ill.  But let it warp to evil,\nOr with more ardour than behooves, or less.\nPursue the good, the thing created then\nWorks \'gainst its Maker.  Hence thou must infer\nThat love is germin of each virtue in ye,\nAnd of each act no less, that merits pain.\nNow since it may not be, but love intend\nThe welfare mainly of the thing i");
    strcat(expected_filecontent, "t loves,\nAll from self-hatred are secure; and since\nNo being can be thought t\' exist apart\nAnd independent of the first, a bar\nOf equal force restrains from hating that.\n     \"Grant the distinction just; and it remains\nThe\' evil must be another\'s, which is lov\'d.\nThree ways such love is gender\'d in your clay.\nThere is who hopes (his neighbour\'s worth deprest,)\nPreeminence himself, and coverts hence\nFor his own greatness that another fall.\nThere is who so much fears the loss of power,\nFame, favour, glory (should his fellow mount\nAbove him), and so sickens at the thought,\nHe loves their opposite: and there is he,\nWhom wrong or insult seems to gall and shame\nThat he doth thirst for vengeance, and such needs\nMust doat on other\'s evil.  Here beneath\nThis threefold love is mourn\'d.  Of th\' other sort\nBe now instructed, that which follows good\nBut with disorder\'d and irregular course.\n     \"All indistinctly apprehend a bliss\nOn which the soul may rest, the hearts of all\nYearn after it, and to that wished bourn\nAll therefore strive to tend.  If ye behold\nOr seek it with a love remiss and lax,\nThis cornice after just repenting lays\nIts penal torment on ye.  Other good\nThere is, where man finds not his happiness:\nIt is not true fruition, not that blest\nEssence, of every good the branch and root.\nThe love too lavishly bestow\'d on this,\nAlong three circles over us, is mourn\'d.\nAccount of that division tripartite\nExpect not, fitter for thine own research.\n\n\n\nCANTO XVIII\n\nThe teacher ended, and his high discourse\nConcluding, earnest in my looks inquir\'d\nIf I appear\'d content; and I, whom still\nUnsated thirst to hear him urg\'d, was mute,\nMute outwardly, yet inwardly I said:\n\"Perchance my too much questioning offends\nBut he, true father, mark\'d the secret wish\nBy diffidence restrain\'d, and speaking, gave\nMe boldness thus to speak: \"Master, my Sight\nGathers so lively virtue from thy beams,\nThat all, thy words convey, distinct is seen.\nWherefore I pray thee, father, whom this heart\nHolds dearest!  thou wouldst deign by proof t\' unfold\nThat love, from which as from their source thou bring\'st\nAll good deeds and their opposite.\"  He then:\n\"To what I now disclose be thy clear ken\nDirected, and thou plainly shalt behold\nHow much those blind have err\'d, who make themselves\nThe guides of men.  The soul, created apt\nTo love, moves versatile which way soe\'er\nAught pleasing prompts her, soon as she is wak\'d\nBy pleasure into act.  Of substance true\nYour apprehension forms its counterfeit,\nAnd in you the ideal shape presenting\nAttracts the soul\'s regard.  If she, thus drawn,\nincline toward it, love is that inclining,\nAnd a new nature knit by pleasure in ye.\nThen as the fire points up, and mounting seeks\nHis birth-place and his lasting seat, e\'en thus\nEnters the captive soul into desire,\nWhich is a spiritual motion, that ne\'er rests\nBefore enjoyment of the thing it loves.\nEnough to show thee, how the truth from those\nIs hidden, who aver all love a thing\nPraise-worthy in itself: although perhaps\nIts substance seem still good.  Yet if the wax\nBe good, it follows not th\' impression must.\"\n\"What love is,\" I return\'d, \"thy words, O guide!\nAnd my own docile mind, reveal.  Yet thence\nNew doubts have sprung.  For from without if love\nBe offer\'d to us, and the spirit knows\nNo other footing, tend she right or wrong,\nIs no desert of hers.\"  He answering thus:\n\"What reason here discovers I have power\nTo show thee: that which lies beyond, expect\nFrom Beatrice, faith not reason\'s task.\nSpirit, substantial form, with matter join\'d\nNot in confusion mix\'d, hath in itself\nSpecific virtue of that union born,\nWhich is not felt except it work, nor prov\'d\nBut through effect, as vegetable life\nBy the green leaf.  From whence his intellect\nDeduced its primal notices of things,\nMan therefore knows not, or his appetites\nTheir first affections; such in you, as zeal\nIn bees to gather honey; at the first,\nVolition, meriting nor blame nor praise.\nBut o\'er each lower faculty supreme,\nThat as she list are summon\'d to her bar,\nYe have that virtue in you, whose just voice\nUttereth co");
    strcat(expected_filecontent, "unsel, and whose word should keep\nThe threshold of assent.  Here is the source,\nWhence cause of merit in you is deriv\'d,\nE\'en as the affections good or ill she takes,\nOr severs, winnow\'d as the chaff.  Those men\nWho reas\'ning went to depth profoundest, mark\'d\nThat innate freedom, and were thence induc\'d\nTo leave their moral teaching to the world.\nGrant then, that from necessity arise\nAll love that glows within you; to dismiss\nOr harbour it, the pow\'r is in yourselves.\nRemember, Beatrice, in her style,\nDenominates free choice by eminence\nThe noble virtue, if in talk with thee\nShe touch upon that theme.\"  The moon, well nigh\nTo midnight hour belated, made the stars\nAppear to wink and fade; and her broad disk\nSeem\'d like a crag on fire, as up the vault\nThat course she journey\'d, which the sun then warms,\nWhen they of Rome behold him at his set.\nBetwixt Sardinia and the Corsic isle.\nAnd now the weight, that hung upon my thought,\nWas lighten\'d by the aid of that clear spirit,\nWho raiseth Andes above Mantua\'s name.\nI therefore, when my questions had obtain\'d\nSolution plain and ample, stood as one\nMusing in dreary slumber; but not long\nSlumber\'d; for suddenly a multitude,\nThe steep already turning, from behind,\nRush\'d on.  With fury and like random rout,\nAs echoing on their shores at midnight heard\nIsmenus and Asopus, for his Thebes\nIf Bacchus\' help were needed; so came these\nTumultuous, curving each his rapid step,\nBy eagerness impell\'d of holy love.\n     Soon they o\'ertook us; with such swiftness mov\'d\nThe mighty crowd.  Two spirits at their head\nCried weeping; \"Blessed Mary sought with haste\nThe hilly region.  Caesar to subdue\nIlerda, darted in Marseilles his sting,\nAnd flew to Spain.\"--\"Oh tarry not: away;\"\nThe others shouted; \"let not time be lost\nThrough slackness of affection.  Hearty zeal\nTo serve reanimates celestial grace.\"\n     \"O ye, in whom intenser fervency\nHaply supplies, where lukewarm erst ye fail\'d,\nSlow or neglectful, to absolve your part\nOf good and virtuous, this man, who yet lives,\n(Credit my tale, though strange) desires t\' ascend,\nSo morning rise to light us.  Therefore say\nWhich hand leads nearest to the rifted rock?\"\n     So spake my guide, to whom a shade return\'d:\n\"Come after us, and thou shalt find the cleft.\nWe may not linger: such resistless will\nSpeeds our unwearied course.  Vouchsafe us then\nThy pardon, if our duty seem to thee\nDiscourteous rudeness.  In Verona I\nWas abbot of San Zeno, when the hand\nOf Barbarossa grasp\'d Imperial sway,\nThat name, ne\'er utter\'d without tears in Milan.\nAnd there is he, hath one foot in his grave,\nWho for that monastery ere long shall weep,\nRuing his power misus\'d: for that his son,\nOf body ill compact, and worse in mind,\nAnd born in evil, he hath set in place\nOf its true pastor.\"  Whether more he spake,\nOr here was mute, I know not: he had sped\nE\'en now so far beyond us.  Yet thus much\nI heard, and in rememb\'rance treasur\'d it.\n     He then, who never fail\'d me at my need,\nCried, \"Hither turn.  Lo!  two with sharp remorse\nChiding their sin!\"  In rear of all the troop\nThese shouted:  \"First they died, to whom the sea\nOpen\'d, or ever Jordan saw his heirs:\nAnd they, who with Aeneas to the end\nEndur\'d not suffering, for their portion chose\nLife without glory.\"  Soon as they had fled\nPast reach of sight, new thought within me rose\nBy others follow\'d fast, and each unlike\nIts fellow: till led on from thought to thought,\nAnd pleasur\'d with the fleeting train, mine eye\nWas clos\'d, and meditation chang\'d to dream.\n\n\nCANTO XIX\n\nIt was the hour, when of diurnal heat\nNo reliques chafe the cold beams of the moon,\nO\'erpower\'d by earth, or planetary sway\nOf Saturn; and the geomancer sees\nHis Greater Fortune up the east ascend,\nWhere gray dawn checkers first the shadowy cone;\nWhen \'fore me in my dream a woman\'s shape\nThere came, with lips that stammer\'d, eyes aslant,\nDistorted feet, hands maim\'d, and colour pale.\n     I look\'d upon her; and as sunshine cheers\nLimbs numb\'d by nightly cold, e\'en thus my look\nUnloos\'d her tongue, next in brief space her form\nDecrepit rais\'d erect, ");
    strcat(expected_filecontent, "and faded face\nWith love\'s own hue illum\'d. Recov\'ring speech\nShe forthwith warbling such a strain began,\nThat I, how loth soe\'er, could scarce have held\nAttention from the song.  \"I,\" thus she sang,\n\"I am the Siren, she, whom mariners\nOn the wide sea are wilder\'d when they hear:\nSuch fulness of delight the list\'ner feels.\nI from his course Ulysses by my lay\nEnchanted drew.  Whoe\'er frequents me once\nParts seldom; so I charm him, and his heart\nContented knows no void.\"  Or ere her mouth\nWas clos\'d, to shame her at her side appear\'d\nA dame of semblance holy.  With stern voice\nShe utter\'d; \"Say, O Virgil, who is this?\"\nWhich hearing, he approach\'d, with eyes still bent\nToward that goodly presence: th\' other seiz\'d her,\nAnd, her robes tearing, open\'d her before,\nAnd show\'d the belly to me, whence a smell,\nExhaling loathsome, wak\'d me.  Round I turn\'d\nMine eyes, and thus the teacher:  \"At the least\nThree times my voice hath call\'d thee.  Rise, begone.\nLet us the opening find where thou mayst pass.\"\n     I straightway rose.  Now day, pour\'d down from high,\nFill\'d all the circuits of the sacred mount;\nAnd, as we journey\'d, on our shoulder smote\nThe early ray.  I follow\'d, stooping low\nMy forehead, as a man, o\'ercharg\'d with thought,\nWho bends him to the likeness of an arch,\nThat midway spans the flood; when thus I heard,\n\"Come, enter here,\" in tone so soft and mild,\nAs never met the ear on mortal strand.\n     With swan-like wings dispread and pointing up,\nWho thus had spoken marshal\'d us along,\nWhere each side of the solid masonry\nThe sloping, walls retir\'d; then mov\'d his plumes,\nAnd fanning us, affirm\'d that those, who mourn,\nAre blessed, for that comfort shall be theirs.\n     \"What aileth thee, that still thou look\'st to earth?\"\nBegan my leader; while th\' angelic shape\nA little over us his station took.\n     \"New vision,\" I replied, \"hath rais\'d in me\n8urmisings strange and anxious doubts, whereon\nMy soul intent allows no other thought\nOr room or entrance.--\"Hast thou seen,\" said he,\n\"That old enchantress, her, whose w");

                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "SOME.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 14459, file);
                test_error(size == 14336, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 14336 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 14336);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 14336);


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
    

                char *filecontent = (char *)calloc(14150, 1);
                char expected_filecontent[14151] = "";

                strcat(expected_filecontent, "ed in 1312, at\nthe age of twenty four, in consequence, as it was supposed, of\nhis extreme intemperance.\nSee Mariana, Hist I. xv.  c. 11.\n\nv. 123.  The Bohemian.]  Winceslaus II.  Purgatory, Canto VII. v.\n\nv. 125.  The halter of Jerusalem.]  Charles II of Naples and\nJerusalem who was lame.  See note to Purgatory, Canto VII.  v.\n122, and XX. v. 78.\n\nv. 127.  He.]  Frederick of Sicily son of Peter III of Arragon.\nPurgatory, Canto VII.  v. 117.  The isle of fire is Sicily, where\nwas the tomb of Anchises.\n\nv. 133.  His uncle.]  James, king of Majorca and Minorca, brother\nto Peter III.\n\nv. 133.  His brother.]  James II of Arragon, who died in 1327.\nSee Purgatory, Canto VII.  v. 117.\n\nv. 135.  Of Portugal.]  In the time of Dante, Dionysius was king\nof Portugal.  He died in 1328, after a reign of near forty-six\nyears, and does not seem to have deserved the stigma here\nfastened on him. See Mariana. and 1. xv. c. 18.  Perhaps the\nrebellious son of Dionysius may be alluded to.\n\nv. 136.  Norway.]  Haquin, king of Norway, is probably meant;\nwho, having given refuge to the murderers of Eric VII king of\nDenmark, A D. 1288, commenced a war against his successor, Erie\nVIII, \"which continued for nine years, almost to the utter ruin\nand destruction of both kingdoms.\"  Modern Univ. Hist. v. xxxii\np. 215.\n\nv. 136.  -Him\nOf Ratza.]\nOne of the dynasty of the house of Nemagna, which ruled the\nkingdom of Rassia, or Ratza, in Sclavonia, from 1161 to 1371, and\nwhose history may be found in Mauro Orbino, Regno degli Slavi,\nEdiz. Pesaro. 1601. Uladislaus appears to have been the sovereign\nin Dante\'s time, but the disgraceful forgery adverted to in the\ntext, is not recorded by the historian v. 138.  Hungary.]  The\nkingdom of Hungary was about this time disputed by Carobert, son\nof Charles Martel, and Winceslaus, prince of Bohemia, son of\nWinceslaus II.  See Coxe\'s House of Austria, vol. i. p. 1. p. 86.\n\n4to edit.\n\nv. 140.  Navarre.]  Navarre was now under the yoke of France.\n It soon after (in 1328) followed the advice of Dante and had a\nmonarch of its own.  Mariana, 1.  xv. c. 19.\n\nv. 141.  Mountainous girdle.]  The Pyrenees.\n\nv. 143.  -Famagosta\'s streets\nAnd Nicosia\'s.]\n\nCities in the kingdom of Cyprus, at that time ruled by Henry II a\npusillanimous prince. Vertot.  Hist. des Chev.  de Malte, 1. iii.\niv. The meaning appears to be, that the complaints made by those\ncities of their weak and worthless governor, may be regarded as\nan earnest of his condemnation at the last doom.\n\nCANTO XX\n\nv. 6.  Wherein one shines.]  The light of the sun, whence he\nsupposes the other celestial bodies to derive their light\n\nv. 8.  The great sign.]  The eagle, the Imperial ensign.\n\nv. 34.  Who.]  David.\n\nv. 39.  He.]  Trajan.  See Purgatory, Canto X. 68.\n\nv. 44.  He next.]  Hezekiah.\n\nv. 50.  \'The other following.]  Constantine.  There is no passage\nin which Dante\'s opinion of the evil; that had arisen from the\nmixture of the civil with the ecclesiastical power, is more\nunequivocally  declared.\n\nv. 57.  William.]  William II, king of Sicily, at the latter part\nof  the twelfth century He was of the Norman line of sovereigns,\nand obtained the appellation of \"the Good\" and, as the poet says\nhis loss was as much the subject of regret in his dominions, as\nthe presence of Charles I of Anjou and Frederick of Arragon, was\nof sorrow and complaint.\n\nv. 62.  Trojan Ripheus.]\nRipheus, justissimus unus\nQui fuit in Teneris, et servantissimus aequi.\nVirg.  Aen.  1. ii. 4--.\n\nv. 97.  This.]  Ripheus.\n\nv. 98.  That.]  Trajan.\n\nv. 103.  The prayers,] The prayers of St. Gregory\n\nv. 119.  The three nymphs.]  Faith, Hope, and Charity. Purgatory,\nCanto XXIX.  116.\nv. 138.  The pair.]  Ripheus and Trajan.\n\nCANTO XXI\n\nv. 12.  The seventh splendour.]  The planet Saturn\n\nv. 13.  The burning lion\'s breast.]  The constellation Leo.\n\nv. 21.  In equal balance.]  \"My pleasure was as great in\ncomplying\nwith her will as in beholding her countenance.\"\n\nv. 24.  Of that lov\'d monarch.]  Saturn.  Compare Hell, Canto\nXIV.  91.\n\nv. 56.  What forbade the smile.]  \"Because it would have overcome\nthee.\"\n\nv. 6");
    strcat(expected_filecontent, "1.  There aloft.]  Where the other souls were.\n\nv. 97.  A stony ridge.]  The Apennine.\n\nv. 112.  Pietro Damiano.]  \"S. Pietro Damiano obtained a great\nand well-merited reputation, by the pains he took to correct the\nabuses among the clergy.  Ravenna is supposed to have been the\nplace of his birth, about 1007.  He was employed in several\nimportant missions, and rewarded by Stephen IX with the dignity\nof cardinal, and the bishopric of Ostia, to which, however, he\npreferred his former retreat in the monastery of Fonte Aveliana,\nand prevailed on Alexander II to permit him to retire thither.\nYet he did not long continue in this seclusion, before he was\nsent on other embassies.  He died at Faenza in 1072.  His\nletters throw much light on the obscure history of these times.\nBesides them, he has left several treatises on sacred and\necclesiastical subjects. His eloquence is worthy of a better\nage.\"  Tiraboschi, Storia della Lett Ital. t. iii.  1. iv. c. 2.\n\nv. 114.  Beside the Adriatic.]  At Ravenna.  Some editions have\nFU instead of FUI, according to which reading, Pietro\ndistinguishes  himself from another Pietro, who was termed\n\"Peccator,\" the sinner.\n\nv. 117.  The hat.]  The cardinal\'s hat.\n\nv. 118.  Cephas.]  St. Peter.\n\nv. 119 The Holy Spirit\'s vessel.]  St. Paul. See Hell, Canto II.\n30.\n\nv. 130.  Round this.]  Round the spirit of Pietro Damiano.\n\nCANTO XXII\n\nv. 14.  The vengeance.]  Beatrice, it is supposed, intimates the\napproaching fate of Boniface VIII.  See Purgatory, Canto XX.  86.\n\nv. 36.  Cassino.]  A castle in the Terra di Lavoro.\n\nv. 38.  I it was.]  \"A new order of monks, which in a manner\nabsorbed all the others that were established in the west, was\ninstituted, A.D.  529, by Benedict of Nursis, a man of piety and\nreputation for the age he  lived in.\"  Maclaine\'s Mosheim,\nEccles. Hist. v. ii.  cent. vi. p. 2. ch.  2 - 6.\n\nv. 48.  Macarius.]  There are two of this name enumerated by\nMosheim among the Greek theologians of the fourth century, v. i.\ncent. iv p. 11 ch. 2 - 9.  In the following chapter, 10, it is\nsaid, \"Macarius, an Egyptian monk, undoubtedly deserves the first\nrank among the practical matters of this time, as his works\ndisplayed, some few things excepted, the brightest and most\nlovely portraiture of sanctity and virtue.\"\n\nv. 48.  Romoaldo.]  S. Romoaldo, a native of Ravenna, and the\nfounder of the order of Camaldoli, died in 1027.  He was the\nauthor of a commentary on the Psalms.\n\nv. 70.  The patriarch Jacob.]  So Milton, P. L. b. iii. 510:\nThe stairs were such, as whereon Jacob saw\nAngels ascending and descending, bands\nOf guardians bright.\n\nv. 107.  The sign.]  The constellation of Gemini.\n\nv. 130. This globe.]  So Chaucer, Troilus and Cresseide, b. v,\n\nAnd down from thence fast he gan avise\nThis little spot of earth, that with the sea\nEmbraced is, and fully gan despite\nThis wretched world.\n\nCompare Cicero, Somn. Scip.  \"Jam ipsa terra ita mihi parva visa\nest.\" &c.  Lucan, Phar 1.  ix. 11;  and Tasso, G.  L.  c.  xiv.\nst, 9, 10, 11.\n\nv. 140.  Maia and Dione.]  The planets Mercury and Venus.\n\nCANTO XXIII\n\nv. 11.  That region.]  Towards the south, where the course of the\nsun appears less rapid, than, when he is in the east or the west.\n\nv. 26.  Trivia.]  A name of Diana.\n\nv. 26.  Th\' eternal nymphs.]  The stars.\n\nv. 36.  The Might.]  Our Saviour\n\nv. 71.  The rose.]  The Virgin Mary.\n\nv. 73.  The lilies.]  The apostles.\n\nv. 84.  Thou didst exalt thy glory.]  The diving light retired\nupwards, to render the eyes of Dante more capable of enduring the\nspectacle  which now presented itself.\n\nv. 86.  The name of that fair flower.]  The name of the Virgin.\n\nv. 92.  A cresset.]  The angel Gabriel.\n\nv. 98.  That lyre.]  By synecdoche, the lyre is put for the angel\n\nv. 99.  The goodliest sapphire.]  The Virgin\n\nv. 126.  Those rich-laden coffers.]  Those spirits who, having\nsown the seed of good works on earth, now contain the fruit of\ntheir pious endeavours.\n\nv. 129.  In the Babylonian exile.]  During their abode in this\nworld.\n\nv. 133.  He.]  St. Peter, with the other holy men of the Old and\nNew testament.\n\nC");
    strcat(expected_filecontent, "ANTO XXIV\n\nv. 28.  Such folds.]  Pindar has the same bold image:\n[GREEK HERE?]\nOn which Hayne strangely remarks:  Ad ambitus stropharum vldetur\n\nv. 65.  Faith.]  Hebrews, c.  xi.  1.  So Marino, in one of his\nsonnets, which calls Divozioni:\n\nFede e sustanza di sperate cose,\nE delle non visioili argomento.\n\nv. 82.  Current.]  \"The answer thou hast made is right; but let\nme know if thy inward persuasion is conformable to thy\nprofession.\"\n\nv. 91.  The ancient bond and new.]  The Old and New Testament.\n\nv. 114.  That Worthy.]  Quel Baron.\nIn the next Canto, St. James is called \"Barone.\"  So in\nBoccaccio, G. vi. N. 10, we find \"Baron Messer Santo Antonio.\"\nv. 124.  As to outstrip.]  Venturi insists that the Poet has\nhere, \"made a slip;\" for that John came first to the sepulchre,\nthough Peter was the first to enter it.  But let Dante have leave\nto explain his own meaning, in a passage from his third book De\nMonarchia:  \"Dicit etiam Johannes ipsum (scilicet Petrum)\nintroiisse SUBITO, cum venit in monumentum, videns allum\ndiscipulum cunctantem ad ostium.\" Opere de Dante, Ven. 1793. T.\nii. P. 146.\n\nCANTO XXV\n\nv. 6.  The fair sheep-fold.]  Florence, whence he was banished.\n\nv. 13.  For its sake.]  For the sake of that faith.\n\nv. 20.  Galicia throng\'d with visitants.] See Mariana, Hist. 1.\nxi.\n\nv. 13.  \"En el tiempo,\" &c.  \"At the time that the sepulchre of\nthe apostle St. James was discovered, the devotion for that place\nextended itself not only over all Spain, but even round about to\nforeign nations. Multitudes from all parts of the world came to\nvisit it.  Many others were deterred by the difficulty for the\njourney, by the roughness and barrenness of those parts, and by\nthe incursions of the Moors, who made captives many of the\npilgrims.  The canons of St. Eloy afterwards (the precise time is\nnot known), with a desire of remedying these evils, built, in\nmany places, along the whole read, which reached as far as to\nFrance, hospitals for the reception of the pilgrims.\"\n\nv. 31.  Who.]  The Epistle of St. James is here attributed to the\nelder apostle of that name, whose shrine was at Compostella, in\nGalicia.  Which of the two was the author of it is yet doubtful.\nThe learned and candid Michaelis contends very forcibly for its\nhaving been written by James the Elder.  Lardner rejects that\nopinion as absurd; while Benson argues against it, but is well\nanswered by Michaelis, who after all, is obliged to leave the\nquestion undecided.  See his Introduction to the New Testament,\ntranslated by Dr. Marsh, ed.  Cambridge, 1793.  V. iv. c.  26.  -\n1, 2, 3.\n\nv. 35.  As Jesus.]  In the transfiguration on Mount Tabor.\n\nv. 39.  The second flame.]  St. James.\n\nv. 40.  I lifted up.]  \"I will lift up mine eyes unto the hills,\nfrom whence cometh my help.\"  Ps.  Cxxi.  1.\n\nv. 59.  From Egypt to Jerusalem.]  From the lower world to\nheaven.\n\nv. 67.  Hope.]  This is from the Sentences of Petrus Lombardus.\n\"Est autem spes virtus, qua spiritualia et aeterna bona speratam,\nid  est, beatitudinem aeternam.  Sine meritis enim aliquid\nsperare non spes, sed praesumptio, dici potest.\"  Pet. Lomb.\nSent.  1.  Iii.  Dist.  26.   Ed. Bas.  1486.  Fol.\n\nv. 74.  His anthem.]  Psalm ix.  10.\n\nv. 90.  Isaias ]  Chap. lxi. 10.\n\nv. 94.  Thy brother.]  St. John in the Revelation, c. vii.  9.\n\nv. 101.  Winter\'s month.]  \"If a luminary, like that which now\nappeared, were to shine throughout the month following the winter\nsolstice during which the constellation Cancer appears in the\neast at the setting of the sun, there would be no interruption to\nthe light, but the whole month would be as a single day.\"\n\nv. 112.  This.]  St. John, who reclined on the bosom of our\nSaviour, and to whose charge Jesus recommended his mother.\n\nv. 121.  So I.]  He looked so earnestly, to descry whether St.\nJohn were present there in body, or in spirit only, having had\nhis doubts raised  by that saying of our Saviour\'s:  \"If I will,\nthat he tarry till I come  what is that to thee.\"\n\nv. 127.  The two.]  Christ and Mary, whom he has described, in\nthe last Canto but one, as rising above his sight\n\nCANT");
    strcat(expected_filecontent, "O XXVI\n\nv. 2.  The beamy flame.]  St. John.\n\nv. 13.  Ananias\' hand.]  Who, by putting his hand on St. Paul,\nrestored his sight.  Acts, c. ix.  17.\n\nv. 36.  From him.]  Some suppose that Plato is here meant, who,\nin his Banquet, makes Phaedrus say:  \"Love is confessedly amongst\nthe eldest of beings, and, being the eldest, is the cause to us\nof the greatest goods \" Plat. Op. t. x. p. 177.  Bip.  ed. Others\nhave understood it of Aristotle, and others, of the writer who\ngoes by the name of Dionysius the Areopagite, referred to in the\ntwenty-eighth Canto.\n\nv. 40.  I will make.]  Exodus, c. xxxiii. 19.\n\nv. 42.  At the outset.]  John, c. i. 1.  &c.\n\nv. 51.  The eagle of our Lord.]  St. John\n\nv. 62.  The leaves.]  Created beings.\n\nv. 82.  The first living soul.]  Adam.\n\nv. 107.  Parhelion.]  Who enlightens and comprehends all things;\nbut is himself enlightened and comprehended by none.\n\nv. 117.  Whence.]  That is, from Limbo.  See Hell, Canto II.  53.\nAdam says that 5232 years elapsed from his creation to the time\nof his deliverance, which followed the death of Christ.\n\nv. 133.  EL]  Some read UN, \"One,\" instead of EL:  but the latter\nof these readings is confirmed by a passage from Dante\'s Treatise\nDe Vulg. Eloq. 1. i. cap. 4. \"Quod prius vox primi loquentis\nsonaverit, viro sanae mentis in promptu esse non dubito ipsum\nfuisse quod Deus est, videlicet El.\"  St. Isidore in the\nOrigines, 1.  vii. c. 1. had said, \"Primum apud Hebraeos Dei\nnomen El dicitur.\"\n\nv. 135.  Use.]  From Horace, Ars. Poet. 62.\n\nv. 138.  All my life.]  \"I remained in the terrestrial Paradise\nonly tothe seventh hour.\"  In the Historia Scolastica of Petrus\nComestor, it is said of our first parents:  Quidam tradunt eos\nfuisse in Paradiso septem horae.\"  I. 9. ed. Par. 1513. 4to.\n\nCANTO XXVII\n\nv.  1.  Four torches.]  St. Peter, St. James, St. John, and Adam.\n\nv. 11.  That.] ");

                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "HAPPEN.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 14400, file);
                test_error(size == 14150, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 14150 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 14150);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 14150);


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
    

                char *filecontent = (char *)calloc(6913, 1);
                char expected_filecontent[6914] = "";

                strcat(expected_filecontent, "st gives\nIts temper and impression.  Morning there,\nHere eve was by almost such passage made;\nAnd whiteness had o\'erspread that hemisphere,\nBlackness the other part; when to the left\nI saw Beatrice turn\'d, and on the sun\nGazing, as never eagle fix\'d his ken.\nAs from the first a second beam is wont\nTo issue, and reflected upwards rise,\nE\'en as a pilgrim bent on his return,\nSo of her act, that through the eyesight pass\'d\nInto my fancy, mine was form\'d; and straight,\nBeyond our mortal wont, I fix\'d mine eyes\nUpon the sun.  Much is allowed us there,\nThat here exceeds our pow\'r; thanks to the place\nMade for the dwelling of the human kind\n     I suffer\'d it not long, and yet so long\nThat I beheld it bick\'ring sparks around,\nAs iron that comes boiling from the fire.\nAnd suddenly upon the day appear\'d\nA day new-ris\'n, as he, who hath the power,\nHad with another sun bedeck\'d the sky.\n     Her eyes fast fix\'d on the eternal wheels,\nBeatrice stood unmov\'d; and I with ken\nFix\'d upon her, from upward gaze remov\'d\nAt her aspect, such inwardly became\nAs Glaucus, when he tasted of the herb,\nThat made him peer among the ocean gods;\nWords may not tell of that transhuman change:\nAnd therefore let the example serve, though weak,\nFor those whom grace hath better proof in store\n     If I were only what thou didst create,\nThen newly, Love!  by whom the heav\'n is rul\'d,\nThou know\'st, who by thy light didst bear me up.\nWhenas the wheel which thou dost ever guide,\nDesired Spirit!  with its harmony\nTemper\'d of thee and measur\'d, charm\'d mine ear,\nThen seem\'d to me so much of heav\'n to blaze\nWith the sun\'s flame, that rain or flood ne\'er made\nA lake so broad.  The newness of the sound,\nAnd that great light, inflam\'d me with desire,\nKeener than e\'er was felt, to know their cause.\n     Whence she who saw me, clearly as myself,\nTo calm my troubled mind, before I ask\'d,\nOpen\'d her lips, and gracious thus began:\n\"With false imagination thou thyself\nMak\'st dull, so that thou seest not the thing,\nWhich thou hadst seen, had that been shaken off.\nThou art not on the earth as thou believ\'st;\nFor light\'ning scap\'d from its own proper place\nNe\'er ran, as thou hast hither now return\'d.\"\n     Although divested of my first-rais\'d doubt,\nBy those brief words, accompanied with smiles,\nYet in new doubt was I entangled more,\nAnd said:  \"Already satisfied, I rest\nFrom admiration deep, but now admire\nHow I above those lighter bodies rise.\"\n     Whence, after utt\'rance of a piteous sigh,\nShe tow\'rds me bent her eyes, with such a look,\nAs on her frenzied child a mother casts;\nThen thus began:  \"Among themselves all things\nHave order; and from hence the form, which makes\nThe universe resemble God.  In this\nThe higher creatures see the printed steps\nOf that eternal worth, which is the end\nWhither the line is drawn.  All natures lean,\nIn this their order, diversely, some more,\nSome less approaching to their primal source.\nThus they to different havens are mov\'d on\nThrough the vast sea of being, and each one\nWith instinct giv\'n, that bears it in its course;\nThis to the lunar sphere directs the fire,\nThis prompts the hearts of mortal animals,\nThis the brute earth together knits, and binds.\nNor only creatures, void of intellect,\nAre aim\'d at by this bow; hut even those,\nThat have intelligence and love, are pierc\'d.\nThat Providence, who so well orders all,\nWith her own light makes ever calm the heaven,\nIn which the substance, that hath greatest speed,\nIs turn\'d: and thither now, as to our seat\nPredestin\'d, we are carried by the force\nOf that strong cord, that never looses dart,\nBut at fair aim and glad.  Yet is it true,\nThat as ofttimes but ill accords the form\nTo the design of art, through sluggishness\nOf unreplying matter, so this course\nIs sometimes quitted by the creature, who\nHath power, directed thus, to bend elsewhere;\nAs from a cloud the fire is seen to fall,\nFrom its original impulse warp\'d, to earth,\nBy vicious fondness.  Thou no more admire\nThy soaring, (if I rightly deem,) than lapse\nOf torrent downwards from a mountain\'s height.\nThere would in thee for wonder be m");
    strcat(expected_filecontent, "ore cause,\nIf, free of hind\'rance, thou hadst fix\'d thyself\nBelow, like fire unmoving on the earth.\"\n     So said, she turn\'d toward the heav\'n her face.\n\n\n\nCANTO II\n\nAll ye, who in small bark have following sail\'d,\nEager to listen, on the advent\'rous track\nOf my proud keel, that singing cuts its way,\nBackward return with speed, and your own shores\nRevisit, nor put out to open sea,\nWhere losing me, perchance ye may remain\nBewilder\'d in deep maze.  The way I pass\nNe\'er yet was run: Minerva breathes the gale,\nApollo guides me, and another Nine\nTo my rapt sight the arctic beams reveal.\nYe other few, who have outstretch\'d the neck.\nTimely for food of angels, on which here\nThey live, yet never know satiety,\nThrough the deep brine ye fearless may put out\nYour vessel, marking, well the furrow broad\nBefore you in the wave, that on both sides\nEqual returns.  Those, glorious, who pass\'d o\'er\nTo Colchos, wonder\'d not as ye will do,\nWhen they saw Jason following the plough.\n     The increate perpetual thirst, that draws\nToward the realm of God\'s own form, bore us\nSwift almost as the heaven ye behold.\n     Beatrice upward gaz\'d, and I on her,\nAnd in such space as on the notch a dart\nIs plac\'d, then loosen\'d flies, I saw myself\nArriv\'d, where wond\'rous thing engag\'d my sight.\nWhence she, to whom no work of mine was hid,\nTurning to me, with aspect glad as fair,\nBespake me: \"Gratefully direct thy mind\nTo God, through whom to this first star we come.\"\n     Me seem\'d as if a cloud had cover\'d us,\nTranslucent, solid, firm, and polish\'d bright,\nLike adamant, which the sun\'s beam had smit\nWithin itself the ever-during pearl\nReceiv\'d us, as the wave a ray of light\nReceives, and rests unbroken.  If I then\nWas of corporeal frame, and it transcend\nOur weaker thought, how one dimension thus\nAnother could endure, which needs must be\nIf body enter body, how much more\nMust the desire inflame us to behold\nThat essence, which discovers by what means\nGod and our nature join\'d!  There will be seen\nThat which we hold through faith, not shown by proof,\nBut in itself intelligibly plain,\nE\'en as the truth that man at first believes.\n     I answered:  \"Lady!  I with thoughts devout,\nSuch as I best can frame, give thanks to Him,\nWho hath remov\'d me from the mortal world.\nBut tell, I pray thee, whence the gloomy spots\nUpon this body, which below on earth\nGive rise to talk of Cain in fabling quaint?\"\n     She somewhat smil\'d, then spake:  \"If mortals err\nIn their opinion, when the key of sense\nUnlocks not, surely wonder\'s weapon keen\nOught not to pierce thee; since thou find\'st, the wings\nOf reason to pursue the senses\' flight\nAre short.  But what thy own thought is, declare.\"\n     Then I:  \"What various here above appears,\nIs caus\'d, I deem, by bodies dense or rare.\"\n     She then resum\'d:  \"Thou certainly ");

                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "SOUND.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 7048, file);
                test_error(size == 6913, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6913 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6913);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 6913);


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
    

                char *filecontent = (char *)calloc(15015, 1);
                char expected_filecontent[15016] = "";

                strcat(expected_filecontent, "ges, till he arrives in a beautiful valley\ncovered with flowers on all sides, and the richest in the world;\nbut which was continually  shifting its appearance from a round\nfigure to a square, from obscurity to light, and from\npopulousness to solitude.  This is the region of Pleasure, or\nCupid, who is accompanied by four ladies, Love, Hope, Fear, and\nDesire.  In one part of it he meets with Ovid, and is instructed\nby him how to conquer the passion of love, and to escape from\nthat place.  After his escape he makes his confession to a friar,\nand then returns to the forest of visions:  and ascending a\nmountain, he meets with Ptolemy, a venerable old man.  Here the\nnarrative breaks off. The  poem ends, as it began, with an\naddress to Rustico di Filippo, on whom he lavishes every sort of\npraise.\n\nIt has been observed, that Dante derived the idea of opening his\npoem by describing himself as lost in a wood, from the Tesoretto\nof his master.  I know not whether it has been remarked, that the\ncrime of usury is branded by both these poets as offensive to God\nand Nature:  or that the sin for which Brunetto is condemned by\nhis pupil, is mentioned in the Tesoretto with great horror.\nDante\'s twenty-fifth sonnet is a jocose one, addressed to\nBrunetto.  He died in 1295.\n\nv. 62.  Who in old times came down from Fesole.]  See G. Villani\nHist. l. iv. c. 5. and Macchiavelli Hist. of Flor. b. ii.\n\nv. 89.  With another text.]  He refers to the prediction of\nFarinata, in Canto X.\n\nv. 110.  Priscian.]  There is no reason to believe, as the\ncommentators observe that the grammarian of this name was stained\nwith the vice imputed to him; and we must therefore suppose that\nDante puts the individual for the species, and implies the\nfrequency of the crime among those who abused the opportunities\nwhich the education of youth afforded them, to so abominable a\npurpose.\n\nv. 111.  Francesco.]  Son of Accorso, a Florentine, celebrated\nfor his skill in jurisprudence, and commonly known by the name of\nAccursius.\n\nv. 113.  Him.]  Andrea de\' Mozzi, who, that his scandalous life\nmight be less exposed to observation, was translated either by\nNicholas III, or Boniface VIII from the see of Florence to that\nof Vicenza, through which passes the river Baccchiglione.  At the\nlatter of these places he died.\n\nv. 114.  The servants\' servant.]  Servo de\' servi.  So Ariosto,\nSat. 3.\n               Degli servi\n        Io sia il gran servo.\n\nv. 124.  I commend my Treasure to thee.]  Brunetto\'s great work,\nthe Tresor.\nSieti raccomandato \'l mio Tesoro.\nSo Giusto de\' Conti, in his Bella Mano, Son.  \"Occhi:\"\n        Siavi raccommandato il mio Tesoro.\n\nCANTO XVI\n\nv. 38.  Gualdrada.]  Gualdrada was the daughter of Bellincione\nBerti, of whom mention is made in the Paradise, Canto XV, and\nXVI.  He was of the family of Ravignani, a branch of the Adimari.\n\nThe Emperor Otho IV. being at a festival in Florence, where\nGualdrada was present, was struck with her beauty; and inquiring\nwho she was, was answered by Bellincione, that she was the\ndaughter of one who, if it was his Majesty\'s pleasure, would make\nher admit the honour of his salute.  On overhearing this, she\narose from her seat, and blushing, in an animated tone of voice,\ndesired her father that he would not be so liberal in his offers,\nfor that no man should ever be allowed that freedom, except him\nwho should be her lawful husband.  The Emperor was not less\ndelighted by her resolute modesty than he had before been by the\nloveliness of her person, and calling to him Guido, one of his\nbarons, gave her to him in marriage, at the same time raising him\n\nto the rank of a count, and bestowing on her the whole of\nCasentino, and a part of the territory of Romagna, as her\nportion.  Two sons were the offspring of this union, Guglielmo\nand Ruggieri, the latter of whom was father of Guidoguerra, a man\nof great military skill and prowess who, at the head of four\nhundred Florentines of the Guelph party, was signally\ninstrumental to the victory obtained at Benevento by Charles of\nAnjou, over Manfredi, King of Naples, in 1265.   One of the\nconsequ");
    strcat(expected_filecontent, "ences of this victory was the expulsion of the Ghibellini,\nand the re-establishment of the Guelfi at Florence.\n\nv. 39.  Many a noble act.]  Compare Tasso, G. L. c. i. st. 1.\n\nv. 42.  Aldobrandiu]  Tegghiaio Aldobrandi was of the noble\nfamily of Adimari, and much esteemed for his military talents.\nHe endeavored to dissuade the Florentines from the attack, which\nthey meditated against the Siennese, and the rejection of his\ncounsel occasioned the memorable defeat, which the former\nsustained at Montaperto, and the consequent banishment of the\nGuelfi from Florence.\n\nv. 45.  Rusticucci.]  Giacopo Rusticucci, a Florentine,\nremarkable for his opulence and the generosity of his spirit.\n\nv. 70.  Borsiere.]  Guglielmo Borsiere, another Florentine, whom\nBoccaccio, in a story which he relates of him, terms \"a man of\ncourteous and elegant manners, and of great readiness in\nconversation.\"  Dec. Giorn. i. Nov. 8.\n\nv. 84.  When thou with pleasure shalt retrace the past.]\n        Quando ti giovera dicere io fui.\nSo Tasso, G. L. c. xv. st. 38.\n        Quando mi giovera narrar altrui\n        Le novita vedute, e dire; io fui.\n\nv. 121.  Ever to that truth.]  This memorable apophthegm is\nrepeated by Luigi Pulci and Trissino.\n\n        Sempre a quel ver, ch\' ha faccia di menzogna\n        E piu senno tacer la lingua cheta\n        Che spesso senza colpa fa vergogna.\n               Morgante. Magg.  c. xxiv.\n\n               La verita, che par mensogna\n        Si dovrebbe tacer dall\' uom ch\'e saggio.\n               Italia. Lib. C. xvi.\n\nCANTO XVII\n\nv. 1.  The fell monster.]  Fraud.\n\nv. 53.  A pouch.]  A purse, whereon the armorial bearings of each\nwere emblazoned.  According to Landino, our poet implies that the\nusurer can pretend to no other honour, than such as he derives\nfrom his purse and his family.\n\nv. 57.  A yellow purse.]  The arms of the Gianfigliazzi of\nFlorence.\n\nv. 60.  Another.]  Those of the Ubbriachi, another Florentine\nfamily of high distinction.\n\nv. 62.  A fat and azure swine.]  The arms of the Scrovigni a\nnoble family of Padua.\n\nv. 66.  Vitaliano.]  Vitaliano del Dente, a Paduan.\n\nv. 69.  That noble knight.]  Giovanni Bujamonti, a Florentine\nusurer, the most infamous of his time.\n\nCANTO XVIII\n\nv. 28.  With us beyond.]  Beyond the middle point they tended the\nsame way with us, but their pace was quicker than ours.\n\nv. 29.  E\'en thus the Romans.]  In the year 1300, Pope Boniface\nVIII., to remedy the inconvenience occasioned by the press of\npeople who were passing over the bridge of St. Angelo during the\ntime of the Jubilee, caused it to be divided length wise by a\npartition, and ordered, that all those who were going to St.\nPeter\'s should keep one side, and those returning the other.\n\nv. 50.  Venedico.]  Venedico Caccianimico, a Bolognese, who\nprevailed on his sister Ghisola to prostitute herself to Obizzo\nda  Este, Marquis of Ferrara, whom we have seen among the\ntyrants, Canto XII.\n\nv. 62.  To answer Sipa.]  He denotes Bologna by its situation\nbetween the rivers Savena to the east, and Reno to the west of\nthat city; and by a peculiarity of dialect, the use of the\naffirmative sipa instead of si.\n\nv. 90.  Hypsipyle.]  See Appolonius Rhodius, l. i. and Valerius\nFlaccus l.ii.  Hypsipyle deceived the other women by concealing\nher father Thoas, when they had agreed to put all their males to\ndeath.\n\nv. 120.  Alessio.]  Alessio, of an ancient and considerable\nfamily in Lucca, called the Interminei.\n\nv. 130.  Thais.]  He alludes to that passage in the Eunuchus of\nTerence where Thraso asks if Thais was obliged to him for the\npresent he had sent her, and Gnatho replies, that she had\nexpressed her obligation in the most forcible terms.\n        T.  Magnas vero agere gratias Thais mihi?\n        G.  Ingentes.\n               Eun. a. iii. s. i.\n\nCANTO XIX\n\nv. 18.  Saint John\'s fair dome.]  The apertures in the  rock were\nof the same dimensions as the fonts of St. John the Baptist at\nFlorence, one of which, Dante says he had broken, to rescue a\nchild  that was playing near and fell in. He intimates that the\nmotive of his  breaking the font had been m");
    strcat(expected_filecontent, "aliciously represented\nby his enemies.\n\nv. 55.  O Boniface!]  The spirit mistakes Dante for  Boniface\nVIII. who was then alive, and who he did not expect would have\narrived so soon, in consequence, as it should seem, of a\nprophecy, which  predicted the death of that Pope at a later\nperiod. Boniface died in  1303.\n\nv. 58.  In guile.]  \"Thou didst presume to arrive by fraudulent\nmeans at the papal power, and afterwards to abuse it.\"\n\nv. 71.  In the mighty mantle I was rob\'d.]  Nicholas III, of the\nOrsini family, whom the poet therefore calls \"figliuol dell\'\norsa,\" \"son of the she-bear.\"  He died in 1281.\n\nv. 86.  From forth the west, a shepherd without law.]   Bertrand\nde Got Archbishop of Bordeaux, who succeeded to the pontificate\nin 1305, and assumed the title of Clement V. He transferred the\nholy  see to Avignon in 1308 (where it remained till 1376), and\ndied in 1314.\n\nv. 88.  A new Jason.]  See Maccabees, b. ii. c. iv. 7,8.\n\nv. 97.  Nor Peter.]  Acts of the Apostles, c.i. 26.\n\nv. 100.  The condemned soul.]  Judas.\n\nv. 103.  Against Charles.]  Nicholas III. was enraged against\nCharles I, King of Sicily, because he rejected with scorn a\nproposition made by that Pope for an alliance between their\nfamilies.  See G. Villani, Hist. l. vii. c. liv.\n\nv. 109.  Th\' Evangelist.]  Rev. c. xvii. 1, 2, 3.  Compare\nPetrarch.  Opera fol. ed. Basil. 1551. Epist. sine titulo liber.\nep. xvi. p. 729.\n\nv. 118.  Ah, Constantine.]  He alludes to the pretended gift of\nthe Lateran by Constantine to Silvester, of which Dante himself\nseems to imply a doubt, in his treatise \"De Monarchia.\" - \"Ergo\nscindere Imperium, Imperatori non licet.  Si ergo aliquae,\ndignitates per Constantinum essent alienatae, (ut dicunt) ab\nImperio,\" &c. l. iii.\nThe gift is by Ariosto very humorously placed in the moon, among\nthe things lost or abused on earth.\n        Di varj fiori, &c.\n               O. F. c. xxxiv. st. 80.\n\nMilton has translated both this passage and that in the text.\nProse works, vol. i. p. 11. ed. 1753.\n\nCANTO XX\n\nv. 11.  Revers\'d.]  Compare Spenser, F. Q. b. i. c. viii.  st. 31\n\nv. 30.  Before whose eyes.]  Amphiaraus, one of the seven kings\nwho besieged Thebes.  He is said to have been swallowed up by  an\nopening of the earth.  See Lidgate\'s Storie of Thebes, Part III\nwhere it is told how the \"Bishop Amphiaraus\" fell down to hell.\n        And thus the devill for his outrages,\n        Like his desert payed him his wages.\nA different reason for his being doomed thus to perish is\nassigned by Pindar.\n[GREEK HERE]\n               Nem ix.\n\n        For thee, Amphiaraus, earth,\n        By Jove\'s all-riving thunder cleft\n        Her mighty bosom open\'d wide,\n        Thee and thy plunging steeds to hide,\n        Or ever on thy back the spear\n        Of Periclymenus impress\'d\n        A wound to shame thy warlike breast\n        For struck with panic fear\n        The gods\' own children flee.\n\nv. 37.  Tiresias.]\n        Duo magnorum viridi coeuntia sylva\n        Corpora serpentum baculi violaverat ictu, &c.\n               Ovid. Met. iii.\n\nv. 43.  Aruns.]  Aruns is said to have dwelt in the  mountains of\nLuni (from whence that territory is still called Lunigiana),\nabove Carrara, celebrated for its marble.  Lucan. Phars. l. i.\n575.  So Boccaccio in the Fiammetta, l. iii.  \"Quale Arunte,\" &c.\n\n\"Like Aruns, who amidst the white marbles of Luni, contemplated\nthe celestial bodies and their motions.\"\n\nv. 50.  Manto.]  The daughter of Tiresias of Thebes, a city\ndedicated to Bacchus.  From Manto Mantua, the country of Virgil\nderives its name. The Poet proceeds to describe the situation of\nthat place.\n\nv. 61.  Between the vale.]  The lake Benacus, now called  the\nLago di Garda, though here said to lie between Garda, Val\nCamonica, and the Apennine, is, however, very distant from the\nlatter two\n\nv. 63.  There is a spot.]  Prato di Fame, where the dioceses of\nTrento, Verona, and Brescia met.\n\nv. 69.  Peschiera.]  A garrison situated to the south of the\nlake, where it empties itself and forms the Mincius.\n\nv. 94.  Casalodi\'s madness.]  Alberto da Casalodi, who had got\npossess");
    strcat(expected_filecontent, "ion of Mantua, was persuaded by Pinamonte Buonacossi, that\nhe might ingratiate himself with the people by banishing to their\n\nown castles the nobles, who were obnoxious to them.  No sooner\nwas this done, than Pinamonte put himself at the head of the\npopulace, drove out Casalodi and his adherents, and obtained the\nsovereignty for himself.\n\nv. 111.  So sings my tragic strain.]\n        Suspensi Eurypilum scitatum oracula Phoebi\n        Mittimus.\n               Virg. Aeneid. ii. 14.\n\nv. 115.  Michael Scot.]  Sir Michael Scott, of Balwearie,\nastrologer to the Emperor Frederick II. lived in the thirteenth\ncentury.  For further particulars relating to this singular man,\nsee Warton\'s History of English Poetry, vol. i. diss. ii. and\nsect. ix.  p 292, and the Notes to Mr. Scott\'s \"Lay of the Last\nMinstrel,\" a  poem in which a happy use is made of the traditions\nthat are still current in North Britain concerning him.  He is\nmentioned by G. Villani. Hist. l. x. c. cv. and cxli. and l. xii.\nc. xviii. and by Boccaccio, Dec. Giorn. viii. Nov. 9.\n\nv. 116.  Guido Bonatti.]  An astrologer of Forli, on whose  skill\nGuido da Montefeltro, lord of that place, so much relied, that he\nis reported never to have gone into battle, except in the hour\nrecommended to him as fortunate by Bonatti.\n\nLandino and Vellutello, speak of a book, which he composed on the\nsubject of his art.\n\nv. 116.  Asdente.]  A shoemaker at Parma, who deserted his\nbusiness to practice the arts of divination.\n\nv. 123.  Cain with fork of thorns.]  By Cain and the thorns, or\nwhat is still vulgarly called the Man in the Moon, the Poet\ndenotes that luminary.  The same superstition is alluded to in\nthe Paradise, Canto II. 52.  The curious reader may consult Brand\non Popular Antiquities, 4to.  1813. vol. ii. p. 476.\n\nCANTO XXI\n\nv. 7.  In the Venetians\' arsenal.]  Compare Ruccellai, Le  Api,\n165, and Dryden\'s Annus Mirabilis, st. 146, &c.\n\nv. 37.  One of Santa Zita\'s elders.]  The elders or chief\nmagistrates of Lucca, where Santa Zita was held in especial\nveneration.  The name of this sinner is supposed to have been\nMartino Botaio.\n\nv. 40.  Except Bonturo, barterers.]  This is said ironically of\nBonturo de\' Dati.  By barterers are meant peculators, of every\ndescription; all who traffic the interests of the public  for\ntheir own private advantage.\n\nv. 48.  Is other swimming than in Serchio\'s wave.]\n        Qui si nuota altrimenti che nel Serchio.\nSerchio is the river that flows by Lucca.  So Pulci, Morg. Mag.\nc. xxiv.\n        Qui si nuota nel sangue, e non nel Serchio.\n\nv. 92.  From Caprona.]  The surrender of the castle of Caprona to\nthe combined forces of Florence and Lucca, on condition that the\ngarrison should march out in safety, to which ");

                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "MANY");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 15130, file);
                test_error(size == 15015, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 15015 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 15015);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 15015);


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
    

                char *filecontent = (char *)calloc(393, 1);
                char expected_filecontent[394] = "";

                strcat(expected_filecontent, " came; nor was it ever known whence\nhe was or wither he went.\" G. Villani, 1.  vi.  c. 92.\n\nv. 135.  Four daughters.]  Of the four daughters of Raymond\nBerenger, Margaret, the eldest, was married to Louis IX of\nFrance; Eleanor; the next, to Henry III, of England; Sancha, the\nthird, to Richard, Henry\'s brother, and King of the Romans; and\nthe youngest, Beatrice, to Charles I, King of Naples ");

                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "DIVIDETE.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 843, file);
                test_error(size == 393, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 393 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 393);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 393);


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
    

                char expected_filecontent[621] = "";

                strcat(expected_filecontent, "pass\'d me speechless by; and doing so\nHath made me more compassionate his fate.\"\n     So we discours\'d to where the rock first show\'d\nThe other valley, had more light been there,\nE\'en to the lowest depth.  Soon as we came\nO\'er the last cloister in the dismal rounds\nOf Malebolge, and the brotherhood\nWere to our view expos\'d, then many a dart\nOf sore lament assail\'d me, headed all\nWith points of thrilling pity, that I clos\'d\nBoth ears against the volley with mine hands.\n     As were the torment, if each lazar-house\nOf Valdichiana, in the sultry time\n\'Twixt July and September, with the isle\nSardinia and Maremma\'s pe");

                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "WANT.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 620; ++i)
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
    

                char expected_filecontent[14274] = "";

                strcat(expected_filecontent, "t.  Sails never such I saw\nOutstretch\'d on the wide sea.  No plumes had they,\nBut were in texture like a bat, and these\nHe flapp\'d i\' th\' air, that from him issued still\nThree winds, wherewith Cocytus to its depth\nWas frozen.  At six eyes he wept:  the tears\nAdown three chins distill\'d with bloody foam.\nAt every mouth his teeth a sinner champ\'d\nBruis\'d as with pond\'rous engine, so that three\nWere in this guise tormented.  But far more\nThan from that gnawing, was the foremost pang\'d\nBy the fierce rending, whence ofttimes the back\nWas stript of all its skin.  \"That upper spirit,\nWho hath worse punishment,\" so spake my guide,\n\"Is Judas, he that hath his head within\nAnd plies the feet without.  Of th\' other two,\nWhose heads are under, from the murky jaw\nWho hangs, is Brutus:  lo!  how he doth writhe\nAnd speaks not!  Th\' other Cassius, that appears\nSo large of limb.  But night now re-ascends,\nAnd it is time for parting.  All is seen.\"\n     I clipp\'d him round the neck, for so he bade;\nAnd noting time and place, he, when the wings\nEnough were op\'d, caught fast the shaggy sides,\nAnd down from pile to pile descending stepp\'d\nBetween the thick fell and the jagged ice.\n     Soon as he reach\'d the point, whereat the thigh\nUpon the swelling of the haunches turns,\nMy leader there with pain and struggling hard\nTurn\'d round his head, where his feet stood before,\nAnd grappled at the fell, as one who mounts,\nThat into hell methought we turn\'d again.\n     \"Expect that by such stairs as these,\" thus spake\nThe teacher, panting like a man forespent,\n\"We must depart from evil so extreme.\"\nThen at a rocky opening issued forth,\nAnd plac\'d me on a brink to sit, next join\'d\nWith wary step my side.  I rais\'d mine eyes,\nBelieving that I Lucifer should see\nWhere he was lately left, but saw him now\nWith legs held upward.  Let the grosser sort,\nWho see not what the point was I had pass\'d,\nBethink them if sore toil oppress\'d me then.\n     \"Arise,\" my master cried, \"upon thy feet.\n\"The way is long, and much uncouth the road;\nAnd now within one hour and half of noon\nThe sun returns.\"  It was no palace-hall\nLofty and luminous wherein we stood,\nBut natural dungeon where ill footing was\nAnd scant supply of light.  \"Ere from th\' abyss\nI sep\'rate,\" thus when risen I began,\n\"My guide!  vouchsafe few words to set me free\nFrom error\'s thralldom.  Where is now the ice?\nHow standeth he in posture thus revers\'d?\nAnd how from eve to morn in space so brief\nHath the sun made his transit?\"  He in few\nThus answering spake:  \"Thou deemest thou art still\nOn th\' other side the centre, where I grasp\'d\nTh\' abhorred worm, that boreth through the world.\nThou wast on th\' other side, so long as I\nDescended; when I turn\'d, thou didst o\'erpass\nThat point, to which from ev\'ry part is dragg\'d\nAll heavy substance.  Thou art now arriv\'d\nUnder the hemisphere opposed to that,\nWhich the great continent doth overspread,\nAnd underneath whose canopy expir\'d\nThe Man, that was born sinless, and so liv\'d.\nThy feet are planted on the smallest sphere,\nWhose other aspect is Judecca.  Morn\nHere rises, when there evening sets:  and he,\nWhose shaggy pile was scal\'d, yet standeth fix\'d,\nAs at the first.  On this part he fell down\nFrom heav\'n; and th\' earth, here prominent before,\nThrough fear of him did veil her with the sea,\nAnd to our hemisphere retir\'d.  Perchance\nTo shun him was the vacant space left here\nBy what of firm land on this side appears,\nThat sprang aloof.\"  There is a place beneath,\nFrom Belzebub as distant, as extends\nThe vaulted tomb, discover\'d not by sight,\nBut by the sound of brooklet, that descends\nThis way along the hollow of a rock,\nWhich, as it winds with no precipitous course,\nThe wave hath eaten.  By that hidden way\nMy guide and I did enter, to return\nTo the fair world:  and heedless of repose\nWe climbed, he first, I following his steps,\nTill on our view the beautiful lights of heav\'n\nDawn, through a circular opening in the cave:\nThus issuing we again beheld the stars.\n\n\n\nNOTES TO HELL\n\nCANTO I\n\nVerse 1.  In the midway.]  That the era of the Poem is intended\nby these words ");
    strcat(expected_filecontent, "to be fixed to the thirty fifth year of the poet\'s\nage, A.D. 1300, will appear more plainly in Canto XXI. where that\ndate is explicitly marked.\n\nv. 16.  That planet\'s beam.]  The sun.\n\nv. 29.  The hinder foot.]  It is to be remembered, that in\nascending a hill the weight of the body rests on the hinder foot.\n\nv. 30.  A panther.]  Pleasure or luxury.\n\nv. 36.  With those stars.]  The sun was in Aries, in which sign\nhe supposes it to have begun its course at the creation.\n\nv. 43.  A lion.]  Pride or ambition.\n\nv. 45.  A she wolf.]  Avarice.\n\nv. 56.  Where the sun in silence rests.]  Hence Milton appears to\nhave taken his idea in the Samson Agonistes:\n\n        The sun to me is dark\n               And silent as the moon, &c\nThe same metaphor will recur, Canto V. v. 29.\n        Into a place I came\n       Where light was silent all.\n\nv. 65.  When the power of Julius.] This is explained by the\ncommentators to mean \"Although it was rather late with respect to\nmy birth before Julius Caesar assumed the supreme authority, and\nmade himself perpetual dictator.\"\n\nv. 98.  That greyhound.]  This passage is intended as an eulogium\non the liberal spirit of his Veronese patron Can Grande della\nScala.\n\nv. 102.  \'Twizt either Feltro.]  Verona, the country of Can della\nScala, is situated between Feltro, a city in the Marca\nTrivigiana, and Monte Feltro, a city in the territory of Urbino.\n\nv. 103.  Italia\'s plains.]  \"Umile Italia,\" from Virgil, Aen lib.\niii. 522.\n        Humilemque videmus\n       Italiam.\n\nv. 115.  Content in fire.]  The spirits in Purgatory.\n\nv. 118.  A spirit worthier.]  Beatrice, who conducts the Poet\nthrough Paradise.\n\nv. 130.  Saint Peter\'s gate.]  The gate of Purgatory, which the\nPoet feigns to be guarded by an angel placed on that station by\nSt. Peter.\n\nCANTO II\n\nv. 1.  Now was the day.]  A compendium of Virgil\'s description\nAen. lib. iv 522.  Nox erat, &c. Compare Apollonius Rhodius, lib\niii. 744, and lib. iv. 1058\n\nv. 8.  O mind.]\n        O thought that write all that I met,\n        And in the tresorie it set\n        Of my braine, now shall men see\n        If any virtue in thee be.\n               Chaucer.  Temple of Fame, b. ii. v.18\n\nv. 14.  Silvius\'sire.] Aeneas.\n\nv. 30.  The chosen vessel.]  St.Paul, Acts, c. ix. v. 15.  \"But\nthe Lord said unto him, Go thy way; for he is a chosen vessel\nunto me.\"\n\nv. 46.  Thy soul.] L\'anima tua e da viltate offesa. So in Berni,\nOrl Inn.lib. iii. c. i. st. 53.\n        Se l\'alma avete offesa da viltate.\n\nv. 64.  Who rest suspended.]  The spirits in Limbo, neither\nadmitted to a state of glory nor doomed to punishment.\n\nv. 61.  A friend not of my fortune, but myself.]  Se non fortunae\nsed hominibus solere esse amicum.  Cornelii Nepotis Attici Vitae,\nc. ix.\n\nv. 78.  Whatever is contain\'d.]  Every other thing comprised\nwithin the lunar heaven, which, being the lowest of all, has the\nsmallest circle.\n\nv. 93.  A blessed dame.]  The divine mercy.\n\nv. 97.  Lucia.]  The enlightening grace of heaven.\n\nv. 124.  Three maids.]  The divine mercy, Lucia, and Beatrice.\n\nv. 127.  As florets.]  This simile is well translated by\nChaucer--\n        But right as floures through the cold of night\n        Iclosed, stoupen in her stalkes lowe,\n        Redressen hem agen the sunne bright,\n        And speden in her kinde course by rowe, &c.\n               Troilus and Creseide, b.ii.\nIt has been imitated by many others, among whom see Berni,\nOrl.Inn. Iib. 1. c. xii. st. 86.  Marino, Adone, c. xvii. st. 63.\nand Sor. \"Donna vestita di nero.\" and Spenser\'s Faery Queen, b.4.\nc. xii. st. 34. and b. 6 c. ii. st. 35.\n\nCANTO III\n\nv. 5.          Power divine\n        Supremest wisdom, and primeval love.]  The three\npersons of the blessed Trinity.\nv. 9.  all hope abandoned.] Lasciate ogni speranza voi\nch\'entrate.\nSo Berni, Orl. Inn. lib. i. c. 8. st. 53.\n        Lascia pur della vita ogni speranza.\n\nv. 29.  Like to the sand.]\n               Unnumber\'d as the sands\n        Of Barca or Cyrene\'s torrid soil\n        Levied to side with warring winds, and poise\n        Their lighter wings.\n               Milton, P. L. ii. 908.");
    strcat(expected_filecontent, "\n\nv. 40.  Lest th\' accursed tribe.]  Lest the rebellious angels\nshould exult at seeing those who were neutral and therefore less\nguilty, condemned to the same punishment with themselves.\n\nv. 50.  A flag.]\n               All the grisly legions that troop\n        Under the sooty flag of Acheron\n               Milton. Comus.\n\nv. 56.         Who to base fear\n        Yielding, abjur\'d his high estate.] This is\ncommonly understood of Celestine the Fifth, who abdicated the\npapal power in 1294. Venturi mentions a work written by\nInnocenzio Barcellini, of the Celestine order, and printed in\nMilan in 1701, In which an attempt is made to put a different\ninterpretation on this passage.\n\nv. 70.  through the blear light.]\n        Lo fioco lume\nSo Filicaja, canz. vi. st. 12.\n        Qual fioco lume.\n\nv. 77.  An old man.]\n        Portitor has horrendus aquas et flumina servat\n        Terribili squalore Charon, cui plurima mento\n        Canities inculta jacet; stant lumina flamma.\n               Virg. 7.  Aen. Iib. vi. 2.\n\nv. 82.  In fierce heat and in ice.]\n               The delighted spirit\n        To bathe in fiery floods or to reside\n        In thrilling regions of thick ribbed ice.\n               Shakesp. Measure for Measure, a. iii.s.1.\nCompare Milton, P. L. b. ii. 600.\n\nv. 92.  The livid lake.] Vada livida.\n               Virg. Aen. Iib. vi. 320\n               Totius ut Lacus putidaeque paludis\n        Lividissima, maximeque est profunda vorago.\n               Catullus. xviii. 10.\n\nv. 102.  With eyes of burning coal.]\n        His looks were dreadful, and his fiery eyes\n        Like two great beacons glared bright and wide.\n               Spenser. F.Q. b. vi. c. vii.st. 42\n\nv. 104.  As fall off the light of autumnal leaves.]\n        Quam multa in silvis autumul frigore primo\n        Lapsa cadunt folia.\n               Virg. Aen. lib. vi. 309\nCompare Apoll.  Rhod. lib. iv. 214.\n\nCANTO IV\n\nv. 8.  A thund\'rous sound.]  Imitated, as Mr. Thyer has remarked,\nby Milton, P. L. b. viii. 242.\n               But long ere our approaching heard\n        Noise, other, than the sound of dance or song\n        Torment, and loud lament, and furious rage.\n\nv. 50.  a puissant one.]  Our Saviour.\n\nv. 75.                 Honour the bard\n        Sublime.]\n\n        Onorate l\'altissimo poeta.\nSo Chiabrera, Canz. Eroiche. 32.\n        Onorando l\'altissimo poeta.\n\nv. 79.  Of semblance neither sorrowful nor glad.]\n        She nas to sober ne to glad.\n               Chaucer\'s Dream.\n\nv. 90.  The Monarch of sublimest song.]  Homer.\n\nv. 100.  Fitter left untold.]\n        Che\'l tacere e bello,\nSo our Poet, in Canzone 14.\n        La vide in parte che\'l tacere e bello,\nRuccellai, Le Api, 789.\n        Ch\'a dire e brutto ed a tacerlo e bello\nAnd Bembo,\n        \"Vie pui bello e il tacerle, che il favellarne.\"\n               Gli. Asol. lib. 1.\n\nv. 117.  Electra.]  The daughter of Atlas, and mother of Dardanus\nthe founder of Troy.  See Virg. Aen. b. viii. 134. as referred to\nby Dante in treatise \"De Monarchia,\" lib. ii. \"Electra, scilicet,\nnata magni nombris regis Atlantis, ut de ambobus testimonium\nreddit poeta noster in octavo ubi Aeneas ad Avandrum sic ait\n        \"Dardanus Iliacae,\" &c.\n\nv. 125.  Julia.]  The daughter of Julius Caesar, and wife of\nPompey.\n\nv. 126.  The Soldan fierce.]  Saladin or Salaheddin, the  rival\nof  Richard coeur de lion.  See D\'Herbelot, Bibl. Orient. and\nKnolles\'s Hist. of the Turks p. 57 to 73 and the Life of Saladin,\nby Bohao\'edin Ebn Shedad, published by Albert Schultens, with a\nLatin translation. He is introduced by Petrarch in the Triumph of\nFame, c. ii\n\nv. 128.  The master of the sapient throng.]\n        Maestro di color che sanno.\nAristotle--Petrarch assigns the first place to Plato. See Triumph\nof Fame, c. iii.\nPulci, in his Morgante Maggiore, c. xviii. says,\n        Tu se\'il maestro di color che sanno.\n\nv. 132.               Democritus\n        Who sets the world at chance.]\nDemocritus,who maintained the world to have been formed by the\nfortuitous concourse of atoms.\n\nv. 140.  Avicen.]  See D\'Herbelot Bibl. Orient. article  Sina. He\n");
    strcat(expected_filecontent, "died in 1050.  Pulci here again imitates our poet:\n\n        Avicenna quel che il sentimento\n        Intese di Aristotile e i segreti,\n        Averrois che fece il gran comento.\n               Morg. Mag. c. xxv.\n\nv. 140.               Him who made\n        That commentary vast, Averroes.]\nAverroes, called by the Arabians Roschd, translated and commented\nthe works of Aristotle. According to Tiraboschi (storia della\nLett. Ital. t. v. 1. ii. c. ii. sect. 4.) he was the source of\nmodern philosophical impiety. The critic quotes some passages\nfrom Petrarch (Senil. 1. v. ep. iii. et. Oper. v. ii. p. 1143) to\nshow how strongly such sentiments prevailed in the time of that\npoet, by whom they were held in horror and detestation He adds,\nthat this fanatic admirer of Aristotle translated his writings\nwith that felicity, which might be expected from one who did not\nknow a syllable of Greek, and who was therefore compelled to\navail himself of the unfaithful Arabic versions. D\'Herbelot, on\nthe other hand, informs us, that \"Averroes was the first who\ntranslated Aristotle from Greek into Arabic, before the Jews had\nmade their translation:  and that we had for a long time no other\ntext of Aristotle, except that of the Latin translation, which\nwas made from this Arabic version of this great philosopher\n(Averroes), who afterwards added to it a very ample commentary,\nof which Thomas Aquinas, and the other scholastic writers,\navailed themselves, before the Greek originals of Aristotle and\nhis commentators were known to us in Europe.\" According to\nD\'Herbelot, he died in 1198: but Tiraboschi places that event\nabout 1206.\n\nCANTO V\n\nv. 5.  Grinning with ghastly feature.]  Hence Milton:\n               Death\n        Grinn\'d horrible a ghastly smile.\n               P. L. b. ii. 845.\n\nv. 46.  As cranes.]  This simile is imitated by Lorenzo de\nMedici, in his Ambra, a poem, first published by Mr. Roscoe, in\nthe  Appendix to his Life of Lorenzo.\n        Marking the tracts of air, the clam");

                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "COMMON.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 14273; ++i)
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
    

                char expected_filecontent[14337] = "";

                strcat(expected_filecontent, "y leader\'s feet still equaling pace\nFrom forth that cloud I came, when now expir\'d\nThe parting beams from off the nether shores.\n     O quick and forgetive power!  that sometimes dost\nSo rob us of ourselves, we take no mark\nThough round about us thousand trumpets clang!\nWhat moves thee, if the senses stir not?  Light\nKindled in heav\'n, spontaneous, self-inform\'d,\nOr likelier gliding down with swift illapse\nBy will divine.  Portray\'d before me came\nThe traces of her dire impiety,\nWhose form was chang\'d into the bird, that most\nDelights itself in song: and here my mind\nWas inwardly so wrapt, it gave no place\nTo aught that ask\'d admittance from without.\n     Next shower\'d into my fantasy a shape\nAs of one crucified, whose visage spake\nFell rancour, malice deep, wherein he died;\nAnd round him Ahasuerus the great king,\nEsther his bride, and Mordecai the just,\nBlameless in word and deed.  As of itself\nThat unsubstantial coinage of the brain\nBurst, like a bubble, Which the water fails\nThat fed it; in my vision straight uprose\nA damsel weeping loud, and cried, \"O queen!\nO mother!  wherefore has intemperate ire\nDriv\'n thee to loath thy being?  Not to lose\nLavinia, desp\'rate thou hast slain thyself.\nNow hast thou lost me.  I am she, whose tears\nMourn, ere I fall, a mother\'s timeless end.\"\n     E\'en as a sleep breaks off, if suddenly\nNew radiance strike upon the closed lids,\nThe broken slumber quivering ere it dies;\nThus from before me sunk that imagery\nVanishing, soon as on my face there struck\nThe light, outshining far our earthly beam.\nAs round I turn\'d me to survey what place\nI had arriv\'d at, \"Here ye mount,\" exclaim\'d\nA voice, that other purpose left me none,\nSave will so eager to behold who spake,\nI could not choose but gaze.  As \'fore the sun,\nThat weighs our vision down, and veils his form\nIn light transcendent, thus my virtue fail\'d\nUnequal.  \"This is Spirit from above,\nWho marshals us our upward way, unsought;\nAnd in his own light shrouds him;. As a man\nDoth for himself, so now is done for us.\nFor whoso waits imploring, yet sees need\nOf his prompt aidance, sets himself prepar\'d\nFor blunt denial, ere the suit be made.\nRefuse we not to lend a ready foot\nAt such inviting: haste we to ascend,\nBefore it darken: for we may not then,\nTill morn again return.\"  So spake my guide;\nAnd to one ladder both address\'d our steps;\nAnd the first stair approaching, I perceiv\'d\nNear me as \'twere the waving of a wing,\nThat fann\'d my face and whisper\'d: \"Blessed they\nThe peacemakers: they know not evil wrath.\"\n     Now to such height above our heads were rais\'d\nThe last beams, follow\'d close by hooded night,\nThat many a star on all sides through the gloom\nShone out.  \"Why partest from me, O my strength?\"\nSo with myself I commun\'d; for I felt\nMy o\'ertoil\'d sinews slacken.  We had reach\'d\nThe summit, and were fix\'d like to a bark\nArriv\'d at land.  And waiting a short space,\nIf aught should meet mine ear in that new round,\nThen to my guide I turn\'d, and said: \"Lov\'d sire!\nDeclare what guilt is on this circle purg\'d.\nIf our feet rest, no need thy speech should pause.\"\n     He thus to me:  \"The love of good, whate\'er\nWanted of just proportion, here fulfils.\nHere plies afresh the oar, that loiter\'d ill.\nBut that thou mayst yet clearlier understand,\nGive ear unto my words, and thou shalt cull\nSome fruit may please thee well, from this delay.\n     \"Creator, nor created being, ne\'er,\nMy son,\" he thus began, \"was without love,\nOr natural, or the free spirit\'s growth.\nThou hast not that to learn.  The natural still\nIs without error; but the other swerves,\nIf on ill object bent, or through excess\nOf vigour, or defect.  While e\'er it seeks\nThe primal blessings, or with measure due\nTh\' inferior, no delight, that flows from it,\nPartakes of ill.  But let it warp to evil,\nOr with more ardour than behooves, or less.\nPursue the good, the thing created then\nWorks \'gainst its Maker.  Hence thou must infer\nThat love is germin of each virtue in ye,\nAnd of each act no less, that merits pain.\nNow since it may not be, but love intend\nThe welfare mainly of the thing i");
    strcat(expected_filecontent, "t loves,\nAll from self-hatred are secure; and since\nNo being can be thought t\' exist apart\nAnd independent of the first, a bar\nOf equal force restrains from hating that.\n     \"Grant the distinction just; and it remains\nThe\' evil must be another\'s, which is lov\'d.\nThree ways such love is gender\'d in your clay.\nThere is who hopes (his neighbour\'s worth deprest,)\nPreeminence himself, and coverts hence\nFor his own greatness that another fall.\nThere is who so much fears the loss of power,\nFame, favour, glory (should his fellow mount\nAbove him), and so sickens at the thought,\nHe loves their opposite: and there is he,\nWhom wrong or insult seems to gall and shame\nThat he doth thirst for vengeance, and such needs\nMust doat on other\'s evil.  Here beneath\nThis threefold love is mourn\'d.  Of th\' other sort\nBe now instructed, that which follows good\nBut with disorder\'d and irregular course.\n     \"All indistinctly apprehend a bliss\nOn which the soul may rest, the hearts of all\nYearn after it, and to that wished bourn\nAll therefore strive to tend.  If ye behold\nOr seek it with a love remiss and lax,\nThis cornice after just repenting lays\nIts penal torment on ye.  Other good\nThere is, where man finds not his happiness:\nIt is not true fruition, not that blest\nEssence, of every good the branch and root.\nThe love too lavishly bestow\'d on this,\nAlong three circles over us, is mourn\'d.\nAccount of that division tripartite\nExpect not, fitter for thine own research.\n\n\n\nCANTO XVIII\n\nThe teacher ended, and his high discourse\nConcluding, earnest in my looks inquir\'d\nIf I appear\'d content; and I, whom still\nUnsated thirst to hear him urg\'d, was mute,\nMute outwardly, yet inwardly I said:\n\"Perchance my too much questioning offends\nBut he, true father, mark\'d the secret wish\nBy diffidence restrain\'d, and speaking, gave\nMe boldness thus to speak: \"Master, my Sight\nGathers so lively virtue from thy beams,\nThat all, thy words convey, distinct is seen.\nWherefore I pray thee, father, whom this heart\nHolds dearest!  thou wouldst deign by proof t\' unfold\nThat love, from which as from their source thou bring\'st\nAll good deeds and their opposite.\"  He then:\n\"To what I now disclose be thy clear ken\nDirected, and thou plainly shalt behold\nHow much those blind have err\'d, who make themselves\nThe guides of men.  The soul, created apt\nTo love, moves versatile which way soe\'er\nAught pleasing prompts her, soon as she is wak\'d\nBy pleasure into act.  Of substance true\nYour apprehension forms its counterfeit,\nAnd in you the ideal shape presenting\nAttracts the soul\'s regard.  If she, thus drawn,\nincline toward it, love is that inclining,\nAnd a new nature knit by pleasure in ye.\nThen as the fire points up, and mounting seeks\nHis birth-place and his lasting seat, e\'en thus\nEnters the captive soul into desire,\nWhich is a spiritual motion, that ne\'er rests\nBefore enjoyment of the thing it loves.\nEnough to show thee, how the truth from those\nIs hidden, who aver all love a thing\nPraise-worthy in itself: although perhaps\nIts substance seem still good.  Yet if the wax\nBe good, it follows not th\' impression must.\"\n\"What love is,\" I return\'d, \"thy words, O guide!\nAnd my own docile mind, reveal.  Yet thence\nNew doubts have sprung.  For from without if love\nBe offer\'d to us, and the spirit knows\nNo other footing, tend she right or wrong,\nIs no desert of hers.\"  He answering thus:\n\"What reason here discovers I have power\nTo show thee: that which lies beyond, expect\nFrom Beatrice, faith not reason\'s task.\nSpirit, substantial form, with matter join\'d\nNot in confusion mix\'d, hath in itself\nSpecific virtue of that union born,\nWhich is not felt except it work, nor prov\'d\nBut through effect, as vegetable life\nBy the green leaf.  From whence his intellect\nDeduced its primal notices of things,\nMan therefore knows not, or his appetites\nTheir first affections; such in you, as zeal\nIn bees to gather honey; at the first,\nVolition, meriting nor blame nor praise.\nBut o\'er each lower faculty supreme,\nThat as she list are summon\'d to her bar,\nYe have that virtue in you, whose just voice\nUttereth co");
    strcat(expected_filecontent, "unsel, and whose word should keep\nThe threshold of assent.  Here is the source,\nWhence cause of merit in you is deriv\'d,\nE\'en as the affections good or ill she takes,\nOr severs, winnow\'d as the chaff.  Those men\nWho reas\'ning went to depth profoundest, mark\'d\nThat innate freedom, and were thence induc\'d\nTo leave their moral teaching to the world.\nGrant then, that from necessity arise\nAll love that glows within you; to dismiss\nOr harbour it, the pow\'r is in yourselves.\nRemember, Beatrice, in her style,\nDenominates free choice by eminence\nThe noble virtue, if in talk with thee\nShe touch upon that theme.\"  The moon, well nigh\nTo midnight hour belated, made the stars\nAppear to wink and fade; and her broad disk\nSeem\'d like a crag on fire, as up the vault\nThat course she journey\'d, which the sun then warms,\nWhen they of Rome behold him at his set.\nBetwixt Sardinia and the Corsic isle.\nAnd now the weight, that hung upon my thought,\nWas lighten\'d by the aid of that clear spirit,\nWho raiseth Andes above Mantua\'s name.\nI therefore, when my questions had obtain\'d\nSolution plain and ample, stood as one\nMusing in dreary slumber; but not long\nSlumber\'d; for suddenly a multitude,\nThe steep already turning, from behind,\nRush\'d on.  With fury and like random rout,\nAs echoing on their shores at midnight heard\nIsmenus and Asopus, for his Thebes\nIf Bacchus\' help were needed; so came these\nTumultuous, curving each his rapid step,\nBy eagerness impell\'d of holy love.\n     Soon they o\'ertook us; with such swiftness mov\'d\nThe mighty crowd.  Two spirits at their head\nCried weeping; \"Blessed Mary sought with haste\nThe hilly region.  Caesar to subdue\nIlerda, darted in Marseilles his sting,\nAnd flew to Spain.\"--\"Oh tarry not: away;\"\nThe others shouted; \"let not time be lost\nThrough slackness of affection.  Hearty zeal\nTo serve reanimates celestial grace.\"\n     \"O ye, in whom intenser fervency\nHaply supplies, where lukewarm erst ye fail\'d,\nSlow or neglectful, to absolve your part\nOf good and virtuous, this man, who yet lives,\n(Credit my tale, though strange) desires t\' ascend,\nSo morning rise to light us.  Therefore say\nWhich hand leads nearest to the rifted rock?\"\n     So spake my guide, to whom a shade return\'d:\n\"Come after us, and thou shalt find the cleft.\nWe may not linger: such resistless will\nSpeeds our unwearied course.  Vouchsafe us then\nThy pardon, if our duty seem to thee\nDiscourteous rudeness.  In Verona I\nWas abbot of San Zeno, when the hand\nOf Barbarossa grasp\'d Imperial sway,\nThat name, ne\'er utter\'d without tears in Milan.\nAnd there is he, hath one foot in his grave,\nWho for that monastery ere long shall weep,\nRuing his power misus\'d: for that his son,\nOf body ill compact, and worse in mind,\nAnd born in evil, he hath set in place\nOf its true pastor.\"  Whether more he spake,\nOr here was mute, I know not: he had sped\nE\'en now so far beyond us.  Yet thus much\nI heard, and in rememb\'rance treasur\'d it.\n     He then, who never fail\'d me at my need,\nCried, \"Hither turn.  Lo!  two with sharp remorse\nChiding their sin!\"  In rear of all the troop\nThese shouted:  \"First they died, to whom the sea\nOpen\'d, or ever Jordan saw his heirs:\nAnd they, who with Aeneas to the end\nEndur\'d not suffering, for their portion chose\nLife without glory.\"  Soon as they had fled\nPast reach of sight, new thought within me rose\nBy others follow\'d fast, and each unlike\nIts fellow: till led on from thought to thought,\nAnd pleasur\'d with the fleeting train, mine eye\nWas clos\'d, and meditation chang\'d to dream.\n\n\nCANTO XIX\n\nIt was the hour, when of diurnal heat\nNo reliques chafe the cold beams of the moon,\nO\'erpower\'d by earth, or planetary sway\nOf Saturn; and the geomancer sees\nHis Greater Fortune up the east ascend,\nWhere gray dawn checkers first the shadowy cone;\nWhen \'fore me in my dream a woman\'s shape\nThere came, with lips that stammer\'d, eyes aslant,\nDistorted feet, hands maim\'d, and colour pale.\n     I look\'d upon her; and as sunshine cheers\nLimbs numb\'d by nightly cold, e\'en thus my look\nUnloos\'d her tongue, next in brief space her form\nDecrepit rais\'d erect, ");
    strcat(expected_filecontent, "and faded face\nWith love\'s own hue illum\'d. Recov\'ring speech\nShe forthwith warbling such a strain began,\nThat I, how loth soe\'er, could scarce have held\nAttention from the song.  \"I,\" thus she sang,\n\"I am the Siren, she, whom mariners\nOn the wide sea are wilder\'d when they hear:\nSuch fulness of delight the list\'ner feels.\nI from his course Ulysses by my lay\nEnchanted drew.  Whoe\'er frequents me once\nParts seldom; so I charm him, and his heart\nContented knows no void.\"  Or ere her mouth\nWas clos\'d, to shame her at her side appear\'d\nA dame of semblance holy.  With stern voice\nShe utter\'d; \"Say, O Virgil, who is this?\"\nWhich hearing, he approach\'d, with eyes still bent\nToward that goodly presence: th\' other seiz\'d her,\nAnd, her robes tearing, open\'d her before,\nAnd show\'d the belly to me, whence a smell,\nExhaling loathsome, wak\'d me.  Round I turn\'d\nMine eyes, and thus the teacher:  \"At the least\nThree times my voice hath call\'d thee.  Rise, begone.\nLet us the opening find where thou mayst pass.\"\n     I straightway rose.  Now day, pour\'d down from high,\nFill\'d all the circuits of the sacred mount;\nAnd, as we journey\'d, on our shoulder smote\nThe early ray.  I follow\'d, stooping low\nMy forehead, as a man, o\'ercharg\'d with thought,\nWho bends him to the likeness of an arch,\nThat midway spans the flood; when thus I heard,\n\"Come, enter here,\" in tone so soft and mild,\nAs never met the ear on mortal strand.\n     With swan-like wings dispread and pointing up,\nWho thus had spoken marshal\'d us along,\nWhere each side of the solid masonry\nThe sloping, walls retir\'d; then mov\'d his plumes,\nAnd fanning us, affirm\'d that those, who mourn,\nAre blessed, for that comfort shall be theirs.\n     \"What aileth thee, that still thou look\'st to earth?\"\nBegan my leader; while th\' angelic shape\nA little over us his station took.\n     \"New vision,\" I replied, \"hath rais\'d in me\n8urmisings strange and anxious doubts, whereon\nMy soul intent allows no other thought\nOr room or entrance.--\"Hast thou seen,\" said he,\n\"That old enchantress, her, whose w");

                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "SOME.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 14336; ++i)
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
    

                char expected_filecontent[14151] = "";

                strcat(expected_filecontent, "ed in 1312, at\nthe age of twenty four, in consequence, as it was supposed, of\nhis extreme intemperance.\nSee Mariana, Hist I. xv.  c. 11.\n\nv. 123.  The Bohemian.]  Winceslaus II.  Purgatory, Canto VII. v.\n\nv. 125.  The halter of Jerusalem.]  Charles II of Naples and\nJerusalem who was lame.  See note to Purgatory, Canto VII.  v.\n122, and XX. v. 78.\n\nv. 127.  He.]  Frederick of Sicily son of Peter III of Arragon.\nPurgatory, Canto VII.  v. 117.  The isle of fire is Sicily, where\nwas the tomb of Anchises.\n\nv. 133.  His uncle.]  James, king of Majorca and Minorca, brother\nto Peter III.\n\nv. 133.  His brother.]  James II of Arragon, who died in 1327.\nSee Purgatory, Canto VII.  v. 117.\n\nv. 135.  Of Portugal.]  In the time of Dante, Dionysius was king\nof Portugal.  He died in 1328, after a reign of near forty-six\nyears, and does not seem to have deserved the stigma here\nfastened on him. See Mariana. and 1. xv. c. 18.  Perhaps the\nrebellious son of Dionysius may be alluded to.\n\nv. 136.  Norway.]  Haquin, king of Norway, is probably meant;\nwho, having given refuge to the murderers of Eric VII king of\nDenmark, A D. 1288, commenced a war against his successor, Erie\nVIII, \"which continued for nine years, almost to the utter ruin\nand destruction of both kingdoms.\"  Modern Univ. Hist. v. xxxii\np. 215.\n\nv. 136.  -Him\nOf Ratza.]\nOne of the dynasty of the house of Nemagna, which ruled the\nkingdom of Rassia, or Ratza, in Sclavonia, from 1161 to 1371, and\nwhose history may be found in Mauro Orbino, Regno degli Slavi,\nEdiz. Pesaro. 1601. Uladislaus appears to have been the sovereign\nin Dante\'s time, but the disgraceful forgery adverted to in the\ntext, is not recorded by the historian v. 138.  Hungary.]  The\nkingdom of Hungary was about this time disputed by Carobert, son\nof Charles Martel, and Winceslaus, prince of Bohemia, son of\nWinceslaus II.  See Coxe\'s House of Austria, vol. i. p. 1. p. 86.\n\n4to edit.\n\nv. 140.  Navarre.]  Navarre was now under the yoke of France.\n It soon after (in 1328) followed the advice of Dante and had a\nmonarch of its own.  Mariana, 1.  xv. c. 19.\n\nv. 141.  Mountainous girdle.]  The Pyrenees.\n\nv. 143.  -Famagosta\'s streets\nAnd Nicosia\'s.]\n\nCities in the kingdom of Cyprus, at that time ruled by Henry II a\npusillanimous prince. Vertot.  Hist. des Chev.  de Malte, 1. iii.\niv. The meaning appears to be, that the complaints made by those\ncities of their weak and worthless governor, may be regarded as\nan earnest of his condemnation at the last doom.\n\nCANTO XX\n\nv. 6.  Wherein one shines.]  The light of the sun, whence he\nsupposes the other celestial bodies to derive their light\n\nv. 8.  The great sign.]  The eagle, the Imperial ensign.\n\nv. 34.  Who.]  David.\n\nv. 39.  He.]  Trajan.  See Purgatory, Canto X. 68.\n\nv. 44.  He next.]  Hezekiah.\n\nv. 50.  \'The other following.]  Constantine.  There is no passage\nin which Dante\'s opinion of the evil; that had arisen from the\nmixture of the civil with the ecclesiastical power, is more\nunequivocally  declared.\n\nv. 57.  William.]  William II, king of Sicily, at the latter part\nof  the twelfth century He was of the Norman line of sovereigns,\nand obtained the appellation of \"the Good\" and, as the poet says\nhis loss was as much the subject of regret in his dominions, as\nthe presence of Charles I of Anjou and Frederick of Arragon, was\nof sorrow and complaint.\n\nv. 62.  Trojan Ripheus.]\nRipheus, justissimus unus\nQui fuit in Teneris, et servantissimus aequi.\nVirg.  Aen.  1. ii. 4--.\n\nv. 97.  This.]  Ripheus.\n\nv. 98.  That.]  Trajan.\n\nv. 103.  The prayers,] The prayers of St. Gregory\n\nv. 119.  The three nymphs.]  Faith, Hope, and Charity. Purgatory,\nCanto XXIX.  116.\nv. 138.  The pair.]  Ripheus and Trajan.\n\nCANTO XXI\n\nv. 12.  The seventh splendour.]  The planet Saturn\n\nv. 13.  The burning lion\'s breast.]  The constellation Leo.\n\nv. 21.  In equal balance.]  \"My pleasure was as great in\ncomplying\nwith her will as in beholding her countenance.\"\n\nv. 24.  Of that lov\'d monarch.]  Saturn.  Compare Hell, Canto\nXIV.  91.\n\nv. 56.  What forbade the smile.]  \"Because it would have overcome\nthee.\"\n\nv. 6");
    strcat(expected_filecontent, "1.  There aloft.]  Where the other souls were.\n\nv. 97.  A stony ridge.]  The Apennine.\n\nv. 112.  Pietro Damiano.]  \"S. Pietro Damiano obtained a great\nand well-merited reputation, by the pains he took to correct the\nabuses among the clergy.  Ravenna is supposed to have been the\nplace of his birth, about 1007.  He was employed in several\nimportant missions, and rewarded by Stephen IX with the dignity\nof cardinal, and the bishopric of Ostia, to which, however, he\npreferred his former retreat in the monastery of Fonte Aveliana,\nand prevailed on Alexander II to permit him to retire thither.\nYet he did not long continue in this seclusion, before he was\nsent on other embassies.  He died at Faenza in 1072.  His\nletters throw much light on the obscure history of these times.\nBesides them, he has left several treatises on sacred and\necclesiastical subjects. His eloquence is worthy of a better\nage.\"  Tiraboschi, Storia della Lett Ital. t. iii.  1. iv. c. 2.\n\nv. 114.  Beside the Adriatic.]  At Ravenna.  Some editions have\nFU instead of FUI, according to which reading, Pietro\ndistinguishes  himself from another Pietro, who was termed\n\"Peccator,\" the sinner.\n\nv. 117.  The hat.]  The cardinal\'s hat.\n\nv. 118.  Cephas.]  St. Peter.\n\nv. 119 The Holy Spirit\'s vessel.]  St. Paul. See Hell, Canto II.\n30.\n\nv. 130.  Round this.]  Round the spirit of Pietro Damiano.\n\nCANTO XXII\n\nv. 14.  The vengeance.]  Beatrice, it is supposed, intimates the\napproaching fate of Boniface VIII.  See Purgatory, Canto XX.  86.\n\nv. 36.  Cassino.]  A castle in the Terra di Lavoro.\n\nv. 38.  I it was.]  \"A new order of monks, which in a manner\nabsorbed all the others that were established in the west, was\ninstituted, A.D.  529, by Benedict of Nursis, a man of piety and\nreputation for the age he  lived in.\"  Maclaine\'s Mosheim,\nEccles. Hist. v. ii.  cent. vi. p. 2. ch.  2 - 6.\n\nv. 48.  Macarius.]  There are two of this name enumerated by\nMosheim among the Greek theologians of the fourth century, v. i.\ncent. iv p. 11 ch. 2 - 9.  In the following chapter, 10, it is\nsaid, \"Macarius, an Egyptian monk, undoubtedly deserves the first\nrank among the practical matters of this time, as his works\ndisplayed, some few things excepted, the brightest and most\nlovely portraiture of sanctity and virtue.\"\n\nv. 48.  Romoaldo.]  S. Romoaldo, a native of Ravenna, and the\nfounder of the order of Camaldoli, died in 1027.  He was the\nauthor of a commentary on the Psalms.\n\nv. 70.  The patriarch Jacob.]  So Milton, P. L. b. iii. 510:\nThe stairs were such, as whereon Jacob saw\nAngels ascending and descending, bands\nOf guardians bright.\n\nv. 107.  The sign.]  The constellation of Gemini.\n\nv. 130. This globe.]  So Chaucer, Troilus and Cresseide, b. v,\n\nAnd down from thence fast he gan avise\nThis little spot of earth, that with the sea\nEmbraced is, and fully gan despite\nThis wretched world.\n\nCompare Cicero, Somn. Scip.  \"Jam ipsa terra ita mihi parva visa\nest.\" &c.  Lucan, Phar 1.  ix. 11;  and Tasso, G.  L.  c.  xiv.\nst, 9, 10, 11.\n\nv. 140.  Maia and Dione.]  The planets Mercury and Venus.\n\nCANTO XXIII\n\nv. 11.  That region.]  Towards the south, where the course of the\nsun appears less rapid, than, when he is in the east or the west.\n\nv. 26.  Trivia.]  A name of Diana.\n\nv. 26.  Th\' eternal nymphs.]  The stars.\n\nv. 36.  The Might.]  Our Saviour\n\nv. 71.  The rose.]  The Virgin Mary.\n\nv. 73.  The lilies.]  The apostles.\n\nv. 84.  Thou didst exalt thy glory.]  The diving light retired\nupwards, to render the eyes of Dante more capable of enduring the\nspectacle  which now presented itself.\n\nv. 86.  The name of that fair flower.]  The name of the Virgin.\n\nv. 92.  A cresset.]  The angel Gabriel.\n\nv. 98.  That lyre.]  By synecdoche, the lyre is put for the angel\n\nv. 99.  The goodliest sapphire.]  The Virgin\n\nv. 126.  Those rich-laden coffers.]  Those spirits who, having\nsown the seed of good works on earth, now contain the fruit of\ntheir pious endeavours.\n\nv. 129.  In the Babylonian exile.]  During their abode in this\nworld.\n\nv. 133.  He.]  St. Peter, with the other holy men of the Old and\nNew testament.\n\nC");
    strcat(expected_filecontent, "ANTO XXIV\n\nv. 28.  Such folds.]  Pindar has the same bold image:\n[GREEK HERE?]\nOn which Hayne strangely remarks:  Ad ambitus stropharum vldetur\n\nv. 65.  Faith.]  Hebrews, c.  xi.  1.  So Marino, in one of his\nsonnets, which calls Divozioni:\n\nFede e sustanza di sperate cose,\nE delle non visioili argomento.\n\nv. 82.  Current.]  \"The answer thou hast made is right; but let\nme know if thy inward persuasion is conformable to thy\nprofession.\"\n\nv. 91.  The ancient bond and new.]  The Old and New Testament.\n\nv. 114.  That Worthy.]  Quel Baron.\nIn the next Canto, St. James is called \"Barone.\"  So in\nBoccaccio, G. vi. N. 10, we find \"Baron Messer Santo Antonio.\"\nv. 124.  As to outstrip.]  Venturi insists that the Poet has\nhere, \"made a slip;\" for that John came first to the sepulchre,\nthough Peter was the first to enter it.  But let Dante have leave\nto explain his own meaning, in a passage from his third book De\nMonarchia:  \"Dicit etiam Johannes ipsum (scilicet Petrum)\nintroiisse SUBITO, cum venit in monumentum, videns allum\ndiscipulum cunctantem ad ostium.\" Opere de Dante, Ven. 1793. T.\nii. P. 146.\n\nCANTO XXV\n\nv. 6.  The fair sheep-fold.]  Florence, whence he was banished.\n\nv. 13.  For its sake.]  For the sake of that faith.\n\nv. 20.  Galicia throng\'d with visitants.] See Mariana, Hist. 1.\nxi.\n\nv. 13.  \"En el tiempo,\" &c.  \"At the time that the sepulchre of\nthe apostle St. James was discovered, the devotion for that place\nextended itself not only over all Spain, but even round about to\nforeign nations. Multitudes from all parts of the world came to\nvisit it.  Many others were deterred by the difficulty for the\njourney, by the roughness and barrenness of those parts, and by\nthe incursions of the Moors, who made captives many of the\npilgrims.  The canons of St. Eloy afterwards (the precise time is\nnot known), with a desire of remedying these evils, built, in\nmany places, along the whole read, which reached as far as to\nFrance, hospitals for the reception of the pilgrims.\"\n\nv. 31.  Who.]  The Epistle of St. James is here attributed to the\nelder apostle of that name, whose shrine was at Compostella, in\nGalicia.  Which of the two was the author of it is yet doubtful.\nThe learned and candid Michaelis contends very forcibly for its\nhaving been written by James the Elder.  Lardner rejects that\nopinion as absurd; while Benson argues against it, but is well\nanswered by Michaelis, who after all, is obliged to leave the\nquestion undecided.  See his Introduction to the New Testament,\ntranslated by Dr. Marsh, ed.  Cambridge, 1793.  V. iv. c.  26.  -\n1, 2, 3.\n\nv. 35.  As Jesus.]  In the transfiguration on Mount Tabor.\n\nv. 39.  The second flame.]  St. James.\n\nv. 40.  I lifted up.]  \"I will lift up mine eyes unto the hills,\nfrom whence cometh my help.\"  Ps.  Cxxi.  1.\n\nv. 59.  From Egypt to Jerusalem.]  From the lower world to\nheaven.\n\nv. 67.  Hope.]  This is from the Sentences of Petrus Lombardus.\n\"Est autem spes virtus, qua spiritualia et aeterna bona speratam,\nid  est, beatitudinem aeternam.  Sine meritis enim aliquid\nsperare non spes, sed praesumptio, dici potest.\"  Pet. Lomb.\nSent.  1.  Iii.  Dist.  26.   Ed. Bas.  1486.  Fol.\n\nv. 74.  His anthem.]  Psalm ix.  10.\n\nv. 90.  Isaias ]  Chap. lxi. 10.\n\nv. 94.  Thy brother.]  St. John in the Revelation, c. vii.  9.\n\nv. 101.  Winter\'s month.]  \"If a luminary, like that which now\nappeared, were to shine throughout the month following the winter\nsolstice during which the constellation Cancer appears in the\neast at the setting of the sun, there would be no interruption to\nthe light, but the whole month would be as a single day.\"\n\nv. 112.  This.]  St. John, who reclined on the bosom of our\nSaviour, and to whose charge Jesus recommended his mother.\n\nv. 121.  So I.]  He looked so earnestly, to descry whether St.\nJohn were present there in body, or in spirit only, having had\nhis doubts raised  by that saying of our Saviour\'s:  \"If I will,\nthat he tarry till I come  what is that to thee.\"\n\nv. 127.  The two.]  Christ and Mary, whom he has described, in\nthe last Canto but one, as rising above his sight\n\nCANT");
    strcat(expected_filecontent, "O XXVI\n\nv. 2.  The beamy flame.]  St. John.\n\nv. 13.  Ananias\' hand.]  Who, by putting his hand on St. Paul,\nrestored his sight.  Acts, c. ix.  17.\n\nv. 36.  From him.]  Some suppose that Plato is here meant, who,\nin his Banquet, makes Phaedrus say:  \"Love is confessedly amongst\nthe eldest of beings, and, being the eldest, is the cause to us\nof the greatest goods \" Plat. Op. t. x. p. 177.  Bip.  ed. Others\nhave understood it of Aristotle, and others, of the writer who\ngoes by the name of Dionysius the Areopagite, referred to in the\ntwenty-eighth Canto.\n\nv. 40.  I will make.]  Exodus, c. xxxiii. 19.\n\nv. 42.  At the outset.]  John, c. i. 1.  &c.\n\nv. 51.  The eagle of our Lord.]  St. John\n\nv. 62.  The leaves.]  Created beings.\n\nv. 82.  The first living soul.]  Adam.\n\nv. 107.  Parhelion.]  Who enlightens and comprehends all things;\nbut is himself enlightened and comprehended by none.\n\nv. 117.  Whence.]  That is, from Limbo.  See Hell, Canto II.  53.\nAdam says that 5232 years elapsed from his creation to the time\nof his deliverance, which followed the death of Christ.\n\nv. 133.  EL]  Some read UN, \"One,\" instead of EL:  but the latter\nof these readings is confirmed by a passage from Dante\'s Treatise\nDe Vulg. Eloq. 1. i. cap. 4. \"Quod prius vox primi loquentis\nsonaverit, viro sanae mentis in promptu esse non dubito ipsum\nfuisse quod Deus est, videlicet El.\"  St. Isidore in the\nOrigines, 1.  vii. c. 1. had said, \"Primum apud Hebraeos Dei\nnomen El dicitur.\"\n\nv. 135.  Use.]  From Horace, Ars. Poet. 62.\n\nv. 138.  All my life.]  \"I remained in the terrestrial Paradise\nonly tothe seventh hour.\"  In the Historia Scolastica of Petrus\nComestor, it is said of our first parents:  Quidam tradunt eos\nfuisse in Paradiso septem horae.\"  I. 9. ed. Par. 1513. 4to.\n\nCANTO XXVII\n\nv.  1.  Four torches.]  St. Peter, St. James, St. John, and Adam.\n\nv. 11.  That.] ");

                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "HAPPEN.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 14150; ++i)
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
    

                char expected_filecontent[6914] = "";

                strcat(expected_filecontent, "st gives\nIts temper and impression.  Morning there,\nHere eve was by almost such passage made;\nAnd whiteness had o\'erspread that hemisphere,\nBlackness the other part; when to the left\nI saw Beatrice turn\'d, and on the sun\nGazing, as never eagle fix\'d his ken.\nAs from the first a second beam is wont\nTo issue, and reflected upwards rise,\nE\'en as a pilgrim bent on his return,\nSo of her act, that through the eyesight pass\'d\nInto my fancy, mine was form\'d; and straight,\nBeyond our mortal wont, I fix\'d mine eyes\nUpon the sun.  Much is allowed us there,\nThat here exceeds our pow\'r; thanks to the place\nMade for the dwelling of the human kind\n     I suffer\'d it not long, and yet so long\nThat I beheld it bick\'ring sparks around,\nAs iron that comes boiling from the fire.\nAnd suddenly upon the day appear\'d\nA day new-ris\'n, as he, who hath the power,\nHad with another sun bedeck\'d the sky.\n     Her eyes fast fix\'d on the eternal wheels,\nBeatrice stood unmov\'d; and I with ken\nFix\'d upon her, from upward gaze remov\'d\nAt her aspect, such inwardly became\nAs Glaucus, when he tasted of the herb,\nThat made him peer among the ocean gods;\nWords may not tell of that transhuman change:\nAnd therefore let the example serve, though weak,\nFor those whom grace hath better proof in store\n     If I were only what thou didst create,\nThen newly, Love!  by whom the heav\'n is rul\'d,\nThou know\'st, who by thy light didst bear me up.\nWhenas the wheel which thou dost ever guide,\nDesired Spirit!  with its harmony\nTemper\'d of thee and measur\'d, charm\'d mine ear,\nThen seem\'d to me so much of heav\'n to blaze\nWith the sun\'s flame, that rain or flood ne\'er made\nA lake so broad.  The newness of the sound,\nAnd that great light, inflam\'d me with desire,\nKeener than e\'er was felt, to know their cause.\n     Whence she who saw me, clearly as myself,\nTo calm my troubled mind, before I ask\'d,\nOpen\'d her lips, and gracious thus began:\n\"With false imagination thou thyself\nMak\'st dull, so that thou seest not the thing,\nWhich thou hadst seen, had that been shaken off.\nThou art not on the earth as thou believ\'st;\nFor light\'ning scap\'d from its own proper place\nNe\'er ran, as thou hast hither now return\'d.\"\n     Although divested of my first-rais\'d doubt,\nBy those brief words, accompanied with smiles,\nYet in new doubt was I entangled more,\nAnd said:  \"Already satisfied, I rest\nFrom admiration deep, but now admire\nHow I above those lighter bodies rise.\"\n     Whence, after utt\'rance of a piteous sigh,\nShe tow\'rds me bent her eyes, with such a look,\nAs on her frenzied child a mother casts;\nThen thus began:  \"Among themselves all things\nHave order; and from hence the form, which makes\nThe universe resemble God.  In this\nThe higher creatures see the printed steps\nOf that eternal worth, which is the end\nWhither the line is drawn.  All natures lean,\nIn this their order, diversely, some more,\nSome less approaching to their primal source.\nThus they to different havens are mov\'d on\nThrough the vast sea of being, and each one\nWith instinct giv\'n, that bears it in its course;\nThis to the lunar sphere directs the fire,\nThis prompts the hearts of mortal animals,\nThis the brute earth together knits, and binds.\nNor only creatures, void of intellect,\nAre aim\'d at by this bow; hut even those,\nThat have intelligence and love, are pierc\'d.\nThat Providence, who so well orders all,\nWith her own light makes ever calm the heaven,\nIn which the substance, that hath greatest speed,\nIs turn\'d: and thither now, as to our seat\nPredestin\'d, we are carried by the force\nOf that strong cord, that never looses dart,\nBut at fair aim and glad.  Yet is it true,\nThat as ofttimes but ill accords the form\nTo the design of art, through sluggishness\nOf unreplying matter, so this course\nIs sometimes quitted by the creature, who\nHath power, directed thus, to bend elsewhere;\nAs from a cloud the fire is seen to fall,\nFrom its original impulse warp\'d, to earth,\nBy vicious fondness.  Thou no more admire\nThy soaring, (if I rightly deem,) than lapse\nOf torrent downwards from a mountain\'s height.\nThere would in thee for wonder be m");
    strcat(expected_filecontent, "ore cause,\nIf, free of hind\'rance, thou hadst fix\'d thyself\nBelow, like fire unmoving on the earth.\"\n     So said, she turn\'d toward the heav\'n her face.\n\n\n\nCANTO II\n\nAll ye, who in small bark have following sail\'d,\nEager to listen, on the advent\'rous track\nOf my proud keel, that singing cuts its way,\nBackward return with speed, and your own shores\nRevisit, nor put out to open sea,\nWhere losing me, perchance ye may remain\nBewilder\'d in deep maze.  The way I pass\nNe\'er yet was run: Minerva breathes the gale,\nApollo guides me, and another Nine\nTo my rapt sight the arctic beams reveal.\nYe other few, who have outstretch\'d the neck.\nTimely for food of angels, on which here\nThey live, yet never know satiety,\nThrough the deep brine ye fearless may put out\nYour vessel, marking, well the furrow broad\nBefore you in the wave, that on both sides\nEqual returns.  Those, glorious, who pass\'d o\'er\nTo Colchos, wonder\'d not as ye will do,\nWhen they saw Jason following the plough.\n     The increate perpetual thirst, that draws\nToward the realm of God\'s own form, bore us\nSwift almost as the heaven ye behold.\n     Beatrice upward gaz\'d, and I on her,\nAnd in such space as on the notch a dart\nIs plac\'d, then loosen\'d flies, I saw myself\nArriv\'d, where wond\'rous thing engag\'d my sight.\nWhence she, to whom no work of mine was hid,\nTurning to me, with aspect glad as fair,\nBespake me: \"Gratefully direct thy mind\nTo God, through whom to this first star we come.\"\n     Me seem\'d as if a cloud had cover\'d us,\nTranslucent, solid, firm, and polish\'d bright,\nLike adamant, which the sun\'s beam had smit\nWithin itself the ever-during pearl\nReceiv\'d us, as the wave a ray of light\nReceives, and rests unbroken.  If I then\nWas of corporeal frame, and it transcend\nOur weaker thought, how one dimension thus\nAnother could endure, which needs must be\nIf body enter body, how much more\nMust the desire inflame us to behold\nThat essence, which discovers by what means\nGod and our nature join\'d!  There will be seen\nThat which we hold through faith, not shown by proof,\nBut in itself intelligibly plain,\nE\'en as the truth that man at first believes.\n     I answered:  \"Lady!  I with thoughts devout,\nSuch as I best can frame, give thanks to Him,\nWho hath remov\'d me from the mortal world.\nBut tell, I pray thee, whence the gloomy spots\nUpon this body, which below on earth\nGive rise to talk of Cain in fabling quaint?\"\n     She somewhat smil\'d, then spake:  \"If mortals err\nIn their opinion, when the key of sense\nUnlocks not, surely wonder\'s weapon keen\nOught not to pierce thee; since thou find\'st, the wings\nOf reason to pursue the senses\' flight\nAre short.  But what thy own thought is, declare.\"\n     Then I:  \"What various here above appears,\nIs caus\'d, I deem, by bodies dense or rare.\"\n     She then resum\'d:  \"Thou certainly ");

                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "SOUND.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 6913; ++i)
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
    

                char expected_filecontent[15016] = "";

                strcat(expected_filecontent, "ges, till he arrives in a beautiful valley\ncovered with flowers on all sides, and the richest in the world;\nbut which was continually  shifting its appearance from a round\nfigure to a square, from obscurity to light, and from\npopulousness to solitude.  This is the region of Pleasure, or\nCupid, who is accompanied by four ladies, Love, Hope, Fear, and\nDesire.  In one part of it he meets with Ovid, and is instructed\nby him how to conquer the passion of love, and to escape from\nthat place.  After his escape he makes his confession to a friar,\nand then returns to the forest of visions:  and ascending a\nmountain, he meets with Ptolemy, a venerable old man.  Here the\nnarrative breaks off. The  poem ends, as it began, with an\naddress to Rustico di Filippo, on whom he lavishes every sort of\npraise.\n\nIt has been observed, that Dante derived the idea of opening his\npoem by describing himself as lost in a wood, from the Tesoretto\nof his master.  I know not whether it has been remarked, that the\ncrime of usury is branded by both these poets as offensive to God\nand Nature:  or that the sin for which Brunetto is condemned by\nhis pupil, is mentioned in the Tesoretto with great horror.\nDante\'s twenty-fifth sonnet is a jocose one, addressed to\nBrunetto.  He died in 1295.\n\nv. 62.  Who in old times came down from Fesole.]  See G. Villani\nHist. l. iv. c. 5. and Macchiavelli Hist. of Flor. b. ii.\n\nv. 89.  With another text.]  He refers to the prediction of\nFarinata, in Canto X.\n\nv. 110.  Priscian.]  There is no reason to believe, as the\ncommentators observe that the grammarian of this name was stained\nwith the vice imputed to him; and we must therefore suppose that\nDante puts the individual for the species, and implies the\nfrequency of the crime among those who abused the opportunities\nwhich the education of youth afforded them, to so abominable a\npurpose.\n\nv. 111.  Francesco.]  Son of Accorso, a Florentine, celebrated\nfor his skill in jurisprudence, and commonly known by the name of\nAccursius.\n\nv. 113.  Him.]  Andrea de\' Mozzi, who, that his scandalous life\nmight be less exposed to observation, was translated either by\nNicholas III, or Boniface VIII from the see of Florence to that\nof Vicenza, through which passes the river Baccchiglione.  At the\nlatter of these places he died.\n\nv. 114.  The servants\' servant.]  Servo de\' servi.  So Ariosto,\nSat. 3.\n               Degli servi\n        Io sia il gran servo.\n\nv. 124.  I commend my Treasure to thee.]  Brunetto\'s great work,\nthe Tresor.\nSieti raccomandato \'l mio Tesoro.\nSo Giusto de\' Conti, in his Bella Mano, Son.  \"Occhi:\"\n        Siavi raccommandato il mio Tesoro.\n\nCANTO XVI\n\nv. 38.  Gualdrada.]  Gualdrada was the daughter of Bellincione\nBerti, of whom mention is made in the Paradise, Canto XV, and\nXVI.  He was of the family of Ravignani, a branch of the Adimari.\n\nThe Emperor Otho IV. being at a festival in Florence, where\nGualdrada was present, was struck with her beauty; and inquiring\nwho she was, was answered by Bellincione, that she was the\ndaughter of one who, if it was his Majesty\'s pleasure, would make\nher admit the honour of his salute.  On overhearing this, she\narose from her seat, and blushing, in an animated tone of voice,\ndesired her father that he would not be so liberal in his offers,\nfor that no man should ever be allowed that freedom, except him\nwho should be her lawful husband.  The Emperor was not less\ndelighted by her resolute modesty than he had before been by the\nloveliness of her person, and calling to him Guido, one of his\nbarons, gave her to him in marriage, at the same time raising him\n\nto the rank of a count, and bestowing on her the whole of\nCasentino, and a part of the territory of Romagna, as her\nportion.  Two sons were the offspring of this union, Guglielmo\nand Ruggieri, the latter of whom was father of Guidoguerra, a man\nof great military skill and prowess who, at the head of four\nhundred Florentines of the Guelph party, was signally\ninstrumental to the victory obtained at Benevento by Charles of\nAnjou, over Manfredi, King of Naples, in 1265.   One of the\nconsequ");
    strcat(expected_filecontent, "ences of this victory was the expulsion of the Ghibellini,\nand the re-establishment of the Guelfi at Florence.\n\nv. 39.  Many a noble act.]  Compare Tasso, G. L. c. i. st. 1.\n\nv. 42.  Aldobrandiu]  Tegghiaio Aldobrandi was of the noble\nfamily of Adimari, and much esteemed for his military talents.\nHe endeavored to dissuade the Florentines from the attack, which\nthey meditated against the Siennese, and the rejection of his\ncounsel occasioned the memorable defeat, which the former\nsustained at Montaperto, and the consequent banishment of the\nGuelfi from Florence.\n\nv. 45.  Rusticucci.]  Giacopo Rusticucci, a Florentine,\nremarkable for his opulence and the generosity of his spirit.\n\nv. 70.  Borsiere.]  Guglielmo Borsiere, another Florentine, whom\nBoccaccio, in a story which he relates of him, terms \"a man of\ncourteous and elegant manners, and of great readiness in\nconversation.\"  Dec. Giorn. i. Nov. 8.\n\nv. 84.  When thou with pleasure shalt retrace the past.]\n        Quando ti giovera dicere io fui.\nSo Tasso, G. L. c. xv. st. 38.\n        Quando mi giovera narrar altrui\n        Le novita vedute, e dire; io fui.\n\nv. 121.  Ever to that truth.]  This memorable apophthegm is\nrepeated by Luigi Pulci and Trissino.\n\n        Sempre a quel ver, ch\' ha faccia di menzogna\n        E piu senno tacer la lingua cheta\n        Che spesso senza colpa fa vergogna.\n               Morgante. Magg.  c. xxiv.\n\n               La verita, che par mensogna\n        Si dovrebbe tacer dall\' uom ch\'e saggio.\n               Italia. Lib. C. xvi.\n\nCANTO XVII\n\nv. 1.  The fell monster.]  Fraud.\n\nv. 53.  A pouch.]  A purse, whereon the armorial bearings of each\nwere emblazoned.  According to Landino, our poet implies that the\nusurer can pretend to no other honour, than such as he derives\nfrom his purse and his family.\n\nv. 57.  A yellow purse.]  The arms of the Gianfigliazzi of\nFlorence.\n\nv. 60.  Another.]  Those of the Ubbriachi, another Florentine\nfamily of high distinction.\n\nv. 62.  A fat and azure swine.]  The arms of the Scrovigni a\nnoble family of Padua.\n\nv. 66.  Vitaliano.]  Vitaliano del Dente, a Paduan.\n\nv. 69.  That noble knight.]  Giovanni Bujamonti, a Florentine\nusurer, the most infamous of his time.\n\nCANTO XVIII\n\nv. 28.  With us beyond.]  Beyond the middle point they tended the\nsame way with us, but their pace was quicker than ours.\n\nv. 29.  E\'en thus the Romans.]  In the year 1300, Pope Boniface\nVIII., to remedy the inconvenience occasioned by the press of\npeople who were passing over the bridge of St. Angelo during the\ntime of the Jubilee, caused it to be divided length wise by a\npartition, and ordered, that all those who were going to St.\nPeter\'s should keep one side, and those returning the other.\n\nv. 50.  Venedico.]  Venedico Caccianimico, a Bolognese, who\nprevailed on his sister Ghisola to prostitute herself to Obizzo\nda  Este, Marquis of Ferrara, whom we have seen among the\ntyrants, Canto XII.\n\nv. 62.  To answer Sipa.]  He denotes Bologna by its situation\nbetween the rivers Savena to the east, and Reno to the west of\nthat city; and by a peculiarity of dialect, the use of the\naffirmative sipa instead of si.\n\nv. 90.  Hypsipyle.]  See Appolonius Rhodius, l. i. and Valerius\nFlaccus l.ii.  Hypsipyle deceived the other women by concealing\nher father Thoas, when they had agreed to put all their males to\ndeath.\n\nv. 120.  Alessio.]  Alessio, of an ancient and considerable\nfamily in Lucca, called the Interminei.\n\nv. 130.  Thais.]  He alludes to that passage in the Eunuchus of\nTerence where Thraso asks if Thais was obliged to him for the\npresent he had sent her, and Gnatho replies, that she had\nexpressed her obligation in the most forcible terms.\n        T.  Magnas vero agere gratias Thais mihi?\n        G.  Ingentes.\n               Eun. a. iii. s. i.\n\nCANTO XIX\n\nv. 18.  Saint John\'s fair dome.]  The apertures in the  rock were\nof the same dimensions as the fonts of St. John the Baptist at\nFlorence, one of which, Dante says he had broken, to rescue a\nchild  that was playing near and fell in. He intimates that the\nmotive of his  breaking the font had been m");
    strcat(expected_filecontent, "aliciously represented\nby his enemies.\n\nv. 55.  O Boniface!]  The spirit mistakes Dante for  Boniface\nVIII. who was then alive, and who he did not expect would have\narrived so soon, in consequence, as it should seem, of a\nprophecy, which  predicted the death of that Pope at a later\nperiod. Boniface died in  1303.\n\nv. 58.  In guile.]  \"Thou didst presume to arrive by fraudulent\nmeans at the papal power, and afterwards to abuse it.\"\n\nv. 71.  In the mighty mantle I was rob\'d.]  Nicholas III, of the\nOrsini family, whom the poet therefore calls \"figliuol dell\'\norsa,\" \"son of the she-bear.\"  He died in 1281.\n\nv. 86.  From forth the west, a shepherd without law.]   Bertrand\nde Got Archbishop of Bordeaux, who succeeded to the pontificate\nin 1305, and assumed the title of Clement V. He transferred the\nholy  see to Avignon in 1308 (where it remained till 1376), and\ndied in 1314.\n\nv. 88.  A new Jason.]  See Maccabees, b. ii. c. iv. 7,8.\n\nv. 97.  Nor Peter.]  Acts of the Apostles, c.i. 26.\n\nv. 100.  The condemned soul.]  Judas.\n\nv. 103.  Against Charles.]  Nicholas III. was enraged against\nCharles I, King of Sicily, because he rejected with scorn a\nproposition made by that Pope for an alliance between their\nfamilies.  See G. Villani, Hist. l. vii. c. liv.\n\nv. 109.  Th\' Evangelist.]  Rev. c. xvii. 1, 2, 3.  Compare\nPetrarch.  Opera fol. ed. Basil. 1551. Epist. sine titulo liber.\nep. xvi. p. 729.\n\nv. 118.  Ah, Constantine.]  He alludes to the pretended gift of\nthe Lateran by Constantine to Silvester, of which Dante himself\nseems to imply a doubt, in his treatise \"De Monarchia.\" - \"Ergo\nscindere Imperium, Imperatori non licet.  Si ergo aliquae,\ndignitates per Constantinum essent alienatae, (ut dicunt) ab\nImperio,\" &c. l. iii.\nThe gift is by Ariosto very humorously placed in the moon, among\nthe things lost or abused on earth.\n        Di varj fiori, &c.\n               O. F. c. xxxiv. st. 80.\n\nMilton has translated both this passage and that in the text.\nProse works, vol. i. p. 11. ed. 1753.\n\nCANTO XX\n\nv. 11.  Revers\'d.]  Compare Spenser, F. Q. b. i. c. viii.  st. 31\n\nv. 30.  Before whose eyes.]  Amphiaraus, one of the seven kings\nwho besieged Thebes.  He is said to have been swallowed up by  an\nopening of the earth.  See Lidgate\'s Storie of Thebes, Part III\nwhere it is told how the \"Bishop Amphiaraus\" fell down to hell.\n        And thus the devill for his outrages,\n        Like his desert payed him his wages.\nA different reason for his being doomed thus to perish is\nassigned by Pindar.\n[GREEK HERE]\n               Nem ix.\n\n        For thee, Amphiaraus, earth,\n        By Jove\'s all-riving thunder cleft\n        Her mighty bosom open\'d wide,\n        Thee and thy plunging steeds to hide,\n        Or ever on thy back the spear\n        Of Periclymenus impress\'d\n        A wound to shame thy warlike breast\n        For struck with panic fear\n        The gods\' own children flee.\n\nv. 37.  Tiresias.]\n        Duo magnorum viridi coeuntia sylva\n        Corpora serpentum baculi violaverat ictu, &c.\n               Ovid. Met. iii.\n\nv. 43.  Aruns.]  Aruns is said to have dwelt in the  mountains of\nLuni (from whence that territory is still called Lunigiana),\nabove Carrara, celebrated for its marble.  Lucan. Phars. l. i.\n575.  So Boccaccio in the Fiammetta, l. iii.  \"Quale Arunte,\" &c.\n\n\"Like Aruns, who amidst the white marbles of Luni, contemplated\nthe celestial bodies and their motions.\"\n\nv. 50.  Manto.]  The daughter of Tiresias of Thebes, a city\ndedicated to Bacchus.  From Manto Mantua, the country of Virgil\nderives its name. The Poet proceeds to describe the situation of\nthat place.\n\nv. 61.  Between the vale.]  The lake Benacus, now called  the\nLago di Garda, though here said to lie between Garda, Val\nCamonica, and the Apennine, is, however, very distant from the\nlatter two\n\nv. 63.  There is a spot.]  Prato di Fame, where the dioceses of\nTrento, Verona, and Brescia met.\n\nv. 69.  Peschiera.]  A garrison situated to the south of the\nlake, where it empties itself and forms the Mincius.\n\nv. 94.  Casalodi\'s madness.]  Alberto da Casalodi, who had got\npossess");
    strcat(expected_filecontent, "ion of Mantua, was persuaded by Pinamonte Buonacossi, that\nhe might ingratiate himself with the people by banishing to their\n\nown castles the nobles, who were obnoxious to them.  No sooner\nwas this done, than Pinamonte put himself at the head of the\npopulace, drove out Casalodi and his adherents, and obtained the\nsovereignty for himself.\n\nv. 111.  So sings my tragic strain.]\n        Suspensi Eurypilum scitatum oracula Phoebi\n        Mittimus.\n               Virg. Aeneid. ii. 14.\n\nv. 115.  Michael Scot.]  Sir Michael Scott, of Balwearie,\nastrologer to the Emperor Frederick II. lived in the thirteenth\ncentury.  For further particulars relating to this singular man,\nsee Warton\'s History of English Poetry, vol. i. diss. ii. and\nsect. ix.  p 292, and the Notes to Mr. Scott\'s \"Lay of the Last\nMinstrel,\" a  poem in which a happy use is made of the traditions\nthat are still current in North Britain concerning him.  He is\nmentioned by G. Villani. Hist. l. x. c. cv. and cxli. and l. xii.\nc. xviii. and by Boccaccio, Dec. Giorn. viii. Nov. 9.\n\nv. 116.  Guido Bonatti.]  An astrologer of Forli, on whose  skill\nGuido da Montefeltro, lord of that place, so much relied, that he\nis reported never to have gone into battle, except in the hour\nrecommended to him as fortunate by Bonatti.\n\nLandino and Vellutello, speak of a book, which he composed on the\nsubject of his art.\n\nv. 116.  Asdente.]  A shoemaker at Parma, who deserted his\nbusiness to practice the arts of divination.\n\nv. 123.  Cain with fork of thorns.]  By Cain and the thorns, or\nwhat is still vulgarly called the Man in the Moon, the Poet\ndenotes that luminary.  The same superstition is alluded to in\nthe Paradise, Canto II. 52.  The curious reader may consult Brand\non Popular Antiquities, 4to.  1813. vol. ii. p. 476.\n\nCANTO XXI\n\nv. 7.  In the Venetians\' arsenal.]  Compare Ruccellai, Le  Api,\n165, and Dryden\'s Annus Mirabilis, st. 146, &c.\n\nv. 37.  One of Santa Zita\'s elders.]  The elders or chief\nmagistrates of Lucca, where Santa Zita was held in especial\nveneration.  The name of this sinner is supposed to have been\nMartino Botaio.\n\nv. 40.  Except Bonturo, barterers.]  This is said ironically of\nBonturo de\' Dati.  By barterers are meant peculators, of every\ndescription; all who traffic the interests of the public  for\ntheir own private advantage.\n\nv. 48.  Is other swimming than in Serchio\'s wave.]\n        Qui si nuota altrimenti che nel Serchio.\nSerchio is the river that flows by Lucca.  So Pulci, Morg. Mag.\nc. xxiv.\n        Qui si nuota nel sangue, e non nel Serchio.\n\nv. 92.  From Caprona.]  The surrender of the castle of Caprona to\nthe combined forces of Florence and Lucca, on condition that the\ngarrison should march out in safety, to which ");

                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "MANY");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 15015; ++i)
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
    

                char expected_filecontent[394] = "";

                strcat(expected_filecontent, " came; nor was it ever known whence\nhe was or wither he went.\" G. Villani, 1.  vi.  c. 92.\n\nv. 135.  Four daughters.]  Of the four daughters of Raymond\nBerenger, Margaret, the eldest, was married to Louis IX of\nFrance; Eleanor; the next, to Henry III, of England; Sancha, the\nthird, to Richard, Henry\'s brother, and King of the Romans; and\nthe youngest, Beatrice, to Charles I, King of Naples ");

                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "DIVIDETE.BIN");
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
    
            char *filecontent = (char *)calloc(14336, 1);
            char expected_filecontent[14337] = "";

            strcat(expected_filecontent, "y leader\'s feet still equaling pace\nFrom forth that cloud I came, when now expir\'d\nThe parting beams from off the nether shores.\n     O quick and forgetive power!  that sometimes dost\nSo rob us of ourselves, we take no mark\nThough round about us thousand trumpets clang!\nWhat moves thee, if the senses stir not?  Light\nKindled in heav\'n, spontaneous, self-inform\'d,\nOr likelier gliding down with swift illapse\nBy will divine.  Portray\'d before me came\nThe traces of her dire impiety,\nWhose form was chang\'d into the bird, that most\nDelights itself in song: and here my mind\nWas inwardly so wrapt, it gave no place\nTo aught that ask\'d admittance from without.\n     Next shower\'d into my fantasy a shape\nAs of one crucified, whose visage spake\nFell rancour, malice deep, wherein he died;\nAnd round him Ahasuerus the great king,\nEsther his bride, and Mordecai the just,\nBlameless in word and deed.  As of itself\nThat unsubstantial coinage of the brain\nBurst, like a bubble, Which the water fails\nThat fed it; in my vision straight uprose\nA damsel weeping loud, and cried, \"O queen!\nO mother!  wherefore has intemperate ire\nDriv\'n thee to loath thy being?  Not to lose\nLavinia, desp\'rate thou hast slain thyself.\nNow hast thou lost me.  I am she, whose tears\nMourn, ere I fall, a mother\'s timeless end.\"\n     E\'en as a sleep breaks off, if suddenly\nNew radiance strike upon the closed lids,\nThe broken slumber quivering ere it dies;\nThus from before me sunk that imagery\nVanishing, soon as on my face there struck\nThe light, outshining far our earthly beam.\nAs round I turn\'d me to survey what place\nI had arriv\'d at, \"Here ye mount,\" exclaim\'d\nA voice, that other purpose left me none,\nSave will so eager to behold who spake,\nI could not choose but gaze.  As \'fore the sun,\nThat weighs our vision down, and veils his form\nIn light transcendent, thus my virtue fail\'d\nUnequal.  \"This is Spirit from above,\nWho marshals us our upward way, unsought;\nAnd in his own light shrouds him;. As a man\nDoth for himself, so now is done for us.\nFor whoso waits imploring, yet sees need\nOf his prompt aidance, sets himself prepar\'d\nFor blunt denial, ere the suit be made.\nRefuse we not to lend a ready foot\nAt such inviting: haste we to ascend,\nBefore it darken: for we may not then,\nTill morn again return.\"  So spake my guide;\nAnd to one ladder both address\'d our steps;\nAnd the first stair approaching, I perceiv\'d\nNear me as \'twere the waving of a wing,\nThat fann\'d my face and whisper\'d: \"Blessed they\nThe peacemakers: they know not evil wrath.\"\n     Now to such height above our heads were rais\'d\nThe last beams, follow\'d close by hooded night,\nThat many a star on all sides through the gloom\nShone out.  \"Why partest from me, O my strength?\"\nSo with myself I commun\'d; for I felt\nMy o\'ertoil\'d sinews slacken.  We had reach\'d\nThe summit, and were fix\'d like to a bark\nArriv\'d at land.  And waiting a short space,\nIf aught should meet mine ear in that new round,\nThen to my guide I turn\'d, and said: \"Lov\'d sire!\nDeclare what guilt is on this circle purg\'d.\nIf our feet rest, no need thy speech should pause.\"\n     He thus to me:  \"The love of good, whate\'er\nWanted of just proportion, here fulfils.\nHere plies afresh the oar, that loiter\'d ill.\nBut that thou mayst yet clearlier understand,\nGive ear unto my words, and thou shalt cull\nSome fruit may please thee well, from this delay.\n     \"Creator, nor created being, ne\'er,\nMy son,\" he thus began, \"was without love,\nOr natural, or the free spirit\'s growth.\nThou hast not that to learn.  The natural still\nIs without error; but the other swerves,\nIf on ill object bent, or through excess\nOf vigour, or defect.  While e\'er it seeks\nThe primal blessings, or with measure due\nTh\' inferior, no delight, that flows from it,\nPartakes of ill.  But let it warp to evil,\nOr with more ardour than behooves, or less.\nPursue the good, the thing created then\nWorks \'gainst its Maker.  Hence thou must infer\nThat love is germin of each virtue in ye,\nAnd of each act no less, that merits pain.\nNow since it may not be, but love intend\nThe welfare mainly of the thing i");
    strcat(expected_filecontent, "t loves,\nAll from self-hatred are secure; and since\nNo being can be thought t\' exist apart\nAnd independent of the first, a bar\nOf equal force restrains from hating that.\n     \"Grant the distinction just; and it remains\nThe\' evil must be another\'s, which is lov\'d.\nThree ways such love is gender\'d in your clay.\nThere is who hopes (his neighbour\'s worth deprest,)\nPreeminence himself, and coverts hence\nFor his own greatness that another fall.\nThere is who so much fears the loss of power,\nFame, favour, glory (should his fellow mount\nAbove him), and so sickens at the thought,\nHe loves their opposite: and there is he,\nWhom wrong or insult seems to gall and shame\nThat he doth thirst for vengeance, and such needs\nMust doat on other\'s evil.  Here beneath\nThis threefold love is mourn\'d.  Of th\' other sort\nBe now instructed, that which follows good\nBut with disorder\'d and irregular course.\n     \"All indistinctly apprehend a bliss\nOn which the soul may rest, the hearts of all\nYearn after it, and to that wished bourn\nAll therefore strive to tend.  If ye behold\nOr seek it with a love remiss and lax,\nThis cornice after just repenting lays\nIts penal torment on ye.  Other good\nThere is, where man finds not his happiness:\nIt is not true fruition, not that blest\nEssence, of every good the branch and root.\nThe love too lavishly bestow\'d on this,\nAlong three circles over us, is mourn\'d.\nAccount of that division tripartite\nExpect not, fitter for thine own research.\n\n\n\nCANTO XVIII\n\nThe teacher ended, and his high discourse\nConcluding, earnest in my looks inquir\'d\nIf I appear\'d content; and I, whom still\nUnsated thirst to hear him urg\'d, was mute,\nMute outwardly, yet inwardly I said:\n\"Perchance my too much questioning offends\nBut he, true father, mark\'d the secret wish\nBy diffidence restrain\'d, and speaking, gave\nMe boldness thus to speak: \"Master, my Sight\nGathers so lively virtue from thy beams,\nThat all, thy words convey, distinct is seen.\nWherefore I pray thee, father, whom this heart\nHolds dearest!  thou wouldst deign by proof t\' unfold\nThat love, from which as from their source thou bring\'st\nAll good deeds and their opposite.\"  He then:\n\"To what I now disclose be thy clear ken\nDirected, and thou plainly shalt behold\nHow much those blind have err\'d, who make themselves\nThe guides of men.  The soul, created apt\nTo love, moves versatile which way soe\'er\nAught pleasing prompts her, soon as she is wak\'d\nBy pleasure into act.  Of substance true\nYour apprehension forms its counterfeit,\nAnd in you the ideal shape presenting\nAttracts the soul\'s regard.  If she, thus drawn,\nincline toward it, love is that inclining,\nAnd a new nature knit by pleasure in ye.\nThen as the fire points up, and mounting seeks\nHis birth-place and his lasting seat, e\'en thus\nEnters the captive soul into desire,\nWhich is a spiritual motion, that ne\'er rests\nBefore enjoyment of the thing it loves.\nEnough to show thee, how the truth from those\nIs hidden, who aver all love a thing\nPraise-worthy in itself: although perhaps\nIts substance seem still good.  Yet if the wax\nBe good, it follows not th\' impression must.\"\n\"What love is,\" I return\'d, \"thy words, O guide!\nAnd my own docile mind, reveal.  Yet thence\nNew doubts have sprung.  For from without if love\nBe offer\'d to us, and the spirit knows\nNo other footing, tend she right or wrong,\nIs no desert of hers.\"  He answering thus:\n\"What reason here discovers I have power\nTo show thee: that which lies beyond, expect\nFrom Beatrice, faith not reason\'s task.\nSpirit, substantial form, with matter join\'d\nNot in confusion mix\'d, hath in itself\nSpecific virtue of that union born,\nWhich is not felt except it work, nor prov\'d\nBut through effect, as vegetable life\nBy the green leaf.  From whence his intellect\nDeduced its primal notices of things,\nMan therefore knows not, or his appetites\nTheir first affections; such in you, as zeal\nIn bees to gather honey; at the first,\nVolition, meriting nor blame nor praise.\nBut o\'er each lower faculty supreme,\nThat as she list are summon\'d to her bar,\nYe have that virtue in you, whose just voice\nUttereth co");
    strcat(expected_filecontent, "unsel, and whose word should keep\nThe threshold of assent.  Here is the source,\nWhence cause of merit in you is deriv\'d,\nE\'en as the affections good or ill she takes,\nOr severs, winnow\'d as the chaff.  Those men\nWho reas\'ning went to depth profoundest, mark\'d\nThat innate freedom, and were thence induc\'d\nTo leave their moral teaching to the world.\nGrant then, that from necessity arise\nAll love that glows within you; to dismiss\nOr harbour it, the pow\'r is in yourselves.\nRemember, Beatrice, in her style,\nDenominates free choice by eminence\nThe noble virtue, if in talk with thee\nShe touch upon that theme.\"  The moon, well nigh\nTo midnight hour belated, made the stars\nAppear to wink and fade; and her broad disk\nSeem\'d like a crag on fire, as up the vault\nThat course she journey\'d, which the sun then warms,\nWhen they of Rome behold him at his set.\nBetwixt Sardinia and the Corsic isle.\nAnd now the weight, that hung upon my thought,\nWas lighten\'d by the aid of that clear spirit,\nWho raiseth Andes above Mantua\'s name.\nI therefore, when my questions had obtain\'d\nSolution plain and ample, stood as one\nMusing in dreary slumber; but not long\nSlumber\'d; for suddenly a multitude,\nThe steep already turning, from behind,\nRush\'d on.  With fury and like random rout,\nAs echoing on their shores at midnight heard\nIsmenus and Asopus, for his Thebes\nIf Bacchus\' help were needed; so came these\nTumultuous, curving each his rapid step,\nBy eagerness impell\'d of holy love.\n     Soon they o\'ertook us; with such swiftness mov\'d\nThe mighty crowd.  Two spirits at their head\nCried weeping; \"Blessed Mary sought with haste\nThe hilly region.  Caesar to subdue\nIlerda, darted in Marseilles his sting,\nAnd flew to Spain.\"--\"Oh tarry not: away;\"\nThe others shouted; \"let not time be lost\nThrough slackness of affection.  Hearty zeal\nTo serve reanimates celestial grace.\"\n     \"O ye, in whom intenser fervency\nHaply supplies, where lukewarm erst ye fail\'d,\nSlow or neglectful, to absolve your part\nOf good and virtuous, this man, who yet lives,\n(Credit my tale, though strange) desires t\' ascend,\nSo morning rise to light us.  Therefore say\nWhich hand leads nearest to the rifted rock?\"\n     So spake my guide, to whom a shade return\'d:\n\"Come after us, and thou shalt find the cleft.\nWe may not linger: such resistless will\nSpeeds our unwearied course.  Vouchsafe us then\nThy pardon, if our duty seem to thee\nDiscourteous rudeness.  In Verona I\nWas abbot of San Zeno, when the hand\nOf Barbarossa grasp\'d Imperial sway,\nThat name, ne\'er utter\'d without tears in Milan.\nAnd there is he, hath one foot in his grave,\nWho for that monastery ere long shall weep,\nRuing his power misus\'d: for that his son,\nOf body ill compact, and worse in mind,\nAnd born in evil, he hath set in place\nOf its true pastor.\"  Whether more he spake,\nOr here was mute, I know not: he had sped\nE\'en now so far beyond us.  Yet thus much\nI heard, and in rememb\'rance treasur\'d it.\n     He then, who never fail\'d me at my need,\nCried, \"Hither turn.  Lo!  two with sharp remorse\nChiding their sin!\"  In rear of all the troop\nThese shouted:  \"First they died, to whom the sea\nOpen\'d, or ever Jordan saw his heirs:\nAnd they, who with Aeneas to the end\nEndur\'d not suffering, for their portion chose\nLife without glory.\"  Soon as they had fled\nPast reach of sight, new thought within me rose\nBy others follow\'d fast, and each unlike\nIts fellow: till led on from thought to thought,\nAnd pleasur\'d with the fleeting train, mine eye\nWas clos\'d, and meditation chang\'d to dream.\n\n\nCANTO XIX\n\nIt was the hour, when of diurnal heat\nNo reliques chafe the cold beams of the moon,\nO\'erpower\'d by earth, or planetary sway\nOf Saturn; and the geomancer sees\nHis Greater Fortune up the east ascend,\nWhere gray dawn checkers first the shadowy cone;\nWhen \'fore me in my dream a woman\'s shape\nThere came, with lips that stammer\'d, eyes aslant,\nDistorted feet, hands maim\'d, and colour pale.\n     I look\'d upon her; and as sunshine cheers\nLimbs numb\'d by nightly cold, e\'en thus my look\nUnloos\'d her tongue, next in brief space her form\nDecrepit rais\'d erect, ");
    strcat(expected_filecontent, "and faded face\nWith love\'s own hue illum\'d. Recov\'ring speech\nShe forthwith warbling such a strain began,\nThat I, how loth soe\'er, could scarce have held\nAttention from the song.  \"I,\" thus she sang,\n\"I am the Siren, she, whom mariners\nOn the wide sea are wilder\'d when they hear:\nSuch fulness of delight the list\'ner feels.\nI from his course Ulysses by my lay\nEnchanted drew.  Whoe\'er frequents me once\nParts seldom; so I charm him, and his heart\nContented knows no void.\"  Or ere her mouth\nWas clos\'d, to shame her at her side appear\'d\nA dame of semblance holy.  With stern voice\nShe utter\'d; \"Say, O Virgil, who is this?\"\nWhich hearing, he approach\'d, with eyes still bent\nToward that goodly presence: th\' other seiz\'d her,\nAnd, her robes tearing, open\'d her before,\nAnd show\'d the belly to me, whence a smell,\nExhaling loathsome, wak\'d me.  Round I turn\'d\nMine eyes, and thus the teacher:  \"At the least\nThree times my voice hath call\'d thee.  Rise, begone.\nLet us the opening find where thou mayst pass.\"\n     I straightway rose.  Now day, pour\'d down from high,\nFill\'d all the circuits of the sacred mount;\nAnd, as we journey\'d, on our shoulder smote\nThe early ray.  I follow\'d, stooping low\nMy forehead, as a man, o\'ercharg\'d with thought,\nWho bends him to the likeness of an arch,\nThat midway spans the flood; when thus I heard,\n\"Come, enter here,\" in tone so soft and mild,\nAs never met the ear on mortal strand.\n     With swan-like wings dispread and pointing up,\nWho thus had spoken marshal\'d us along,\nWhere each side of the solid masonry\nThe sloping, walls retir\'d; then mov\'d his plumes,\nAnd fanning us, affirm\'d that those, who mourn,\nAre blessed, for that comfort shall be theirs.\n     \"What aileth thee, that still thou look\'st to earth?\"\nBegan my leader; while th\' angelic shape\nA little over us his station took.\n     \"New vision,\" I replied, \"hath rais\'d in me\n8urmisings strange and anxious doubts, whereon\nMy soul intent allows no other thought\nOr room or entrance.--\"Hast thou seen,\" said he,\n\"That old enchantress, her, whose w");

            struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "SOME.TX");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int i;
            for (i = 0; i < 1024; ++i)
            {
                int res = file_read(filecontent + 14 * i, 14, 1, file);
                test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            }

            int res = file_read(filecontent + 14 * i, 14, 1, file);
            test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 14336);

            // jeśli jest, to raportuj błąd
            test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

            onerror_compare_memory(expected_filecontent, filecontent, 14336);

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
    

            char *filecontent0 = (char *)calloc(620, 1);
    char *filecontent1 = (char *)calloc(14273, 1);
    char *filecontent2 = (char *)calloc(14336, 1);
    char *filecontent3 = (char *)calloc(14150, 1);
    char *filecontent4 = (char *)calloc(6913, 1);
    char *filecontent5 = (char *)calloc(15015, 1);
    char *filecontent6 = (char *)calloc(393, 1);

            char expected_filecontent0[621] = "";
    char expected_filecontent1[14274] = "";
    char expected_filecontent2[14337] = "";
    char expected_filecontent3[14151] = "";
    char expected_filecontent4[6914] = "";
    char expected_filecontent5[15016] = "";
    char expected_filecontent6[394] = "";

            strcat(expected_filecontent0, "pass\'d me speechless by; and doing so\nHath made me more compassionate his fate.\"\n     So we discours\'d to where the rock first show\'d\nThe other valley, had more light been there,\nE\'en to the lowest depth.  Soon as we came\nO\'er the last cloister in the dismal rounds\nOf Malebolge, and the brotherhood\nWere to our view expos\'d, then many a dart\nOf sore lament assail\'d me, headed all\nWith points of thrilling pity, that I clos\'d\nBoth ears against the volley with mine hands.\n     As were the torment, if each lazar-house\nOf Valdichiana, in the sultry time\n\'Twixt July and September, with the isle\nSardinia and Maremma\'s pe");strcat(expected_filecontent1, "t.  Sails never such I saw\nOutstretch\'d on the wide sea.  No plumes had they,\nBut were in texture like a bat, and these\nHe flapp\'d i\' th\' air, that from him issued still\nThree winds, wherewith Cocytus to its depth\nWas frozen.  At six eyes he wept:  the tears\nAdown three chins distill\'d with bloody foam.\nAt every mouth his teeth a sinner champ\'d\nBruis\'d as with pond\'rous engine, so that three\nWere in this guise tormented.  But far more\nThan from that gnawing, was the foremost pang\'d\nBy the fierce rending, whence ofttimes the back\nWas stript of all its skin.  \"That upper spirit,\nWho hath worse punishment,\" so spake my guide,\n\"Is Judas, he that hath his head within\nAnd plies the feet without.  Of th\' other two,\nWhose heads are under, from the murky jaw\nWho hangs, is Brutus:  lo!  how he doth writhe\nAnd speaks not!  Th\' other Cassius, that appears\nSo large of limb.  But night now re-ascends,\nAnd it is time for parting.  All is seen.\"\n     I clipp\'d him round the neck, for so he bade;\nAnd noting time and place, he, when the wings\nEnough were op\'d, caught fast the shaggy sides,\nAnd down from pile to pile descending stepp\'d\nBetween the thick fell and the jagged ice.\n     Soon as he reach\'d the point, whereat the thigh\nUpon the swelling of the haunches turns,\nMy leader there with pain and struggling hard\nTurn\'d round his head, where his feet stood before,\nAnd grappled at the fell, as one who mounts,\nThat into hell methought we turn\'d again.\n     \"Expect that by such stairs as these,\" thus spake\nThe teacher, panting like a man forespent,\n\"We must depart from evil so extreme.\"\nThen at a rocky opening issued forth,\nAnd plac\'d me on a brink to sit, next join\'d\nWith wary step my side.  I rais\'d mine eyes,\nBelieving that I Lucifer should see\nWhere he was lately left, but saw him now\nWith legs held upward.  Let the grosser sort,\nWho see not what the point was I had pass\'d,\nBethink them if sore toil oppress\'d me then.\n     \"Arise,\" my master cried, \"upon thy feet.\n\"The way is long, and much uncouth the road;\nAnd now within one hour and half of noon\nThe sun returns.\"  It was no palace-hall\nLofty and luminous wherein we stood,\nBut natural dungeon where ill footing was\nAnd scant supply of light.  \"Ere from th\' abyss\nI sep\'rate,\" thus when risen I began,\n\"My guide!  vouchsafe few words to set me free\nFrom error\'s thralldom.  Where is now the ice?\nHow standeth he in posture thus revers\'d?\nAnd how from eve to morn in space so brief\nHath the sun made his transit?\"  He in few\nThus answering spake:  \"Thou deemest thou art still\nOn th\' other side the centre, where I grasp\'d\nTh\' abhorred worm, that boreth through the world.\nThou wast on th\' other side, so long as I\nDescended; when I turn\'d, thou didst o\'erpass\nThat point, to which from ev\'ry part is dragg\'d\nAll heavy substance.  Thou art now arriv\'d\nUnder the hemisphere opposed to that,\nWhich the great continent doth overspread,\nAnd underneath whose canopy expir\'d\nThe Man, that was born sinless, and so liv\'d.\nThy feet are planted on the smallest sphere,\nWhose other aspect is Judecca.  Morn\nHere rises, when there evening sets:  and he,\nWhose shaggy pile was scal\'d, yet standeth fix\'d,\nAs at the first.  On this part he fell down\nFrom heav\'n; and th\' earth, here prominent before,\nThrough fear of him did veil her with the sea,\nAnd to our hemisphere retir\'d.  Perchance\nTo shun him was the vacant space left here\nBy what of firm land on this side appears,\nThat sprang aloof.\"  There is a place beneath,\nFrom Belzebub as distant, as extends\nThe vaulted tomb, discover\'d not by sight,\nBut by the sound of brooklet, that descends\nThis way along the hollow of a rock,\nWhich, as it winds with no precipitous course,\nThe wave hath eaten.  By that hidden way\nMy guide and I did enter, to return\nTo the fair world:  and heedless of repose\nWe climbed, he first, I following his steps,\nTill on our view the beautiful lights of heav\'n\nDawn, through a circular opening in the cave:\nThus issuing we again beheld the stars.\n\n\n\nNOTES TO HELL\n\nCANTO I\n\nVerse 1.  In the midway.]  That the era of the Poem is intended\nby these words ");
    strcat(expected_filecontent1, "to be fixed to the thirty fifth year of the poet\'s\nage, A.D. 1300, will appear more plainly in Canto XXI. where that\ndate is explicitly marked.\n\nv. 16.  That planet\'s beam.]  The sun.\n\nv. 29.  The hinder foot.]  It is to be remembered, that in\nascending a hill the weight of the body rests on the hinder foot.\n\nv. 30.  A panther.]  Pleasure or luxury.\n\nv. 36.  With those stars.]  The sun was in Aries, in which sign\nhe supposes it to have begun its course at the creation.\n\nv. 43.  A lion.]  Pride or ambition.\n\nv. 45.  A she wolf.]  Avarice.\n\nv. 56.  Where the sun in silence rests.]  Hence Milton appears to\nhave taken his idea in the Samson Agonistes:\n\n        The sun to me is dark\n               And silent as the moon, &c\nThe same metaphor will recur, Canto V. v. 29.\n        Into a place I came\n       Where light was silent all.\n\nv. 65.  When the power of Julius.] This is explained by the\ncommentators to mean \"Although it was rather late with respect to\nmy birth before Julius Caesar assumed the supreme authority, and\nmade himself perpetual dictator.\"\n\nv. 98.  That greyhound.]  This passage is intended as an eulogium\non the liberal spirit of his Veronese patron Can Grande della\nScala.\n\nv. 102.  \'Twizt either Feltro.]  Verona, the country of Can della\nScala, is situated between Feltro, a city in the Marca\nTrivigiana, and Monte Feltro, a city in the territory of Urbino.\n\nv. 103.  Italia\'s plains.]  \"Umile Italia,\" from Virgil, Aen lib.\niii. 522.\n        Humilemque videmus\n       Italiam.\n\nv. 115.  Content in fire.]  The spirits in Purgatory.\n\nv. 118.  A spirit worthier.]  Beatrice, who conducts the Poet\nthrough Paradise.\n\nv. 130.  Saint Peter\'s gate.]  The gate of Purgatory, which the\nPoet feigns to be guarded by an angel placed on that station by\nSt. Peter.\n\nCANTO II\n\nv. 1.  Now was the day.]  A compendium of Virgil\'s description\nAen. lib. iv 522.  Nox erat, &c. Compare Apollonius Rhodius, lib\niii. 744, and lib. iv. 1058\n\nv. 8.  O mind.]\n        O thought that write all that I met,\n        And in the tresorie it set\n        Of my braine, now shall men see\n        If any virtue in thee be.\n               Chaucer.  Temple of Fame, b. ii. v.18\n\nv. 14.  Silvius\'sire.] Aeneas.\n\nv. 30.  The chosen vessel.]  St.Paul, Acts, c. ix. v. 15.  \"But\nthe Lord said unto him, Go thy way; for he is a chosen vessel\nunto me.\"\n\nv. 46.  Thy soul.] L\'anima tua e da viltate offesa. So in Berni,\nOrl Inn.lib. iii. c. i. st. 53.\n        Se l\'alma avete offesa da viltate.\n\nv. 64.  Who rest suspended.]  The spirits in Limbo, neither\nadmitted to a state of glory nor doomed to punishment.\n\nv. 61.  A friend not of my fortune, but myself.]  Se non fortunae\nsed hominibus solere esse amicum.  Cornelii Nepotis Attici Vitae,\nc. ix.\n\nv. 78.  Whatever is contain\'d.]  Every other thing comprised\nwithin the lunar heaven, which, being the lowest of all, has the\nsmallest circle.\n\nv. 93.  A blessed dame.]  The divine mercy.\n\nv. 97.  Lucia.]  The enlightening grace of heaven.\n\nv. 124.  Three maids.]  The divine mercy, Lucia, and Beatrice.\n\nv. 127.  As florets.]  This simile is well translated by\nChaucer--\n        But right as floures through the cold of night\n        Iclosed, stoupen in her stalkes lowe,\n        Redressen hem agen the sunne bright,\n        And speden in her kinde course by rowe, &c.\n               Troilus and Creseide, b.ii.\nIt has been imitated by many others, among whom see Berni,\nOrl.Inn. Iib. 1. c. xii. st. 86.  Marino, Adone, c. xvii. st. 63.\nand Sor. \"Donna vestita di nero.\" and Spenser\'s Faery Queen, b.4.\nc. xii. st. 34. and b. 6 c. ii. st. 35.\n\nCANTO III\n\nv. 5.          Power divine\n        Supremest wisdom, and primeval love.]  The three\npersons of the blessed Trinity.\nv. 9.  all hope abandoned.] Lasciate ogni speranza voi\nch\'entrate.\nSo Berni, Orl. Inn. lib. i. c. 8. st. 53.\n        Lascia pur della vita ogni speranza.\n\nv. 29.  Like to the sand.]\n               Unnumber\'d as the sands\n        Of Barca or Cyrene\'s torrid soil\n        Levied to side with warring winds, and poise\n        Their lighter wings.\n               Milton, P. L. ii. 908.");
    strcat(expected_filecontent1, "\n\nv. 40.  Lest th\' accursed tribe.]  Lest the rebellious angels\nshould exult at seeing those who were neutral and therefore less\nguilty, condemned to the same punishment with themselves.\n\nv. 50.  A flag.]\n               All the grisly legions that troop\n        Under the sooty flag of Acheron\n               Milton. Comus.\n\nv. 56.         Who to base fear\n        Yielding, abjur\'d his high estate.] This is\ncommonly understood of Celestine the Fifth, who abdicated the\npapal power in 1294. Venturi mentions a work written by\nInnocenzio Barcellini, of the Celestine order, and printed in\nMilan in 1701, In which an attempt is made to put a different\ninterpretation on this passage.\n\nv. 70.  through the blear light.]\n        Lo fioco lume\nSo Filicaja, canz. vi. st. 12.\n        Qual fioco lume.\n\nv. 77.  An old man.]\n        Portitor has horrendus aquas et flumina servat\n        Terribili squalore Charon, cui plurima mento\n        Canities inculta jacet; stant lumina flamma.\n               Virg. 7.  Aen. Iib. vi. 2.\n\nv. 82.  In fierce heat and in ice.]\n               The delighted spirit\n        To bathe in fiery floods or to reside\n        In thrilling regions of thick ribbed ice.\n               Shakesp. Measure for Measure, a. iii.s.1.\nCompare Milton, P. L. b. ii. 600.\n\nv. 92.  The livid lake.] Vada livida.\n               Virg. Aen. Iib. vi. 320\n               Totius ut Lacus putidaeque paludis\n        Lividissima, maximeque est profunda vorago.\n               Catullus. xviii. 10.\n\nv. 102.  With eyes of burning coal.]\n        His looks were dreadful, and his fiery eyes\n        Like two great beacons glared bright and wide.\n               Spenser. F.Q. b. vi. c. vii.st. 42\n\nv. 104.  As fall off the light of autumnal leaves.]\n        Quam multa in silvis autumul frigore primo\n        Lapsa cadunt folia.\n               Virg. Aen. lib. vi. 309\nCompare Apoll.  Rhod. lib. iv. 214.\n\nCANTO IV\n\nv. 8.  A thund\'rous sound.]  Imitated, as Mr. Thyer has remarked,\nby Milton, P. L. b. viii. 242.\n               But long ere our approaching heard\n        Noise, other, than the sound of dance or song\n        Torment, and loud lament, and furious rage.\n\nv. 50.  a puissant one.]  Our Saviour.\n\nv. 75.                 Honour the bard\n        Sublime.]\n\n        Onorate l\'altissimo poeta.\nSo Chiabrera, Canz. Eroiche. 32.\n        Onorando l\'altissimo poeta.\n\nv. 79.  Of semblance neither sorrowful nor glad.]\n        She nas to sober ne to glad.\n               Chaucer\'s Dream.\n\nv. 90.  The Monarch of sublimest song.]  Homer.\n\nv. 100.  Fitter left untold.]\n        Che\'l tacere e bello,\nSo our Poet, in Canzone 14.\n        La vide in parte che\'l tacere e bello,\nRuccellai, Le Api, 789.\n        Ch\'a dire e brutto ed a tacerlo e bello\nAnd Bembo,\n        \"Vie pui bello e il tacerle, che il favellarne.\"\n               Gli. Asol. lib. 1.\n\nv. 117.  Electra.]  The daughter of Atlas, and mother of Dardanus\nthe founder of Troy.  See Virg. Aen. b. viii. 134. as referred to\nby Dante in treatise \"De Monarchia,\" lib. ii. \"Electra, scilicet,\nnata magni nombris regis Atlantis, ut de ambobus testimonium\nreddit poeta noster in octavo ubi Aeneas ad Avandrum sic ait\n        \"Dardanus Iliacae,\" &c.\n\nv. 125.  Julia.]  The daughter of Julius Caesar, and wife of\nPompey.\n\nv. 126.  The Soldan fierce.]  Saladin or Salaheddin, the  rival\nof  Richard coeur de lion.  See D\'Herbelot, Bibl. Orient. and\nKnolles\'s Hist. of the Turks p. 57 to 73 and the Life of Saladin,\nby Bohao\'edin Ebn Shedad, published by Albert Schultens, with a\nLatin translation. He is introduced by Petrarch in the Triumph of\nFame, c. ii\n\nv. 128.  The master of the sapient throng.]\n        Maestro di color che sanno.\nAristotle--Petrarch assigns the first place to Plato. See Triumph\nof Fame, c. iii.\nPulci, in his Morgante Maggiore, c. xviii. says,\n        Tu se\'il maestro di color che sanno.\n\nv. 132.               Democritus\n        Who sets the world at chance.]\nDemocritus,who maintained the world to have been formed by the\nfortuitous concourse of atoms.\n\nv. 140.  Avicen.]  See D\'Herbelot Bibl. Orient. article  Sina. He\n");
    strcat(expected_filecontent1, "died in 1050.  Pulci here again imitates our poet:\n\n        Avicenna quel che il sentimento\n        Intese di Aristotile e i segreti,\n        Averrois che fece il gran comento.\n               Morg. Mag. c. xxv.\n\nv. 140.               Him who made\n        That commentary vast, Averroes.]\nAverroes, called by the Arabians Roschd, translated and commented\nthe works of Aristotle. According to Tiraboschi (storia della\nLett. Ital. t. v. 1. ii. c. ii. sect. 4.) he was the source of\nmodern philosophical impiety. The critic quotes some passages\nfrom Petrarch (Senil. 1. v. ep. iii. et. Oper. v. ii. p. 1143) to\nshow how strongly such sentiments prevailed in the time of that\npoet, by whom they were held in horror and detestation He adds,\nthat this fanatic admirer of Aristotle translated his writings\nwith that felicity, which might be expected from one who did not\nknow a syllable of Greek, and who was therefore compelled to\navail himself of the unfaithful Arabic versions. D\'Herbelot, on\nthe other hand, informs us, that \"Averroes was the first who\ntranslated Aristotle from Greek into Arabic, before the Jews had\nmade their translation:  and that we had for a long time no other\ntext of Aristotle, except that of the Latin translation, which\nwas made from this Arabic version of this great philosopher\n(Averroes), who afterwards added to it a very ample commentary,\nof which Thomas Aquinas, and the other scholastic writers,\navailed themselves, before the Greek originals of Aristotle and\nhis commentators were known to us in Europe.\" According to\nD\'Herbelot, he died in 1198: but Tiraboschi places that event\nabout 1206.\n\nCANTO V\n\nv. 5.  Grinning with ghastly feature.]  Hence Milton:\n               Death\n        Grinn\'d horrible a ghastly smile.\n               P. L. b. ii. 845.\n\nv. 46.  As cranes.]  This simile is imitated by Lorenzo de\nMedici, in his Ambra, a poem, first published by Mr. Roscoe, in\nthe  Appendix to his Life of Lorenzo.\n        Marking the tracts of air, the clam");strcat(expected_filecontent2, "y leader\'s feet still equaling pace\nFrom forth that cloud I came, when now expir\'d\nThe parting beams from off the nether shores.\n     O quick and forgetive power!  that sometimes dost\nSo rob us of ourselves, we take no mark\nThough round about us thousand trumpets clang!\nWhat moves thee, if the senses stir not?  Light\nKindled in heav\'n, spontaneous, self-inform\'d,\nOr likelier gliding down with swift illapse\nBy will divine.  Portray\'d before me came\nThe traces of her dire impiety,\nWhose form was chang\'d into the bird, that most\nDelights itself in song: and here my mind\nWas inwardly so wrapt, it gave no place\nTo aught that ask\'d admittance from without.\n     Next shower\'d into my fantasy a shape\nAs of one crucified, whose visage spake\nFell rancour, malice deep, wherein he died;\nAnd round him Ahasuerus the great king,\nEsther his bride, and Mordecai the just,\nBlameless in word and deed.  As of itself\nThat unsubstantial coinage of the brain\nBurst, like a bubble, Which the water fails\nThat fed it; in my vision straight uprose\nA damsel weeping loud, and cried, \"O queen!\nO mother!  wherefore has intemperate ire\nDriv\'n thee to loath thy being?  Not to lose\nLavinia, desp\'rate thou hast slain thyself.\nNow hast thou lost me.  I am she, whose tears\nMourn, ere I fall, a mother\'s timeless end.\"\n     E\'en as a sleep breaks off, if suddenly\nNew radiance strike upon the closed lids,\nThe broken slumber quivering ere it dies;\nThus from before me sunk that imagery\nVanishing, soon as on my face there struck\nThe light, outshining far our earthly beam.\nAs round I turn\'d me to survey what place\nI had arriv\'d at, \"Here ye mount,\" exclaim\'d\nA voice, that other purpose left me none,\nSave will so eager to behold who spake,\nI could not choose but gaze.  As \'fore the sun,\nThat weighs our vision down, and veils his form\nIn light transcendent, thus my virtue fail\'d\nUnequal.  \"This is Spirit from above,\nWho marshals us our upward way, unsought;\nAnd in his own light shrouds him;. As a man\nDoth for himself, so now is done for us.\nFor whoso waits imploring, yet sees need\nOf his prompt aidance, sets himself prepar\'d\nFor blunt denial, ere the suit be made.\nRefuse we not to lend a ready foot\nAt such inviting: haste we to ascend,\nBefore it darken: for we may not then,\nTill morn again return.\"  So spake my guide;\nAnd to one ladder both address\'d our steps;\nAnd the first stair approaching, I perceiv\'d\nNear me as \'twere the waving of a wing,\nThat fann\'d my face and whisper\'d: \"Blessed they\nThe peacemakers: they know not evil wrath.\"\n     Now to such height above our heads were rais\'d\nThe last beams, follow\'d close by hooded night,\nThat many a star on all sides through the gloom\nShone out.  \"Why partest from me, O my strength?\"\nSo with myself I commun\'d; for I felt\nMy o\'ertoil\'d sinews slacken.  We had reach\'d\nThe summit, and were fix\'d like to a bark\nArriv\'d at land.  And waiting a short space,\nIf aught should meet mine ear in that new round,\nThen to my guide I turn\'d, and said: \"Lov\'d sire!\nDeclare what guilt is on this circle purg\'d.\nIf our feet rest, no need thy speech should pause.\"\n     He thus to me:  \"The love of good, whate\'er\nWanted of just proportion, here fulfils.\nHere plies afresh the oar, that loiter\'d ill.\nBut that thou mayst yet clearlier understand,\nGive ear unto my words, and thou shalt cull\nSome fruit may please thee well, from this delay.\n     \"Creator, nor created being, ne\'er,\nMy son,\" he thus began, \"was without love,\nOr natural, or the free spirit\'s growth.\nThou hast not that to learn.  The natural still\nIs without error; but the other swerves,\nIf on ill object bent, or through excess\nOf vigour, or defect.  While e\'er it seeks\nThe primal blessings, or with measure due\nTh\' inferior, no delight, that flows from it,\nPartakes of ill.  But let it warp to evil,\nOr with more ardour than behooves, or less.\nPursue the good, the thing created then\nWorks \'gainst its Maker.  Hence thou must infer\nThat love is germin of each virtue in ye,\nAnd of each act no less, that merits pain.\nNow since it may not be, but love intend\nThe welfare mainly of the thing i");
    strcat(expected_filecontent2, "t loves,\nAll from self-hatred are secure; and since\nNo being can be thought t\' exist apart\nAnd independent of the first, a bar\nOf equal force restrains from hating that.\n     \"Grant the distinction just; and it remains\nThe\' evil must be another\'s, which is lov\'d.\nThree ways such love is gender\'d in your clay.\nThere is who hopes (his neighbour\'s worth deprest,)\nPreeminence himself, and coverts hence\nFor his own greatness that another fall.\nThere is who so much fears the loss of power,\nFame, favour, glory (should his fellow mount\nAbove him), and so sickens at the thought,\nHe loves their opposite: and there is he,\nWhom wrong or insult seems to gall and shame\nThat he doth thirst for vengeance, and such needs\nMust doat on other\'s evil.  Here beneath\nThis threefold love is mourn\'d.  Of th\' other sort\nBe now instructed, that which follows good\nBut with disorder\'d and irregular course.\n     \"All indistinctly apprehend a bliss\nOn which the soul may rest, the hearts of all\nYearn after it, and to that wished bourn\nAll therefore strive to tend.  If ye behold\nOr seek it with a love remiss and lax,\nThis cornice after just repenting lays\nIts penal torment on ye.  Other good\nThere is, where man finds not his happiness:\nIt is not true fruition, not that blest\nEssence, of every good the branch and root.\nThe love too lavishly bestow\'d on this,\nAlong three circles over us, is mourn\'d.\nAccount of that division tripartite\nExpect not, fitter for thine own research.\n\n\n\nCANTO XVIII\n\nThe teacher ended, and his high discourse\nConcluding, earnest in my looks inquir\'d\nIf I appear\'d content; and I, whom still\nUnsated thirst to hear him urg\'d, was mute,\nMute outwardly, yet inwardly I said:\n\"Perchance my too much questioning offends\nBut he, true father, mark\'d the secret wish\nBy diffidence restrain\'d, and speaking, gave\nMe boldness thus to speak: \"Master, my Sight\nGathers so lively virtue from thy beams,\nThat all, thy words convey, distinct is seen.\nWherefore I pray thee, father, whom this heart\nHolds dearest!  thou wouldst deign by proof t\' unfold\nThat love, from which as from their source thou bring\'st\nAll good deeds and their opposite.\"  He then:\n\"To what I now disclose be thy clear ken\nDirected, and thou plainly shalt behold\nHow much those blind have err\'d, who make themselves\nThe guides of men.  The soul, created apt\nTo love, moves versatile which way soe\'er\nAught pleasing prompts her, soon as she is wak\'d\nBy pleasure into act.  Of substance true\nYour apprehension forms its counterfeit,\nAnd in you the ideal shape presenting\nAttracts the soul\'s regard.  If she, thus drawn,\nincline toward it, love is that inclining,\nAnd a new nature knit by pleasure in ye.\nThen as the fire points up, and mounting seeks\nHis birth-place and his lasting seat, e\'en thus\nEnters the captive soul into desire,\nWhich is a spiritual motion, that ne\'er rests\nBefore enjoyment of the thing it loves.\nEnough to show thee, how the truth from those\nIs hidden, who aver all love a thing\nPraise-worthy in itself: although perhaps\nIts substance seem still good.  Yet if the wax\nBe good, it follows not th\' impression must.\"\n\"What love is,\" I return\'d, \"thy words, O guide!\nAnd my own docile mind, reveal.  Yet thence\nNew doubts have sprung.  For from without if love\nBe offer\'d to us, and the spirit knows\nNo other footing, tend she right or wrong,\nIs no desert of hers.\"  He answering thus:\n\"What reason here discovers I have power\nTo show thee: that which lies beyond, expect\nFrom Beatrice, faith not reason\'s task.\nSpirit, substantial form, with matter join\'d\nNot in confusion mix\'d, hath in itself\nSpecific virtue of that union born,\nWhich is not felt except it work, nor prov\'d\nBut through effect, as vegetable life\nBy the green leaf.  From whence his intellect\nDeduced its primal notices of things,\nMan therefore knows not, or his appetites\nTheir first affections; such in you, as zeal\nIn bees to gather honey; at the first,\nVolition, meriting nor blame nor praise.\nBut o\'er each lower faculty supreme,\nThat as she list are summon\'d to her bar,\nYe have that virtue in you, whose just voice\nUttereth co");
    strcat(expected_filecontent2, "unsel, and whose word should keep\nThe threshold of assent.  Here is the source,\nWhence cause of merit in you is deriv\'d,\nE\'en as the affections good or ill she takes,\nOr severs, winnow\'d as the chaff.  Those men\nWho reas\'ning went to depth profoundest, mark\'d\nThat innate freedom, and were thence induc\'d\nTo leave their moral teaching to the world.\nGrant then, that from necessity arise\nAll love that glows within you; to dismiss\nOr harbour it, the pow\'r is in yourselves.\nRemember, Beatrice, in her style,\nDenominates free choice by eminence\nThe noble virtue, if in talk with thee\nShe touch upon that theme.\"  The moon, well nigh\nTo midnight hour belated, made the stars\nAppear to wink and fade; and her broad disk\nSeem\'d like a crag on fire, as up the vault\nThat course she journey\'d, which the sun then warms,\nWhen they of Rome behold him at his set.\nBetwixt Sardinia and the Corsic isle.\nAnd now the weight, that hung upon my thought,\nWas lighten\'d by the aid of that clear spirit,\nWho raiseth Andes above Mantua\'s name.\nI therefore, when my questions had obtain\'d\nSolution plain and ample, stood as one\nMusing in dreary slumber; but not long\nSlumber\'d; for suddenly a multitude,\nThe steep already turning, from behind,\nRush\'d on.  With fury and like random rout,\nAs echoing on their shores at midnight heard\nIsmenus and Asopus, for his Thebes\nIf Bacchus\' help were needed; so came these\nTumultuous, curving each his rapid step,\nBy eagerness impell\'d of holy love.\n     Soon they o\'ertook us; with such swiftness mov\'d\nThe mighty crowd.  Two spirits at their head\nCried weeping; \"Blessed Mary sought with haste\nThe hilly region.  Caesar to subdue\nIlerda, darted in Marseilles his sting,\nAnd flew to Spain.\"--\"Oh tarry not: away;\"\nThe others shouted; \"let not time be lost\nThrough slackness of affection.  Hearty zeal\nTo serve reanimates celestial grace.\"\n     \"O ye, in whom intenser fervency\nHaply supplies, where lukewarm erst ye fail\'d,\nSlow or neglectful, to absolve your part\nOf good and virtuous, this man, who yet lives,\n(Credit my tale, though strange) desires t\' ascend,\nSo morning rise to light us.  Therefore say\nWhich hand leads nearest to the rifted rock?\"\n     So spake my guide, to whom a shade return\'d:\n\"Come after us, and thou shalt find the cleft.\nWe may not linger: such resistless will\nSpeeds our unwearied course.  Vouchsafe us then\nThy pardon, if our duty seem to thee\nDiscourteous rudeness.  In Verona I\nWas abbot of San Zeno, when the hand\nOf Barbarossa grasp\'d Imperial sway,\nThat name, ne\'er utter\'d without tears in Milan.\nAnd there is he, hath one foot in his grave,\nWho for that monastery ere long shall weep,\nRuing his power misus\'d: for that his son,\nOf body ill compact, and worse in mind,\nAnd born in evil, he hath set in place\nOf its true pastor.\"  Whether more he spake,\nOr here was mute, I know not: he had sped\nE\'en now so far beyond us.  Yet thus much\nI heard, and in rememb\'rance treasur\'d it.\n     He then, who never fail\'d me at my need,\nCried, \"Hither turn.  Lo!  two with sharp remorse\nChiding their sin!\"  In rear of all the troop\nThese shouted:  \"First they died, to whom the sea\nOpen\'d, or ever Jordan saw his heirs:\nAnd they, who with Aeneas to the end\nEndur\'d not suffering, for their portion chose\nLife without glory.\"  Soon as they had fled\nPast reach of sight, new thought within me rose\nBy others follow\'d fast, and each unlike\nIts fellow: till led on from thought to thought,\nAnd pleasur\'d with the fleeting train, mine eye\nWas clos\'d, and meditation chang\'d to dream.\n\n\nCANTO XIX\n\nIt was the hour, when of diurnal heat\nNo reliques chafe the cold beams of the moon,\nO\'erpower\'d by earth, or planetary sway\nOf Saturn; and the geomancer sees\nHis Greater Fortune up the east ascend,\nWhere gray dawn checkers first the shadowy cone;\nWhen \'fore me in my dream a woman\'s shape\nThere came, with lips that stammer\'d, eyes aslant,\nDistorted feet, hands maim\'d, and colour pale.\n     I look\'d upon her; and as sunshine cheers\nLimbs numb\'d by nightly cold, e\'en thus my look\nUnloos\'d her tongue, next in brief space her form\nDecrepit rais\'d erect, ");
    strcat(expected_filecontent2, "and faded face\nWith love\'s own hue illum\'d. Recov\'ring speech\nShe forthwith warbling such a strain began,\nThat I, how loth soe\'er, could scarce have held\nAttention from the song.  \"I,\" thus she sang,\n\"I am the Siren, she, whom mariners\nOn the wide sea are wilder\'d when they hear:\nSuch fulness of delight the list\'ner feels.\nI from his course Ulysses by my lay\nEnchanted drew.  Whoe\'er frequents me once\nParts seldom; so I charm him, and his heart\nContented knows no void.\"  Or ere her mouth\nWas clos\'d, to shame her at her side appear\'d\nA dame of semblance holy.  With stern voice\nShe utter\'d; \"Say, O Virgil, who is this?\"\nWhich hearing, he approach\'d, with eyes still bent\nToward that goodly presence: th\' other seiz\'d her,\nAnd, her robes tearing, open\'d her before,\nAnd show\'d the belly to me, whence a smell,\nExhaling loathsome, wak\'d me.  Round I turn\'d\nMine eyes, and thus the teacher:  \"At the least\nThree times my voice hath call\'d thee.  Rise, begone.\nLet us the opening find where thou mayst pass.\"\n     I straightway rose.  Now day, pour\'d down from high,\nFill\'d all the circuits of the sacred mount;\nAnd, as we journey\'d, on our shoulder smote\nThe early ray.  I follow\'d, stooping low\nMy forehead, as a man, o\'ercharg\'d with thought,\nWho bends him to the likeness of an arch,\nThat midway spans the flood; when thus I heard,\n\"Come, enter here,\" in tone so soft and mild,\nAs never met the ear on mortal strand.\n     With swan-like wings dispread and pointing up,\nWho thus had spoken marshal\'d us along,\nWhere each side of the solid masonry\nThe sloping, walls retir\'d; then mov\'d his plumes,\nAnd fanning us, affirm\'d that those, who mourn,\nAre blessed, for that comfort shall be theirs.\n     \"What aileth thee, that still thou look\'st to earth?\"\nBegan my leader; while th\' angelic shape\nA little over us his station took.\n     \"New vision,\" I replied, \"hath rais\'d in me\n8urmisings strange and anxious doubts, whereon\nMy soul intent allows no other thought\nOr room or entrance.--\"Hast thou seen,\" said he,\n\"That old enchantress, her, whose w");strcat(expected_filecontent3, "ed in 1312, at\nthe age of twenty four, in consequence, as it was supposed, of\nhis extreme intemperance.\nSee Mariana, Hist I. xv.  c. 11.\n\nv. 123.  The Bohemian.]  Winceslaus II.  Purgatory, Canto VII. v.\n\nv. 125.  The halter of Jerusalem.]  Charles II of Naples and\nJerusalem who was lame.  See note to Purgatory, Canto VII.  v.\n122, and XX. v. 78.\n\nv. 127.  He.]  Frederick of Sicily son of Peter III of Arragon.\nPurgatory, Canto VII.  v. 117.  The isle of fire is Sicily, where\nwas the tomb of Anchises.\n\nv. 133.  His uncle.]  James, king of Majorca and Minorca, brother\nto Peter III.\n\nv. 133.  His brother.]  James II of Arragon, who died in 1327.\nSee Purgatory, Canto VII.  v. 117.\n\nv. 135.  Of Portugal.]  In the time of Dante, Dionysius was king\nof Portugal.  He died in 1328, after a reign of near forty-six\nyears, and does not seem to have deserved the stigma here\nfastened on him. See Mariana. and 1. xv. c. 18.  Perhaps the\nrebellious son of Dionysius may be alluded to.\n\nv. 136.  Norway.]  Haquin, king of Norway, is probably meant;\nwho, having given refuge to the murderers of Eric VII king of\nDenmark, A D. 1288, commenced a war against his successor, Erie\nVIII, \"which continued for nine years, almost to the utter ruin\nand destruction of both kingdoms.\"  Modern Univ. Hist. v. xxxii\np. 215.\n\nv. 136.  -Him\nOf Ratza.]\nOne of the dynasty of the house of Nemagna, which ruled the\nkingdom of Rassia, or Ratza, in Sclavonia, from 1161 to 1371, and\nwhose history may be found in Mauro Orbino, Regno degli Slavi,\nEdiz. Pesaro. 1601. Uladislaus appears to have been the sovereign\nin Dante\'s time, but the disgraceful forgery adverted to in the\ntext, is not recorded by the historian v. 138.  Hungary.]  The\nkingdom of Hungary was about this time disputed by Carobert, son\nof Charles Martel, and Winceslaus, prince of Bohemia, son of\nWinceslaus II.  See Coxe\'s House of Austria, vol. i. p. 1. p. 86.\n\n4to edit.\n\nv. 140.  Navarre.]  Navarre was now under the yoke of France.\n It soon after (in 1328) followed the advice of Dante and had a\nmonarch of its own.  Mariana, 1.  xv. c. 19.\n\nv. 141.  Mountainous girdle.]  The Pyrenees.\n\nv. 143.  -Famagosta\'s streets\nAnd Nicosia\'s.]\n\nCities in the kingdom of Cyprus, at that time ruled by Henry II a\npusillanimous prince. Vertot.  Hist. des Chev.  de Malte, 1. iii.\niv. The meaning appears to be, that the complaints made by those\ncities of their weak and worthless governor, may be regarded as\nan earnest of his condemnation at the last doom.\n\nCANTO XX\n\nv. 6.  Wherein one shines.]  The light of the sun, whence he\nsupposes the other celestial bodies to derive their light\n\nv. 8.  The great sign.]  The eagle, the Imperial ensign.\n\nv. 34.  Who.]  David.\n\nv. 39.  He.]  Trajan.  See Purgatory, Canto X. 68.\n\nv. 44.  He next.]  Hezekiah.\n\nv. 50.  \'The other following.]  Constantine.  There is no passage\nin which Dante\'s opinion of the evil; that had arisen from the\nmixture of the civil with the ecclesiastical power, is more\nunequivocally  declared.\n\nv. 57.  William.]  William II, king of Sicily, at the latter part\nof  the twelfth century He was of the Norman line of sovereigns,\nand obtained the appellation of \"the Good\" and, as the poet says\nhis loss was as much the subject of regret in his dominions, as\nthe presence of Charles I of Anjou and Frederick of Arragon, was\nof sorrow and complaint.\n\nv. 62.  Trojan Ripheus.]\nRipheus, justissimus unus\nQui fuit in Teneris, et servantissimus aequi.\nVirg.  Aen.  1. ii. 4--.\n\nv. 97.  This.]  Ripheus.\n\nv. 98.  That.]  Trajan.\n\nv. 103.  The prayers,] The prayers of St. Gregory\n\nv. 119.  The three nymphs.]  Faith, Hope, and Charity. Purgatory,\nCanto XXIX.  116.\nv. 138.  The pair.]  Ripheus and Trajan.\n\nCANTO XXI\n\nv. 12.  The seventh splendour.]  The planet Saturn\n\nv. 13.  The burning lion\'s breast.]  The constellation Leo.\n\nv. 21.  In equal balance.]  \"My pleasure was as great in\ncomplying\nwith her will as in beholding her countenance.\"\n\nv. 24.  Of that lov\'d monarch.]  Saturn.  Compare Hell, Canto\nXIV.  91.\n\nv. 56.  What forbade the smile.]  \"Because it would have overcome\nthee.\"\n\nv. 6");
    strcat(expected_filecontent3, "1.  There aloft.]  Where the other souls were.\n\nv. 97.  A stony ridge.]  The Apennine.\n\nv. 112.  Pietro Damiano.]  \"S. Pietro Damiano obtained a great\nand well-merited reputation, by the pains he took to correct the\nabuses among the clergy.  Ravenna is supposed to have been the\nplace of his birth, about 1007.  He was employed in several\nimportant missions, and rewarded by Stephen IX with the dignity\nof cardinal, and the bishopric of Ostia, to which, however, he\npreferred his former retreat in the monastery of Fonte Aveliana,\nand prevailed on Alexander II to permit him to retire thither.\nYet he did not long continue in this seclusion, before he was\nsent on other embassies.  He died at Faenza in 1072.  His\nletters throw much light on the obscure history of these times.\nBesides them, he has left several treatises on sacred and\necclesiastical subjects. His eloquence is worthy of a better\nage.\"  Tiraboschi, Storia della Lett Ital. t. iii.  1. iv. c. 2.\n\nv. 114.  Beside the Adriatic.]  At Ravenna.  Some editions have\nFU instead of FUI, according to which reading, Pietro\ndistinguishes  himself from another Pietro, who was termed\n\"Peccator,\" the sinner.\n\nv. 117.  The hat.]  The cardinal\'s hat.\n\nv. 118.  Cephas.]  St. Peter.\n\nv. 119 The Holy Spirit\'s vessel.]  St. Paul. See Hell, Canto II.\n30.\n\nv. 130.  Round this.]  Round the spirit of Pietro Damiano.\n\nCANTO XXII\n\nv. 14.  The vengeance.]  Beatrice, it is supposed, intimates the\napproaching fate of Boniface VIII.  See Purgatory, Canto XX.  86.\n\nv. 36.  Cassino.]  A castle in the Terra di Lavoro.\n\nv. 38.  I it was.]  \"A new order of monks, which in a manner\nabsorbed all the others that were established in the west, was\ninstituted, A.D.  529, by Benedict of Nursis, a man of piety and\nreputation for the age he  lived in.\"  Maclaine\'s Mosheim,\nEccles. Hist. v. ii.  cent. vi. p. 2. ch.  2 - 6.\n\nv. 48.  Macarius.]  There are two of this name enumerated by\nMosheim among the Greek theologians of the fourth century, v. i.\ncent. iv p. 11 ch. 2 - 9.  In the following chapter, 10, it is\nsaid, \"Macarius, an Egyptian monk, undoubtedly deserves the first\nrank among the practical matters of this time, as his works\ndisplayed, some few things excepted, the brightest and most\nlovely portraiture of sanctity and virtue.\"\n\nv. 48.  Romoaldo.]  S. Romoaldo, a native of Ravenna, and the\nfounder of the order of Camaldoli, died in 1027.  He was the\nauthor of a commentary on the Psalms.\n\nv. 70.  The patriarch Jacob.]  So Milton, P. L. b. iii. 510:\nThe stairs were such, as whereon Jacob saw\nAngels ascending and descending, bands\nOf guardians bright.\n\nv. 107.  The sign.]  The constellation of Gemini.\n\nv. 130. This globe.]  So Chaucer, Troilus and Cresseide, b. v,\n\nAnd down from thence fast he gan avise\nThis little spot of earth, that with the sea\nEmbraced is, and fully gan despite\nThis wretched world.\n\nCompare Cicero, Somn. Scip.  \"Jam ipsa terra ita mihi parva visa\nest.\" &c.  Lucan, Phar 1.  ix. 11;  and Tasso, G.  L.  c.  xiv.\nst, 9, 10, 11.\n\nv. 140.  Maia and Dione.]  The planets Mercury and Venus.\n\nCANTO XXIII\n\nv. 11.  That region.]  Towards the south, where the course of the\nsun appears less rapid, than, when he is in the east or the west.\n\nv. 26.  Trivia.]  A name of Diana.\n\nv. 26.  Th\' eternal nymphs.]  The stars.\n\nv. 36.  The Might.]  Our Saviour\n\nv. 71.  The rose.]  The Virgin Mary.\n\nv. 73.  The lilies.]  The apostles.\n\nv. 84.  Thou didst exalt thy glory.]  The diving light retired\nupwards, to render the eyes of Dante more capable of enduring the\nspectacle  which now presented itself.\n\nv. 86.  The name of that fair flower.]  The name of the Virgin.\n\nv. 92.  A cresset.]  The angel Gabriel.\n\nv. 98.  That lyre.]  By synecdoche, the lyre is put for the angel\n\nv. 99.  The goodliest sapphire.]  The Virgin\n\nv. 126.  Those rich-laden coffers.]  Those spirits who, having\nsown the seed of good works on earth, now contain the fruit of\ntheir pious endeavours.\n\nv. 129.  In the Babylonian exile.]  During their abode in this\nworld.\n\nv. 133.  He.]  St. Peter, with the other holy men of the Old and\nNew testament.\n\nC");
    strcat(expected_filecontent3, "ANTO XXIV\n\nv. 28.  Such folds.]  Pindar has the same bold image:\n[GREEK HERE?]\nOn which Hayne strangely remarks:  Ad ambitus stropharum vldetur\n\nv. 65.  Faith.]  Hebrews, c.  xi.  1.  So Marino, in one of his\nsonnets, which calls Divozioni:\n\nFede e sustanza di sperate cose,\nE delle non visioili argomento.\n\nv. 82.  Current.]  \"The answer thou hast made is right; but let\nme know if thy inward persuasion is conformable to thy\nprofession.\"\n\nv. 91.  The ancient bond and new.]  The Old and New Testament.\n\nv. 114.  That Worthy.]  Quel Baron.\nIn the next Canto, St. James is called \"Barone.\"  So in\nBoccaccio, G. vi. N. 10, we find \"Baron Messer Santo Antonio.\"\nv. 124.  As to outstrip.]  Venturi insists that the Poet has\nhere, \"made a slip;\" for that John came first to the sepulchre,\nthough Peter was the first to enter it.  But let Dante have leave\nto explain his own meaning, in a passage from his third book De\nMonarchia:  \"Dicit etiam Johannes ipsum (scilicet Petrum)\nintroiisse SUBITO, cum venit in monumentum, videns allum\ndiscipulum cunctantem ad ostium.\" Opere de Dante, Ven. 1793. T.\nii. P. 146.\n\nCANTO XXV\n\nv. 6.  The fair sheep-fold.]  Florence, whence he was banished.\n\nv. 13.  For its sake.]  For the sake of that faith.\n\nv. 20.  Galicia throng\'d with visitants.] See Mariana, Hist. 1.\nxi.\n\nv. 13.  \"En el tiempo,\" &c.  \"At the time that the sepulchre of\nthe apostle St. James was discovered, the devotion for that place\nextended itself not only over all Spain, but even round about to\nforeign nations. Multitudes from all parts of the world came to\nvisit it.  Many others were deterred by the difficulty for the\njourney, by the roughness and barrenness of those parts, and by\nthe incursions of the Moors, who made captives many of the\npilgrims.  The canons of St. Eloy afterwards (the precise time is\nnot known), with a desire of remedying these evils, built, in\nmany places, along the whole read, which reached as far as to\nFrance, hospitals for the reception of the pilgrims.\"\n\nv. 31.  Who.]  The Epistle of St. James is here attributed to the\nelder apostle of that name, whose shrine was at Compostella, in\nGalicia.  Which of the two was the author of it is yet doubtful.\nThe learned and candid Michaelis contends very forcibly for its\nhaving been written by James the Elder.  Lardner rejects that\nopinion as absurd; while Benson argues against it, but is well\nanswered by Michaelis, who after all, is obliged to leave the\nquestion undecided.  See his Introduction to the New Testament,\ntranslated by Dr. Marsh, ed.  Cambridge, 1793.  V. iv. c.  26.  -\n1, 2, 3.\n\nv. 35.  As Jesus.]  In the transfiguration on Mount Tabor.\n\nv. 39.  The second flame.]  St. James.\n\nv. 40.  I lifted up.]  \"I will lift up mine eyes unto the hills,\nfrom whence cometh my help.\"  Ps.  Cxxi.  1.\n\nv. 59.  From Egypt to Jerusalem.]  From the lower world to\nheaven.\n\nv. 67.  Hope.]  This is from the Sentences of Petrus Lombardus.\n\"Est autem spes virtus, qua spiritualia et aeterna bona speratam,\nid  est, beatitudinem aeternam.  Sine meritis enim aliquid\nsperare non spes, sed praesumptio, dici potest.\"  Pet. Lomb.\nSent.  1.  Iii.  Dist.  26.   Ed. Bas.  1486.  Fol.\n\nv. 74.  His anthem.]  Psalm ix.  10.\n\nv. 90.  Isaias ]  Chap. lxi. 10.\n\nv. 94.  Thy brother.]  St. John in the Revelation, c. vii.  9.\n\nv. 101.  Winter\'s month.]  \"If a luminary, like that which now\nappeared, were to shine throughout the month following the winter\nsolstice during which the constellation Cancer appears in the\neast at the setting of the sun, there would be no interruption to\nthe light, but the whole month would be as a single day.\"\n\nv. 112.  This.]  St. John, who reclined on the bosom of our\nSaviour, and to whose charge Jesus recommended his mother.\n\nv. 121.  So I.]  He looked so earnestly, to descry whether St.\nJohn were present there in body, or in spirit only, having had\nhis doubts raised  by that saying of our Saviour\'s:  \"If I will,\nthat he tarry till I come  what is that to thee.\"\n\nv. 127.  The two.]  Christ and Mary, whom he has described, in\nthe last Canto but one, as rising above his sight\n\nCANT");
    strcat(expected_filecontent3, "O XXVI\n\nv. 2.  The beamy flame.]  St. John.\n\nv. 13.  Ananias\' hand.]  Who, by putting his hand on St. Paul,\nrestored his sight.  Acts, c. ix.  17.\n\nv. 36.  From him.]  Some suppose that Plato is here meant, who,\nin his Banquet, makes Phaedrus say:  \"Love is confessedly amongst\nthe eldest of beings, and, being the eldest, is the cause to us\nof the greatest goods \" Plat. Op. t. x. p. 177.  Bip.  ed. Others\nhave understood it of Aristotle, and others, of the writer who\ngoes by the name of Dionysius the Areopagite, referred to in the\ntwenty-eighth Canto.\n\nv. 40.  I will make.]  Exodus, c. xxxiii. 19.\n\nv. 42.  At the outset.]  John, c. i. 1.  &c.\n\nv. 51.  The eagle of our Lord.]  St. John\n\nv. 62.  The leaves.]  Created beings.\n\nv. 82.  The first living soul.]  Adam.\n\nv. 107.  Parhelion.]  Who enlightens and comprehends all things;\nbut is himself enlightened and comprehended by none.\n\nv. 117.  Whence.]  That is, from Limbo.  See Hell, Canto II.  53.\nAdam says that 5232 years elapsed from his creation to the time\nof his deliverance, which followed the death of Christ.\n\nv. 133.  EL]  Some read UN, \"One,\" instead of EL:  but the latter\nof these readings is confirmed by a passage from Dante\'s Treatise\nDe Vulg. Eloq. 1. i. cap. 4. \"Quod prius vox primi loquentis\nsonaverit, viro sanae mentis in promptu esse non dubito ipsum\nfuisse quod Deus est, videlicet El.\"  St. Isidore in the\nOrigines, 1.  vii. c. 1. had said, \"Primum apud Hebraeos Dei\nnomen El dicitur.\"\n\nv. 135.  Use.]  From Horace, Ars. Poet. 62.\n\nv. 138.  All my life.]  \"I remained in the terrestrial Paradise\nonly tothe seventh hour.\"  In the Historia Scolastica of Petrus\nComestor, it is said of our first parents:  Quidam tradunt eos\nfuisse in Paradiso septem horae.\"  I. 9. ed. Par. 1513. 4to.\n\nCANTO XXVII\n\nv.  1.  Four torches.]  St. Peter, St. James, St. John, and Adam.\n\nv. 11.  That.] ");strcat(expected_filecontent4, "st gives\nIts temper and impression.  Morning there,\nHere eve was by almost such passage made;\nAnd whiteness had o\'erspread that hemisphere,\nBlackness the other part; when to the left\nI saw Beatrice turn\'d, and on the sun\nGazing, as never eagle fix\'d his ken.\nAs from the first a second beam is wont\nTo issue, and reflected upwards rise,\nE\'en as a pilgrim bent on his return,\nSo of her act, that through the eyesight pass\'d\nInto my fancy, mine was form\'d; and straight,\nBeyond our mortal wont, I fix\'d mine eyes\nUpon the sun.  Much is allowed us there,\nThat here exceeds our pow\'r; thanks to the place\nMade for the dwelling of the human kind\n     I suffer\'d it not long, and yet so long\nThat I beheld it bick\'ring sparks around,\nAs iron that comes boiling from the fire.\nAnd suddenly upon the day appear\'d\nA day new-ris\'n, as he, who hath the power,\nHad with another sun bedeck\'d the sky.\n     Her eyes fast fix\'d on the eternal wheels,\nBeatrice stood unmov\'d; and I with ken\nFix\'d upon her, from upward gaze remov\'d\nAt her aspect, such inwardly became\nAs Glaucus, when he tasted of the herb,\nThat made him peer among the ocean gods;\nWords may not tell of that transhuman change:\nAnd therefore let the example serve, though weak,\nFor those whom grace hath better proof in store\n     If I were only what thou didst create,\nThen newly, Love!  by whom the heav\'n is rul\'d,\nThou know\'st, who by thy light didst bear me up.\nWhenas the wheel which thou dost ever guide,\nDesired Spirit!  with its harmony\nTemper\'d of thee and measur\'d, charm\'d mine ear,\nThen seem\'d to me so much of heav\'n to blaze\nWith the sun\'s flame, that rain or flood ne\'er made\nA lake so broad.  The newness of the sound,\nAnd that great light, inflam\'d me with desire,\nKeener than e\'er was felt, to know their cause.\n     Whence she who saw me, clearly as myself,\nTo calm my troubled mind, before I ask\'d,\nOpen\'d her lips, and gracious thus began:\n\"With false imagination thou thyself\nMak\'st dull, so that thou seest not the thing,\nWhich thou hadst seen, had that been shaken off.\nThou art not on the earth as thou believ\'st;\nFor light\'ning scap\'d from its own proper place\nNe\'er ran, as thou hast hither now return\'d.\"\n     Although divested of my first-rais\'d doubt,\nBy those brief words, accompanied with smiles,\nYet in new doubt was I entangled more,\nAnd said:  \"Already satisfied, I rest\nFrom admiration deep, but now admire\nHow I above those lighter bodies rise.\"\n     Whence, after utt\'rance of a piteous sigh,\nShe tow\'rds me bent her eyes, with such a look,\nAs on her frenzied child a mother casts;\nThen thus began:  \"Among themselves all things\nHave order; and from hence the form, which makes\nThe universe resemble God.  In this\nThe higher creatures see the printed steps\nOf that eternal worth, which is the end\nWhither the line is drawn.  All natures lean,\nIn this their order, diversely, some more,\nSome less approaching to their primal source.\nThus they to different havens are mov\'d on\nThrough the vast sea of being, and each one\nWith instinct giv\'n, that bears it in its course;\nThis to the lunar sphere directs the fire,\nThis prompts the hearts of mortal animals,\nThis the brute earth together knits, and binds.\nNor only creatures, void of intellect,\nAre aim\'d at by this bow; hut even those,\nThat have intelligence and love, are pierc\'d.\nThat Providence, who so well orders all,\nWith her own light makes ever calm the heaven,\nIn which the substance, that hath greatest speed,\nIs turn\'d: and thither now, as to our seat\nPredestin\'d, we are carried by the force\nOf that strong cord, that never looses dart,\nBut at fair aim and glad.  Yet is it true,\nThat as ofttimes but ill accords the form\nTo the design of art, through sluggishness\nOf unreplying matter, so this course\nIs sometimes quitted by the creature, who\nHath power, directed thus, to bend elsewhere;\nAs from a cloud the fire is seen to fall,\nFrom its original impulse warp\'d, to earth,\nBy vicious fondness.  Thou no more admire\nThy soaring, (if I rightly deem,) than lapse\nOf torrent downwards from a mountain\'s height.\nThere would in thee for wonder be m");
    strcat(expected_filecontent4, "ore cause,\nIf, free of hind\'rance, thou hadst fix\'d thyself\nBelow, like fire unmoving on the earth.\"\n     So said, she turn\'d toward the heav\'n her face.\n\n\n\nCANTO II\n\nAll ye, who in small bark have following sail\'d,\nEager to listen, on the advent\'rous track\nOf my proud keel, that singing cuts its way,\nBackward return with speed, and your own shores\nRevisit, nor put out to open sea,\nWhere losing me, perchance ye may remain\nBewilder\'d in deep maze.  The way I pass\nNe\'er yet was run: Minerva breathes the gale,\nApollo guides me, and another Nine\nTo my rapt sight the arctic beams reveal.\nYe other few, who have outstretch\'d the neck.\nTimely for food of angels, on which here\nThey live, yet never know satiety,\nThrough the deep brine ye fearless may put out\nYour vessel, marking, well the furrow broad\nBefore you in the wave, that on both sides\nEqual returns.  Those, glorious, who pass\'d o\'er\nTo Colchos, wonder\'d not as ye will do,\nWhen they saw Jason following the plough.\n     The increate perpetual thirst, that draws\nToward the realm of God\'s own form, bore us\nSwift almost as the heaven ye behold.\n     Beatrice upward gaz\'d, and I on her,\nAnd in such space as on the notch a dart\nIs plac\'d, then loosen\'d flies, I saw myself\nArriv\'d, where wond\'rous thing engag\'d my sight.\nWhence she, to whom no work of mine was hid,\nTurning to me, with aspect glad as fair,\nBespake me: \"Gratefully direct thy mind\nTo God, through whom to this first star we come.\"\n     Me seem\'d as if a cloud had cover\'d us,\nTranslucent, solid, firm, and polish\'d bright,\nLike adamant, which the sun\'s beam had smit\nWithin itself the ever-during pearl\nReceiv\'d us, as the wave a ray of light\nReceives, and rests unbroken.  If I then\nWas of corporeal frame, and it transcend\nOur weaker thought, how one dimension thus\nAnother could endure, which needs must be\nIf body enter body, how much more\nMust the desire inflame us to behold\nThat essence, which discovers by what means\nGod and our nature join\'d!  There will be seen\nThat which we hold through faith, not shown by proof,\nBut in itself intelligibly plain,\nE\'en as the truth that man at first believes.\n     I answered:  \"Lady!  I with thoughts devout,\nSuch as I best can frame, give thanks to Him,\nWho hath remov\'d me from the mortal world.\nBut tell, I pray thee, whence the gloomy spots\nUpon this body, which below on earth\nGive rise to talk of Cain in fabling quaint?\"\n     She somewhat smil\'d, then spake:  \"If mortals err\nIn their opinion, when the key of sense\nUnlocks not, surely wonder\'s weapon keen\nOught not to pierce thee; since thou find\'st, the wings\nOf reason to pursue the senses\' flight\nAre short.  But what thy own thought is, declare.\"\n     Then I:  \"What various here above appears,\nIs caus\'d, I deem, by bodies dense or rare.\"\n     She then resum\'d:  \"Thou certainly ");strcat(expected_filecontent5, "ges, till he arrives in a beautiful valley\ncovered with flowers on all sides, and the richest in the world;\nbut which was continually  shifting its appearance from a round\nfigure to a square, from obscurity to light, and from\npopulousness to solitude.  This is the region of Pleasure, or\nCupid, who is accompanied by four ladies, Love, Hope, Fear, and\nDesire.  In one part of it he meets with Ovid, and is instructed\nby him how to conquer the passion of love, and to escape from\nthat place.  After his escape he makes his confession to a friar,\nand then returns to the forest of visions:  and ascending a\nmountain, he meets with Ptolemy, a venerable old man.  Here the\nnarrative breaks off. The  poem ends, as it began, with an\naddress to Rustico di Filippo, on whom he lavishes every sort of\npraise.\n\nIt has been observed, that Dante derived the idea of opening his\npoem by describing himself as lost in a wood, from the Tesoretto\nof his master.  I know not whether it has been remarked, that the\ncrime of usury is branded by both these poets as offensive to God\nand Nature:  or that the sin for which Brunetto is condemned by\nhis pupil, is mentioned in the Tesoretto with great horror.\nDante\'s twenty-fifth sonnet is a jocose one, addressed to\nBrunetto.  He died in 1295.\n\nv. 62.  Who in old times came down from Fesole.]  See G. Villani\nHist. l. iv. c. 5. and Macchiavelli Hist. of Flor. b. ii.\n\nv. 89.  With another text.]  He refers to the prediction of\nFarinata, in Canto X.\n\nv. 110.  Priscian.]  There is no reason to believe, as the\ncommentators observe that the grammarian of this name was stained\nwith the vice imputed to him; and we must therefore suppose that\nDante puts the individual for the species, and implies the\nfrequency of the crime among those who abused the opportunities\nwhich the education of youth afforded them, to so abominable a\npurpose.\n\nv. 111.  Francesco.]  Son of Accorso, a Florentine, celebrated\nfor his skill in jurisprudence, and commonly known by the name of\nAccursius.\n\nv. 113.  Him.]  Andrea de\' Mozzi, who, that his scandalous life\nmight be less exposed to observation, was translated either by\nNicholas III, or Boniface VIII from the see of Florence to that\nof Vicenza, through which passes the river Baccchiglione.  At the\nlatter of these places he died.\n\nv. 114.  The servants\' servant.]  Servo de\' servi.  So Ariosto,\nSat. 3.\n               Degli servi\n        Io sia il gran servo.\n\nv. 124.  I commend my Treasure to thee.]  Brunetto\'s great work,\nthe Tresor.\nSieti raccomandato \'l mio Tesoro.\nSo Giusto de\' Conti, in his Bella Mano, Son.  \"Occhi:\"\n        Siavi raccommandato il mio Tesoro.\n\nCANTO XVI\n\nv. 38.  Gualdrada.]  Gualdrada was the daughter of Bellincione\nBerti, of whom mention is made in the Paradise, Canto XV, and\nXVI.  He was of the family of Ravignani, a branch of the Adimari.\n\nThe Emperor Otho IV. being at a festival in Florence, where\nGualdrada was present, was struck with her beauty; and inquiring\nwho she was, was answered by Bellincione, that she was the\ndaughter of one who, if it was his Majesty\'s pleasure, would make\nher admit the honour of his salute.  On overhearing this, she\narose from her seat, and blushing, in an animated tone of voice,\ndesired her father that he would not be so liberal in his offers,\nfor that no man should ever be allowed that freedom, except him\nwho should be her lawful husband.  The Emperor was not less\ndelighted by her resolute modesty than he had before been by the\nloveliness of her person, and calling to him Guido, one of his\nbarons, gave her to him in marriage, at the same time raising him\n\nto the rank of a count, and bestowing on her the whole of\nCasentino, and a part of the territory of Romagna, as her\nportion.  Two sons were the offspring of this union, Guglielmo\nand Ruggieri, the latter of whom was father of Guidoguerra, a man\nof great military skill and prowess who, at the head of four\nhundred Florentines of the Guelph party, was signally\ninstrumental to the victory obtained at Benevento by Charles of\nAnjou, over Manfredi, King of Naples, in 1265.   One of the\nconsequ");
    strcat(expected_filecontent5, "ences of this victory was the expulsion of the Ghibellini,\nand the re-establishment of the Guelfi at Florence.\n\nv. 39.  Many a noble act.]  Compare Tasso, G. L. c. i. st. 1.\n\nv. 42.  Aldobrandiu]  Tegghiaio Aldobrandi was of the noble\nfamily of Adimari, and much esteemed for his military talents.\nHe endeavored to dissuade the Florentines from the attack, which\nthey meditated against the Siennese, and the rejection of his\ncounsel occasioned the memorable defeat, which the former\nsustained at Montaperto, and the consequent banishment of the\nGuelfi from Florence.\n\nv. 45.  Rusticucci.]  Giacopo Rusticucci, a Florentine,\nremarkable for his opulence and the generosity of his spirit.\n\nv. 70.  Borsiere.]  Guglielmo Borsiere, another Florentine, whom\nBoccaccio, in a story which he relates of him, terms \"a man of\ncourteous and elegant manners, and of great readiness in\nconversation.\"  Dec. Giorn. i. Nov. 8.\n\nv. 84.  When thou with pleasure shalt retrace the past.]\n        Quando ti giovera dicere io fui.\nSo Tasso, G. L. c. xv. st. 38.\n        Quando mi giovera narrar altrui\n        Le novita vedute, e dire; io fui.\n\nv. 121.  Ever to that truth.]  This memorable apophthegm is\nrepeated by Luigi Pulci and Trissino.\n\n        Sempre a quel ver, ch\' ha faccia di menzogna\n        E piu senno tacer la lingua cheta\n        Che spesso senza colpa fa vergogna.\n               Morgante. Magg.  c. xxiv.\n\n               La verita, che par mensogna\n        Si dovrebbe tacer dall\' uom ch\'e saggio.\n               Italia. Lib. C. xvi.\n\nCANTO XVII\n\nv. 1.  The fell monster.]  Fraud.\n\nv. 53.  A pouch.]  A purse, whereon the armorial bearings of each\nwere emblazoned.  According to Landino, our poet implies that the\nusurer can pretend to no other honour, than such as he derives\nfrom his purse and his family.\n\nv. 57.  A yellow purse.]  The arms of the Gianfigliazzi of\nFlorence.\n\nv. 60.  Another.]  Those of the Ubbriachi, another Florentine\nfamily of high distinction.\n\nv. 62.  A fat and azure swine.]  The arms of the Scrovigni a\nnoble family of Padua.\n\nv. 66.  Vitaliano.]  Vitaliano del Dente, a Paduan.\n\nv. 69.  That noble knight.]  Giovanni Bujamonti, a Florentine\nusurer, the most infamous of his time.\n\nCANTO XVIII\n\nv. 28.  With us beyond.]  Beyond the middle point they tended the\nsame way with us, but their pace was quicker than ours.\n\nv. 29.  E\'en thus the Romans.]  In the year 1300, Pope Boniface\nVIII., to remedy the inconvenience occasioned by the press of\npeople who were passing over the bridge of St. Angelo during the\ntime of the Jubilee, caused it to be divided length wise by a\npartition, and ordered, that all those who were going to St.\nPeter\'s should keep one side, and those returning the other.\n\nv. 50.  Venedico.]  Venedico Caccianimico, a Bolognese, who\nprevailed on his sister Ghisola to prostitute herself to Obizzo\nda  Este, Marquis of Ferrara, whom we have seen among the\ntyrants, Canto XII.\n\nv. 62.  To answer Sipa.]  He denotes Bologna by its situation\nbetween the rivers Savena to the east, and Reno to the west of\nthat city; and by a peculiarity of dialect, the use of the\naffirmative sipa instead of si.\n\nv. 90.  Hypsipyle.]  See Appolonius Rhodius, l. i. and Valerius\nFlaccus l.ii.  Hypsipyle deceived the other women by concealing\nher father Thoas, when they had agreed to put all their males to\ndeath.\n\nv. 120.  Alessio.]  Alessio, of an ancient and considerable\nfamily in Lucca, called the Interminei.\n\nv. 130.  Thais.]  He alludes to that passage in the Eunuchus of\nTerence where Thraso asks if Thais was obliged to him for the\npresent he had sent her, and Gnatho replies, that she had\nexpressed her obligation in the most forcible terms.\n        T.  Magnas vero agere gratias Thais mihi?\n        G.  Ingentes.\n               Eun. a. iii. s. i.\n\nCANTO XIX\n\nv. 18.  Saint John\'s fair dome.]  The apertures in the  rock were\nof the same dimensions as the fonts of St. John the Baptist at\nFlorence, one of which, Dante says he had broken, to rescue a\nchild  that was playing near and fell in. He intimates that the\nmotive of his  breaking the font had been m");
    strcat(expected_filecontent5, "aliciously represented\nby his enemies.\n\nv. 55.  O Boniface!]  The spirit mistakes Dante for  Boniface\nVIII. who was then alive, and who he did not expect would have\narrived so soon, in consequence, as it should seem, of a\nprophecy, which  predicted the death of that Pope at a later\nperiod. Boniface died in  1303.\n\nv. 58.  In guile.]  \"Thou didst presume to arrive by fraudulent\nmeans at the papal power, and afterwards to abuse it.\"\n\nv. 71.  In the mighty mantle I was rob\'d.]  Nicholas III, of the\nOrsini family, whom the poet therefore calls \"figliuol dell\'\norsa,\" \"son of the she-bear.\"  He died in 1281.\n\nv. 86.  From forth the west, a shepherd without law.]   Bertrand\nde Got Archbishop of Bordeaux, who succeeded to the pontificate\nin 1305, and assumed the title of Clement V. He transferred the\nholy  see to Avignon in 1308 (where it remained till 1376), and\ndied in 1314.\n\nv. 88.  A new Jason.]  See Maccabees, b. ii. c. iv. 7,8.\n\nv. 97.  Nor Peter.]  Acts of the Apostles, c.i. 26.\n\nv. 100.  The condemned soul.]  Judas.\n\nv. 103.  Against Charles.]  Nicholas III. was enraged against\nCharles I, King of Sicily, because he rejected with scorn a\nproposition made by that Pope for an alliance between their\nfamilies.  See G. Villani, Hist. l. vii. c. liv.\n\nv. 109.  Th\' Evangelist.]  Rev. c. xvii. 1, 2, 3.  Compare\nPetrarch.  Opera fol. ed. Basil. 1551. Epist. sine titulo liber.\nep. xvi. p. 729.\n\nv. 118.  Ah, Constantine.]  He alludes to the pretended gift of\nthe Lateran by Constantine to Silvester, of which Dante himself\nseems to imply a doubt, in his treatise \"De Monarchia.\" - \"Ergo\nscindere Imperium, Imperatori non licet.  Si ergo aliquae,\ndignitates per Constantinum essent alienatae, (ut dicunt) ab\nImperio,\" &c. l. iii.\nThe gift is by Ariosto very humorously placed in the moon, among\nthe things lost or abused on earth.\n        Di varj fiori, &c.\n               O. F. c. xxxiv. st. 80.\n\nMilton has translated both this passage and that in the text.\nProse works, vol. i. p. 11. ed. 1753.\n\nCANTO XX\n\nv. 11.  Revers\'d.]  Compare Spenser, F. Q. b. i. c. viii.  st. 31\n\nv. 30.  Before whose eyes.]  Amphiaraus, one of the seven kings\nwho besieged Thebes.  He is said to have been swallowed up by  an\nopening of the earth.  See Lidgate\'s Storie of Thebes, Part III\nwhere it is told how the \"Bishop Amphiaraus\" fell down to hell.\n        And thus the devill for his outrages,\n        Like his desert payed him his wages.\nA different reason for his being doomed thus to perish is\nassigned by Pindar.\n[GREEK HERE]\n               Nem ix.\n\n        For thee, Amphiaraus, earth,\n        By Jove\'s all-riving thunder cleft\n        Her mighty bosom open\'d wide,\n        Thee and thy plunging steeds to hide,\n        Or ever on thy back the spear\n        Of Periclymenus impress\'d\n        A wound to shame thy warlike breast\n        For struck with panic fear\n        The gods\' own children flee.\n\nv. 37.  Tiresias.]\n        Duo magnorum viridi coeuntia sylva\n        Corpora serpentum baculi violaverat ictu, &c.\n               Ovid. Met. iii.\n\nv. 43.  Aruns.]  Aruns is said to have dwelt in the  mountains of\nLuni (from whence that territory is still called Lunigiana),\nabove Carrara, celebrated for its marble.  Lucan. Phars. l. i.\n575.  So Boccaccio in the Fiammetta, l. iii.  \"Quale Arunte,\" &c.\n\n\"Like Aruns, who amidst the white marbles of Luni, contemplated\nthe celestial bodies and their motions.\"\n\nv. 50.  Manto.]  The daughter of Tiresias of Thebes, a city\ndedicated to Bacchus.  From Manto Mantua, the country of Virgil\nderives its name. The Poet proceeds to describe the situation of\nthat place.\n\nv. 61.  Between the vale.]  The lake Benacus, now called  the\nLago di Garda, though here said to lie between Garda, Val\nCamonica, and the Apennine, is, however, very distant from the\nlatter two\n\nv. 63.  There is a spot.]  Prato di Fame, where the dioceses of\nTrento, Verona, and Brescia met.\n\nv. 69.  Peschiera.]  A garrison situated to the south of the\nlake, where it empties itself and forms the Mincius.\n\nv. 94.  Casalodi\'s madness.]  Alberto da Casalodi, who had got\npossess");
    strcat(expected_filecontent5, "ion of Mantua, was persuaded by Pinamonte Buonacossi, that\nhe might ingratiate himself with the people by banishing to their\n\nown castles the nobles, who were obnoxious to them.  No sooner\nwas this done, than Pinamonte put himself at the head of the\npopulace, drove out Casalodi and his adherents, and obtained the\nsovereignty for himself.\n\nv. 111.  So sings my tragic strain.]\n        Suspensi Eurypilum scitatum oracula Phoebi\n        Mittimus.\n               Virg. Aeneid. ii. 14.\n\nv. 115.  Michael Scot.]  Sir Michael Scott, of Balwearie,\nastrologer to the Emperor Frederick II. lived in the thirteenth\ncentury.  For further particulars relating to this singular man,\nsee Warton\'s History of English Poetry, vol. i. diss. ii. and\nsect. ix.  p 292, and the Notes to Mr. Scott\'s \"Lay of the Last\nMinstrel,\" a  poem in which a happy use is made of the traditions\nthat are still current in North Britain concerning him.  He is\nmentioned by G. Villani. Hist. l. x. c. cv. and cxli. and l. xii.\nc. xviii. and by Boccaccio, Dec. Giorn. viii. Nov. 9.\n\nv. 116.  Guido Bonatti.]  An astrologer of Forli, on whose  skill\nGuido da Montefeltro, lord of that place, so much relied, that he\nis reported never to have gone into battle, except in the hour\nrecommended to him as fortunate by Bonatti.\n\nLandino and Vellutello, speak of a book, which he composed on the\nsubject of his art.\n\nv. 116.  Asdente.]  A shoemaker at Parma, who deserted his\nbusiness to practice the arts of divination.\n\nv. 123.  Cain with fork of thorns.]  By Cain and the thorns, or\nwhat is still vulgarly called the Man in the Moon, the Poet\ndenotes that luminary.  The same superstition is alluded to in\nthe Paradise, Canto II. 52.  The curious reader may consult Brand\non Popular Antiquities, 4to.  1813. vol. ii. p. 476.\n\nCANTO XXI\n\nv. 7.  In the Venetians\' arsenal.]  Compare Ruccellai, Le  Api,\n165, and Dryden\'s Annus Mirabilis, st. 146, &c.\n\nv. 37.  One of Santa Zita\'s elders.]  The elders or chief\nmagistrates of Lucca, where Santa Zita was held in especial\nveneration.  The name of this sinner is supposed to have been\nMartino Botaio.\n\nv. 40.  Except Bonturo, barterers.]  This is said ironically of\nBonturo de\' Dati.  By barterers are meant peculators, of every\ndescription; all who traffic the interests of the public  for\ntheir own private advantage.\n\nv. 48.  Is other swimming than in Serchio\'s wave.]\n        Qui si nuota altrimenti che nel Serchio.\nSerchio is the river that flows by Lucca.  So Pulci, Morg. Mag.\nc. xxiv.\n        Qui si nuota nel sangue, e non nel Serchio.\n\nv. 92.  From Caprona.]  The surrender of the castle of Caprona to\nthe combined forces of Florence and Lucca, on condition that the\ngarrison should march out in safety, to which ");strcat(expected_filecontent6, " came; nor was it ever known whence\nhe was or wither he went.\" G. Villani, 1.  vi.  c. 92.\n\nv. 135.  Four daughters.]  Of the four daughters of Raymond\nBerenger, Margaret, the eldest, was married to Louis IX of\nFrance; Eleanor; the next, to Henry III, of England; Sancha, the\nthird, to Richard, Henry\'s brother, and King of the Romans; and\nthe youngest, Beatrice, to Charles I, King of Naples ");


            struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            
                    struct file_t* file0 = file_open(volume, "WANT.TXT");
                    test_error(file0 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file1 = file_open(volume, "COMMON.BIN");
                    test_error(file1 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file2 = file_open(volume, "SOME.TX");
                    test_error(file2 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file3 = file_open(volume, "HAPPEN.TXT");
                    test_error(file3 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file4 = file_open(volume, "SOUND.TXT");
                    test_error(file4 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file5 = file_open(volume, "MANY");
                    test_error(file5 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file6 = file_open(volume, "DIVIDETE.BIN");
                    test_error(file6 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
            
                size_t size0 = file_read(filecontent0, 1, 620, file0);
                test_error(size0 == 620, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 620 bajtów, a wczytała %lu", size0);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos0 = mem_find_first_difference(filecontent0, expected_filecontent0, 620);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos0 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos0, mem_get_byte(filecontent0, diff_pos0), mem_get_byte(expected_filecontent0, diff_pos0));
        
                onerror_compare_memory(expected_filecontent0, filecontent0, 620);
            
                size_t size1 = file_read(filecontent1, 1, 14273, file1);
                test_error(size1 == 14273, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 14273 bajtów, a wczytała %lu", size1);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos1 = mem_find_first_difference(filecontent1, expected_filecontent1, 14273);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos1 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos1, mem_get_byte(filecontent1, diff_pos1), mem_get_byte(expected_filecontent1, diff_pos1));
        
                onerror_compare_memory(expected_filecontent1, filecontent1, 14273);
            
                size_t size2 = file_read(filecontent2, 1, 14336, file2);
                test_error(size2 == 14336, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 14336 bajtów, a wczytała %lu", size2);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos2 = mem_find_first_difference(filecontent2, expected_filecontent2, 14336);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos2 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos2, mem_get_byte(filecontent2, diff_pos2), mem_get_byte(expected_filecontent2, diff_pos2));
        
                onerror_compare_memory(expected_filecontent2, filecontent2, 14336);
            
                size_t size3 = file_read(filecontent3, 1, 14150, file3);
                test_error(size3 == 14150, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 14150 bajtów, a wczytała %lu", size3);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos3 = mem_find_first_difference(filecontent3, expected_filecontent3, 14150);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos3 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos3, mem_get_byte(filecontent3, diff_pos3), mem_get_byte(expected_filecontent3, diff_pos3));
        
                onerror_compare_memory(expected_filecontent3, filecontent3, 14150);
            
                size_t size4 = file_read(filecontent4, 1, 6913, file4);
                test_error(size4 == 6913, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6913 bajtów, a wczytała %lu", size4);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos4 = mem_find_first_difference(filecontent4, expected_filecontent4, 6913);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos4 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos4, mem_get_byte(filecontent4, diff_pos4), mem_get_byte(expected_filecontent4, diff_pos4));
        
                onerror_compare_memory(expected_filecontent4, filecontent4, 6913);
            
                size_t size5 = file_read(filecontent5, 1, 15015, file5);
                test_error(size5 == 15015, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 15015 bajtów, a wczytała %lu", size5);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos5 = mem_find_first_difference(filecontent5, expected_filecontent5, 15015);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos5 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos5, mem_get_byte(filecontent5, diff_pos5), mem_get_byte(expected_filecontent5, diff_pos5));
        
                onerror_compare_memory(expected_filecontent5, filecontent5, 15015);
            
                size_t size6 = file_read(filecontent6, 1, 393, file6);
                test_error(size6 == 393, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 393 bajtów, a wczytała %lu", size6);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos6 = mem_find_first_difference(filecontent6, expected_filecontent6, 393);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos6 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos6, mem_get_byte(filecontent6, diff_pos6), mem_get_byte(expected_filecontent6, diff_pos6));
        
                onerror_compare_memory(expected_filecontent6, filecontent6, 393);
            

            free(filecontent0);
    free(filecontent1);
    free(filecontent2);
    free(filecontent3);
    free(filecontent4);
    free(filecontent5);
    free(filecontent6);

            file_close(file0);
    file_close(file1);
    file_close(file2);
    file_close(file3);
    file_close(file4);
    file_close(file5);
    file_close(file6);


            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 29: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST29(void)
{
    // informacje o teście
    test_start(29, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(14150, 1);
            char expected_filecontent[14151] = "";

            strcat(expected_filecontent, "ed in 1312, at\nthe age of twenty four, in consequence, as it was supposed, of\nhis extreme intemperance.\nSee Mariana, Hist I. xv.  c. 11.\n\nv. 123.  The Bohemian.]  Winceslaus II.  Purgatory, Canto VII. v.\n\nv. 125.  The halter of Jerusalem.]  Charles II of Naples and\nJerusalem who was lame.  See note to Purgatory, Canto VII.  v.\n122, and XX. v. 78.\n\nv. 127.  He.]  Frederick of Sicily son of Peter III of Arragon.\nPurgatory, Canto VII.  v. 117.  The isle of fire is Sicily, where\nwas the tomb of Anchises.\n\nv. 133.  His uncle.]  James, king of Majorca and Minorca, brother\nto Peter III.\n\nv. 133.  His brother.]  James II of Arragon, who died in 1327.\nSee Purgatory, Canto VII.  v. 117.\n\nv. 135.  Of Portugal.]  In the time of Dante, Dionysius was king\nof Portugal.  He died in 1328, after a reign of near forty-six\nyears, and does not seem to have deserved the stigma here\nfastened on him. See Mariana. and 1. xv. c. 18.  Perhaps the\nrebellious son of Dionysius may be alluded to.\n\nv. 136.  Norway.]  Haquin, king of Norway, is probably meant;\nwho, having given refuge to the murderers of Eric VII king of\nDenmark, A D. 1288, commenced a war against his successor, Erie\nVIII, \"which continued for nine years, almost to the utter ruin\nand destruction of both kingdoms.\"  Modern Univ. Hist. v. xxxii\np. 215.\n\nv. 136.  -Him\nOf Ratza.]\nOne of the dynasty of the house of Nemagna, which ruled the\nkingdom of Rassia, or Ratza, in Sclavonia, from 1161 to 1371, and\nwhose history may be found in Mauro Orbino, Regno degli Slavi,\nEdiz. Pesaro. 1601. Uladislaus appears to have been the sovereign\nin Dante\'s time, but the disgraceful forgery adverted to in the\ntext, is not recorded by the historian v. 138.  Hungary.]  The\nkingdom of Hungary was about this time disputed by Carobert, son\nof Charles Martel, and Winceslaus, prince of Bohemia, son of\nWinceslaus II.  See Coxe\'s House of Austria, vol. i. p. 1. p. 86.\n\n4to edit.\n\nv. 140.  Navarre.]  Navarre was now under the yoke of France.\n It soon after (in 1328) followed the advice of Dante and had a\nmonarch of its own.  Mariana, 1.  xv. c. 19.\n\nv. 141.  Mountainous girdle.]  The Pyrenees.\n\nv. 143.  -Famagosta\'s streets\nAnd Nicosia\'s.]\n\nCities in the kingdom of Cyprus, at that time ruled by Henry II a\npusillanimous prince. Vertot.  Hist. des Chev.  de Malte, 1. iii.\niv. The meaning appears to be, that the complaints made by those\ncities of their weak and worthless governor, may be regarded as\nan earnest of his condemnation at the last doom.\n\nCANTO XX\n\nv. 6.  Wherein one shines.]  The light of the sun, whence he\nsupposes the other celestial bodies to derive their light\n\nv. 8.  The great sign.]  The eagle, the Imperial ensign.\n\nv. 34.  Who.]  David.\n\nv. 39.  He.]  Trajan.  See Purgatory, Canto X. 68.\n\nv. 44.  He next.]  Hezekiah.\n\nv. 50.  \'The other following.]  Constantine.  There is no passage\nin which Dante\'s opinion of the evil; that had arisen from the\nmixture of the civil with the ecclesiastical power, is more\nunequivocally  declared.\n\nv. 57.  William.]  William II, king of Sicily, at the latter part\nof  the twelfth century He was of the Norman line of sovereigns,\nand obtained the appellation of \"the Good\" and, as the poet says\nhis loss was as much the subject of regret in his dominions, as\nthe presence of Charles I of Anjou and Frederick of Arragon, was\nof sorrow and complaint.\n\nv. 62.  Trojan Ripheus.]\nRipheus, justissimus unus\nQui fuit in Teneris, et servantissimus aequi.\nVirg.  Aen.  1. ii. 4--.\n\nv. 97.  This.]  Ripheus.\n\nv. 98.  That.]  Trajan.\n\nv. 103.  The prayers,] The prayers of St. Gregory\n\nv. 119.  The three nymphs.]  Faith, Hope, and Charity. Purgatory,\nCanto XXIX.  116.\nv. 138.  The pair.]  Ripheus and Trajan.\n\nCANTO XXI\n\nv. 12.  The seventh splendour.]  The planet Saturn\n\nv. 13.  The burning lion\'s breast.]  The constellation Leo.\n\nv. 21.  In equal balance.]  \"My pleasure was as great in\ncomplying\nwith her will as in beholding her countenance.\"\n\nv. 24.  Of that lov\'d monarch.]  Saturn.  Compare Hell, Canto\nXIV.  91.\n\nv. 56.  What forbade the smile.]  \"Because it would have overcome\nthee.\"\n\nv. 6");
    strcat(expected_filecontent, "1.  There aloft.]  Where the other souls were.\n\nv. 97.  A stony ridge.]  The Apennine.\n\nv. 112.  Pietro Damiano.]  \"S. Pietro Damiano obtained a great\nand well-merited reputation, by the pains he took to correct the\nabuses among the clergy.  Ravenna is supposed to have been the\nplace of his birth, about 1007.  He was employed in several\nimportant missions, and rewarded by Stephen IX with the dignity\nof cardinal, and the bishopric of Ostia, to which, however, he\npreferred his former retreat in the monastery of Fonte Aveliana,\nand prevailed on Alexander II to permit him to retire thither.\nYet he did not long continue in this seclusion, before he was\nsent on other embassies.  He died at Faenza in 1072.  His\nletters throw much light on the obscure history of these times.\nBesides them, he has left several treatises on sacred and\necclesiastical subjects. His eloquence is worthy of a better\nage.\"  Tiraboschi, Storia della Lett Ital. t. iii.  1. iv. c. 2.\n\nv. 114.  Beside the Adriatic.]  At Ravenna.  Some editions have\nFU instead of FUI, according to which reading, Pietro\ndistinguishes  himself from another Pietro, who was termed\n\"Peccator,\" the sinner.\n\nv. 117.  The hat.]  The cardinal\'s hat.\n\nv. 118.  Cephas.]  St. Peter.\n\nv. 119 The Holy Spirit\'s vessel.]  St. Paul. See Hell, Canto II.\n30.\n\nv. 130.  Round this.]  Round the spirit of Pietro Damiano.\n\nCANTO XXII\n\nv. 14.  The vengeance.]  Beatrice, it is supposed, intimates the\napproaching fate of Boniface VIII.  See Purgatory, Canto XX.  86.\n\nv. 36.  Cassino.]  A castle in the Terra di Lavoro.\n\nv. 38.  I it was.]  \"A new order of monks, which in a manner\nabsorbed all the others that were established in the west, was\ninstituted, A.D.  529, by Benedict of Nursis, a man of piety and\nreputation for the age he  lived in.\"  Maclaine\'s Mosheim,\nEccles. Hist. v. ii.  cent. vi. p. 2. ch.  2 - 6.\n\nv. 48.  Macarius.]  There are two of this name enumerated by\nMosheim among the Greek theologians of the fourth century, v. i.\ncent. iv p. 11 ch. 2 - 9.  In the following chapter, 10, it is\nsaid, \"Macarius, an Egyptian monk, undoubtedly deserves the first\nrank among the practical matters of this time, as his works\ndisplayed, some few things excepted, the brightest and most\nlovely portraiture of sanctity and virtue.\"\n\nv. 48.  Romoaldo.]  S. Romoaldo, a native of Ravenna, and the\nfounder of the order of Camaldoli, died in 1027.  He was the\nauthor of a commentary on the Psalms.\n\nv. 70.  The patriarch Jacob.]  So Milton, P. L. b. iii. 510:\nThe stairs were such, as whereon Jacob saw\nAngels ascending and descending, bands\nOf guardians bright.\n\nv. 107.  The sign.]  The constellation of Gemini.\n\nv. 130. This globe.]  So Chaucer, Troilus and Cresseide, b. v,\n\nAnd down from thence fast he gan avise\nThis little spot of earth, that with the sea\nEmbraced is, and fully gan despite\nThis wretched world.\n\nCompare Cicero, Somn. Scip.  \"Jam ipsa terra ita mihi parva visa\nest.\" &c.  Lucan, Phar 1.  ix. 11;  and Tasso, G.  L.  c.  xiv.\nst, 9, 10, 11.\n\nv. 140.  Maia and Dione.]  The planets Mercury and Venus.\n\nCANTO XXIII\n\nv. 11.  That region.]  Towards the south, where the course of the\nsun appears less rapid, than, when he is in the east or the west.\n\nv. 26.  Trivia.]  A name of Diana.\n\nv. 26.  Th\' eternal nymphs.]  The stars.\n\nv. 36.  The Might.]  Our Saviour\n\nv. 71.  The rose.]  The Virgin Mary.\n\nv. 73.  The lilies.]  The apostles.\n\nv. 84.  Thou didst exalt thy glory.]  The diving light retired\nupwards, to render the eyes of Dante more capable of enduring the\nspectacle  which now presented itself.\n\nv. 86.  The name of that fair flower.]  The name of the Virgin.\n\nv. 92.  A cresset.]  The angel Gabriel.\n\nv. 98.  That lyre.]  By synecdoche, the lyre is put for the angel\n\nv. 99.  The goodliest sapphire.]  The Virgin\n\nv. 126.  Those rich-laden coffers.]  Those spirits who, having\nsown the seed of good works on earth, now contain the fruit of\ntheir pious endeavours.\n\nv. 129.  In the Babylonian exile.]  During their abode in this\nworld.\n\nv. 133.  He.]  St. Peter, with the other holy men of the Old and\nNew testament.\n\nC");
    strcat(expected_filecontent, "ANTO XXIV\n\nv. 28.  Such folds.]  Pindar has the same bold image:\n[GREEK HERE?]\nOn which Hayne strangely remarks:  Ad ambitus stropharum vldetur\n\nv. 65.  Faith.]  Hebrews, c.  xi.  1.  So Marino, in one of his\nsonnets, which calls Divozioni:\n\nFede e sustanza di sperate cose,\nE delle non visioili argomento.\n\nv. 82.  Current.]  \"The answer thou hast made is right; but let\nme know if thy inward persuasion is conformable to thy\nprofession.\"\n\nv. 91.  The ancient bond and new.]  The Old and New Testament.\n\nv. 114.  That Worthy.]  Quel Baron.\nIn the next Canto, St. James is called \"Barone.\"  So in\nBoccaccio, G. vi. N. 10, we find \"Baron Messer Santo Antonio.\"\nv. 124.  As to outstrip.]  Venturi insists that the Poet has\nhere, \"made a slip;\" for that John came first to the sepulchre,\nthough Peter was the first to enter it.  But let Dante have leave\nto explain his own meaning, in a passage from his third book De\nMonarchia:  \"Dicit etiam Johannes ipsum (scilicet Petrum)\nintroiisse SUBITO, cum venit in monumentum, videns allum\ndiscipulum cunctantem ad ostium.\" Opere de Dante, Ven. 1793. T.\nii. P. 146.\n\nCANTO XXV\n\nv. 6.  The fair sheep-fold.]  Florence, whence he was banished.\n\nv. 13.  For its sake.]  For the sake of that faith.\n\nv. 20.  Galicia throng\'d with visitants.] See Mariana, Hist. 1.\nxi.\n\nv. 13.  \"En el tiempo,\" &c.  \"At the time that the sepulchre of\nthe apostle St. James was discovered, the devotion for that place\nextended itself not only over all Spain, but even round about to\nforeign nations. Multitudes from all parts of the world came to\nvisit it.  Many others were deterred by the difficulty for the\njourney, by the roughness and barrenness of those parts, and by\nthe incursions of the Moors, who made captives many of the\npilgrims.  The canons of St. Eloy afterwards (the precise time is\nnot known), with a desire of remedying these evils, built, in\nmany places, along the whole read, which reached as far as to\nFrance, hospitals for the reception of the pilgrims.\"\n\nv. 31.  Who.]  The Epistle of St. James is here attributed to the\nelder apostle of that name, whose shrine was at Compostella, in\nGalicia.  Which of the two was the author of it is yet doubtful.\nThe learned and candid Michaelis contends very forcibly for its\nhaving been written by James the Elder.  Lardner rejects that\nopinion as absurd; while Benson argues against it, but is well\nanswered by Michaelis, who after all, is obliged to leave the\nquestion undecided.  See his Introduction to the New Testament,\ntranslated by Dr. Marsh, ed.  Cambridge, 1793.  V. iv. c.  26.  -\n1, 2, 3.\n\nv. 35.  As Jesus.]  In the transfiguration on Mount Tabor.\n\nv. 39.  The second flame.]  St. James.\n\nv. 40.  I lifted up.]  \"I will lift up mine eyes unto the hills,\nfrom whence cometh my help.\"  Ps.  Cxxi.  1.\n\nv. 59.  From Egypt to Jerusalem.]  From the lower world to\nheaven.\n\nv. 67.  Hope.]  This is from the Sentences of Petrus Lombardus.\n\"Est autem spes virtus, qua spiritualia et aeterna bona speratam,\nid  est, beatitudinem aeternam.  Sine meritis enim aliquid\nsperare non spes, sed praesumptio, dici potest.\"  Pet. Lomb.\nSent.  1.  Iii.  Dist.  26.   Ed. Bas.  1486.  Fol.\n\nv. 74.  His anthem.]  Psalm ix.  10.\n\nv. 90.  Isaias ]  Chap. lxi. 10.\n\nv. 94.  Thy brother.]  St. John in the Revelation, c. vii.  9.\n\nv. 101.  Winter\'s month.]  \"If a luminary, like that which now\nappeared, were to shine throughout the month following the winter\nsolstice during which the constellation Cancer appears in the\neast at the setting of the sun, there would be no interruption to\nthe light, but the whole month would be as a single day.\"\n\nv. 112.  This.]  St. John, who reclined on the bosom of our\nSaviour, and to whose charge Jesus recommended his mother.\n\nv. 121.  So I.]  He looked so earnestly, to descry whether St.\nJohn were present there in body, or in spirit only, having had\nhis doubts raised  by that saying of our Saviour\'s:  \"If I will,\nthat he tarry till I come  what is that to thee.\"\n\nv. 127.  The two.]  Christ and Mary, whom he has described, in\nthe last Canto but one, as rising above his sight\n\nCANT");
    strcat(expected_filecontent, "O XXVI\n\nv. 2.  The beamy flame.]  St. John.\n\nv. 13.  Ananias\' hand.]  Who, by putting his hand on St. Paul,\nrestored his sight.  Acts, c. ix.  17.\n\nv. 36.  From him.]  Some suppose that Plato is here meant, who,\nin his Banquet, makes Phaedrus say:  \"Love is confessedly amongst\nthe eldest of beings, and, being the eldest, is the cause to us\nof the greatest goods \" Plat. Op. t. x. p. 177.  Bip.  ed. Others\nhave understood it of Aristotle, and others, of the writer who\ngoes by the name of Dionysius the Areopagite, referred to in the\ntwenty-eighth Canto.\n\nv. 40.  I will make.]  Exodus, c. xxxiii. 19.\n\nv. 42.  At the outset.]  John, c. i. 1.  &c.\n\nv. 51.  The eagle of our Lord.]  St. John\n\nv. 62.  The leaves.]  Created beings.\n\nv. 82.  The first living soul.]  Adam.\n\nv. 107.  Parhelion.]  Who enlightens and comprehends all things;\nbut is himself enlightened and comprehended by none.\n\nv. 117.  Whence.]  That is, from Limbo.  See Hell, Canto II.  53.\nAdam says that 5232 years elapsed from his creation to the time\nof his deliverance, which followed the death of Christ.\n\nv. 133.  EL]  Some read UN, \"One,\" instead of EL:  but the latter\nof these readings is confirmed by a passage from Dante\'s Treatise\nDe Vulg. Eloq. 1. i. cap. 4. \"Quod prius vox primi loquentis\nsonaverit, viro sanae mentis in promptu esse non dubito ipsum\nfuisse quod Deus est, videlicet El.\"  St. Isidore in the\nOrigines, 1.  vii. c. 1. had said, \"Primum apud Hebraeos Dei\nnomen El dicitur.\"\n\nv. 135.  Use.]  From Horace, Ars. Poet. 62.\n\nv. 138.  All my life.]  \"I remained in the terrestrial Paradise\nonly tothe seventh hour.\"  In the Historia Scolastica of Petrus\nComestor, it is said of our first parents:  Quidam tradunt eos\nfuisse in Paradiso septem horae.\"  I. 9. ed. Par. 1513. 4to.\n\nCANTO XXVII\n\nv.  1.  Four torches.]  St. Peter, St. James, St. John, and Adam.\n\nv. 11.  That.] ");

            struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "HAPPEN.TXT");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 2339, SEEK_SET);
        
            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[2339] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[2339], c);

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
//  Test 30: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST30(void)
{
    // informacje o teście
    test_start(30, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(620, 1);
            char expected_filecontent[621] = "";

            strcat(expected_filecontent, "pass\'d me speechless by; and doing so\nHath made me more compassionate his fate.\"\n     So we discours\'d to where the rock first show\'d\nThe other valley, had more light been there,\nE\'en to the lowest depth.  Soon as we came\nO\'er the last cloister in the dismal rounds\nOf Malebolge, and the brotherhood\nWere to our view expos\'d, then many a dart\nOf sore lament assail\'d me, headed all\nWith points of thrilling pity, that I clos\'d\nBoth ears against the volley with mine hands.\n     As were the torment, if each lazar-house\nOf Valdichiana, in the sultry time\n\'Twixt July and September, with the isle\nSardinia and Maremma\'s pe");

            struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "WANT.TXT");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, -343, SEEK_END);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[277] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[277], c);

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
//  Test 31: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST31(void)
{
    // informacje o teście
    test_start(31, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(15015, 1);
            char expected_filecontent[15016] = "";

            strcat(expected_filecontent, "ges, till he arrives in a beautiful valley\ncovered with flowers on all sides, and the richest in the world;\nbut which was continually  shifting its appearance from a round\nfigure to a square, from obscurity to light, and from\npopulousness to solitude.  This is the region of Pleasure, or\nCupid, who is accompanied by four ladies, Love, Hope, Fear, and\nDesire.  In one part of it he meets with Ovid, and is instructed\nby him how to conquer the passion of love, and to escape from\nthat place.  After his escape he makes his confession to a friar,\nand then returns to the forest of visions:  and ascending a\nmountain, he meets with Ptolemy, a venerable old man.  Here the\nnarrative breaks off. The  poem ends, as it began, with an\naddress to Rustico di Filippo, on whom he lavishes every sort of\npraise.\n\nIt has been observed, that Dante derived the idea of opening his\npoem by describing himself as lost in a wood, from the Tesoretto\nof his master.  I know not whether it has been remarked, that the\ncrime of usury is branded by both these poets as offensive to God\nand Nature:  or that the sin for which Brunetto is condemned by\nhis pupil, is mentioned in the Tesoretto with great horror.\nDante\'s twenty-fifth sonnet is a jocose one, addressed to\nBrunetto.  He died in 1295.\n\nv. 62.  Who in old times came down from Fesole.]  See G. Villani\nHist. l. iv. c. 5. and Macchiavelli Hist. of Flor. b. ii.\n\nv. 89.  With another text.]  He refers to the prediction of\nFarinata, in Canto X.\n\nv. 110.  Priscian.]  There is no reason to believe, as the\ncommentators observe that the grammarian of this name was stained\nwith the vice imputed to him; and we must therefore suppose that\nDante puts the individual for the species, and implies the\nfrequency of the crime among those who abused the opportunities\nwhich the education of youth afforded them, to so abominable a\npurpose.\n\nv. 111.  Francesco.]  Son of Accorso, a Florentine, celebrated\nfor his skill in jurisprudence, and commonly known by the name of\nAccursius.\n\nv. 113.  Him.]  Andrea de\' Mozzi, who, that his scandalous life\nmight be less exposed to observation, was translated either by\nNicholas III, or Boniface VIII from the see of Florence to that\nof Vicenza, through which passes the river Baccchiglione.  At the\nlatter of these places he died.\n\nv. 114.  The servants\' servant.]  Servo de\' servi.  So Ariosto,\nSat. 3.\n               Degli servi\n        Io sia il gran servo.\n\nv. 124.  I commend my Treasure to thee.]  Brunetto\'s great work,\nthe Tresor.\nSieti raccomandato \'l mio Tesoro.\nSo Giusto de\' Conti, in his Bella Mano, Son.  \"Occhi:\"\n        Siavi raccommandato il mio Tesoro.\n\nCANTO XVI\n\nv. 38.  Gualdrada.]  Gualdrada was the daughter of Bellincione\nBerti, of whom mention is made in the Paradise, Canto XV, and\nXVI.  He was of the family of Ravignani, a branch of the Adimari.\n\nThe Emperor Otho IV. being at a festival in Florence, where\nGualdrada was present, was struck with her beauty; and inquiring\nwho she was, was answered by Bellincione, that she was the\ndaughter of one who, if it was his Majesty\'s pleasure, would make\nher admit the honour of his salute.  On overhearing this, she\narose from her seat, and blushing, in an animated tone of voice,\ndesired her father that he would not be so liberal in his offers,\nfor that no man should ever be allowed that freedom, except him\nwho should be her lawful husband.  The Emperor was not less\ndelighted by her resolute modesty than he had before been by the\nloveliness of her person, and calling to him Guido, one of his\nbarons, gave her to him in marriage, at the same time raising him\n\nto the rank of a count, and bestowing on her the whole of\nCasentino, and a part of the territory of Romagna, as her\nportion.  Two sons were the offspring of this union, Guglielmo\nand Ruggieri, the latter of whom was father of Guidoguerra, a man\nof great military skill and prowess who, at the head of four\nhundred Florentines of the Guelph party, was signally\ninstrumental to the victory obtained at Benevento by Charles of\nAnjou, over Manfredi, King of Naples, in 1265.   One of the\nconsequ");
    strcat(expected_filecontent, "ences of this victory was the expulsion of the Ghibellini,\nand the re-establishment of the Guelfi at Florence.\n\nv. 39.  Many a noble act.]  Compare Tasso, G. L. c. i. st. 1.\n\nv. 42.  Aldobrandiu]  Tegghiaio Aldobrandi was of the noble\nfamily of Adimari, and much esteemed for his military talents.\nHe endeavored to dissuade the Florentines from the attack, which\nthey meditated against the Siennese, and the rejection of his\ncounsel occasioned the memorable defeat, which the former\nsustained at Montaperto, and the consequent banishment of the\nGuelfi from Florence.\n\nv. 45.  Rusticucci.]  Giacopo Rusticucci, a Florentine,\nremarkable for his opulence and the generosity of his spirit.\n\nv. 70.  Borsiere.]  Guglielmo Borsiere, another Florentine, whom\nBoccaccio, in a story which he relates of him, terms \"a man of\ncourteous and elegant manners, and of great readiness in\nconversation.\"  Dec. Giorn. i. Nov. 8.\n\nv. 84.  When thou with pleasure shalt retrace the past.]\n        Quando ti giovera dicere io fui.\nSo Tasso, G. L. c. xv. st. 38.\n        Quando mi giovera narrar altrui\n        Le novita vedute, e dire; io fui.\n\nv. 121.  Ever to that truth.]  This memorable apophthegm is\nrepeated by Luigi Pulci and Trissino.\n\n        Sempre a quel ver, ch\' ha faccia di menzogna\n        E piu senno tacer la lingua cheta\n        Che spesso senza colpa fa vergogna.\n               Morgante. Magg.  c. xxiv.\n\n               La verita, che par mensogna\n        Si dovrebbe tacer dall\' uom ch\'e saggio.\n               Italia. Lib. C. xvi.\n\nCANTO XVII\n\nv. 1.  The fell monster.]  Fraud.\n\nv. 53.  A pouch.]  A purse, whereon the armorial bearings of each\nwere emblazoned.  According to Landino, our poet implies that the\nusurer can pretend to no other honour, than such as he derives\nfrom his purse and his family.\n\nv. 57.  A yellow purse.]  The arms of the Gianfigliazzi of\nFlorence.\n\nv. 60.  Another.]  Those of the Ubbriachi, another Florentine\nfamily of high distinction.\n\nv. 62.  A fat and azure swine.]  The arms of the Scrovigni a\nnoble family of Padua.\n\nv. 66.  Vitaliano.]  Vitaliano del Dente, a Paduan.\n\nv. 69.  That noble knight.]  Giovanni Bujamonti, a Florentine\nusurer, the most infamous of his time.\n\nCANTO XVIII\n\nv. 28.  With us beyond.]  Beyond the middle point they tended the\nsame way with us, but their pace was quicker than ours.\n\nv. 29.  E\'en thus the Romans.]  In the year 1300, Pope Boniface\nVIII., to remedy the inconvenience occasioned by the press of\npeople who were passing over the bridge of St. Angelo during the\ntime of the Jubilee, caused it to be divided length wise by a\npartition, and ordered, that all those who were going to St.\nPeter\'s should keep one side, and those returning the other.\n\nv. 50.  Venedico.]  Venedico Caccianimico, a Bolognese, who\nprevailed on his sister Ghisola to prostitute herself to Obizzo\nda  Este, Marquis of Ferrara, whom we have seen among the\ntyrants, Canto XII.\n\nv. 62.  To answer Sipa.]  He denotes Bologna by its situation\nbetween the rivers Savena to the east, and Reno to the west of\nthat city; and by a peculiarity of dialect, the use of the\naffirmative sipa instead of si.\n\nv. 90.  Hypsipyle.]  See Appolonius Rhodius, l. i. and Valerius\nFlaccus l.ii.  Hypsipyle deceived the other women by concealing\nher father Thoas, when they had agreed to put all their males to\ndeath.\n\nv. 120.  Alessio.]  Alessio, of an ancient and considerable\nfamily in Lucca, called the Interminei.\n\nv. 130.  Thais.]  He alludes to that passage in the Eunuchus of\nTerence where Thraso asks if Thais was obliged to him for the\npresent he had sent her, and Gnatho replies, that she had\nexpressed her obligation in the most forcible terms.\n        T.  Magnas vero agere gratias Thais mihi?\n        G.  Ingentes.\n               Eun. a. iii. s. i.\n\nCANTO XIX\n\nv. 18.  Saint John\'s fair dome.]  The apertures in the  rock were\nof the same dimensions as the fonts of St. John the Baptist at\nFlorence, one of which, Dante says he had broken, to rescue a\nchild  that was playing near and fell in. He intimates that the\nmotive of his  breaking the font had been m");
    strcat(expected_filecontent, "aliciously represented\nby his enemies.\n\nv. 55.  O Boniface!]  The spirit mistakes Dante for  Boniface\nVIII. who was then alive, and who he did not expect would have\narrived so soon, in consequence, as it should seem, of a\nprophecy, which  predicted the death of that Pope at a later\nperiod. Boniface died in  1303.\n\nv. 58.  In guile.]  \"Thou didst presume to arrive by fraudulent\nmeans at the papal power, and afterwards to abuse it.\"\n\nv. 71.  In the mighty mantle I was rob\'d.]  Nicholas III, of the\nOrsini family, whom the poet therefore calls \"figliuol dell\'\norsa,\" \"son of the she-bear.\"  He died in 1281.\n\nv. 86.  From forth the west, a shepherd without law.]   Bertrand\nde Got Archbishop of Bordeaux, who succeeded to the pontificate\nin 1305, and assumed the title of Clement V. He transferred the\nholy  see to Avignon in 1308 (where it remained till 1376), and\ndied in 1314.\n\nv. 88.  A new Jason.]  See Maccabees, b. ii. c. iv. 7,8.\n\nv. 97.  Nor Peter.]  Acts of the Apostles, c.i. 26.\n\nv. 100.  The condemned soul.]  Judas.\n\nv. 103.  Against Charles.]  Nicholas III. was enraged against\nCharles I, King of Sicily, because he rejected with scorn a\nproposition made by that Pope for an alliance between their\nfamilies.  See G. Villani, Hist. l. vii. c. liv.\n\nv. 109.  Th\' Evangelist.]  Rev. c. xvii. 1, 2, 3.  Compare\nPetrarch.  Opera fol. ed. Basil. 1551. Epist. sine titulo liber.\nep. xvi. p. 729.\n\nv. 118.  Ah, Constantine.]  He alludes to the pretended gift of\nthe Lateran by Constantine to Silvester, of which Dante himself\nseems to imply a doubt, in his treatise \"De Monarchia.\" - \"Ergo\nscindere Imperium, Imperatori non licet.  Si ergo aliquae,\ndignitates per Constantinum essent alienatae, (ut dicunt) ab\nImperio,\" &c. l. iii.\nThe gift is by Ariosto very humorously placed in the moon, among\nthe things lost or abused on earth.\n        Di varj fiori, &c.\n               O. F. c. xxxiv. st. 80.\n\nMilton has translated both this passage and that in the text.\nProse works, vol. i. p. 11. ed. 1753.\n\nCANTO XX\n\nv. 11.  Revers\'d.]  Compare Spenser, F. Q. b. i. c. viii.  st. 31\n\nv. 30.  Before whose eyes.]  Amphiaraus, one of the seven kings\nwho besieged Thebes.  He is said to have been swallowed up by  an\nopening of the earth.  See Lidgate\'s Storie of Thebes, Part III\nwhere it is told how the \"Bishop Amphiaraus\" fell down to hell.\n        And thus the devill for his outrages,\n        Like his desert payed him his wages.\nA different reason for his being doomed thus to perish is\nassigned by Pindar.\n[GREEK HERE]\n               Nem ix.\n\n        For thee, Amphiaraus, earth,\n        By Jove\'s all-riving thunder cleft\n        Her mighty bosom open\'d wide,\n        Thee and thy plunging steeds to hide,\n        Or ever on thy back the spear\n        Of Periclymenus impress\'d\n        A wound to shame thy warlike breast\n        For struck with panic fear\n        The gods\' own children flee.\n\nv. 37.  Tiresias.]\n        Duo magnorum viridi coeuntia sylva\n        Corpora serpentum baculi violaverat ictu, &c.\n               Ovid. Met. iii.\n\nv. 43.  Aruns.]  Aruns is said to have dwelt in the  mountains of\nLuni (from whence that territory is still called Lunigiana),\nabove Carrara, celebrated for its marble.  Lucan. Phars. l. i.\n575.  So Boccaccio in the Fiammetta, l. iii.  \"Quale Arunte,\" &c.\n\n\"Like Aruns, who amidst the white marbles of Luni, contemplated\nthe celestial bodies and their motions.\"\n\nv. 50.  Manto.]  The daughter of Tiresias of Thebes, a city\ndedicated to Bacchus.  From Manto Mantua, the country of Virgil\nderives its name. The Poet proceeds to describe the situation of\nthat place.\n\nv. 61.  Between the vale.]  The lake Benacus, now called  the\nLago di Garda, though here said to lie between Garda, Val\nCamonica, and the Apennine, is, however, very distant from the\nlatter two\n\nv. 63.  There is a spot.]  Prato di Fame, where the dioceses of\nTrento, Verona, and Brescia met.\n\nv. 69.  Peschiera.]  A garrison situated to the south of the\nlake, where it empties itself and forms the Mincius.\n\nv. 94.  Casalodi\'s madness.]  Alberto da Casalodi, who had got\npossess");
    strcat(expected_filecontent, "ion of Mantua, was persuaded by Pinamonte Buonacossi, that\nhe might ingratiate himself with the people by banishing to their\n\nown castles the nobles, who were obnoxious to them.  No sooner\nwas this done, than Pinamonte put himself at the head of the\npopulace, drove out Casalodi and his adherents, and obtained the\nsovereignty for himself.\n\nv. 111.  So sings my tragic strain.]\n        Suspensi Eurypilum scitatum oracula Phoebi\n        Mittimus.\n               Virg. Aeneid. ii. 14.\n\nv. 115.  Michael Scot.]  Sir Michael Scott, of Balwearie,\nastrologer to the Emperor Frederick II. lived in the thirteenth\ncentury.  For further particulars relating to this singular man,\nsee Warton\'s History of English Poetry, vol. i. diss. ii. and\nsect. ix.  p 292, and the Notes to Mr. Scott\'s \"Lay of the Last\nMinstrel,\" a  poem in which a happy use is made of the traditions\nthat are still current in North Britain concerning him.  He is\nmentioned by G. Villani. Hist. l. x. c. cv. and cxli. and l. xii.\nc. xviii. and by Boccaccio, Dec. Giorn. viii. Nov. 9.\n\nv. 116.  Guido Bonatti.]  An astrologer of Forli, on whose  skill\nGuido da Montefeltro, lord of that place, so much relied, that he\nis reported never to have gone into battle, except in the hour\nrecommended to him as fortunate by Bonatti.\n\nLandino and Vellutello, speak of a book, which he composed on the\nsubject of his art.\n\nv. 116.  Asdente.]  A shoemaker at Parma, who deserted his\nbusiness to practice the arts of divination.\n\nv. 123.  Cain with fork of thorns.]  By Cain and the thorns, or\nwhat is still vulgarly called the Man in the Moon, the Poet\ndenotes that luminary.  The same superstition is alluded to in\nthe Paradise, Canto II. 52.  The curious reader may consult Brand\non Popular Antiquities, 4to.  1813. vol. ii. p. 476.\n\nCANTO XXI\n\nv. 7.  In the Venetians\' arsenal.]  Compare Ruccellai, Le  Api,\n165, and Dryden\'s Annus Mirabilis, st. 146, &c.\n\nv. 37.  One of Santa Zita\'s elders.]  The elders or chief\nmagistrates of Lucca, where Santa Zita was held in especial\nveneration.  The name of this sinner is supposed to have been\nMartino Botaio.\n\nv. 40.  Except Bonturo, barterers.]  This is said ironically of\nBonturo de\' Dati.  By barterers are meant peculators, of every\ndescription; all who traffic the interests of the public  for\ntheir own private advantage.\n\nv. 48.  Is other swimming than in Serchio\'s wave.]\n        Qui si nuota altrimenti che nel Serchio.\nSerchio is the river that flows by Lucca.  So Pulci, Morg. Mag.\nc. xxiv.\n        Qui si nuota nel sangue, e non nel Serchio.\n\nv. 92.  From Caprona.]  The surrender of the castle of Caprona to\nthe combined forces of Florence and Lucca, on condition that the\ngarrison should march out in safety, to which ");

            struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "MANY");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 1297, SEEK_SET);
            file_seek(file, 4108, SEEK_CUR);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[5405] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[5405], c);

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
//  Test 32: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST32(void)
{
    // informacje o teście
    test_start(32, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "CLEAR");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (CLEAR) jest nazwą katalogu, a nie pliku");
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
//  Test 33: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST33(void)
{
    // informacje o teście
    test_start(33, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "COAT");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (COAT) jest nazwą katalogu, a nie pliku");
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
//  Test 34: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST34(void)
{
    // informacje o teście
    test_start(34, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "WRONG");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (WRONG) jest nazwą katalogu, a nie pliku");
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
    

                 struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "PERSON");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (PERSON) jest nazwą katalogu, a nie pliku");
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
    

                 struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "ALSO");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (ALSO) jest nazwą katalogu, a nie pliku");
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
    

                 struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "SKILL");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (SKILL) jest nazwą katalogu, a nie pliku");
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
    

                 struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "WRITE");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (WRITE) jest nazwą katalogu, a nie pliku");
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
    

                 struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "THINABOV");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (THINABOV) jest nazwą katalogu, a nie pliku");
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
    

            struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "GARDEN.TXT");
            test_error(file == NULL, "Funkcja file_open() nie powinna otworzyć pliku o nazwie GARDEN.TXT, ponieważ nie istnieje on w katalogu głównym");
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
    

            struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(NULL, "GARDEN.TXT");
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
    

            struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
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
    

            struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
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
//  Test 44: Sprawdzanie poprawności działania funkcji file_close
//
void UTEST44(void)
{
    // informacje o teście
    test_start(44, "Sprawdzanie poprawności działania funkcji file_close", __LINE__);

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
    

            struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "WANT.TXT");
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
//  Test 46: Sprawdzanie poprawności działania funkcji dir_read
//
void UTEST46(void)
{
    // informacje o teście
    test_start(46, "Sprawdzanie poprawności działania funkcji dir_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char* expected_names[15] = { "WANT.TXT", "COMMON.BIN", "SOME.TX", "HAPPEN.TXT", "SOUND.TXT", "MANY", "DIVIDETE.BIN", "CLEAR", "COAT", "WRONG", "PERSON", "ALSO", "SKILL", "WRITE", "THINABOV" };
            int found_names[15] = { 0 };

            struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t* pdir = dir_open(volume, "\\");
            test_error(pdir != NULL, "Funkcja dir_open() niepoprawnie otworzyła katalog");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            for (int i = 0; i < 15; ++i)
            {
                struct dir_entry_t entry;
                int res = dir_read(pdir, &entry);
                test_error(res == 0, "Funkcja dir_read() niepoprawnie odczytała wpis z katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int name_found = 0;

                for (int j = 0; j < 15; ++j)
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
//  Test 47: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST47(void)
{
    // informacje o teście
    test_start(47, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "WANT.TXT");
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
//  Test 48: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST48(void)
{
    // informacje o teście
    test_start(48, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "COMMON.BIN");
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
//  Test 49: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST49(void)
{
    // informacje o teście
    test_start(49, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "SOME.TX");
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
    

                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "HAPPEN.TXT");
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
    

                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "SOUND.TXT");
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
    

                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "MANY");
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
    

                struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "DIVIDETE.BIN");
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
    

            struct disk_t* disk = disk_open_from_file("cent_fat12_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t*  dir = dir_open(volume, "center");
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
            UTEST29, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST30, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST31, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST32, // Sprawdzanie poprawności działania funkcji file_open
            UTEST33, // Sprawdzanie poprawności działania funkcji file_open
            UTEST34, // Sprawdzanie poprawności działania funkcji file_open
            UTEST35, // Sprawdzanie poprawności działania funkcji file_open
            UTEST36, // Sprawdzanie poprawności działania funkcji file_open
            UTEST37, // Sprawdzanie poprawności działania funkcji file_open
            UTEST38, // Sprawdzanie poprawności działania funkcji file_open
            UTEST39, // Sprawdzanie poprawności działania funkcji file_open
            UTEST40, // Sprawdzanie poprawności działania funkcji file_open
            UTEST41, // Sprawdzanie poprawności działania funkcji file_read
            UTEST42, // Sprawdzanie poprawności działania funkcji file_read
            UTEST43, // Sprawdzanie poprawności działania funkcji file_read
            UTEST44, // Sprawdzanie poprawności działania funkcji file_close
            UTEST45, // Sprawdzanie poprawności działania funkcji file_read
            UTEST46, // Sprawdzanie poprawności działania funkcji dir_read
            UTEST47, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST48, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST49, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST50, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST51, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST52, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST53, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST54, // Sprawdzanie poprawności działania funkcji dir_open
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
            test_summary(54); // wszystkie testy muszą zakończyć się sukcesem
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