file = open ( 'words.dat' , 'w' )

word = '-1'

while word != '':
    word = input( 'Enter a word (hit only enter to quit): ')
    
    if word != '':
        file.write( word + '\n' )

file.close ( )