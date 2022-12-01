file = open ( 'words.dat' , 'w' )
word = ''
while word != 'END' :
    word = input( 'Enter a word (enter END to quit): ')
    if word != 'END':
        file.write( word + '\n' )
file.close( )