#include "Term.h";

void Term::Convert_input(string input)
{
	int temp=1;
	bool co_eff = true;
	bool has_x = false;
	for (int i = 0; i <= input.size(); i++)
	{
		if (input[i] == 0)
			break;
		else if (input[i] == 'x')
		{
			coefficient = temp;
			temp = 0;
			co_eff == false;
			has_x = true;
		}

		else if (co_eff == true)
		{
			if (temp != 1)
				temp = temp * 10 + input[i];
			else
				temp = input[i];
		}

		else if (input[i] == '^')
			continue;
		else if (co_eff == false)
		{
			if (temp != 0)
				temp = temp * 10 + input[i];
			else
				temp = input[i];
		}
		else
				break;
		}
	if (has_x==false)
		coefficient = temp;
	else
		exponent = temp;
}
