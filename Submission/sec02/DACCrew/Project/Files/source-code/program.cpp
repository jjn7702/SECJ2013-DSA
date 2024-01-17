//save to file function
void saveToFile(stack &transactionStack)
{
    ofstream file("transaction_history.txt");

    if (file.is_open())
    {
        nodeStack *temp = transactionStack.getTop();
        while (temp)
        {
            file << temp->getDate() << "," << temp->getType() << "," << temp->getAmount() << "," << temp->getBalance() << "\n";
            temp = temp->next;
        }
        file.close();
        cout << "Transaction history saved to 'transaction_history.txt'." << endl;
    }
    else
    {
        cout << "Error opening the file." << endl;
    }
}
