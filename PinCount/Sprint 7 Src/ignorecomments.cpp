// *** PLEASE NOTE ***


// THIS CODE IS MEANT TO PUSH THE GROUPS KNOWLEDGE FORWARD
// I DO NOT TAKE CREDIT FOR WIRTING THIS CODE
// I GOT THIS FROM https://stackoverflow.com/questions/13304028/c-reading-numbers-from-text-files-ignoring-comments
// MORE COMPLETE CODE WILL COME IN THE COMING DAYS.


while (std::getline(input_file, line))
{
    if (line[0] != "#" )
    {
        std::istringstream iss(line);
        float num; // The number in the line

        //while the iss is a number 
        while ((iss >> num))
        {
            //look at the number
        }
    }

    // I Wrote the following. I DID NOT WRITE the above code. 
    else if (line[0] ! = '/'){
        std::istringstream iss(line);
        float num; // The number in the line

        //while the iss is a number 
        while ((iss >> num))
        {
            //look at the number that we are looking for
        }

    }
    else 
        break;
}