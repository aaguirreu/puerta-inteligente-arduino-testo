// Boolean to check if password array is "empty". Empty means {0, 0, 0, 0}
bool isPasswordFillable()
{
    bool fillable = false;
    for (int i = 0; i < passSize; i++)
    {
        if (password[i] == 0)
        {
            fillable = true;
        }
    }
    return fillable;
}
// Makes the password "empty".
void cleanPassword()
{
    for (int i = 0; i < passSize; i++)
    {
        password[i] = 0;
    }
}
// Replace the first 0 with the value.
void setPasswordValue(int value)
{
    for (int i = 0; i < passSize; i++)
    {
        bool done = false;
        if (password[i] == 0 && done == false)
        {
            password[i] = value;
            done = true;
        }
    }
}
// Comparison of passwords. If equal, return true.
bool comparePasswords()
{
    for (int i = 0; i < passSize; i++)
    {
        int inputPasswordValue = password[i];
        int storedPasswordValue = dummyPassword[i];
        if (inputPasswordValue != storedPasswordValue)
        {
            return false;
        }
    }
    return true;
}