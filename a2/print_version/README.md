Here we put the files that show us the result, mainly for testing (NOT FOR SUBMISSION).
Some of the functions won't work unless we implement the queue functions. If you want to test them, comment out the last printing section of queue—talking about this:

'''
 string PrintStatus() const
    {
      string complainttext;
      ostringstream output;
      output << "Ticket queue contains " << tickets.Size() << " open tickets.\n";
      output << "Position\tTicket ID\tCustomer\tShort description\n";
      output << "-----------------------------------------------------------------------\n";
      for (int i = 0; i < tickets.Size(); i++)
      {
        complainttext = tickets.ElementAt(i).GetComplaint();
        output << i+1 << "\t\t" << tickets.ElementAt(i).GetID() << "\t\t"
               << tickets.ElementAt(i).GetCustomer() << "\t" << complainttext.substr(0, std::min((int)20, (int)complainttext.length())) << "...\n";
      }
      return output.str();
'''
