file = open ( 'words.dat' , 'w' )
word = ''
while word != 'END' :
    word = input( 'Enter a word (enter END to quit): ')
    file.write ( word + '\n' )
file.close ( )
