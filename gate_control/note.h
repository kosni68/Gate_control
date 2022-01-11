https://www.arduino.cc/reference/en/


//   différents types de variables :       
      
      boolean           1octet       valeur :               0 ou 1
      char              1octet       valeur :            -128 à +128
      byte              1octet       valeur :               0 à 255
      int               2octets      valeur :         -32 768 à +32 767
      unsigned int      2octets      valeur :               0 à 65 536
      long              4octets      valeur :  -2 147 483 648 à 2 147 483 647
      unsigned long     4octets      valeur :               0 à 4 294 967 295
      float             4octets      valeur :  -3.4028235E+38 à +3.4028235E+38
      double            4octets      valeur :  -3.4028235E+38 à +3.4028235E+38
      String            8octets      chaine de caractères 
//

// Structure

 break 
      break est utilisé pour la sortie d'un for, while ou do…​while boucle,
      sans passer par létat de la boucle normale.
      Il est également utilisé pour quitter une switch caseinstruction.

      int threshold = 40;
      for (int x = 0; x < 255; x++) {
         analogWrite(PWMpin, x);
         sens = analogRead(sensorPin);
         if (sens > threshold) {     // bail out on sensor detect
            x = 0;
            break;
         }
         delay(50);
      }
 //

 continue 
      continue ignore le reste de litération courante d'une boucle ( for, whileou do…​while).
      Il continue en vérifiant lexpression conditionnelle de la boucle et en procédant à toutes les itérations suivantes.

      for (int x = 0; x <= 255; x ++) {
         if (x > 40 && x < 120) {  // create jump in values
         continue;
      }
 //

 do...while 
      La boucle do…​while  fonctionne de la même manière que la boucle while,
      à lexception que la condition est testée à la fin de la boucle,
      de sorte que la boucle do sexécutera toujours au moins une fois.

      int x = 0;
      do {
         delay(50);          // wait for sensors to stabilize
         x = readSensors();  // check the sensors
      } while (x < 100);
 //

 else 
      Le if…​else permet un meilleur contrôle du flux de code que if seul ,
       en permettant de regrouper plusieurs tests.

      if (temperature >= 70) {
         // Danger! Shut down the system.
      }
      else if (temperature >= 60) { // 60 <= temperature < 70
         // Warning! User attention required.
      }
      else { // temperature < 60
         // Safe! Continue usual tasks.
      }
 //

 for 
      Linstruction for est utilisée pour répéter un bloc d'instructions entre accolades. 
      Un compteur d'incrément est généralement utilisé pour incrémenter et terminer la boucle.
      Linstruction for est utile pour toute opération répétitive et est souvent utilisée en combinaison avec des tableaux pour fonctionner sur des collections de données / broches.
      
      for (int i = 0; i <= 255; i++)
 //

 goto 
      Transfère le flux du programme vers un point étiqueté du programme

      goto bailout;
      ...
      bailout:
 //

 if 
      if instruction vérifie une condition et exécute linstruction en cours ou un ensemble d'instructions si la condition est «vraie».

      if (x > 120) digitalWrite(LEDpin, HIGH);
 //

 return 
      Terminez une fonction et renvoyez une valeur d'une fonction à la fonction appelante, si vous le souhaitez.

      int checkSensor() {
         if (analogRead(0) > 400) {
            return 1;
         }
         else {
            return 0;
         }
      }
 //

 switch...case 
      Comme les instructions if , switch case contrôle le flux des programmes en permettant aux programmeurs de spécifier
      un code différent qui doit être exécuté dans diverses conditions. 

         switch (var) {
      case label1:
         // statements
         break;
      case label2:
         // statements
         break;
      default:
         // statements
         break;
      }
 //

 while 
      Une whileboucle bouclera en continu, et à linfini, jusquà ce que lexpression à lintérieur de la parenthèse,
      () devienne fausse.

      var = 0;
      while (var < 200) {
          // do something repetitive 200 times
      var++;
      }
 //


// Opérateurs de comparaison :

   if (x != y)  // != (différent de) 

   if (x < y)  //<(inférieur à) 

   if (x <= y)  //<= (inférieur ou égal à) 

   if (x == y)  //== (égal à) 

   if (x > y)  //> (supérieur à) 
      
   if (x >= y)  //>= (supérieur ou égal à) 
//


//Opérateurs booléens

   ! (NON logique) 
   x =! y; // x devient l'inverse de y 

   && (ET logique) 
   if (digitalRead(2) == HIGH && digitalRead(3) == HIGH) // ET logique ne résulte true que si les deux opérandes le sont true.

   || (OU logique) 
   if (x > 0 || y > 0) // OU logique résulte en un true si l'un des deux opérandes l'est true.
//

//Opérateurs composés

   % = (reste composé) //modulo
      int x = 7;
      x %= 5;    // x now contains 2

   & = (composé au niveau du bit et)
      x &= y; // equivalent to x = x & y;

   * = (multiplication composée) 
      x *= y; // equivalent to the expression x = x * y;

      x = 2;
      x *= 2; // x now contains 4

   ++ (incrément)

      x = 2;
      y = ++x;  // x now contains 3, y contains 3
      y = x++;  // x contains 4, but y still contains 3

   += (addition composée)
      x += y; // equivalent to the expression x = x + y; 

      x = 2;
      x += 4; // x now contains 6

   - (décrément) 

      x = 2;
      y = --x;  // x now contains 1, y contains 1
      y = x--;  // x contains 0, but y still contains 1

   -= (soustraction composée) 
      x -= y; // equivalent to the expression x = x - y;

      x = 20;
      x -= 2; // x now contains 18

   /= (division composée) 
      x /= y; // equivalent to the expression x = x / y;

      x = 2;
      x /= 2; // x now contains 1

   ^= ( composé au niveau du bit xor) 

      x ^= y; // equivalent to x = x ^ y;

   |= (composé au niveau du bit ou) 

      x |= y; // equivalent to x = x | y;
//

//Opérateurs d'accès au pointeur

   & (opérateur de référence) 
      int *p;       // declare a pointer to an int data type
      int i = 5;
      int result = 0;
      p = &i;       // now 'p' contains the address of 'i'
      result = *p;  // 'result' gets the value at the address pointed by 'p'
              // i.e., it gets the value of 'i' which is 5

   * (opérateur de déréférence) 
      int *p;       // declare a pointer to an int data type
      int i = 5;
      int result = 0;
      p = &i;       // now 'p' contains the address of 'i'
      result = *p;  // 'result' gets the value at the address pointed by 'p'
                 // i.e., it gets the value of 'i' which is 5
//


// Opérateurs au niveau du bit

   & (au niveau du bit et)

      0 0 1 1 opérande1
      0 1 0 1 opérande2
      ----------
      0 0 0 1 (opérande1 et opérande2) - résultat renvoyé

   << (décalage du bit à gauche) 

      int a = 5;      // binary: 0000000000000101
      int b = a << 3; // binary: 0000000000101000, or 40 in decimal

   >> (décalage du bit à droite) 

      int a = 40;     // binary: 0000000000101000
      int b = a >> 3; // binary: 0000000000000101, or 5 in decimal

   ^ (xor au niveau du bit)

      0 0 1 1 opérande1
      0 1 0 1 opérande2
      ----------
      0 1 1 0 (opérande1 ^ opérande2) - résultat renvoyé

   | (au niveau du bit ou) 

      0 0 1 1 opérande1
      0 1 0 1 opérande2
      ----------
      0 1 1 1 (opérande1 | opérande2) - résultat renvoyé
   
   ~ (au niveau du bit pas) 

      0 1 opérande1
      -----
      1 0 ~ opérande1
//


/*table ascii ( 0 - 127 )

       Décimal   Octal   Hex  Binaire   Caractère
       -------   -----   ---  --------    ------
         000      000    00   00000000      NUL    (Null char.)
         001      001    01   00000001      SOH    (Start of Header)
         002      002    02   00000010      STX    (Start of Text)
         003      003    03   00000011      ETX    (End of Text)
         004      004    04   00000100      EOT    (End of Transmission)
         005      005    05   00000101      ENQ    (Enquiry)
         006      006    06   00000110      ACK    (Acknowledgment)
         007      007    07   00000111      BEL    (Bell)
         008      010    08   00001000       BS    (Backspace)
         009      011    09   00001001       HT    (Horizontal Tab)
         010      012    0A   00001010       LF    (Line Feed)
         011      013    0B   00001011       VT    (Vertical Tab)
         012      014    0C   00001100       FF    (Form Feed)
         013      015    0D   00001101       CR    (Carriage Return)
         014      016    0E   00001110       SO    (Shift Out)
         015      017    0F   00001111       SI    (Shift In)
         016      020    10   00010000      DLE    (Data Link Escape)
         017      021    11   00010001      DC1    (XON)(Device Control 1)
         018      022    12   00010010      DC2    (Device Control 2)
         019      023    13   00010011      DC3    (XOFF)(Device Control 3)
         020      024    14   00010100      DC4    (Device Control 4)
         021      025    15   00010101      NAK    (Negative Acknowledgement)
         022      026    16   00010110      SYN    (Synchronous Idle)
         023      027    17   00010111      ETB    (End of Trans. Block)
         024      030    18   00011000      CAN    (Cancel)
         025      031    19   00011001       EM    (End of Medium)
         026      032    1A   00011010      SUB    (Substitute)
         027      033    1B   00011011      ESC    (Escape)
         028      034    1C   00011100       FS    (File Separator)
         029      035    1D   00011101       GS    (Group Separator)
         030      036    1E   00011110       RS    (Request to Send)(Record Separator)
         031      037    1F   00011111       US    (Unit Separator)
         032      040    20   00100000       SP    (Space)
         033      041    21   00100001        !    (exclamation mark)
         034      042    22   00100010        "    (double quote)
         035      043    23   00100011        #    (number sign)
         036      044    24   00100100        $    (dollar sign)
         037      045    25   00100101        %    (percent)
         038      046    26   00100110        &    (ampersand)
         039      047    27   00100111        '    (single quote)
         040      050    28   00101000        (    (left opening parenthesis)
         041      051    29   00101001        )    (right closing parenthesis)
         042      052    2A   00101010        *    (asterisk)
         043      053    2B   00101011        +    (plus)
         044      054    2C   00101100        ,    (comma)
         045      055    2D   00101101        -    (minus or dash)
         046      056    2E   00101110        .    (dot)
         047      057    2F   00101111        /    (forward slash)
         048      060    30   00110000        0
         049      061    31   00110001        1
         050      062    32   00110010        2
         051      063    33   00110011        3
         052      064    34   00110100        4
         053      065    35   00110101        5
         054      066    36   00110110        6
         055      067    37   00110111        7
         056      070    38   00111000        8
         057      071    39   00111001        9
         058      072    3A   00111010        :    (colon)
         059      073    3B   00111011        ;    (semi-colon)
         060      074    3C   00111100        <    (less than sign)
         061      075    3D   00111101        =    (equal sign)
         062      076    3E   00111110        >    (greater than sign)
         063      077    3F   00111111        ?    (question mark)
         064      100    40   01000000        @    (AT symbol)
         065      101    41   01000001        A
         066      102    42   01000010        B
         067      103    43   01000011        C
         068      104    44   01000100        D
         069      105    45   01000101        E
         070      106    46   01000110        F
         071      107    47   01000111        G
         072      110    48   01001000        H
         073      111    49   01001001        I
         074      112    4A   01001010        J
         075      113    4B   01001011        K
         076      114    4C   01001100        L
         077      115    4D   01001101        M
         078      116    4E   01001110        N
         079      117    4F   01001111        O
         080      120    50   01010000        P
         081      121    51   01010001        Q
         082      122    52   01010010        R
         083      123    53   01010011        S
         084      124    54   01010100        T
         085      125    55   01010101        U
         086      126    56   01010110        V
         087      127    57   01010111        W
         088      130    58   01011000        X
         089      131    59   01011001        Y
         090      132    5A   01011010        Z
         091      133    5B   01011011        [    (left opening bracket)
         092      134    5C   01011100        \    (back slash)
         093      135    5D   01011101        ]    (right closing bracket)
         094      136    5E   01011110        ^    (caret cirumflex)
         095      137    5F   01011111        _    (underscore)
         096      140    60   01100000        `
         097      141    61   01100001        a
         098      142    62   01100010        b
         099      143    63   01100011        c
         100      144    64   01100100        d
         101      145    65   01100101        e
         102      146    66   01100110        f
         103      147    67   01100111        g
         104      150    68   01101000        h
         105      151    69   01101001        i
         106      152    6A   01101010        j
         107      153    6B   01101011        k
         108      154    6C   01101100        l
         109      155    6D   01101101        m
         110      156    6E   01101110        n
         111      157    6F   01101111        o
         112      160    70   01110000        p
         113      161    71   01110001        q
         114      162    72   01110010        r
         115      163    73   01110011        s
         116      164    74   01110100        t
         117      165    75   01110101        u
         118      166    76   01110110        v
         119      167    77   01110111        w
         120      170    78   01111000        x
         121      171    79   01111001        y
         122      172    7A   01111010        z
         123      173    7B   01111011        {    (left opening brace)
         124      174    7C   01111100        |    (vertical bar)
         125      175    7D   01111101        }    (right closing brace)
         126      176    7E   01111110        ~    (tilde)
         127      177    7F   01111111      DEL    (delete)
*/