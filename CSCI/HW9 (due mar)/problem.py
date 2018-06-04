# Author: Karan Sharma CS1300 Spring 2018
# Recitation: 101 – Akriti Kapur
# Cloud9 Workspace Editor Link: https://ide.c9.io/kash0329/karansharma-csci1300
# HW9
#
# Algorithm: that takes in a list of names (each element being first name last name), and returns a dictionary with key as first name and it’s value as a list of last names
#   1. that takes in a list of names
#   2. returns a dictionary with key as first name and it’s value as a list of last names
#   Input parameters: list of names
#   Output: ø
#   Returns: dictionary of names
def countNames(names):
    name_dict = { }
    for i in names:
        n = i.split()
        if not n:
            continue
        if (n[0] in name_dict) == False:
            name_dict[n[0]] = []
        name_dict[n[0]].append(n[1])
    return (name_dict)

# Algorithm: takes a parameter, file_name, and computes the final grade of class given the grades of each section of the course and the weights associate with the section
#   1. takes a parameter, file_name
#   2. computes the final grade of class given the grades of each section of the course and the weights associate with the section
#   3. checks edge cases of no file or empty file
#   4. strips line of \n and gets weight value and number of values. calculates wtaverage by avg/n
#   Input parameters: string filename
#   Output: ø
#   Returns: int add or "File not found"
def compute_grade(file_name):
    if(file_name == ''):
        return ("File not found")
    try:
        f = open(file_name, 'r')
    except IOError:
        return ("File not found")
    contents = f.readlines()
    add = 0
    for line in contents:
        temp = line.rstrip("\n")
        t = temp.split(",")
        wt = float(t[len(t)-1])
        n = len(t)-2
        avg = 0
        for i in range(0,n):
            avg = avg + int(t[i])
        a = avg/n
        wtavg = wt*a
        add = add + wtavg
    return(add)

# Algorithm: Open the given file, checks for edge cases, Return the updated dictionary. 
#   1. If the file open succeeds print "filename loaded successfully."
#   2. If the file open fails: print "filename does not exist."
#   3. Read in the data and fill the dictionary.
#   4. Provide the new size: print "The dictionary has _ entries."
#   Input parameters: string filename, dictionary d
#   Output: string of existance of dictionary and number of entries
#   Returns: dictionary d
def update_dictionary(file_name, d):
    if(file_name == ''):
        print (file_name + " does not exist.")
        print ('The dictionary has %d entries.'  %len(d))
        return d
    try:
        f = open(file_name, 'r')
        print(file_name + " loaded successfully.")
    except IOError:
        print (file_name + " does not exist.")
        print ('The dictionary has %d entries.'  %len(d))
        return d
    contents = f.readlines()
    for line in contents:
        temp = line.rstrip("\n")
        t = temp.split(",")
        d[t[0]] = t[1]
    print ('The dictionary has %d entries.'  %len(d))
    return d

# Algorithm: takes two parameters, a string and a dictionary, and returns the deslanged string
#   1. replaces , with ''
#   2. replaces slang word 'i' in string with dictionary with key 'i' (d[i])
#   Input parameters: string sentence, dictionary d
#   Output: ø
#   Returns: string sentence
def deslang(sentence, d):
    if(not d):
        return sentence
    temp = sentence.replace(',','')
    t = temp.split(" ")
    for i in t:
        if (i in d):
            sentence = sentence.replace(i,d[i])
    return sentence

def main():
    dic = {}
    while(True):
        inputed = input("Would you like to (a)dd words to the dictionary, (d)e-slang a sentence, or (q)uit?: ")
        if (inputed == 'a'):
            yay = False
            while not yay:
                fileName = input("Enter a filename: ")
                if len(fileName) > 0:
                    dic = update_dictionary(fileName, dic)
                    yay = True
        elif (inputed == 'd'):
            yay = False
            while not yay:
                sent = input("Enter a sentence: ")
                if len(sent) > 0:
                    print(deslang(sent,dic))
                    yay = True
        elif (inputed == 'q'):
            break
    
if __name__ == "__main__":
    main()
    
'''
TEST 1

Would you like to (a)dd words to the dictionary, (d)e-slang a sentence, or (q)uit?: d
Enter a sentence: y r u cool
y r u cool
Would you like to (a)dd words to the dictionary, (d)e-slang a sentence, or (q)uit?: d
Enter a sentence: y r u cool
y r u cool
Would you like to (a)dd words to the dictionary, (d)e-slang a sentence, or (q)uit?: a
Enter a filename: textToEnglish.txt
textToEnglish.txt loaded successfully.
The dictionary has 4239 entries.
Would you like to (a)dd words to the dictionary, (d)e-slang a sentence, or (q)uit?: d
Enter a sentence: y r u cool
why are you cool
Would you like to (a)dd words to the dictionary, (d)e-slang a sentence, or (q)uit?: q
'''
'''
TEST 2

Would you like to (a)dd words to the dictionary, (d)e-slang a sentence, or (q)uit?: d
Enter a sentence: u have a big package and a b00t y to slay all           
u have a big package and a b00t y to slay all
Would you like to (a)dd words to the dictionary, (d)e-slang a sentence, or (q)uit?: a
Enter a filename: textToEnglish.txt
textToEnglish.txt loaded successfully.
The dictionary has 4239 entries.
Would you like to (a)dd words to the dictionary, (d)e-slang a sentence, or (q)uit?: d
Enter a sentence: u have a big package and a b00t y to slay all
whyou have a big package and a boot why to slawhy all
Would you like to (a)dd words to the dictionary, (d)e-slang a sentence, or (q)uit?: q
'''