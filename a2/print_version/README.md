Final version of dlinkedlist.cpp that prints the results. Mainly for testing.

```
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
```
