/************************************************
    Author: Erik Kell         Date: 26 March 2022
    Class: CS 202             Title: Midterm Exam

Programs are also on github:
https://github.com/airjet00/CS202

****Purpose****
Midterm exam. Code nneds to be clear, concise,
and readable. Create a pdf report containing
source code and first 10 pages of output for a
book for EACH problem.

****What to Do****

    1. (Version of HW3: Additional Program 1)
        Write a program that reads in a book
        (Project Gutenberg or similar) and
        outputs the text based on given characters
        wrapping value.

        Usage: prettyprint 768.txt 50
        Should print the book with a max of 50 char
        per line.

    2.  Modify program from #1 to print the text in
        two column format. The command-line arguments
        are the input file name, the number of lines
        per page, the width of the columns, and the
        number of blank spaces between the columns.

        Usage: twocolumn 768.txt 40 38 4
        Should print 40 lines per page, with each
        column a max of 38 char wide and 4 blank
        spaces between the columns. Output
        "-----------" to show each page break.

****Optional next steps****
N/A

************************************************/

#include <iostream>
#include <vector>
#include <fstream>


using TYPE = std::string;

//Method prints the text with x number of char per line
void printFile(std::vector<TYPE> fileData, const int charPerLine){
    int count = 0;
    for(int i = 0; i < fileData.size(); i++)
    {
        //checking char count on each line and printing if 50 or under
        if((count + fileData[i].size()) < charPerLine){
            std::cout << fileData[i] << " ";
            count = count + fileData[i].size() +1;
        }
        else if((count + fileData[i].size()) == charPerLine)
        {
            std::cout << fileData[i];
            count = count + fileData[i].size();
        }
        else if((count + fileData[i].size()) > charPerLine)
        {
//            std::cout << count << "\n"; //to check count of each line
            std::cout << "\n";
            count = 0;
            continue;
        }
        else
        {
            break;
        }
    }
    std::cout << "\n";
}

//open file method
void loadFile(std::string fileName, const int charPerLine)
{
    std::vector<TYPE>(fileData);
    std::ifstream file;
    file.open(fileName);
    if(!file.is_open()) return;

    std::string word;
    while (file >> word)
    {
        fileData.push_back(word);
    }
    //call to print file
    printFile(fileData, charPerLine);
}

int main(int argc, char *argv[]){

    std::string fileName = argv[1];
    const char* chNum = argv[2];
    const int charPerLine = std::stoi(chNum);

    //TEST TEXT FILES
    //    std::string fileName = "/Users/erikkell/Programming/CS202/CS202/testfile.txt";
    //    /Users/erikkell/Programming/CS202/CS202/ten_page_book.txt

    loadFile(fileName, charPerLine);

    return 0;
}




PROGRAM 1

INPUT:
./main/Users/erikkell/Programming/CS202/CS202/testfile.txt 40

OUTPUT:

Section 1.10.33 of "de Finibus Bonorum 
Malorum", written by Cicero in 45 BC "At
eos et accusamus et iusto odio 
ducimus qui blanditiis praesentium 
deleniti atque corrupti quos dolores et 
molestias excepturi sint occaecati 
non provident, similique sunt in culpa 
officia deserunt mollitia animi, id est 
et dolorum fuga. Et harum quidem rerum 
est et expedita distinctio. Nam libero 
cum soluta nobis est eligendi optio 
nihil impedit quo minus id quod maxime 
facere possimus, omnis voluptas 
est, omnis dolor repellendus. Temporibus
quibusdam et aut officiis debitis aut 
necessitatibus saepe eveniet ut et 
repudiandae sint et molestiae non 
Itaque earum rerum hic tenetur a 
delectus, ut aut reiciendis voluptatibus
alias consequatur aut perferendis 
asperiores repellat." 1914 translation 
H. Rackham "On the other hand, we 
with righteous indignation and dislike 
who are so beguiled and demoralized by 
charms of pleasure of the moment, so 
by desire, that they cannot foresee the 
and trouble that are bound to ensue; and
blame belongs to those who fail in their
through weakness of will, which is the 
as saying through shrinking from toil 
pain. These cases are perfectly simple 
easy to distinguish. In a free hour, 
our power of choice is untrammelled and 
nothing prevents our being able to do 
we like best, every pleasure is to be 
and every pain avoided. But in certain 
and owing to the claims of duty or the 
of business it will frequently occur 
pleasures have to be repudiated and 
accepted. The wise man therefore always 
in these matters to this principle of 
he rejects pleasures to secure other 
pleasures, or else he endures pains to 
worse pains."

/************************************************
    Author: Erik Kell         Date: 26 March 2022
    Class: CS 202             Title: Midterm Exam

    2.  Modify program from #1 to print the text in
        two column format. The command-line arguments
        are the input file name, the number of lines
        per page, the width of the columns, and the
        number of blank spaces between the columns.

        Usage: twocolumn 768.txt 40 38 4
        Should print 40 lines per page, with each
        column a max of 38 char wide and 4 blank
        spaces between the columns. Output
        "-----------" to show each page break.


************************************************/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>


using TYPE = std::string;
using std::stoi;

//Method builds and returns columns as vector
std::vector<TYPE> createColumn(std::vector<TYPE> fileData, const int linesPerPage,
                               const int columnWidth, int& columnCount) {
    std::vector <TYPE> vColumn;
    std::string s;
    int count = 0;
    int countLines = 0;
        //loop thr and build column using columnCount as a ref for i
        for (int i = columnCount; i <= fileData.size(); i++) {
            //if less than column width
            if ((s.size() + fileData[i].size()) < columnWidth) {
                columnCount = i;
                if(columnCount == fileData.size()) {
                    s.append(fileData[i]);
                    vColumn.push_back(s);
                    return vColumn;
                }
                s.append(fileData[i]).append(" ");

            //if equal to column width
            } else if ((s.size() + fileData[i].size()) == columnWidth) {
                s.append(fileData[i]);
                vColumn.push_back(s);
                s = "";
                columnCount = i;
                countLines++;
                if(countLines == linesPerPage || columnCount == 							fileData.size()) return vColumn;

            //if greater than column width
            } else if ((s.size() + fileData[i].size()) > columnWidth) {
                vColumn.push_back(s);
                columnCount = i;
                i--;
                countLines++;
                s = "";
                if(countLines == linesPerPage) return vColumn;
            }
        }
    return vColumn;
}

//Method prints the text with x number of char per line
void printFile(std::vector<TYPE> fileData, const int linesPerPage,
               const int columnWidth, const int spaceBetweenColumns) {

    int LTCount = 0;
    int RTCount = 0;
    bool flag = true;
    int dataPlace = 0;
    std::string s;
    std::vector <TYPE> strColumn1;
    std::vector <TYPE> strColumn2;

        while(flag) {
            //When even, make left column
            if ((LTCount + RTCount) % 2 == 0) {
                //dataPlace to calc where at in fileData
                std::vector <TYPE> vectorCol1 = createColumn(fileData, 						linesPerPage, columnWidth,dataPlace);
                strColumn1.insert(strColumn1.end(), vectorCol1.begin(), 									vectorCol1.end());
                LTCount++;
                //if size doesn't match line count then is uneven column 		    //and finished
                if (strColumn1.size() != (linesPerPage * LTCount)) {
                    flag = false;
                    break;
                }
            //When odd, make right column
            } else if ((LTCount + RTCount) % 2 != 0) {
                //dataPlace to calc where at in fileData
                std::vector <TYPE> vectorCol2 = createColumn(fileData,    						 linesPerPage, columnWidth, dataPlace);
                strColumn2.insert(strColumn2.end(), vectorCol2.begin(),									vectorCol2.end());
                RTCount++;

                //if size doesn't match line count then is uneven column //and finished
                if (strColumn2.size() != (linesPerPage * RTCount)) {
                    flag = false;
                    break;
                }
            }
        }
// printing loop
    std::string spaceBC;
    int count = 0;
    std::ofstream resultFile("resultTest.txt");
    for (int p = 0; p < strColumn1.size(); p++) {
        //counting space between columns
        while((columnWidth - strColumn1[p].size() + spaceBetweenColumns) 				 			!= spaceBC.size()) {
            spaceBC.append(" ");
        }
        //print to file/screen
        resultFile << strColumn1[p] << spaceBC << strColumn2[p] << "\n";
        std::cout << strColumn1[p] << spaceBC << strColumn2[p] <<   												std::endl;

        //testing column size and spaces
//        std::cout << spaceBC.size() << " col size: " << 
//						  strColumn1[p].size() <<std::endl;

        spaceBC = "";
        //adding pg break
        if(((p+1) % linesPerPage) == 0){
            std::cout << "\n------------- Pg. " << ((p+1)/linesPerPage)       <<" ----------------\n" << std::endl;

            resultFile << "\n------------- Pg. " << ((p+1)/linesPerPage) <<" ----------------\n";
        }

    }
    resultFile.close();

}

//run file method
void runFile(std::string fileName, const int linesPerPage,
             const int columnWidth, const int spaceBetweenColumns)
{
    //open and added to vector fileData
    std::vector<TYPE>(fileData);
    std::ifstream file;
    file.open(fileName);
    if(!file.is_open()) return;

    std::string word;
    while (file >> word)
    {
        fileData.push_back(word);
    }
    //call to print file
    printFile(fileData, linesPerPage, columnWidth, spaceBetweenColumns);
}

int main(int argc, char *argv[]){

    //Arguments from command line
    std::string fileName = argv[1];
    const char* chLinesPerPage = argv[2];
    const char* chColumnWidth = argv[3];
    const char* chSpaceBetweenColumns = argv[4];

    //convert to int
    const int linesPerPage = stoi(chLinesPerPage);
    const int columnWidth = stoi(chColumnWidth);
    const int spaceBetweenColumns = stoi(chSpaceBetweenColumns);

    //run method call
    runFile(fileName, linesPerPage, columnWidth, spaceBetweenColumns);

    //TEST TEXT FILES, for future testing
    //    /Users/erikkell/Programming/CS202/CS202/testfile.txt
    //    /Users/erikkell/Programming/CS202/CS202/ten_page_book.txt
    return 0;
}






































PROGRAM 2

INPUT:
./twocolumn /Users/erikkell/Programming/CS202/CS202/ten_page_book.txt 40 35 4

OUTPUT:


I. Introduction The Time Traveller     you that? Neither has a 
(for so it will be convenient to       mathematical plane. These things 
speak of him) was expounding a         are mere abstractions.” “That 
recondite matter to us. His pale       is all right,” said the 
grey eyes shone and twinkled, and      Psychologist. “Nor, having only 
his usually pale face was flushed      length, breadth, and thickness, can
and animated. The fire burnt           a cube have a real existence.” 
brightly, and the soft radiance of     “There I object,” said Filby. 
the incandescent lights in the         “Of course a solid body may 
lilies of silver caught the bubbles    exist. All real things—” “So 
that flashed and passed in our         most people think. But wait a 
glasses. Our chairs, being his         moment. Can an _instantaneous_ cube
patents, embraced and caressed us      exist?” “Don’t follow you,”
rather than submitted to be sat        said Filby. “Can a cube that does
upon, and there was that luxurious     not last for any time at all, have 
after-dinner atmosphere, when          a real existence?” Filby became 
thought runs gracefully free of the    pensive. “Clearly,” the Time 
trammels of precision. And he put      Traveller proceeded, “any real 
it to us in this way—marking the     body must have extension in _four_ 
points with a lean forefinger—as     directions: it must have Length, 
we sat and lazily admired his          Breadth, Thickness, and—Duration.
earnestness over this new paradox      But through a natural infirmity of 
(as we thought it) and his             the flesh, which I will explain to 
fecundity. “You must follow me       you in a moment, we incline to 
carefully. I shall have to             overlook this fact. There are 
controvert one or two ideas that       really four dimensions, three which
are almost universally accepted.       we call the three planes of Space, 
The geometry, for instance, they       and a fourth, Time. There is, 
taught you at school is founded on     however, a tendency to draw an 
a misconception.” “Is not that     unreal distinction between the 
rather a large thing to expect us      former three dimensions and the 
to begin upon?” said Filby, an       latter, because it happens that our
argumentative person with red hair.    consciousness moves intermittently 
“I do not mean to ask you to         in one direction along the latter 
accept anything without reasonable     from the beginning to the end of 
ground for it. You will soon admit     our lives.” “That,” said a 
as much as I need from you. You        very young man, making spasmodic 
know of course that a mathematical     efforts to relight his cigar over 
line, a line of thickness _nil_,       the lamp; “that . . . very clear 
has no real existence. They taught     indeed.” “Now, it is very 

------------- Pg. 1 ----------------
remarkable that this is so             solid, and similarly they think 
extensively overlooked,”             that by models of three dimensions 
continued the Time Traveller, with     they could represent one of 
a slight accession of cheerfulness.    four—if they could master the 
“Really this is what is meant by     perspective of the thing. See?” 
the Fourth Dimension, though some      “I think so,” murmured the 
people who talk about the Fourth       Provincial Mayor; and, knitting his
Dimension do not know they mean it.    brows, he lapsed into an 
It is only another way of looking      introspective state, his lips 
at Time. _There is no difference       moving as one who repeats mystic 
between Time and any of the three      words. “Yes, I think I see it 
dimensions of Space except that our    now,” he said after some time, 
consciousness moves along it_. But     brightening in a quite transitory 
some foolish people have got hold      manner. “Well, I do not mind 
of the wrong side of that idea. You    telling you I have been at work 
have all heard what they have to       upon this geometry of Four 
say about this Fourth Dimension?”    Dimensions for some time. Some of 
“_I_ have not,” said the           my results are curious. For 
Provincial Mayor. “It is simply      instance, here is a portrait of a 
this. That Space, as our               man at eight years old, another at 
mathematicians have it, is spoken      fifteen, another at seventeen, 
of as having three dimensions,         another at twenty-three, and so on.
which one may call Length, Breadth,    All these are evidently sections, 
and Thickness, and is always           as it were, Three-Dimensional 
definable by reference to three        representations of his 
planes, each at right angles to the    Four-Dimensioned being, which is a 
others. But some philosophical         fixed and unalterable thing. 
people have been asking why _three_    “Scientific people,” proceeded 
dimensions particularly—why not      the Time Traveller, after the pause
another direction at right angles      required for the proper 
to the other three?—and have even    assimilation of this, “know very 
tried to construct a                   well that Time is only a kind of 
Four-Dimensional geometry.             Space. Here is a popular scientific
Professor Simon Newcomb was            diagram, a weather record. This 
expounding this to the New York        line I trace with my finger shows 
Mathematical Society only a month      the movement of the barometer. 
or so ago. You know how on a flat      Yesterday it was so high, yesterday
surface, which has only two            night it fell, then this morning it
dimensions, we can represent a         rose again, and so gently upward to
figure of a three-dimensional          here. Surely the mercury did not 

------------- Pg. 2 ----------------
trace this line in any of the          and have no dimensions, are passing
dimensions of Space generally          along the Time-Dimension with a 
recognised? But certainly it traced    uniform velocity from the cradle to
such a line, and that line,            the grave. Just as we should travel
therefore, we must conclude, was       _down_ if we began our existence 
along the Time-Dimension.”           fifty miles above the earth’s 
“But,” said the Medical Man,       surface.” “But the great 
staring hard at a coal in the fire,    difficulty is this,” interrupted 
“if Time is really only a fourth     the Psychologist. ’You _can_ move
dimension of Space, why is it, and     about in all directions of Space, 
why has it always been, regarded as    but you cannot move about in 
something different? And why cannot    Time.” “That is the germ of my 
we move in Time as we move about in    great discovery. But you are wrong 
the other dimensions of Space?”      to say that we cannot move about in
The Time Traveller smiled. “Are      Time. For instance, if I am 
you so sure we can move freely in      recalling an incident very vividly 
Space? Right and left we can go,       I go back to the instant of its 
backward and forward freely enough,    occurrence: I become absent-minded,
and men always have done so. I         as you say. I jump back for a 
admit we move freely in two            moment. Of course we have no means 
dimensions. But how about up and       of staying back for any length of 
down? Gravitation limits us            Time, any more than a savage or an 
there.” “Not exactly,” said      animal has of staying six feet 
the Medical Man. “There are          above the ground. But a civilised 
balloons.” “But before the         man is better off than the savage 
balloons, save for spasmodic           in this respect. He can go up 
jumping and the inequalities of the    against gravitation in a balloon, 
surface, man had no freedom of         and why should he not hope that 
vertical movement.” “Still they    ultimately he may be able to stop 
could move a little up and down,”    or accelerate his drift along the 
said the Medical Man. “Easier,       Time-Dimension, or even turn about 
far easier down than up.” “And     and travel the other way?” “Oh,
you cannot move at all in Time, you    _this_,” began Filby, “is 
cannot get away from the present       all—” “Why not?” said the 
moment.” “My dear sir, that is     Time Traveller. “It’s against 
just where you are wrong. That is      reason,” said Filby. “What 
just where the whole world has gone    reason?” said the Time Traveller.
wrong. We are always getting away      “You can show black is white by 
from the present moment. Our mental    argument,” said Filby, “but you
existences, which are immaterial       will never convince me.” 

------------- Pg. 3 ----------------
“Possibly not,” said the Time      theories!” began the 
Traveller. “But now you begin to     Psychologist. “Yes, so it seemed 
see the object of my investigations    to me, and so I never talked of it 
into the geometry of Four              until—” “Experimental 
Dimensions. Long ago I had a vague     verification!” cried I. “You 
inkling of a machine—” “To       are going to verify _that_?” 
travel through Time!” exclaimed      “The experiment!” cried Filby, 
the Very Young Man. “That shall      who was getting brain-weary. 
travel indifferently in any            “Let’s see your experiment 
direction of Space and Time, as the    anyhow,” said the Psychologist, 
driver determines.” Filby            “though it’s all humbug, you 
contented himself with laughter.       know.” The Time Traveller smiled 
“But I have experimental             round at us. Then, still smiling 
verification,” said the Time         faintly, and with his hands deep in
Traveller. “It would be              his trousers pockets, he walked 
remarkably convenient for the          slowly out of the room, and we 
historian,” the Psychologist         heard his slippers shuffling down 
suggested. “One might travel back    the long passage to his laboratory.
and verify the accepted account of     The Psychologist looked at us. “I
the Battle of Hastings, for            wonder what he’s got?” “Some 
instance!” “Don’t you think      sleight-of-hand trick or other,” 
you would attract attention?”        said the Medical Man, and Filby 
said the Medical Man. “Our           tried to tell us about a conjuror 
ancestors had no great tolerance       he had seen at Burslem, but before 
for anachronisms.” “One might      he had finished his preface the 
get one’s Greek from the very        Time Traveller came back, and 
lips of Homer and Plato,” the        Filby’s anecdote collapsed. II. 
Very Young Man thought. “In which    The Machine The thing the Time 
case they would certainly plough       Traveller held in his hand was a 
you for the Little-go. The German      glittering metallic framework, 
scholars have improved Greek so        scarcely larger than a small clock,
much.” “Then there is the          and very delicately made. There was
future,” said the Very Young Man.    ivory in it, and some transparent 
“Just think! One might invest all    crystalline substance. And now I 
one’s money, leave it to             must be explicit, for this that 
accumulate at interest, and hurry      follows—unless his explanation is
on ahead!” “To discover a          to be accepted—is an absolutely 
society,” said I, “erected on a    unaccountable thing. He took one of
strictly communistic basis.”         the small octagonal tables that 
“Of all the wild extravagant         were scattered about the room, and 

------------- Pg. 4 ----------------
set it in front of the fire, with      twinkling appearance about this 
two legs on the hearthrug. On this     bar, as though it was in some way 
table he placed the mechanism. Then    unreal.” He pointed to the part 
he drew up a chair, and sat down.      with his finger. “Also, here is 
The only other object on the table     one little white lever, and here is
was a small shaded lamp, the bright    another.” The Medical Man got up 
light of which fell upon the model.    out of his chair and peered into 
There were also perhaps a dozen        the thing. “It’s beautifully 
candles about, two in brass            made,” he said. “It took two 
candlesticks upon the mantel and       years to make,” retorted the Time
several in sconces, so that the        Traveller. Then, when we had all 
room was brilliantly illuminated. I    imitated the action of the Medical 
sat in a low arm-chair nearest the     Man, he said: “Now I want you 
fire, and I drew this forward so as    clearly to understand that this 
to be almost between the Time          lever, being pressed over, sends 
Traveller and the fireplace. Filby     the machine gliding into the 
sat behind him, looking over his       future, and this other reverses the
shoulder. The Medical Man and the      motion. This saddle represents the 
Provincial Mayor watched him in        seat of a time traveller. Presently
profile from the right, the            I am going to press the lever, and 
Psychologist from the left. The        off the machine will go. It will 
Very Young Man stood behind the        vanish, pass into future Time, and 
Psychologist. We were all on the       disappear. Have a good look at the 
alert. It appears incredible to me     thing. Look at the table too, and 
that any kind of trick, however        satisfy yourselves there is no 
subtly conceived and however           trickery. I don’t want to waste 
adroitly done, could have been         this model, and then be told I’m 
played upon us under these             a quack.” There was a minute’s 
conditions. The Time Traveller         pause perhaps. The Psychologist 
looked at us, and then at the          seemed about to speak to me, but 
mechanism. “Well?” said the        changed his mind. Then the Time 
Psychologist. “This little           Traveller put forth his finger 
affair,” said the Time Traveller,    towards the lever. “No,” he 
resting his elbows upon the table      said suddenly. “Lend me your 
and pressing his hands together        hand.” And turning to the 
above the apparatus, “is only a      Psychologist, he took that 
model. It is my plan for a machine     individual’s hand in his own and 
to travel through time. You will       told him to put out his forefinger.
notice that it looks singularly        So that it was the Psychologist 
askew, and that there is an odd        himself who sent forth the model 

------------- Pg. 5 ----------------
Time Machine on its interminable       there”—he indicated the 
voyage. We all saw the lever turn.     laboratory—“and when that is 
I am absolutely certain there was      put together I mean to have a 
no trickery. There was a breath of     journey on my own account.” 
wind, and the lamp flame jumped.       “You mean to say that that 
One of the candles on the mantel       machine has travelled into the 
was blown out, and the little          future?” said Filby. “Into the 
machine suddenly swung round,          future or the past—I don’t, for
became indistinct, was seen as a       certain, know which.” After an 
ghost for a second perhaps, as an      interval the Psychologist had an 
eddy of faintly glittering brass       inspiration. “It must have gone 
and ivory; and it was                  into the past if it has gone 
gone—vanished! Save for the lamp     anywhere,” he said. “Why?” 
the table was bare. Everyone was       said the Time Traveller. “Because
silent for a minute. Then Filby        I presume that it has not moved in 
said he was damned. The                space, and if it travelled into the
Psychologist recovered from his        future it would still be here all 
stupor, and suddenly looked under      this time, since it must have 
the table. At that the Time            travelled through this time.” 
Traveller laughed cheerfully.          “But,” said I, “If it 
“Well?” he said, with a            travelled into the past it would 
reminiscence of the Psychologist.      have been visible when we came 
Then, getting up, he went to the       first into this room; and last 
tobacco jar on the mantel, and with    Thursday when we were here; and the
his back to us began to fill his       Thursday before that; and so 
pipe. We stared at each other.         forth!” “Serious objections,”
“Look here,” said the Medical      remarked the Provincial Mayor, with
Man, “are you in earnest about       an air of impartiality, turning 
this? Do you seriously believe that    towards the Time Traveller. “Not 
that machine has travelled into        a bit,” said the Time Traveller, 
time?” “Certainly,” said the     and, to the Psychologist: “You 
Time Traveller, stooping to light a    think. _You_ can explain that. 
spill at the fire. Then he turned,     It’s presentation below the 
lighting his pipe, to look at the      threshold, you know, diluted 
Psychologist’s face. (The            presentation.” “Of course,” 
Psychologist, to show that he was      said the Psychologist, and 
not unhinged, helped himself to a      reassured us. “That’s a simple 
cigar and tried to light it uncut.)    point of psychology. I should have 
“What is more, I have a big          thought of it. It’s plain enough,
machine nearly finished in             and helps the paradox delightfully.

------------- Pg. 6 ----------------
delightfully. We cannot see it, nor    parts had certainly been filed or 
can we appreciate this machine, any    sawn out of rock crystal. The thing
more than we can the spoke of a        was generally complete, but the 
wheel spinning, or a bullet flying     twisted crystalline bars lay 
through the air. If it is              unfinished upon the bench beside 
travelling through time fifty times    some sheets of drawings, and I took
or a hundred times faster than we      one up for a better look at it. 
are, if it gets through a minute       Quartz it seemed to be. “Look 
while we get through a second, the     here,” said the Medical Man, 
impression it creates will of          “are you perfectly serious? Or is
course be only one-fiftieth or         this a trick—like that ghost you 
one-hundredth of what it would make    showed us last Christmas?” 
if it were not travelling in time.     “Upon that machine,” said the 
That’s plain enough.” He passed    Time Traveller, holding the lamp 
his hand through the space in which    aloft, “I intend to explore time.
the machine had been. “You           Is that plain? I was never more 
see?” he said, laughing. We sat      serious in my life.” None of us 
and stared at the vacant table for     quite knew how to take it. I caught
a minute or so. Then the Time          Filby’s eye over the shoulder of 
Traveller asked us what we thought     the Medical Man, and he winked at 
of it all. “It sounds plausible      me solemnly. III. The Time 
enough tonight,” said the Medical    Traveller Returns I think that at 
Man; “but wait until tomorrow.       that time none of us quite believed
Wait for the common sense of the       in the Time Machine. The fact is, 
morning.” “Would you like to       the Time Traveller was one of those
see the Time Machine itself?”        men who are too clever to be 
asked the Time Traveller. And          believed: you never felt that you 
therewith, taking the lamp in his      saw all round him; you always 
hand, he led the way down the long,    suspected some subtle reserve, some
draughty corridor to his               ingenuity in ambush, behind his 
laboratory. I remember vividly the     lucid frankness. Had Filby shown 
flickering light, his queer, broad     the model and explained the matter 
head in silhouette, the dance of       in the Time Traveller’s words, we
the shadows, how we all followed       should have shown _him_ far less 
him, puzzled but incredulous, and      scepticism. For we should have 
how there in the laboratory we         perceived his motives: a 
beheld a larger edition of the         pork-butcher could understand 
little mechanism which we had seen     Filby. But the Time Traveller had 
vanish from before our eyes. Parts     more than a touch of whim among his
were of nickel, parts of ivory,        elements, and we distrusted him. 

------------- Pg. 7 ----------------
Things that would have made the        for the Time Traveller, 
fame of a less clever man seemed       and—“It’s half-past seven 
tricks in his hands. It is a           now,” said the Medical Man. “I 
mistake to do things too easily.       suppose we’d better have 
The serious people who took him        dinner?” “Where’s——?” 
seriously never felt quite sure of     said I, naming our host. 
his deportment; they were somehow      “You’ve just come? It’s 
aware that trusting their              rather odd. He’s unavoidably 
reputations for judgment with him      detained. He asks me in this note 
was like furnishing a nursery with     to lead off with dinner at seven if
eggshell china. So I don’t think     he’s not back. Says he’ll 
any of us said very much about time    explain when he comes.” “It 
travelling in the interval between     seems a pity to let the dinner 
that Thursday and the next, though     spoil,” said the Editor of a 
its odd potentialities ran, no         well-known daily paper; and 
doubt, in most of our minds: its       thereupon the Doctor rang the bell.
plausibility, that is, its             The Psychologist was the only 
practical incredibleness, the          person besides the Doctor and 
curious possibilities of               myself who had attended the 
anachronism and of utter confusion     previous dinner. The other men were
it suggested. For my own part, I       Blank, the Editor aforementioned, a
was particularly preoccupied with      certain journalist, and another—a
the trick of the model. That I         quiet, shy man with a beard—whom 
remember discussing with the           I didn’t know, and who, as far as
Medical Man, whom I met on Friday      my observation went, never opened 
at the Linnæan. He said he had        his mouth all the evening. There 
seen a similar thing at Tübingen,     was some speculation at the 
and laid considerable stress on the    dinner-table about the Time 
blowing-out of the candle. But how     Traveller’s absence, and I 
the trick was done he could not        suggested time travelling, in a 
explain. The next Thursday I went      half-jocular spirit. The Editor 
again to Richmond—I suppose I was    wanted that explained to him, and 
one of the Time Traveller’s most     the Psychologist volunteered a 
constant guests—and, arriving        wooden account of the “ingenious 
late, found four or five men           paradox and trick” we had 
already assembled in his               witnessed that day week. He was in 
drawing-room. The Medical Man was      the midst of his exposition when 
standing before the fire with a        the door from the corridor opened 
sheet of paper in one hand and his     slowly and without noise. I was 
watch in the other. I looked round     facing the door, and saw it first. 

------------- Pg. 8 ----------------
“Hallo!” I said. “At last!”    articulation. “I’m all 
And the door opened wider, and the     right.” He stopped, held out his 
Time Traveller stood before us. I      glass for more, and took it off at 
gave a cry of surprise. “Good        a draught. “That’s good,” he 
heavens! man, what’s the             said. His eyes grew brighter, and a
matter?” cried the Medical Man,      faint colour came into his cheeks. 
who saw him next. And the whole        His glance flickered over our faces
tableful turned towards the door.      with a certain dull approval, and 
He was in an amazing plight. His       then went round the warm and 
coat was dusty and dirty, and          comfortable room. Then he spoke 
smeared with green down the            again, still as it were feeling his
sleeves; his hair disordered, and      way among his words. “I’m going
as it seemed to me greyer—either     to wash and dress, and then I’ll 
with dust and dirt or because its      come down and explain things.... 
colour had actually faded. His face    Save me some of that mutton. I’m 
was ghastly pale; his chin had a       starving for a bit of meat.” He 
brown cut on it—a cut                looked across at the Editor, who 
half-healed; his expression was        was a rare visitor, and hoped he 
haggard and drawn, as by intense       was all right. The Editor began a 
suffering. For a moment he             question. “Tell you presently,”
hesitated in the doorway, as if he     said the Time Traveller. 
had been dazzled by the light. Then    “I’m—funny! Be all right in a
he came into the room. He walked       minute.” He put down his glass, 
with just such a limp as I have        and walked towards the staircase 
seen in footsore tramps. We stared     door. Again I remarked his lameness
at him in silence, expecting him to    and the soft padding sound of his 
speak. He said not a word, but came    footfall, and standing up in my 
painfully to the table, and made a     place, I saw his feet as he went 
motion towards the wine. The Editor    out. He had nothing on them but a 
filled a glass of champagne, and       pair of tattered, blood-stained 
pushed it towards him. He drained      socks. Then the door closed upon 
it, and it seemed to do him good:      him. I had half a mind to follow, 
for he looked round the table, and     till I remembered how he detested 
the ghost of his old smile             any fuss about himself. For a 
flickered across his face. “What     minute, perhaps, my mind was 
on earth have you been up to,          wool-gathering. Then, “Remarkable
man?” said the Doctor. The Time      Behaviour of an Eminent 
Traveller did not seem to hear.        Scientist,” I heard the Editor 
“Don’t let me disturb you,”      say, thinking (after his wont) in 
he said, with a certain faltering      headlines. And this brought my 

------------- Pg. 9 ----------------
attention back to the bright           clothes-brushes in the Future? The 
dinner-table. “What’s the          Journalist too, would not believe 
game?” said the Journalist.          at any price, and joined the Editor
“Has he been doing the Amateur       in the easy work of heaping 
Cadger? I don’t follow.” I met     ridicule on the whole thing. They 
the eye of the Psychologist, and       were both the new kind of 
read my own interpretation in his      journalist—very joyous, 
face. I thought of the Time            irreverent young men. “Our 
Traveller limping painfully            Special Correspondent in the Day 
upstairs. I don’t think anyone       after Tomorrow reports,” the 
else had noticed his lameness. The     Journalist was saying—or rather 
first to recover completely from       shouting—when the Time Traveller 
this surprise was the Medical Man,     came back. He was dressed in 
who rang the bell—the Time           ordinary evening clothes, and 
Traveller hated to have servants       nothing save his haggard look 
waiting at dinner—for a hot          remained of the change that had 
plate. At that the Editor turned to    startled me. “I say,” said the 
his knife and fork with a grunt,       Editor hilariously, “these chaps 
and the Silent Man followed suit.      here say you have been travelling 
The dinner was resumed.                into the middle of next week! Tell 
Conversation was exclamatory for a     us all about little Rosebery, will 
little while with gaps of              you? What will you take for the 
wonderment; and then the Editor got    lot?” The Time Traveller came to 
fervent in his curiosity. “Does      the place reserved for him without 
our friend eke out his modest          a word. He smiled quietly, in his 
income with a crossing? or has he      old way. “Where’s my mutton?”
his Nebuchadnezzar phases?” he       he said. “What a treat it is to 
inquired. “I feel assured it’s     stick a fork into meat again!” 
this business of the Time              “Story!” cried the Editor. 
Machine,” I said, and took up the    “Story be damned!” said the 
Psychologist’s account of our        Time Traveller. “I want something
previous meeting. The new guests       to eat. I won’t say a word until 
were frankly incredulous. The          I get some peptone into my 
Editor raised objections. “What      arteries. Thanks. And the salt.” 
_was_ this time travelling? A man      “One word,” said I. “Have you
couldn’t cover himself with dust     been time travelling?” “Yes,”
by rolling in a paradox, could         said the Time Traveller, with his 
he?” And then, as the idea came      mouth full, nodding his head. 
home to him, he resorted to            “I’d give a shilling a line for
caricature. Hadn’t they any          a verbatim note,” said the 

------------- Pg. 10 ----------------
Editor. The Time Traveller pushed      “But the thing’s a mere 
his glass towards the Silent Man       paradox,” said the Editor. “I 
and rang it with his fingernail; at    can’t argue tonight. I don’t 
which the Silent Man, who had been     mind telling you the story, but I 
staring at his face, started           can’t argue. I will,” he went 
convulsively, and poured him wine.     on, “tell you the story of what 
The rest of the dinner was             has happened to me, if you like, 
uncomfortable. For my own part,        but you must refrain from 
sudden questions kept on rising to     interruptions. I want to tell it. 
my lips, and I dare say it was the     Badly. Most of it will sound like 
same with the others. The              lying. So be it! It’s 
Journalist tried to relieve the        true—every word of it, all the 
tension by telling anecdotes of        same. I was in my laboratory at 
Hettie Potter. The Time Traveller      four o’clock, and since then … 
devoted his attention to his           I’ve lived eight days … such 
dinner, and displayed the appetite     days as no human being ever lived 
of a tramp. The Medical Man smoked     before! I’m nearly worn out, but 
a cigarette, and watched the Time      I shan’t sleep till I’ve told 
Traveller through his eyelashes.       this thing over to you. Then I 
The Silent Man seemed even more        shall go to bed. But no 
clumsy than usual, and drank           interruptions! Is it agreed?” 
champagne with regularity and          “Agreed,” said the Editor, and 
determination out of sheer             the rest of us echoed “Agreed.”
nervousness. At last the Time          And with that the Time Traveller 
Traveller pushed his plate away,       began his story as I have set it 
and looked round us. “I suppose I    forth. He sat back in his chair at 
must apologise,” he said. “I       first, and spoke like a weary man. 
was simply starving. I’ve had a      Afterwards he got more animated. In
most amazing time.” He reached       writing it down I feel with only 
out his hand for a cigar, and cut      too much keenness the inadequacy of
the end. “But come into the          pen and ink—and, above all, my 
smoking-room. It’s too long a        own inadequacy—to express its 
story to tell over greasy              quality. You read, I will suppose, 
plates.” And ringing the bell in     attentively enough; but you cannot 
passing, he led the way into the       see the speaker’s white, sincere 
adjoining room. “You have told       face in the bright circle of the 
Blank, and Dash, and Chose about       little lamp, nor hear the 
the machine?” he said to me,         intonation of his voice. You cannot
leaning back in his easy-chair and     know how his expression followed 
naming the three new guests. “But    the turns of his story! Most of us 

------------- Pg. 11 ----------------
hearers were in shadow, for the        
candles in the smoking-room had not    
been lighted, and only the face of     
the Journalist and the legs of the     
Silent Man from the knees downward     
were illuminated. At first we          
glanced now and again at each          
other. After a time we ceased to do    
that, and looked only at the Time      
Traveller’s face.                    

