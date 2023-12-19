// Sort cutomers based on name
void SortingName(Customer data[], int size)
{
  Customer temp;
  bool sorted = false;

  for (int pass = 1; (pass < size) && !sorted; ++pass)
  {
    sorted = true;
    for (int x = 0; x < size-pass; x++)
    {
      if (data[x].getName() > data[x+1].getName())
      {
        temp.setName(data[x].getName());
        temp.setAge(data[x].getAge());
        temp.setIC(data[x].getIC());
        temp.setPhone(data[x].getPhone());

        data[x].setName(data[x+1].getName());
        data[x].setAge(data[x+1].getAge());
        data[x].setIC(data[x+1].getIC());
        data[x].setPhone(data[x+1].getPhone());

        data[x+1].setName(temp.getName());
        data[x+1].setAge(temp.getAge());
        data[x+1].setIC(temp.getIC());
        data[x+1].setPhone(temp.getPhone());

        sorted = false;
      }
    }
  }
} // end of sort based on name

// Sort cutomers based on age
void SortingAge(Customer data[], int size)
{
  Customer temp;
  bool sorted = false;

  for (int pass = 1; (pass < size) && !sorted; ++pass)
  {
    sorted = true;
    for (int x = 0; x < size-pass; x++)
    {
      if (data[x].getAge() > data[x+1].getAge())
      {
        temp.setName(data[x].getName());
        temp.setAge(data[x].getAge());
        temp.setIC(data[x].getIC());
        temp.setPhone(data[x].getPhone());

        data[x].setName(data[x+1].getName());
        data[x].setAge(data[x+1].getAge());
        data[x].setIC(data[x+1].getIC());
        data[x].setPhone(data[x+1].getPhone());

        data[x+1].setName(temp.getName());
        data[x+1].setAge(temp.getAge());
        data[x+1].setIC(temp.getIC());
        data[x+1].setPhone(temp.getPhone());

        sorted = false;
      }
    }
  }
} // end of sort based on age

// Sort cutomers based on IC
void SortingIC(Customer data[], int size)
{
  Customer temp;
  bool sorted = false;

  for (int pass = 1; (pass < size) && !sorted; ++pass)
  {
    sorted = true;
    for (int x = 0; x < size-pass; x++)
    {
      // Malaysia IC first two value can count age
      if (data[x].getName() > data[x+1].getName())
      {
        temp.setName(data[x].getName());
        temp.setAge(data[x].getAge());
        temp.setIC(data[x].getIC());
        temp.setPhone(data[x].getPhone());

        data[x].setName(data[x+1].getName());
        data[x].setAge(data[x+1].getAge());
        data[x].setIC(data[x+1].getIC());
        data[x].setPhone(data[x+1].getPhone());

        data[x+1].setName(temp.getName());
        data[x+1].setAge(temp.getAge());
        data[x+1].setIC(temp.getIC());
        data[x+1].setPhone(temp.getPhone());

        sorted = false;
      }
    }
  }
} // end of sort based on IC number

// Search key based on name, IC number or phone number
void Search(string searchKey, Customer data[], int size)
{
  int index = -1; // -1 means record is not found
  for (int i = 0; i < size; i++)
  {
    if (searchKey == data[i].getName())
    {
      index = i; // assign current array index
      break; // terminate searching
    }
    else if (searchKey == data[i].getIC())
    {
      index = i; // assign current array index
      break; // terminate searching
    }
    else if (searchKey == data[i].getPhone())
    {
      index = i; // assign current array index
      break; // terminate searching
    }
  } // end for

  if (index == -1)
    cout << "\nNot found..." << endl;
  else
  {
    cout << "\Name: " << data[index].getName() << endl
         << "\Age: " << data[index].getAge() << endl
         << "\IC Number: " << data[index].getIC() << endl
         << "\Phone Number: " << data[index].getPhone() << endl;
  }
} // end of search for name, IC number or phone number
